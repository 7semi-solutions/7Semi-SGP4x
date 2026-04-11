/**
 * 7Semi Example: Basic SGP40 Reading
 *
 * I2C Connection:
 * - VCC  → 3.3V or 5V (check your module)
 * - GND  → GND
 * - SDA  → Arduino SDA pin
 * - SCL  → Arduino SCL pin
 *
 * Default I2C Address:
 * - 0x59
 *
 * Description:
 * - Reads raw VOC signal every 1 second
 * - No humidity compensation used
 */

#include <Wire.h>
#include <7Semi_SGP4x.h>

SGP4x_7Semi sgp(SGP4x_7Semi::SGP40_SENSOR);

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    if (!sgp.begin())
    {
        Serial.println("SGP40 not detected");
        while (1);
    }

    Serial.println("SGP40 Ready");
}

void loop()
{
    uint16_t voc;

    if (sgp.readVOC(voc))
    {
        Serial.print("VOC Raw: ");
        Serial.println(voc);
    }
    else
    {
        Serial.println("Read Error");
    }

    delay(1000);
}