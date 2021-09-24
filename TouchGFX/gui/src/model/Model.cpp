#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
				, Channel1(1, false, Slope::UP, Threshold::Manula, 200, 1, 2)
{

}

void Model::tick()
{

}

std::unique_ptr<TimeModeParameter> Model::getChannel1()
{

	return std::make_unique<TimeModeParameter>(Channel1);
}
