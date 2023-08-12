#include <Arduino.h>

#include "rfal_platform/rfal_platform.h"

extern "C" {
#include "rfal_core/rfal_nfca.h"
#include "rfal_core/rfal_nfcb.h"
#include "rfal_core/rfal_nfcf.h"
#include "rfal_core/rfal_nfcv.h"
#include "rfal_core/rfal_isoDep.h"
#include "rfal_core/rfal_nfcDep.h"
#include "rfal_core/rfal_analogConfig.h"
}

// REFERENCE: https://www.st.com/resource/en/user_manual/um2890-rfnfc-abstraction-layer-rfal-stmicroelectronics.pdf
// ISO 15693

void setup() {
    Serial.begin(115200);
    spi_init();
}

void loop() {

    Serial.println("init");
    ReturnCode ret = rfalInitialize();

    Serial.println(ret);

    Serial.println("Worker");

    // put your main code here, to run repeatedly:
    rfalWorker(); //TODO: put in a separate thread

    Serial.println("init poller");

    ret = rfalNfcvPollerInitialize(); // TODO check return code

    Serial.println(ret);

    Serial.println("field on and start GT");

    ret = rfalFieldOnAndStartGT(); // TODO check return code

    Serial.println(ret);

    rfalNfcvInventoryRes inventory; // TODO check return code

    Serial.println("Inventorying... ");
    ret = rfalNfcvPollerCheckPresence(&inventory); // TODO check return code

    Serial.println(ret);

    Serial.print("uid: ");
    for (size_t i = 0; i < 8; i++)
    {
        Serial.print(inventory.UID[i]);
    }
    
    vTaskDelay(1000);
}