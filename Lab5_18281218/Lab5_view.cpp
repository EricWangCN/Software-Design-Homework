//
// Created by 王子龙 on 2019-05-05.
//

#include "Lab5_data.h"
#include "Lab5_view.h"
#include <stdio.h>

extern int dataLength;
extern int **TArray;
extern dataStruct *SArray;
extern int **PArray;
extern Linklist *head, *node, *end;

/*******************
 * @funcname print *
 * @feature print  *
 * @param Status   *
 *******************/

void print(int Status) {
    if (Status == 3 || Status == 7 || Status == 11) {
        printTArray();
    } else if (Status == 4 || Status == 8 || Status == 12) {
        printSArray();
    } else if (Status == 5 || Status == 9 || Status == 13) {
        printPArray();
    } else if (Status == 6 || Status == 10 || Status == 14) {
        printLinkList();
    } else {}
}

/***************************
 * @funcname printTArray   *
 * @feature print 2D array *
 ***************************/

void printTArray() {
    for (int i = 0; i < dataLength; ++i) {
        printf("%d,%d,%d\n", TArray[i][0], TArray[i][1], TArray[i][2]);
    }
}

/*******************************
 * @funcname printSArray       *
 * @feature print Struct array *
 *******************************/

void printSArray() {
    for (int i = 0; i < dataLength; ++i) {
        printf("%d,%d,%d\n", SArray[i].item1, SArray[i].item2, SArray[i].item3);
    }
}

/********************************
 * @funcname printPArray        *
 * @feature print Pointer array *
 ********************************/

void printPArray() {
    for (int i = 0; i < dataLength; ++i) {
        printf("%d,%d,%d\n", *(*(PArray + i)), *(*(PArray + i) + 1), *(*(PArray + i) + 2));
    }
}

/***************************
 * @funcname printLinkList *
 * @feature print Linklist *
 ***************************/


void printLinkList() {
    while (node->next != NULL) {
        printf("%d,%d,%d\n", node->data[0], node->data[1], node->data[2]);
        node = node->next;
    }
    printf("%d,%d,%d\n", node->data[0], node->data[1], node->data[2]);
}