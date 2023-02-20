/**
 * @file EmmaConfig.h
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once


/* Common configs */
#define EMMA_BSP_VERISON                "v3.0"
#define EMMA_PROJECT_NAME               "Emma"


/* Enable module Button */
/* Add your own button in "Button/EmmaButton.hpp" */
#define EMMA_MODULE_BUTTON              1
#if EMMA_MODULE_BUTTON
    #define EMMA_BTN_A_PIN              39
    #define EMMA_BTN_B_PIN              38
    #define EMMA_BTN_C_PIN              37
#endif


/* Enable module RGB led */
/* Require: https://github.com/FastLED/FastLED.git */
#define EMMA_MODULE_RGB_LED             1
#if EMMA_MODULE_RGB_LED
    #define EMMA_RGBLED_PIN             15
    #define EMMA_RGBLED_NUM             10
    #define EMMA_RGBLED_INIT_TEST       1
#endif


/* Enable module buzzer */
#define EMMA_MODULE_BUZZER              0
#if EMMA_MODULE_BUZZER
    #define EMMA_BUZZER_PIN             2
    #define EMMA_BUZZER_MELODY          1
    #define EMMA_BUZZER_MELODY_MSG      1
    #define EMMA_BUZZER_MELODY_MUSIC    1
#endif

