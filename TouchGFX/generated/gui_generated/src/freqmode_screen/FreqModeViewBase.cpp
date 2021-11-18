/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/freqmode_screen/FreqModeViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

FreqModeViewBase::FreqModeViewBase() :
    buttonCallback(this, &FreqModeViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxBackgroungFreq.setPosition(0, 0, 800, 480);
    boxBackgroungFreq.setColor(touchgfx::Color::getColorFromRGB(67, 88, 112));

    boxWithBorderMain.setPosition(9, 75, 783, 389);
    boxWithBorderMain.setColor(touchgfx::Color::getColorFromRGB(17, 3, 59));
    boxWithBorderMain.setBorderColor(touchgfx::Color::getColorFromRGB(0, 2, 5));
    boxWithBorderMain.setBorderSize(4);
    boxWithBorderMain.setAlpha(30);

    boxWithBorderHome.setPosition(9, 11, 783, 60);
    boxWithBorderHome.setColor(touchgfx::Color::getColorFromRGB(0, 145, 161));
    boxWithBorderHome.setBorderColor(touchgfx::Color::getColorFromRGB(0, 2, 5));
    boxWithBorderHome.setBorderSize(4);
    boxWithBorderHome.setAlpha(30);

    buttonToMenuF.setXY(726, 11);
    buttonToMenuF.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_BACK_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_BACK_NEW_ID));
    buttonToMenuF.setAction(buttonCallback);

    buttonConfig.setXY(630, 11);
    buttonConfig.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_SETTING_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_SETTING_NEW_ID));
    buttonConfig.setAction(buttonCallback);

    buttonReset.setXY(532, 11);
    buttonReset.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_RESET_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_RESET_NEW_ID));
    buttonReset.setAction(buttonCallback);

    textFreq1start.setPosition(99, 100, 68, 31);
    textFreq1start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textFreq1start.setLinespacing(0);
    textFreq1startBuffer[0] = 0;
    textFreq1start.setWildcard(textFreq1startBuffer);
    textFreq1start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID199));

    textFreq2start.setPosition(99, 147, 67, 31);
    textFreq2start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textFreq2start.setLinespacing(0);
    textFreq2startBuffer[0] = 0;
    textFreq2start.setWildcard(textFreq2startBuffer);
    textFreq2start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID200));

    textFreq3start.setPosition(99, 195, 68, 31);
    textFreq3start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textFreq3start.setLinespacing(0);
    textFreq3startBuffer[0] = 0;
    textFreq3start.setWildcard(textFreq3startBuffer);
    textFreq3start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID201));

    textFreq4start.setPosition(99, 243, 68, 32);
    textFreq4start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textFreq4start.setLinespacing(0);
    textFreq4startBuffer[0] = 0;
    textFreq4start.setWildcard(textFreq4startBuffer);
    textFreq4start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID202));

    textFreq5start.setPosition(100, 291, 68, 30);
    textFreq5start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textFreq5start.setLinespacing(0);
    textFreq5startBuffer[0] = 0;
    textFreq5start.setWildcard(textFreq5startBuffer);
    textFreq5start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID203));

    textFreq6start.setPosition(100, 340, 68, 31);
    textFreq6start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textFreq6start.setLinespacing(0);
    textFreq6startBuffer[0] = 0;
    textFreq6start.setWildcard(textFreq6startBuffer);
    textFreq6start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID204));

    textFreq7start.setPosition(98, 389, 68, 32);
    textFreq7start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textFreq7start.setLinespacing(0);
    textFreq7startBuffer[0] = 0;
    textFreq7start.setWildcard(textFreq7startBuffer);
    textFreq7start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID205));

    textLabelFreq1.setPosition(17, 100, 74, 31);
    textLabelFreq1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelFreq1.setLinespacing(0);
    textLabelFreq1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID206));

    textLabelFreq2.setPosition(17, 147, 74, 31);
    textLabelFreq2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelFreq2.setLinespacing(0);
    textLabelFreq2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID207));

    textLabelFreq3.setPosition(17, 195, 74, 31);
    textLabelFreq3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelFreq3.setLinespacing(0);
    textLabelFreq3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID208));

    textLabelFreq4.setPosition(17, 243, 74, 32);
    textLabelFreq4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelFreq4.setLinespacing(0);
    textLabelFreq4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID209));

    textLabelFreq5.setPosition(17, 290, 74, 31);
    textLabelFreq5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelFreq5.setLinespacing(0);
    textLabelFreq5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID210));

    textLabelFreq6.setPosition(17, 340, 74, 31);
    textLabelFreq6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelFreq6.setLinespacing(0);
    textLabelFreq6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID211));

    textLabelFreq7.setPosition(17, 389, 74, 32);
    textLabelFreq7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelFreq7.setLinespacing(0);
    textLabelFreq7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID212));

    textFreq8start.setPosition(98, 436, 68, 31);
    textFreq8start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textFreq8start.setLinespacing(0);
    textFreq8startBuffer[0] = 0;
    textFreq8start.setWildcard(textFreq8startBuffer);
    textFreq8start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID213));

    textLabeFreq8.setPosition(17, 436, 74, 31);
    textLabeFreq8.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabeFreq8.setLinespacing(0);
    textLabeFreq8.setTypedText(touchgfx::TypedText(T_SINGLEUSEID214));

    textSampleLabel.setXY(292, 75);
    textSampleLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSampleLabel.setLinespacing(0);
    textSampleLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID215));

    textMeanLabel.setXY(552, 71);
    textMeanLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanLabel.setLinespacing(0);
    textMeanLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID216));

    textStdDevLabel.setXY(675, 71);
    textStdDevLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevLabel.setLinespacing(0);
    textStdDevLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID217));

    textSample1.setPosition(292, 106, 63, 19);
    textSample1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample1.setLinespacing(0);
    textSample1Buffer[0] = 0;
    textSample1.setWildcard(textSample1Buffer);
    textSample1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID218));

    textSample2.setPosition(292, 153, 63, 19);
    textSample2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample2.setLinespacing(0);
    textSample2Buffer[0] = 0;
    textSample2.setWildcard(textSample2Buffer);
    textSample2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID219));

    textSample3.setPosition(292, 201, 63, 19);
    textSample3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample3.setLinespacing(0);
    textSample3Buffer[0] = 0;
    textSample3.setWildcard(textSample3Buffer);
    textSample3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID220));

    textSample4.setPosition(292, 250, 63, 19);
    textSample4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample4.setLinespacing(0);
    textSample4Buffer[0] = 0;
    textSample4.setWildcard(textSample4Buffer);
    textSample4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID221));

    textSample5.setPosition(292, 296, 63, 19);
    textSample5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample5.setLinespacing(0);
    textSample5Buffer[0] = 0;
    textSample5.setWildcard(textSample5Buffer);
    textSample5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID222));

    textSample6.setPosition(292, 345, 63, 20);
    textSample6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample6.setLinespacing(0);
    textSample6Buffer[0] = 0;
    textSample6.setWildcard(textSample6Buffer);
    textSample6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID223));

    textSample7.setPosition(292, 396, 63, 19);
    textSample7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample7.setLinespacing(0);
    textSample7Buffer[0] = 0;
    textSample7.setWildcard(textSample7Buffer);
    textSample7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID224));

    textSample8.setPosition(292, 442, 63, 19);
    textSample8.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample8.setLinespacing(0);
    textSample8Buffer[0] = 0;
    textSample8.setWildcard(textSample8Buffer);
    textSample8.setTypedText(touchgfx::TypedText(T_SINGLEUSEID225));

    textMeanVal1.setPosition(372, 103, 245, 25);
    textMeanVal1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal1.setLinespacing(0);
    textMeanVal1Buffer[0] = 0;
    textMeanVal1.setWildcard(textMeanVal1Buffer);
    textMeanVal1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID226));

    textMeanVal2.setPosition(372, 150, 245, 25);
    textMeanVal2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal2.setLinespacing(0);
    textMeanVal2Buffer[0] = 0;
    textMeanVal2.setWildcard(textMeanVal2Buffer);
    textMeanVal2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID227));

    textMeanVal3.setPosition(372, 198, 245, 25);
    textMeanVal3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal3.setLinespacing(0);
    textMeanVal3Buffer[0] = 0;
    textMeanVal3.setWildcard(textMeanVal3Buffer);
    textMeanVal3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID228));

    textMeanVal4.setPosition(372, 247, 245, 25);
    textMeanVal4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal4.setLinespacing(0);
    textMeanVal4Buffer[0] = 0;
    textMeanVal4.setWildcard(textMeanVal4Buffer);
    textMeanVal4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID229));

    textMeanVal5.setPosition(372, 294, 245, 25);
    textMeanVal5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal5.setLinespacing(0);
    textMeanVal5Buffer[0] = 0;
    textMeanVal5.setWildcard(textMeanVal5Buffer);
    textMeanVal5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID230));

    textMeanVal6.setPosition(372, 343, 245, 25);
    textMeanVal6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal6.setLinespacing(0);
    textMeanVal6Buffer[0] = 0;
    textMeanVal6.setWildcard(textMeanVal6Buffer);
    textMeanVal6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID231));

    textMeanVal7.setPosition(372, 393, 239, 25);
    textMeanVal7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal7.setLinespacing(0);
    textMeanVal7Buffer[0] = 0;
    textMeanVal7.setWildcard(textMeanVal7Buffer);
    textMeanVal7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID232));

    textMeanVal8.setPosition(372, 439, 239, 25);
    textMeanVal8.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal8.setLinespacing(0);
    textMeanVal8Buffer[0] = 0;
    textMeanVal8.setWildcard(textMeanVal8Buffer);
    textMeanVal8.setTypedText(touchgfx::TypedText(T_SINGLEUSEID233));

    textStdDevVal1.setPosition(683, 103, 64, 25);
    textStdDevVal1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal1.setLinespacing(0);
    textStdDevVal1Buffer[0] = 0;
    textStdDevVal1.setWildcard(textStdDevVal1Buffer);
    textStdDevVal1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID234));

    textStdDevVal2.setPosition(683, 150, 64, 25);
    textStdDevVal2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal2.setLinespacing(0);
    textStdDevVal2Buffer[0] = 0;
    textStdDevVal2.setWildcard(textStdDevVal2Buffer);
    textStdDevVal2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID235));

    textStdDevVal3.setPosition(683, 198, 64, 25);
    textStdDevVal3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal3.setLinespacing(0);
    textStdDevVal3Buffer[0] = 0;
    textStdDevVal3.setWildcard(textStdDevVal3Buffer);
    textStdDevVal3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID236));

    textStdDevVal4.setPosition(683, 247, 64, 25);
    textStdDevVal4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal4.setLinespacing(0);
    textStdDevVal4Buffer[0] = 0;
    textStdDevVal4.setWildcard(textStdDevVal4Buffer);
    textStdDevVal4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID237));

    textStdDevVal5.setPosition(683, 294, 64, 25);
    textStdDevVal5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal5.setLinespacing(0);
    textStdDevVal5Buffer[0] = 0;
    textStdDevVal5.setWildcard(textStdDevVal5Buffer);
    textStdDevVal5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID238));

    textStdDevVal6.setPosition(683, 343, 64, 25);
    textStdDevVal6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal6.setLinespacing(0);
    textStdDevVal6Buffer[0] = 0;
    textStdDevVal6.setWildcard(textStdDevVal6Buffer);
    textStdDevVal6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID239));

    textStdDevVal7.setPosition(683, 393, 64, 25);
    textStdDevVal7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal7.setLinespacing(0);
    textStdDevVal7Buffer[0] = 0;
    textStdDevVal7.setWildcard(textStdDevVal7Buffer);
    textStdDevVal7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID240));

    textStdDevVal8.setPosition(683, 439, 64, 25);
    textStdDevVal8.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal8.setLinespacing(0);
    textStdDevVal8Buffer[0] = 0;
    textStdDevVal8.setWildcard(textStdDevVal8Buffer);
    textStdDevVal8.setTypedText(touchgfx::TypedText(T_SINGLEUSEID241));

    textUnitSD1.setPosition(756, 106, 36, 19);
    textUnitSD1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitSD1.setLinespacing(0);
    textUnitSD1Buffer[0] = 0;
    textUnitSD1.setWildcard(textUnitSD1Buffer);
    textUnitSD1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID249));

    textUnitSD2.setPosition(756, 153, 36, 19);
    textUnitSD2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitSD2.setLinespacing(0);
    textUnitSD2Buffer[0] = 0;
    textUnitSD2.setWildcard(textUnitSD2Buffer);
    textUnitSD2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID250));

    textUnitSD3.setPosition(756, 201, 36, 19);
    textUnitSD3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitSD3.setLinespacing(0);
    textUnitSD3Buffer[0] = 0;
    textUnitSD3.setWildcard(textUnitSD3Buffer);
    textUnitSD3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID251));

    textUnitSD4.setPosition(756, 250, 36, 19);
    textUnitSD4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitSD4.setLinespacing(0);
    textUnitSD4Buffer[0] = 0;
    textUnitSD4.setWildcard(textUnitSD4Buffer);
    textUnitSD4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID252));

    textUnitSD5.setPosition(756, 297, 36, 19);
    textUnitSD5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitSD5.setLinespacing(0);
    textUnitSD5Buffer[0] = 0;
    textUnitSD5.setWildcard(textUnitSD5Buffer);
    textUnitSD5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID253));

    textUnitSD6.setPosition(756, 346, 36, 19);
    textUnitSD6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitSD6.setLinespacing(0);
    textUnitSD6Buffer[0] = 0;
    textUnitSD6.setWildcard(textUnitSD6Buffer);
    textUnitSD6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID254));

    textUnitSD7.setPosition(756, 396, 36, 19);
    textUnitSD7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitSD7.setLinespacing(0);
    textUnitSD7Buffer[0] = 0;
    textUnitSD7.setWildcard(textUnitSD7Buffer);
    textUnitSD7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID255));

    textUnitSD8.setPosition(756, 442, 36, 19);
    textUnitSD8.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitSD8.setLinespacing(0);
    textUnitSD8Buffer[0] = 0;
    textUnitSD8.setWildcard(textUnitSD8Buffer);
    textUnitSD8.setTypedText(touchgfx::TypedText(T_SINGLEUSEID256));

    textUnitMean1.setPosition(630, 106, 36, 19);
    textUnitMean1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitMean1.setLinespacing(0);
    textUnitMean1Buffer[0] = 0;
    textUnitMean1.setWildcard(textUnitMean1Buffer);
    textUnitMean1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID265));

    textUnitMean2.setPosition(630, 153, 36, 19);
    textUnitMean2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitMean2.setLinespacing(0);
    textUnitMean2Buffer[0] = 0;
    textUnitMean2.setWildcard(textUnitMean2Buffer);
    textUnitMean2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID266));

    textUnitMean3.setPosition(630, 201, 36, 19);
    textUnitMean3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitMean3.setLinespacing(0);
    textUnitMean3Buffer[0] = 0;
    textUnitMean3.setWildcard(textUnitMean3Buffer);
    textUnitMean3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID267));

    textUnitMean4.setPosition(630, 250, 36, 19);
    textUnitMean4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitMean4.setLinespacing(0);
    textUnitMean4Buffer[0] = 0;
    textUnitMean4.setWildcard(textUnitMean4Buffer);
    textUnitMean4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID268));

    textUnitMean5.setPosition(630, 297, 36, 19);
    textUnitMean5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitMean5.setLinespacing(0);
    textUnitMean5Buffer[0] = 0;
    textUnitMean5.setWildcard(textUnitMean5Buffer);
    textUnitMean5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID269));

    textUnitMean6.setPosition(630, 346, 36, 19);
    textUnitMean6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitMean6.setLinespacing(0);
    textUnitMean6Buffer[0] = 0;
    textUnitMean6.setWildcard(textUnitMean6Buffer);
    textUnitMean6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID270));

    textUnitMean7.setPosition(630, 396, 36, 19);
    textUnitMean7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitMean7.setLinespacing(0);
    textUnitMean7Buffer[0] = 0;
    textUnitMean7.setWildcard(textUnitMean7Buffer);
    textUnitMean7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID271));

    textUnitMean8.setPosition(630, 442, 36, 19);
    textUnitMean8.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textUnitMean8.setLinespacing(0);
    textUnitMean8Buffer[0] = 0;
    textUnitMean8.setWildcard(textUnitMean8Buffer);
    textUnitMean8.setTypedText(touchgfx::TypedText(T_SINGLEUSEID272));

    buttonHistogram.setXY(431, 11);
    buttonHistogram.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_GRAPH_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_GRAPH_NEW_ID));
    buttonHistogram.setAction(buttonCallback);

    labelFreqConfig.setXY(71, 29);
    labelFreqConfig.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelFreqConfig.setLinespacing(0);
    labelFreqConfig.setTypedText(touchgfx::TypedText(T_SINGLEUSEID316));

    imageHome.setXY(17, 17);
    imageHome.setBitmap(touchgfx::Bitmap(BITMAP_MY_HOME_NEW_ID));

    add(__background);
    add(boxBackgroungFreq);
    add(boxWithBorderMain);
    add(boxWithBorderHome);
    add(buttonToMenuF);
    add(buttonConfig);
    add(buttonReset);
    add(textFreq1start);
    add(textFreq2start);
    add(textFreq3start);
    add(textFreq4start);
    add(textFreq5start);
    add(textFreq6start);
    add(textFreq7start);
    add(textLabelFreq1);
    add(textLabelFreq2);
    add(textLabelFreq3);
    add(textLabelFreq4);
    add(textLabelFreq5);
    add(textLabelFreq6);
    add(textLabelFreq7);
    add(textFreq8start);
    add(textLabeFreq8);
    add(textSampleLabel);
    add(textMeanLabel);
    add(textStdDevLabel);
    add(textSample1);
    add(textSample2);
    add(textSample3);
    add(textSample4);
    add(textSample5);
    add(textSample6);
    add(textSample7);
    add(textSample8);
    add(textMeanVal1);
    add(textMeanVal2);
    add(textMeanVal3);
    add(textMeanVal4);
    add(textMeanVal5);
    add(textMeanVal6);
    add(textMeanVal7);
    add(textMeanVal8);
    add(textStdDevVal1);
    add(textStdDevVal2);
    add(textStdDevVal3);
    add(textStdDevVal4);
    add(textStdDevVal5);
    add(textStdDevVal6);
    add(textStdDevVal7);
    add(textStdDevVal8);
    add(textUnitSD1);
    add(textUnitSD2);
    add(textUnitSD3);
    add(textUnitSD4);
    add(textUnitSD5);
    add(textUnitSD6);
    add(textUnitSD7);
    add(textUnitSD8);
    add(textUnitMean1);
    add(textUnitMean2);
    add(textUnitMean3);
    add(textUnitMean4);
    add(textUnitMean5);
    add(textUnitMean6);
    add(textUnitMean7);
    add(textUnitMean8);
    add(buttonHistogram);
    add(labelFreqConfig);
    add(imageHome);
}

void FreqModeViewBase::setupScreen()
{

}

void FreqModeViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonToMenuF)
    {
        //BackToMenu
        //When buttonToMenuF clicked change screen to Menu
        //Go to Menu with screen transition towards West
        application().gotoMenuScreenCoverTransitionWest();
    }
    else if (&src == &buttonConfig)
    {
        //GoToConfigFreq
        //When buttonConfig clicked change screen to FreqModeConfig
        //Go to FreqModeConfig with screen transition towards West
        application().gotoFreqModeConfigScreenWipeTransitionWest();
    }
    else if (&src == &buttonReset)
    {
        //Reset
        //When buttonReset clicked call virtual function
        //Call ResetParameter
        ResetParameter();
    }
    else if (&src == &buttonHistogram)
    {
        //GoToHistogram
        //When buttonHistogram clicked change screen to FreqHistogram
        //Go to FreqHistogram with screen transition towards West
        application().gotoFreqHistogramScreenWipeTransitionWest();
    }
}
