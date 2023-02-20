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
#define EMMA_PROJECT_NAME               "Bricky"


/* Enable module RGB led */
#define EMMA_MODULE_RGB_LED             1
#if EMMA_MODULE_RGB_LED
    #define EMMA_RGBLED_PIN             21
    #define EMMA_RGBLED_NUM             1
#endif


/* Enable module buzzer */
#define EMMA_MODULE_BUZZER              1
#if EMMA_MODULE_BUZZER
    #define EMMA_BUZZER_PIN             0
    #define EMMA_BUZZER_MELOD           1
    #define EMMA_BUZZER_MELODY_MSG      1
    #define EMMA_BUZZER_MELODY_MUSIC    1
#endif

