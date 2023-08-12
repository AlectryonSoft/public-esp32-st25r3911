#ifndef RFAL_PLATFORM_H
#define RFAL_PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/

#include "config.h"
#include "pltf_timer.h"
#include "pltf_spi.h"
#include "pltf_gpio.h"
#include "pltf_interrupt.h"

#include <Arduino.h>

/*
******************************************************************************
* GLOBAL DEFINES
******************************************************************************
*/

/*
#define LED_NFCA_PIN				13
#define LED_NFCB_PIN				6
#define LED_NFCF_PIN				5
#define LED_NFCV_PIN				22
#define LED_AP2P_PIN				27
#define LED_NFCA_PORT				0
#define LED_NFCB_PORT				0
#define LED_NFCF_PORT				0
#define LED_NFCV_PORT				0  */       /* These have been removed as they are not required as LEDs are not being used*/

#define ST25R3911

#define ST25R_INT_PIN                     IRQ_PIN                   /*!< GPIO pin used for ST25R3911 External Interrupt */
#define ST25R_INT_PORT                    0                         /*!< GPIO port used for ST25R3911 External Interrupt */

/*
******************************************************************************
* GLOBAL MACROS
******************************************************************************
*/
#define ST25R391X_COM_SINGLETXRX                                        /*!< Enable single SPI frame transmission */

#define platformProtectST25RComm()            pltf_protect_com()
#define platformUnprotectST25RComm()          pltf_unprotect_com()

#define platformIrqST25RPinInitialize()       interrupt_init();
#define platformIrqST25RSetCallback(cb)       attachInterrupt(digitalPinToInterrupt(ST25R_INT_PIN), cb, RISING)

#define platformSpiSelect()                   pltf_cs_select()       /*!< SPI SS\CS: Chip|Slave Select */
#define platformSpiDeselect()                 pltf_cs_deselect()     /*!< SPI SS\CS: Chip|Slave Deselect */

#define platformProtectST25RIrqStatus()       pltf_protect_interrupt_status()   /*!< Acquire the lock for safe access of RFAL interrupt status variable */
#define platformUnprotectST25RIrqStatus()     pltf_unprotect_interrupt_status() /*!< Release the lock aquired for safe accessing of RFAL interrupt status variable */

#define platformGpioIsHigh(port, pin)         (gpio_readpin(port, pin) == GPIO_PIN_SET)                                                     /*!< Checks if the given GPIO is High */

#define platformTimerDestroy(t)
#define platformTimerCreate(t)                timerCalculateTimer(t)    /*!< Create a timer with the given time (ms)     */
#define platformTimerIsExpired(timer)         timerIsExpired(timer)     /*!< Checks if the given timer is expired        */
#define platformDelay(t)                      timerDelay(t)             /*!< Performs a delay for the given time (ms)    */
#define platformGetSysTick()                  platformGetSysTick_esp32()/*!< Get System Tick ( 1 tick = 1 ms)            */

#define platformSpiTxRx(txBuf, rxBuf, len)    spiTxRx(txBuf, rxBuf, len)/*!< SPI transceive */

#define platformI2CTx(txBuf, len)                                       /*!< I2C Transmit  */
#define platformI2CRx(txBuf, len)                                       /*!< I2C Receive   */
#define platformI2CStart()                                              /*!< I2C Start condition */
#define platformI2CStop()                                               /*!< I2C Stop condition  */
#define platformI2CRepeatStart()                                        /*!< I2C Repeat Start    */
#define platformI2CSlaveAddrWR(add)                                     /*!< I2C Slave address for Write operation       */
#define platformI2CSlaveAddrRD(add)                                     /*!< I2C Slave address for Read operation        */

/*
******************************************************************************
* RFAL FEATURES CONFIGURATION
******************************************************************************
*/

#define RFAL_FEATURE_NFCA                       false                   /*!< Enable/Disable RFAL support for NFC-A (ISO14443A)                         */
#define RFAL_FEATURE_NFCB                       false                   /*!< Enable/Disable RFAL support for NFC-B (ISO14443B)                         */
#define RFAL_FEATURE_NFCF                       false                   /*!< Enable/Disable RFAL support for NFC-F (FeliCa)                            */
#define RFAL_FEATURE_NFCV                       true                    /*!< Enable/Disable RFAL support for NFC-V (ISO15693)                          */
#define RFAL_FEATURE_T1T                        false                   /*!< Enable/Disable RFAL support for T1T (Topaz)                               */
#define RFAL_FEATURE_ST25TB                     false                   /*!< Enable/Disable RFAL support for ST25TB                                    */
#define RFAL_FEATURE_DYNAMIC_ANALOG_CONFIG      true                    /*!< Enable/Disable Analog Configs to be dynamically updated (RAM)             */
#define RFAL_FEATURE_DYNAMIC_POWER              false                   /*!< Enable/Disable RFAL dynamic power support                                 */
#define RFAL_FEATURE_ISO_DEP                    false                   /*!< Enable/Disable RFAL support for ISO-DEP (ISO14443-4)                      */
#define RFAL_FEATURE_NFC_DEP                    false                   /*!< Enable/Disable RFAL support for NFC-DEP (NFCIP1/P2P)                     */


#define RFAL_FEATURE_ISO_DEP_IBLOCK_MAX_LEN     256                     /*!< ISO-DEP I-Block max length. Please use values as defined by rfalIsoDepFSx */
#define RFAL_FEATURE_ISO_DEP_APDU_MAX_LEN       1024                    /*!< ISO-DEP APDU max length. Please use multiples of I-Block max length       */
#define RFAL_FEATURE_NFC_RF_BUF_LEN             258U                    /*!< RF buffer length used by RFAL NFC layer                                   */

#ifdef __cplusplus
}
#endif

#endif /* RFAL_PLATFORM_H */

