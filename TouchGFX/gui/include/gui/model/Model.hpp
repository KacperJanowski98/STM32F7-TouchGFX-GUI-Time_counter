#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

#include <main.h>

extern LPS25HB_Result_t Result;
extern LPS25HB_measurement_t Measure;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void lps25hbMsgRdy();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
