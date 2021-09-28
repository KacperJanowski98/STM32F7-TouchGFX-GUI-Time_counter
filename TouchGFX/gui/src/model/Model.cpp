#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern osSemaphoreId_t myBinarySemGetDataTimeHandle;

Model::Model() : modelListener(0)
//				, Channel1(1, false, Slope::UP, Threshold::Manula, 100, 1, 2) -- version 1
{
//	Channel1 = new TimeModeParameter(1, false, SlopeName::UP, ThresholdName::Manula, 100, 1, 2);
}

void Model::tick()
{

}

//
void Model::getDataTime()
{
	osSemaphoreRelease(myBinarySemGetDataTimeHandle);
}

// Inna wrsja - remove
//std::unique_ptr<TimeModeParameter> Model::getChannel1()
//{
//  return std::make_unique<TimeModeParameter>(Channel1);  -- version 1
//	std::unique_ptr<TimeModeParameter> ch1(new TimeModeParameter(Channel1));
//	return ch1;
//}
