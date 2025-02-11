#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22

const uint WRAP_PERIOD = 20000;
const float CLK_DIV = 125.0;

void pwm_setup()
{
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);

    pwm_set_clkdiv(slice, CLK_DIV);
    pwm_set_wrap(slice, WRAP_PERIOD);
    pwm_set_gpio_level(PWM_PIN, 0);

    pwm_set_enabled(slice, true);
}

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

    while (true)
    {
        pwm_set_gpio_level(PWM_PIN, 2400); // 180°
        sleep_ms(5000);
        pwm_set_gpio_level(PWM_PIN, 1470); // 90°
        sleep_ms(5000);
        pwm_set_gpio_level(PWM_PIN, 500); // 0°
        sleep_ms(5000);
        while (true)
        {
            rotate_servo();
        }
    }
}
