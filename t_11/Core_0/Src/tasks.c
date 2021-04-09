# include "tasks.h"


void settingsAndCreateTread(const char *fnc_name, void (*fnc)(), void *arg_0)
{
	/* Definitions for SPITask */
	osThreadId_t SPITaskHandle;
	const osThreadAttr_t SPITask_attributes = {
	  .name = fnc_name,
	  .priority = (osPriority_t) osPriorityNormal,
	  .stack_size = configMINIMAL_STACK_SIZE * 2
	};

	osThreadNew(fnc, arg_0, &SPITask_attributes);
}

__weak void GPIO_Task(void *arg)
{
	/* USER CODE BEGIN 5 */

	/* Infinite loop */
	for(;;)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		HAL_Delay(1000);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_Delay(1000);
	}
	/* USER CODE END 5 */
}

__weak void SPI_Task(void *arg)
{
	/* USER CODE BEGIN 5 */
	// uint8_t *tx_data;
	// uint8_t *rx_data;

	/* Infinite loop */
	char message[] = "Hello, World";
	for(;;)
	{
		// if ((SPI2->SR & SPI_SR_TXE) == 0)
		// {
		// 	SPI2->DR = *tx_data++;
		// }
		// if ((SPI2->SR & SPI_SR_RXNE) != 0)
		// {
		// 	*rx_data++ = SPI2->DR;
		// }

        HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);
        HAL_SPI_Transmit(&hspi2, (uint8_t *)message, strlen(message), HAL_MAX_DELAY);
        HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);
        HAL_Delay(10);
	}
	/* USER CODE END 5 */
}

void fn_update(SPI_HandleTypeDef fresh_hspi2)
{
	hspi2 = fresh_hspi2;
}