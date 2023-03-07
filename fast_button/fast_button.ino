/* 
 *###################################################################################################
 * Sistema de debounce rapido criado por: Romario J Santana
 * Data da criaçao: 23/10/2019
 * Contato: (79)9.9903-0137 ou romariojs14@hotmail.com
 * O sistema visa uma maneira de filtrar o efeito bounce causado por botoes de acionamento mecanico,
 * dessa forma ele consegue filtra o bounce de maneira mais eficiente e responsiva. 
 * **FUNCOES**
 * 
 attach(pin, intervalo); - atribui a porta e a define como entrada comum GND com ajuste de tempo para bounce
 attach(pin); - atribui a porta ao mesmo tempo que a define como entrada PULLUP(comum GND)
 press();  - retorna HIGH enquanto o botao estiver pressionado
 click();  -  retorna um ciclo de execuçao a cada clique do botao
 * 
 * 
 *####################################################################################################
 */

#include "Botao.h"

Botao up, dn, ok;
bool b=0;

void setup() {

  up.attach(4);
  dn.attach(3);
  ok.attach(2);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {

  if (ok.click()) b = !b;
   digitalWrite(13, b);
  digitalWrite(12, dn.press());

}
