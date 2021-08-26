/*
 * lps25hb_spi_lib.c
 *
 *  Created on: 26 sie 2021
 *      Author: Kacper Janowski
 */

#include "lps25hb_spi_lib.h"


SPI_HandleTypeDef hspi2;
LPS25_SPIMode_TypeDef gSPIMode;  //global SPIMode

//Set NSS line low, activate slave
void SPI_NSS_Enable(void)
{
	HAL_GPIO_WritePin(LPS25_SPI_GPIOA, LPS25_SS, GPIO_PIN_RESET);
}

//Set NSS line high, deactivate slave
void SPI_NSS_Disable(void)
{
	HAL_GPIO_WritePin(LPS25_SPI_GPIOA, LPS25_SS, GPIO_PIN_SET);
}

//LPS25 initialization
char LPS25_SPI_Init(LPS25_ODR_TypeDef ODRMode, LPS25_SPIMode_TypeDef SPIMode)
{
  unsigned char RegVal = 0, LPS25Settings;

  gSPIMode = SPIMode;

  //soft reset LPS25, enable SPI, disable I2C
  LPS25_SPI_WriteRegister(LPS25_CTRL_REG2, LPS25_CTRL_REG2_SWRESET);
  HAL_Delay(100);
  LPS25_SPI_WriteRegister(LPS25_CTRL_REG1, gSPIMode);
  LPS25_SPI_WriteRegister(LPS25_CTRL_REG2, LPS25_CTRL_REG2_I2C_DIS);

  //PowerUp and write settings
  LPS25Settings = LPS25_CTRL_REG1_PD_Active | ODRMode | LPS25_CTRL_REG1_BDU | gSPIMode;
  LPS25_SPI_WriteRegister(LPS25_CTRL_REG1, LPS25Settings);

  //Read LPS25 self identifier - if 0xBD read back, LPS25 is up and running
  LPS25_SPI_ReadRegister(LPS25_WHO_AM_I, &RegVal);
  if (RegVal == 0xBD) return LPS25_OK;
  else return LPS25_ERROR;
}

//Reads one register value from LPS25
void LPS25_SPI_ReadRegister(unsigned char addr, unsigned char *v)
{
	unsigned char DataReceived = 0;
	unsigned char DataToTransmit;

	DataToTransmit = LPS25_READ|LPS25_ADDR_NO_INC|addr;

	SPI_NSS_Enable();
	HAL_SPI_Transmit(&hspi2, &DataToTransmit, 1, 50);
	if (gSPIMode==SPI3w) {HAL_SPI_Receive(&hspi2,  &DataReceived, 1, 50);}
	HAL_SPI_Receive(&hspi2,  &DataReceived, 1, 50);
	SPI_NSS_Disable();
	*v=DataReceived;
}

//Writes one register value to LPS25
void LPS25_SPI_WriteRegister(unsigned char addr, unsigned char v)
{
	unsigned char DataToTransmit[2];

	DataToTransmit[0] = LPS25_WRITE|LPS25_ADDR_NO_INC|addr;
	DataToTransmit[1] = v;

	SPI_NSS_Enable();
	HAL_SPI_Transmit(&hspi2, DataToTransmit, 2, 50);
	SPI_NSS_Disable();
}

void LPS25_SPI_GetPress(int32_t* Pressure)
{
	unsigned char DataReceived[3] = {0};
	unsigned char DataToTransmit;

	//Read 3 consecutive registers in autoincrement mode starting from LPS25_PRESS_OUT_XL
	DataToTransmit = LPS25_READ|LPS25_ADDR_INC_SPI|LPS25_PRESS_OUT_XL;
	SPI_NSS_Enable();
    HAL_SPI_Transmit(&hspi2, &DataToTransmit, 1, 50);
    if (gSPIMode == SPI3w) {HAL_SPI_Receive(&hspi2, DataReceived, 1, 50);}
    HAL_SPI_Receive(&hspi2, DataReceived, 3, 50);
	SPI_NSS_Disable();

	*Pressure = 0;
    *Pressure=(int32_t)(((uint32_t)DataReceived[2] << 16) + ((uint32_t)DataReceived[1] << 8) + ((uint32_t)DataReceived[0]));
    if(DataReceived[2] & 0x80){*Pressure |= 0xFF000000; } //correction of upper bits of 32-bit value when pressure is negative to maintain proper 2's complement handling
}

void LPS25_SPI_GetTemp(int16_t* Temperature)
{
	unsigned char DataReceived[2] = {0};
	unsigned char DataToTransmit;

	//Read 2 consecutive registers in autoincrement mode starting from LPS25_TEMP_OUT_L
	DataToTransmit = LPS25_READ|LPS25_ADDR_INC_SPI|LPS25_TEMP_OUT_L;
	SPI_NSS_Enable();
    HAL_SPI_Transmit(&hspi2, &DataToTransmit, 1, 50);
    if (gSPIMode == SPI3w) {HAL_SPI_Receive(&hspi2, DataReceived, 1, 50);}
    HAL_SPI_Receive(&hspi2, DataReceived, 2, 50);
	SPI_NSS_Disable();

	*Temperature=(int16_t)(((uint16_t)DataReceived[1] << 8)+((uint16_t)DataReceived[0]));
}
