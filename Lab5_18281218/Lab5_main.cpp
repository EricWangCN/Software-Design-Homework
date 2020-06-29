//
// Created by 王子龙 on 2019-04-19.
//

#include "Lab5_call.h"
#include "Lab5_data.h"
#include "Lab5_loadfile.h"
#include "Lab5_main.h"
#include "Lab5_view.h"
#include <stdio.h>


/******************************
 * @funcname run              *
 * @feature run all funcntion *
 * @param argc                *
 * @param argv                *
 * @return 0: error           *
 *         1: pass            *
 ******************************/

int run(int argc, char *argv[]) {
    int Status = Menu();
    fileInfo fileInfo1;
    fileInfo1.status = 0;
    switch ( Initialization() ) {
        case 0: {//Initialization error!
            return 0;
        }
        case 1: {//Manual Mode
            fileInfo1.status = 1;
            break;
        }
        case 2: {//Automatic Mode
            break;
        }
        default: {
            printf("Unknown error!");
            return 0;
        }
    }

    work(Status, fileInfo1);
    print(Status);

    return 1;
}

/**************************************
 * @funcname Menu                     *
 * @feature Menu                      *
 * @return Status(Option user choose) *
 **************************************/

int Menu() {
    int Status = 0;

    printf("Please choose mode:\n");
    printf("1. Use Lab4 to create file (Text)\n");
    printf("2. Use Lab4 to create file (Binary)\n");
    printf("3. Read exact data file (2D array)\n");
    printf("4. Read exact data file (struct Array)\n");
    printf("5. Read exact data file (pointer Array)\n");
    printf("6. Read exact data file (Linked lists)\n");
    printf("7. Use Lab4 to create file, and read its data file (TEXT OUT & 2D Array storage)\n");
    printf("8. Use Lab4 to create file, and read its data file (TEXT OUT & struct array storage)\n");
    printf("9. Use Lab4 to create file, and read its data file (TEXT OUT & pointer array storage)\n");
    printf("10.Use Lab4 to create file, and read its data file (TEXT OUT & linked lists storage)\n");
    printf("11.Use Lab4 to create file, and read its data file (Binary OUT & 2D Array storage)\n");
    printf("12.Use Lab4 to create file, and read its data file (Binary OUT & struct array storage)\n");
    printf("13.Use Lab4 to create file, and read its data file (Binary OUT & pointer array storage)\n");
    printf("14.Use Lab4 to create file, and read its data file (Binary OUT & linked lists storage)\n");
    printf("15.Set config file again\n");
    printf("0. Exit\n");

    scanf("%d", &Status);

    return Status;
}