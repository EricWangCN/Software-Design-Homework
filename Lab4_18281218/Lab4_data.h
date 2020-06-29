//
// Created by 王子龙 on 2019-04-03.
// Email: wangzilong0201@gmail.com
//

#ifndef LAB4_18281218_LAB4_DATA_H
#define LAB4_18281218_LAB4_DATA_H

#define MAX_STR_LEN 100000

typedef struct configinfo{
    char filesavepath[MAX_STR_LEN]; //To record the save path of the file
    char filename[MAX_STR_LEN];     //To record the name of the file
    char fileandpath[MAX_STR_LEN];  //To record the path and name of the file
    int number;                     //To record the number of values to be created
    int maxvalue1;                  //To record the max limitation of the value 1&2
    int minvalue1;                  //To record the min limitation of the value 1&2
    int maxvalue2;                  //To record the max limitation of the value 3
    int minvalue2;                  //To record the min limitation of the value 3
    int recordCount1;               //To record the max limitation of the number of values
    int recordCount2;               //To record the min limitation of the number of values
    int recordcount1;               //To record if the number is input
    int recordcount2;               //To record if the filename is input
    int recordcount3;               //To record if the type is input
    int type;
}CONF;

typedef struct DataItem{
    int item1 ; //The first item.
    int item2 ; //The second item.
    int item3 ; //The third item.
} DATAITEM;

#endif //LAB4_18281218_LAB4_DATA_H
