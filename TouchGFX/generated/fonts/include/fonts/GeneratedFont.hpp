/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_GENERATEDFONT_HPP
#define TOUCHGFX_GENERATEDFONT_HPP

#include <touchgfx/ConstFont.hpp>

namespace touchgfx
{
/**
 * An GeneratedFont has both glyph table and glyph data placed in a flash which
 * supports random access read (i.e. not a NAND flash)
 *
 * @see ConstFont
 */
class GeneratedFont : public ConstFont
{
public:
    /**
     * Construct the GeneratedFont.
     *
     * @param list                   The array of glyphs known to this font.
     * @param size                   The number of glyphs in list.
     * @param height                 The height in pixels of the highest character in this font.
     * @param pixBelowBase           The maximum number of pixels that can be drawn below the
     *                               baseline in this font.
     * @param bitsPerPixel           The number of bits per pixel in this font.
     * @param byteAlignRow           Are glyphs encoded using A4 format
     * @param maxLeft                The maximum a character extends to the left.
     * @param maxRight               The maximum a character extends to the right.
     * @param glyphDataInternalFlash Pointer to the glyph data for the font, placed in internal
     *                               flash.
     * @param kerningList            pointer to the kerning data for the font, placed in internal
     *                               flash.
     * @param fallbackChar           The fallback character for the typography in case no glyph is
     *                               available.
     * @param ellipsisChar           The ellipsis character used for truncating long texts.
     * @param gsubTable              Pointer to GSUB table.
     * @param formsTable             Pointer to contextual forms table.
     */
    GeneratedFont(const GlyphNode* list, uint16_t size, uint16_t height, uint8_t pixBelowBase, uint8_t bitsPerPixel, uint8_t byteAlignRow, uint8_t maxLeft, uint8_t maxRight, const uint8_t* const* glyphDataInternalFlash, const KerningNode* kerningList, const Unicode::UnicodeChar fallbackChar, const Unicode::UnicodeChar ellipsisChar, const uint16_t* const gsubData, const FontContextualFormsTable* formsTable);

    using ConstFont::getGlyph;

    /**
     * Obtains a RAM-based pointer to the pixel data for the specified glyph.
     *
     * @param glyph The glyph to get the pixels data of.
     *
     * @return The pixel data of the glyph.
     */
    virtual const uint8_t* getPixelData(const GlyphNode* glyph) const;

    /**
     * Gets the kerning distance between two characters.
     *
     * @param prevChar The unicode value of the previous character.
     * @param glyph    the glyph object for the current character.
     *
     * @return The kerning distance between prevChar and glyph char.
     */
    virtual int8_t getKerning(Unicode::UnicodeChar prevChar, const GlyphNode* glyph) const;

    /**
     * Gets GSUB table.
     *
     * @return The GSUB table or null if font has GSUB no table
     */
    virtual const uint16_t* getGSUBTable() const
    {
        return gsubTable;
    }

    /**
     * Gets the contextual forms table used in arabic fonts.
     *
     * @return The FontContextualFormsTable or null if the font has no table.
     */
    virtual const FontContextualFormsTable* getContextualFormsTable() const
    {
        return arabicTable;
    }

protected:
    GeneratedFont()
        : ConstFont(0, 0, 0, 0, 0, 0, 0, 0, 0, 0), glyphData(0), kerningData(0), gsubTable(0), arabicTable(0)
    {
    }

    const void* glyphData;          ///< The glyphs
    const KerningNode* kerningData; ///< The kerning
    const uint16_t* gsubTable;      ///< The GSUB tables

    const FontContextualFormsTable* arabicTable; ///< Contextual forms
};

struct BinaryFontData
{
    uint32_t fontIndex;                // The font index (as used by TypedTextDatabase)
    uint32_t sizeOfFontData;           // Size of the complete BinaryFont
    uint32_t offsetToTable;            // GlyphNode[]
    uint32_t offsetToKerning;          // KerningNode[]
    uint32_t offsetToGlyphs;           // uint8_t[]
    uint32_t offsetToGSUB;             // uint16_t[]
    uint32_t offsetToArabicTable;      // FontContextualFormsTable
    uint16_t numberOfGlyphs;           // Number of glyphs in Table and Glyphs
    uint16_t height;                   // Font height from base
    uint8_t pixBelowBase;              // Max pixels below base
    uint8_t bitsPerPixel : 7;          // Bpp
    uint8_t byteAlignRow : 1;          // A4/A2/A1
    uint8_t maxLeft;                   // The maximum a glyph extends to the left
    uint8_t maxRight;                  // The maximum a glyph extends to the right
    Unicode::UnicodeChar fallbackChar; // Fallback Character for the font
    Unicode::UnicodeChar ellipsisChar; // Ellipsis Character for the font
};

class BinaryFont : public GeneratedFont
{
public:
    BinaryFont(const struct touchgfx::BinaryFontData* data)
        : GeneratedFont((const GlyphNode*)((const uint8_t*)data + data->offsetToTable),
                        data->numberOfGlyphs,
                        data->height,
                        data->pixBelowBase,
                        data->bitsPerPixel,
                        data->byteAlignRow,
                        data->maxLeft,
                        data->maxRight,
                        0,
                        (const KerningNode*)((const uint8_t*)data + data->offsetToKerning),
                        data->fallbackChar,
                        data->ellipsisChar,
                        (data->offsetToGSUB == 0) ? 0 : (const uint16_t*)((const uint8_t*)data + data->offsetToGSUB),
                        0),
          glyphData((const uint8_t*)data + data->offsetToGlyphs)
    {
        if (data->offsetToArabicTable > 0)
        {
            setupContextualTable(data);
        }
    }

    BinaryFont()
        : GeneratedFont()
    {
    }

    virtual const uint8_t* getPixelData(const GlyphNode* glyph) const
    {
        const uint8_t* data = (const uint8_t*)glyphData;
        return &(data[glyph->dataOffset]);
    }

protected:
    const uint8_t* glyphData;
    FontContextualFormsTable contextualForms;

private:
    typedef const Unicode::UnicodeChar (*array5ptr)[5];
    typedef const Unicode::UnicodeChar (*array4ptr)[4];
    void setupContextualTable(const struct touchgfx::BinaryFontData* data)
    {
        const uint16_t* const base = (const uint16_t*)(((const uint8_t*)data) + data->offsetToArabicTable);
        //first elements in binary font are offsets to arrays in 16bit words
        contextualForms.contextualForms4Long = (array5ptr)(base + base[0]);
        contextualForms.contextualForms3Long = (array5ptr)(base + base[1]);
        contextualForms.contextualForms2Long = (array5ptr)(base + base[2]);
        contextualForms.contextualForms0621_063a = (array4ptr)(base + base[3]);
        contextualForms.contextualForms0641_064a = (array4ptr)(base + base[4]);
        contextualForms.contextualForms06XX = (array5ptr)(base + base[5]);
        contextualForms.contextualForms4LongSize = base[6];
        contextualForms.contextualForms3LongSize = base[7];
        contextualForms.contextualForms2LongSize = base[8];
        contextualForms.contextualForms06XXSize = base[9];
        arabicTable = &contextualForms;
    }
};
} // namespace touchgfx

#endif // TOUCHGFX_GENERATEDFONT_HPP
