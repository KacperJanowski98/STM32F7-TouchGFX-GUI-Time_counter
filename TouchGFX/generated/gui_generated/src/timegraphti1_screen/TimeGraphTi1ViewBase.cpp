/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/timegraphti1_screen/TimeGraphTi1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

TimeGraphTi1ViewBase::TimeGraphTi1ViewBase() :
    buttonCallback(this, &TimeGraphTi1ViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(35, 50, 66));

    boxWithBorder1.setPosition(9, 60, 782, 412);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(3);
    boxWithBorder1.setAlpha(25);

    textLabel.setPosition(262, 17, 273, 27);
    textLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabel.setLinespacing(0);
    textLabelBuffer[0] = 0;
    textLabel.setWildcard(textLabelBuffer);
    textLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID294));

    dynamicGraph1.setScale(1);
    dynamicGraph1.setPosition(9, 60, 782, 412);
    dynamicGraph1.setGraphAreaMargin(15, 65, 25, 50);
    dynamicGraph1.setGraphAreaPadding(0, 20, 0, 0);
    dynamicGraph1.setGraphRangeY(0, 40);

    dynamicGraph1MajorYAxisGrid.setScale(1);
    dynamicGraph1MajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(135, 145, 163));
    dynamicGraph1MajorYAxisGrid.setInterval(2);
    dynamicGraph1MajorYAxisGrid.setLineWidth(1);
    dynamicGraph1.addGraphElement(dynamicGraph1MajorYAxisGrid);

    dynamicGraph1MajorXAxisLabel.setScale(1);
    dynamicGraph1MajorXAxisLabel.setInterval(2);
    dynamicGraph1MajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T_SINGLEUSEID295));
    dynamicGraph1MajorXAxisLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dynamicGraph1.addBottomElement(dynamicGraph1MajorXAxisLabel);

    dynamicGraph1MajorYAxisLabel.setScale(1);
    dynamicGraph1MajorYAxisLabel.setInterval(4);
    dynamicGraph1MajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T_SINGLEUSEID296));
    dynamicGraph1MajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dynamicGraph1.addLeftElement(dynamicGraph1MajorYAxisLabel);

    dynamicGraph1Histogram1.setScale(1);
    dynamicGraph1Histogram1.setColor(touchgfx::Color::getColorFromRGB(68, 227, 163));
    dynamicGraph1Histogram1.setBarWidth(10);
    dynamicGraph1Histogram1.setBaseline(0);
    dynamicGraph1.addGraphElement(dynamicGraph1Histogram1);

    dynamicGraph1.addDataPoint(19.428277907214923f);
    dynamicGraph1.addDataPoint(29.109353398266965f);
    dynamicGraph1.addDataPoint(21.974236846737263f);
    dynamicGraph1.addDataPoint(0.8991352646032951f);
    dynamicGraph1.addDataPoint(13.306393592885035f);
    dynamicGraph1.addDataPoint(24.29241539734094f);
    dynamicGraph1.addDataPoint(15.340891529919688f);
    dynamicGraph1.addDataPoint(29.12384171705957f);
    dynamicGraph1.addDataPoint(38.13664581027876f);
    dynamicGraph1.addDataPoint(15.603600337210146f);
    dynamicGraph1.addDataPoint(12.072074433006854f);
    dynamicGraph1.addDataPoint(20.298640158452137f);
    dynamicGraph1.addDataPoint(6.2256240704804595f);
    dynamicGraph1.addDataPoint(11.967871965945275f);
    dynamicGraph1.addDataPoint(35.162717766457064f);
    dynamicGraph1.addDataPoint(27.22954886775658f);
    dynamicGraph1.addDataPoint(20.58324270920061f);
    dynamicGraph1.addDataPoint(30.79271866683238f);
    dynamicGraph1.addDataPoint(14.459849819506879f);
    dynamicGraph1.addDataPoint(0.9202261019975122f);
    dynamicGraph1.addDataPoint(19.421954100397116f);
    dynamicGraph1.addDataPoint(21.80641816348661f);
    dynamicGraph1.addDataPoint(16.333444836494856f);
    dynamicGraph1.addDataPoint(35.18016411910964f);
    dynamicGraph1.addDataPoint(33.19045292368805f);

    buttonBack.setXY(740, 0);
    buttonBack.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_BACK_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_BACK_NEW_ID));
    buttonBack.setAction(buttonCallback);

    textAreaLabelX.setXY(340, 444);
    textAreaLabelX.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaLabelX.setLinespacing(0);
    textAreaLabelX.setTypedText(touchgfx::TypedText(T_SINGLEUSEID311));

    textAreaLabelY.setPosition(15, 231, 33, 19);
    textAreaLabelY.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaLabelY.setLinespacing(0);
    textAreaLabelYBuffer[0] = 0;
    textAreaLabelY.setWildcard(textAreaLabelYBuffer);
    textAreaLabelY.setTypedText(touchgfx::TypedText(T_SINGLEUSEID312));

    add(__background);
    add(box1);
    add(boxWithBorder1);
    add(textLabel);
    add(dynamicGraph1);
    add(buttonBack);
    add(textAreaLabelX);
    add(textAreaLabelY);
}

void TimeGraphTi1ViewBase::setupScreen()
{

}

void TimeGraphTi1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonBack)
    {
        //Back
        //When buttonBack clicked change screen to TimeHistogram
        //Go to TimeHistogram with screen transition towards East
        application().gotoTimeHistogramScreenWipeTransitionEast();
    }
}
