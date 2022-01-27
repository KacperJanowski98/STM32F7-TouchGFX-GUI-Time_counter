#ifndef TIMEMODEVIEW_HPP
#define TIMEMODEVIEW_HPP

#include <gui_generated/timemode_screen/TimeModeViewBase.hpp>
#include <gui/timemode_screen/TimeModePresenter.hpp>
#include <string.h>
#include <gui/lib/TimeModeParameter.hpp>
#include <gui/lib/SessionSetup.hpp>
#include <gui/model/Model.hpp>
#include <touchgfx/Color.hpp>

class TimeModeView : public TimeModeViewBase
{
public:
    TimeModeView();
    virtual ~TimeModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void ResetParameter();

    /**
     * @brief Aktualizacja wynikow pomiarow wyswietlanych na tym ekranie.
     * 
     */
    virtual void updateUIContinuousTime();

protected:

    /**
     * @brief Funkcja obliczajaca format wyswietlanych wartosci srednich na podstawie danych ze struktury wymiany danych.
     * 
     * @param mean Wartosc srednia ze struktury wymiany dannych.
     * @param pTotal Wskaznik na czesc calokowita wartosci sreniej.
     * @param pFrac1 Wskaznik na pierwsza czesc frakcyjna wartosci sreniej.
     * @param pFrac2 Wskaznik na druga czesc frakcyjna wartosci sredniej.
     */
    void calculateFormatMeanTime(float mean, int *pTotal, int *pFrac1, int *pFrac2);

    /**
     * @brief Funkcja obliczajaca format wyswietlanych odchylen standardowych na podstawie danych ze struktury wymiany danych.
     * 
     * @param stdDev Wartosc odchylenia stadardowego.
     * @param pTotal Wskaznik na czesc calkowita odchylenia standardowego.
     * @param pFrac Wskaznik na pierwsza czesc frakcyjna wartosci odchylenia standardowego.
     */
    void calculateFormatStdDevTime(float stdDev, int *pTotal, int *pFrac);

    /**
     * @brief Funkcja ustawiajaca wartosci etykiet konfiguracji wejsc pomiarowych do obliczen relacji czasowych.
     * 
     * @param textBuffer Bufor na dane do wyswietlenia.
     * @param size Rozmiar bufora na dane do wyswietlenia.
     * @param startIn Numer wejscia pomiarowego rozpoczynajacy pomiar relacji czasowej.
     * @param text Komponent GUI ktory podane dane w interfejsie.
     */
    void setLabelTi(touchgfx::Unicode::UnicodeChar *textBuffer, uint16_t size, uint8_t startIn, touchgfx::TextAreaWithOneWildcard *text);

    /**
     * @brief Funkcja ustawiajaca kolor etykiet konfiguracji wejsc pomiarowych do obliczen relacji czasowych.
     * 
     * @param channelState Stan w jakim znjduje sie wejscie pomiarowe.
     * @param label Etykieta, ktorej modyfikowany jest kolor.
     * @param labelStart Etykieta, ktorej modyfikowany jest kolor.
     * @param labelStop Etykieta, ktorej modyfikowany jest kolor.
     */
    void setLabelColorTi(bool channelState, touchgfx::TextArea *label, touchgfx::TextArea *labelStart, touchgfx::TextArea *labelStop);

    /**
     * @brief Funkcja ustawiajaca kolor etykiet z wynikami pomiarow relacji czasowych.
     * 
     * @param channelState Stan w jakim znjduje sie wejscie pomiarowe.
     * @param mean Etykieta, ktorej modyfikowany jest kolor.
     * @param stdDev Etykieta, ktorej modyfikowany jest kolor.
     */
    void setMeasColorTi(bool channelState, touchgfx::TextAreaWithOneWildcard *mean, touchgfx::TextAreaWithOneWildcard *stdDev);

    /**
     * @brief Funkcja ustawiajaca kolor etykiet konfiguracji wejsc pomiarowych w przypadku blednej konfiguracji do obliczen relacji czasowych
     * 
     * @param startIn Numer wejscia pomiarowego rozpoczynajacy pomiar.
     * @param stopIn Numer wejscia pomiarowego konczacy pomiar.
     * @param labelStart Etykieta, ktorej modyfikowany jest kolor.
     * @param labelStop Etykieta, ktorej modyfikowany jest kolor.
     */
    void setErrorColorTi(uint8_t startIn, uint8_t stopIn, touchgfx::TextAreaWithOneWildcard *labelStart, touchgfx::TextAreaWithOneWildcard *labelStop);

    /**
     * @brief Funkcja ustawiajaca etykete odpowiedzialna za prezentacje liczby wykonanych pomiarow w serii.
     * 
     * @param textBufferStart Bufor do przechowywania informacji o wejsciu ktore rozpoczyna pomiar.
     * @param sizeStart Wielkosc bufora.
     * @param textStart Etykieta do wyswietlenia numeru wejscia pomiarowego.
     * @param textBufferStop Bufor do przechowywania informacji o wejsciu ktore konczy pomiar.
     * @param sizeStop Wielkosc bufora.
     * @param textStop Etykieta do wyswietlenia numeru wejscia pomiarowego.
     * @param textBufferSample Bufor na wartosc liczby powtorzen w serii.
     * @param sizeSample Wielkosc bufora.
     * @param textSample Etykieta do wyswietlenia numeru liczby powtorzen w serii.
     * @param Ti Wskaznik na strukture z danymi konfiguracyjnymi relacji czasowej.
     * @param session Wskaznik na strukture z seria pomiarowa.
     */
    void setStampsSampleTi(touchgfx::Unicode::UnicodeChar *textBufferStart, uint16_t sizeStart, touchgfx::TextAreaWithOneWildcard *textStart,
			touchgfx::Unicode::UnicodeChar *textBufferStop, uint16_t sizeStop, touchgfx::TextAreaWithOneWildcard *textStop,
			touchgfx::Unicode::UnicodeChar *textBufferSample, uint16_t sizeSample, touchgfx::TextAreaWithOneWildcard *textSample,
			TimeTi_t *Ti, SessionSetup_t *session);

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
    void setMeanResultTime(MeasValues_t *measure, int *total, int *fraction1, int *fraction2, touchgfx::Unicode::UnicodeChar *textMeanBuffer,
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
    void setStdDevResultTime(touchgfx::Unicode::UnicodeChar *textStdDevBuffer, uint16_t sizeStdDev, touchgfx::TextAreaWithOneWildcard *textStdDev,
			touchgfx::Unicode::UnicodeChar *textUnitStdDevBuffer, uint16_t sizeUnitStdDev, touchgfx::TextAreaWithOneWildcard *textUnitStdDev,
			MeasValues_t *measure, int *total, int *fraction);
private:
    std::string ps;
    std::string ns;
    std::string us;
    std::string ms;
    std::string sec;
    int m_total_ti1;
    int m_frac1_ti1;
    int m_frac2_ti1;
    int m_total_ti2;
    int m_frac1_ti2;
    int m_frac2_ti2;
    int m_total_ti3;
    int m_frac1_ti3;
    int m_frac2_ti3;
    int m_total_ti4;
    int m_frac1_ti4;
    int m_frac2_ti4;
    int m_total_ti5;
    int m_frac1_ti5;
    int m_frac2_ti5;
    int m_total_ti6;
    int m_frac1_ti6;
    int m_frac2_ti6;
    int m_total_ti7;
    int m_frac1_ti7;
    int m_frac2_ti7;
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
};

#endif // TIMEMODEVIEW_HPP
