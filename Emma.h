/**
 * @file Emma.h
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <Arduino.h>
#include <iostream>
#include <string>

#include "Button/EmmaButton.hpp"
#include "RGBLED/EmmaRGBLED.hpp"
#include "Buzzer/EmmaBuzzer.hpp"


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
 * @brief Emma BSP
 * 
 */
class EMMA {
    private:
        void load_modules();
        
    public:
        const std::string Logo = R"(
 ______  __    __  __    __  ______
/\  ___\/\ "-./  \/\ "-./  \/\  __ \
\ \  __\\ \ \-./\ \ \ \-./\ \ \  __ \
 \ \_____\ \_\ \ \_\ \_\ \ \_\ \_\ \_\
  \/_____/\/_/  \/_/\/_/  \/_/\/_/\/_/
)";
        const std::string Cow = R"(
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
)";

        /* Module Button */
        #if EMMA_MODULE_BUTTON
        EmmaButton Button;
        #endif

        /* Module RGBLED */
        #if EMMA_MODULE_RGB_LED
        EmmaRGBLED Led;
        #endif

        /* Module buzzer */
        #if EMMA_MODULE_BUZZER
        EmmaBuzzer Buzzer;
        #endif

        /**
         * @brief BSP init
         * 
         */
        void init();


        /**
         * @brief Print out board infos
         * 
         */
        void printBspInfos();
        

        /**
         * @brief Listen to the cow
         * 
         * @param whatCowSay 
         * @param ANSIcolor e.g. ANSI_BLUE
         * @return string that cow want to say
         */
        std::string Cowsay(std::string whatCowSay, int ANSIcolor = 0);


};

