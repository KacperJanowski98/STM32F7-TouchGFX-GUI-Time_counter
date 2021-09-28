#ifndef MODEL_HPP
#define MODEL_HPP

#include <gui/lib/TimeModeParameter.hpp>
#include <memory>
#include <cstdint>
#include <algorithm>
#include <vector>


extern int testDisplay;

extern "C"
{
	#include "cmsis_os.h"
	#include "cmsis_os2.h"
}

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void getDataTime();

//    std::unique_ptr<TimeModeParameter> getChannel1();
protected:
    ModelListener* modelListener;
//private:
//    TimeModeParameter Channel1;
};

#endif // MODEL_HPP
