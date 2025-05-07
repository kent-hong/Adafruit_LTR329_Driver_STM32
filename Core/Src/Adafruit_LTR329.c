/*
 * @file Adafruit_LTR329.c
 *
 *  #mainpage Adafruit LTR329 I2C Light Sensorso_sec Introduction
 *
 *    I2C Driver for the LTR329 I2C Light Sensors
 *
 *    This is a library for the Adafruit LTR329 breakout:
 *    https://www.adafruit.com/product/5591
 *
 *    @section author Author
 *
 *    Kent Hong, Gabriel Dao, Kyle Tsai (SharkSat-1)
 */

#include "stm32l4xx_hal.h"
#include "Adafruit_LTR329.h"
#include <stdbool.h>
#include <stdint.h>

/*!
 *   @brief  Setups the hardware for talking to the LTR329
 *   @param  *hi2c An optional pointer to an I2C interface
 *   @return True if initialization was successful, otherwise false.
 */
bool begin(Adafruit_LTR329_t *sensor, I2C_HandleTypeDef *hi2c, uint8_t i2c_addr) {
	uint8_t part_id = 0;

	// Save I2C handle and sensor address in struct
	sensor->hi2c = hi2c;
	sensor->i2c_addr = i2c_addr;

	// Try to read the PART ID register
	if (HAL_I2C_Mem_Read(sensor->hi2c, sensor->i2c_addr, LTR329_PART_ID, I2C_MEMADD_SIZE_8BIT, &part_id, 1, HAL_MAX_DELAY) != HAL_OK) {
		return false; // Failed to read PART ID
	}

	// Check if the returned ID matches what we expect
	if (part_id != LTR329_PART_ID_DEFAULT) {
		return false; // Invalid PART ID
	}

	return true; // Initialization successful
}


