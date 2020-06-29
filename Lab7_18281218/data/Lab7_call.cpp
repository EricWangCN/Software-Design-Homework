//
// Created by 王子龙 on 2019-06-01.
//
#include "Lab7_call.h"
#include "../Lab7_data.h"
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <string>

int makeDataFile() {
    int num;
    char command[MAX_STR_LEN] = "./Lab4.out D ";
    char String_num[MAX_STR_LEN];

    printf("Please input command:(not more than 100)");
    scanf("%d", &num);


    sprintf(String_num, "%d", num);
    strcat(command, String_num);
    system(command);

    return num;
}