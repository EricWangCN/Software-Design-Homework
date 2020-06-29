//
// Created by 王子龙 on 2019-04-19.
//
#include "Lab6_data.h"
#include "Lab6_call.h"
#include "Lab6_conf.h"
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <sys/malloc.h>
#include <sys/stat.h>

extern int dataLength;
extern int **TArray;
extern dataStruct *SArray;
extern int **PArray;
extern Linklist *head, *node, *end;

/*************************
 * @funcname work        *
 * @feature work by menu *
 * @param Status         *
 * @param fileInfo1      *
 * @return 0 error       *
 *         1 pass        *
 *************************/

int work(int Status, fileInfo fileInfo1) {
    char command[MAX_STR_LEN] = "./Lab4.out ";

    switch (Status) {
        case 0: {
            return 0;
        }
        case 1: {//Use Lab4 to create file (Text)
            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", fileInfo1.number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", fileInfo1.nameandpath);
                strcat(command, fileInfo1.nameandpath);
                strcat(command, " ");
                strcat(command, fileInfo1.number);
                strcat(command, " ");
                strcat(command, "D");
            } else {
                strcat(command, "D");
            }
            system(command);
            break;
        }
        case 2: {//Use Lab4 to create file (Binary)
            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", fileInfo1.number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", fileInfo1.nameandpath);
                strcat(command, fileInfo1.nameandpath);
                strcat(command, " ");
                strcat(command, fileInfo1.number);
                strcat(command, " ");
                strcat(command, "B");
            } else {
                strcat(command, "B");
            }
            system(command);
            break;
        }
        case 3: {//Read exact data file (2D array)


            FILE *fp = fopen(defaultPath, "r");
            fscanf(fp, "%d", &dataLength);

            TArray = (int **)malloc(sizeof(int *) * dataLength);
            for (int i = 0; i < dataLength; ++i) {
                TArray[i] = (int *)malloc(sizeof(int) * 3);
            }
            for (int i = 0; i < dataLength; ++i) {
                fscanf(fp, "%d,%d,%d\n", &TArray[i][0], &TArray[i][1], &TArray[i][2]);
            }

            break;
        }
        case 4: {//Read exact data file (struct Array)


            FILE *fp = fopen(defaultPath, "r");
            fscanf(fp, "%d", &dataLength);

            SArray = (dataStruct*)malloc(sizeof(dataStruct) * dataLength);
            for (int i = 0; i < dataLength; ++i) {
                fscanf(fp, "%d,%d,%d\n", &SArray[i].item1, &SArray[i].item2, &SArray[i].item3);
            }

            break;
        }
        case 5: {//Read exact data file (pointer Array)


            FILE *fp = fopen(defaultPath, "r");
            fscanf(fp, "%d", &dataLength);

            PArray = (int **)malloc(sizeof(int *) * dataLength);
            for (int i = 0; i < dataLength; ++i) {
                PArray[i] = (int *)malloc(sizeof(int) * 3);
            }
            for (int i = 0; i < dataLength; ++i) {
                fscanf(fp, "%d,%d,%d\n", *(PArray + i), (*(PArray + i) + 1), (*(PArray + i) + 2));
            }

            break;
        }
        case 6: {//Read exact data file (Linked lists)


            head = (Linklist *)malloc(sizeof(Linklist));
            end = head;

            FILE *fp = fopen(defaultPath, "r");
            fscanf(fp, "%d", &dataLength);

            for (int i = 0; i < dataLength; ++i) {
                node = (Linklist*)malloc(sizeof(Linklist));
                fscanf(fp, "%d,%d,%d\n", &node->data[0], &node->data[1], &node->data[2]);
                end->next = node;
                end = node;
            }
            end->next = NULL;

            node = head->next;

            break;
        }
        case 7: {//User Lab4 to create file, and read exact data file (TEXT OUT & 2D Array storage)
            char pathandname[MAX_STR_LEN] = defaultPath;
            char number[MAX_STR_LEN];

            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", pathandname);
                strcat(command, pathandname);
                strcat(command, " ");
                strcat(command, number);
                strcat(command, " ");
                strcat(command, "D");
            } else {
                strcat(command, "D");
            }

            system(command);

            FILE *fp = fopen(pathandname, "r");
            fscanf(fp, "%d", &dataLength);

            TArray = (int **)malloc(sizeof(int *) * dataLength);
            for (int i = 0; i < dataLength; ++i) {
                TArray[i] = (int *)malloc(sizeof(int) * 3);
            }
            for (int i = 0; i < dataLength; ++i) {
                fscanf(fp, "%d,%d,%d\n", &TArray[i][0], &TArray[i][1], &TArray[i][2]);
            }

            break;
        }
        case 8: {// User Lab4 to create file, and read exact data file (TEXT OUT & struct array storage)
            char pathandname[MAX_STR_LEN] = defaultPath;
            char number[MAX_STR_LEN];

            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", pathandname);
                strcat(command, pathandname);
                strcat(command, " ");
                strcat(command, number);
                strcat(command, " ");
                strcat(command, "D");
            } else {
                strcat(command, " D");
            }

            system(command);

            FILE *fp = fopen(pathandname, "r");
            fscanf(fp, "%d", &dataLength);

            SArray = (dataStruct*)malloc(sizeof(dataStruct) * dataLength);
            for (int i = 0; i < dataLength; ++i) {
                fscanf(fp, "%d,%d,%d\n", &SArray[i].item1, &SArray[i].item2, &SArray[i].item3);
            }

            break;
        }
        case 9: {//User Lab4 to create file, and read its data file (TEXT OUT & pointer array storage)
            char pathandname[MAX_STR_LEN] = defaultPath;
            char number[MAX_STR_LEN];
            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", pathandname);
                strcat(command, pathandname);
                strcat(command, " ");
                strcat(command, number);
                strcat(command, " ");
                strcat(command, "D");
            } else {
                strcat(command, "D");
            }

            system(command);

            FILE *fp = fopen(pathandname, "r");
            fscanf(fp, "%d", &dataLength);

            PArray = (int **)malloc(sizeof(int *) * dataLength);
            for (int i = 0; i < dataLength; ++i) {
                PArray[i] = (int *)malloc(sizeof(int) * 3);
            }
            for (int i = 0; i < dataLength; ++i) {
                fscanf(fp, "%d,%d,%d\n", *(PArray + i), (*(PArray + i) + 1), (*(PArray + i) + 2));
            }

            break;
        }
        case 10: {//User Lab4 to create file, and read its data file (TEXT OUT & linked lists storage)
            char pathandname[MAX_STR_LEN] = defaultPath;
            char number[MAX_STR_LEN];

            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", pathandname);
                strcat(command, pathandname);
                strcat(command, " ");
                strcat(command, number);
                strcat(command, " ");
                strcat(command, "D");
            } else {
                strcat(command, "D");
            }

            system(command);

            head = (Linklist *)malloc(sizeof(Linklist));
            end = head;

            FILE *fp = fopen(pathandname, "r");
            fscanf(fp, "%d", &dataLength);

            for (int i = 0; i < dataLength; ++i) {
                node = (Linklist*)malloc(sizeof(Linklist));
                fscanf(fp, "%d,%d,%d\n", &node->data[0], &node->data[1], &node->data[2]);
                end->next = node;
                end = node;
            }
            end->next = NULL;

            node = head->next;
            break;
        }
        case 11: {//User Lab4 to create file, and read its data file (Binary OUT & 2D Array storage)
            char pathandname[MAX_STR_LEN] = "/Users/wangzilong/Desktop/Study/Assignment/ProgramDesign/Lab5_18281218/Lab4_Out/DataFile.dat";
            char number[MAX_STR_LEN];

            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", pathandname);
                strcat(command, pathandname);
                strcat(command, " ");
                strcat(command, number);
                strcat(command, " ");
                strcat(command, "B");
            } else {
                strcat(command, "B");
            }

            system(command);

            FILE *fp = fopen(pathandname, "r");
            fread(&dataLength, 4, 1, fp);

            TArray = (int **)malloc(sizeof(int *) * dataLength);
            for (int i = 0; i < dataLength; ++i) {
                TArray[i] = (int *)malloc(sizeof(int) * 3);
            }
            for (int i = 0; i < dataLength; ++i) {
                fread(&TArray[i][0], 4, 1, fp);
                fread(&TArray[i][1], 4, 1, fp);
                fread(&TArray[i][2], 4, 1, fp);
            }

            break;
        }
        case 12: {//User Lab4 to create file, and read its data file (Binary OUT & struct array storage)
            char pathandname[MAX_STR_LEN] = "/Users/wangzilong/Desktop/Study/Assignment/ProgramDesign/Lab5_18281218/Lab4_Out/DataFile.dat";
            char number[MAX_STR_LEN];

            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", pathandname);
                strcat(command, pathandname);
                strcat(command, " ");
                strcat(command, number);
                strcat(command, " ");
                strcat(command, "B");
            } else {
                strcat(command, "B");
            }

            system(command);

            FILE *fp = fopen(pathandname, "r");
            fread(&dataLength, 4, 1, fp);

            SArray = (dataStruct*)malloc(sizeof(dataStruct) * dataLength);
            for (int i = 0; i < dataLength; ++i) {
                fread(&SArray[i].item1, 4, 1, fp);
                fread(&SArray[i].item2, 4, 1, fp);
                fread(&SArray[i].item3, 4, 1, fp);
                fscanf(fp, "\n");
            }

            break;
        }
        case 13: {//User Lab4 to create file, and read its data file (Binary OUT & pointer array storage)
            char pathandname[MAX_STR_LEN] = "/Users/wangzilong/Desktop/Study/Assignment/ProgramDesign/Lab5_18281218/Lab4_Out/DataFile.dat";
            char number[MAX_STR_LEN];

            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", pathandname);
                strcat(command, pathandname);
                strcat(command, " ");
                strcat(command, number);
                strcat(command, " ");
                strcat(command, "B");
            } else {
                strcat(command, "B");
            }

            system(command);

            FILE *fp = fopen(pathandname, "r");
            fread(&dataLength, 4, 1, fp);

            PArray = (int **)malloc(sizeof(int *) * dataLength);
            printf("%d\n", dataLength);
            for (int i = 0; i < dataLength; ++i) {
                PArray[i] = (int *)malloc(sizeof(int) * 3);
            }
            for (int i = 0; i < dataLength; ++i) {
                fread(&PArray[i][0], 4, 1, fp);
                fread(&PArray[i][1], 4, 1, fp);
                fread(&PArray[i][2], 4, 1, fp);
                fscanf(fp, "\n");
            }

            break;
        }
        case 14: {//User Lab4 to create file, and read its data file (Binary OUT & linked lists storage)
            char pathandname[MAX_STR_LEN] = "/Users/wangzilong/Desktop/Study/Assignment/ProgramDesign/Lab5_18281218/Lab4_Out/DataFile.dat";
            char number[MAX_STR_LEN];

            head = (Linklist *)malloc(sizeof(Linklist));
            end = head;

            if (fileInfo1.status) {
                printf("Please input how many group of numbers you want to create:\n");
                scanf("%s", number);
                printf("Please input the file path and name (e,g /Users/Guest_1/Desktop/a.dat)\n");
                scanf("%s", pathandname);
                strcat(command, pathandname);
                strcat(command, " ");
                strcat(command, number);
                strcat(command, " ");
                strcat(command, "B");
            } else {
                strcat(command, "B");
            }

            system(command);

            FILE *fp = fopen(pathandname, "r");
            fread(&dataLength, 4, 1, fp);

            for (int i = 0; i < dataLength; ++i) {
                node = (Linklist*)malloc(sizeof(Linklist));
                fread(&node->data[0], 4, 1, fp);
                fread(&node->data[1], 4, 1, fp);
                fread(&node->data[2], 4, 1, fp);
                fscanf(fp, "\n");
                end->next = node;
                end = node;
            }
            end->next = NULL;

            node = head->next;

            break;
        }
        case 15: {
            reConf();
            break;
        }
        default: {
            printf("ERROR!");
            return 0;
        }
    }
    return 1;
}