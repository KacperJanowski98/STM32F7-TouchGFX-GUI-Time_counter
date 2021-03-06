#ifndef TIMEMODECONFIGVIEW_HPP
#define TIMEMODECONFIGVIEW_HPP

#include <gui_generated/timemodeconfig_screen/TimeModeConfigViewBase.hpp>
#include <gui/timemodeconfig_screen/TimeModeConfigPresenter.hpp>
#include <gui/lib/TimeModeParameter.hpp>
#include <gui/lib/SessionSetup.hpp>
#include <gui/model/Model.hpp>

class TimeModeConfigView : public TimeModeConfigViewBase
{
public:
    TimeModeConfigView();
    virtual ~TimeModeConfigView() {}
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
     * @brief Funkcja aktualizujaca element w scroll wheel na podstawie indeksu.
     * 
     * @param item Element w scroll wheel. 
     * @param itemIndex Indeks elementu.
     */
    virtual void scrollWheelTISetupUpdateItem(ChannelContainer& item, int16_t itemIndex);
    /**
     * @brief Funkcja aktualizujaca glowny element scroll wheel na podstawie indeksu.
     * 
     * @param item Element w scroll wheel.
     * @param itemIndex Indeks elementu.
     */
    virtual void scrollWheelTISetupUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex);

    /**
     * @brief Funkcja aktualizujaca element w scroll wheel na podstawie indeksu.
     * 
     * @param item Element w scroll wheel. 
     * @param itemIndex Indeks elementu.
     */
    virtual void scrollWheelStartUpdateItem(ChannelContainer& item, int16_t itemIndex);
    /**
     * @brief Funkcja aktualizujaca glowny element scroll wheel na podstawie indeksu.
     * 
     * @param item Element w scroll wheel.
     * @param itemIndex Indeks elementu.
     */
    virtual void scrollWheelStartUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex);

    /**
     * @brief Funkcja aktualizujaca element w scroll wheel na podstawie indeksu.
     * 
     * @param item Element w scroll wheel. 
     * @param itemIndex Indeks elementu.
     */
    virtual void scrollWheelStopUpdateItem(ChannelContainer& item, int16_t itemIndex);
    /**
     * @brief Funkcja aktualizujaca glowny element scroll wheel na podstawie indeksu.
     * 
     * @param item Element w scroll wheel.
     * @param itemIndex Indeks elementu.
     */
    virtual void scrollWheelStopUpdateCenterItem(ChannelContainerCenter& item, int16_t itemIndex);

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku toggle button, ustawia stan kana??u.
     * 
     */
    virtual void ChangeChannelState();
    
    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku toggle button dla TI MAX RANGE.
     */
    virtual void turnTiMaxRange();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Single ktora konczy konfiguracje.
     */
    virtual void FinishSetupTimeModeSingle();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Continuous ktora konczy konfiguracje.
     */
    virtual void FinishSetupTimeModeConst();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Stamps ktora konczy konfiguracje.
     */
    virtual void FinishSetupTimeModeStamps();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku Repeat ktora konczy konfiguracje.
     */
    virtual void FinishSetupTimeModeRepeat();

    /**
     * @brief Funkcja wykonujaca sie po nacisnieciu przycisku toggle button, ustawia stan odcinka czasowego.
     *
     */
    virtual void ChangeStateTI();

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
    virtual void AddRange();

    /**
     * @brief Funkcja zmniejszajaca ustawiona zakresu pomiarowego o jeden.
     * 
     */
    virtual void OddRange();

    /**
     * @brief Funkcja zwiekszajaca ustawiona liczbe powtorzen serii pomiarowych o jeden.
     * 
     */
    virtual void AddRepeat();

    /**
     * @brief Funkcja zmniejszajaca ustawiona liczbe powtorzen serii pomiarowych o jeden.
     * 
     */
    virtual void OddRepeat();

    /**
     * @brief Funkcja zwiekszajaca ustawiona wartosc liczby pomiarow w serii o jeden.
     * 
     */
    virtual void AddStamps();

    /**
     * @brief Funkcja zmniejszajaca ustawiona wartosc liczby pomiarow w serii o jeden.
     * 
     */
    virtual void OddStamps();

    /**
     * @brief Funkcja ustawiajaca elementy konfiguracji w UI okreslonego kanalu.
     *
     * @param channel Obiekt kanalu.
     */
    void initUIChannel(std::shared_ptr<TimeModeParameter>& channel);
    /**
     * @brief Funkcja blokujaca elemnty ekranu.
     * 
     * @param state True elementy odblokowane, false elementy zablokowona.
     */
    void setGuiTouchable(bool state);
    /**
     * @brief Funkcja zwracajaca numer wybranego kanalu do konfiguracji.
     * 
     * @return uint16_t Numer kanalu.
     */
    uint16_t getCurrentChannel();
    /**
     * @brief Funkcja ustawiajaca stan okreslonego kanalu.
     * 
     * @param channel Obiekt kanalu.
     * @param state True oznacza stan ON, false stan OFF.
     */
    void setChannelStateUI(std::shared_ptr<TimeModeParameter>& channel, bool state);

    /**
     * @brief Funkcja ustawiajaca stan okreslonego odcinka czasowego.
     *
     * @param channel Obiekt kanalu.
     * @param state True oznacza stan ON, false stan OFF.
     */
    void setTiChannelStateUI(std::shared_ptr<TimeModeParameter>& channel, bool state);
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
    void setSlopeUI(std::shared_ptr<TimeModeParameter>& channel, SlopeName slopeUi);
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
    void setThresholdUI(std::shared_ptr<TimeModeParameter>& channel, uint32_t value);

    /**
     * @brief Funkcja ustawiajaca wartosc zakresu pomiarowego w obikcie klasy sesji pomiarowej.
     * 
     * @param session Obiekt sesji pomiarowa.
     * @param value Wartosc do ustawienia.
     */
    void setRangeUI(std::shared_ptr<SessionSetup>& session, uint16_t value);

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
     * @brief Ustawienie elementow UI na podstawie stanu kanalu.
     * 
     * @param stateChannel Stan kanalu odczytany z obiekti kanalu.
     */
    void readStateChannel(bool stateChannel);
    /**
     * @brief Funckja tworzaca wektor aktywny kanalow.
     * 
     * @param channel Numer kanalu.
     * @param chanelState Stan sprawdzanego stanu.
     */
    void setActiveListChannels(int16_t channel, bool chanelState);
    /**
     * @brief Funkcja aktualizujaca elementy UI w panelu konfiguracji TI setup.
     * 
     */
    void updateScrollTiSetup();
    /**
     * @brief Funkcja aktualizujaca elementu UI na podstawie obiektu kanalu, panelu TI setup, elementy START IN, STOP IN.
     * 
     * @param channel Obiekt kanalu.
     */
    void updateStartStopIn(std::shared_ptr<TimeModeParameter>& channel);
    
    /**
     * @brief Aktualizacja ustwien wejsc pomiarowych w konfiguracji relacji czasowych.
     * 
     */
    void updateTiSetupScreen();

    /**
     * @brief Funkcja aktualizujaca elementu UI na podstawie obiektu kanalu, panelu TI setup, elementy scroll wheel start i stop.
     *
     * @param channel Obiekt kanalu.
     */
    void updateStartStopScroolList(std::shared_ptr<TimeModeParameter>& channel);

    /**
     * @brief Funkcja aktualizujaca elementu UI panelu konfiguracji zegara na podstawie zmiennej.
     *
     * @param ClockName Nazwa zrodla zegarowego.
     */
    void updateClockSourceUI(ClockName clk);

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
    void updateTimeParameterBackend();

    /**
     * @brief Ustawienie wartosci odczytanej ze slidera odpowiedzialnego za ustawienie progu wyzwalania.
     * 
     * @param value Wartosc progu wyzwalania.
     */
    void setValueSliderThresholdUI(int value);

    /**
     * @brief Ustawienie wartosci odczytanej ze slidera odpowiedzialnego za ustawienie zakresu pomiarowego.
     * 
     * @param value Wartosc zakresu pomiarowego.
     */
    void setValueSliderRange(int value);

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
     * @brief Ustawienie wartosci odpowiedzialnych za konfiguracje wejsc pomiarowych w strukturze wymiany danych.
     * 
     * @param pChannelBack Podstruktura na dane konfiguracyje ze struktury wymiany danych.
     * @param pChannel Obiekt klasy odpwoiedzialnej za konfiguracje danego wejscia pomiarowego.
     */
    void updateChannelBackendStruct(TimeChannel_t *pChannelBack, std::shared_ptr<TimeModeParameter> pChannel);

    /**
     * @brief Ustawienie wartosci odpowiedzialnych za konfiguracje relacji czasowych w strukturze wymiany danych.
     * 
     * @param pTiBack Podstruktura na dane konfiguracyje ze struktury wymiany danych.
     * @param pTi Obiekt klasy odpwoiedzialnej za konfiguracje danej relacji czasowej.
     */
    void updateTiBackendStruct(TimeTi_t *pTiBack, std::shared_ptr<TimeModeParameter> pTi);

    /**
     * @brief Ustawienie wartosci odpowiedzialnych za konfiguracje sesji pomiarowej w strukturze wymiany danych.
     * 
     * @param pSessionBack Podstruktura na dane konfiguracyje ze struktury wymiany danych.
     * @param pSession Obiekt klasy odpwoiedzialnej za konfiguracje sesji pomiarowej.
     */
    void updateSessionBackendStruct(SessionSetup_t *pSessionBack, std::shared_ptr<SessionSetup> pSession);

protected:
    /**
     * @brief Wywo??anie zwrotne, kt??re jest wykonywane, gdy element w scroll wheel jest zmieniony
     * 
     */
    Callback<TimeModeConfigView, int16_t> scrollWheelINPUTAnimateToCallback;
    /**
     * @brief Funkcja obslugujaca wunkcje wywolujaca scrollWheelINPUTAnimateToCallback.
     * 
     * @param itemSelected Indeks wybranego elementu z scroll wheel.
     */
    void scrollWheelINPUTAnimateToHandler(int16_t itemSelected);

    /**
     * @brief Wywo??anie zwrotne, kt??re jest wykonywane, gdy element w scroll wheel jest zmieniony
     * 
     */
    Callback<TimeModeConfigView, int16_t> scrollWheelTISetupAnimateToCallback;
    /**
     * @brief Funkcja obslugujaca wunkcje wywolujaca scrollWheelTISetupAnimateToCallback.
     * 
     * @param itemSelected Indeks wybranego elementu z scroll wheel.
     */
    void scrollWheelTISetupAnimateToHandler(int16_t itemSelected);

    /**
     * @brief Wywo??anie zwrotne, kt??re jest wykonywane, gdy element w scroll wheel jest zmieniony
     * 
     */
    Callback<TimeModeConfigView, int16_t> scrollWheelStartAnimateToCallback;
    /**
     * @brief Funkcja obslugujaca wunkcje wywolujaca scrollWheelStartAnimateToCallback.
     * 
     * @param itemSelected Indeks wybranego elementu z scroll wheel.
     */
    void scrollWheelStartAnimateToHandler(int16_t itemSelected);

    /**
     * @brief Wywo??anie zwrotne, kt??re jest wykonywane, gdy element w scroll wheel jest zmieniony
     * 
     */
    Callback<TimeModeConfigView, int16_t> scrollWheelStopAnimateToCallback;
    /**
     * @brief Funkcja obslugujaca wunkcje wywolujaca scrollWheelStopAnimateToCallback.
     * 
     * @param itemSelected Indeks wybranego elementu z scroll wheel.
     */
    void scrollWheelStopAnimateToHandler(int16_t itemSelected);

    // Deklaracja wywolywan zwrotnych.
    touchgfx::Callback<TimeModeConfigView, const touchgfx::Slider&, int> sliderValueStartedChangeCallback;
    touchgfx::Callback<TimeModeConfigView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<TimeModeConfigView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;

    touchgfx::Callback<TimeModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupSlopeCallback;
    touchgfx::Callback<TimeModeConfigView, const touchgfx::AbstractButton&> RadioBtnGroupClockCallback;

    // Deklaracje obs??ugi wywo??a?? zwrotnych.
    void sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
    void RadioBtnGroupSlopeCallbackHandler(const touchgfx::AbstractButton& src);
    void RadioBtnGroupClockCallbackHandler(const touchgfx::AbstractButton& src);
private:
    TimeModeParameter Channel1 , Channel2, Channel3, Channel4, Channel5, Channel6, Channel7, Channel8;

    SessionSetup Session;

    std::shared_ptr<SessionSetup> pSession;

    std::shared_ptr<TimeModeParameter> pChannel1;
    std::shared_ptr<TimeModeParameter> pChannel2;
    std::shared_ptr<TimeModeParameter> pChannel3;
    std::shared_ptr<TimeModeParameter> pChannel4;
    std::shared_ptr<TimeModeParameter> pChannel5;
    std::shared_ptr<TimeModeParameter> pChannel6;
    std::shared_ptr<TimeModeParameter> pChannel7;
    std::shared_ptr<TimeModeParameter> pChannel8;

    int16_t m_channelInput;
    std::shared_ptr<TimeModeParameter> pChannelInput;
    std::shared_ptr<TimeModeParameter> pChannelTI;
    int16_t m_channelTiSetup;
    int16_t m_channelTiSetupStart;
    int16_t m_channelTiSetupStop;
    int32_t m_newThreshold;
    int16_t m_newRange;
    int16_t m_newRepeat;
    int16_t m_newStamps;

    std::vector<int16_t> activeChannels;
};

#endif // TIMEMODECONFIGVIEW_HPP
