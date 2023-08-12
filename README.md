# public-esp32-st25r3911
This is an example of the st25r3911 implementation on the ESP32-S2 (METRO ESP32-S2 Express) + PlatformIO to read NFCV tags.

We contribute this implementation so you don't have to check around for too long like we did.

# Setup

config.h contains the GPIO definitions for the SPI.

It is currently set to work with the X-NUCLEO-NFC05A1.

It is configured to read NFCV tags. 

The RFAL lib can be configured in the src/rfal_platform/rfal_platform.h file.

# ST RFAL implementation

- src/rfal_core
- src/rfal_core/st25r3911
- src/rfal_platform

# Debug Output:

Each step returns the NFC lib error code.
The uid represent the unique id of the nfc device.

```text
init
0
Worker
init poller
0
field on and start GT
0
Inventorying... 
0
uid: 9186832468014224
```