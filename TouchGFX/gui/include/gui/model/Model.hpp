#ifndef MODEL_HPP
#define MODEL_HPP

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
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
