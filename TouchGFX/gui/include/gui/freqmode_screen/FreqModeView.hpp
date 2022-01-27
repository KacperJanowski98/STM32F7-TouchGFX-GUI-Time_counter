#ifndef FREQMODEVIEW_HPP
#define FREQMODEVIEW_HPP

#include <gui_generated/freqmode_screen/FreqModeViewBase.hpp>
#include <gui/freqmode_screen/FreqModePresenter.hpp>
#include <touchgfx/Color.hpp>

class FreqModeView : public FreqModeViewBase
{
public:
    FreqModeView();
    virtual ~FreqModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void ResetParameter();

    /**
     * @brief Aktualizacja wynikow pomiarow wyswietlanych na tym ekranie.
     * 
     */
    virtual void updateUIContinuousFreq();

protected:

    /**
     * @brief Funkcja obliczajaca format wyswietlanych wartosci srednich na podstawie danych ze struktury wymiany danych.
     * 
     * @param mean Wartosc srednia ze struktury wymiany dannych.
     * @param pTotal Wskaznik na czesc calokowita wartosci sreniej.
     * @param pFrac1 Wskaznik na pierwsza czesc frakcyjna wartosci sreniej.
     * @param pFrac2 Wskaznik na druga czesc frakcyjna wartosci sredniej.
     */
    void calculateFormatMeanFreq(float mean, int *pTotal, int *pFrac1, int *pFrac2);

    /**
     * @brief Funkcja obliczajaca format wyswietlanych odchylen standardowych na podstawie danych ze struktury wymiany danych.
     * 
     * @param stdDev Wartosc odchylenia stadardowego.
     * @param pTotal Wskaznik na czesc calkowita odchylenia standardowego.
     * @param pFrac Wskaznik na pierwsza czesc frakcyjna wartosci odchylenia standardowego.
     */
    void calculateFormatStdDevFreq(float stdDev, int *pTotal, int *pFrac);

    /**
     * @brief Funkcja ustawiajaca wartosci etykiet konfiguracji wejsc pomiarowych do obliczen czestotliwosci.
     * 
     * @param textBuffer Bufor na dane do wyswietlenia.
     * @param size Rozmiar bufora na dane do wyswietlenia.
     * @param numberCh Numer wejscia pomiarowego.
     * @param text Komponent GUI ktory podane dane w interfejsie.
     */
    void setLabelFreq(touchgfx::Unicode::UnicodeChar *textBuffer, uint16_t size, uint8_t numberCh, touchgfx::TextAreaWithOneWildcard *text);

    /**
     * @brief Funkcja ustawiajaca kolor etykiet konfiguracji wejsc pomiarowych do obliczen czestotliwosci.
     * 
     * @param channelState Stan w jakim znjduje sie wejscie pomiarowe.
     * @param label Etykieta, ktorej modyfikowany jest kolor.
     * @param labelStart Etykieta, ktorej modyfikowany jest kolor.
     */
    void setLabelColorFreq(bool channelState, touchgfx::TextArea *label, touchgfx::TextArea *labelStart);

    /**
     * @brief Funkcja ustawiajaca kolor etykiet z wynikami pomiarow czestotliwosci.
     * 
     * @param channelState Stan w jakim znjduje sie wejscie pomiarowe.
     * @param mean Etykieta, ktorej modyfikowany jest kolor.
     * @param stdDev Etykieta, ktorej modyfikowany jest kolor.
     */
    void setMeasColorFreq(bool channelState, touchgfx::TextAreaWithOneWildcard *mean, touchgfx::TextAreaWithOneWildcard *stdDev);

    /**
     * @brief Funkcja ustawiajaca etykete odpowiedzialna za prezentacje liczby wykonanych pomiarow w serii.
     * 
     * @param pFreqCh Wskaznik na strukture konfiguracyjna pomiar czestotliwosci.
     * @param textSample Etykieta do prezentowania wartosci liczby pomiarow w serii pomiarowej.
     * @param textSampleBuffer Bufor na wartosc liczby powtorzen w serii.
     * @param sizeSample Wielkosc bufora.
     * @param session Wskaznik na strukture z seria pomiarowa.
     */
    void setSampleFreq(FreqChannel_t *pFreqCh, touchgfx::TextAreaWithOneWildcard *textSample, touchgfx::Unicode::UnicodeChar *textSampleBuffer,
						uint16_t sizeSample, SessionSetup_t *session);

    /**
     * @brief Funkcja ustawiajaca etykiety odpowiedzialne za prezentowanie wynikow srednich pomiarow.
     * 
     * @param measure Wskaznik na funkcje z wartosciami pomiarowymi.
     * @param total Czesc calkowita wartosci sredniej.
     * @param fraction1 Pierwsza czesc frakcyjna wartosci sredniej.
     * @param fraction2 Druga czesc frakcyjna wartosci sredniej.
     * @param textMeanBuffer Bufor na wartosc srednia.
     * @param sizeMean Wielkosc bufora na wartosc srednia.
     * @param textMean Etykieta do wyswietlenia wartosci sredniej.
     * @param textUnitMeanBuffer Bufor na jednostke.
     * @param sizeUnitMean Wielkosc bufora na jednostke.
     * @param textUnitMean Etykieta do wyswietlenia jednostki.
     */
    void setMeanResultFreq(MeasValues_t *measure, int *total, int *fraction1, int *fraction2, touchgfx::Unicode::UnicodeChar *textMeanBuffer,
    						uint16_t sizeMean, touchgfx::TextAreaWithOneWildcard *textMean, touchgfx::Unicode::UnicodeChar *textUnitMeanBuffer,
							uint16_t sizeUnitMean, touchgfx::TextAreaWithOneWildcard *textUnitMean);

    /**
     * @brief Funkcja ustawiajaca etykiety odpowiedzialne za prezentowanie wynikow obliczen odchylenia standardowego.
     * 
     * @param textStdDevBuffer Bufor na wynik odchylenia standardowego do wyswietlenia.
     * @param sizeStdDev Wielkosc bufora na wynik odchylenia standardowego.
     * @param textStdDev Etykieta do wyswietlenia wyniku odchylenia standardowego.
     * @param textUnitStdDevBuffer Bufor na jednostke odchylenia standardowego.
     * @param sizeUnitStdDev Wielkosc bufora na jednostke.
     * @param textUnitStdDev Etykieta do wyswietlenia jednostki.
     * @param measure Wskaznik na funkcje z wartosciami pomiarowymi.
     * @param total Czesc calkowita wartosci sredniej.
     * @param fraction Czesc frakcyjna wartosci sredniej.
     */
    void setStdDevResultFreq(touchgfx::Unicode::UnicodeChar *textStdDevBuffer, uint16_t sizeStdDev, touchgfx::TextAreaWithOneWildcard *textStdDev,
    						touchgfx::Unicode::UnicodeChar *textUnitStdDevBuffer, uint16_t sizeUnitStdDev, touchgfx::TextAreaWithOneWildcard *textUnitStdDev,
							MeasValues_t *measure, int *total, int *fraction);
private:
    std::string pHz;
    std::string nHz;
    std::string uHz;
    std::string mHz;
    std::string Hz;
    std::string kHz;
    std::string MHz;
    std::string GHz;

    int m_total_freq1;
    int m_frac1_freq1;
    int m_frac2_freq1;
    int m_total_freq2;
    int m_frac1_freq2;
    int m_frac2_freq2;
    int m_total_freq3;
    int m_frac1_freq3;
    int m_frac2_freq3;
    int m_total_freq4;
    int m_frac1_freq4;
    int m_frac2_freq4;
    int m_total_freq5;
    int m_frac1_freq5;
    int m_frac2_freq5;
    int m_total_freq6;
    int m_frac1_freq6;
    int m_frac2_freq6;
    int m_total_freq7;
    int m_frac1_freq7;
    int m_frac2_freq7;
    int m_total_freq8;
    int m_frac1_freq8;
    int m_frac2_freq8;
    int m_totalStdDev1;
    int m_fracStdDev1;
    int m_totalStdDev2;
    int m_fracStdDev2;
    int m_totalStdDev3;
    int m_fracStdDev3;
    int m_totalStdDev4;
    int m_fracStdDev4;
    int m_totalStdDev5;
    int m_fracStdDev5;
    int m_totalStdDev6;
    int m_fracStdDev6;
    int m_totalStdDev7;
    int m_fracStdDev7;
    int m_totalStdDev8;
    int m_fracStdDev8;
};

#endif // FREQMODEVIEW_HPP
