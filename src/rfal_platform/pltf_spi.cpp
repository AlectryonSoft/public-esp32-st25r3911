/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include "pltf_spi.h"

#include "config.h"
#include "pltf_gpio.h"

#include <Arduino.h>
#include <SPI.h>

/*
 ******************************************************************************
 * DEFINES
 ******************************************************************************
 */
const long spi_speed = 500000;

/*
 ******************************************************************************
 * STATIC VARIABLES
 ******************************************************************************
 */
/* Lock to serialize SPI communication */
static SemaphoreHandle_t rfal_spi_mtx;

/*
 ******************************************************************************
 * GLOBAL AND HELPER FUNCTIONS
 ******************************************************************************
 */
void spi_init(void)
{
    rfal_spi_mtx = xSemaphoreCreateMutex();
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    pinMode(SPI_SS, OUTPUT);
}

void spiTxRx(const uint8_t *txData, uint8_t *rxData, uint8_t length)
{ 
    SPI.transferBytes(txData, rxData, length);
}

void pltf_cs_select(void)
{
    SPI.beginTransaction(SPISettings(spi_speed, MSBFIRST, SPI_MODE1));
    digitalWrite(SPI_SS, LOW);
}

void pltf_cs_deselect(void)
{
    SPI.endTransaction();
    digitalWrite(SPI_SS, HIGH);
}

void pltf_protect_com(void)
{
    xSemaphoreTake(rfal_spi_mtx, portMAX_DELAY); // enter critical section
}

void pltf_unprotect_com(void)
{
    xSemaphoreGive(rfal_spi_mtx); // exit critical section
}
