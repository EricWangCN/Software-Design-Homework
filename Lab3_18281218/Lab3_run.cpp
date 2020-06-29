/*********************************************
 * @filename                                 *
 *      Lab3_run.cpp                         *
 * @filefistory                              *
 *  Mar.13th, 2019:                          *
 *      Created by Wang Zilong               *
 *          E-mail: wangzilnog0201@gmail.com *
 *********************************************/

#include "Lab3_run.h"
#include "Lab3_fun.h"
#include "Lab3_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int run(int argc, char* argv[]) {
    CONF userConfig;
    int data[40000][3] = {0};

    srand((unsigned int)time(NULL));
    userConfig.maxvalue1 = MAX_A;
    userConfig.maxvalue2 = MAX_B;
    userConfig.minvalue1 = MIN_A;
    userConfig.minvalue2 = MIN_B;
    userConfig.recordCount1 = MAX_C;
    userConfig.recordCount2 = MIN_C;
    userConfig.number = 0;
    userConfig.recordcount1 = 0;
    userConfig.recordcount2 = 0;

    if (argc == 1) {}                   //No Command Line parameters are input
    else if (argc == 2) {               //Only one Command Line parameter is input
        if (isNumber(argv[1]) == 1) {   //The parameter is number
            userConfig.recordcount1 = 1;
            userConfig.number = atoi(argv[1]);
            if (isNumberLegal(userConfig.number, userConfig.recordCount2, userConfig.recordCount1)) {}
            else {
                printf("Number exceed the range!\n");
                return 9;
            }
        } else if (isPathandName(argv[1], userConfig.filesavepath, userConfig.filename) == 1) {
            userConfig.recordcount2 = 1;//The parameter is the path of a file and its name
        } else {                        //Illegal string is input.
            printf("Input content error!\n");
            return 9;
        }
    } else if (argc == 3) {             //Two Command Line parameters are both input
        if (isNumber(argv[1]) == 1) {   //argv[1] is number
            if (isPathandName(argv[2], userConfig.filesavepath, userConfig.filename) == 1) {
                userConfig.recordcount2 = 1;
            } else {
                printf("Input content error!\n");
                return 9;
            }
            userConfig.recordcount1 = 1;
            userConfig.number = atoi(argv[1]);
            if (isNumberLegal(userConfig.number, userConfig.recordCount2, userConfig.recordCount1)) {}
            else {
                printf("Number exceed the range!\n");
                return 9;
            }
        } else if (isNumber(argv[2]) == 1) { //argv[2] is the name of a file and its path.
            if (isPathandName(argv[1], userConfig.filesavepath, userConfig.filename) == 1) {
                userConfig.recordcount2 = 1;
            } else {
                printf("Input content error!\n");
                return 9;
            }
            userConfig.recordcount1 = 1;
            userConfig.number = atoi(argv[2]);
            if (isNumberLegal(userConfig.number, userConfig.recordCount2, userConfig.recordCount1)) {}
            else {
                printf("Number exceed the range!\n");
                return 9;
            }
        } else {
            printf("Input content error!\n");
            return 9;
        }
    } else {
        printf("To much content you input!\n");
        return 10;
    }
    if (dataReinput(userConfig.recordcount1, userConfig.recordcount2,
            userConfig.filesavepath, userConfig.filename, &userConfig.number,
            userConfig.recordCount2, userConfig.recordCount1) == 1) {}  //Input the data manually
    else return 12;
    if (fileCreater(userConfig.filesavepath,userConfig.filename) == 1) {}//Create file & make direction
    else {
        printf("Cannot create file!\n");
        return 13;
    }
    dataProcess(userConfig.number, data, userConfig.minvalue1,
            userConfig.minvalue2,userConfig.maxvalue1, userConfig.maxvalue2);
    if (writeFile(userConfig.filesavepath, userConfig.filename, data, userConfig.number)) {}
    else {
        printf("Cannot write data into the file!\n");
        return 14;
    }

    return 1;
}
