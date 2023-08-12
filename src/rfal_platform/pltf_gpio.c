/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */

#include "pltf_gpio.h"

#include "config.h"

#include <Arduino.h>
#include "rfal_core/st25r3911/st25r3911_interrupt.h"


/*
 ******************************************************************************
 * GLOBAL AND HELPER FUNCTIONS
 ******************************************************************************
 */

void gpio_set(int port, int pin_no) 
{
	(void)port;
	digitalWrite(pin_no, HIGH);
}

void gpio_clear(int port, int pin_no) 
{
	(void)port;
	digitalWrite(pin_no, LOW);
}

GPIO_PinState gpio_readpin(int port, int pin_no)
{
	(void)port;
	return digitalRead(pin_no) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET;
}
