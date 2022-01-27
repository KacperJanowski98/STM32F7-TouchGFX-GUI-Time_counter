#ifndef FREQMODECONFIGVIEW_HPP
#define FREQMODECONFIGVIEW_HPP

#include <gui_generated/freqmodeconfig_screen/FreqModeConfigViewBase.hpp>
#include <gui/freqmodeconfig_screen/FreqModeConfigPresenter.hpp>
#include <gui/lib/SessionSetup.hpp>
#include <gui/lib/FreqModeParameter.hpp>

class FreqModeConfigView : public FreqModeConfigViewBase
{
public:
    FreqModeConfigView();
    virtual ~FreqModeConfigView() {}
    /**
     * @brief Funkcja wykonujaca sie na poczatku uruchomienia ekranu.
     * 
     */
    virtual void setupScreen();
    /**
     * @brief Funkcja wykonujaca sie na zakonczenie dzialania ekranu.
     * 
     */
    virtual void tearDownScreen();

    /**
     * @brief Funkcja aktualizujaca element w scroll wheel na podstawie indeksu.
     * 
     * @param item Element w scroll wheel. 
     * @param itemIndex Indeks elementu.
     */
    virtual void scrollWheelINPUTUpdateItem(ChannelContainer& item, int16_t itemIndex);

    /**
     * @brief Funkcja aktualizujaca glowny element scroll wheel na podstawie indeksu.
     * 
     * @param item Element w scroll wheel.
     * @param itemIndex Indeks elementu.
     */
    virtual void scrollWheelINPUTUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex);

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Single ktora konczy konfiguracje.
     */
    virtual void FinishSetupFreqModeSingle();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Continuous ktora konczy konfiguracje.
     */
    virtual void FinishSetupFreqModeConst();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Stamps ktora konczy konfiguracje.
     */
    virtual void FinishSetupFreqModeStamps();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Repeat ktora konczy konfiguracje.
     */
    virtual void FinishSetupFreqModeRepeat();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku toggle button, ustawia stan kanału.
     * 
     */
    virtual void toggleChannelState();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Detect, ustawia wykryta wartosc zbocza wyzwalania.
     *
     */
    virtual void detectThreshold();

    /**
     * @brief Funkcja zwiekszajaca ustawiona wartosc progu wyzwalania o jeden.
     * 
     */
    virtual void AddThreshold();

    /**
     * @brief Funkcja zmniejszajaca ustawiona wartosc progu wyzwalania o jeden.
     * 
     */
    virtual void OddThreshold();

    /**
     * @brief Funkcja zwiekszajaca ustawiona wartosc zakresu pomiarowego o jeden.
     * 
     */
    virtual void AddRepeat();

    /**
     * @brief Funkcja zmniejszajaca ustawiona zakresu pomiarowego o jeden.
     * 
     */
    virtual void OddRepeat();

    /**
     * @brief Funkcja zwiekszajaca ustawiona liczbe powtorzen serii pomiarowych o jeden.
     * 
     */
    virtual void AddStamps();

    /**
     * @brief Funkcja zmniejszajaca ustawiona liczbe powtorzen serii pomiarowych o jeden.
     * 
     */
    virtual void OddStamps();

    /**
     * @brief Funkcja zwiekszajaca ustawiona wartosc liczby pomiarow w serii o jeden.
     * 
     */
    virtual void AddGate();

    /**
     * @brief Funkcja zmniejszajaca ustawiona wartosc liczby pomiarow w serii o jeden.
     * 
     */
    virtual void OddGate();

    /**
     * @brief Funkcja ustawiajaca elementy konfiguracji w UI okreslonego kanalu.
     *
     * @param channel Obiekt kanalu.
     */
    void initUIChannel(std::shared_ptr<FreqModeParameter>& channel);

    /**
     * @brief Funkcja blokujaca elemnty ekranu.
     * 
     * @param state True elementy odblokowane, false elementy zablokowona.
     */
    void setGuiTouchable(bool state);

    /**
     * @brief Funkcja ustawiajaca stan okreslonego kanalu.
     * 
     * @param channel Obiekt kanalu.
     * @param state True oznacza stan ON, false stan OFF.
     */
    void setChannelStateUI(std::shared_ptr<FreqModeParameter>& channel, bool state);

    /**
     * @brief Funkcja ustawiajaca odpowiednie zbocze w UI odczytane z obiektu kanalu.
     * 
     * @param slopeUi Zbocze do ustawienia w UI.
     */
    void readSlopeUI(SlopeName slopeUi);

    /**
     * @brief Ustawienie zbocza obiektu kanalu w UI.
     * 
     * @param channel Konfigurowany kanal.
     * @param slopeUi Zbocze.
     */
    void setSlopeUI(std::shared_ptr<FreqModeParameter>& channel, SlopeName slopeUi);

    /**
     * @brief Funkcja ustawiajaca w UI wartosc progu wyzwalania z obiektu kanalu.
     * 
     * @param value Wartosc progu wyzwalania.
     */
    void readThresholdUI(uint32_t value);

    /**
     * @brief Funkcja ustawiajaca wartosc progu wyzwalania w obiekcie kanalu.
     * 
     * @param channel Konfigurowany kanal.
     * @param value Wartosc progu wyzwalania.
     */
    void setThresholdUI(std::shared_ptr<FreqModeParameter>& channel, uint32_t value);

    /**
     * @brief Ustawienie wartosci odczytanej ze slidera odpowiedzialnego za ustawienie progu wyzwalania.
     * 
     * @param value Wartosc progu wyzwalania.
     */
    void setValueSliderThresholdUI(int value);

    /**
     * @brief Ustawienie wartosci odczytanej ze slidera odpowiedzialnego za ustawienie liczby pomiarow w serii pomiarowej.
     * 
     * @param value Liczba pomiarow w serii.
     */    
    void setValueSliderStampsNumberUI(int value);

    /**
     * @brief Ustawienie wartosci odczytanej ze slidera odpowiedzialnego za ustawienie liczby serii pomiarowych.
     * 
     * @param value Liczba serii pomiarowych.
     */    
    void setValueSliderRepeatUI(int value);

    /**
     * @brief SUstawienie wartosci odczytanej ze slidera odpowiedzialnego za ustawienie wartosci bramki konfiguracji pomiaru.
     * 
     * @param value Wartosc bramki.
     */
    void setValueSliderGateUI(int value);

    /**
     * @brief Inicjalizacja elementow UI panelu MESS SETUP
     * 
     */
    void initMesSetupUI();

    /**
     * @brief Funkcja ustawiajaca wartosc serii pomiarowej w obiekcie klasy sesji pomiarowej.
     * 
     * @param session Obiekt sesji pomiarowej. 
     * @param value Wartosc do ustawienia.
     */
    void setStampsUI(std::shared_ptr<SessionSetup>& session, uint16_t value);

    /**
     * @brief Funkcja ustawiajaca wartosc powtorzen serii pomiarowej.
     * 
     * @param session Obiekt sesji pomiarowej.
     * @param value Wartosc do ustawienia.
     */
    void setRepeatUI(std::shared_ptr<SessionSetup>& session, uint16_t value);

    /**
     * @brief Funkcja aktualizujaca elementu UI panelu konfiguracji zegara na podstawie zmiennej.
     *
     * @param ClockName Nazwa zrodla zegarowego.
     */
    void updateClockSourceUI(ClockName clk);

    /**
     * @brief Funkcja aktualizujaca elementy UI panelu konfiguracji ekranu MES SETUP.
     * 
     * @param state Zapisany stan w strukturze wymiany danych.
     */
    void updateMesSetupUI(bool state);

    /**
     * @brief Aktualizacja wartosci ustawianych na ekranie konfiguracji sesji pomiarowej.
     * 
     * @param session Obiekt klasy sesji pomiarowej.
     */
    void updateSessionSetupUI(std::shared_ptr<SessionSetup>& session);

    /**
     * @brief Funkcja odpowiedzialna za przypisanie dokonanej konfiguracji do struktury wymiany danych.
     * 
     */
    void updateFreqParameterBackend();

    /**
     * @brief Ustawienie wartosci odpowiedzialnych za konfiguracje wejsc pomiarowych w strukturze wymiany danych.
     * 
     * @param pChannelBack Podstruktura na dane konfiguracyje ze struktury wymiany danych.
     * @param pChannel Obiekt klasy odpwoiedzialnej za konfiguracje danego wejscia pomiarowego.
     */
    void updateChannelBackendStruct(FreqChannel_t *pChannelBack, std::shared_ptr<FreqModeParameter> pChannel);

    /**
     * @brief Ustawienie wartosci odpowiedzialnych za konfiguracje sesji pomiarowej w strukturze wymiany danych.
     * 
     * @param pSessionBack Podstruktura na dane konfiguracyje ze struktury wymiany danych.
     * @param pSession Obiekt klasy odpwoiedzialnej za konfiguracje sesji pomiarowej.
     */
    void updateSessionBackendStruct(SessionSetup_t *pSessionBack, std::shared_ptr<SessionSetup> pSession);

protected:
    /**
     * @brief Wywołanie zwrotne, które jest wykonywane, gdy element w scroll wheel jest zmieniony
     * 
     */
    Callback<FreqModeConfigView, int16_t> scrollWheelINPUTAnimateToCallback;

    /**
     * @brief Funkcja obslugujaca wunkcje wywolujaca scrollWheelINPUTAnimateToCallback.
     * 
     * @param itemSelected Indeks wybranego elementu z scroll wheel.
     */
    void scrollWheelINPUTAnimateToHandler(int16_t itemSelected);

    // Deklaracja wywolywan zwrotnych.
    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueStartedChangeCallback;
    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<FreqModeConfigView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;

	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupFreqCallback;
	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupHfInputCallback;
	touchgfx::Callback<FreqModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupClockCallback;

    // Deklaracje obsługi wywołań zwrotnych.
    void sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
    void RadioBtnGroupFreqCallbackHandler(const touchgfx::AbstractButton& src);
    void RadioBtnGroupHfInputCallbackHandler(const touchgfx::AbstractButton& src);
    void RadioBtnGroupClockCallbackHandler(const touchgfx::AbstractButton& src);

private:
    FreqModeParameter Channel1 , Channel2, Channel3, Channel4, Channel5, Channel6, Channel7, Channel8;

    SessionSetup Session;

    std::shared_ptr<SessionSetup> pSession;

    std::shared_ptr<FreqModeParameter> pChannel1;
    std::shared_ptr<FreqModeParameter> pChannel2;
    std::shared_ptr<FreqModeParameter> pChannel3;
    std::shared_ptr<FreqModeParameter> pChannel4;
    std::shared_ptr<FreqModeParameter> pChannel5;
    std::shared_ptr<FreqModeParameter> pChannel6;
    std::shared_ptr<FreqModeParameter> pChannel7;
    std::shared_ptr<FreqModeParameter> pChannel8;

    int16_t m_channelInput;
    std::shared_ptr<FreqModeParameter> pChannelInput;

    int32_t m_newThreshold;
    int16_t m_newRepeat;
    int16_t m_newStamps;
    int16_t m_newGate;
	bool m_hfInput;
	uint16_t m_gate;
};

#endif // FREQMODECONFIGVIEW_HPP
