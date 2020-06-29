//
// Created by 王子龙 on 2019-06-01.
//

#ifndef LAB7_18281218_LAB7_DATA_H
#define LAB7_18281218_LAB7_DATA_H

///////////////////////Macro definition///////////////////////
#define MAX_STR_LEN 1024
#define defaultPath "/Users/wangzilong/Desktop/Study/Assignment/ProgramDesign/Lab7_18281218/DataDirectory/dataFile.txt"

/////////////////////// Data Structure ///////////////////////
//User call information.
typedef struct UserCall {
    int user_floor; //User's floor.
    int user_target;//user target floor.
    int call_time;  //user call time.
    char call_type; //Upward -> "U", Downward -> "D", which means the status of user.
} USERCALL;

//Serve line list node
typedef struct ServeListNode {
    char serve_state;                   //state of the elevator. Upward -> "U", Downward -> "D", Stop -> "S".
    USERCALL *user_call;                //When the elevator respond, the element be pointed.
    struct ServeListNode *next_node;    //To store the address of the next node;
} SERVELISTNODE;

//The state of the elevator
typedef struct elevatorstate {
    int current_floor;          //current floor of the elevator.
    char run_state;             //the running status of the elevator.
    SERVELISTNODE *serve_list;  //Pointer of the serving line.
} ELEVATORSTATE;

//Pending response command link list struct
typedef struct ResponseListNode {
    USERCALL *user_call;                 //user instruction number.
    struct ResponseListNode *next_node;  //To store the address of the next node;
} RESPONSELISTNODE;

//Link list head node statement
typedef struct ResponseListHeadNode {
    int list_num;            //Pending response user number.
    RESPONSELISTNODE *head;  //Address of the first data node.
    RESPONSELISTNODE *tail;  //Address of the last data node.
} RESPONSELISTHEADNODE;

#endif //LAB7_18281218_LAB7_DATA_H
