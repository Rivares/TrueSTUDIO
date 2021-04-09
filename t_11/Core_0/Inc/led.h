#ifndef _LED_H_
#define _LED_H_

#include <stdint.h>		// For uint8_t

// Перечисляем команды
enum LED_MODE {
    RED,
    GREEN,
    OFF,
    ON,
    TOGGLE,
};

void LED(uint8_t led, uint8_t mode);  //Объявляем функцию управления светодиодами

#endif //_LED_H_