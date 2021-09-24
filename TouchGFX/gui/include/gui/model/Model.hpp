#ifndef MODEL_HPP
#define MODEL_HPP

#include <gui/lib/TimeModeParameter.hpp>
#include <memory>
#include <cstdint>

extern "C"
{
	#include "cmsis_os.h"
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
//    TimeModeParameter Channel1;
protected:
    ModelListener* modelListener;

};

#endif // MODEL_HPP
