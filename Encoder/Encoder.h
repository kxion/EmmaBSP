/**
 * @file Encoder.h
 * @author Forairaaaaa 
 * @brief Encoder driver by using GPIO lib
 * @version 0.1
 * @date 2022-12-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Button/Button.h"


class Encoder {
    private:
        int _pinA;
        int _pinB;
        int _pinBTN;
        bool _enPullup;
        bool _reverse;
        TaskHandle_t _ecTaskHandle;
        unsigned int _ecTaskPriority;
    public:
        Button Btn;

        Encoder();
        ~Encoder();
        void Init(int pinA = -1, int pinB = -1, int pinBTN = -1);
        void Uninit();
        int GetDirection();
        int GetPosition();
};





