#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"
#include "main.h"
#include <stdio.h>

const uint LED_PIN = 25;

// Metadata
bi_decl(bi_program_description("This is an example binary."));
bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
        hello_world();
        sleep_ms(1000);
    }
}