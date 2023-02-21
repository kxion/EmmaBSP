/**
 * @file EmmaMicPDM.hpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "../EmmaConfig.h"
#if EMMA_MODULE_MIC_PDM
#include "I2S/I2SSampler.h"


class EmmaMicPDM {
    private:
    public:
        EmmaMicPDM(uint8_t i2sPort, int clkPin, int dataPin)
        {
            // Set the I2S configuration as PDM and 16bits per sample
            i2s_config_t i2s_config = {
                .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_PDM),
                .sample_rate = 44100,
                .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
                .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
                .communication_format = I2S_COMM_FORMAT_STAND_I2S,
                .intr_alloc_flags = ESP_INTR_FLAG_LEVEL2,
                .dma_buf_count = 8,
                .dma_buf_len = 200,
                .use_apll = 0,
            };

            // Set the pinout configuration (set using menuconfig)
            i2s_pin_config_t pin_config = {
                .mck_io_num = I2S_PIN_NO_CHANGE,
                .bck_io_num = I2S_PIN_NO_CHANGE,
                .ws_io_num = clkPin,
                .data_out_num = I2S_PIN_NO_CHANGE,
                .data_in_num = dataPin,
            };

            
        }
        ~EmmaMicPDM() {}



        
};




#endif
