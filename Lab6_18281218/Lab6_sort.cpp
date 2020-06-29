//
// Created by 王子龙 on 2019-05-14.
//
#include "Lab6_data.h"
#include "Lab6_sort.h"
#include "Lab6_view.h"
#include <stdlib.h>
#include <stdio.h>

extern int dataLength;
extern int **TArray;
extern dataStruct *SArray;
extern int **PArray;
extern Linklist *head, *node, *end;

/**********
 *
 * @param Status
 */

void sort(int Status) {
    if (Status == 3 || Status == 7 || Status == 11) {
        printf("After sorting:\n");
        sortT();
        printTArray();
    } else if (Status == 4 || Status == 8 || Status == 12) {
        printf("After sorting:\n");
        sortS();
        printSArray();
    } else if (Status == 5 || Status == 9 || Status == 13) {
        printf("After sorting:\n");
        sortP();
        printPArray();
    } else if (Status == 6 || Status == 10 || Status == 14) {
        printf("After sorting:\n");
        sortL();
        while (node->next != NULL) {
            printf("%d,%d,%d\n", node->data[0], node->data[1], node->data[2]);
            node = node->next;
        }
    } else {}
}

void sortT() {
    qsort(TArray, dataLength, sizeof(int *), TandPcmp);
}

void sortS() {
    qsort(SArray, dataLength, sizeof(dataStruct), Scmp);
}

void sortP() {
    qsort(PArray, dataLength, sizeof(int *), TandPcmp);
}

void sortL() {
    Linklist *big, *temp;

    for (int i = 0; i < dataLength; ++i) {
        node = head;
        big = end;
        for (int j = 0; j < dataLength - i; ++j) {
            if (node->data[2] > big->data[2]) {
                big = node;
            }

            if (j != dataLength - i - 1) node = node->next;
        }

        temp->data[0] = node->data[0];
        node->data[0] =  big->data[0];
        big->data[0]  = temp->data[0];
        temp->data[1] = node->data[1];
        node->data[1] =  big->data[1];
        big->data[1]  = temp->data[1];
        temp->data[2] = node->data[2];
        node->data[2] =  big->data[2];
        big->data[2]  = temp->data[2];
    }
}

int TandPcmp(const void *a, const void *b) {
    int **num1=(int **)a;
    int **num2=(int **)b;
    if(*(*num1 + 2) > *(*num2 + 2))
        return 1;
    else return -1;
}

int Scmp(const void *a, const void *b) {
    return (*(dataStruct *)a).item3 > (*(dataStruct *)b).item3 ? 1 : -1;
}
