/**
 * @file EmmaBSP.h
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Arduino.h"
#include <iostream>
#include <string>
using namespace std;


/* Configs */
#define BSP_VERISON             "v2.0"
/* GPIO map */
#define EMMA_PIN_BUZZER         46
#define EMMA_PIN_RGB_LED        1
#define EMMA_PIN_EC_BTN         2
#define EMMA_PIN_EC_A           18
#define EMMA_PIN_EC_B           3
#define EMMA_PIN_LCD_RST        17
#define EMMA_PIN_LCD_SDA        15
#define EMMA_PIN_LCD_SCL        13
#define EMMA_PIN_LCD_CS         21
#define EMMA_PIN_LCD_DC         16
#define EMMA_PIN_LCD_BL         14
/* ANSI colors */
#define ANSI_BLACK              30
#define ANSI_RED                31
#define ANSI_GREEN              32
#define ANSI_YELLOW             33
#define ANSI_BLUE               34
#define ANSI_MAGENTA            35
#define ANSI_CYAN               36
#define ANSI_WHITE              37



/**
 * @brief Class of Emma bsp
 * 
 */
class EMMA {
    private:
        
    public:
        const string EmmaLogo = R"(
 ______  __    __  __    __  ______
/\  ___\/\ "-./  \/\ "-./  \/\  __ \
\ \  __\\ \ \-./\ \ \ \-./\ \ \  __ \
 \ \_____\ \_\ \ \_\ \_\ \ \_\ \_\ \_\
  \/_____/\/_/  \/_/\/_/  \/_/\/_/\/_/
)";
        const string Cow = R"(
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
)";
        /**
         * @brief Public methods
         * 
         */
        void Init(bool enLcd = true, bool enEncoder = true, bool enLedRGB = true, bool enBuzzer = true);
        void PrintBoardInfo(bool printOnLcd = true);
        string Cowsay(string whatCowSay, int ANSIcolor = 0);

};

