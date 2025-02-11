# Controle de Servomotor por PWM no Raspberry Pi Pico W

## Descrição
Este projeto implementa o controle de um servomotor utilizando PWM no Raspberry Pi Pico W, conforme os requisitos da atividade. O servo realiza movimentações programadas entre os ângulos de 0°, 90° e 180°, e posteriormente faz uma varredura suave e ininterrupta entre 0° e 180°. Também inclui um teste para verificar o funcionamento de um LED RGB conectado à GPIO 12.

## Requisitos
- Raspberry Pi Pico W
- Simulador **Wokwi** integrado ao VS Code
- LED RGB conectado à GPIO 12
- Kit de Desenvolvimento de Software **Pico SDK**
- **BitDogLab** para testes do LED RGB
- **GitHub** para versionamento do código

## Funcionalidades
- Configuração do PWM na GPIO 22 com frequência de **50Hz** (período de 20ms)
- Definição dos ciclos ativos para controle do servo:
  - **2400µs** (180°) - Aguarda 5s
  - **1470µs** (90°) - Aguarda 5s
  - **500µs** (0°) - Aguarda 5s
- Movimentação suave do servo de **0° a 180° e vice-versa** de forma ininterrupta
- Teste de LED RGB na GPIO 12, piscando 5 vezes antes da execução do controle do servo

## Como Executar
1. **Configurar o Ambiente:**
   - Instale o **Pico SDK** no VS Code
   - Configure o **Wokwi** para simulação
   - Clone este repositório no GitHub
   
2. **Executar a Simulação no Wokwi:**
   - Carregue o código no simulador
   - Observe a movimentação do servo e o teste do LED RGB

## Testes Implementados
- **Movimentação do servo** nos três pontos fixos
- **Varredura suave** entre 0° e 180°
de forma cíclica
- **Piscar do LED RGB** na GPIO 12 antes da execução do código principal

## Resposta para o Item 6 - Experimento com o LED RGB na GPIO 12 (BitDogLab)
### Observação do comportamento da iluminação do LED RGB:
---
O resultado do experimento utilizando a GPIO 12 do LED foi:
- O LED inicia com a sua intensidade máxima e fica assim por 5 segundos.
- Após isso o LED tem a sua intensidade reduzida pela metade e fica assim por mais 5 segundos.
- O LED fica com uma intensidade mínima por 5 segundos.
- O LED oscila entre a intensidade maior e menor.
  
Durante o experimento com o LED RGB utilizando a ferramenta BitDogLab, foi possível observar que a variação do duty cycle do PWM afeta diretamente a intensidade do LED. O comportamento registrado foi:

Oscilação da Intensidade:

- Como o LED está sendo controlado pelo PWM, o brilho do LED varia de acordo com o ciclo de trabalho (duty cycle).
- Quando o duty cycle aumenta, o LED brilha com mais intensidade.
- Quando o duty cycle diminui, o LED fica mais fraco.

Durante os testes, o LED apresentou variações sutis no brilho enquanto o servo motor estava em operação. Isso pode ser explicado por pequenas interferências causadas pelo acionamento do PWM do servo e do LED simultaneamente.

## Vídeo de demonstração
https://youtu.be/ikjAmFpvWTg?si=nsqMlpNeC1VI-1Tn


## Autor
**Richard Lima Ribeiro**

