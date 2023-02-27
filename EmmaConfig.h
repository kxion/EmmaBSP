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
#define EMMA_BSP_VERISON                "v3.2"
#define EMMA_PROJECT_NAME               "Emma"


/* Enable module Button */
/* Add your own button in "Button/EmmaButton.hpp" */
#define EMMA_MODULE_BUTTON              1
#if EMMA_MODULE_BUTTON
    #define EMMA_BTN_A_PIN              9
    #define EMMA_BTN_B_PIN              0
    #define EMMA_BTN_C_PIN              -1
#endif


/* Enable module RGB led */
/* Require: https://github.com/FastLED/FastLED.git */
#define EMMA_MODULE_RGB_LED             1
#if EMMA_MODULE_RGB_LED
    #define EMMA_RGBLED_PIN             14
    #define EMMA_RGBLED_NUM             1
#endif


/* Enable module Buzzer */
#define EMMA_MODULE_BUZZER              0
#if EMMA_MODULE_BUZZER
    #define EMMA_BUZZER_PIN             2
    #define EMMA_BUZZER_MELODY          1
    #define EMMA_BUZZER_MELODY_MSG      1
    #define EMMA_BUZZER_MELODY_MUSIC    1
#endif


/* Enable module Mic */
#define EMMA_MODULE_MIC_PDM             0
#if EMMA_MODULE_MIC_PDM
    #define EMMA_MICPDM_CLK_PIN         0
    #define EMMA_MICPDM_DATA_PIN        34
    #define EMMA_MICPDM_I2S_PORT        I2S_NUM_0
#endif


/* Enable module Display */
/* Using https://github.com/lovyan03/LovyanGFX as GFX lib */
#define EMMA_MODULE_DISPLAY             1
#if EMMA_MODULE_DISPLAY
    /* Use auto detect if supported */
    // #define LGFX_AUTODETECT
    /* If not, setup your own config in Display/EmmaDisplay.hpp */
#endif

