/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) //Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

//Default typed text database
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x54, 0x49, 0x4d, 0x45, 0x20, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x56, 0x41, 0x4c, 0x2f, 0x4d, 0x4f, 0x44, 0x45, 0x3a, 0x20, 0x49, 0x4e, 0x44, 0x45, 0x50, 0x45, 0x4e, 0x44, 0x45, 0x4e, 0x54, 0x0, // @0 "TIME INTERVAL/MODE: INDEPENDENT"
    0x56, 0x61, 0x6c, 0x75, 0x65, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x2e, 0x63, 0x3a, 0x20, 0x2, 0x0, // @32 "Value from main.c: <>"
    0x46, 0x52, 0x45, 0x51, 0x55, 0x45, 0x4e, 0x43, 0x59, 0x20, 0x4d, 0x45, 0x41, 0x53, 0x55, 0x52, 0x45, 0x4d, 0x45, 0x4e, 0x54, 0x0, // @53 "FREQUENCY MEASUREMENT"
    0x54, 0x49, 0x4d, 0x45, 0x20, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x56, 0x41, 0x4c, 0x2f, 0x4d, 0x4f, 0x44, 0x45, 0x0, // @75 "TIME INTERVAL/MODE"
    0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0xa, 0x51, 0x75, 0x61, 0x72, 0x74, 0x7a, 0x0, // @94 "Internal?Quartz"
    0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0xa, 0x52, 0x75, 0x62, 0x69, 0x64, 0x0, // @110 "Internal?Rubid"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x20, 0x4e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x0, // @125 "Stamps Number"
    0x53, 0x45, 0x53, 0x53, 0x49, 0x4f, 0x4e, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @139 "SESSION SETUP"
    0x54, 0x49, 0x20, 0x4d, 0x41, 0x58, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x45, 0x0, // @153 "TI MAX RANGE"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @166 "Calibration"
    0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6e, 0x75, 0x6f, 0x75, 0x73, 0x0, // @178 "Continuous"
    0x2, 0x20, 0x6d, 0x73, 0x0, // @189 "<> ms"
    0x53, 0x54, 0x41, 0x52, 0x54, 0x20, 0x2d, 0x20, 0x49, 0x4e, 0x0, // @194 "START - IN"
    0x2, 0x20, 0x6d, 0x56, 0x0, // @205 "<> mV"
    0x54, 0x48, 0x52, 0x45, 0x53, 0x48, 0x4f, 0x4c, 0x44, 0x0, // @210 "THRESHOLD"
    0x2, 0x20, 0x73, 0x0, // @220 "<> s"
    0x4d, 0x45, 0x53, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @224 "MES SETUP"
    0x4d, 0x65, 0x61, 0x73, 0x20, 0x52, 0x61, 0x74, 0x65, 0x0, // @234 "Meas Rate"
    0x53, 0x54, 0x4f, 0x50, 0x20, 0x2d, 0x20, 0x49, 0x4e, 0x0, // @244 "STOP - IN"
    0x48, 0x46, 0x20, 0x49, 0x4e, 0x50, 0x55, 0x54, 0x0, // @254 "HF INPUT"
    0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0x0, // @263 "External"
    0x54, 0x49, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @272 "TI SETUP"
    0x44, 0x65, 0x66, 0x69, 0x6e, 0x65, 0x64, 0x0, // @281 "Defined"
    0x4d, 0x61, 0x6e, 0x75, 0x61, 0x6c, 0x0, // @289 "Manual"
    0x44, 0x65, 0x74, 0x65, 0x63, 0x74, 0x0, // @296 "Detect"
    0x53, 0x69, 0x6e, 0x67, 0x6c, 0x65, 0x0, // @303 "Single"
    0x52, 0x65, 0x70, 0x65, 0x61, 0x74, 0x0, // @310 "Repeat"
    0x53, 0x4c, 0x4f, 0x50, 0x45, 0x0, // @317 "SLOPE"
    0x43, 0x4c, 0x4f, 0x43, 0x4b, 0x0, // @323 "CLOCK"
    0x47, 0x41, 0x54, 0x45, 0x0, // @329 "GATE"
    0x4f, 0x46, 0x46, 0x0, // @334 "OFF"
    0x4f, 0x4e, 0x0, // @338 "ON"
    0x58, 0x0, // @341 "X"
    0x30, 0x0, // @343 "0"
    0x31, 0x0 // @345 "1"
};
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

//array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

//Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            //dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            //compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
