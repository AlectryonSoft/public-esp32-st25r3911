#ifndef PLATFORMSPI_H
#define PLATFORMSPI_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include <stdint.h>

/*
 ******************************************************************************
 * GLOBAL FUNCTIONS
 ******************************************************************************
 */

/*! 
 *****************************************************************************
 * \brief  Initialize SPI Interface
 *  
 * This methods initialize SPI interface so that the host can use SPI interface
 *	to communicate with ST25R3911XX.
 *
 *****************************************************************************
 */
void spi_init(void);

/*! 
 *****************************************************************************
 * \brief  SPI Interface
 *  
 * This methods sends and receive data in full duplex using the SPI interface 
 *	to communicate with ST25R3911XX.
 *
 *****************************************************************************
 */
/* function for full duplex SPI communication */
void spiTxRx(const uint8_t *txData, uint8_t *rxData, uint8_t length);

void pltf_cs_select(void);

void pltf_cs_deselect(void);

/*! 
 *****************************************************************************
 * \brief  To protect SPI communication
 *  
 * This method acquire a mutex and shall be used before communication takes 
 * place.
 * 
 *****************************************************************************
 */
void pltf_protect_com(void);

/*! 
 *****************************************************************************
 * \brief  To unprotect SPI communication
 *  
 * This method release the mutex that was acquired with pltf_protect_com.
 * 
 *****************************************************************************
 */
void pltf_unprotect_com(void); 

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_SPI */
