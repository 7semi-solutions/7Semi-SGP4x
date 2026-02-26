# 7Semi SGP40/SGP41

Arduino library for Sensirion SGP40 and SGP41 gas sensors.

- Library name: 7Semi_SGP4x
- Supported sensors:
  - SGP40 (VOC)
  - SGP41 (VOC + NOx)
- Interface: I2C

------------------------------------------------------------

## Features

- CRC8 data validation
- SGP41 conditioning support
- Humidity and temperature compensation
- Heater control
- Serial number reading
- Simple VOC / NOx index helpers

------------------------------------------------------------

## Installation

1. Download this repository as a ZIP.
2. Arduino IDE → Sketch → Include Library → Add .ZIP Library…
3. Ensure Wire library is available (default in Arduino).

No additional dependencies required.

------------------------------------------------------------

## Quick Start (SGP41 Example)

```cpp
#include <Wire.h>
#include <7Semi_SGP4x.h>

SGP4x_7Semi sgp;

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    if (!sgp.begin())
    {
        Serial.println("SGP4x not detected");
        while (1);
    }
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

    delay(1000);
}
