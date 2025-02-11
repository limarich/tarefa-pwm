#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22
#define LED_PIN 12

const uint WRAP_PERIOD = 20000;
const float CLK_DIV = 125.0;

// configuração do pwm
void pwm_setup()
{
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);

    pwm_set_clkdiv(slice, CLK_DIV);
    pwm_set_wrap(slice, WRAP_PERIOD);
    pwm_set_gpio_level(PWM_PIN, 0);

    pwm_set_enabled(slice, true);
}
// configuração do led
void led_setup()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, false);
}

// função de teste do led -> espera-se que o led fique alternando entre aceso e apagado
void led_test()
{

    for (int i = 0; i < 5; i++)
    {
        gpio_put(LED_PIN, 1); // Acende o LED
        sleep_ms(500);
        gpio_put(LED_PIN, 0); // Apaga o LED
        sleep_ms(500);
    }
}
// movimentação do servo motor de 0° a 180°
void rotate_servo()
{
    uint pulse = 500;
    uint step = 5;
    while (pulse <= 2400)
    {
        pulse += step;
        pwm_set_gpio_level(PWM_PIN, pulse);
        sleep_ms(10);
    }
    while (pulse >= 500)
    {
        pulse -= step;
        pwm_set_gpio_level(PWM_PIN, pulse);
        sleep_ms(10);
    }
}

int main()
{
    stdio_init_all();
    pwm_setup(); // configuração do PWM
    led_setup(); // configuração do led

    while (true)
    {
        pwm_set_gpio_level(PWM_PIN, 2400); // 180°
        sleep_ms(5000);
        pwm_set_gpio_level(PWM_PIN, 1470); // 90°
        sleep_ms(5000);
        pwm_set_gpio_level(PWM_PIN, 500); // 0°
        sleep_ms(5000);
        while (true) // movimentação periódica do servo-motor
        {
            rotate_servo();
        }
    }
}
