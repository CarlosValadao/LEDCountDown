#include "inc/rgb.h"
#include "inc/push_button.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_GREEN_PIN 11

static volatile bool is_alarm_callback_running = false;

static int64_t turn_off_callback(alarm_id_t alarm, void *user_data);

int main()
{
    rgb_t rgb_pins = {.red = 13, .blue = 12, .green = 11};
    rgb_init(&rgb_pins);
    pb_config_btn_a();
    while (true)
    {
        if(pb_is_button_a_pressed() && !is_alarm_callback_running)
        {
            is_alarm_callback_running = true;
            rgb_turn_on_white(&rgb_pins, 30);
            add_alarm_in_ms(3000, turn_off_callback, &rgb_pins.blue, false);
            add_alarm_in_ms(6000, turn_off_callback, &rgb_pins.red, false);
            add_alarm_in_ms(9000, turn_off_callback, &rgb_pins.green, false);
        }
    }
    return 0;
}

static int64_t turn_off_callback(alarm_id_t alarm, void *user_data)
{
    uint8_t *gpio = (uint8_t *)user_data;
    turn_off_led_by_gpio(*gpio);
    if(*gpio == LED_GREEN_PIN) is_alarm_callback_running = false;
    return 0;
}
