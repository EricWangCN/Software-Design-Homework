/****************************************************\
作者信息：
    姓名：王子龙
版权声明：
    版权由王子龙所有
模块名称:
    实验2（输出随机数）
摘要:
    文件、命令行参数、随机数生成、数组、指针、结构的学习
其它说明:

模块历史:
　　王子龙2019年3月12日创建该文件 wangzilong0201@gmail.com

**********************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct dataContainer {
    int value[3];
} DATA;

int getCmd(int *Num,char Name[],int argc,char *argv[]);
int getTxt(char str[]);
int getNumofStr(char str[]);
void writeArray(int dArray[][3], int n, DATA a[]);

int main(int argc,char *argv[]) {
    int num = 0;
    char name[10000];
    srand((unsigned)time(0));

    switch (getCmd(&num,name,argc,argv)) {
        case 0:{
            strcpy(name,"RandomValue.txt");
            num = rand() % 1000;
            break;
        }
        case 1:{
            num = rand() % 1000;
            break;
        }
        case 2:{
            strcpy(name,"RandomValue.txt");
            break;
        }
        case 3:
            break;
        case 4:
            printf("Error!\n");
            break;
        default:
            printf("Error!\n");
            break;
    }

    int a[num][3];
    int sta = 0, s;
    DATA data[num];
    writeArray(a, num, data);
    while (sta == 0) {
        printf("Please choose the container(0:array,1:struct)");
        scanf("%d",&s);
        if (s == 0 || s == 1) {
            sta = 1;
        }
    }

    FILE *fp = fopen(name, "w+");

    fprintf(fp, "%d\n", num);
    if (s == 0) {
        for (int i = 0; i < num; ++i) {
            fprintf(fp, "%3d,%3d,%3d\n", a[i][0], a[i][1], a[i][2]);
        }
    } else {
        for (int i = 0; i < num; ++i) {
            fprintf(fp, "%3d,%3d,%3d\n", data->value[0], data->value[1], data->value[2]);
        }
    }
    fclose(fp);

    return 0;
}

/**********************************************************
 * 函数名称：getCmd
 * 函数作用：获取在命令行参数传入的数据组数和文件名
 * 输入参数：int *Num,char Name[],int argc,char *argv[]
 * 返回值：在命令行输入的值的状态
 **********************************************************/

int getCmd(int *Num,char Name[],int argc,char *argv[]) {
    if (argc == 1) return 0;
    else if (argc == 2) {
        if (getTxt(argv[1])){
            int i = 0;
            while(argv[1][i] != '\0') {
                Name[i] = argv[1][i];
                i++;
            }
            Name[i+1]  = '\0';
            return 1;
        }
        else {
            for (int i = 0; i < getNumofStr(argv[1]); ++i) {
                *Num += (argv[1][i] - 48) * pow(10,getNumofStr(argv[1]) - i - 1);
            }
            return 2;
        }
    }
    else if (argc == 3) {
        if (getTxt(argv[1])) {
            int i = 0;
            while(argv[1][i] != '\0') {
                Name[i] = argv[1][i];
                i++;
            }
            Name[i+1]  = '\0';
            for (int i = 0; i < getNumofStr(argv[2]); ++i) {
                *Num += (argv[2][i] - 48) * pow(10,getNumofStr(argv[2]) - i - 1);
            }
        }
        else {
            int i = 0;
            while(argv[2][i] != '\0') {
                Name[i] = argv[2][i];
                i++;
            }
            Name[i+1]  = '\0';
            for (int i = 0; i < getNumofStr(argv[1]); ++i) {
                *Num += (argv[1][i] - 48) * pow(10,getNumofStr(argv[1]) - i - 1);
            }
        }
        return 3;
    }
    else return 4;
}

/**********************************************************
 * 函数名称：getTxt
 * 函数作用：判断字符串内是否含有".txt"
 * 输入参数：str[]
 * 返回值：是或否
 **********************************************************/

int getTxt(char str[]) {
    if(strstr(str,".txt")) return 1;
    else if(strstr(str,".Txt")) return 1;
    else if(strstr(str,".tXt")) return 1;
    else if(strstr(str,".TXt")) return 1;
    else if(strstr(str,".txT")) return 1;
    else if(strstr(str,".TxT")) return 1;
    else if(strstr(str,".TXT")) return 1;
    else if(strstr(str,".tXT")) return 1;
    else return 0;
}

/**********************************************************
 * 函数名称：getNumofStr
 * 函数作用：获取字符串长度
 * 输入参数：str[]
 * 返回值：字符串长度
 **********************************************************/

int getNumofStr(char str[]) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}

/**********************************************************
 * 函数名称：writeArray
 * 函数作用：将随机数写入数组
 * 输入参数：*dArray[],n
 * 返回值：N/A
 **********************************************************/

void writeArray(int dArray[][3], int n, DATA a[]) {
    for (int i = 0; i < n; ++i) {
        dArray[i][0] = rand() % 1000;哇Z
        dArray[i][1] = rand() % 1000;
        dArray[i][2] = rand() % 1000;
        a->value[0] = dArray[i][0];
        a->value[1] = dArray[i][1];
        a->value[2] = dArray[i][2];
    }
 }