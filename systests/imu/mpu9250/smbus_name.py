#!/usr/bin/env python3

from smbus2 import SMBus

# Constants for MPU9250
I2C_BUS = 1            # 1 for Raspberry Pi, adjust as needed
DEVICE_ADDRESS = 0x68  # or 0x69 depending on ADO pin
WHO_AM_I_REG = 0x75    # WHO_AM_I register address
EXPECTED_ID = 0x71     # Default MPU9250 ID

# Connect to the I2C bus and read the register
with SMBus(I2C_BUS) as bus:
    device_id = bus.read_byte_data(DEVICE_ADDRESS, WHO_AM_I_REG)

print(f"Device ID returned: {hex(device_id)}")

if device_id == EXPECTED_ID:
    print("Success: MPU9250 detected!")
else:
    print("Warning: ID does not match MPU9250 (0x71).")
    print("Note: 0x70 indicates MPU6500, 0x73 indicates MPU9255.")

