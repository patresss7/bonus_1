/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "assignment.h"

int main(void)
{
  /*
   *  DO NOT WRITE TO THE WHOLE REGISTER!!!
   *  Write to the bits, that are meant for change.
   */
   
  //Systick init
  LL_Init1msTick(8000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(8000000);	

  /*
   * TASK - configure MCU peripherals so that button state can be read and LED will blink.
   * Button must be connected to the GPIO port A and its pin 3.
   * LED must be connected to the GPIO port A and its pin 4.
   *
   * In header file "assignment.h" define macros for MCU registers access and LED blink application.
   * Code in this file must use these macros for the peripherals setup.
   *
   * Add LED blinking: fast when the button is pressed, otherwise slow blinking.
   */


  /* Enable clock for GPIO port A*/

	//type your code for GPIOA clock enable here:


   RCC_AHBENR_REG |= (uint32_t)(1 << 17);
      // replace with RCC_AHBENR_REG?

    /* GPIOA pin 3 and 4 setup */

  	//type your code for GPIOA pins setup here:
      *((volatile uint32_t *)(GPIOA_MODER_REG)) &= ~(uint32_t)(0x3 << 6); //set input mode for pin 3

      *((volatile uint32_t *)(GPIOA_MODER_REG)) &= ~(uint32_t)(0x3 << 8); //put 00 (part of setting output) in pin 4
      *((volatile uint32_t *)(GPIOA_MODER_REG)) |= (uint32_t)(1 << 8);  //set output mode for pin 4

      *((volatile uint32_t *)(GPIOA_OTYPER_REG)) &= ~(uint32_t)(1 << 4); //set output type to push-pull

      *((volatile uint32_t *)(GPIOA_OSPEEDER_REG)) &= ~(uint32_t)(1 << 8);  //set output to low speed

      *((volatile uint32_t *)((uint32_t)(GPIOA_PUPDR_REG))) &= ~(0x3 << 6);  //put 00 (part of setting pullup) on pin 3
      *((volatile uint32_t *)((uint32_t)(GPIOA_PUPDR_REG))) |= (1 << 6);   //set pull up for button on pin 3

      *((volatile uint32_t *)((uint32_t)(GPIOA_PUPDR_REG))) &= ~(0x3 << 8);  //no pull for output on pin 4



  while (1)
  {
	  /* Read button state and blink the led fast/slow */

	  //type your code for led blinking here:

  }

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
