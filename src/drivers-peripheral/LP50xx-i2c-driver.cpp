#include "LP50xx-i2c-driver.h"


LP50xx::LP50xx()
{
    i2c_handle = ;
    i2c_address = ;
}




void LP50xx::enable()
{
    data_to_send = CHIP_EN;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, DEVICE_CONFIG0, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}

void LP50xx::config(uint8_t configValue)
{
    data_to_send = configValue;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, DEVICE_CONFIG1, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}

void LP50xx::reset()
{
    data_to_send = RESET_VALUE;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, RESET, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}




void LP50xx::bankConfig(uint8_t bankConfigValue)
{
    data_to_send = bankConfigValue;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, LED_CONFIG, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}

void LP50xx::setBankBrightness(uint8_t bankBrightnessValue)
{
    data_to_send = bankBrightnessValue;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, BANK_BRIGHTNESS, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}

void LP50xx::setBankColor(uint8_t bankColorValue)
{
    data_to_send = bankColorValue;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, XXX, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}



void LP50xx::setLEDBrightness(uint8_t LEDBrightnessValue)
{
    data_to_send = LEDBrightnessValue;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, XXX, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}

void LP50xx::setOutColor(uint8_t outColorValue)
{
    data_to_send = outColorValue;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, XXX, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}



void LP50xx::registerWrite(uint8_t value)
{
    data_to_send = value;
    HAL_I2C_Mem_Write(&i2c_handle, i2c_address, XXX, I2C_MEMADD_SIZE_8BIT, &data_to_send, 1, HAL_MAX_DELAY);
}

uint8_t LP50xx::registerRead(uint8_t reg)
{
    uint8_t dataRead;
    HAL_I2C_Mem_Read(&i2c_handle, i2c_address, reg, I2C_MEMADD_SIZE_8BIT, &dataRead, 1, HAL_MAX_DELAY);
    return dataRead;
}