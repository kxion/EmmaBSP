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
#include "driver/i2s.h"


class EmmaMicPDM {
    private:
        uint8_t __i2s_port;
        uint16_t __data;
        size_t __bytes_read;

    public:
        EmmaMicPDM(uint8_t i2sPort, int clkPin, int dataPin)
        {
            __i2s_port = i2sPort;
            
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

            // Call driver installation function before any I2S R/W operation.
            ESP_ERROR_CHECK( i2s_driver_install((i2s_port_t)__i2s_port, &i2s_config, 0, NULL) );
            ESP_ERROR_CHECK( i2s_set_pin((i2s_port_t)__i2s_port, &pin_config) );
            ESP_ERROR_CHECK( i2s_set_clk((i2s_port_t)__i2s_port, 44100, I2S_BITS_PER_SAMPLE_16BIT, I2S_CHANNEL_MONO) );
        }
        ~EmmaMicPDM() {}


        int16_t read()
        {
            i2s_read((i2s_port_t)__i2s_port, (void*)&__data, sizeof(__data), &__bytes_read, 100);
            return __data;
        }


        inline esp_err_t readBuffer(void* buffer, size_t bufferSize, size_t* bytesRead, TickType_t ticks2Wait)
        {
            return i2s_read((i2s_port_t)__i2s_port, buffer, bufferSize, bytesRead, ticks2Wait);
        }
        
};




#endif
