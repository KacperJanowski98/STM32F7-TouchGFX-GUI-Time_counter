/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId LARGE = 1;
    static const touchgfx::FontId SMALL = 2;
    static const touchgfx::FontId SCROLLWHEEL = 3;
    static const touchgfx::FontId SCROLLWHEELCENTER = 4;
    static const touchgfx::FontId DISPLAYMEAS = 5;
    static const touchgfx::FontId DISPLAYLABEL = 6;
    static const touchgfx::FontId DISPLAYLABELBOLD = 7;
    static const touchgfx::FontId DISPLAYMEASVALUE = 8;
    static const touchgfx::FontId TITLE = 9;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0;           // verdana_20_4bpp
    static const touchgfx::FontId LARGE = 1;             // verdana_40_4bpp
    static const touchgfx::FontId SMALL = 2;             // verdana_10_4bpp
    static const touchgfx::FontId SCROLLWHEEL = 3;       // Roboto_Bold_25_4bpp
    static const touchgfx::FontId SCROLLWHEELCENTER = 4; // Roboto_Bold_35_4bpp
    static const touchgfx::FontId DISPLAYMEAS = 5;       // verdana_22_4bpp
    static const touchgfx::FontId DISPLAYLABEL = 6;      // verdana_15_4bpp
    static const touchgfx::FontId DISPLAYLABELBOLD = 7;  // verdanab_15_4bpp
    static const touchgfx::FontId DISPLAYMEASVALUE = 8;  // verdanab_18_4bpp
    static const touchgfx::FontId TITLE = 9;             // verdanab_20_4bpp
    static const uint16_t NUMBER_OF_FONTS = 10;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /* flashReader */)
    {
    }
    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
