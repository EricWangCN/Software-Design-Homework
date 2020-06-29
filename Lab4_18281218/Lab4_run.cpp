//
// Created by 王子龙 on 2019-04-03.
// Email: wangzilong0201@gmail.com
//
#include "Lab4_fun.h"
#include "Lab4_data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int run(int argc, char* argv[]) {
    CONF userConfig;

    initializationConfig(&userConfig); //Initialization config struct.
    if (argc == 1) {} //No command line parameter is input.
    else if (argc == 2) { //One command line parameter is input.
        if (isNumber(argv[1])) {
            userConfig.recordcount1 = 1;
            userConfig.number = atoi(argv[1]);
        } else if (isPathandName(argv[1], &userConfig)) {
            userConfig.recordcount2 = 1;
        } else if (isType(argv[1], &userConfig)) {
        } else {
            printf("Illegal Input!");
            return 0;
        }
    } else if (argc == 3) { //Two command line parameters are input.
        if (isNumber(argv[1])) {
            userConfig.recordcount1 = 1;
            userConfig.number = atoi(argv[1]);
            if (isPathandName(argv[2], &userConfig)) {
                userConfig.recordcount2 = 1;
            } else if (isType(argv[2], &userConfig)) {
            } else {
                printf("Illegal Input!");
                return 0;
            }
        } else if (isPathandName(argv[1], &userConfig)) {
            userConfig.recordcount2 = 1;
            if (isNumber(argv[2])) {
                userConfig.recordcount1 = 1;
                userConfig.number = atoi(argv[2]);
            } else if (isType(argv[2], &userConfig)) {

            } else {
                printf("Illegal Input!");
                return 0;
            }
        } else if (isType(argv[1], &userConfig)) {

            if (isNumber(argv[2])) {
                userConfig.recordcount1 = 1;
                userConfig.number = atoi(argv[2]);
            } else if (isType(argv[2], &userConfig)) {

            } else {
                printf("Illegal Input!");
                return 0;
            }
        } else {
            printf("Illegal Input!");
            return 0;
        }
    } else if (argc == 4) { //Three command line parameters are input.
        if (isNumber(argv[1])) {
            userConfig.recordcount1 = 1;
            userConfig.number = atoi(argv[1]);
            if (isPathandName(argv[2], &userConfig)) {
                userConfig.recordcount2 = 1;
                if (isType(argv[3], &userConfig)) {

                } else {
                    printf("Illegal Input!");
                    return 0;
                }
            } else if (isPathandName(argv[3], &userConfig)) {
                userConfig.recordcount2 = 1;
                if (isType(argv[2], &userConfig)) {

                } else {
                    printf("Illegal Input!");
                    return 0;
                }
            } else {
                printf("Illegal Input!");
                return 0;
            }
        } else if (isNumber(argv[2])) {
            userConfig.recordcount1 = 1;
            userConfig.number = atoi(argv[2]);
            if (isPathandName(argv[1], &userConfig)) {
                userConfig.recordcount2 = 1;
                if (isType(argv[3], &userConfig)) {

                } else {
                    printf("Illegal Input!");
                    return 0;
                }
            } else if (isPathandName(argv[3], &userConfig)) {
                userConfig.recordcount2 = 1;
                if (isType(argv[1], &userConfig)) {

                } else {
                    printf("Illegal Input!");
                    return 0;
                }
            } else {
                printf("Illegal Input!");
                return 0;
            }
        } else if (isNumber(argv[3])) {
            userConfig.recordcount1 = 1;
            userConfig.number = atoi(argv[3]);
            if (isPathandName(argv[1], &userConfig)) {
                userConfig.recordcount2 = 1;
                if (isType(argv[2], &userConfig)) {

                } else {
                    printf("Illegal Input!");
                    return 0;
                }
            } else if (isPathandName(argv[2], &userConfig)) {
                userConfig.recordcount2 = 1;
                if (isType(argv[1], &userConfig)) {

                } else {
                    printf("Illegal Input!");
                    return 0;
                }
            } else {
                printf("Illegal Input!");
                return 0;
            }
        } else {
            printf("Illegal Input!");
            return 0;
        }
    } else { //More than three command line parameters are input.
        printf("Illegal Input!");
        return 0;
    }
    work(&userConfig);

    return 1;
}