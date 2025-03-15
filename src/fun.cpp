// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false; 
    bool hasDigit = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            if (inWord && !hasDigit) {
                ++count;
            }
            inWord = false;
            hasDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
            }
            if (str[i] >= '0' && str[i] <= '9') {
                hasDigit = true;
            }
        }
    }

    if (inWord && !hasDigit) {
        ++count;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    return 0;
}

unsigned int faStr3(const char *str) {
    return 0;
}
