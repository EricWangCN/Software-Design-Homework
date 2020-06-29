//
// Created by 王子龙 on 2019-06-01.
//
#include "Lab7_data.h"
#include "Lab7_main.h"
#include "data/Lab7_call.h"
#include "data/Lab7_loadfile.h"
#include "elevator/Lab7_elevator_work.h"
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>

ELEVATORSTATE eleState;
int time;
int narrive;
int n;
int mh;
RESPONSELISTHEADNODE rHeadNode;
RESPONSELISTNODE *rNode;
SERVELISTNODE *sNode;

void run() {
    USERCALL *uCall;

    int max;

    makeDataFile();

    uCall = (USERCALL*)malloc(sizeof(USERCALL)*1005);

    max = getUserCallInfo(uCall);

    eleState.current_floor = 1;
    eleState.run_state = 'S';
    eleState.serve_list = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
    eleState.serve_list->next_node = NULL;

    rNode =  (RESPONSELISTNODE*)malloc(sizeof(RESPONSELISTNODE));
    rNode->next_node = NULL;
    rNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));

    rHeadNode.list_num = 0;
    rHeadNode.head = rNode;
    rHeadNode.tail = rNode;

    rHeadNode.head = rNode;

    sNode = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
    sNode->next_node = NULL;
    sNode->serve_state = 'N';

    time = 0;
    narrive = 0;
    mh = 0;

    printf("\nElevator start:\n\n");
    while(narrive < n){
        work(uCall);
        //sleep(1);
    }

    freenode();
    printf("End!\n");
}

void freenode(){
    RESPONSELISTNODE *p = rHeadNode.head;
    while(p->next_node != NULL){
        free(p);
        p = p->next_node;
    }
    SERVELISTNODE *q = eleState.serve_list;
    while(q->next_node != NULL){
        free(q);
        q = q->next_node;
    }
}
