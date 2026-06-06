/*
 * ESP32 Firmware Educacional - ESP-IDF
 * 
 * Este é um código educacional para o ESP32 desenvolvido no framework ESP-IDF.
 * Ele foi projetado para inicializar o chip, exibir mensagens de status no 
 * terminal do computador e entrar em um ciclo contínuo de funcionamento, 
 * evitando falhas de sistema.
 * 
 * Autor: Educacional
 * Data: 2026
 */

#include <FreeRTOS.h>
#include <task.h>
#include <esp_log.h>

/*
 * ATALHOS INTELIGENTES (#define)
 * 
 * Usamos #define para deixar o código mais limpo e amigável, criando "atalhos"
 * que substituem comandos gigantes do ESP-IDF, tornando o código mais legível
 * e fácil de manter.
 */

#define print(tag, texto) ESP_LOGI(tag, texto)
#define esperar(ms) vTaskDelay(pdMS_TO_TICKS(ms))

/*
 * TAG PARA LOGS
 * 
 * Define uma categoria para as mensagens de log desta aplicação.
 * Permite organizar as mensagens por funcionalidade.
 */
static const char *TAG = "APP_MAIN";

/*
 * FUNÇÃO PRINCIPAL - app_main()
 * 
 * É a porta de entrada do chip. Todo firmware para ESP32 começa a rodar 
 * obrigatoriamente por aqui. Ela não recebe dados externos e não devolve 
 * nada para o sistema (por isso o uso do 'void' duas vezes).
 * 
 * O sistema operacional em tempo real (FreeRTOS) chama automaticamente 
 * esta função após a inicialização do hardware.
 */
void app_main(void) {
    
    /*
     * INICIALIZAÇÃO DO SISTEMA
     * 
     * Aqui começamos a inicializar o chip. Exibimos uma mensagem de status
     * para indicar que o firmware começou a executar.
     */
    print(TAG, "Sistema inicializado com sucesso");
    print(TAG, "Chip ESP32 operacional");
    print(TAG, "Entrando em ciclo contínuo...");
    
    /*
     * LOOP INFINITO - while(1)
     * 
     * Essencial em sistemas embarcados. Como o ESP32 não tem um sistema 
     * operacional como o Windows para fechar o programa e voltar para a área 
     * de trabalho, a função principal nunca pode chegar ao fim.
     * 
     * O while(1) prende o processador em um ciclo eterno.
     * 
     * IMPORTANTE: Se deixássemos o código acabar sem o while, o FreeRTOS 
     * perderia o controle do chip, causando um erro crítico de sistema 
     * (Crash/Reset) conhecido como Kernel Panic.
     */
    while(1) {
        
        /*
         * OPERAÇÃO CONTÍNUA
         * 
         * Exibimos uma mensagem indicando que o sistema está funcionando
         */
        print(TAG, "Ciclo contínuo em execução...");
        
        /*
         * DELAY/PAUSA
         * 
         * Aguardamos 1 segundo (1000 milissegundos) antes de repetir o ciclo.
         * Sem isso, o processador usaria 100% de CPU imprimindo mensagens
         * continuamente, desperdiçando energia.
         */
        esperar(1000);
    }
}

/*
 * RESUMO DO QUE APRENDEMOS
 * 
 * 1. Arquivos de Inclusão (#include):
 *    - FreeRTOS.h e task.h: Para gerenciar tarefas e tempo
 *    - esp_log.h: Para exibir mensagens no terminal
 * 
 * 2. Atalhos Inteligentes (#define):
 *    - Tornam o código mais legível e fácil de manter
 *    - print() abrevia ESP_LOGI()
 *    - esperar() abrevia vTaskDelay()
 * 
 * 3. Função Principal (app_main):
 *    - Ponto de entrada obrigatório do firmware
 *    - Chamada automaticamente pelo FreeRTOS
 * 
 * 4. Loop Infinito (while(1)):
 *    - Mantém o programa sempre executando
 *    - Previne Kernel Panic
 *    - Necessário para sistemas embarcados
 */
