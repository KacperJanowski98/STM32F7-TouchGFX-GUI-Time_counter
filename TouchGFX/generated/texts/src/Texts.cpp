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
    0x4b, 0x61, 0x63, 0x70, 0x65, 0x72, 0x20, 0x4a, 0x61, 0x6e, 0x6f, 0x77, 0x73, 0x6b, 0x69, 0xa, 0x57, 0x45, 0x4c, 0x31, 0x38, 0x45, 0x43, 0x31, 0x53, 0x31, 0xa, 0x4e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x20, 0x6f, 0x66, 0x20, 0x61, 0x6c, 0x62, 0x75, 0x6d, 0x3a, 0x20, 0x37, 0x31, 0x39, 0x38, 0x30, 0x0, // @51 "Kacper Janowski?WEL18EC1S1?Number of album: 71980"
    0x47, 0x72, 0x61, 0x70, 0x68, 0x20, 0x2d, 0x20, 0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x2, 0x0, // @101 "Graph - Frequency Measurement <>"
    0x4d, 0x75, 0x6c, 0x74, 0x69, 0x63, 0x68, 0x61, 0x6e, 0x6e, 0x65, 0x6c, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x2f, 0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x43, 0x6f, 0x75, 0x6e, 0x74, 0x65, 0x72, 0x0, // @133 "Multichannel Time/Frequency Counter"
    0x4d, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x79, 0x20, 0x55, 0x6e, 0x69, 0x76, 0x65, 0x72, 0x73, 0x69, 0x74, 0x79, 0x20, 0x6f, 0x66, 0x20, 0x54, 0x65, 0x63, 0x68, 0x6e, 0x6f, 0x6c, 0x6f, 0x67, 0x79, 0x0, // @169 "Military University of Technology"
    0x54, 0x49, 0x4d, 0x45, 0x20, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x56, 0x41, 0x4c, 0x2f, 0x4d, 0x4f, 0x44, 0x45, 0x3a, 0x20, 0x49, 0x4e, 0x44, 0x45, 0x50, 0x45, 0x4e, 0x44, 0x45, 0x4e, 0x54, 0x0, // @203 "TIME INTERVAL/MODE: INDEPENDENT"
    0x47, 0x72, 0x61, 0x70, 0x68, 0x20, 0x2d, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x20, 0x2, 0x0, // @235 "Graph - Time interval  <>"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x36, 0x0, // @260 "Frequency measurement 6"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x37, 0x0, // @284 "Frequency measurement 7"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x38, 0x0, // @308 "Frequency measurement 8"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x35, 0x0, // @332 "Frequency measurement 5"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x34, 0x0, // @356 "Frequency measurement 4"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x31, 0x0, // @380 "Frequency measurement 1"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x32, 0x0, // @404 "Frequency measurement 2"
    0x46, 0x72, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x79, 0x20, 0x6d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x33, 0x0, // @428 "Frequency measurement 3"
    0x46, 0x52, 0x45, 0x51, 0x55, 0x45, 0x4e, 0x43, 0x59, 0x20, 0x4d, 0x45, 0x41, 0x53, 0x55, 0x52, 0x45, 0x4d, 0x45, 0x4e, 0x54, 0x0, // @452 "FREQUENCY MEASUREMENT"
    0x54, 0x49, 0x4d, 0x45, 0x20, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x56, 0x41, 0x4c, 0x2f, 0x4d, 0x4f, 0x44, 0x45, 0x0, // @474 "TIME INTERVAL/MODE"
    0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0xa, 0x51, 0x75, 0x61, 0x72, 0x74, 0x7a, 0x0, // @493 "Internal?Quartz"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x37, 0x0, // @509 "Time interval 7"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x34, 0x0, // @525 "Time interval 4"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x33, 0x0, // @541 "Time interval 3"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x35, 0x0, // @557 "Time interval 5"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x32, 0x0, // @573 "Time interval 2"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x31, 0x0, // @589 "Time interval 1"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x20, 0x36, 0x0, // @605 "Time interval 6"
    0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0xa, 0x52, 0x75, 0x62, 0x69, 0x64, 0x0, // @621 "Internal?Rubid"
    0x53, 0x45, 0x53, 0x53, 0x49, 0x4f, 0x4e, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @636 "SESSION SETUP"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x20, 0x4e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x0, // @650 "Stamps Number"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x20, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x0, // @664 "Stamps number"
    0x54, 0x49, 0x20, 0x4d, 0x41, 0x58, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x45, 0x0, // @678 "TI MAX RANGE"
    0x49, 0x4e, 0x2, 0x3a, 0x20, 0x0, // @691 "IN<>: "
    0x28, 0x49, 0x4e, 0x2, 0x29, 0x0, // @697 "(IN<>)"
    0x43, 0x41, 0x4c, 0x49, 0x42, 0x52, 0x41, 0x54, 0x49, 0x4f, 0x4e, 0x0, // @703 "CALIBRATION"
    0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6e, 0x75, 0x6f, 0x75, 0x73, 0x0, // @715 "Continuous"
    0x2, 0x20, 0x6d, 0x56, 0x0, // @726 "<> mV"
    0x28, 0x49, 0x4e, 0x2, 0x0, // @731 "(IN<>"
    0x2, 0x20, 0x6d, 0x73, 0x0, // @736 "<> ms"
    0x53, 0x54, 0x41, 0x52, 0x54, 0x20, 0x2d, 0x20, 0x49, 0x4e, 0x0, // @741 "START - IN"
    0x4d, 0x45, 0x53, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @752 "MES SETUP"
    0x54, 0x48, 0x52, 0x45, 0x53, 0x48, 0x4f, 0x4c, 0x44, 0x0, // @762 "THRESHOLD"
    0x53, 0x54, 0x4f, 0x50, 0x20, 0x2d, 0x20, 0x49, 0x4e, 0x0, // @772 "STOP - IN"
    0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x3a, 0x0, // @782 "Version:"
    0x48, 0x46, 0x20, 0x49, 0x4e, 0x50, 0x55, 0x54, 0x0, // @791 "HF INPUT"
    0x54, 0x49, 0x20, 0x53, 0x45, 0x54, 0x55, 0x50, 0x0, // @800 "TI SETUP"
    0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0x0, // @809 "External"
    0x2, 0x25, 0x0, // @818 "<>%"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x20, 0x0, // @821 "Stamps "
    0x4d, 0x54, 0x43, 0x20, 0x31, 0x30, 0x38, 0x0, // @829 "MTC 108"
    0x41, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x3a, 0x0, // @837 "Author:"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x31, 0x20, 0x0, // @845 "Freq 1 "
    0x53, 0x74, 0x64, 0x44, 0x65, 0x76, 0x0, // @853 "StdDev"
    0x52, 0x65, 0x70, 0x65, 0x61, 0x74, 0x0, // @860 "Repeat"
    0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x0, // @867 "Sample"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x38, 0x0, // @874 "Freq 8"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x37, 0x0, // @881 "Freq 7"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x36, 0x0, // @888 "Freq 6"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x35, 0x0, // @895 "Freq 5"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x34, 0x0, // @902 "Freq 4"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x33, 0x0, // @909 "Freq 3"
    0x46, 0x72, 0x65, 0x71, 0x20, 0x32, 0x0, // @916 "Freq 2"
    0x44, 0x65, 0x74, 0x65, 0x63, 0x74, 0x0, // @923 "Detect"
    0x53, 0x69, 0x6e, 0x67, 0x6c, 0x65, 0x0, // @930 "Single"
    0x53, 0x74, 0x61, 0x6d, 0x70, 0x73, 0x0, // @937 "Stamps"
    0x53, 0x4c, 0x4f, 0x50, 0x45, 0x0, // @944 "SLOPE"
    0x54, 0x49, 0x20, 0x31, 0x20, 0x0, // @950 "TI 1 "
    0x54, 0x49, 0x20, 0x32, 0x20, 0x0, // @956 "TI 2 "
    0x54, 0x49, 0x20, 0x34, 0x20, 0x0, // @962 "TI 4 "
    0x54, 0x49, 0x20, 0x35, 0x20, 0x0, // @968 "TI 5 "
    0x54, 0x49, 0x20, 0x36, 0x20, 0x0, // @974 "TI 6 "
    0x43, 0x4c, 0x4f, 0x43, 0x4b, 0x0, // @980 "CLOCK"
    0x41, 0x42, 0x4f, 0x55, 0x54, 0x0, // @986 "ABOUT"
    0x54, 0x49, 0x20, 0x37, 0x20, 0x0, // @992 "TI 7 "
    0x31, 0x2e, 0x30, 0x2e, 0x30, 0x0, // @998 "1.0.0"
    0x4d, 0x45, 0x4e, 0x55, 0x0, // @1004 "MENU"
    0x47, 0x41, 0x54, 0x45, 0x0, // @1009 "GATE"
    0x4d, 0x65, 0x61, 0x6e, 0x0, // @1014 "Mean"
    0x54, 0x49, 0x20, 0x33, 0x0, // @1019 "TI 3"
    0x4f, 0x46, 0x46, 0x0, // @1024 "OFF"
    0x58, 0x0 // @1028 "X"
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
