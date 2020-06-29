/*********************************************
 * @filename                                 *
 *      Lab3_fun.cpp                         *
 * @filehistory                              *
 *  Mar.13th, 2019:                          *
 *      Created by Wang Zilong               *
 *          E-mail: wangzilnog0201@gmail.com *
 *  Mar.23th, 0219                           *
 *      Fixed by Wang Zilong                 *
 *          E-mail: wangzilong0201@gmail.com *
 *********************************************/

#include "Lab3_fun.h"
#include "Lab3_data.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sysdir.h>
#include <sys/stat.h>

/******************************************************************
 * @functionname isNumber                                         *
 * @features Judge if a string is consist of numbers('0'~'9')     *
 * @param str                                                     *
 * @return 0: have char which is not a number     1:is all number *
 ******************************************************************/

int isNumber(char str[]) {
    int i = 0;
    if (str[i] == '\0') {
        return 0;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

/************************************************************************
 * @functionname isPathandName                                          *
 * @features To judge if a string is consist of Filepath and its name,  *
 *           then divide the string into its path and its name with     *
 *           saving them in two string.                                 *
 * @param str                                                           *
 * @param path                  `                                       *
 * @param name                                                          *
 * @return 0:Failed 1:Success                                           *
 ************************************************************************/

int isPathandName(char str[], char path[], char name[]) {
    int i = strlen(str), flag = 0, nameLen = 0;
    char illegalChar[8] = {'<', '>', '\\', '|', ':', '"', '*', '?'};

    if (str[i - 1] == '/') {
        return 0;
    }
    for (; i >= 0; i--) {
        for (int j = 0; j < 8; ++j) {
            if (str[i] == illegalChar[j]) return 0;
        }
        if (str[i] == '/' && str[i + 1] == '/') return 0;
        if (flag == 0 && str[i] == '/') {
            flag = 1;
            nameLen = strlen(str) - i;
        }
    }
    for (int j = 0; j < nameLen - 1; ++j) {
        name[j] = str[strlen(str) - nameLen + 1 + j];
    }
    name[nameLen - 1] = '\0';
    for (int j = 0; j < strlen(str) - nameLen; ++j) {
        path[j] = str[j];
    }
    str[strlen(str) - nameLen] = '\0';
    return 1;
}

/*************************************************************
 * @functionname writeFile                                   *
 * @features write all data into the file which was created. *
 * @param path                                               *
 * @param name                                               *
 * @param data                                               *
 * @param number                                             *
 * @return 0:Failed 1:Success                                *
 *************************************************************/

int writeFile(char path[], char name[], int data[][3], int number) {
    char pathAndname[MAX_STR_LEN];

    FILE *fp = NULL;
    fp = fopen(path, "w+");
    fprintf(fp, "%d\n", number);
    if (fp == NULL) {
        return 0;
    }
    for (int i = 0; i < number; ++i) {
        fprintf(fp, "%d,%d,%d\n", data[i][0], data[i][1], data[i][2]);
    }
    fclose(fp);
    printf("Create the file succeed!\n");
    return 1;
}

/****************************************************************
 * @funcname dataReinput                                        *
 * @features If the parameters wasn't be input in command line, *
 *           by using this function, they can be inout again.   *
 * @param count1                                                *
 * @param count2                                                *
 * @param path                                                  *
 * @param name                                                  *
 * @param number                                                *
 * @param min                                                   *
 * @param max                                                   *
 * @return 0:Failed 1:Success                                   *
 ****************************************************************/

int dataReinput(int count1, int count2, char path[], char name[], int *number, int min, int max) {
    char str[MAX_STR_LEN];

    if (count1 == 0) {
        printf("Please input the number:");
        gets(str);
        while (isNumber(str) != 1) {
            printf("The content you input was illegal!\n");
            printf("Please input the number again:");
            gets(str);
        }
        printf("Would you like to produce the number random? (input \"y\" if you want or input anything if you don't want)");
        if (getchar() == 'y') {
            *number = rand() % 32768;
        } else {
            printf("Please input the number:");
            scanf("%d",number);
            if (isNumberLegal(*number, min, max)) {}
            else {
                printf("Number exceed the range!\n");
                return 0;
            }
        }
    }
    if (count2 == 0) {
        printf("Please input the path and the file name:");
        gets(str);
        gets(str);
        if (isPathandName(str, path, name) == 1 && strlen(str) != 0) {
        } else {
            printf("Input content error!\n");
            return 0;
        }
    }

    return 1;
}

/*****************************************************
 * @funcname fileCreater                             *
 * @features make the direction and create the file. *
 * @param path                                       *
 * @param name                                       *
 * @return 0:Failed 1:Success                        *
 *****************************************************/

int fileCreater(char path[], char name[]) {
    char pathAndname[MAX_STR_LEN];

    mkdir(path, 0755);
    strcpy(path, strcat(path, "/"));
    strcpy(pathAndname, strcat(path, name));
    FILE *fp = NULL;
    fp = fopen(pathAndname,"w");
    if (fp == NULL) {
        return 0;
    }
    fclose(fp);
    return 1;
}

/*******************************************
 * @funcname dataProcess                   *
 * @features produce numbers in random and *
 *           write them into the array.    *
 * @param number                           *
 * @param data                             *
 * @param min1                             *
 * @param min2                             *
 * @param max1                             *
 * @param max2                             *
 *******************************************/

void dataProcess(int number, int data[][3], int min1, int min2, int max1, int max2) {
    srand((unsigned int)time(NULL));

    int differenceA = max1 - min1;
    int differenceB = max2 - min2;

    for (int i = 0; i < number; ++i) {
        while (data[i][0] == data[i][1]) {
            data[i][0] = rand() % differenceA + min1;
            data[i][1] = rand() % differenceA + min1;
        }
        data[i][2] = rand() % differenceB + min2;
    }
}

/***********************************************************
 * @funcname isNumberLegal                                 *
 * @features Judge a number if it's in the range [min,max] *
 * @param number                                           *
 * @param min                                              *
 * @param max                                              *
 * @return 0:it's not in the range 1:it's in the range     *
 ***********************************************************/

int isNumberLegal(int number, int min, int max) {
    if (number < min || number > max) {
        return 0;
    }
    return 1;
}