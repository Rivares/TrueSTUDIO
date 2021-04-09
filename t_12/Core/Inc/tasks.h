#ifndef TASKS_H
#define TASKS_H

#include <stdint.h>
#include <string.h>

#include "cmsis_os.h"
#include "stm32f7xx_hal.h"

extern SPI_HandleTypeDef hspi2;
extern uint16_t m_IL_SPI_data;

void settingsAndCreateTread(const char *fnc_name, void (*fnc)(), void *arg_0);

void GPIO_Task(void *arg);
void SPI_Task(void *arg);

void SPI_Init();

void SPI_Send(uint16_t data);













#endif // TASKS_H
