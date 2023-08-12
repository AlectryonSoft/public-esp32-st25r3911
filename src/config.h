#ifndef CONFIG_H
#define CONFIG_H

  //#define WIFI_REV2_USED (LED_BUILTIN == 25)
  #define METRO_ESP32_S2  (LED_BUILTIN == 42)

  #ifdef METRO_ESP32_S2
    #define SPI_MOSI    (uint8_t)16  //No need to define them, it's default in the SPI
    #define SPI_MISO    (uint8_t)21
    #define SPI_SCK     (uint8_t)42
    #define SPI_SS      (uint8_t)15  //Default is 42 
    #define IRQ_PIN     (uint8_t)17
    
    #define MCU_LED1    (uint8_t)18
    #define MCU_LED2    (uint8_t)1
    #define MCU_LED3    (uint8_t)2
    #define MCU_LED5    (uint8_t)9
  #endif
#endif
