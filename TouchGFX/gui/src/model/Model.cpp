#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern osSemaphoreId_t myBinarySemGetTimeSingleHandle;
extern osSemaphoreId_t myBinarySemGetFreqSingleHandle;

extern osSemaphoreId_t myBinarySemGetTimeConstHandle;
extern osSemaphoreId_t myBinarySemGetFreqConstHandle;

extern osSemaphoreId_t myBinarySemGetTimeStampsHandle;
extern osSemaphoreId_t myBinarySemGetFreqStampsHandle;

extern osSemaphoreId_t myBinarySemDetectThreTimeHandle;
extern osSemaphoreId_t myBinarySemDetectThreFreqHandle;

extern osSemaphoreId_t myBinarySemResetParamTHandle;
extern osSemaphoreId_t myBinarySemResetParamFHandle;

extern osSemaphoreId_t myBinarySemUpdateTimeDispHandle;
extern osSemaphoreId_t myBinarySemUpdateFreqDispHandle;

extern osSemaphoreId_t myBinarySemCalibrationHandle;

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
}

void Model::updateScreenContinuousTimeMode()
{
	modelListener->updateUIContinuousTime();
}

//
void Model::getDataTimeSingle()
{
	osSemaphoreRelease(myBinarySemGetTimeSingleHandle);
}

void Model::getDataTimeContinuous()
{
	osSemaphoreRelease(myBinarySemGetTimeConstHandle);
}

void Model::getDataTimeStamps()
{

}

void Model::getDataFreqSingle()
{
	osSemaphoreRelease(myBinarySemGetFreqSingleHandle);
}

void Model::getDataFreqContinuous()
{

}

void Model::getDataFreqStamps()
{

}

void Model::getResetTime()
{
	osSemaphoreRelease(myBinarySemResetParamTHandle);
}

void Model::getResetFreq()
{
	osSemaphoreRelease(myBinarySemResetParamFHandle);
}

void Model::getDetectedTimeThreshold()
{
	osSemaphoreRelease(myBinarySemDetectThreTimeHandle);
}

void Model::getDetectedFreqThreshold()
{
	osSemaphoreRelease(myBinarySemDetectThreFreqHandle);
}
