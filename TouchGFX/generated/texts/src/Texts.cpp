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
    0x47, 0x72, 0x61, 0x70, 0x68, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x68, 0x65, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x73, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x0, // @0 "Graph with the measurement values from stamps mode"
    0x47, 0x72, 0x61, 0x70, 0x68, 0x20, 0x2d, 0x20, 0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x2, 0x0, // @51 "Graph - Frequency Measurement <>"
    0x4d, 0x75, 0x6c, 0x74, 0x69, 0x63, 0x68, 0x61, 0x6e, 0x6e, 0x65, 0x6c, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x2f, 0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x43, 0x6f, 0x75, 0x6e, 0x74, 0x65, 0x72, 0x0, // @83 "Multichannel Time/Frequency Counter"
    0x54, 0x49, 0x4d, 0x45, 0x20, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x56, 0x41, 0x4c, 0x2f, 0x4d, 0x4f, 0x44, 0x45, 0x3a, 0x20, 0x49, 0x4e, 0x44, 0x45, 0x50, 0x45, 0x4e, 0x44, 0x45, 0x4e, 0x54, 0x0, // @119 "TIME INTERVAL/MODE: INDEPENDENT"
    0x47, 0x72, 0x61, 0x70, 0x68, 0x20, 0x2d, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x20, 0x2, 0x0, // @151 "Graph - Time interval  <>"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x35, 0x0, // @176 "Frequency measurement 5"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x33, 0x0, // @200 "Frequency measurement 3"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x32, 0x0, // @224 "Frequency measurement 2"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x31, 0x0, // @248 "Frequency measurement 1"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x36, 0x0, // @272 "Frequency measurement 6"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x37, 0x0, // @296 "Frequency measurement 7"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x34, 0x0, // @320 "Frequency measurement 4"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x38, 0x0, // @344 "Frequency measurement 8"
    0x46, 0x52, 0x45, 0x51, 0x55, 0x45, 0x4e, 0x43, 0x59, 0x20, 0x4d, 0x45, 0x41, 0x53, 0x55, 0x52, 0x45, 0x4d, 0x45, 0x4e, 0x54, 0x0, // @368 "FREQUENCY MEASUREMENT"
    0x54, 0x49, 0x4d, 0x45, 0x20, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x56, 0x41, 0x4c, 0x2f, 0x4d, 0x4f, 0x44, 0x45, 0x0, // @390 "TIME INTERVAL/MODE"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x35, 0x0, // @409 "Time interval 5"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x36, 0x0, // @425 "Time interval 6"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x31, 0x0, // @441 "Time interval 1"
    0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0xa, 0x51, 0x75, 0x61, 0x72, 0x74, 0x7a, 0x0, // @457 "Internal?Quartz"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x34, 0x0, // @473 "Time interval 4"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x33, 0x0, // @489 "Time interval 3"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x37, 0x0, // @505 "Time interval 7"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x32, 0x0, // @521 "Time interval 2"
    0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0xa, 0x52, 0x75, 0x62, 0x69, 0x64, 0x0, // @537 "Internal?Rubid"
    0x53, 0x45, 0x53, 0x53, 0x49, 0x4f, 0x4e, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @552 "SESSION SETUP"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x20, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x0, // @566 "Stamps number"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x20, 0x4e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x0, // @580 "Stamps Number"
    0x54, 0x49, 0x20, 0x4d, 0x41, 0x58, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x45, 0x0, // @594 "TI MAX RANGE"
    0x28, 0x49, 0x4e, 0x2, 0x29, 0x0, // @607 "(IN<>)"
    0x49, 0x4e, 0x2, 0x3a, 0x20, 0x0, // @613 "IN<>: "
    0x43, 0x41, 0x4c, 0x49, 0x42, 0x52, 0x41, 0x54, 0x49, 0x4f, 0x4e, 0x0, // @619 "CALIBRATION"
    0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6e, 0x75, 0x6f, 0x75, 0x73, 0x0, // @631 "Continuous"
    0x2, 0x20, 0x6d, 0x73, 0x0, // @642 "<> ms"
    0x53, 0x54, 0x41, 0x52, 0x54, 0x20, 0x2d, 0x20, 0x49, 0x4e, 0x0, // @647 "START - IN"
    0x2, 0x20, 0x6d, 0x56, 0x0, // @658 "<> mV"
    0x28, 0x49, 0x4e, 0x2, 0x0, // @663 "(IN<>"
    0x4d, 0x45, 0x53, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @668 "MES SETUP"
    0x54, 0x48, 0x52, 0x45, 0x53, 0x48, 0x4f, 0x4c, 0x44, 0x0, // @678 "THRESHOLD"
    0x53, 0x54, 0x4f, 0x50, 0x20, 0x2d, 0x20, 0x49, 0x4e, 0x0, // @688 "STOP - IN"
    0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0x0, // @698 "External"
    0x48, 0x46, 0x20, 0x49, 0x4e, 0x50, 0x55, 0x54, 0x0, // @707 "HF INPUT"
    0x2, 0x25, 0x0, // @716 "<>%"
    0x54, 0x49, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @719 "TI SETUP"
    0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x3a, 0x0, // @728 "Version:"
    0x4d, 0x54, 0x43, 0x20, 0x31, 0x30, 0x38, 0x0, // @737 "MTC 108"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x20, 0x0, // @745 "Stamps "
    0x46, 0x72, 0x65, 0x71, 0x20, 0x31, 0x20, 0x0, // @753 "Freq 1 "
    0x53, 0x74, 0x64, 0x44, 0x65, 0x76, 0x0, // @761 "StdDev"
    0x52, 0x65, 0x70, 0x65, 0x61, 0x74, 0x0, // @768 "Repeat"
    0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x0, // @775 "Sample"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x38, 0x0, // @782 "Freq 8"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x37, 0x0, // @789 "Freq 7"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x36, 0x0, // @796 "Freq 6"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x35, 0x0, // @803 "Freq 5"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x34, 0x0, // @810 "Freq 4"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x33, 0x0, // @817 "Freq 3"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x32, 0x0, // @824 "Freq 2"
    0x44, 0x65, 0x74, 0x65, 0x63, 0x74, 0x0, // @831 "Detect"
    0x53, 0x69, 0x6e, 0x67, 0x6c, 0x65, 0x0, // @838 "Single"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x0, // @845 "Stamps"
    0x43, 0x4c, 0x4f, 0x43, 0x4b, 0x0, // @852 "CLOCK"
    0x54, 0x49, 0x20, 0x31, 0x20, 0x0, // @858 "TI 1 "
    0x54, 0x49, 0x20, 0x32, 0x20, 0x0, // @864 "TI 2 "
    0x54, 0x49, 0x20, 0x34, 0x20, 0x0, // @870 "TI 4 "
    0x54, 0x49, 0x20, 0x35, 0x20, 0x0, // @876 "TI 5 "
    0x54, 0x49, 0x20, 0x36, 0x20, 0x0, // @882 "TI 6 "
    0x53, 0x4c, 0x4f, 0x50, 0x45, 0x0, // @888 "SLOPE"
    0x54, 0x49, 0x20, 0x37, 0x20, 0x0, // @894 "TI 7 "
    0x31, 0x2e, 0x30, 0x2e, 0x30, 0x0, // @900 "1.0.0"
    0x41, 0x42, 0x4f, 0x55, 0x54, 0x0, // @906 "ABOUT"
    0x4d, 0x65, 0x61, 0x6e, 0x0, // @912 "Mean"
    0x47, 0x41, 0x54, 0x45, 0x0, // @917 "GATE"
    0x4d, 0x45, 0x4e, 0x55, 0x0, // @922 "MENU"
    0x54, 0x49, 0x20, 0x33, 0x0, // @927 "TI 3"
    0x4f, 0x46, 0x46, 0x0, // @932 "OFF"
    0x58, 0x0 // @936 "X"
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
