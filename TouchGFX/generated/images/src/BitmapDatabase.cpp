// 4.17.0 0xaf4e6f32
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_blue_buttons_round_edge_icon_button[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID = 0, Size: 60x60 pixels
extern const unsigned char image_blue_buttons_round_edge_icon_button_pressed[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID = 1, Size: 60x60 pixels
extern const unsigned char image_blue_buttons_round_large[]; // BITMAP_BLUE_BUTTONS_ROUND_LARGE_ID = 2, Size: 360x60 pixels
extern const unsigned char image_blue_buttons_round_large_pressed[]; // BITMAP_BLUE_BUTTONS_ROUND_LARGE_PRESSED_ID = 3, Size: 360x60 pixels
extern const unsigned char image_blue_progressindicators_bg_medium_circle_indicator_bg_line_full[]; // BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_CIRCLE_INDICATOR_BG_LINE_FULL_ID = 4, Size: 104x104 pixels
extern const unsigned char image_blue_progressindicators_fill_medium_circle_indicator_fill_line_full[]; // BITMAP_BLUE_PROGRESSINDICATORS_FILL_MEDIUM_CIRCLE_INDICATOR_FILL_LINE_FULL_ID = 5, Size: 104x104 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_blue_buttons_round_edge_icon_button, 0, 60, 60, 7, 6, 46, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 46, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_edge_icon_button_pressed, 0, 60, 60, 7, 6, 46, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 46, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_large, 0, 360, 60, 22, 5, 316, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 48, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_large_pressed, 0, 360, 60, 22, 5, 316, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 48, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_progressindicators_bg_medium_circle_indicator_bg_line_full, 0, 104, 104, 85, 28, 13, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 48, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_progressindicators_fill_medium_circle_indicator_fill_line_full, 0, 104, 104, 87, 31, 10, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 42, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
