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

extern FrequencyMode_t FreqBackend;
extern ResultFreq_t ResultFreqBackend;

extern uint32_t detectedThresholdTime;
extern uint32_t detectedThresholdFreq;

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
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
