//
// Created by 王子龙 on 2019-05-05.
//
#include "Lab6_data.h"
#include <string.h>
#include <stdio.h>

/***************************************
 * @funcname Initialization            *
 * @feature initialization config file *
 * @return 0 error                     *
 *         1 manual mode               *
 *         2 automatic mode            *
 ***************************************/

int Initialization() {
    FILE *fp = fopen("Lab4.out", "r");
    char in[MAX_STR_LEN];

    if (fp == NULL) {
        printf("Initialization error!(Cannot find 'Lab4.out')\n");
        return 0;
    }
    fclose(fp);

    FILE *ffp = fopen("_conf.ini", "r");

    if (ffp == NULL) {
        printf("Initialization error!(Cannot open '_conf.ini'!)\n");
        return 0;
    } else {
        fscanf(ffp, "%s", in);
        fclose(ffp);
        while (1) {
            if (strstr(in,"manual")) {
                return 1;
            } else if (strstr(in, "automatic")) {
                return 2;
            } else {
                printf("Initialization error!(config file error!)\n");
                return 0;
            }
        }
    }
}