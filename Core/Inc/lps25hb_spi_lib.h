/*
 * lps25hb_spi_lib.h
 *
 *  Created on: 26 sie 2021
 *      Author: Kacper Janowski
 */

#ifndef INC_LPS25HB_SPI_LIB_H_
#define INC_LPS25HB_SPI_LIB_H_

#include "stm32f7xx_hal.h"
#include "stdint.h"

#define LPS25_SPI  					SPI2
#define LPS25_SPI_GPIOA 			GPIOA      //MEMS2 GPIO port for SPI
#define LPS25_SPI_GPIOB 			GPIOB      //MEMS2 GPIO port for SPI

#define LPS25_SS   					GPIO_PIN_11	   //SPI SS  (CS)
#define LPS25_SCK  					GPIO_PIN_12    //SPI SCK (SCL)
#define LPS25_MISO 					GPIO_PIN_14    //SPI MISO (SDO)
#define LPS25_MOSI 					GPIO_PIN_15    //SPI MOSI (SDI in 4 wire SPI or SDI/SDO 3 wire SPI)

typedef enum {
  LPS25_DISABLE = 0,
  LPS25_ENABLE  = 1
} LPS25_bool;

#define LPS25_ERROR 				1
#define LPS25_OK 					0

#define LPS25_WRITE        			0     //SPI
#define LPS25_READ         			0x80  //SPI
#define LPS25_ADDR_NO_INC  			0
#define LPS25_ADDR_INC_SPI 			0x40  //SPI


#define LPS25_PRESS_OUT_XL 			0x28 //preassure, read only
#define LPS25_PRESS_OUT_L  			0x29
#define LPS25_PRESS_OUT_H  			0x2A
#define LPS25_TEMP_OUT_L			0x2B //temperature, read only
#define LPS25_TEMP_OUT_H			0x2C


#define LPS25_REF_P_XL      		0x08
#define LPS25_REF_P_L       		0x09
#define LPS25_REF_P_H       		0x0A

#define LPS25_WHO_AM_I     		 	0x0F //read only

#define LPS25_CTRL_REG1     		0x20
#define LPS25_CTRL_REG2    		 	0x21
#define LPS25_CTRL_REG3     		0x22
#define LPS25_CTRL_REG4     		0x23

#define LPS25_CTRL_REG1_PD_Active   0x1<<7  //PD (Power Down) bit = 1, active mode

typedef enum {
 Rate_OneShot  = 0x0<<4,
 Rate_1Hz      = 0x1<<4,
 Rate_7Hz      = 0x2<<4,
 Rate_12Hz5    = 0x3<<4,
 Rate_25Hz     = 0x4<<4
} LPS25_ODR_TypeDef;


#define LPS25_CTRL_REG1_DIFF_EN       0x1<<3
#define LPS25_CTRL_REG1_BDU           0x1<<2
#define LPS25_CTRL_REG1_RESET_AZ      0x1<<1  //reset (disable) autozero function

typedef enum {
  SPI4w    = 0x0,   //use 4 wire SPI
  SPI3w    = 0x1    //use 3 wire SPI
} LPS25_SPIMode_TypeDef;

#define LPS25_CTRL_REG2_BOOT          0x1<<7
#define LPS25_CTRL_REG2_FIFO_EN       0x1<<6  //enable FIFO
#define LPS25_CTRL_REG2_STOP_ON_FTH   0x1<<5
#define LPS25_CTRL_REG2_FIFO_MEAN_DEC 0x1<<4  //in FIFO Mean mode, return results at 1Hz, regardless of ODR settings
#define LPS25_CTRL_REG2_I2C_DIS       0x1<<3  //disable I2C
#define LPS25_CTRL_REG2_SWRESET       0x1<<2  //soft reset
#define LPS25_CTRL_REG2_AUTOZERO      0x1<<1  //enable autozero and set REF_P_ registers
#define LPS25_CTRL_REG2_ONE_SHOT      0x1     //perform one measure in One Shot mode

#define LPS25_INTERRUPT_CFG 		0x24
#define LPS25_INT_SOURCE    		0x25 //read only

#define LPS25_STATUS_REG    		0x27

#define LPS25_FIFO_CTRL     		0x2E

#define LPS25_FIFO_STATUS   		0x2F //read only

#define LPS25_THS_P_L       		0x30
#define LPS25_THS_P_H       		0x31

#define LPS25_RPDS_L        		0x39
#define LPS25_RPDS_H        		0x3A


char LPS25_SPI_Init(LPS25_ODR_TypeDef ODRMode, LPS25_SPIMode_TypeDef SPIMode);
void LPS25_SPI_ReadRegister(unsigned char addr, unsigned char *v);
void LPS25_SPI_WriteRegister(unsigned char addr, unsigned char v);
void LPS25_SPI_GetPress(int32_t* Pressure);
void LPS25_SPI_GetTemp(int16_t* Temperature);

#endif /* INC_LPS25HB_SPI_LIB_H_ */
