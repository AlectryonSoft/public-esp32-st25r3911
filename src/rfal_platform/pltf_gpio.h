#ifndef PLATFORMGPIO_H
#define PLATFORMGPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 ******************************************************************************
 * GLOBAL TYPES
 ******************************************************************************
 */
/* GPIO pin set and reset enumeration */
typedef enum {
	GPIO_PIN_RESET = 0,
	GPIO_PIN_SET
}GPIO_PinState;

/*
 ******************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 ******************************************************************************
 */

/*! 
 *****************************************************************************
 * \brief  To read GPIO pin state
 *  
 * This methods reads the state of given GPIO pin.
 * \param[in]	: GPIO port of the given GPIO pin
 * \param[in]	: GPIO pin number
 * 
 * \return GPIO_PIN_RESET	: State of GPIO pin is low 
 * \return GPIO_PIN_SET		: State of GPIo pin is high
 *****************************************************************************
 */
GPIO_PinState gpio_readpin(int port, int pin_no); 

/*! 
 *****************************************************************************
 * \brief  To set GPIO pin 
 *  
 * This method sets the state of GPIO pin high.
 * \param[in]	: GPIO port of the given GPIO pin
 * \param[in]	: GPIO pin number
 * 
 *****************************************************************************
 */
void gpio_set(int port, int pin_no); 

/*! 
 *****************************************************************************
 * \brief  To clear GPIO pin 
 *  
 * This method sets the state of GPIO pin Low.
 * \param[in]	: GPIO port of the given GPIO pin
 * \param[in]	: GPIO pin number
 * 
 *****************************************************************************
 */
void gpio_clear(int port, int pin_no);

#ifdef __cplusplus
}
#endif

#endif /* PLATFORMGPIO_H */


