#ifndef MODEL_HPP
#define MODEL_HPP

#include <gui/lib/TimeModeParameter.hpp>
#include <memory>
#include <cstdint>
#include <algorithm>
#include <vector>
#include "main.h"
#include "cmsis_os.h"
#include "cmsis_os2.h"

extern TimeMode_t TimeBackend;
extern ResultTime_t ResultTimeBackend;

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

    void getDataTimeSingle();

    void getDataFreqSingle();

    void getDataTimeContinuous();

    void getDataFreqContinuous();

    void getDataTimeStamps();

    void getDataFreqStamps();

    void getReset();

    void updateScreenContinuousTimeMode();

//    std::unique_ptr<TimeModeParameter> getChannel1();
protected:
    ModelListener* modelListener;
//private:
//    TimeModeParameter Channel1;
};

#endif // MODEL_HPP
