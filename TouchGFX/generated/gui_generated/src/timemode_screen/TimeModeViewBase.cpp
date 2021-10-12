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
    boxBackgroundTime.setColor(touchgfx::Color::getColorFromRGB(56, 69, 120));

    buttonBackMenuT.setXY(740, 0);
    buttonBackMenuT.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    buttonBackMenuT.setAction(buttonCallback);

    buttonConfig.setXY(542, 0);
    buttonConfig.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonConfig.setAction(buttonCallback);

    buttonReset.setXY(337, 0);
    buttonReset.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));

    textTi1start.setPosition(11, 124, 114, 31);
    textTi1start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi1start.setLinespacing(0);
    textTi1startBuffer[0] = 0;
    textTi1start.setWildcard(textTi1startBuffer);
    textTi1start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID90));

    texTi1stop.setPosition(153, 124, 69, 31);
    texTi1stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    texTi1stop.setLinespacing(0);
    texTi1stopBuffer[0] = 0;
    texTi1stop.setWildcard(texTi1stopBuffer);
    texTi1stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID91));

    textTi2start.setPosition(11, 171, 114, 31);
    textTi2start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi2start.setLinespacing(0);
    textTi2startBuffer[0] = 0;
    textTi2start.setWildcard(textTi2startBuffer);
    textTi2start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID92));

    texTi2stop.setPosition(153, 171, 69, 31);
    texTi2stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    texTi2stop.setLinespacing(0);
    texTi2stopBuffer[0] = 0;
    texTi2stop.setWildcard(texTi2stopBuffer);
    texTi2stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID93));

    textTi3start.setPosition(11, 219, 114, 31);
    textTi3start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi3start.setLinespacing(0);
    textTi3startBuffer[0] = 0;
    textTi3start.setWildcard(textTi3startBuffer);
    textTi3start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID94));

    texTi3stop.setPosition(153, 219, 69, 31);
    texTi3stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    texTi3stop.setLinespacing(0);
    texTi3stopBuffer[0] = 0;
    texTi3stop.setWildcard(texTi3stopBuffer);
    texTi3stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID95));

    textTi4start.setPosition(11, 266, 114, 31);
    textTi4start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi4start.setLinespacing(0);
    textTi4startBuffer[0] = 0;
    textTi4start.setWildcard(textTi4startBuffer);
    textTi4start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID96));

    texTi4stop.setPosition(153, 266, 69, 31);
    texTi4stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    texTi4stop.setLinespacing(0);
    texTi4stopBuffer[0] = 0;
    texTi4stop.setWildcard(texTi4stopBuffer);
    texTi4stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID97));

    textTi5start.setPosition(11, 315, 114, 31);
    textTi5start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi5start.setLinespacing(0);
    textTi5startBuffer[0] = 0;
    textTi5start.setWildcard(textTi5startBuffer);
    textTi5start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID98));

    texTi5stop.setPosition(153, 315, 69, 31);
    texTi5stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    texTi5stop.setLinespacing(0);
    texTi5stopBuffer[0] = 0;
    texTi5stop.setWildcard(texTi5stopBuffer);
    texTi5stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID99));

    textTi6start.setPosition(11, 364, 114, 31);
    textTi6start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi6start.setLinespacing(0);
    textTi6startBuffer[0] = 0;
    textTi6start.setWildcard(textTi6startBuffer);
    textTi6start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID100));

    texTi6stop.setPosition(153, 364, 69, 31);
    texTi6stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    texTi6stop.setLinespacing(0);
    texTi6stopBuffer[0] = 0;
    texTi6stop.setWildcard(texTi6stopBuffer);
    texTi6stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID101));

    textTi7start.setPosition(11, 412, 114, 31);
    textTi7start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTi7start.setLinespacing(0);
    textTi7startBuffer[0] = 0;
    textTi7start.setWildcard(textTi7startBuffer);
    textTi7start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID102));

    texTi7stop.setPosition(153, 412, 69, 31);
    texTi7stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    texTi7stop.setLinespacing(0);
    texTi7stopBuffer[0] = 0;
    texTi7stop.setWildcard(texTi7stopBuffer);
    texTi7stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID103));

    textStamps1start.setPosition(234, 118, 77, 19);
    textStamps1start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps1start.setLinespacing(0);
    textStamps1startBuffer1[0] = 0;
    textStamps1start.setWildcard1(textStamps1startBuffer1);
    textStamps1start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID104));

    textStampsLabel.setXY(235, 96);
    textStampsLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStampsLabel.setLinespacing(0);
    textStampsLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID105));

    textSampleLabel.setXY(330, 96);
    textSampleLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textSampleLabel.setLinespacing(0);
    textSampleLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID106));

    textStamps1stop.setPosition(234, 137, 77, 16);
    textStamps1stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps1stop.setLinespacing(0);
    textStamps1stopBuffer1[0] = 0;
    textStamps1stop.setWildcard1(textStamps1stopBuffer1);
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

    textStamps2start.setPosition(234, 169, 77, 19);
    textStamps2start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps2start.setLinespacing(0);
    textStamps2startBuffer1[0] = 0;
    textStamps2start.setWildcard1(textStamps2startBuffer1);
    textStamps2start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID111));

    textStamps2stop.setPosition(234, 188, 77, 16);
    textStamps2stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps2stop.setLinespacing(0);
    textStamps2stopBuffer1[0] = 0;
    textStamps2stop.setWildcard1(textStamps2stopBuffer1);
    textStamps2stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID112));

    textStamps3start.setPosition(234, 215, 77, 19);
    textStamps3start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps3start.setLinespacing(0);
    textStamps3startBuffer1[0] = 0;
    textStamps3start.setWildcard1(textStamps3startBuffer1);
    textStamps3start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID113));

    textStamps3stop.setPosition(234, 234, 77, 16);
    textStamps3stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps3stop.setLinespacing(0);
    textStamps3stopBuffer1[0] = 0;
    textStamps3stop.setWildcard1(textStamps3stopBuffer1);
    textStamps3stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID114));

    textStamps4start.setPosition(234, 262, 77, 19);
    textStamps4start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps4start.setLinespacing(0);
    textStamps4startBuffer1[0] = 0;
    textStamps4start.setWildcard1(textStamps4startBuffer1);
    textStamps4start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID115));

    textStamps4stop.setPosition(234, 281, 77, 16);
    textStamps4stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps4stop.setLinespacing(0);
    textStamps4stopBuffer1[0] = 0;
    textStamps4stop.setWildcard1(textStamps4stopBuffer1);
    textStamps4stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID116));

    textStamps5start.setPosition(234, 311, 77, 19);
    textStamps5start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps5start.setLinespacing(0);
    textStamps5startBuffer1[0] = 0;
    textStamps5start.setWildcard1(textStamps5startBuffer1);
    textStamps5start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID117));

    textStamps5stop.setPosition(234, 330, 77, 16);
    textStamps5stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps5stop.setLinespacing(0);
    textStamps5stopBuffer1[0] = 0;
    textStamps5stop.setWildcard1(textStamps5stopBuffer1);
    textStamps5stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID118));

    textStamps6start.setPosition(234, 360, 77, 19);
    textStamps6start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps6start.setLinespacing(0);
    textStamps6startBuffer1[0] = 0;
    textStamps6start.setWildcard1(textStamps6startBuffer1);
    textStamps6start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID119));

    textStamps6stop.setPosition(234, 379, 77, 16);
    textStamps6stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps6stop.setLinespacing(0);
    textStamps6stopBuffer1[0] = 0;
    textStamps6stop.setWildcard1(textStamps6stopBuffer1);
    textStamps6stop.setTypedText(touchgfx::TypedText(T_SINGLEUSEID120));

    textStamps7start.setPosition(235, 408, 77, 19);
    textStamps7start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps7start.setLinespacing(0);
    textStamps7startBuffer1[0] = 0;
    textStamps7start.setWildcard1(textStamps7startBuffer1);
    textStamps7start.setTypedText(touchgfx::TypedText(T_SINGLEUSEID121));

    textStamps7stop.setPosition(234, 427, 77, 16);
    textStamps7stop.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStamps7stop.setLinespacing(0);
    textStamps7stopBuffer1[0] = 0;
    textStamps7stop.setWildcard1(textStamps7stopBuffer1);
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

    textStdDevVal1.setPosition(695, 124, 64, 25);
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

    textStdDevVal2.setPosition(695, 174, 64, 25);
    textStdDevVal2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal2.setLinespacing(0);
    textStdDevVal2Buffer[0] = 0;
    textStdDevVal2.setWildcard(textStdDevVal2Buffer);
    textStdDevVal2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID137));

    textStdDevVal3.setPosition(695, 222, 64, 25);
    textStdDevVal3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal3.setLinespacing(0);
    textStdDevVal3Buffer[0] = 0;
    textStdDevVal3.setWildcard(textStdDevVal3Buffer);
    textStdDevVal3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID138));

    textStdDevVal4.setPosition(695, 269, 64, 25);
    textStdDevVal4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal4.setLinespacing(0);
    textStdDevVal4Buffer[0] = 0;
    textStdDevVal4.setWildcard(textStdDevVal4Buffer);
    textStdDevVal4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID139));

    textStdDevVal5.setPosition(695, 321, 64, 25);
    textStdDevVal5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal5.setLinespacing(0);
    textStdDevVal5Buffer[0] = 0;
    textStdDevVal5.setWildcard(textStdDevVal5Buffer);
    textStdDevVal5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID140));

    textStdDevVal6.setPosition(695, 364, 64, 25);
    textStdDevVal6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal6.setLinespacing(0);
    textStdDevVal6Buffer[0] = 0;
    textStdDevVal6.setWildcard(textStdDevVal6Buffer);
    textStdDevVal6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID141));

    textStdDevVal7.setPosition(695, 412, 64, 25);
    textStdDevVal7.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStdDevVal7.setLinespacing(0);
    textStdDevVal7Buffer[0] = 0;
    textStdDevVal7.setWildcard(textStdDevVal7Buffer);
    textStdDevVal7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID142));

    add(__background);
    add(boxBackgroundTime);
    add(buttonBackMenuT);
    add(buttonConfig);
    add(buttonReset);
    add(textTi1start);
    add(texTi1stop);
    add(textTi2start);
    add(texTi2stop);
    add(textTi3start);
    add(texTi3stop);
    add(textTi4start);
    add(texTi4stop);
    add(textTi5start);
    add(texTi5stop);
    add(textTi6start);
    add(texTi6stop);
    add(textTi7start);
    add(texTi7stop);
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
        //Go to Menu with screen transition towards East
        application().gotoMenuScreenSlideTransitionEast();
    }
    else if (&src == &buttonConfig)
    {
        //GoToConfigTime
        //When buttonConfig clicked change screen to TimeModeConfig
        //Go to TimeModeConfig with no screen transition
        application().gotoTimeModeConfigScreenNoTransition();
    }
}
