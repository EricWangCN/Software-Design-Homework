//
// Created by 王子龙 on 2019-06-01.
//
#include "../Lab7_data.h"
#include "Lab7_loadfile.h"
#include <cstdio>
#include <stdlib.h>


extern ELEVATORSTATE eleState;
extern int time;
extern int narrive;
extern int n;
extern int mh;
extern RESPONSELISTHEADNODE rHeadNode;
extern RESPONSELISTNODE *rNode;
extern SERVELISTNODE *sNode;

int getUserCallInfo(USERCALL *uCall) {
    FILE *fp = fopen(defaultPath, "r");

    printf("Please input command:(not more than 100)");
    fscanf(fp, "%d", &n);
    rHeadNode.list_num = n;

    printf("\nUser call:\n%d\n",n);

    for (int i = 0; i < n; ++i) {
        fscanf(fp, "%d,%d,%d\n", &uCall[i].user_floor, &uCall[i].user_target, &uCall[i].call_time);
        if (uCall[i].user_target - uCall[i].user_floor > 0) {
            uCall[i].call_type = 'U';
        } else {
            uCall[i].call_type = 'D';
        }
    }
    qsort(uCall, (size_t)n, sizeof(USERCALL), cmp);

    for (int i = 0; i < n; ++i) {
        printf("%d,%d,%d\n", uCall[i].user_floor, uCall[i].user_target, uCall[i].call_time);

    }

    printf("*********************************************************");
    fclose(fp);

    return uCall[n-1].call_time;
}

int cmp(const void *a, const void *b) {
    return (*(USERCALL *)a).call_time > (*(USERCALL *)b).call_time ? 1 : -1;
}

