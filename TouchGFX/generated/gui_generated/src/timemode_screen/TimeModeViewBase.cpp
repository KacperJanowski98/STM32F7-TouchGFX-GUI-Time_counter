/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/timemode_screen/TimeModeViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

TimeModeViewBase::TimeModeViewBase() :
    buttonCallback(this, &TimeModeViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxBackgroundTime.setPosition(0, 0, 800, 480);
    boxBackgroundTime.setColor(touchgfx::Color::getColorFromRGB(67, 88, 112));

    boxWithBorderMain.setPosition(9, 80, 783, 384);
    boxWithBorderMain.setColor(touchgfx::Color::getColorFromRGB(20, 6, 69));
    boxWithBorderMain.setBorderColor(touchgfx::Color::getColorFromRGB(0, 2, 5));
    boxWithBorderMain.setBorderSize(4);
    boxWithBorderMain.setAlpha(30);

    boxWithBorderHome.setPosition(9, 14, 783, 60);
    boxWithBorderHome.setColor(touchgfx::Color::getColorFromRGB(0, 145, 161));
    boxWithBorderHome.setBorderColor(touchgfx::Color::getColorFromRGB(0, 2, 5));
    boxWithBorderHome.setBorderSize(4);
    boxWithBorderHome.setAlpha(30);

    buttonBackMenuT.setXY(723, 14);
    buttonBackMenuT.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_BACK_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_BACK_NEW_ID));
    buttonBackMenuT.setAction(buttonCallback);

    buttonConfig.setXY(629, 14);
    buttonConfig.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_SETTING_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_SETTING_NEW_ID));
    buttonConfig.setAction(buttonCallback);

    buttonReset.setXY(531, 14);
    buttonReset.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_RESET_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_RESET_NEW_ID));
    buttonReset.setAction(buttonCallback);

    textTi1start.setPosition(67, 124, 58, 31);
    textTi1start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi1start.setLinespacing(0);
    textTi1startBuffer[0] = 0;
    textTi1start.setWildcard(textTi1startBuffer);
    textTi1start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID90));

    textTi1stop.setPosition(159, 124, 69, 31);
    textTi1stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi1stop.setLinespacing(0);
    textTi1stopBuffer[0] = 0;
    textTi1stop.setWildcard(textTi1stopBuffer);
    textTi1stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID91));

    textTi2start.setPosition(68, 171, 57, 31);
    textTi2start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi2start.setLinespacing(0);
    textTi2startBuffer[0] = 0;
    textTi2start.setWildcard(textTi2startBuffer);
    textTi2start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID92));

    textTi2stop.setPosition(159, 171, 69, 31);
    textTi2stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi2stop.setLinespacing(0);
    textTi2stopBuffer[0] = 0;
    textTi2stop.setWildcard(textTi2stopBuffer);
    textTi2stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID93));

    textTi3start.setPosition(67, 219, 58, 31);
    textTi3start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi3start.setLinespacing(0);
    textTi3startBuffer[0] = 0;
    textTi3start.setWildcard(textTi3startBuffer);
    textTi3start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID94));

    textTi3stop.setPosition(159, 219, 69, 31);
    textTi3stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi3stop.setLinespacing(0);
    textTi3stopBuffer[0] = 0;
    textTi3stop.setWildcard(textTi3stopBuffer);
    textTi3stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID95));

    textTi4start.setPosition(67, 266, 58, 31);
    textTi4start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi4start.setLinespacing(0);
    textTi4startBuffer[0] = 0;
    textTi4start.setWildcard(textTi4startBuffer);
    textTi4start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID96));

    textTi4stop.setPosition(159, 266, 69, 31);
    textTi4stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi4stop.setLinespacing(0);
    textTi4stopBuffer[0] = 0;
    textTi4stop.setWildcard(textTi4stopBuffer);
    textTi4stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID97));

    textTi5start.setPosition(67, 315, 58, 31);
    textTi5start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi5start.setLinespacing(0);
    textTi5startBuffer[0] = 0;
    textTi5start.setWildcard(textTi5startBuffer);
    textTi5start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID98));

    textTi5stop.setPosition(159, 315, 69, 31);
    textTi5stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi5stop.setLinespacing(0);
    textTi5stopBuffer[0] = 0;
    textTi5stop.setWildcard(textTi5stopBuffer);
    textTi5stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID99));

    textTi6start.setPosition(67, 364, 58, 31);
    textTi6start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi6start.setLinespacing(0);
    textTi6startBuffer[0] = 0;
    textTi6start.setWildcard(textTi6startBuffer);
    textTi6start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID100));

    textTi6stop.setPosition(159, 364, 69, 31);
    textTi6stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi6stop.setLinespacing(0);
    textTi6stopBuffer[0] = 0;
    textTi6stop.setWildcard(textTi6stopBuffer);
    textTi6stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID101));

    textTi7start.setPosition(67, 412, 58, 31);
    textTi7start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi7start.setLinespacing(0);
    textTi7startBuffer[0] = 0;
    textTi7start.setWildcard(textTi7startBuffer);
    textTi7start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID102));

    textTi7stop.setPosition(159, 412, 69, 31);
    textTi7stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi7stop.setLinespacing(0);
    textTi7stopBuffer[0] = 0;
    textTi7stop.setWildcard(textTi7stopBuffer);
    textTi7stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID103));

    textStamps1start.setPosition(234, 118, 35, 18);
    textStamps1start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps1start.setLinespacing(0);
    textStamps1startBuffer[0] = 0;
    textStamps1start.setWildcard(textStamps1startBuffer);
    textStamps1start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID104));

    textStampsLabel.setXY(235, 96);
    textStampsLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStampsLabel.setLinespacing(0);
    textStampsLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID105));

    textSampleLabel.setXY(330, 96);
    textSampleLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSampleLabel.setLinespacing(0);
    textSampleLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID106));

    textStamps1stop.setPosition(234, 137, 35, 18);
    textStamps1stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps1stop.setLinespacing(0);
    textStamps1stopBuffer[0] = 0;
    textStamps1stop.setWildcard(textStamps1stopBuffer);
    textStamps1stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID107));

    textSample1.setPosition(330, 130, 63, 19);
    textSample1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample1.setLinespacing(0);
    textSample1Buffer[0] = 0;
    textSample1.setWildcard(textSample1Buffer);
    textSample1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID108));

    textMeanLabel.setXY(561, 86);
    textMeanLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanLabel.setLinespacing(0);
    textMeanLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID109));

    textStdDevLabel.setXY(695, 86);
    textStdDevLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevLabel.setLinespacing(0);
    textStdDevLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID110));

    textStamps2start.setPosition(234, 169, 35, 19);
    textStamps2start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps2start.setLinespacing(0);
    textStamps2startBuffer[0] = 0;
    textStamps2start.setWildcard(textStamps2startBuffer);
    textStamps2start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID111));

    textStamps2stop.setPosition(234, 188, 35, 16);
    textStamps2stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps2stop.setLinespacing(0);
    textStamps2stopBuffer[0] = 0;
    textStamps2stop.setWildcard(textStamps2stopBuffer);
    textStamps2stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID112));

    textStamps3start.setPosition(234, 215, 35, 19);
    textStamps3start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps3start.setLinespacing(0);
    textStamps3startBuffer[0] = 0;
    textStamps3start.setWildcard(textStamps3startBuffer);
    textStamps3start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID113));

    textStamps3stop.setPosition(234, 234, 35, 16);
    textStamps3stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps3stop.setLinespacing(0);
    textStamps3stopBuffer[0] = 0;
    textStamps3stop.setWildcard(textStamps3stopBuffer);
    textStamps3stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID114));

    textStamps4start.setPosition(234, 262, 35, 19);
    textStamps4start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps4start.setLinespacing(0);
    textStamps4startBuffer[0] = 0;
    textStamps4start.setWildcard(textStamps4startBuffer);
    textStamps4start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID115));

    textStamps4stop.setPosition(234, 281, 35, 16);
    textStamps4stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps4stop.setLinespacing(0);
    textStamps4stopBuffer[0] = 0;
    textStamps4stop.setWildcard(textStamps4stopBuffer);
    textStamps4stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID116));

    textStamps5start.setPosition(234, 311, 35, 19);
    textStamps5start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps5start.setLinespacing(0);
    textStamps5startBuffer[0] = 0;
    textStamps5start.setWildcard(textStamps5startBuffer);
    textStamps5start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID117));

    textStamps5stop.setPosition(234, 330, 35, 16);
    textStamps5stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps5stop.setLinespacing(0);
    textStamps5stopBuffer[0] = 0;
    textStamps5stop.setWildcard(textStamps5stopBuffer);
    textStamps5stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID118));

    textStamps6start.setPosition(234, 360, 35, 19);
    textStamps6start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps6start.setLinespacing(0);
    textStamps6startBuffer[0] = 0;
    textStamps6start.setWildcard(textStamps6startBuffer);
    textStamps6start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID119));

    textStamps6stop.setPosition(234, 379, 35, 16);
    textStamps6stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps6stop.setLinespacing(0);
    textStamps6stopBuffer[0] = 0;
    textStamps6stop.setWildcard(textStamps6stopBuffer);
    textStamps6stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID120));

    textStamps7start.setPosition(235, 408, 34, 19);
    textStamps7start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps7start.setLinespacing(0);
    textStamps7startBuffer[0] = 0;
    textStamps7start.setWildcard(textStamps7startBuffer);
    textStamps7start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID121));

    textStamps7stop.setPosition(234, 427, 35, 16);
    textStamps7stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps7stop.setLinespacing(0);
    textStamps7stopBuffer[0] = 0;
    textStamps7stop.setWildcard(textStamps7stopBuffer);
    textStamps7stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID122));

    textSample2.setPosition(330, 179, 63, 19);
    textSample2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample2.setLinespacing(0);
    textSample2Buffer[0] = 0;
    textSample2.setWildcard(textSample2Buffer);
    textSample2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID123));

    textSample3.setPosition(330, 225, 63, 19);
    textSample3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample3.setLinespacing(0);
    textSample3Buffer[0] = 0;
    textSample3.setWildcard(textSample3Buffer);
    textSample3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID124));

    textSample4.setPosition(330, 272, 63, 19);
    textSample4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample4.setLinespacing(0);
    textSample4Buffer[0] = 0;
    textSample4.setWildcard(textSample4Buffer);
    textSample4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID125));

    textSample5.setPosition(330, 321, 63, 19);
    textSample5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample5.setLinespacing(0);
    textSample5Buffer[0] = 0;
    textSample5.setWildcard(textSample5Buffer);
    textSample5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID126));

    textSample6.setPosition(330, 369, 63, 20);
    textSample6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample6.setLinespacing(0);
    textSample6Buffer[0] = 0;
    textSample6.setWildcard(textSample6Buffer);
    textSample6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID127));

    textSample7.setPosition(330, 418, 63, 19);
    textSample7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSample7.setLinespacing(0);
    textSample7Buffer[0] = 0;
    textSample7.setWildcard(textSample7Buffer);
    textSample7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID128));

    textMeanVal1.setPosition(411, 124, 227, 25);
    textMeanVal1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal1.setLinespacing(0);
    textMeanVal1Buffer[0] = 0;
    textMeanVal1.setWildcard(textMeanVal1Buffer);
    textMeanVal1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID129));

    textStdDevVal1.setPosition(689, 124, 64, 25);
    textStdDevVal1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal1.setLinespacing(0);
    textStdDevVal1Buffer[0] = 0;
    textStdDevVal1.setWildcard(textStdDevVal1Buffer);
    textStdDevVal1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID130));

    textMeanVal2.setPosition(411, 174, 227, 25);
    textMeanVal2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal2.setLinespacing(0);
    textMeanVal2Buffer[0] = 0;
    textMeanVal2.setWildcard(textMeanVal2Buffer);
    textMeanVal2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID131));

    textMeanVal3.setPosition(411, 222, 227, 25);
    textMeanVal3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal3.setLinespacing(0);
    textMeanVal3Buffer[0] = 0;
    textMeanVal3.setWildcard(textMeanVal3Buffer);
    textMeanVal3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID132));

    textMeanVal4.setPosition(411, 269, 227, 25);
    textMeanVal4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal4.setLinespacing(0);
    textMeanVal4Buffer[0] = 0;
    textMeanVal4.setWildcard(textMeanVal4Buffer);
    textMeanVal4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID133));

    textMeanVal5.setPosition(411, 321, 227, 25);
    textMeanVal5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal5.setLinespacing(0);
    textMeanVal5Buffer[0] = 0;
    textMeanVal5.setWildcard(textMeanVal5Buffer);
    textMeanVal5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID134));

    textMeanVal6.setPosition(411, 364, 227, 25);
    textMeanVal6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal6.setLinespacing(0);
    textMeanVal6Buffer[0] = 0;
    textMeanVal6.setWildcard(textMeanVal6Buffer);
    textMeanVal6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID135));

    textMeanVal7.setPosition(411, 412, 227, 25);
    textMeanVal7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textMeanVal7.setLinespacing(0);
    textMeanVal7Buffer[0] = 0;
    textMeanVal7.setWildcard(textMeanVal7Buffer);
    textMeanVal7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID136));

    textStdDevVal2.setPosition(689, 171, 64, 25);
    textStdDevVal2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal2.setLinespacing(0);
    textStdDevVal2Buffer[0] = 0;
    textStdDevVal2.setWildcard(textStdDevVal2Buffer);
    textStdDevVal2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID137));

    textStdDevVal3.setPosition(689, 222, 64, 25);
    textStdDevVal3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal3.setLinespacing(0);
    textStdDevVal3Buffer[0] = 0;
    textStdDevVal3.setWildcard(textStdDevVal3Buffer);
    textStdDevVal3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID138));

    textStdDevVal4.setPosition(689, 269, 64, 25);
    textStdDevVal4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal4.setLinespacing(0);
    textStdDevVal4Buffer[0] = 0;
    textStdDevVal4.setWildcard(textStdDevVal4Buffer);
    textStdDevVal4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID139));

    textStdDevVal5.setPosition(689, 321, 64, 25);
    textStdDevVal5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal5.setLinespacing(0);
    textStdDevVal5Buffer[0] = 0;
    textStdDevVal5.setWildcard(textStdDevVal5Buffer);
    textStdDevVal5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID140));

    textStdDevVal6.setPosition(689, 364, 64, 25);
    textStdDevVal6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal6.setLinespacing(0);
    textStdDevVal6Buffer[0] = 0;
    textStdDevVal6.setWildcard(textStdDevVal6Buffer);
    textStdDevVal6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID141));

    textStdDevVal7.setPosition(689, 412, 64, 25);
    textStdDevVal7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal7.setLinespacing(0);
    textStdDevVal7Buffer[0] = 0;
    textStdDevVal7.setWildcard(textStdDevVal7Buffer);
    textStdDevVal7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID142));

    textStamps1startVal.setPosition(269, 118, 45, 18);
    textStamps1startVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps1startVal.setLinespacing(0);
    textStamps1startValBuffer[0] = 0;
    textStamps1startVal.setWildcard(textStamps1startValBuffer);
    textStamps1startVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID143));

    textStamps1stopVal.setPosition(269, 137, 45, 18);
    textStamps1stopVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps1stopVal.setLinespacing(0);
    textStamps1stopValBuffer[0] = 0;
    textStamps1stopVal.setWildcard(textStamps1stopValBuffer);
    textStamps1stopVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID144));

    textStamps2startVal.setPosition(269, 168, 45, 18);
    textStamps2startVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps2startVal.setLinespacing(0);
    textStamps2startValBuffer[0] = 0;
    textStamps2startVal.setWildcard(textStamps2startValBuffer);
    textStamps2startVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID145));

    textStamps2stopVal.setPosition(269, 187, 45, 18);
    textStamps2stopVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps2stopVal.setLinespacing(0);
    textStamps2stopValBuffer[0] = 0;
    textStamps2stopVal.setWildcard(textStamps2stopValBuffer);
    textStamps2stopVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID146));

    textStamps3startVal.setPosition(269, 216, 45, 18);
    textStamps3startVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps3startVal.setLinespacing(0);
    textStamps3startValBuffer[0] = 0;
    textStamps3startVal.setWildcard(textStamps3startValBuffer);
    textStamps3startVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID147));

    textStamps3stopVal.setPosition(269, 235, 45, 18);
    textStamps3stopVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps3stopVal.setLinespacing(0);
    textStamps3stopValBuffer[0] = 0;
    textStamps3stopVal.setWildcard(textStamps3stopValBuffer);
    textStamps3stopVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID148));

    textStamps4startVal.setPosition(269, 263, 45, 18);
    textStamps4startVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps4startVal.setLinespacing(0);
    textStamps4startValBuffer[0] = 0;
    textStamps4startVal.setWildcard(textStamps4startValBuffer);
    textStamps4startVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID149));

    textStamps4stopVal.setPosition(269, 282, 45, 18);
    textStamps4stopVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps4stopVal.setLinespacing(0);
    textStamps4stopValBuffer[0] = 0;
    textStamps4stopVal.setWildcard(textStamps4stopValBuffer);
    textStamps4stopVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID150));

    textStamps5startVal.setPosition(269, 311, 45, 18);
    textStamps5startVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps5startVal.setLinespacing(0);
    textStamps5startValBuffer[0] = 0;
    textStamps5startVal.setWildcard(textStamps5startValBuffer);
    textStamps5startVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID151));

    textStamps5stopVal.setPosition(269, 330, 45, 18);
    textStamps5stopVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps5stopVal.setLinespacing(0);
    textStamps5stopValBuffer[0] = 0;
    textStamps5stopVal.setWildcard(textStamps5stopValBuffer);
    textStamps5stopVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID152));

    textStamps6startVal.setPosition(269, 360, 45, 18);
    textStamps6startVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps6startVal.setLinespacing(0);
    textStamps6startValBuffer[0] = 0;
    textStamps6startVal.setWildcard(textStamps6startValBuffer);
    textStamps6startVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID153));

    textStamps6stopVal.setPosition(269, 379, 45, 18);
    textStamps6stopVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps6stopVal.setLinespacing(0);
    textStamps6stopValBuffer[0] = 0;
    textStamps6stopVal.setWildcard(textStamps6stopValBuffer);
    textStamps6stopVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID154));

    textStamps7startVal.setPosition(269, 408, 45, 18);
    textStamps7startVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps7startVal.setLinespacing(0);
    textStamps7startValBuffer[0] = 0;
    textStamps7startVal.setWildcard(textStamps7startValBuffer);
    textStamps7startVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID155));

    textStamps7stopVal.setPosition(269, 428, 45, 18);
    textStamps7stopVal.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps7stopVal.setLinespacing(0);
    textStamps7stopValBuffer[0] = 0;
    textStamps7stopVal.setWildcard(textStamps7stopValBuffer);
    textStamps7stopVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID156));

    textUnitSD1.setPosition(762, 127, 30, 19);
    textUnitSD1.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitSD1.setLinespacing(0);
    textUnitSD1Buffer[0] = 0;
    textUnitSD1.setWildcard(textUnitSD1Buffer);
    textUnitSD1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID157));

    textUnitSD2.setPosition(762, 174, 30, 22);
    textUnitSD2.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitSD2.setLinespacing(0);
    textUnitSD2Buffer[0] = 0;
    textUnitSD2.setWildcard(textUnitSD2Buffer);
    textUnitSD2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID158));

    textUnitSD3.setPosition(762, 226, 30, 21);
    textUnitSD3.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitSD3.setLinespacing(0);
    textUnitSD3Buffer[0] = 0;
    textUnitSD3.setWildcard(textUnitSD3Buffer);
    textUnitSD3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID159));

    textUnitSD4.setPosition(762, 272, 30, 22);
    textUnitSD4.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitSD4.setLinespacing(0);
    textUnitSD4Buffer[0] = 0;
    textUnitSD4.setWildcard(textUnitSD4Buffer);
    textUnitSD4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID160));

    textUnitSD5.setPosition(762, 324, 30, 21);
    textUnitSD5.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitSD5.setLinespacing(0);
    textUnitSD5Buffer[0] = 0;
    textUnitSD5.setWildcard(textUnitSD5Buffer);
    textUnitSD5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID161));

    textUnitSD6.setPosition(762, 367, 30, 20);
    textUnitSD6.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitSD6.setLinespacing(0);
    textUnitSD6Buffer[0] = 0;
    textUnitSD6.setWildcard(textUnitSD6Buffer);
    textUnitSD6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID162));

    textUnitSD7.setPosition(762, 417, 30, 20);
    textUnitSD7.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitSD7.setLinespacing(0);
    textUnitSD7Buffer[0] = 0;
    textUnitSD7.setWildcard(textUnitSD7Buffer);
    textUnitSD7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID163));

    textUnitMean1.setPosition(638, 125, 32, 25);
    textUnitMean1.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitMean1.setLinespacing(0);
    textUnitMean1Buffer[0] = 0;
    textUnitMean1.setWildcard(textUnitMean1Buffer);
    textUnitMean1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID164));

    textUnitMean2.setPosition(638, 175, 32, 25);
    textUnitMean2.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitMean2.setLinespacing(0);
    textUnitMean2Buffer[0] = 0;
    textUnitMean2.setWildcard(textUnitMean2Buffer);
    textUnitMean2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID165));

    textUnitMean3.setPosition(638, 222, 32, 25);
    textUnitMean3.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitMean3.setLinespacing(0);
    textUnitMean3Buffer[0] = 0;
    textUnitMean3.setWildcard(textUnitMean3Buffer);
    textUnitMean3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID166));

    textUnitMean4.setPosition(638, 269, 32, 25);
    textUnitMean4.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitMean4.setLinespacing(0);
    textUnitMean4Buffer[0] = 0;
    textUnitMean4.setWildcard(textUnitMean4Buffer);
    textUnitMean4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID167));

    textUnitMean5.setPosition(638, 320, 32, 25);
    textUnitMean5.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitMean5.setLinespacing(0);
    textUnitMean5Buffer[0] = 0;
    textUnitMean5.setWildcard(textUnitMean5Buffer);
    textUnitMean5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID168));

    textUnitMean6.setPosition(638, 364, 32, 25);
    textUnitMean6.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitMean6.setLinespacing(0);
    textUnitMean6Buffer[0] = 0;
    textUnitMean6.setWildcard(textUnitMean6Buffer);
    textUnitMean6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID169));

    textUnitMean7.setPosition(638, 412, 32, 25);
    textUnitMean7.setColor(touchgfx::Color::getColorFromRGB(29, 222, 203));
    textUnitMean7.setLinespacing(0);
    textUnitMean7Buffer[0] = 0;
    textUnitMean7.setWildcard(textUnitMean7Buffer);
    textUnitMean7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID170));

    textLabelTi1.setPosition(18, 124, 49, 31);
    textLabelTi1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelTi1.setLinespacing(0);
    textLabelTi1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID192));

    textLabelTi2.setPosition(18, 171, 49, 31);
    textLabelTi2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelTi2.setLinespacing(0);
    textLabelTi2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID193));

    textLabelTi3.setPosition(19, 219, 49, 31);
    textLabelTi3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelTi3.setLinespacing(0);
    textLabelTi3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID194));

    textLabelTi4.setPosition(18, 267, 49, 31);
    textLabelTi4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelTi4.setLinespacing(0);
    textLabelTi4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID195));

    textLabelTi5.setPosition(18, 314, 49, 31);
    textLabelTi5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelTi5.setLinespacing(0);
    textLabelTi5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID196));

    textLabelTi6.setPosition(18, 364, 49, 31);
    textLabelTi6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelTi6.setLinespacing(0);
    textLabelTi6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID197));

    textLabelTi7.setPosition(18, 413, 49, 31);
    textLabelTi7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textLabelTi7.setLinespacing(0);
    textLabelTi7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID198));

    buttonHistogram.setXY(428, 14);
    buttonHistogram.setBitmaps(touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_GRAPH_PRESSED_NEW_ID), touchgfx::Bitmap(BITMAP_MY_BLUE_BUTTONS_GRAPH_NEW_ID));
    buttonHistogram.setAction(buttonCallback);

    labelTimeConfig.setPosition(79, 20, 332, 48);
    labelTimeConfig.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    labelTimeConfig.setLinespacing(0);
    labelTimeConfig.setTypedText(touchgfx::TypedText(T_SINGLEUSEID315));

    imageHome.setXY(18, 20);
    imageHome.setBitmap(touchgfx::Bitmap(BITMAP_MY_HOME_NEW_ID));

    imageArrowTi1.setXY(125, 129);
    imageArrowTi1.setBitmap(touchgfx::Bitmap(BITMAP_ARROWTI_20_ID));

    imageArrowTi2.setXY(125, 176);
    imageArrowTi2.setBitmap(touchgfx::Bitmap(BITMAP_ARROWTI_20_ID));

    imageArrowTi3.setXY(125, 224);
    imageArrowTi3.setBitmap(touchgfx::Bitmap(BITMAP_ARROWTI_20_ID));

    imageArrowTi4.setXY(125, 271);
    imageArrowTi4.setBitmap(touchgfx::Bitmap(BITMAP_ARROWTI_20_ID));

    imageArrowTi5.setXY(125, 320);
    imageArrowTi5.setBitmap(touchgfx::Bitmap(BITMAP_ARROWTI_20_ID));

    imageArrowTi6.setXY(125, 369);
    imageArrowTi6.setBitmap(touchgfx::Bitmap(BITMAP_ARROWTI_20_ID));

    imageArrowTi7.setXY(125, 417);
    imageArrowTi7.setBitmap(touchgfx::Bitmap(BITMAP_ARROWTI_20_ID));

    add(__background);
    add(boxBackgroundTime);
    add(boxWithBorderMain);
    add(boxWithBorderHome);
    add(buttonBackMenuT);
    add(buttonConfig);
    add(buttonReset);
    add(textTi1start);
    add(textTi1stop);
    add(textTi2start);
    add(textTi2stop);
    add(textTi3start);
    add(textTi3stop);
    add(textTi4start);
    add(textTi4stop);
    add(textTi5start);
    add(textTi5stop);
    add(textTi6start);
    add(textTi6stop);
    add(textTi7start);
    add(textTi7stop);
    add(textStamps1start);
    add(textStampsLabel);
    add(textSampleLabel);
    add(textStamps1stop);
    add(textSample1);
    add(textMeanLabel);
    add(textStdDevLabel);
    add(textStamps2start);
    add(textStamps2stop);
    add(textStamps3start);
    add(textStamps3stop);
    add(textStamps4start);
    add(textStamps4stop);
    add(textStamps5start);
    add(textStamps5stop);
    add(textStamps6start);
    add(textStamps6stop);
    add(textStamps7start);
    add(textStamps7stop);
    add(textSample2);
    add(textSample3);
    add(textSample4);
    add(textSample5);
    add(textSample6);
    add(textSample7);
    add(textMeanVal1);
    add(textStdDevVal1);
    add(textMeanVal2);
    add(textMeanVal3);
    add(textMeanVal4);
    add(textMeanVal5);
    add(textMeanVal6);
    add(textMeanVal7);
    add(textStdDevVal2);
    add(textStdDevVal3);
    add(textStdDevVal4);
    add(textStdDevVal5);
    add(textStdDevVal6);
    add(textStdDevVal7);
    add(textStamps1startVal);
    add(textStamps1stopVal);
    add(textStamps2startVal);
    add(textStamps2stopVal);
    add(textStamps3startVal);
    add(textStamps3stopVal);
    add(textStamps4startVal);
    add(textStamps4stopVal);
    add(textStamps5startVal);
    add(textStamps5stopVal);
    add(textStamps6startVal);
    add(textStamps6stopVal);
    add(textStamps7startVal);
    add(textStamps7stopVal);
    add(textUnitSD1);
    add(textUnitSD2);
    add(textUnitSD3);
    add(textUnitSD4);
    add(textUnitSD5);
    add(textUnitSD6);
    add(textUnitSD7);
    add(textUnitMean1);
    add(textUnitMean2);
    add(textUnitMean3);
    add(textUnitMean4);
    add(textUnitMean5);
    add(textUnitMean6);
    add(textUnitMean7);
    add(textLabelTi1);
    add(textLabelTi2);
    add(textLabelTi3);
    add(textLabelTi4);
    add(textLabelTi5);
    add(textLabelTi6);
    add(textLabelTi7);
    add(buttonHistogram);
    add(labelTimeConfig);
    add(imageHome);
    add(imageArrowTi1);
    add(imageArrowTi2);
    add(imageArrowTi3);
    add(imageArrowTi4);
    add(imageArrowTi5);
    add(imageArrowTi6);
    add(imageArrowTi7);
}

void TimeModeViewBase::setupScreen()
{

}

void TimeModeViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonBackMenuT)
    {
        //BackToMenu
        //When buttonBackMenuT clicked change screen to Menu
        //Go to Menu with screen transition towards West
        application().gotoMenuScreenCoverTransitionWest();
    }
    else if (&src == &buttonConfig)
    {
        //GoToConfigTime
        //When buttonConfig clicked change screen to TimeModeConfig
        //Go to TimeModeConfig with screen transition towards West
        application().gotoTimeModeConfigScreenWipeTransitionWest();
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
        //When buttonHistogram clicked change screen to TimeHistogram
        //Go to TimeHistogram with screen transition towards West
        application().gotoTimeHistogramScreenWipeTransitionWest();
    }
}
