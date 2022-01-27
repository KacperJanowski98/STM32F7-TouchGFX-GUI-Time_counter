#ifndef MODEL_HPP
#define MODEL_HPP

#include <gui/lib/TimeModeParameter.hpp>
#include <memory>
#include <cstdint>
#include <algorithm>
#include <vector>
#include "main.h"
#include "cmsis_os.h"
#include "cmsis_os2.h"

extern DataExchange_t DataExchange;

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    /**
     * @brief Funkcja uruchamiajaca zadanie symulatora dla pojedynczego pomiaru relacji czasowej (uzupelnienie struktury wymiany danch).
     * 
     */
    void getDataTimeSingle();

    /**
     * @brief Funkcja uruchamiajaca zadanie symulatora dla pojedynczego pomiaru czestotliwosci (uzupelnienie struktury wymiany danch).
     * 
     */
    void getDataFreqSingle();

    /**
     * @brief Funkcja uruchamiajaca zadanie symulatora dla ciaglego pomiaru relacji czasowej (uzupelnienie struktury wymiany danch).
     * 
     */
    void getDataTimeContinuous();

    /**
     * @brief Funkcja uruchamiajaca zadanie symulatora dla ciaglego pomiaru czestotliwosci (uzupelnienie struktury wymiany danch).
     * 
     */
    void getDataFreqContinuous();

    /**
     * @brief Funkcja uruchamiajaca zadanie symulatora dla pomiaru serii wykonujaca okreslona liczbe pomiarow w trybie pomiaru relacji czasowej (uzupelnienie struktury wymiany danch).
     * 
     */
    void getDataTimeStamps();

    /**
     * @brief Funkcja uruchamiajaca zadanie symulatora dla pomiaru serii wykonujaca okreslona liczbe pomiarow w trybie pomiaru czestotliwosci (uzupelnienie struktury wymiany danch).
     * 
     */
    void getDataFreqStamps();

    /**
     * @brief Funkcja uruchamiajaca zadanie symulatora dla pomiaru okreslonej liczby serii wykonujaca okreslona liczbe pomiarow w trybie pomiaru relacji czasowej (uzupelnienie struktury wymiany danch).
     * 
     */
    void getDataTimeRepeat();

    /**
     * @brief Funkcja uruchamiajaca zadanie symulatora dla pomiaru okreslonej serii serii wykonujaca okreslona liczbe pomiarow w trybie pomiaru czestotliwosci (uzupelnienie struktury wymiany danch).
     * 
     */
    void getDataFreqRepeat();

    /**
     * @brief Funkcja uruchamiajaca zadanie systemu operacyjnego odpowiedzialne za reset paremetrow konfiguracyjnych i pomiarowych pomiar relacji czasowych w strukturze wymiany danych.
     * 
     */
    void getResetTime();

    /**
     * @brief Funkcja uruchamiajaca zadanie systemu operacyjnego odpowiedzialne za reset paremetrow konfiguracyjnych i pomiarowych pomiar czestotliwosci w strukturze wymiany danych.
     * 
     */
    void getResetFreq();

    /**
     * @brief Pobranie wartosci progu wyzwalania w trybie pomiaru relacji czasowych.
     * 
     */
    void getDetectedTimeThreshold();

    /**
     * @brief Pobranie wartosci progu wyzwalania w trybie pomiaru czestotliwosci.
     * 
     */
    void getDetectedFreqThreshold();

    /**
     * @brief Funkcja odpowiedzialna za odswezenie ekranu z wynikami pomiarow relacji czasowych, pobranie wartosci ze struktury wymiany danych.
     * 
     */
    void updateScreenContinuousTimeMode();

    /**
     * @brief Funkcja odpowiedzialna za odswezenie ekranu z wynikami pomiarow czestotliwosci, pobranie wartosci ze struktury wymiany danych.
     * 
     */
    void updateScreenContinuousFreqMode();

    /**
     * @brief Funkcja odpowiedzialna za uruchomienie kalibracji w symulatorze/liczniku.
     * 
     */
    void getCalibration();
protected:
    ModelListener* modelListener;
    int counterT{0};
    int counterF{0};
};

#endif // MODEL_HPP
