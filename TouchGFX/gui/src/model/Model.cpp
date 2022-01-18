#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern osSemaphoreId_t myBinarySemUpdateTimeDispHandle;
extern osSemaphoreId_t myBinarySemUpdateFreqDispHandle;

extern uint32_t FlagTimeSingle;
extern uint32_t FlagFreqSingle;
extern uint32_t FlagTimeConst;
extern uint32_t FlagFreqConst;
extern uint32_t FlagTimeStamps;
extern uint32_t FlagFreqStamps;
extern uint32_t FlagResetParamT;
extern uint32_t FlagDetectThreshold;
extern uint32_t FlagResetParamF;
extern uint32_t FlagCalibration;
extern uint32_t FlagTimeRepeat;
extern uint32_t FlagFreqRepeat;

extern osThreadId_t TaskTimeSingleHandle;
extern osThreadId_t TaskFreqSingleHandle;
extern osThreadId_t TaskTimeConstHandle;
extern osThreadId_t TaskFreqConstHandle;
extern osThreadId_t TaskTimeStampsHandle;
extern osThreadId_t TaskFreqStampsHandle;
extern osThreadId_t TaskResetParamTHandle;
extern osThreadId_t TaskDetectThreHandle;
extern osThreadId_t TaskResetParamFHandle;
extern osThreadId_t TaskCalibrationHandle;
extern osThreadId_t TaskTimeRepeatHandle;
extern osThreadId_t TaskFreqRepeatHandle;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if (myBinarySemUpdateTimeDispHandle != NULL)
	{
		if (osSemaphoreAcquire(myBinarySemUpdateTimeDispHandle, ( uint32_t ) 10) == osOK)
		{
			updateScreenContinuousTimeMode();
		}
	}

	if (myBinarySemUpdateFreqDispHandle != NULL)
	{
		if (osSemaphoreAcquire(myBinarySemUpdateFreqDispHandle, ( uint32_t ) 10) == osOK)
		{
			updateScreenContinuousFreqMode();
		}
	}
}

void Model::updateScreenContinuousTimeMode()
{
	modelListener->updateUIContinuousTime();
}

void Model::updateScreenContinuousFreqMode()
{
	modelListener->updateUIContinuousFreq();
}

void Model::getDataTimeSingle()
{
	osThreadFlagsSet(TaskTimeSingleHandle, FlagTimeSingle);
}

void Model::getDataTimeContinuous()
{
	osThreadFlagsSet(TaskTimeConstHandle, FlagTimeConst);
}

void Model::getDataTimeStamps()
{
	osThreadFlagsSet(TaskTimeStampsHandle, FlagTimeStamps);
}

void Model::getDataTimeRepeat()
{
	osThreadFlagsSet(TaskTimeRepeatHandle, FlagTimeRepeat);
}

void Model::getDataFreqSingle()
{
	osThreadFlagsSet(TaskFreqSingleHandle, FlagFreqSingle);
}

void Model::getDataFreqContinuous()
{
	osThreadFlagsSet(TaskFreqConstHandle, FlagFreqConst);
}

void Model::getDataFreqStamps()
{
	osThreadFlagsSet(TaskFreqStampsHandle, FlagFreqStamps);
}

void Model::getDataFreqRepeat()
{
	osThreadFlagsSet(TaskFreqRepeatHandle, FlagFreqRepeat);
}

void Model::getResetTime()
{
	osThreadFlagsSet(TaskResetParamTHandle, FlagResetParamT);
	modelListener->updateUIContinuousTime();
}

void Model::getResetFreq()
{
	osThreadFlagsSet(TaskResetParamFHandle, FlagResetParamF);
	modelListener->updateUIContinuousFreq();
}

void Model::getDetectedTimeThreshold()
{
	osThreadFlagsSet(TaskDetectThreHandle, FlagDetectThreshold);
}

void Model::getDetectedFreqThreshold()
{
	osThreadFlagsSet(TaskDetectThreHandle, FlagDetectThreshold);
}

void Model::getCalibration()
{
	osThreadFlagsSet(TaskCalibrationHandle, FlagCalibration);
}
