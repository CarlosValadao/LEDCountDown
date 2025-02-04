#include "inc/rgb.h"               // Biblioteca para controle do LED RGB
#include "inc/push_button.h"       // Biblioteca para controle do botão
#include "pico/stdlib.h"           // Biblioteca padrão do Raspberry Pi Pico
#include "hardware/timer.h"        // Biblioteca para utilização de timers

#define LED_GREEN_PIN 11           // Define o pino do LED verde

// Variável global para evitar múltiplas execuções simultâneas do alarme
static volatile bool is_alarm_callback_running = false;

// Protótipo da função de callback para desligar os LEDs
static int64_t turn_off_callback(alarm_id_t alarm, void *user_data);

int main()
{
    // Estrutura para armazenar os pinos do LED RGB
    rgb_t rgb_pins = {.red = 13, .blue = 12, .green = 11};

    // Inicializa o LED RGB com os pinos especificados
    rgb_init(&rgb_pins);

    // Configura o botão A como entrada
    pb_config_btn_a();

    // Loop infinito para verificar o estado do botão
    while (true)
    {
        // Verifica se o botão A foi pressionado e se nenhum alarme está rodando
        if(pb_is_button_a_pressed() && !is_alarm_callback_running)
        {
            is_alarm_callback_running = true; // Indica que o alarme foi ativado

            // Acende todos os LEDs com 30% de brilho
            rgb_turn_on_white(&rgb_pins, 30);

            // Configura alarmes para desligar os LEDs em sequência
            add_alarm_in_ms(3000, turn_off_callback, &rgb_pins.blue, false); // Apaga o azul após 3s
            add_alarm_in_ms(6000, turn_off_callback, &rgb_pins.red, false);  // Apaga o vermelho após 6s
            add_alarm_in_ms(9000, turn_off_callback, &rgb_pins.green, false); // Apaga o verde após 9s
        }
    }
    return 0;
}

// Função de callback chamada pelos alarmes para desligar os LEDs
static int64_t turn_off_callback(alarm_id_t alarm, void *user_data)
{
    uint8_t *gpio = (uint8_t *)user_data; // Obtém o pino do LED a ser apagado

    turn_off_led_by_gpio(*gpio); // Desliga o LED correspondente

    // Se o LED verde foi apagado, libera o alarme para futuras execuções
    if(*gpio == LED_GREEN_PIN) is_alarm_callback_running = false;

    return 0; // Retorna 0 para indicar que não há necessidade de reativação do alarme
}
