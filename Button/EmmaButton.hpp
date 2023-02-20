/**
 * @file EmmaButton.hpp
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
#include "Button/Button.h"
#if EMMA_MODULE_BUTTON

#define Button_Add(name, pin) __Button name = __Button(pin)

/* Wrap of button */
class EmmaButton {
    private:
    public:
    
        /* Add your button here */
        Button_Add(A, EMMA_BTN_A_PIN);
        Button_Add(B, EMMA_BTN_B_PIN);
        Button_Add(C, EMMA_BTN_C_PIN);

};

#endif
