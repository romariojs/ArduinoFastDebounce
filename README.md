# Arduino Fast Debounce
### Sketch para Arduino

Esse programa consegue filtrar de forma rapida e precisa o ruido gerado pelo acionamento de botões mecanicos, tendo como diferencial um melhor desempenho com relação ao delay no acionamento geralmente encontrado em outras bibliotecas, isso porque ele consegue gerar o sinal de saida ao mesmo tempo que foi pressionado fazendo o debounce durante o pressionamento e lendo a entrada direto dos registradores.
 Em geral a filtragem é feita de forma que ao pressionar do botao espera de 25 a 50ms de delay para entao enviar o sinal a saida, porem nesse codigo a saida ja é enviada desde o pressionamento e so é atualizada apos 10ms de execuçao ou seja o tempo minimo possivel que esse botao pode ficar pressionado é 10ms antes de voltar ao estado 0
 *Note que o comum dos botoes é GND ou seja no (-) da placa
 
 ### Como utilizar:
  1. Deve copiar os arquivos da pasta para o local do projeto
  2. A Pasta contem dois arquivos um de exemplo de uso **"fast_button.ino"** e outro da biblioteca a importar **"Botao.h"**
  3. O arquivo "Botao.h" deve ser copiado e importado para pasta do projeto igual como no arquivo **"fast_button.ino"**
  
  ### Comandos  
 <div>Botao meubotao; - Cria o objeto de botao unico</div>
 <div>meubotao.attach(pin, intervalo); - atribui a porta e a define como entrada comum GND podendo fazer ajuste de tempo para bounce</div>
 <div>meubotao.attach(pin); - atribui a porta ao mesmo tempo que a define como entrada PULLUP(comum GND) com debounce padrão de 10ms</div>
 <div>meubotao.press();  - retorna HIGH enquanto o botao estiver pressionado</div>
 <div>meubotao.click();  -  retorna um ciclo de execuçao a cada clique do botao</div>
  
