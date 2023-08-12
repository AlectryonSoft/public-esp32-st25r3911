
#include "pltf_interrupt.h"

#include "config.h"
#include <Arduino.h>

/*
 ******************************************************************************
 * STATIC VARIABLES
 ******************************************************************************
 */

static SemaphoreHandle_t rfal_irq_mtx;

/*
 ******************************************************************************
 * GLOBAL AND HELPER FUNCTIONS
 ******************************************************************************
 */

void interrupt_init()
{
    rfal_irq_mtx = xSemaphoreCreateMutex();
    pinMode(IRQ_PIN, INPUT);
}

void pltf_protect_interrupt_status(void)
{
	xSemaphoreTake(rfal_irq_mtx, portMAX_DELAY); // enter critical section
}

void pltf_unprotect_interrupt_status(void)
{
	xSemaphoreGive(rfal_irq_mtx); // exit critical section
}
