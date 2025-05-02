/*
 * Adafruit_LTR329.h
 *
 * I2C Driver for the LTR329 I2C Light Sensors
 *
 * This is a library for the Adafruit LTR329 breakouts:
 * https://www.adafruit.com/product/5591
 *
 * The following code was manually ported from Adafruit's LTR329
 * Arduino C++ driver to work with STM32 HAL in C.
 *
 *
 * Authors: Kent Hong, Gabriel Dao, Kyle Tran
 */

#ifndef INC_ADAFRUIT_LTR329_H_
#define INC_ADAFRUIT_LTR329_H_

#include "stm32l4xx_hal.h"
#include "main.h"
#include <stdint.h>
#include <stdbool.h>

/*!   @brief LTR329 I2C Slave Address */
#define LTR329_I2CADDR_DEFAULT 0x29 ///< I2C slave address (7-bit address)
#define LTR329_I2CADDR_8BIT    (LTR329_I2CADDR_DEFAULT << 1) ///< I2C address shifted for 8-bit address space (STM32 HAL only accepts 8-bit addresses)

/*!   @brief LTR329 Register Addresses */
#define LTR329_PART_ID_REGISTER         0x86 ///< Part id/revision register
#define LTR329_MANU_ID_REGISTER         0x87 ///< Manufacturer ID register
#define LTR329_ALS_CTRL_REGISTER        0x80 ///< ALS control register
#define LTR329_STATUS_REGISTER          0x8C ///< Status register
#define LTR329_CH1DATA_0_REGISTER       0x88 ///< Data for channel 1, lower byte. Read. (can read all 4 bytes using only this starting address!)
#define LTR329_CH1DATA_1_REGISTER       0x89 ///< Data for channel 1, upper byte. Read.
#define LTR329_CH0DATA_0_REGISTER       0x8A ///< Data for channel 0, lower byte. Read.
#define LTR329_CH0DATA_1_REGISTER       0x8B ///< Data for channel 0, upper byte. Read.
#define LTR329_MEAS_RATE_REGISTER       0x85 ///< Integration time and data rate

/*!   @brief LTR329 I2C Slave Address default values */
#define LTR329_I2CADDR_WRITE_VALUE 0x52 ///< I2C default value for write
#define LTR329_I2CADDR_READ_VALUE  0x53 ///< I2C default value for read

/*!   @brief LTR329 Register Reset Values */
#define LTR329_PART_ID_RESET_VALUE   0xA0 ///< Default value for PART_ID register
#define LTR329_MANU_ID_RESET_VALUE   0x05 ///< Default value for MANUFACTURER_ID register
#define LTR329_ALS_CTRL_RESET_VALUE  0x00 ///< Default value for ALS_CTRL register
#define LTR329_STATUS_RESET_VALUE   0x00 ///< Default value for STATUS register
#define LTR329_CH1DATA_0_RESET_VALUE 0x00 ///< Default value for CH1DATA_0 register
#define LTR329_CH1DATA_1_RESET_VALUE 0x00 ///< Default value for CH1DATA_1 register
#define LTR329_CH0DATA_0_RESET_VALUE 0x00 ///< Default value for CH0DATA_0 register
#define LTR329_CH0DATA_1_RESET_VALUE 0x00 ///< Default value for CH0DATA_1 register
#define LTR329_MEAS_RATE_RESET_VALUE 0x03 ///< Default value for MEAS_RATE register


/*!   @brief Sensor gain for ALS */
typedef enum {
	LTR3XX_GAIN_1  = 0,
	LTR3XX_GAIN_2  = 1,
	LTR3XX_GAIN_4  = 2,
	LTR3XX_GAIN_8  = 3,
	// 4 & 5 unused!
	LTR3XX_GAIN_48 = 6,
	LTR3XX_GAIN_96 = 7,
}; ltr329_gain_t;

/*!   @brief Integration times, in milliseconds */
typedef enum {
	LTR3XX_INTEGTIME_100 = 0,
	LTR3XX_INTEGTIME_50 =  1,
	LTR3XX_INTEGTIME_200 = 2,
	LTR3XX_INTEGTIME_400 = 3,
	LTR3XX_INTEGTIME_150 = 4,
	LTR3XX_INTEGTIME_250 = 5,
	LTR3XX_INTEGTIME_300 = 6,
	LTR3XX_INTEGTIME_350 = 7,
}; ltr329_integrationtime_t;

/*!   @brief Measurement rates, in milliseconds */
typedef enum {
	LTR3XX_MEASRATE_50   = 0,
	LTR3XX_MEASRATE_100  = 1,
	LTR3XX_MEASRATE_200  = 2,
	LTR3XX_MEASRATE_500  = 3,
	LTR3XX_MEASRATE_1000 = 4,
	LTR3XX_MEASRATE_2000 = 5,
}; ltr329_measurerate_t;

/*!
 *    @brief  Struct that stores states for interacting with
 *            LTR329 Light Sensor
 */
typedef struct {
	I2C_HandleTypeDef *hi2c; ///< I2C handle
	uint8_t i2caddr;         ///< I2C address
}; Adafruit_LTR329_t;

/*!  @brief Function headers */
bool begin(Adafruit_LTR329_t *sensor, I2C_HandleTypeDef *hi2c); ///< I2C begin function

#endif /* INC_ADAFRUIT_LTR329_H_ */
