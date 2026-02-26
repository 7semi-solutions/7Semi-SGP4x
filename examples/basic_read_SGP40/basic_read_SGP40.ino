/**
 * 7Semi Example: Basic SGP41 Reading
 *
 * I2C Connection:
 * - VCC  → 3.3V or 5V (check module specification)
 * - GND  → GND
 * - SDA  → SDA
 * - SCL  → SCL
 *
 * Default I2C Address:
 * - 0x59
 *
 * Description:
 * - Reads raw VOC and NOx signals
 * - Uses default compensation internally
 */

#include <7Semi_SGP4x.h>

SGP4x_7Semi sgp(SGP4x_7Semi::SGP41_SENSOR);

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    if (!sgp.begin())
    {
        Serial.println("SGP41 not detected");
        while (1);
    }

    Serial.println("SGP41 Ready");
}

void loop()
{
    uint16_t voc, nox;

    if (sgp.readRawSignalSGP41(voc, nox))
    {
        Serial.print("VOC Raw: ");
        Serial.print(voc);
        Serial.print("  NOx Raw: ");
        Serial.println(nox);
    }
    else
    {
        Serial.println("Read Error");
    }

    delay(1000);
}