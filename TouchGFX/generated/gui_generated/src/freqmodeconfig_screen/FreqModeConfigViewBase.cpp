/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/freqmodeconfig_screen/FreqModeConfigViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

FreqModeConfigViewBase::FreqModeConfigViewBase() :
    buttonCallback(this, &FreqModeConfigViewBase::buttonCallbackHandler),
    updateItemCallback(this, &FreqModeConfigViewBase::updateItemCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxLeftBackG.setPosition(-1, 60, 75, 420);
    boxLeftBackG.setColor(touchgfx::Color::getColorFromRGB(13, 122, 255));

    boxRightBackG.setPosition(725, 60, 75, 420);
    boxRightBackG.setColor(touchgfx::Color::getColorFromRGB(13, 122, 255));

    boxConfigFreq.setPosition(0, 0, 800, 60);
    boxConfigFreq.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonBackFreq.setXY(740, 0);
    buttonBackFreq.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    buttonBackFreq.setAction(buttonCallback);

    labelFreqConfig.setXY(17, 18);
    labelFreqConfig.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelFreqConfig.setLinespacing(0);
    labelFreqConfig.setTypedText(touchgfx::TypedText(T_SINGLEUSEID8));

    boxBackgroundFC.setPosition(0, 60, 800, 420);
    boxBackgroundFC.setColor(touchgfx::Color::getColorFromRGB(13, 122, 255));

    swipeContainerFreq.setXY(0, 60);
    swipeContainerFreq.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID), touchgfx::Bitmap(BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID));
    swipeContainerFreq.setPageIndicatorXY(0, 0);
    swipeContainerFreq.setSwipeCutoff(50);
    swipeContainerFreq.setEndSwipeElasticWidth(50);

    swipeContainerFreqINPUT.setWidth(800);
    swipeContainerFreqINPUT.setHeight(420);

    boxINPUT.setPosition(0, 0, 800, 420);
    boxINPUT.setColor(touchgfx::Color::getColorFromRGB(2, 90, 191));
    swipeContainerFreqINPUT.add(boxINPUT);

    imageArrowR.setXY(770, 180);
    imageArrowR.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_NEXT_ARROW_32_ID));
    swipeContainerFreqINPUT.add(imageArrowR);

    labelINPUT.setXY(15, 16);
    labelINPUT.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelINPUT.setLinespacing(0);
    labelINPUT.setTypedText(touchgfx::TypedText(T_SINGLEUSEID9));
    swipeContainerFreqINPUT.add(labelINPUT);

    toggleChannel.setXY(336, 38);
    toggleChannel.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_RE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_RE_LARGE_BUTTON_ON_ID));
    toggleChannel.setAction(buttonCallback);
    swipeContainerFreqINPUT.add(toggleChannel);

    radioSlopeDown.setXY(178, 283);
    radioSlopeDown.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_NORMAL_ID));
    radioSlopeDown.setSelected(false);
    radioSlopeDown.setDeselectionEnabled(false);
    swipeContainerFreqINPUT.add(radioSlopeDown);

    radioSlopeUp.setXY(178, 174);
    radioSlopeUp.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_NORMAL_ID));
    radioSlopeUp.setSelected(false);
    radioSlopeUp.setDeselectionEnabled(false);
    swipeContainerFreqINPUT.add(radioSlopeUp);

    textThreshold.setXY(491, 111);
    textThreshold.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textThreshold.setLinespacing(0);
    textThreshold.setTypedText(touchgfx::TypedText(T_SINGLEUSEID55));
    swipeContainerFreqINPUT.add(textThreshold);

    scrollWheelINPUT.setPosition(36, 85, 100, 300);
    scrollWheelINPUT.setHorizontal(false);
    scrollWheelINPUT.setCircular(false);
    scrollWheelINPUT.setEasingEquation(touchgfx::EasingEquations::circEaseOut);
    scrollWheelINPUT.setSwipeAcceleration(40);
    scrollWheelINPUT.setDragAcceleration(10);
    scrollWheelINPUT.setNumberOfItems(8);
    scrollWheelINPUT.setSelectedItemOffset(120);
    scrollWheelINPUT.setSelectedItemExtraSize(0, 0);
    scrollWheelINPUT.setSelectedItemMargin(0, 0);
    scrollWheelINPUT.setDrawableSize(60, 0);
    scrollWheelINPUT.setDrawables(scrollWheelINPUTListItems, updateItemCallback,
                              scrollWheelINPUTSelectedListItems, updateItemCallback);
    scrollWheelINPUT.animateToItem(0, 0);
    swipeContainerFreqINPUT.add(scrollWheelINPUT);

    textSlope.setXY(201, 111);
    textSlope.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSlope.setLinespacing(0);
    textSlope.setTypedText(touchgfx::TypedText(T_SINGLEUSEID56));
    swipeContainerFreqINPUT.add(textSlope);

    buttonDetect.setXY(468, 194);
    buttonDetect.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonDetect.setLabelText(touchgfx::TypedText(T_SINGLEUSEID57));
    buttonDetect.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonDetect.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    swipeContainerFreqINPUT.add(buttonDetect);

    textSliderThreshold.setPosition(468, 151, 170, 29);
    textSliderThreshold.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSliderThreshold.setLinespacing(0);
    Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID59).getText());
    textSliderThreshold.setWildcard(textSliderThresholdBuffer);
    textSliderThreshold.setTypedText(touchgfx::TypedText(T_SINGLEUSEID58));
    swipeContainerFreqINPUT.add(textSliderThreshold);

    sliderThreshold.setXY(677, 35);
    sliderThreshold.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_SLIDER3_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_SLIDER3_VERTICAL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    sliderThreshold.setupVerticalSlider(7, 3, 0, 0, 285);
    sliderThreshold.setValueRange(0, 1000);
    sliderThreshold.setValue(0);
    swipeContainerFreqINPUT.add(sliderThreshold);

    textChannelINPUT.setPosition(201, 41, 71, 35);
    textChannelINPUT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textChannelINPUT.setLinespacing(0);
    textChannelINPUTBuffer[0] = 0;
    textChannelINPUT.setWildcard(textChannelINPUTBuffer);
    textChannelINPUT.setTypedText(touchgfx::TypedText(T_SINGLEUSEID65));
    swipeContainerFreqINPUT.add(textChannelINPUT);
    swipeContainerFreq.add(swipeContainerFreqINPUT);

    swipeContainerFreqCLOCK.setWidth(800);
    swipeContainerFreqCLOCK.setHeight(420);

    boxCLOCK.setPosition(0, 0, 800, 420);
    boxCLOCK.setColor(touchgfx::Color::getColorFromRGB(68, 72, 94));
    swipeContainerFreqCLOCK.add(boxCLOCK);

    imageArrowCL.setXY(11, 178);
    imageArrowCL.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    swipeContainerFreqCLOCK.add(imageArrowCL);

    imageArrowCR.setXY(770, 178);
    imageArrowCR.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_NEXT_ARROW_32_ID));
    swipeContainerFreqCLOCK.add(imageArrowCR);

    labelCLOCK.setXY(15, 16);
    labelCLOCK.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelCLOCK.setLinespacing(0);
    labelCLOCK.setTypedText(touchgfx::TypedText(T_SINGLEUSEID10));
    swipeContainerFreqCLOCK.add(labelCLOCK);

    textClockExternal.setXY(597, 210);
    textClockExternal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textClockExternal.setLinespacing(0);
    textClockExternal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID62));
    swipeContainerFreqCLOCK.add(textClockExternal);

    radioClockExternal.setXY(616, 114);
    radioClockExternal.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_NORMAL_ID));
    radioClockExternal.setSelected(false);
    radioClockExternal.setDeselectionEnabled(false);
    swipeContainerFreqCLOCK.add(radioClockExternal);

    textClockRubid.setXY(361, 194);
    textClockRubid.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textClockRubid.setLinespacing(0);
    textClockRubid.setTypedText(touchgfx::TypedText(T_SINGLEUSEID63));
    swipeContainerFreqCLOCK.add(textClockRubid);

    radioClockRubid.setXY(378, 114);
    radioClockRubid.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_NORMAL_ID));
    radioClockRubid.setSelected(false);
    radioClockRubid.setDeselectionEnabled(false);
    swipeContainerFreqCLOCK.add(radioClockRubid);

    textClockQuartz.setXY(119, 194);
    textClockQuartz.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textClockQuartz.setLinespacing(0);
    textClockQuartz.setTypedText(touchgfx::TypedText(T_SINGLEUSEID64));
    swipeContainerFreqCLOCK.add(textClockQuartz);

    radioClockQuartz.setXY(136, 114);
    radioClockQuartz.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_NORMAL_ID));
    radioClockQuartz.setSelected(false);
    radioClockQuartz.setDeselectionEnabled(false);
    swipeContainerFreqCLOCK.add(radioClockQuartz);
    swipeContainerFreq.add(swipeContainerFreqCLOCK);

    swipeContainerFreqMESSETUP.setWidth(800);
    swipeContainerFreqMESSETUP.setHeight(420);

    imageArrowTL.setXY(11, 178);
    imageArrowTL.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    swipeContainerFreqMESSETUP.add(imageArrowTL);

    imageArrowTR.setXY(770, 178);
    imageArrowTR.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_NEXT_ARROW_32_ID));
    swipeContainerFreqMESSETUP.add(imageArrowTR);

    labelTISETUP.setXY(15, 16);
    labelTISETUP.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelTISETUP.setLinespacing(0);
    labelTISETUP.setTypedText(touchgfx::TypedText(T_SINGLEUSEID11));
    swipeContainerFreqMESSETUP.add(labelTISETUP);

    boxTISETUP.setPosition(0, 0, 800, 420);
    boxTISETUP.setColor(touchgfx::Color::getColorFromRGB(54, 50, 125));
    swipeContainerFreqMESSETUP.add(boxTISETUP);

    labelHfInput.setXY(82, 76);
    labelHfInput.setColor(touchgfx::Color::getColorFromRGB(252, 252, 252));
    labelHfInput.setLinespacing(0);
    labelHfInput.setTypedText(touchgfx::TypedText(T_SINGLEUSEID66));
    swipeContainerFreqMESSETUP.add(labelHfInput);

    imageArrowML.setXY(11, 178);
    imageArrowML.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    swipeContainerFreqMESSETUP.add(imageArrowML);

    imageArrowMR.setXY(770, 178);
    imageArrowMR.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_NEXT_ARROW_32_ID));
    swipeContainerFreqMESSETUP.add(imageArrowMR);

    radioHfInputOn.setXY(159, 120);
    radioHfInputOn.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_NORMAL_ID));
    radioHfInputOn.setSelected(false);
    radioHfInputOn.setDeselectionEnabled(false);
    swipeContainerFreqMESSETUP.add(radioHfInputOn);

    radioHfInputOff.setXY(449, 123);
    radioHfInputOff.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_NORMAL_ID));
    radioHfInputOff.setSelected(false);
    radioHfInputOff.setDeselectionEnabled(false);
    swipeContainerFreqMESSETUP.add(radioHfInputOff);

    textON.setXY(266, 118);
    textON.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textON.setLinespacing(0);
    textON.setTypedText(touchgfx::TypedText(T_SINGLEUSEID67));
    swipeContainerFreqMESSETUP.add(textON);

    textOFF.setXY(560, 118);
    textOFF.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textOFF.setLinespacing(0);
    textOFF.setTypedText(touchgfx::TypedText(T_SINGLEUSEID68));
    swipeContainerFreqMESSETUP.add(textOFF);

    labelGate.setXY(86, 224);
    labelGate.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelGate.setLinespacing(0);
    labelGate.setTypedText(touchgfx::TypedText(T_SINGLEUSEID69));
    swipeContainerFreqMESSETUP.add(labelGate);

    textGateVal.setPosition(328, 274, 142, 31);
    textGateVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textGateVal.setLinespacing(0);
    textGateValBuffer[0] = 0;
    textGateVal.setWildcard(textGateValBuffer);
    textGateVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID70));
    swipeContainerFreqMESSETUP.add(textGateVal);

    sliderGate.setXY(230, 334);
    sliderGate.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER2_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER2_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_INDICATORS_SLIDER2_ROUND_NOB_ID));
    sliderGate.setupHorizontalSlider(2, 6, 0, 0, 284);
    sliderGate.setValueRange(0, 100);
    sliderGate.setValue(0);
    swipeContainerFreqMESSETUP.add(sliderGate);

    labelMesSetup.setXY(17, 16);
    labelMesSetup.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelMesSetup.setLinespacing(0);
    labelMesSetup.setTypedText(touchgfx::TypedText(T_SINGLEUSEID71));
    swipeContainerFreqMESSETUP.add(labelMesSetup);
    swipeContainerFreq.add(swipeContainerFreqMESSETUP);

    swipeContainerFreqSESSION.setWidth(800);
    swipeContainerFreqSESSION.setHeight(420);

    boxSESSIONSETUP.setPosition(-1, 0, 801, 420);
    boxSESSIONSETUP.setColor(touchgfx::Color::getColorFromRGB(77, 114, 148));
    swipeContainerFreqSESSION.add(boxSESSIONSETUP);

    imageArrowSL.setXY(11, 178);
    imageArrowSL.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    swipeContainerFreqSESSION.add(imageArrowSL);

    labelSESSIONSETUP.setXY(15, 16);
    labelSESSIONSETUP.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelSESSIONSETUP.setLinespacing(0);
    labelSESSIONSETUP.setTypedText(touchgfx::TypedText(T_SINGLEUSEID12));
    swipeContainerFreqSESSION.add(labelSESSIONSETUP);

    textStampsVal.setPosition(244, 192, 128, 29);
    textStampsVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStampsVal.setLinespacing(0);
    Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID74).getText());
    textStampsVal.setWildcard(textStampsValBuffer);
    textStampsVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID73));
    swipeContainerFreqSESSION.add(textStampsVal);

    textSampsNumber.setXY(60, 192);
    textSampsNumber.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSampsNumber.setLinespacing(0);
    textSampsNumber.setTypedText(touchgfx::TypedText(T_SINGLEUSEID75));
    swipeContainerFreqSESSION.add(textSampsNumber);

    textX.setXY(386, 182);
    textX.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textX.setLinespacing(0);
    textX.setTypedText(touchgfx::TypedText(T_SINGLEUSEID76));
    swipeContainerFreqSESSION.add(textX);

    textArea1.setXY(464, 196);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID77));
    swipeContainerFreqSESSION.add(textArea1);

    textRepeatVal.setPosition(620, 197, 120, 24);
    textRepeatVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textRepeatVal.setLinespacing(0);
    Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID79).getText());
    textRepeatVal.setWildcard(textRepeatValBuffer);
    textRepeatVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID78));
    swipeContainerFreqSESSION.add(textRepeatVal);

    sliderStampsNumber.setXY(112, 263);
    sliderStampsNumber.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_INDICATORS_SLIDER_HORIZONTAL_SMALL_ROUND_KNOB_ID));
    sliderStampsNumber.setupHorizontalSlider(3, 7, 0, 0, 125);
    sliderStampsNumber.setValueRange(0, 1000);
    sliderStampsNumber.setValue(0);
    swipeContainerFreqSESSION.add(sliderStampsNumber);

    sliderRepeat.setXY(501, 263);
    sliderRepeat.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_INDICATORS_SLIDER_HORIZONTAL_SMALL_ROUND_KNOB_ID));
    sliderRepeat.setupHorizontalSlider(3, 7, 0, 0, 125);
    sliderRepeat.setValueRange(0, 100);
    sliderRepeat.setValue(0);
    swipeContainerFreqSESSION.add(sliderRepeat);

    buttonConfigFreqStamps.setXY(315, 327);
    buttonConfigFreqStamps.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfigFreqStamps.setLabelText(touchgfx::TypedText(T_SINGLEUSEID89));
    buttonConfigFreqStamps.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigFreqStamps.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigFreqStamps.setAction(buttonCallback);
    swipeContainerFreqSESSION.add(buttonConfigFreqStamps);

    buttonConfigFreqConst.setXY(485, 84);
    buttonConfigFreqConst.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfigFreqConst.setLabelText(touchgfx::TypedText(T_SINGLEUSEID88));
    buttonConfigFreqConst.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigFreqConst.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigFreqConst.setAction(buttonCallback);
    swipeContainerFreqSESSION.add(buttonConfigFreqConst);

    buttonConfigFreqSingle.setXY(141, 81);
    buttonConfigFreqSingle.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfigFreqSingle.setLabelText(touchgfx::TypedText(T_SINGLEUSEID87));
    buttonConfigFreqSingle.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigFreqSingle.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigFreqSingle.setAction(buttonCallback);
    swipeContainerFreqSESSION.add(buttonConfigFreqSingle);
    swipeContainerFreq.add(swipeContainerFreqSESSION);
    swipeContainerFreq.setSelectedPage(0);

    add(__background);
    add(boxLeftBackG);
    add(boxRightBackG);
    add(boxConfigFreq);
    add(buttonBackFreq);
    add(labelFreqConfig);
    add(boxBackgroundFC);
    add(swipeContainerFreq);
    radioButtonGroupSlopeFreq.add(radioSlopeDown);
    radioButtonGroupSlopeFreq.add(radioSlopeUp);
    radioButtonGroupClock.add(radioClockExternal);
    radioButtonGroupClock.add(radioClockRubid);
    radioButtonGroupClock.add(radioClockQuartz);
    radioButtonGroupHfInput.add(radioHfInputOn);
    radioButtonGroupHfInput.add(radioHfInputOff);
}

void FreqModeConfigViewBase::setupScreen()
{
    scrollWheelINPUT.initialize();
    for (int i = 0; i < scrollWheelINPUTListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelINPUTListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelINPUTSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelINPUTSelectedListItems[i].initialize();
    }
}

void FreqModeConfigViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonBackFreq)
    {
        //BackToFreqMode
        //When buttonBackFreq clicked change screen to FreqMode
        //Go to FreqMode with screen transition towards West
        application().gotoFreqModeScreenCoverTransitionWest();
    }
    else if (&src == &toggleChannel)
    {
        //TurnOnOffChannelState
        //When toggleChannel clicked call virtual function
        //Call toggleChannelState
        toggleChannelState();
    }
    else if (&src == &buttonConfigFreqStamps)
    {
        //FinishFreqModeStamps
        //When buttonConfigFreqStamps clicked call virtual function
        //Call FinishSetupFreqModeStamps
        FinishSetupFreqModeStamps();
    }
    else if (&src == &buttonConfigFreqConst)
    {
        //FinishFreqModeConst
        //When buttonConfigFreqConst clicked call virtual function
        //Call FinishSetupFreqModeConst
        FinishSetupFreqModeConst();
    }
    else if (&src == &buttonConfigFreqSingle)
    {
        //FinishFreqModeSingle
        //When buttonConfigFreqSingle clicked call virtual function
        //Call FinishSetupFreqModeSingle
        FinishSetupFreqModeSingle();
    }
}

void FreqModeConfigViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollWheelINPUTListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ChannelContainer* cc = (ChannelContainer*)d;
        scrollWheelINPUTUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelINPUTSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ChannelContainerCenter* cc = (ChannelContainerCenter*)d;
        scrollWheelINPUTUpdateCenterItem(*cc, itemIndex);
    }
}
