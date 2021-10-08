#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern osSemaphoreId_t myBinarySemGetTimeSingleHandle;
extern osSemaphoreId_t myBinarySemGetFreqSingleHandle;

extern osSemaphoreId_t myBinarySemGetTimeConstHandle;
extern osSemaphoreId_t myBinarySemGetFreqConstHandle;

extern osSemaphoreId_t myBinarySemGetTimeStampsHandle;
extern osSemaphoreId_t myBinarySemGetFreqStampsHandle;

Model::Model() : modelListener(0)
//				, Channel1(1, false, Slope::UP, Threshold::Manula, 100, 1, 2) -- version 1
{
//	Channel1 = new TimeModeParameter(1, false, SlopeName::UP, ThresholdName::Manula, 100, 1, 2);
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

// Inna wrsja - remove
//std::unique_ptr<TimeModeParameter> Model::getChannel1()
//{
//  return std::make_unique<TimeModeParameter>(Channel1);  -- version 1
//	std::unique_ptr<TimeModeParameter> ch1(new TimeModeParameter(Channel1));
//	return ch1;
//}
