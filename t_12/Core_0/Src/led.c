#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_gpio.h"
#include "led.h"

enum LED_MODE led, mode;

//Функция управления светодиодами
void LED(uint8_t led, uint8_t mode)
{
    //Проверяем какой светодиод нужно переключить и в зависимости от переменной mode выполняем необходимые действия
    switch (led) {

    case RED:

        if (mode == ON) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
        }
        else if (mode == OFF) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
        }
        else if (mode == TOGGLE) {
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
        }
        break;

    case GREEN:

        if (mode == ON) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
        }
        else if (mode == OFF) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
        }
        else if (mode == TOGGLE) {
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
        }
        break;
    }
}