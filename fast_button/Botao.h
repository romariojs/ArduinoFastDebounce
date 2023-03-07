/*
  ###################################################################################################
   Sistema de debounce rapido criado por: Romario J Santana
   Data da criaçao: 23/10/2019
   Contato: (79)9.9903-0137 ou romariojs14@hotmail.com
   O sistema visa uma maneira de filtrar o efeito bounce causado por botoes de acionamento mecanico,
   dessa forma ele consegue filtra o bounce de maneira mais eficiente e responsiva.
 * **FUNCOES**

  attach(pin, intervalo); - atribui a porta e a define como entrada comum GND com ajuste de tempo para bounce
  attach(pin); - atribui a porta ao mesmo tempo que a define como entrada PULLUP(comum GND)
  press();  - retorna HIGH enquanto o botao estiver pressionado
  click();  -  retorna um ciclo de execuçao a cada clique do botao


  ####################################################################################################
*/

class Botao {
  private:
    unsigned long bounce = 0;
    bool saida = 0, clk_last = 0;
    uint8_t BUTTON_PORT;
    uint16_t db_time = 10;
  public:
    void attach(uint8_t _pin, uint16_t _intervalo);
    void attach(uint8_t _pin);
    bool press();
    bool click();
};

bool readport(uint8_t _p) {

  bool output = 0;
  if (_p < 8) output =  bitRead(PIND, _p);//0 - 7
  else if (_p < 14) output = bitRead(PINB, _p - 8);//8 - 13
  else if (_p < 20) output =  bitRead(PINC, _p - 14);//14 - 19
  return output;

}

void Botao::attach(uint8_t _pin) {
  pinMode(_pin, INPUT_PULLUP);
  BUTTON_PORT = _pin;
}

void Botao::attach(uint8_t _pin, uint16_t _intervalo) {// usar de 1 a 255
  db_time = _intervalo;
}

bool Botao::click() {
  bool clk = press();                            //lê o valor da entrada filtrada
  bool out = false;                              //cria e atualiza variavel de saida
  if (clk != clk_last) {                         //havendo mudanca de estado continue
    clk_last = clk;                              //salva mudanca para intertravamento
    if (clk) out = true;                         //se clk mudou de estado para high saida entao é high
  }
  return out;                                    //escreve valor na saida
}

bool Botao::press() {           //funcao para filtrar ruidos mecanicos do botao
  bool entrada = !readport(BUTTON_PORT);      //le o sinal bruto da porta
  if (entrada) {                                 //se pressionado executa
    saida = true;                                //saida entra em high se botao for high
    bounce = millis();                           //zera a contagem do bounce quando estiver pressionado
  }                                              //pressionado end
  else {                                         //executa quando n estiver pressionado
    if (millis() - bounce > db_time) {           //aguarda 10ms para atualizar o estado
      bounce = millis();                         //zera a contagem do bounce quando executado
      saida = false;                             //atualiza sinal do botao apos o tempo de bounce
    }                                            //intervalo de bounce end
  }                                              //nao pressionado end
  return saida;                                  //retorna o valor de saida filtrado dessa funcao
}                                                //funcao botao read enter
