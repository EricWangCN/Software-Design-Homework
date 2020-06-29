/***********************************************
 * @filename                                   *
 *      Lab3_data.h                            *
 * @filehistory                                *
 *  Mar.13th, 2019:                            *
 *      Created by Wang Zilong                 *
 *          E-mail: wangzilnog0201@gmail.com   *
 ***********************************************/

#ifndef LAB3_18281218_LAB3_DATA_H
#define LAB3_18281218_LAB3_DATA_H

#define MAX_STR_LEN 1000

#define MIN_A 0
#define MIN_B 1000
#define MIN_C 1
#define MAX_A 2000
#define MAX_B 30000
#define MAX_C 32768

typedef struct configinfo{
    char filesavepath[MAX_STR_LEN]; //To record the save path of the file
    char filename[MAX_STR_LEN];     //To record the name of the file
    int number;                     //To record the number of values to be created
    int maxvalue1;                  //To record the max limitation of the value 1&2
    int minvalue1;                  //To record the min limitation of the value 1&2
    int maxvalue2;                  //To record the max limitation of the value 3
    int minvalue2;                  //To record the min limitation of the value 3
    int recordCount1;               //To record the max limitation of the number of values
    int recordCount2;               //To record the min limitation of the number of values
    int recordcount1;               //To record if the number is input
    int recordcount2;               //To record if the filename is input
}CONF;

#endif //LAB3_18281218_LAB3_DATA_H
