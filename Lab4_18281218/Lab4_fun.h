//
// Created by 王子龙 on 2019-04-03.
// Email: wangzilong0201@gmail.com
//
#include "Lab4_data.h"

#ifndef LAB4_18281218_LAB4_FUN_H
#define LAB4_18281218_LAB4_FUN_H

void initializationConfig(CONF* userConfig);
int isNumber(char* str);
int isPathandName(char* str, CONF* userConfig);
void dividePathandname(char* str, CONF* userConfig);
int isType(char* str, CONF* userConfig);
int work(CONF* userConfig);
int dataReInput(CONF* userConfig);
int makeFile(CONF* userConfig, DATAITEM* item);
int getRandom(int min, int max);
void makeData(CONF* userConfig, DATAITEM* item);

#endif //LAB4_18281218_LAB4_FUN_H