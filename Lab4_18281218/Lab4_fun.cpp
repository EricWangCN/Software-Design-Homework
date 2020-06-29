//
// Created by 王子龙 on 2019-04-03.
// Email: wangzilong0201@gmail.com
//
#include "Lab4_data.h"
#include "Lab4_fun.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <cstdlib>
#include <sys/malloc.h>


/***********************************
 * @funcname initializationConfig  *
 * @features Initialize all values *
 * @param userConfig               *
 ***********************************/

void initializationConfig(CONF *userConfig) {
    FILE *fp = fopen("conf.ini","r");

    userConfig->number = 8;

    fscanf(fp, "%s", userConfig->filesavepath);
    fscanf(fp, "%s", userConfig->filename);
    fscanf(fp, "%d", &userConfig->maxvalue1);
    fscanf(fp, "%d", &userConfig->minvalue1);
    fscanf(fp, "%d", &userConfig->maxvalue2);
    fscanf(fp, "%d", &userConfig->minvalue2);
    fscanf(fp, "%d", &userConfig->recordCount1);
    fscanf(fp, "%d", &userConfig->recordCount2);

    userConfig->recordcount1 = 0;
    userConfig->recordcount2 = 0;
    userConfig->recordcount3 = 0;
    userConfig->type = 0;
}

/******************************************************************
 * @functionname isNumber                                         *
 * @features Judge if a string is consist of numbers('0'~'9')     *
 * @param str                                                     *
 * @return 0: have char which is not a number     1:is all number *
 ******************************************************************/

int isNumber(char* str) {
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

/********************************
 * @funcname dividePathandname  *
 * @features divide path & name *
 * @param str                   *
 * @param userConfig            *
 ********************************/

void dividePathandname(char* str, CONF* userConfig) {
    int i = strlen(str);
    int nameLen = 0;
    while (str[i] != '/') {
        nameLen++;
        i--;
    }
    for (int j = 0; j < i; ++j) {
        userConfig->filesavepath[j] = str[j];
    }
    for (int j = 0; j < nameLen; ++j) {
        userConfig->filename[j] = str[j + i + 1];
    }
}

/**********************************************************
 * @funcname isPathandName                                *
 * @features Judge if it is absolutepath or relative path *
 * @param str                                             *
 * @param userConfig                                      *
 * @return 0 illegal                                      *
 *         1 succeed                                      *
 **********************************************************/

int isPathandName(char* str, CONF* userConfig) {
    char illegalChar[7] = {'<', '>', '|', ':', '"', '*', '?'};
    char absolutePath[MAX_STR_LEN];
    int strLen = strlen(str);
    char pathandname[MAX_STR_LEN];

    getcwd(absolutePath, sizeof(absolutePath));

    for (int i = 0; i < strLen; ++i) {
        for (int j = 0; j < 7; ++j) {
            if ((str[i] == illegalChar[j]) || ((str[i] == '\\' && str[i + 1] != '\\' )&&(str[i] == '\\' && str[i - 1] != '\\'))) {
                printf("Filename or path illegal\n");
                return 0;
            }
        }
    }
    if (str[0] == '.') {
        if (str[1] == '.') {
            strcpy(pathandname, absolutePath);

            for (int i = 0; i < strLen; ++i) {
                str[i] = str[i + 2];
            }
            int i = strlen(pathandname);
            while (pathandname[i] != '/') {
                pathandname[i] = '\0';
                i--;
            }
            pathandname[i - 1] = '\0';
            strcat(pathandname,str);
        } else {
            strcpy(pathandname, absolutePath);
            for (int i = 0; i < strLen; ++i) {
                str[i] = str[i + 1];
            }
            strcat(pathandname,str);
        }
    } else if (str[0] == '/') {
        strcpy(pathandname, str);
    } else {
        return 0;
    }
    strcpy(userConfig->fileandpath, pathandname);
    dividePathandname(pathandname, userConfig);

    return 1;
}

/**************************************
 * @funcname isType                   *
 * @features Judge if it's Bin or Dec *
 * @param str                         *
 * @param userConfig                  *
 * @return                            *
 **************************************/

int isType(char* str, CONF* userConfig) { //B: Binary, D: Decimal
    if (strlen(str) >= 2) {
        return 0;
    } else if (str[0] != 'B' && str[0] != 'b' && str[0] != 'D' && str[0] != 'd' && str[0] != 'A' && str[0] != 'a') {
        return 0;
    } else {
        if (str[0] == 'B' || str[0] == 'b') {
            userConfig->recordcount3 = 1;
            printf("Create BIN use:");
        } else if (str[0] == 'D' || str[0] == 'd') {
            userConfig->recordcount3 = 2;
            printf("Create DEC use:");
        } else {
            userConfig->recordcount3 = 3;
            printf("Create BOTH use:");
        }
        return 1;
    }
}

/*************************
 * @funcname work        *
 * @features do all work *
 * @param userConfig     *
 * @return 1             *
 *************************/

int work(CONF* userConfig) {
    DATAITEM *item = (DATAITEM*)malloc(sizeof(DATAITEM) * userConfig->number);

    dataReInput(userConfig);
    double start = clock();
    makeData(userConfig, item);
    double end = clock();
    printf(" %lfs\n", (end - start)/CLOCKS_PER_SEC);
    makeFile(userConfig, item);

    return 1;
}

/**********************************
 * @funcname dataReinput          *
 * @features Re input information *
 * @param userConfig              *
 * @return 1                      *
 **********************************/

int dataReInput(CONF* userConfig) {
    char in[MAX_STR_LEN];
    char path[MAX_STR_LEN];

    strcpy(path, userConfig->filesavepath);

    if (userConfig->recordcount3 == 0) {
        printf("which mode do you want to choose?(A:All, B:Binary, D:Decimal)\n");
        gets(in);


        while (isType(in, userConfig) == 0) {
            printf("Error! Input again!");
            gets(in);
        }
    }

    if (userConfig->recordcount2 == 0) {
        if (userConfig->recordcount3 == 2){}
        else {
            strcpy(userConfig->filename, "DataFile.dat");
        }
        isPathandName(strcat(path, userConfig->filename), userConfig);
    }

    return 1;
}

/****************************************
 * @funcname makeFile                   *
 * @features Create file and write data *
 * @param userConfig                    *
 * @param item                          *
 * @return 1 succeed                    *
 *         0 failed                     *
 ****************************************/

int makeFile(CONF* userConfig, DATAITEM* item) {
    mkdir(userConfig->filesavepath, 0755);
    FILE *fp = fopen(userConfig->fileandpath, "w+");
    if (userConfig->recordcount3 == 1) { //is Binary
        fwrite(&userConfig->number, 4, 1, fp);
        for (int i = 0; i < userConfig->number; ++i) {
            fwrite(&item[i].item1, 4, 1, fp);
            fwrite(&item[i].item2, 4, 1, fp);
            fwrite(&item[i].item3, 4, 1, fp);
        }
        fclose(fp);
    } else if (userConfig->recordcount3 == 2) {    //is Decimal
        fprintf(fp, "%d\n", userConfig->number);
        for (int i = 0; i < userConfig->number; ++i) {
            fprintf(fp, "%d,%d,%d\n", item[i].item1, item[i].item2, item[i].item3);
        }
        fclose(fp);
    } else {    //Create both DEC & BIN
        if (strstr(userConfig->filename, ".txt") || strstr(userConfig->filename, ".Txt") ||
        strstr(userConfig->filename, ".tXt") || strstr(userConfig->filename, ".txT") ||
        strstr(userConfig->filename, ".TXt") || strstr(userConfig->filename, ".TxT") ||
        strstr(userConfig->filename, ".tXT") || strstr(userConfig->filename, ".TXT")) {
            fprintf(fp, "%d\n", userConfig->number);
            for (int i = 0; i < userConfig->number; ++i) {
                fprintf(fp, "%d,%d,%d\n", item[i].item1, item[i].item2, item[i].item3);
            }
            fclose(fp);
            strcpy(userConfig->fileandpath, strcat(userConfig->filesavepath, "default.dat"));
            FILE *FP = fopen(userConfig->fileandpath, "w+");
            fwrite(&userConfig->number, 4, 1, FP);
            fprintf(FP, "\n");
            for (int i = 0; i < userConfig->number; ++i) {
                fwrite(&item[i].item1, 4, 1, FP);
                fwrite(&item[i].item2, 4, 1, FP);
                fwrite(&item[i].item3, 4, 1, FP);
                fprintf(FP, "\n");
            }
            fclose(FP);
        } else {
            fwrite(&userConfig->number, 4, 1, fp);
            fprintf(fp, "\n");
            for (int i = 0; i < userConfig->number; ++i) {
                fwrite(&item[i].item1, 4, 1, fp);
                fwrite(&item[i].item2, 4, 1, fp);
                fwrite(&item[i].item3, 4, 1, fp);
                fprintf(fp, "\n");
            }
            fclose(fp);
            strcpy(userConfig->fileandpath, strcat(userConfig->filesavepath, "default.txt"));
            FILE *FP = fopen(userConfig->fileandpath, "w+");
            fprintf(FP, "%d\n", userConfig->number);
            for (int i = 0; i < userConfig->number; ++i) {
                fprintf(FP, "%d,%d,%d\n", item[i].item1, item[i].item2, item[i].item3);
            }
            fclose(FP);
        }
    }

    return 1;
}

/*****************************************************
 * @funcname getRandom                               *
 * @features get a random number in a range[min,max] *
 * @param min                                        *
 * @param max                                        *
 * @return number                                    *
 *****************************************************/

int getRandom(int min, int max) {
    int number = 0;

    number = rand() % (max - min) + min;

    return number;
}

/***********************
 * @funcname makeData  *
 * @features make data *
 * @param userConfig   *
 * @param item         *
 ***********************/

void makeData(CONF* userConfig, DATAITEM* item) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < userConfig->number; ++i) {
        do {
            item[i].item1 = getRandom(userConfig->minvalue1, userConfig->maxvalue1);
            item[i].item2 = getRandom(userConfig->minvalue1, userConfig->maxvalue1);
        } while(item[i].item1 == item[i].item2);
        item[i].item3 = getRandom(userConfig->minvalue2, userConfig->maxvalue2);
    }
}