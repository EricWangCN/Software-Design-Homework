//
// Created by 王子龙 on 2019-06-01.
//
#include "../Lab7_data.h"
#include "Lab7_elevator_work.h"
#include <zconf.h>
#include <stdio.h>
#include <cstdlib>

extern ELEVATORSTATE eleState;
extern int time;
extern int narrive;
extern int n;
extern int mh;
extern RESPONSELISTHEADNODE rHeadNode;
extern RESPONSELISTNODE *rNode;
extern SERVELISTNODE *sNode;

void work(USERCALL *uCall){
    int i = 0;

    printf("********************\nAt time %d\n Now: ", time);
    print();
    for(i = 0; i < n; i ++){
        if(uCall[i].call_time == time){
            rNode = rHeadNode.tail;
            rNode->user_call->call_time = uCall[i].call_time;
            rNode->user_call->call_type = uCall[i].call_type;
            rNode->user_call->user_floor = uCall[i].user_floor;
            rNode->user_call->user_target = uCall[i].user_target;
            rNode = rNode->next_node = (RESPONSELISTNODE*)malloc(sizeof(RESPONSELISTNODE));
            rNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
            rNode->next_node = NULL;
            rHeadNode.tail = rNode;
        }
    }
    if(emptyserve() == 0){
        if(rHeadNode.head->next_node != NULL){
            mh += 1;
            sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
            sNode->user_call->call_time = rHeadNode.head->user_call->call_time;
            sNode->user_call->call_type = rHeadNode.head->user_call->call_type;
            sNode->user_call->user_floor = rHeadNode.head->user_call->user_floor;
            sNode->user_call->user_target = rHeadNode.head->user_call->user_target;
            sNode->next_node = NULL;
            rHeadNode.head = rHeadNode.head->next_node;
            if(sNode->user_call->user_floor == eleState.current_floor){
                sNode->serve_state = 'E';
            }
            else{
                sNode->serve_state = 'P';
            }
            if(mh == 1){
                eleState.serve_list = sNode;
            }
            sNode = sNode->next_node = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
            sNode->next_node = NULL;
            sNode->serve_state = 'N';
            joinlist();
        }
    }
    else{
        joinlist();
        printf("time: %d ; ", time);
        sNode = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
        sNode = eleState.serve_list;
        printf("At %d Floor; Serve state: %c; ", eleState.current_floor, eleState.run_state);
        while (sNode->next_node != NULL) {
            printf("<%d,%d,%d,%c> ", sNode->user_call->user_floor, sNode->user_call->user_target, sNode->user_call->call_time, sNode->serve_state);
            sNode = sNode->next_node;
        }
        printf("\n");
    }
    judgestate();


    printf("Next: ");
    print();
    printf("********************\n\n");


    time++;
}

void print(){
    switch(eleState.run_state){
        case'U': printf("State of elevator: F%d UPWARD\n", eleState.current_floor); break;
        case'D': printf("State of elevator: F%d DOWNWARD\n", eleState.current_floor); break;
        case'S': printf("State of elevator: F%d STOP\n", eleState.current_floor); break;
        default: printf("ERROR!"); exit(1); break;
    }
}

/*****************************
emptyserve函数：判断电梯是否正在服务函数
*****************************/
int emptyserve(){
    int flag = 0;
    SERVELISTNODE *sln = eleState.serve_list;
    while(sln != NULL){
        if(sln->serve_state == 'P' || sln->serve_state == 'E'){
            flag = 1;
            break;
        }
        sln = sln->next_node;
    }
    return flag;
}

/*****************************
joinlist函数：将待响应指令加入当前服务列表中
*****************************/
void joinlist(){
    rNode = rHeadNode.head;
    int m = eleState.current_floor;
    switch(eleState.run_state){
        case'U':{
            int flag = 0;
            RESPONSELISTNODE *rNodePre = rHeadNode.head;
            while(rNode->next_node != NULL){
                if(rNode->user_call->user_floor > m && rNode->user_call->user_target > rNode->user_call->user_floor){
                    if(rNode == rHeadNode.head){
                        sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
                        sNode->user_call->call_time = rNode->user_call->call_time;
                        sNode->user_call->call_type = rNode->user_call->call_type;
                        sNode->user_call->user_floor = rNode->user_call->user_floor;
                        sNode->user_call->user_target = rNode->user_call->user_target;
                        sNode->serve_state = 'P';
                        /////////////
                        printf("time: %d ; ", time);
                        printf("<%d,%d,%d,%c>\n", sNode->user_call->call_time, sNode->user_call->user_floor, sNode->user_call->user_target, sNode->serve_state);
                        /////////////
                        sNode->next_node = NULL;
                        sNode = sNode->next_node = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
                        sNode->next_node = NULL;
                        sNode->serve_state = 'N';
                        rHeadNode.head = rHeadNode.head->next_node;
                    }
                    else{
                        sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
                        sNode->user_call->call_time = rNode->user_call->call_time;
                        sNode->user_call->call_type = rNode->user_call->call_type;
                        sNode->user_call->user_floor = rNode->user_call->user_floor;
                        sNode->user_call->user_target = rNode->user_call->user_target;
                        sNode->serve_state = 'P';
                        sNode->next_node = NULL;
                        sNode = sNode->next_node= (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
                        sNode->next_node = NULL;
                        sNode->serve_state = 'N';
                        rNodePre->next_node = rNode->next_node;
                        flag  = 1;
                    }
                }
                if(rNode != rHeadNode.head && flag != 1){
                    rNodePre = rNodePre->next_node;
                }
                rNode = rNode->next_node;
                flag = 0;
            }
            break;
        }
        case'D':{
            int flag = 0;
            RESPONSELISTNODE *rNodePre = rHeadNode.head;
            while(rNode->next_node != NULL){
                if(rNode->user_call->user_floor < m && rNode->user_call->user_target < rNode->user_call->user_floor){
                    if(rNode == rHeadNode.head){		//sNode在头结点
                        sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
                        sNode->user_call->call_time = rNode->user_call->call_time;
                        sNode->user_call->call_type = rNode->user_call->call_type;
                        sNode->user_call->user_floor = rNode->user_call->user_floor;
                        sNode->user_call->user_target = rNode->user_call->user_target;
                        sNode->serve_state = 'P';
                        sNode->next_node = NULL;
                        sNode = sNode->next_node = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
                        sNode->next_node = NULL;
                        sNode->serve_state = 'N';
                        rHeadNode.head = rHeadNode.head->next_node;
                    }
                    else{
                        sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
                        sNode->user_call->call_time = rNode->user_call->call_time;
                        sNode->user_call->call_type = rNode->user_call->call_type;
                        sNode->user_call->user_floor = rNode->user_call->user_floor;
                        sNode->user_call->user_target = rNode->user_call->user_target;
                        sNode->serve_state = 'P';
                        sNode->next_node = NULL;
                        sNode = sNode->next_node= (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
                        sNode->next_node = NULL;
                        sNode->serve_state = 'N';
                        rNodePre->next_node = rNode->next_node;
                        flag  = 1;
                    }
                }
                if(rNode != rHeadNode.head && flag != 1){
                    rNodePre = rNodePre->next_node;
                }
                rNode = rNode->next_node;
                flag = 0;
            }
            break;
        }
        case'S':{
            int flag = 0;
            RESPONSELISTNODE *rNodePre = rHeadNode.head;
            int mark = -1;
            while(eleState.serve_list->serve_state != 'P' && eleState.serve_list->serve_state != 'E') eleState.serve_list = eleState.serve_list->next_node;
            if(eleState.serve_list->serve_state == 'P'){
                if(eleState.serve_list->user_call->user_floor > m) mark = 1;
                else mark = 0;
            }
            else if(eleState.serve_list->serve_state == 'E'){
                if(eleState.serve_list->user_call->user_target > m) mark = 1;
                else mark = 0;
            }
            if(mark == 1){
                while(rNode->next_node != NULL){
                    if(rNode->user_call->user_floor >= m && rNode->user_call->user_target > rNode->user_call->user_floor){
                        if(rNode == rHeadNode.head){
                            sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
                            sNode->user_call->call_time = rNode->user_call->call_time;
                            sNode->user_call->call_type = rNode->user_call->call_type;
                            sNode->user_call->user_floor = rNode->user_call->user_floor;
                            sNode->user_call->user_target = rNode->user_call->user_target;
                            sNode->next_node = NULL;
                            rHeadNode.head = rHeadNode.head->next_node;
                        }
                        else{
                            sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
                            sNode->user_call->call_time = rNode->user_call->call_time;
                            sNode->user_call->call_type = rNode->user_call->call_type;
                            sNode->user_call->user_floor = rNode->user_call->user_floor;
                            sNode->user_call->user_target = rNode->user_call->user_target;
                            sNode->next_node = NULL;
                            rNodePre->next_node = rNode->next_node;
                            flag  = 1;
                        }
                        if(rNode->user_call->user_floor == m){
                            sNode->serve_state = 'E';
                        }
                        else{
                            sNode->serve_state = 'P';
                        }
                        sNode = sNode->next_node = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
                        sNode->next_node = NULL;
                        sNode->serve_state = 'N';
                    }
                    if(rNode != rHeadNode.head && flag != 1){
                        rNodePre = rNodePre->next_node;
                    }
                    rNode = rNode->next_node;
                    flag = 0;
                }
            }
            else if(mark == 0){
                while(rNode->next_node != NULL){
                    if(rNode->user_call->user_floor <= m && rNode->user_call->user_target < rNode->user_call->user_floor){
                        if(rNode == rHeadNode.head){
                            sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
                            sNode->user_call->call_time = rNode->user_call->call_time;
                            sNode->user_call->call_type = rNode->user_call->call_type;
                            sNode->user_call->user_floor = rNode->user_call->user_floor;
                            sNode->user_call->user_target = rNode->user_call->user_target;
                            sNode->next_node = NULL;
                            rHeadNode.head = rHeadNode.head->next_node;
                        }
                        else{
                            sNode->user_call = (USERCALL*)malloc(sizeof(USERCALL));
                            sNode->user_call->call_time = rNode->user_call->call_time;
                            sNode->user_call->call_type = rNode->user_call->call_type;
                            sNode->user_call->user_floor = rNode->user_call->user_floor;
                            sNode->user_call->user_target = rNode->user_call->user_target;
                            sNode->next_node = NULL;
                            rNodePre->next_node = rNode->next_node;
                            flag  = 1;
                        }
                        if(rNode->user_call->user_floor == m){
                            sNode->serve_state = 'E';
                        }
                        else{
                            sNode->serve_state = 'P';
                        }
                        sNode = sNode->next_node = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
                        sNode->next_node = NULL;
                        sNode->serve_state = 'N';
                    }
                    if(rNode != rHeadNode.head && flag != 1){
                        rNodePre = rNodePre->next_node;
                    }
                    rNode = rNode->next_node;
                    flag = 0;
                }
            }
            else{
                printf("mark should be 0 or 1!\n");
                exit(1);
            }
            break;
        }
        default: printf("Error!\n"); exit(1); break;
    }
}

/*****************************
judgestate函数：判定电梯下一状态的函数
*****************************/
void judgestate() {
    int m = eleState.current_floor;
    SERVELISTNODE *s = eleState.serve_list;
    switch (eleState.run_state) {
        case 'U': {
            while (s->next_node != NULL) {
                if (s->serve_state == 'P') {
                    if (s->user_call->user_floor == (m + 1)) {
                        eleState.run_state = 'S';
                        s->serve_state = 'E';
                    }
                } else if (s->serve_state == 'E') {
                    if (s->user_call->user_target == (m + 1)) {
                        eleState.run_state = 'S';
                        s->serve_state = 'N';
                        narrive += 1;
                        printf("Finish transport %d people\n", narrive);
                    }
                }
                s = s->next_node;
            }
            eleState.current_floor = (m + 1);
            break;
        }
        case 'D': {
            while (s->next_node != NULL) {
                if (s->serve_state == 'P') {
                    if (s->user_call->user_floor == (m - 1)) {
                        eleState.run_state = 'S';
                        s->serve_state = 'E';
                    }
                } else if (s->serve_state == 'E') {
                    if (s->user_call->user_target == (m - 1)) {
                        eleState.run_state = 'S';
                        s->serve_state = 'N';
                        narrive += 1;
                        printf("Finish transport %d people\n", narrive);
                    }
                }
                s = s->next_node;
            }
            eleState.current_floor = (m - 1);
            break;
        }
        case 'S': {
            while (s->next_node != NULL && s->serve_state == 'N') {
                s = s->next_node;
            }
            if (s->next_node != NULL) {
                if (s->serve_state == 'P') {
                    if (s->user_call->user_floor > m) eleState.run_state = 'U';
                    else eleState.run_state = 'D';
                } else if (s->serve_state == 'E') {
                    if (s->user_call->user_target > m) eleState.run_state = 'U';
                    else eleState.run_state = 'D';
                }
            }
            break;
        }
        default:
            printf("Error to process next status");
            exit(1);
            break;
    }
}