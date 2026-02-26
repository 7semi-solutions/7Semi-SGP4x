/**
 * 7Semi Example: SGP41 Conditioning Procedure
 *
 * I2C Connection:
 * - VCC → 3.3V or 5V
 * - GND → GND
 * - SDA → SDA
 * - SCL → SCL
 *
 * Important:
 * - Conditioning must run 10 times
 * - Must be executed once per second
 * - Required after power-up or heater OFF
 */

#include <Wire.h>
#include <7Semi_SGP4x.h>

SGP4x_7Semi sgp;

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    if (!sgp.begin())
    {
        Serial.println("Sensor not detected");
        while (1);
    }

    Serial.println("Starting Conditioning...");

    uint16_t voc, nox;
    sgp.readRawSignalSGP41(voc, nox);

    for (int i = 0; i < 10; i++)
    {
        sgp.executeConditioning(50.0f, 25.0f, voc);
        delay(1000);
    }

    Serial.println("Conditioning Complete");
}

void loop()
{
    uint16_t voc;

    if (sgp.readVOCComp(50.0f, 25.0f, voc))
    {
        Serial.print("VOC Raw: ");
        Serial.println(voc);
    }

    delay(1000);
}