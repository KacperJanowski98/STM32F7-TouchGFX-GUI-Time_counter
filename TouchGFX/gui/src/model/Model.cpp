#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern osSemaphoreId_t myBinarySemGetTimeSingleHandle;
extern osSemaphoreId_t myBinarySemGetFreqSingleHandle;

extern osSemaphoreId_t myBinarySemGetTimeConstHandle;
extern osSemaphoreId_t myBinarySemGetFreqConstHandle;

extern osSemaphoreId_t myBinarySemGetTimeStampsHandle;
extern osSemaphoreId_t myBinarySemGetFreqStampsHandle;

extern osSemaphoreId_t myBinarySemResetParamHandle;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}

//
void Model::getDataTimeSingle()
{
	osSemaphoreRelease(myBinarySemGetTimeSingleHandle);
}

void Model::getDataTimeContinuous()
{

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

void Model::getReset()
{
	osSemaphoreRelease(myBinarySemResetParamHandle);
}
