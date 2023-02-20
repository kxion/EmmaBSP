/**
 * @file EmmaRGBLED.hpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "../EmmaConfig.h"
#if EMMA_MODULE_RGB_LED
#include <FastLED.h>
#include "esp32-hal-log.h"


#define TAG_RGBLED "RGBLED"


class EmmaRGBLED
{
    private:
        uint8_t __led_pin;
        uint8_t __led_num;
        
    public:
        CRGB* leds;

        EmmaRGBLED(): __led_pin(EMMA_RGBLED_PIN), __led_num(EMMA_RGBLED_NUM) {}
        ~EmmaRGBLED() { free(leds); }

        /**
         * @brief Init RGB led with FastLed
         * 
         */
        void init()
        {
            ESP_LOGI(TAG_RGBLED, "init...");

            leds = (CRGB*)malloc(sizeof(CRGB) * EMMA_RGBLED_NUM);
            if (leds == NULL) {
                ESP_LOGE(TAG_RGBLED, "malloc failed!");
                while (1);
            }

            FastLED.addLeds<SK6812, EMMA_RGBLED_PIN, GRB>(leds, EMMA_RGBLED_NUM);
            ESP_LOGI(TAG_RGBLED, "success!");

            #if EMMA_RGBLED_INIT_TEST
            FastLED.showColor(CRGB::Red);
            delay(150);
            FastLED.showColor(CRGB::Green);
            delay(150);
            FastLED.showColor(CRGB::Blue);
            delay(150);
            FastLED.clear(true);
            #endif
        }
};

#endif
