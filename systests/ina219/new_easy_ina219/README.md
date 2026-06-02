# Raspberry Pi - GoPiGo3 Python Library for Voltage and Current Sensors Using the INA219

### This is a special multi-threaded/multi-processing protected version for Raspberry Pi GoPiGo3 robots

### For PiOS Trixie 64-bit and Ubuntu 26.04 as of 2026-06 

Uses the DexterIndustries R4RTools file di_i2c.py to provide the I2C interface between   
the Raspberry Pi DMA GPIO controller chip and the INA219 sensor.  

Requires:   ```pip3 install pi-ina219``` for the base ina219 driver  
Requires:   ```pip3 install smbus``` for the base ina219 driver
Requires:   easy_ina219.py be in ~/<repo>/plib

 
Additional changes:  
- EasyINA219() class offers I2C Mutex protected access to the most used methods of the INA219 sensor  


EasyINA219 class:  

```
       The EasyINA219 object provides mutex protected (Hardware I2C only) access to the INA219 Voltage and Current Sensor
       for GoPiGo3 robots.   (Hardware I2C only to be compatible with Raspberry Pi5 GoPiGo3 robots)

       Mutex protection allows multiple simultaneous threads/processes to use the INA219A sensor without I2C bus issues.

       Note: EasyINA219.ina219.xx() provides unprotected access to full INA219 class methods, but use is not recommended.

METHODS:
  EasyINA219 unique methods with I2C mutex protection:
      ave_volts()    : volts - average of 3 readings supply_voltage() 0.02s apart
      ave_milliamps(): mA - average of 3 readings 0.02s apart
      ave_watts()    : W  - average of 3 readings 0.02s apart

  Protected INA219 methods:
      volts()       : volts - single INA219.supply_voltage()
      milliamps():  : mA    - single INA219.current(), same as INA219.bus_current
      watts()       : Watts - single INA219.power()/1000

USAGE:
    import sys
    sys.path.prefix(1,"/home/ubuntu/LyricalDave/plib")
    import easy_ina219


    ina = EasyINA219()

    print("Current (bus)      : %.0f mA" % ina.milliamps())
    print("Ave Current (bus)  : %.0f mA" % ina.ave_milliamps())
    print("Supply Voltage     : %.2f V" % ina.volts())
    print("Ave Supply Voltage : %.2f V" % ina.ave_volts())
    print("Power              : %.1f W" % ina.watts())
    print("Ave Power          : %.1f W" % ina.ave_watts())

```

INA219 class:
 
REF:  https://pypi.org/project/pi-ina219/

When using the ina219.INA219() class directly, setting logging=logging.ERROR is advised
(logging=NONE will generate an error)
