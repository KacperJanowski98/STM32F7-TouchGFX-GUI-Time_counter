/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../mx25l512/mx25l512.h"
#include "../otm8009a/otm8009a.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define REFRESH_COUNT        1834
#define SDRAM_TIMEOUT                            ((uint32_t)0xFFFF)
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)

/* QSPI Error codes */
#define QSPI_OK            ((uint8_t)0x00)
#define QSPI_ERROR         ((uint8_t)0x01)
#define QSPI_BUSY          ((uint8_t)0x02)
#define QSPI_NOT_SUPPORTED ((uint8_t)0x04)
#define QSPI_SUSPENDED     ((uint8_t)0x08)

/* DISPLAY */
#define LCD_ORIENTATION_LANDSCAPE 0x01
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

CRC_HandleTypeDef hcrc;

DMA2D_HandleTypeDef hdma2d;

DSI_HandleTypeDef hdsi;

I2C_HandleTypeDef hi2c4;

LTDC_HandleTypeDef hltdc;

QSPI_HandleTypeDef hqspi;

SDRAM_HandleTypeDef hsdram1;

/* Definitions for TouchGFXTask */
osThreadId_t TouchGFXTaskHandle;
const osThreadAttr_t TouchGFXTask_attributes = {
  .name = "TouchGFXTask",
  .stack_size = 4096 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskTimeSingle */
osThreadId_t TaskTimeSingleHandle;
const osThreadAttr_t TaskTimeSingle_attributes = {
  .name = "TaskTimeSingle",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskFreqSingle */
osThreadId_t TaskFreqSingleHandle;
const osThreadAttr_t TaskFreqSingle_attributes = {
  .name = "TaskFreqSingle",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskTimeConst */
osThreadId_t TaskTimeConstHandle;
const osThreadAttr_t TaskTimeConst_attributes = {
  .name = "TaskTimeConst",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskFreqConst */
osThreadId_t TaskFreqConstHandle;
const osThreadAttr_t TaskFreqConst_attributes = {
  .name = "TaskFreqConst",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskTimeStamps */
osThreadId_t TaskTimeStampsHandle;
const osThreadAttr_t TaskTimeStamps_attributes = {
  .name = "TaskTimeStamps",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskFreqStamps */
osThreadId_t TaskFreqStampsHandle;
const osThreadAttr_t TaskFreqStamps_attributes = {
  .name = "TaskFreqStamps",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskResetParamT */
osThreadId_t TaskResetParamTHandle;
const osThreadAttr_t TaskResetParamT_attributes = {
  .name = "TaskResetParamT",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskDetectThreT */
osThreadId_t TaskDetectThreTHandle;
const osThreadAttr_t TaskDetectThreT_attributes = {
  .name = "TaskDetectThreT",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskDetectThreF */
osThreadId_t TaskDetectThreFHandle;
const osThreadAttr_t TaskDetectThreF_attributes = {
  .name = "TaskDetectThreF",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskResetParamF */
osThreadId_t TaskResetParamFHandle;
const osThreadAttr_t TaskResetParamF_attributes = {
  .name = "TaskResetParamF",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskCalibration */
osThreadId_t TaskCalibrationHandle;
const osThreadAttr_t TaskCalibration_attributes = {
  .name = "TaskCalibration",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskTimeRepeat */
osThreadId_t TaskTimeRepeatHandle;
const osThreadAttr_t TaskTimeRepeat_attributes = {
  .name = "TaskTimeRepeat",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskFreqRepeat */
osThreadId_t TaskFreqRepeatHandle;
const osThreadAttr_t TaskFreqRepeat_attributes = {
  .name = "TaskFreqRepeat",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myBinarySemGetTimeSingle */
osSemaphoreId_t myBinarySemGetTimeSingleHandle;
const osSemaphoreAttr_t myBinarySemGetTimeSingle_attributes = {
  .name = "myBinarySemGetTimeSingle"
};
/* Definitions for myBinarySemGetFreqSingle */
osSemaphoreId_t myBinarySemGetFreqSingleHandle;
const osSemaphoreAttr_t myBinarySemGetFreqSingle_attributes = {
  .name = "myBinarySemGetFreqSingle"
};
/* Definitions for myBinarySemGetTimeConst */
osSemaphoreId_t myBinarySemGetTimeConstHandle;
const osSemaphoreAttr_t myBinarySemGetTimeConst_attributes = {
  .name = "myBinarySemGetTimeConst"
};
/* Definitions for myBinarySemGetFreqConst */
osSemaphoreId_t myBinarySemGetFreqConstHandle;
const osSemaphoreAttr_t myBinarySemGetFreqConst_attributes = {
  .name = "myBinarySemGetFreqConst"
};
/* Definitions for myBinarySemGetTimeStamps */
osSemaphoreId_t myBinarySemGetTimeStampsHandle;
const osSemaphoreAttr_t myBinarySemGetTimeStamps_attributes = {
  .name = "myBinarySemGetTimeStamps"
};
/* Definitions for myBinarySemGetFreqStamps */
osSemaphoreId_t myBinarySemGetFreqStampsHandle;
const osSemaphoreAttr_t myBinarySemGetFreqStamps_attributes = {
  .name = "myBinarySemGetFreqStamps"
};
/* Definitions for myBinarySemResetParamT */
osSemaphoreId_t myBinarySemResetParamTHandle;
const osSemaphoreAttr_t myBinarySemResetParamT_attributes = {
  .name = "myBinarySemResetParamT"
};
/* Definitions for myBinarySemUpdateTimeDisp */
osSemaphoreId_t myBinarySemUpdateTimeDispHandle;
const osSemaphoreAttr_t myBinarySemUpdateTimeDisp_attributes = {
  .name = "myBinarySemUpdateTimeDisp"
};
/* Definitions for myBinarySemDetectThreTime */
osSemaphoreId_t myBinarySemDetectThreTimeHandle;
const osSemaphoreAttr_t myBinarySemDetectThreTime_attributes = {
  .name = "myBinarySemDetectThreTime"
};
/* Definitions for myBinarySemDetectThreFreq */
osSemaphoreId_t myBinarySemDetectThreFreqHandle;
const osSemaphoreAttr_t myBinarySemDetectThreFreq_attributes = {
  .name = "myBinarySemDetectThreFreq"
};
/* Definitions for myBinarySemResetParamF */
osSemaphoreId_t myBinarySemResetParamFHandle;
const osSemaphoreAttr_t myBinarySemResetParamF_attributes = {
  .name = "myBinarySemResetParamF"
};
/* Definitions for myBinarySemCalibration */
osSemaphoreId_t myBinarySemCalibrationHandle;
const osSemaphoreAttr_t myBinarySemCalibration_attributes = {
  .name = "myBinarySemCalibration"
};
/* Definitions for myBinarySemUpdateFreqDisp */
osSemaphoreId_t myBinarySemUpdateFreqDispHandle;
const osSemaphoreAttr_t myBinarySemUpdateFreqDisp_attributes = {
  .name = "myBinarySemUpdateFreqDisp"
};
/* Definitions for myBinarySemGetTimeRepeat */
osSemaphoreId_t myBinarySemGetTimeRepeatHandle;
const osSemaphoreAttr_t myBinarySemGetTimeRepeat_attributes = {
  .name = "myBinarySemGetTimeRepeat"
};
/* Definitions for myBinarySemGetFreqRepeat */
osSemaphoreId_t myBinarySemGetFreqRepeatHandle;
const osSemaphoreAttr_t myBinarySemGetFreqRepeat_attributes = {
  .name = "myBinarySemGetFreqRepeat"
};
/* USER CODE BEGIN PV */

uint8_t conditionT = 1;
uint16_t conditionRepeatT = 1;
uint8_t conditionF = 1;
uint16_t conditionRepeatF = 1;

TimeMode_t TimeBackend;
ResultConstCalc_t ResultCalcConstTime;
ResultStampsCalc_t ResultCalcStampsTime;
ResultTime_t ResultTimeBackend;
FrequencyMode_t FreqBackend;
ResultFreq_t ResultFreqBackend;

uint32_t detectedThresholdTime = 0;
uint32_t detectedThresholdFreq = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
static void MX_GPIO_Init(void);
static void MX_CRC_Init(void);
static void MX_DSIHOST_DSI_Init(void);
static void MX_LTDC_Init(void);
static void MX_FMC_Init(void);
static void MX_QUADSPI_Init(void);
static void MX_DMA2D_Init(void);
void TouchGFX_Task(void *argument);
void StartTaskTimeSingle(void *argument);
void StartTaskFreqSingle(void *argument);
void StartTaskTimeConst(void *argument);
void StartTaskFreqConst(void *argument);
void StartTaskTimeStamps(void *argument);
void StartTaskFreqStamps(void *argument);
void StartTaskResetParamT(void *argument);
void StartTaskDetectThreT(void *argument);
void StartTaskDetectThreF(void *argument);
void StartTaskResetParamF(void *argument);
void StartTaskCalibration(void *argument);
void StartTaskTimeRepeat(void *argument);
void StartTaskFreqRepeat(void *argument);

/* USER CODE BEGIN PFP */
static void BSP_SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram, FMC_SDRAM_CommandTypeDef *Command);

static uint8_t QSPI_ResetMemory(QSPI_HandleTypeDef *hqspi);
static uint8_t QSPI_EnterMemory_QPI(QSPI_HandleTypeDef *hqspi);
static uint8_t QSPI_EnterFourBytesAddress(QSPI_HandleTypeDef *hqspi);
static uint8_t QSPI_DummyCyclesCfg(QSPI_HandleTypeDef *hqspi);
static uint8_t QSPI_OutDrvStrengthCfg(QSPI_HandleTypeDef *hqspi);
static uint8_t QSPI_WriteEnable(QSPI_HandleTypeDef *hqspi);
static uint8_t QSPI_AutoPollingMemReady  (QSPI_HandleTypeDef *hqspi, uint32_t Timeout);
static uint8_t BSP_QSPI_EnableMemoryMappedMode(QSPI_HandleTypeDef *hqspi);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void detectedThreshold(uint32_t *threshold)
{
	*threshold = (rand() % (1000 + 1 - 50)) + 50;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CRC_Init();
  MX_DSIHOST_DSI_Init();
  MX_LTDC_Init();
  MX_FMC_Init();
  MX_QUADSPI_Init();
  MX_DMA2D_Init();
  MX_I2C4_Init();
  MX_TouchGFX_Init();
  /* USER CODE BEGIN 2 */

  TimeModeInit(&TimeBackend);
  ResultTimeParameterConstInit(&ResultCalcConstTime);
  ResultTimeParameterStampsInit(&ResultCalcStampsTime);
  ResultTimeInit(&ResultTimeBackend);

  FrequencyModeInit(&FreqBackend);
  ResultFrequencyInit(&ResultFreqBackend);

  srand(time(NULL));

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of myBinarySemGetTimeSingle */
  myBinarySemGetTimeSingleHandle = osSemaphoreNew(1, 1, &myBinarySemGetTimeSingle_attributes);

  /* creation of myBinarySemGetFreqSingle */
  myBinarySemGetFreqSingleHandle = osSemaphoreNew(1, 1, &myBinarySemGetFreqSingle_attributes);

  /* creation of myBinarySemGetTimeConst */
  myBinarySemGetTimeConstHandle = osSemaphoreNew(1, 1, &myBinarySemGetTimeConst_attributes);

  /* creation of myBinarySemGetFreqConst */
  myBinarySemGetFreqConstHandle = osSemaphoreNew(1, 1, &myBinarySemGetFreqConst_attributes);

  /* creation of myBinarySemGetTimeStamps */
  myBinarySemGetTimeStampsHandle = osSemaphoreNew(1, 1, &myBinarySemGetTimeStamps_attributes);

  /* creation of myBinarySemGetFreqStamps */
  myBinarySemGetFreqStampsHandle = osSemaphoreNew(1, 1, &myBinarySemGetFreqStamps_attributes);

  /* creation of myBinarySemResetParamT */
  myBinarySemResetParamTHandle = osSemaphoreNew(1, 1, &myBinarySemResetParamT_attributes);

  /* creation of myBinarySemUpdateTimeDisp */
  myBinarySemUpdateTimeDispHandle = osSemaphoreNew(1, 1, &myBinarySemUpdateTimeDisp_attributes);

  /* creation of myBinarySemDetectThreTime */
  myBinarySemDetectThreTimeHandle = osSemaphoreNew(1, 1, &myBinarySemDetectThreTime_attributes);

  /* creation of myBinarySemDetectThreFreq */
  myBinarySemDetectThreFreqHandle = osSemaphoreNew(1, 1, &myBinarySemDetectThreFreq_attributes);

  /* creation of myBinarySemResetParamF */
  myBinarySemResetParamFHandle = osSemaphoreNew(1, 1, &myBinarySemResetParamF_attributes);

  /* creation of myBinarySemCalibration */
  myBinarySemCalibrationHandle = osSemaphoreNew(1, 1, &myBinarySemCalibration_attributes);

  /* creation of myBinarySemUpdateFreqDisp */
  myBinarySemUpdateFreqDispHandle = osSemaphoreNew(1, 1, &myBinarySemUpdateFreqDisp_attributes);

  /* creation of myBinarySemGetTimeRepeat */
  myBinarySemGetTimeRepeatHandle = osSemaphoreNew(1, 1, &myBinarySemGetTimeRepeat_attributes);

  /* creation of myBinarySemGetFreqRepeat */
  myBinarySemGetFreqRepeatHandle = osSemaphoreNew(1, 1, &myBinarySemGetFreqRepeat_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of TouchGFXTask */
  TouchGFXTaskHandle = osThreadNew(TouchGFX_Task, NULL, &TouchGFXTask_attributes);

  /* creation of TaskTimeSingle */
  TaskTimeSingleHandle = osThreadNew(StartTaskTimeSingle, NULL, &TaskTimeSingle_attributes);

  /* creation of TaskFreqSingle */
  TaskFreqSingleHandle = osThreadNew(StartTaskFreqSingle, NULL, &TaskFreqSingle_attributes);

  /* creation of TaskTimeConst */
  TaskTimeConstHandle = osThreadNew(StartTaskTimeConst, NULL, &TaskTimeConst_attributes);

  /* creation of TaskFreqConst */
  TaskFreqConstHandle = osThreadNew(StartTaskFreqConst, NULL, &TaskFreqConst_attributes);

  /* creation of TaskTimeStamps */
  TaskTimeStampsHandle = osThreadNew(StartTaskTimeStamps, NULL, &TaskTimeStamps_attributes);

  /* creation of TaskFreqStamps */
  TaskFreqStampsHandle = osThreadNew(StartTaskFreqStamps, NULL, &TaskFreqStamps_attributes);

  /* creation of TaskResetParamT */
  TaskResetParamTHandle = osThreadNew(StartTaskResetParamT, NULL, &TaskResetParamT_attributes);

  /* creation of TaskDetectThreT */
  TaskDetectThreTHandle = osThreadNew(StartTaskDetectThreT, NULL, &TaskDetectThreT_attributes);

  /* creation of TaskDetectThreF */
  TaskDetectThreFHandle = osThreadNew(StartTaskDetectThreF, NULL, &TaskDetectThreF_attributes);

  /* creation of TaskResetParamF */
  TaskResetParamFHandle = osThreadNew(StartTaskResetParamF, NULL, &TaskResetParamF_attributes);

  /* creation of TaskCalibration */
  TaskCalibrationHandle = osThreadNew(StartTaskCalibration, NULL, &TaskCalibration_attributes);

  /* creation of TaskTimeRepeat */
  TaskTimeRepeatHandle = osThreadNew(StartTaskTimeRepeat, NULL, &TaskTimeRepeat_attributes);

  /* creation of TaskFreqRepeat */
  TaskFreqRepeatHandle = osThreadNew(StartTaskFreqRepeat, NULL, &TaskFreqRepeat_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC|RCC_PERIPHCLK_I2C4;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 384;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 7;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV2;
  PeriphClkInitStruct.PLLSAIDivQ = 1;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_2;
  PeriphClkInitStruct.I2c4ClockSelection = RCC_I2C4CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  hcrc.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_ENABLE;
  hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
  hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
  hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
  hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief DMA2D Initialization Function
  * @param None
  * @retval None
  */
static void MX_DMA2D_Init(void)
{

  /* USER CODE BEGIN DMA2D_Init 0 */

  /* USER CODE END DMA2D_Init 0 */

  /* USER CODE BEGIN DMA2D_Init 1 */

  /* USER CODE END DMA2D_Init 1 */
  hdma2d.Instance = DMA2D;
  hdma2d.Init.Mode = DMA2D_M2M;
  hdma2d.Init.ColorMode = DMA2D_OUTPUT_ARGB8888;
  hdma2d.Init.OutputOffset = 0;
  hdma2d.LayerCfg[1].InputOffset = 0;
  hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888;
  hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d.LayerCfg[1].InputAlpha = 0;
  hdma2d.LayerCfg[1].AlphaInverted = DMA2D_REGULAR_ALPHA;
  hdma2d.LayerCfg[1].RedBlueSwap = DMA2D_RB_REGULAR;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DMA2D_Init 2 */

  /* USER CODE END DMA2D_Init 2 */

}

/**
  * @brief DSIHOST Initialization Function
  * @param None
  * @retval None
  */
static void MX_DSIHOST_DSI_Init(void)
{

  /* USER CODE BEGIN DSIHOST_Init 0 */
  /* Activate XRES active low */
  HAL_GPIO_WritePin(DSI_RESET_GPIO_Port, DSI_RESET_Pin, GPIO_PIN_RESET);
  HAL_Delay(20); /* wait 20 ms */
  /* Desactivate XRES */
  HAL_GPIO_WritePin(DSI_RESET_GPIO_Port, DSI_RESET_Pin, GPIO_PIN_SET);
  /* Wait for 10ms after releasing XRES before sending commands */
  HAL_Delay(10);
  /* USER CODE END DSIHOST_Init 0 */

  DSI_PLLInitTypeDef PLLInit = {0};
  DSI_HOST_TimeoutTypeDef HostTimeouts = {0};
  DSI_PHY_TimerTypeDef PhyTimings = {0};
  DSI_LPCmdTypeDef LPCmd = {0};
  DSI_CmdCfgTypeDef CmdCfg = {0};

  /* USER CODE BEGIN DSIHOST_Init 1 */

  /* USER CODE END DSIHOST_Init 1 */
  hdsi.Instance = DSI;
  hdsi.Init.AutomaticClockLaneControl = DSI_AUTO_CLK_LANE_CTRL_DISABLE;
  hdsi.Init.TXEscapeCkdiv = 4;
  hdsi.Init.NumberOfLanes = DSI_TWO_DATA_LANES;
  PLLInit.PLLNDIV = 100;
  PLLInit.PLLIDF = DSI_PLL_IN_DIV5;
  PLLInit.PLLODF = DSI_PLL_OUT_DIV1;
  if (HAL_DSI_Init(&hdsi, &PLLInit) != HAL_OK)
  {
    Error_Handler();
  }
  HostTimeouts.TimeoutCkdiv = 1;
  HostTimeouts.HighSpeedTransmissionTimeout = 0;
  HostTimeouts.LowPowerReceptionTimeout = 0;
  HostTimeouts.HighSpeedReadTimeout = 0;
  HostTimeouts.LowPowerReadTimeout = 0;
  HostTimeouts.HighSpeedWriteTimeout = 0;
  HostTimeouts.HighSpeedWritePrespMode = DSI_HS_PM_DISABLE;
  HostTimeouts.LowPowerWriteTimeout = 0;
  HostTimeouts.BTATimeout = 0;
  if (HAL_DSI_ConfigHostTimeouts(&hdsi, &HostTimeouts) != HAL_OK)
  {
    Error_Handler();
  }
  PhyTimings.ClockLaneHS2LPTime = 28;
  PhyTimings.ClockLaneLP2HSTime = 33;
  PhyTimings.DataLaneHS2LPTime = 15;
  PhyTimings.DataLaneLP2HSTime = 25;
  PhyTimings.DataLaneMaxReadTime = 0;
  PhyTimings.StopWaitTime = 0;
  if (HAL_DSI_ConfigPhyTimer(&hdsi, &PhyTimings) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_ConfigFlowControl(&hdsi, DSI_FLOW_CONTROL_BTA) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_SetLowPowerRXFilter(&hdsi, 10000) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_ConfigErrorMonitor(&hdsi, HAL_DSI_ERROR_OVF) != HAL_OK)
  {
    Error_Handler();
  }
  LPCmd.LPGenShortWriteNoP = DSI_LP_GSW0P_ENABLE;
  LPCmd.LPGenShortWriteOneP = DSI_LP_GSW1P_ENABLE;
  LPCmd.LPGenShortWriteTwoP = DSI_LP_GSW2P_ENABLE;
  LPCmd.LPGenShortReadNoP = DSI_LP_GSR0P_ENABLE;
  LPCmd.LPGenShortReadOneP = DSI_LP_GSR1P_ENABLE;
  LPCmd.LPGenShortReadTwoP = DSI_LP_GSR2P_ENABLE;
  LPCmd.LPGenLongWrite = DSI_LP_GLW_ENABLE;
  LPCmd.LPDcsShortWriteNoP = DSI_LP_DSW0P_ENABLE;
  LPCmd.LPDcsShortWriteOneP = DSI_LP_DSW1P_ENABLE;
  LPCmd.LPDcsShortReadNoP = DSI_LP_DSR0P_ENABLE;
  LPCmd.LPDcsLongWrite = DSI_LP_DLW_ENABLE;
  LPCmd.LPMaxReadPacket = DSI_LP_MRDP_ENABLE;
  LPCmd.AcknowledgeRequest = DSI_ACKNOWLEDGE_ENABLE;
  if (HAL_DSI_ConfigCommand(&hdsi, &LPCmd) != HAL_OK)
  {
    Error_Handler();
  }
  CmdCfg.VirtualChannelID = 0;
  CmdCfg.ColorCoding = DSI_RGB565;
  CmdCfg.CommandSize = 200;
  CmdCfg.TearingEffectSource = DSI_TE_EXTERNAL;
  CmdCfg.TearingEffectPolarity = DSI_TE_RISING_EDGE;
  CmdCfg.HSPolarity = DSI_HSYNC_ACTIVE_LOW;
  CmdCfg.VSPolarity = DSI_VSYNC_ACTIVE_LOW;
  CmdCfg.DEPolarity = DSI_DATA_ENABLE_ACTIVE_HIGH;
  CmdCfg.VSyncPol = DSI_VSYNC_FALLING;
  CmdCfg.AutomaticRefresh = DSI_AR_DISABLE;
  CmdCfg.TEAcknowledgeRequest = DSI_TE_ACKNOWLEDGE_ENABLE;
  if (HAL_DSI_ConfigAdaptedCommandMode(&hdsi, &CmdCfg) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_SetGenericVCID(&hdsi, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DSIHOST_Init 2 */

  /* USER CODE END DSIHOST_Init 2 */

}

/**
  * @brief I2C4 Initialization Function
  * @param None
  * @retval None
  */
void MX_I2C4_Init(void)
{

  /* USER CODE BEGIN I2C4_Init 0 */

  /* USER CODE END I2C4_Init 0 */

  /* USER CODE BEGIN I2C4_Init 1 */

  /* USER CODE END I2C4_Init 1 */
  hi2c4.Instance = I2C4;
  hi2c4.Init.Timing = 0x00C0EAFF;
  hi2c4.Init.OwnAddress1 = 0;
  hi2c4.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c4.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c4.Init.OwnAddress2 = 0;
  hi2c4.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c4.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c4.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c4) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c4, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c4, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C4_Init 2 */

  /* USER CODE END I2C4_Init 2 */

}

/**
  * @brief LTDC Initialization Function
  * @param None
  * @retval None
  */
static void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */

  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 1;
  hltdc.Init.VerticalSync = 1;
  hltdc.Init.AccumulatedHBP = 2;
  hltdc.Init.AccumulatedVBP = 2;
  hltdc.Init.AccumulatedActiveW = 202;
  hltdc.Init.AccumulatedActiveH = 482;
  hltdc.Init.TotalWidth = 203;
  hltdc.Init.TotalHeigh = 483;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 200;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 480;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  pLayerCfg.Alpha = 255;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg.FBStartAdress = 0xC0000000;
  pLayerCfg.ImageWidth = 200;
  pLayerCfg.ImageHeight = 480;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */
  __HAL_LTDC_DISABLE(&hltdc);
  DSI_LPCmdTypeDef LPCmd;

  HAL_DSI_Start(&hdsi);
  OTM8009A_Init(OTM8009A_FORMAT_RBG565, LCD_ORIENTATION_LANDSCAPE);

  HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, OTM8009A_CMD_DISPOFF, 0x00);

  LPCmd.LPGenShortWriteNoP = DSI_LP_GSW0P_DISABLE;
  LPCmd.LPGenShortWriteOneP = DSI_LP_GSW1P_DISABLE;
  LPCmd.LPGenShortWriteTwoP = DSI_LP_GSW2P_DISABLE;
  LPCmd.LPGenShortReadNoP = DSI_LP_GSR0P_DISABLE;
  LPCmd.LPGenShortReadOneP = DSI_LP_GSR1P_DISABLE;
  LPCmd.LPGenShortReadTwoP = DSI_LP_GSR2P_DISABLE;
  LPCmd.LPGenLongWrite = DSI_LP_GLW_DISABLE;
  LPCmd.LPDcsShortWriteNoP = DSI_LP_DSW0P_DISABLE;
  LPCmd.LPDcsShortWriteOneP = DSI_LP_DSW1P_DISABLE;
  LPCmd.LPDcsShortReadNoP = DSI_LP_DSR0P_DISABLE;
  LPCmd.LPDcsLongWrite = DSI_LP_DLW_DISABLE;
  HAL_DSI_ConfigCommand(&hdsi, &LPCmd);

  HAL_LTDC_SetPitch(&hltdc, 800, 0);
  __HAL_LTDC_ENABLE(&hltdc);

  // LPCmd.LPGenShortWriteNoP = DSI_LP_GSW0P_DISABLE;
  // LPCmd.LPGenShortWriteOneP = DSI_LP_GSW1P_DISABLE;
  // LPCmd.LPGenShortWriteTwoP = DSI_LP_GSW2P_DISABLE;
  // LPCmd.LPGenShortReadNoP = DSI_LP_GSR0P_DISABLE;
  // LPCmd.LPGenShortReadOneP = DSI_LP_GSR1P_DISABLE;
  // LPCmd.LPGenShortReadTwoP = DSI_LP_GSR2P_DISABLE;
  // LPCmd.LPGenLongWrite = DSI_LP_GLW_DISABLE;
  // LPCmd.LPDcsShortWriteNoP = DSI_LP_DSW0P_DISABLE;
  // LPCmd.LPDcsShortWriteOneP = DSI_LP_DSW1P_DISABLE;
  // LPCmd.LPDcsShortReadNoP = DSI_LP_DSR0P_DISABLE;
  // LPCmd.LPDcsLongWrite = DSI_LP_DLW_DISABLE;
  // HAL_DSI_ConfigCommand(&hdsi, &LPCmd);

  // HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, OTM8009A_CMD_DISPOFF, 0x00);

  // HAL_LTDC_SetPitch(&hltdc, 800, 0);
  // __HAL_LTDC_ENABLE(&hltdc);

  /* USER CODE END LTDC_Init 2 */

}

/**
  * @brief QUADSPI Initialization Function
  * @param None
  * @retval None
  */
static void MX_QUADSPI_Init(void)
{

  /* USER CODE BEGIN QUADSPI_Init 0 */

  /* USER CODE END QUADSPI_Init 0 */

  /* USER CODE BEGIN QUADSPI_Init 1 */

  /* USER CODE END QUADSPI_Init 1 */
  /* QUADSPI parameter configuration*/
  hqspi.Instance = QUADSPI;
  hqspi.Init.ClockPrescaler = 1;
  hqspi.Init.FifoThreshold = 16;
  hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_HALFCYCLE;
  hqspi.Init.FlashSize = 25;
  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_4_CYCLE;
  hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
  hqspi.Init.FlashID = QSPI_FLASH_ID_1;
  hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN QUADSPI_Init 2 */
  /* QSPI memory reset */
  if (QSPI_ResetMemory(&hqspi) != QSPI_OK)
  {
    Error_Handler();
  }

  /* Put QSPI memory in QPI mode */
  if( QSPI_EnterMemory_QPI( &hqspi )!=QSPI_OK )
  {
    Error_Handler();
  }

  /* Set the QSPI memory in 4-bytes address mode */
  if (QSPI_EnterFourBytesAddress(&hqspi) != QSPI_OK)
  {
    Error_Handler();
  }

  /* Configuration of the dummy cycles on QSPI memory side */
  if (QSPI_DummyCyclesCfg(&hqspi) != QSPI_OK)
  {
    Error_Handler();
  }

  /* Configuration of the Output driver strength on memory side */
  if( QSPI_OutDrvStrengthCfg( &hqspi ) != QSPI_OK )
  {
    Error_Handler();
  }

  if( BSP_QSPI_EnableMemoryMappedMode(&hqspi) != QSPI_OK )
  {
    Error_Handler();
  }

  /* USER CODE END QUADSPI_Init 2 */

}

/* FMC initialization function */
static void MX_FMC_Init(void)
{

  /* USER CODE BEGIN FMC_Init 0 */

  /* USER CODE END FMC_Init 0 */

  FMC_SDRAM_TimingTypeDef SdramTiming = {0};

  /* USER CODE BEGIN FMC_Init 1 */

  /* USER CODE END FMC_Init 1 */

  /** Perform the SDRAM1 memory initialization sequence
  */
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
  hsdram1.Init.SDBank = FMC_SDRAM_BANK1;
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_8;
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_12;
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_32;
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_0;
  /* SdramTiming */
  SdramTiming.LoadToActiveDelay = 2;
  SdramTiming.ExitSelfRefreshDelay = 7;
  SdramTiming.SelfRefreshTime = 4;
  SdramTiming.RowCycleDelay = 7;
  SdramTiming.WriteRecoveryTime = 2;
  SdramTiming.RPDelay = 2;
  SdramTiming.RCDDelay = 3;

  if (HAL_SDRAM_Init(&hsdram1, &SdramTiming) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FMC_Init 2 */

  FMC_SDRAM_CommandTypeDef command;

  /* Program the SDRAM external device */
  BSP_SDRAM_Initialization_Sequence(&hsdram1, &command);

  //Deactivate speculative/cache access to first FMC Bank to save FMC bandwidth
  FMC_Bank1->BTCR[0] = 0x000030D2;
  /* USER CODE END FMC_Init 2 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOJ_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOJ, VSYNC_FREQ2_Pin|RENDER_TIME2_Pin|FRAMERATE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DSI_RESET_GPIO_Port, DSI_RESET_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, RENDER_TIME_Pin|VSYNC_FREQ_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : VSYNC_FREQ2_Pin RENDER_TIME2_Pin */
  GPIO_InitStruct.Pin = VSYNC_FREQ2_Pin|RENDER_TIME2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

  /*Configure GPIO pin : DSI_RESET_Pin */
  GPIO_InitStruct.Pin = DSI_RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(DSI_RESET_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RENDER_TIME_Pin VSYNC_FREQ_Pin */
  GPIO_InitStruct.Pin = RENDER_TIME_Pin|VSYNC_FREQ_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : FRAMERATE_Pin */
  GPIO_InitStruct.Pin = FRAMERATE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(FRAMERATE_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
/**
  * @brief  Perform the SDRAM external memory initialization sequence
  * @param  hsdram: SDRAM handle
  * @param  Command: Pointer to SDRAM command structure
  * @retval None
  */
static void BSP_SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram, FMC_SDRAM_CommandTypeDef *Command)
{
 __IO uint32_t tmpmrd = 0;

    /* Step 1: Configure a clock configuration enable command */
    Command->CommandMode            = FMC_SDRAM_CMD_CLK_ENABLE;
    Command->CommandTarget          =  FMC_SDRAM_CMD_TARGET_BANK1;
    Command->AutoRefreshNumber      = 1;
    Command->ModeRegisterDefinition = 0;

    /* Send the command */
    HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

    /* Step 2: Insert 100 us minimum delay */
    /* Inserted delay is equal to 1 ms due to systick time base unit (ms) */
    HAL_Delay(1);

    /* Step 3: Configure a PALL (precharge all) command */
    Command->CommandMode            = FMC_SDRAM_CMD_PALL;
    Command->CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
    Command->AutoRefreshNumber      = 1;
    Command->ModeRegisterDefinition = 0;

    /* Send the command */
    HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

    /* Step 4: Configure an Auto Refresh command */
    Command->CommandMode            = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
    Command->CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
    Command->AutoRefreshNumber      = 8;
    Command->ModeRegisterDefinition = 0;

    /* Send the command */
    HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

    /* Step 5: Program the external memory mode register */
    tmpmrd = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_1          | \
             SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   | \
             SDRAM_MODEREG_CAS_LATENCY_3           | \
             SDRAM_MODEREG_OPERATING_MODE_STANDARD | \
             SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

    Command->CommandMode            = FMC_SDRAM_CMD_LOAD_MODE;
    Command->CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
    Command->AutoRefreshNumber      = 1;
    Command->ModeRegisterDefinition = tmpmrd;

    /* Send the command */
    HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

    /* Step 6: Set the refresh rate counter */
    /* Set the device refresh rate */
    HAL_SDRAM_ProgramRefreshRate(hsdram, REFRESH_COUNT);

}

/**
  * @brief  This function reset the QSPI memory.
  * @param  hqspi: QSPI handle
  * @retval None
  */
static uint8_t QSPI_ResetMemory(QSPI_HandleTypeDef *hqspi)
{
  QSPI_CommandTypeDef      s_command;
  QSPI_AutoPollingTypeDef  s_config;
  uint8_t                  reg;

  /* Send command RESET command in QPI mode (QUAD I/Os) */
  /* Initialize the reset enable command */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = RESET_ENABLE_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_NONE;
  s_command.DummyCycles       = 0;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
  /* Send the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }
  /* Send the reset memory command */
  s_command.Instruction = RESET_MEMORY_CMD;
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Send command RESET command in SPI mode */
  /* Initialize the reset enable command */
  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction       = RESET_ENABLE_CMD;
  /* Send the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }
  /* Send the reset memory command */
  s_command.Instruction = RESET_MEMORY_CMD;
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* After reset CMD, 1000ms requested if QSPI memory SWReset occured during full chip erase operation */
  HAL_Delay( 1000 );

  /* Configure automatic polling mode to wait the WIP bit=0 */
  s_config.Match           = 0;
  s_config.Mask            = MX25L512_SR_WIP;
  s_config.MatchMode       = QSPI_MATCH_MODE_AND;
  s_config.StatusBytesSize = 1;
  s_config.Interval        = 0x10;
  s_config.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

  s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction     = READ_STATUS_REG_CMD;
  s_command.DataMode        = QSPI_DATA_1_LINE;

  if (HAL_QSPI_AutoPolling(hqspi, &s_command, &s_config, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Initialize the reading of status register */
  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction       = READ_STATUS_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_1_LINE;
  s_command.DummyCycles       = 0;
  s_command.NbData            = 1;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Reception of the data */
  if (HAL_QSPI_Receive(hqspi, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Enable write operations, command in 1 bit */
  /* Enable write operations */
  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction       = WRITE_ENABLE_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_NONE;
  s_command.DummyCycles       = 0;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Configure automatic polling mode to wait for write enabling */
  s_config.Match           = MX25L512_SR_WREN;
  s_config.Mask            = MX25L512_SR_WREN;
  s_config.MatchMode       = QSPI_MATCH_MODE_AND;
  s_config.StatusBytesSize = 1;
  s_config.Interval        = 0x10;
  s_config.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

  s_command.Instruction    = READ_STATUS_REG_CMD;
  s_command.DataMode       = QSPI_DATA_1_LINE;

  if (HAL_QSPI_AutoPolling(hqspi, &s_command, &s_config, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Update the configuration register with new dummy cycles */
  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction       = WRITE_STATUS_CFG_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_1_LINE;
  s_command.DummyCycles       = 0;
  s_command.NbData            = 1;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Enable the Quad IO on the QSPI memory (Non-volatile bit) */
  reg |= MX25L512_SR_QUADEN;

  /* Configure the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Transmission of the data */
  if (HAL_QSPI_Transmit(hqspi, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* 40ms  Write Status/Configuration Register Cycle Time */
  HAL_Delay( 40 );

  return QSPI_OK;
}

/**
  * @brief  This function put QSPI memory in QPI mode (quad I/O).
  * @param  hqspi: QSPI handle
  * @retval None
  */
static uint8_t QSPI_EnterMemory_QPI( QSPI_HandleTypeDef *hqspi )
{
  QSPI_CommandTypeDef      s_command;
  QSPI_AutoPollingTypeDef  s_config;

  /* Initialize the QPI enable command */
  /* QSPI memory is supported to be in SPI mode, so CMD on 1 LINE */
  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction       = ENTER_QUAD_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_NONE;
  s_command.DummyCycles       = 0;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Send the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Configure automatic polling mode to wait the QUADEN bit=1 and WIP bit=0 */
  s_config.Match           = MX25L512_SR_QUADEN;
  s_config.Mask            = MX25L512_SR_QUADEN|MX25L512_SR_WIP;
  s_config.MatchMode       = QSPI_MATCH_MODE_AND;
  s_config.StatusBytesSize = 1;
  s_config.Interval        = 0x10;
  s_config.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = READ_STATUS_REG_CMD;
  s_command.DataMode          = QSPI_DATA_4_LINES;

  if (HAL_QSPI_AutoPolling(hqspi, &s_command, &s_config, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

/**
  * @brief  This function set the QSPI memory in 4-byte address mode
  * @param  hqspi: QSPI handle
  * @retval None
  */
static uint8_t QSPI_EnterFourBytesAddress(QSPI_HandleTypeDef *hqspi)
{
  QSPI_CommandTypeDef s_command;

  /* Initialize the command */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = ENTER_4_BYTE_ADDR_MODE_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_NONE;
  s_command.DummyCycles       = 0;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Enable write operations */
  if (QSPI_WriteEnable(hqspi) != QSPI_OK)
  {
    return QSPI_ERROR;
  }

  /* Send the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Configure automatic polling mode to wait the memory is ready */
  if (QSPI_AutoPollingMemReady(hqspi, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != QSPI_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

/**
  * @brief  This function configure the dummy cycles on memory side.
  * @param  hqspi: QSPI handle
  * @retval None
  */
static uint8_t QSPI_DummyCyclesCfg(QSPI_HandleTypeDef *hqspi)
{
  QSPI_CommandTypeDef s_command;
  uint8_t reg[2];

  /* Initialize the reading of status register */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = READ_STATUS_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = 0;
  s_command.NbData            = 1;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Reception of the data */
  if (HAL_QSPI_Receive(hqspi, &(reg[0]), HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Initialize the reading of configuration register */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = READ_CFG_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = 0;
  s_command.NbData            = 1;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Reception of the data */
  if (HAL_QSPI_Receive(hqspi, &(reg[1]), HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Enable write operations */
  if (QSPI_WriteEnable(hqspi) != QSPI_OK)
  {
    return QSPI_ERROR;
  }

  /* Update the configuration register with new dummy cycles */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = WRITE_STATUS_CFG_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = 0;
  s_command.NbData            = 2;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* MX25L512_DUMMY_CYCLES_READ_QUAD = 3 for 10 cycles in QPI mode */
  MODIFY_REG( reg[1], MX25L512_CR_NB_DUMMY, (MX25L512_DUMMY_CYCLES_READ_QUAD << POSITION_VAL(MX25L512_CR_NB_DUMMY)));

  /* Configure the write volatile configuration register command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Transmission of the data */
  if (HAL_QSPI_Transmit(hqspi, &(reg[0]), HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* 40ms  Write Status/Configuration Register Cycle Time */
  HAL_Delay( 40 );

  return QSPI_OK;
}

/**
  * @brief  This function configure the Output driver strength on memory side.
  * @param  hqspi: QSPI handle
  * @retval None
  */
static uint8_t QSPI_OutDrvStrengthCfg( QSPI_HandleTypeDef *hqspi )
{
  QSPI_CommandTypeDef s_command;
  uint8_t reg[2];

  /* Initialize the reading of status register */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = READ_STATUS_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = 0;
  s_command.NbData            = 1;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Reception of the data */
  if (HAL_QSPI_Receive(hqspi, &(reg[0]), HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Initialize the reading of configuration register */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = READ_CFG_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = 0;
  s_command.NbData            = 1;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Reception of the data */
  if (HAL_QSPI_Receive(hqspi, &(reg[1]), HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Enable write operations */
  if (QSPI_WriteEnable(hqspi) != QSPI_OK)
  {
    return QSPI_ERROR;
  }

  /* Update the configuration register with new output driver strength */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = WRITE_STATUS_CFG_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = 0;
  s_command.NbData            = 2;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Set Output Strength of the QSPI memory 15 ohms */
  MODIFY_REG( reg[1], MX25L512_CR_ODS, (MX25L512_CR_ODS_15 << POSITION_VAL(MX25L512_CR_ODS)));

  /* Configure the write volatile configuration register command */
  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Transmission of the data */
  if (HAL_QSPI_Transmit(hqspi, &(reg[0]), HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

/**
  * @brief  This function send a Write Enable and wait it is effective.
  * @param  hqspi: QSPI handle
  * @retval None
  */
static uint8_t QSPI_WriteEnable(QSPI_HandleTypeDef *hqspi)
{
  QSPI_CommandTypeDef     s_command;
  QSPI_AutoPollingTypeDef s_config;

  /* Enable write operations */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = WRITE_ENABLE_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_NONE;
  s_command.DummyCycles       = 0;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Configure automatic polling mode to wait for write enabling */
  s_config.Match           = MX25L512_SR_WREN;
  s_config.Mask            = MX25L512_SR_WREN;
  s_config.MatchMode       = QSPI_MATCH_MODE_AND;
  s_config.StatusBytesSize = 1;
  s_config.Interval        = 0x10;
  s_config.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

  s_command.Instruction    = READ_STATUS_REG_CMD;
  s_command.DataMode       = QSPI_DATA_4_LINES;

  if (HAL_QSPI_AutoPolling(hqspi, &s_command, &s_config, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

/**
  * @brief  This function read the SR of the memory and wait the EOP.
  * @param  hqspi: QSPI handle
  * @param  Timeout
  * @retval None
  */
static uint8_t QSPI_AutoPollingMemReady(QSPI_HandleTypeDef *hqspi, uint32_t Timeout)
{
  QSPI_CommandTypeDef     s_command;
  QSPI_AutoPollingTypeDef s_config;

  /* Configure automatic polling mode to wait for memory ready */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = READ_STATUS_REG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_NONE;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = 0;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  s_config.Match           = 0;
  s_config.Mask            = MX25L512_SR_WIP;
  s_config.MatchMode       = QSPI_MATCH_MODE_AND;
  s_config.StatusBytesSize = 1;
  s_config.Interval        = 0x10;
  s_config.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

  if (HAL_QSPI_AutoPolling(hqspi, &s_command, &s_config, Timeout) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

/**
  * @brief  Configure the QSPI in memory-mapped mode
  * @retval QSPI memory status
  */
static uint8_t BSP_QSPI_EnableMemoryMappedMode(QSPI_HandleTypeDef *hqspi)
{
  QSPI_CommandTypeDef      s_command;
  QSPI_MemoryMappedTypeDef s_mem_mapped_cfg;

  /* Configure the command for the read instruction */
  s_command.InstructionMode   = QSPI_INSTRUCTION_4_LINES;
  s_command.Instruction       = QPI_READ_4_BYTE_ADDR_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_4_LINES;
  s_command.AddressSize       = QSPI_ADDRESS_32_BITS;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = MX25L512_DUMMY_CYCLES_READ_QUAD_IO;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the memory mapped mode */
  s_mem_mapped_cfg.TimeOutActivation = QSPI_TIMEOUT_COUNTER_DISABLE;
  s_mem_mapped_cfg.TimeOutPeriod     = 0;

  if (HAL_QSPI_MemoryMapped(hqspi, &s_command, &s_mem_mapped_cfg) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_TouchGFX_Task */
/**
  * @brief  Function implementing the TouchGFXTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_TouchGFX_Task */
__weak void TouchGFX_Task(void *argument)
{
  /* USER CODE BEGIN 5 */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTaskTimeSingle */
/**
* @brief Function implementing the TaskTimeSingle thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskTimeSingle */
void StartTaskTimeSingle(void *argument)
{
  /* USER CODE BEGIN StartTaskTimeSingle */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemGetTimeSingleHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemGetTimeSingleHandle, (uint32_t) 10) == osOK)
		  {
			  conditionT = 0;
			  conditionRepeatT = TimeBackend.TimeSession.repeat + 1;
			  ResultTimeInit(&ResultTimeBackend);
			  SingleTimeMeas(&TimeBackend, &ResultTimeBackend);
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskTimeSingle */
}

/* USER CODE BEGIN Header_StartTaskFreqSingle */
/**
* @brief Function implementing the TaskFreqSingle thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskFreqSingle */
void StartTaskFreqSingle(void *argument)
{
  /* USER CODE BEGIN StartTaskFreqSingle */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskFreqSingle */
}

/* USER CODE BEGIN Header_StartTaskTimeConst */
/**
* @brief Function implementing the TaskTimeConst thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskTimeConst */
void StartTaskTimeConst(void *argument)
{
  /* USER CODE BEGIN StartTaskTimeConst */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemGetTimeConstHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemGetTimeConstHandle, (uint32_t) 10) == osOK)
		  {
			  conditionT = 1;
			  conditionRepeatT = TimeBackend.TimeSession.repeat + 1;
			  while(conditionT)
			  {
				  ResultTimeInit(&ResultTimeBackend);
				  ContinuousTimeMeas(&TimeBackend, &ResultTimeBackend, &ResultCalcConstTime);
				  osDelay(500);
			  }
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskTimeConst */
}

/* USER CODE BEGIN Header_StartTaskFreqConst */
/**
* @brief Function implementing the TaskFreqConst thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskFreqConst */
void StartTaskFreqConst(void *argument)
{
  /* USER CODE BEGIN StartTaskFreqConst */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskFreqConst */
}

/* USER CODE BEGIN Header_StartTaskTimeStamps */
/**
* @brief Function implementing the TaskTimeStamps thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskTimeStamps */
void StartTaskTimeStamps(void *argument)
{
  /* USER CODE BEGIN StartTaskTimeStamps */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemGetTimeStampsHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemGetTimeStampsHandle, (uint32_t) 10) == osOK) // && counterSingleT > 1)
		  {
			  conditionT = 0;
			  conditionRepeatT = TimeBackend.TimeSession.repeat + 1;
			  ResultTimeInit(&ResultTimeBackend);
			  StampsTimeMeas(&TimeBackend, &ResultTimeBackend, &ResultCalcStampsTime);
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskTimeStamps */
}

/* USER CODE BEGIN Header_StartTaskFreqStamps */
/**
* @brief Function implementing the TaskFreqStamps thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskFreqStamps */
void StartTaskFreqStamps(void *argument)
{
  /* USER CODE BEGIN StartTaskFreqStamps */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskFreqStamps */
}

/* USER CODE BEGIN Header_StartTaskResetParamT */
/**
* @brief Function implementing the TaskResetParamT thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskResetParamT */
void StartTaskResetParamT(void *argument)
{
  /* USER CODE BEGIN StartTaskResetParamT */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemResetParamTHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemResetParamTHandle, (uint32_t) 10) == osOK)
		  {
			  TimeModeInit(&TimeBackend);
			  ResultTimeParameterConstInit(&ResultCalcConstTime);	//aby wyczyscic stamp number trzeba kliknac reset w UI
			  ResultTimeParameterStampsInit(&ResultCalcStampsTime);
			  ResultTimeInit(&ResultTimeBackend);
			  conditionT = 0;
			  conditionRepeatT = TimeBackend.TimeSession.repeat + 1; // przerwanie trybu repeat
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskResetParamT */
}

/* USER CODE BEGIN Header_StartTaskDetectThreT */
/**
* @brief Function implementing the TaskDetectThreT thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskDetectThreT */
void StartTaskDetectThreT(void *argument)
{
  /* USER CODE BEGIN StartTaskDetectThreT */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemDetectThreTimeHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemDetectThreTimeHandle, (uint32_t) 10) == osOK)
		  {
			  detectedThreshold(&detectedThresholdTime);
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskDetectThreT */
}

/* USER CODE BEGIN Header_StartTaskDetectThreF */
/**
* @brief Function implementing the TaskDetectThreF thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskDetectThreF */
void StartTaskDetectThreF(void *argument)
{
  /* USER CODE BEGIN StartTaskDetectThreF */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemDetectThreFreqHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemDetectThreFreqHandle, (uint32_t) 10) == osOK){
			  detectedThreshold(&detectedThresholdFreq);
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskDetectThreF */
}

/* USER CODE BEGIN Header_StartTaskResetParamF */
/**
* @brief Function implementing the TaskResetParamF thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskResetParamF */
void StartTaskResetParamF(void *argument)
{
  /* USER CODE BEGIN StartTaskResetParamF */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemResetParamFHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemResetParamFHandle, (uint32_t) 10) == osOK)
		  {
			  FrequencyModeInit(&FreqBackend);
			  ResultFrequencyInit(&ResultFreqBackend);
			  conditionF = 0;
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskResetParamF */
}

/* USER CODE BEGIN Header_StartTaskCalibration */
/**
* @brief Function implementing the TaskCalibration thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskCalibration */
void StartTaskCalibration(void *argument)
{
  /* USER CODE BEGIN StartTaskCalibration */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemCalibrationHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemCalibrationHandle, (uint32_t) 10) == osOK)
		  {
			  TimeModeInit(&TimeBackend);
			  ResultTimeParameterConstInit(&ResultCalcConstTime);	//aby wyczyscic stamp number trzeba kliknac reset w UI
			  ResultTimeParameterStampsInit(&ResultCalcStampsTime);
			  ResultTimeInit(&ResultTimeBackend);
			  conditionT = 0;
			  conditionRepeatT = TimeBackend.TimeSession.repeat + 1; // przerwanie trybu repeat

			  //:TODO dopisac inicjalizacje funkcji z frequency mode.
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskCalibration */
}

/* USER CODE BEGIN Header_StartTaskTimeRepeat */
/**
* @brief Function implementing the TaskTimeRepeat thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskTimeRepeat */
void StartTaskTimeRepeat(void *argument)
{
  /* USER CODE BEGIN StartTaskTimeRepeat */
  /* Infinite loop */
  for(;;)
  {
	  if (myBinarySemGetTimeRepeatHandle != NULL)
	  {
		  if (osSemaphoreAcquire(myBinarySemGetTimeRepeatHandle, (uint32_t) 10) == osOK)
		  {
			  conditionT = 0;
			  conditionRepeatT = 1;
			  while (conditionRepeatT <= TimeBackend.TimeSession.repeat)
			  {
				  ResultTimeInit(&ResultTimeBackend);
				  StampsTimeMeas(&TimeBackend, &ResultTimeBackend, &ResultCalcStampsTime);
				  conditionRepeatT++;
				  osDelay(1000);
			  }
		  }
	  }
    osDelay(1);
  }
  /* USER CODE END StartTaskTimeRepeat */
}

/* USER CODE BEGIN Header_StartTaskFreqRepeat */
/**
* @brief Function implementing the TaskFreqRepeat thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskFreqRepeat */
void StartTaskFreqRepeat(void *argument)
{
  /* USER CODE BEGIN StartTaskFreqRepeat */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskFreqRepeat */
}

/* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();
  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x20000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_512KB;
  MPU_InitStruct.SubRegionDisable = 0x0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Number = MPU_REGION_NUMBER1;
  MPU_InitStruct.BaseAddress = 0x90000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_512MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Number = MPU_REGION_NUMBER2;
  MPU_InitStruct.Size = MPU_REGION_SIZE_64MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Number = MPU_REGION_NUMBER3;
  MPU_InitStruct.BaseAddress = 0xC0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_512MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Number = MPU_REGION_NUMBER4;
  MPU_InitStruct.Size = MPU_REGION_SIZE_16MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
