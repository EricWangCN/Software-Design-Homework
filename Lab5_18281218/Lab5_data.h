//
// Created by 王子龙 on 2019-04-19.
//

#ifndef LAB5_18281218_LAB5_DATA_H
#define LAB5_18281218_LAB5_DATA_H

#define MAX_STR_LEN 256
#define defaultPath "/Users/wangzilong/Desktop/Study/Assignment/ProgramDesign/Lab5_18281218/Lab4_Out/DataFile.txt"

typedef struct dataLinkList {
    int data[3];
    dataLinkList *next;
} Linklist;

struct dataStruct {
    int item1;
    int item2;
    int item3;
};

struct fileInfo {
    char nameandpath[MAX_STR_LEN];
    char number[MAX_STR_LEN];
    bool status;
};

#endif //LAB5_18281218_LAB5_DATA_H
