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

extern DataExchange_t DataExchange;

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

    void getDataTimeRepeat();

    void getDataFreqRepeat();

    void getResetTime();

    void getResetFreq();

    void getDetectedTimeThreshold();

    void getDetectedFreqThreshold();

    void updateScreenContinuousTimeMode();

    void updateScreenContinuousFreqMode();

    void getCalibration();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
