// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cmath>

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
    unsigned int count = 0;
    bool inWord = false;
    bool isValidWord = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            if (inWord && isValidWord) {
                ++count;
            }
            inWord = false;
            isValidWord = false;
        } else {
            if (!inWord) {
                inWord = true;
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    isValidWord = true;
                } else {
                    isValidWord = false;
                }
            } else {
                if (!(str[i] >= 'a' && str[i] <= 'z')) {
                    isValidWord = false;
                }
            }
        }
    }

    if (inWord && isValidWord) {
        ++count;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            if (inWord) {
                ++wordCount;
                inWord = false;
            }
        } else {
            if (!inWord) {
                inWord = true;
            }
            ++totalLength;
        }
    }

    if (inWord) {
        ++wordCount;
    }

    if (wordCount == 0) {
        return 0;
    }
    double averageLength = static_cast<double>(totalLength) / wordCount;

    return static_cast<unsigned int>(std::round(averageLength));
}
