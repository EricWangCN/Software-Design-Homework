/***********************************************
 * @Filename                                   *
 *      Lab3_fun.h                             *
 * @Filehistory                                *
 *  Mar.13th, 2019:                            *
 *      Created by Wang Zilong                 *
 *          E-mail: wangzilnog0201@gmail.com   *
 ***********************************************/

#ifndef LAB3_18281218_LAB3_FUN_H
#define LAB3_18281218_LAB3_FUN_H

//Declaration of all functions.
int isNumber(char str[]);
int isPathandName(char str[], char path[], char name[]);
int writeFile(char path[], char name[], int data[][3], int number);
int dataReinput(int count1, int count2, char path[], char name[], int* number, int min, int max);
int fileCreater(char path[], char name[]);
void dataProcess(int number, int data[][3], int min1, int min2, int max1, int max2);
int isNumberLegal(int number, int min, int max);

#endif //LAB3_18281218_LAB3_FUN_H
