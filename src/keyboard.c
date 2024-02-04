#include "keyboard.h"
#include "tty.h"
#include "io.h"

void keyboard_callback(__attribute__((unused)) i_register_t registers) {
    unsigned char key = inb(0x60);
    tty_write("K");
}

void keyboard_init() {
    register_interrupt_handler(IRQ1, keyboard_callback);

    BOOT_LOG("Keyboard initialized.")
}