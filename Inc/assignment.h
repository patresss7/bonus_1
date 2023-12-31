#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_


/**
 * This header file provides macros to the MCU's registers required for this assignment.
 * Your task is to provide their actual implementation so you can use them in the application in "main.c"
 * and make your "LED blink" application code readable and great again!
 */

/* General purpose input output port A macros */
//GPIOA peripheral base address
#define	GPIOA_BASE_ADDR			(uint32_t)(0x48000000U)
//MODER register
#define	GPIOA_MODER_REG			(uint32_t *)(GPIOA_BASE_ADDR + 0x00U)
//OTYPER register
#define	GPIOA_OTYPER_REG		(uint32_t *)(GPIOA_BASE_ADDR + 0x04)
//OSPEEDER register
#define GPIOA_OSPEEDER_REG		(uint32_t *)(GPIOA_BASE_ADDR + 0x08U)
//PUPDR register
#define GPIOA_PUPDR_REG			(uint32_t *)(GPIOA_BASE_ADDR + 0x0CU)
//IDR register
#define GPIOA_IDR_REG			(uint32_t *)(GPIOA_BASE_ADDR + 0x10U)
//ODR register
#define GPIOA_ODR_REG			(uint32_t *)(GPIOA_BASE_ADDR + 0x14U)
//BSRR register
#define GPIOA_BSRR_REG			(uint32_t *)(GPIOA_BASE_ADDR + 0x18U)
//BRR register
#define GPIOA_BRR_REG			(uint32_t *)(GPIOA_BASE_ADDR + 0x28U)

/*Reset clock control register macros */
//RCC base address
#define	RCC_BASE_ADDR			(uint32_t)(0x40021000U)
//AHBEN register
#define	RCC_AHBENR_REG			*((volatile uint32_t *) (uint32_t)(RCC_BASE_ADDR + 0x00000014U))

/* LED and button macros */
#define LED_PIN                 LL_GPIO_PIN_4  // Define the LED pin
#define BUTTON_PIN              LL_GPIO_PIN_3  // Define the button pin

/* LED and button macros */
#define LED_ON					*((volatile uint32_t *)((GPIOA_BSRR_REG))) |= (1<<4)
#define LED_OFF					*((volatile uint32_t *)((GPIOA_BRR_REG))) |= (1<<4)

#define BUTTON_GET_STATE		!(*((volatile uint32_t *)((uint32_t)(0x48000000 + 0x10U))) & (1 << 3))

typedef enum {
    NONE = 0,
    RISE = 1,
    FALL = 2
} EDGE_TYPE;

EDGE_TYPE edgeDetect(uint8_t pin_state, uint8_t samples);

#endif /* ASSIGNMENT_H_ */
