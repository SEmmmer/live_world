//
// Created by Emmmer Shirakami on 2020/11/18.
//
#include <iostream>
#include <stdlib.h>
#include <time.h>

bool if_critical(double critical_rate) {
    srand(static_cast<unsigned int>(time(nullptr)));
    return (rand() / static_cast<double>(RAND_MAX) <= critical_rate);
}