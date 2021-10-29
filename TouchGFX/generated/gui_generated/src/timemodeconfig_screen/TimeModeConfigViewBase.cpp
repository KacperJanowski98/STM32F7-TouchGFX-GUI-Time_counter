/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/timemodeconfig_screen/TimeModeConfigViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

TimeModeConfigViewBase::TimeModeConfigViewBase() :
    buttonCallback(this, &TimeModeConfigViewBase::buttonCallbackHandler),
    updateItemCallback(this, &TimeModeConfigViewBase::updateItemCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxLeftBackG.setPosition(-1, 60, 75, 420);
    boxLeftBackG.setColor(touchgfx::Color::getColorFromRGB(56, 69, 120));

    boxRightBackG.setPosition(725, 60, 75, 420);
    boxRightBackG.setColor(touchgfx::Color::getColorFromRGB(56, 69, 120));

    boxConfigTime.setPosition(0, 0, 800, 60);
    boxConfigTime.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonBackTime.setXY(740, 0);
    buttonBackTime.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    buttonBackTime.setAction(buttonCallback);

    labelTimeConfig.setXY(15, 18);
    labelTimeConfig.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelTimeConfig.setLinespacing(0);
    labelTimeConfig.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3));

    boxBacgroundTC.setPosition(0, 60, 800, 420);
    boxBacgroundTC.setColor(touchgfx::Color::getColorFromRGB(56, 69, 120));

    swipeContainerTime.setXY(0, 60);
    swipeContainerTime.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID), touchgfx::Bitmap(BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID));
    swipeContainerTime.setPageIndicatorXY(0, 0);
    swipeContainerTime.setSwipeCutoff(50);
    swipeContainerTime.setEndSwipeElasticWidth(50);

    swipeContainerTimeINPUT.setWidth(800);
    swipeContainerTimeINPUT.setHeight(420);

    boxINPUT.setPosition(0, 2, 800, 420);
    boxINPUT.setColor(touchgfx::Color::getColorFromRGB(0, 119, 255));
    swipeContainerTimeINPUT.add(boxINPUT);

    imageArrowR.setXY(770, 180);
    imageArrowR.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_NEXT_ARROW_32_ID));
    swipeContainerTimeINPUT.add(imageArrowR);

    labelINPUT.setXY(15, 16);
    labelINPUT.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelINPUT.setLinespacing(0);
    labelINPUT.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4));
    swipeContainerTimeINPUT.add(labelINPUT);

    textChannelINPUT.setPosition(201, 41, 71, 35);
    textChannelINPUT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textChannelINPUT.setLinespacing(0);
    textChannelINPUTBuffer[0] = 0;
    textChannelINPUT.setWildcard(textChannelINPUTBuffer);
    textChannelINPUT.setTypedText(touchgfx::TypedText(T_SINGLEUSEID18));
    swipeContainerTimeINPUT.add(textChannelINPUT);

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
    swipeContainerTimeINPUT.add(scrollWheelINPUT);

    toggleChannel.setXY(336, 38);
    toggleChannel.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_RE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_RE_LARGE_BUTTON_ON_ID));
    toggleChannel.setAction(buttonCallback);
    swipeContainerTimeINPUT.add(toggleChannel);

    radioSlopeDown.setXY(178, 283);
    radioSlopeDown.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_NORMAL_ID));
    radioSlopeDown.setSelected(false);
    radioSlopeDown.setDeselectionEnabled(false);
    swipeContainerTimeINPUT.add(radioSlopeDown);

    radioSlopeUp.setXY(178, 174);
    radioSlopeUp.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_NORMAL_ID));
    radioSlopeUp.setSelected(false);
    radioSlopeUp.setDeselectionEnabled(false);
    swipeContainerTimeINPUT.add(radioSlopeUp);

    textThreshold.setXY(491, 111);
    textThreshold.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textThreshold.setLinespacing(0);
    textThreshold.setTypedText(touchgfx::TypedText(T_SINGLEUSEID20));
    swipeContainerTimeINPUT.add(textThreshold);

    textSlope.setXY(201, 111);
    textSlope.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSlope.setLinespacing(0);
    textSlope.setTypedText(touchgfx::TypedText(T_SINGLEUSEID19));
    swipeContainerTimeINPUT.add(textSlope);

    buttonDetect.setXY(468, 194);
    buttonDetect.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonDetect.setLabelText(touchgfx::TypedText(T_SINGLEUSEID21));
    buttonDetect.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonDetect.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonDetect.setAction(buttonCallback);
    swipeContainerTimeINPUT.add(buttonDetect);

    textSliderThreshold.setPosition(468, 151, 170, 29);
    textSliderThreshold.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSliderThreshold.setLinespacing(0);
    Unicode::snprintf(textSliderThresholdBuffer, TEXTSLIDERTHRESHOLD_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID25).getText());
    textSliderThreshold.setWildcard(textSliderThresholdBuffer);
    textSliderThreshold.setTypedText(touchgfx::TypedText(T_SINGLEUSEID22));
    swipeContainerTimeINPUT.add(textSliderThreshold);

    sliderThreshold.setXY(677, 35);
    sliderThreshold.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_SLIDER3_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_SLIDER3_VERTICAL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    sliderThreshold.setupVerticalSlider(7, 3, 0, 0, 285);
    sliderThreshold.setValueRange(0, 1000);
    sliderThreshold.setValue(0);
    swipeContainerTimeINPUT.add(sliderThreshold);
    swipeContainerTime.add(swipeContainerTimeINPUT);

    swipeContainerTimeCLOCK.setWidth(800);
    swipeContainerTimeCLOCK.setHeight(420);

    boxCLOCK.setPosition(0, 0, 800, 420);
    boxCLOCK.setColor(touchgfx::Color::getColorFromRGB(68, 72, 94));
    swipeContainerTimeCLOCK.add(boxCLOCK);

    imageArrowCL.setXY(11, 178);
    imageArrowCL.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    swipeContainerTimeCLOCK.add(imageArrowCL);

    imageArrowCR.setXY(770, 178);
    imageArrowCR.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_NEXT_ARROW_32_ID));
    swipeContainerTimeCLOCK.add(imageArrowCR);

    labelCLOCK.setXY(15, 16);
    labelCLOCK.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelCLOCK.setLinespacing(0);
    labelCLOCK.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5));
    swipeContainerTimeCLOCK.add(labelCLOCK);

    textClockExternal.setXY(597, 210);
    textClockExternal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textClockExternal.setLinespacing(0);
    textClockExternal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID28));
    swipeContainerTimeCLOCK.add(textClockExternal);

    radioClockExternal.setXY(616, 114);
    radioClockExternal.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_NORMAL_ID));
    radioClockExternal.setSelected(false);
    radioClockExternal.setDeselectionEnabled(false);
    swipeContainerTimeCLOCK.add(radioClockExternal);

    textClockRubid.setXY(361, 194);
    textClockRubid.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textClockRubid.setLinespacing(0);
    textClockRubid.setTypedText(touchgfx::TypedText(T_SINGLEUSEID27));
    swipeContainerTimeCLOCK.add(textClockRubid);

    radioClockRubid.setXY(378, 114);
    radioClockRubid.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_NORMAL_ID));
    radioClockRubid.setSelected(false);
    radioClockRubid.setDeselectionEnabled(false);
    swipeContainerTimeCLOCK.add(radioClockRubid);

    textClockQuartz.setXY(119, 194);
    textClockQuartz.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textClockQuartz.setLinespacing(0);
    textClockQuartz.setTypedText(touchgfx::TypedText(T_SINGLEUSEID26));
    swipeContainerTimeCLOCK.add(textClockQuartz);

    radioClockQuartz.setXY(136, 114);
    radioClockQuartz.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_NORMAL_ID));
    radioClockQuartz.setSelected(false);
    radioClockQuartz.setDeselectionEnabled(false);
    swipeContainerTimeCLOCK.add(radioClockQuartz);
    swipeContainerTime.add(swipeContainerTimeCLOCK);

    swipeContainerTimeTISETUP.setWidth(800);
    swipeContainerTimeTISETUP.setHeight(420);

    boxTISETUP.setPosition(0, 0, 800, 420);
    boxTISETUP.setColor(touchgfx::Color::getColorFromRGB(54, 50, 125));
    swipeContainerTimeTISETUP.add(boxTISETUP);

    imageArrowTL.setXY(11, 178);
    imageArrowTL.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    swipeContainerTimeTISETUP.add(imageArrowTL);

    imageArrowTR.setXY(770, 178);
    imageArrowTR.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_NEXT_ARROW_32_ID));
    swipeContainerTimeTISETUP.add(imageArrowTR);

    labelTISETUP.setXY(15, 16);
    labelTISETUP.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelTISETUP.setLinespacing(0);
    labelTISETUP.setTypedText(touchgfx::TypedText(T_SINGLEUSEID6));
    swipeContainerTimeTISETUP.add(labelTISETUP);

    scrollWheelTISetup.setPosition(36, 85, 100, 300);
    scrollWheelTISetup.setHorizontal(false);
    scrollWheelTISetup.setCircular(false);
    scrollWheelTISetup.setEasingEquation(touchgfx::EasingEquations::circEaseOut);
    scrollWheelTISetup.setSwipeAcceleration(40);
    scrollWheelTISetup.setDragAcceleration(10);
    scrollWheelTISetup.setNumberOfItems(7);
    scrollWheelTISetup.setSelectedItemOffset(120);
    scrollWheelTISetup.setSelectedItemExtraSize(0, 0);
    scrollWheelTISetup.setSelectedItemMargin(0, 0);
    scrollWheelTISetup.setDrawableSize(60, 0);
    scrollWheelTISetup.setDrawables(scrollWheelTISetupListItems, updateItemCallback,
                              scrollWheelTISetupSelectedListItems, updateItemCallback);
    scrollWheelTISetup.animateToItem(0, 0);
    swipeContainerTimeTISETUP.add(scrollWheelTISetup);

    textOnOffChannel.setPosition(151, 219, 50, 38);
    textOnOffChannel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textOnOffChannel.setLinespacing(0);
    textOnOffChannelBuffer[0] = 0;
    textOnOffChannel.setWildcard(textOnOffChannelBuffer);
    textOnOffChannel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID29));
    swipeContainerTimeTISETUP.add(textOnOffChannel);

    textTiStop.setXY(409, 280);
    textTiStop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTiStop.setLinespacing(0);
    textTiStop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID31));
    swipeContainerTimeTISETUP.add(textTiStop);

    textTiStart.setXY(399, 102);
    textTiStart.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTiStart.setLinespacing(0);
    textTiStart.setTypedText(touchgfx::TypedText(T_SINGLEUSEID30));
    swipeContainerTimeTISETUP.add(textTiStart);

    textOnState.setPosition(222, 219, 50, 38);
    textOnState.setVisible(false);
    textOnState.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textOnState.setLinespacing(0);
    textOnState.setTypedText(touchgfx::TypedText(T_SINGLEUSEID32));
    swipeContainerTimeTISETUP.add(textOnState);

    textOffState.setPosition(222, 219, 50, 38);
    textOffState.setVisible(false);
    textOffState.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textOffState.setLinespacing(0);
    textOffState.setTypedText(touchgfx::TypedText(T_SINGLEUSEID33));
    swipeContainerTimeTISETUP.add(textOffState);

    scrollWheelStart.setPosition(610, 24, 100, 180);
    scrollWheelStart.setHorizontal(false);
    scrollWheelStart.setCircular(false);
    scrollWheelStart.setEasingEquation(touchgfx::EasingEquations::circEaseOut);
    scrollWheelStart.setSwipeAcceleration(40);
    scrollWheelStart.setDragAcceleration(10);
    scrollWheelStart.setNumberOfItems(8);
    scrollWheelStart.setSelectedItemOffset(60);
    scrollWheelStart.setSelectedItemExtraSize(0, 0);
    scrollWheelStart.setSelectedItemMargin(0, 0);
    scrollWheelStart.setDrawableSize(60, 0);
    scrollWheelStart.setDrawables(scrollWheelStartListItems, updateItemCallback,
                              scrollWheelStartSelectedListItems, updateItemCallback);
    scrollWheelStart.animateToItem(0, 0);
    swipeContainerTimeTISETUP.add(scrollWheelStart);

    textStartChannel.setPosition(539, 102, 71, 25);
    textStartChannel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStartChannel.setLinespacing(0);
    textStartChannelBuffer[0] = 0;
    textStartChannel.setWildcard(textStartChannelBuffer);
    textStartChannel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID34));
    swipeContainerTimeTISETUP.add(textStartChannel);

    textStopChannel.setPosition(539, 280, 71, 25);
    textStopChannel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStopChannel.setLinespacing(0);
    textStopChannelBuffer[0] = 0;
    textStopChannel.setWildcard(textStopChannelBuffer);
    textStopChannel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID35));
    swipeContainerTimeTISETUP.add(textStopChannel);

    scrollWheelStop.setPosition(611, 204, 100, 180);
    scrollWheelStop.setHorizontal(false);
    scrollWheelStop.setCircular(false);
    scrollWheelStop.setEasingEquation(touchgfx::EasingEquations::circEaseOut);
    scrollWheelStop.setSwipeAcceleration(40);
    scrollWheelStop.setDragAcceleration(10);
    scrollWheelStop.setNumberOfItems(8);
    scrollWheelStop.setSelectedItemOffset(60);
    scrollWheelStop.setSelectedItemExtraSize(0, 0);
    scrollWheelStop.setSelectedItemMargin(0, 0);
    scrollWheelStop.setDrawableSize(60, 0);
    scrollWheelStop.setDrawables(scrollWheelStopListItems, updateItemCallback,
                              scrollWheelStopSelectedListItems, updateItemCallback);
    scrollWheelStop.animateToItem(0, 0);
    swipeContainerTimeTISETUP.add(scrollWheelStop);

    toggleTiSetup.setXY(188, 83);
    toggleTiSetup.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_RE_SMALL_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_RE_SMALL_BUTTON_ON_ID));
    toggleTiSetup.setAction(buttonCallback);
    swipeContainerTimeTISETUP.add(toggleTiSetup);
    swipeContainerTime.add(swipeContainerTimeTISETUP);

    swipeContainerTimeSESSION.setWidth(800);
    swipeContainerTimeSESSION.setHeight(420);

    boxSESSIONSETUP.setPosition(-1, 2, 801, 420);
    boxSESSIONSETUP.setColor(touchgfx::Color::getColorFromRGB(77, 114, 148));
    swipeContainerTimeSESSION.add(boxSESSIONSETUP);

    imageArrowSL.setXY(11, 178);
    imageArrowSL.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    swipeContainerTimeSESSION.add(imageArrowSL);

    labelSESSIONSETUP.setXY(15, 16);
    labelSESSIONSETUP.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelSESSIONSETUP.setLinespacing(0);
    labelSESSIONSETUP.setTypedText(touchgfx::TypedText(T_SINGLEUSEID7));
    swipeContainerTimeSESSION.add(labelSESSIONSETUP);

    textTiMaxRange.setXY(158, 80);
    textTiMaxRange.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTiMaxRange.setLinespacing(0);
    textTiMaxRange.setTypedText(touchgfx::TypedText(T_SINGLEUSEID36));
    swipeContainerTimeSESSION.add(textTiMaxRange);

    textRangeVal.setPosition(530, 77, 162, 28);
    textRangeVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textRangeVal.setLinespacing(0);
    Unicode::snprintf(textRangeValBuffer, TEXTRANGEVAL_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID43).getText());
    textRangeVal.setWildcard(textRangeValBuffer);
    textRangeVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID40));
    swipeContainerTimeSESSION.add(textRangeVal);

    sliderRange.setXY(706, 2);
    sliderRange.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    sliderRange.setupVerticalSlider(7, 3, 0, 0, 125);
    sliderRange.setValueRange(0, 1000);
    sliderRange.setValue(0);
    swipeContainerTimeSESSION.add(sliderRange);

    textStampsVal.setPosition(244, 230, 128, 29);
    textStampsVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStampsVal.setLinespacing(0);
    Unicode::snprintf(textStampsValBuffer, TEXTSTAMPSVAL_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID44).getText());
    textStampsVal.setWildcard(textStampsValBuffer);
    textStampsVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID42));
    swipeContainerTimeSESSION.add(textStampsVal);

    textSampsNumber.setXY(61, 232);
    textSampsNumber.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSampsNumber.setLinespacing(0);
    textSampsNumber.setTypedText(touchgfx::TypedText(T_SINGLEUSEID45));
    swipeContainerTimeSESSION.add(textSampsNumber);

    textX.setXY(386, 220);
    textX.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textX.setLinespacing(0);
    textX.setTypedText(touchgfx::TypedText(T_SINGLEUSEID46));
    swipeContainerTimeSESSION.add(textX);

    textArea1.setXY(464, 229);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID47));
    swipeContainerTimeSESSION.add(textArea1);

    textRepeatVal.setPosition(620, 233, 120, 24);
    textRepeatVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textRepeatVal.setLinespacing(0);
    Unicode::snprintf(textRepeatValBuffer, TEXTREPEATVAL_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID49).getText());
    textRepeatVal.setWildcard(textRepeatValBuffer);
    textRepeatVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID48));
    swipeContainerTimeSESSION.add(textRepeatVal);

    sliderStampsNumber.setXY(36, 277);
    sliderStampsNumber.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER2_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER2_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_INDICATORS_SLIDER2_ROUND_NOB_ID));
    sliderStampsNumber.setupHorizontalSlider(2, 6, 0, 0, 284);
    sliderStampsNumber.setValueRange(0, 1000);
    sliderStampsNumber.setValue(0);
    swipeContainerTimeSESSION.add(sliderStampsNumber);

    sliderRepeat.setXY(501, 275);
    sliderRepeat.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_INDICATORS_SLIDER_HORIZONTAL_SMALL_ROUND_KNOB_ID));
    sliderRepeat.setupHorizontalSlider(3, 7, 0, 0, 125);
    sliderRepeat.setValueRange(0, 100);
    sliderRepeat.setValue(0);
    swipeContainerTimeSESSION.add(sliderRepeat);

    toggleTiMaxRange.setXY(26, 73);
    toggleTiMaxRange.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_RE_SMALL_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_RE_SMALL_BUTTON_ON_ID));
    toggleTiMaxRange.setAction(buttonCallback);
    swipeContainerTimeSESSION.add(toggleTiMaxRange);

    buttonConfigTimeSingle.setXY(159, 134);
    buttonConfigTimeSingle.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfigTimeSingle.setLabelText(touchgfx::TypedText(T_SINGLEUSEID84));
    buttonConfigTimeSingle.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigTimeSingle.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigTimeSingle.setAction(buttonCallback);
    swipeContainerTimeSESSION.add(buttonConfigTimeSingle);

    buttonConfigTimeConst.setXY(468, 134);
    buttonConfigTimeConst.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfigTimeConst.setLabelText(touchgfx::TypedText(T_SINGLEUSEID85));
    buttonConfigTimeConst.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigTimeConst.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigTimeConst.setAction(buttonCallback);
    swipeContainerTimeSESSION.add(buttonConfigTimeConst);

    buttonConfigTimeStamps.setXY(120, 336);
    buttonConfigTimeStamps.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfigTimeStamps.setLabelText(touchgfx::TypedText(T_SINGLEUSEID86));
    buttonConfigTimeStamps.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigTimeStamps.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigTimeStamps.setAction(buttonCallback);
    swipeContainerTimeSESSION.add(buttonConfigTimeStamps);

    buttonConfigTimeRepeat.setXY(505, 336);
    buttonConfigTimeRepeat.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfigTimeRepeat.setLabelText(touchgfx::TypedText(T_SINGLEUSEID273));
    buttonConfigTimeRepeat.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigTimeRepeat.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfigTimeRepeat.setAction(buttonCallback);
    swipeContainerTimeSESSION.add(buttonConfigTimeRepeat);
    swipeContainerTime.add(swipeContainerTimeSESSION);
    swipeContainerTime.setSelectedPage(0);

    add(__background);
    add(boxLeftBackG);
    add(boxRightBackG);
    add(boxConfigTime);
    add(buttonBackTime);
    add(labelTimeConfig);
    add(boxBacgroundTC);
    add(swipeContainerTime);
    radioButtonGroupSlope.add(radioSlopeDown);
    radioButtonGroupSlope.add(radioSlopeUp);
    radioButtonGroupClock.add(radioClockExternal);
    radioButtonGroupClock.add(radioClockRubid);
    radioButtonGroupClock.add(radioClockQuartz);
}

void TimeModeConfigViewBase::setupScreen()
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
    scrollWheelTISetup.initialize();
    for (int i = 0; i < scrollWheelTISetupListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelTISetupListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelTISetupSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelTISetupSelectedListItems[i].initialize();
    }
    scrollWheelStart.initialize();
    for (int i = 0; i < scrollWheelStartListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelStartListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelStartSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelStartSelectedListItems[i].initialize();
    }
    scrollWheelStop.initialize();
    for (int i = 0; i < scrollWheelStopListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelStopListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelStopSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelStopSelectedListItems[i].initialize();
    }
}

void TimeModeConfigViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonBackTime)
    {
        //BackToTimeMode
        //When buttonBackTime clicked change screen to TimeMode
        //Go to TimeMode with screen transition towards West
        application().gotoTimeModeScreenCoverTransitionWest();
    }
    else if (&src == &toggleChannel)
    {
        //TurnOnOffChannel
        //When toggleChannel clicked call virtual function
        //Call ChangeChannelState
        ChangeChannelState();
    }
    else if (&src == &buttonDetect)
    {
        //DetectThreshold
        //When buttonDetect clicked call virtual function
        //Call detectThreshold
        detectThreshold();
    }
    else if (&src == &toggleTiSetup)
    {
        //TurnOnOfTiChannel
        //When toggleTiSetup clicked call virtual function
        //Call ChangeStateTI
        ChangeStateTI();
    }
    else if (&src == &toggleTiMaxRange)
    {
        //OnOffMaxRange
        //When toggleTiMaxRange clicked call virtual function
        //Call turnTiMaxRange
        turnTiMaxRange();
    }
    else if (&src == &buttonConfigTimeSingle)
    {
        //FinishTimeModeSingle
        //When buttonConfigTimeSingle clicked call virtual function
        //Call FinishSetupTimeModeSingle
        FinishSetupTimeModeSingle();
    }
    else if (&src == &buttonConfigTimeConst)
    {
        //FinishTimeModeConst
        //When buttonConfigTimeConst clicked call virtual function
        //Call FinishSetupTimeModeConst
        FinishSetupTimeModeConst();
    }
    else if (&src == &buttonConfigTimeStamps)
    {
        //FinishTimeModeStamps
        //When buttonConfigTimeStamps clicked call virtual function
        //Call FinishSetupTimeModeStamps
        FinishSetupTimeModeStamps();
    }
    else if (&src == &buttonConfigTimeRepeat)
    {
        //FinishTimeModeRepeat
        //When buttonConfigTimeRepeat clicked call virtual function
        //Call FinishSetupTimeModeRepeat
        FinishSetupTimeModeRepeat();
    }
}

void TimeModeConfigViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
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
    if (items == &scrollWheelTISetupListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ChannelContainer* cc = (ChannelContainer*)d;
        scrollWheelTISetupUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelTISetupSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ChannelContainerCenter* cc = (ChannelContainerCenter*)d;
        scrollWheelTISetupUpdateCenterItem(*cc, itemIndex);
    }
    if (items == &scrollWheelStartListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ChannelContainer* cc = (ChannelContainer*)d;
        scrollWheelStartUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelStartSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ChannelContainerCenter* cc = (ChannelContainerCenter*)d;
        scrollWheelStartUpdateCenterItem(*cc, itemIndex);
    }
    if (items == &scrollWheelStopListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ChannelContainer* cc = (ChannelContainer*)d;
        scrollWheelStopUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelStopSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ChannelContainerCenter* cc = (ChannelContainerCenter*)d;
        scrollWheelStopUpdateCenterItem(*cc, itemIndex);
    }
}
