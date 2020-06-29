//
// Created by 王子龙 on 2019-05-05.
//

#include <stdio.h>
#include <cstdio>
#include <cstdlib>

/*****************************
 * @funcname reConf          *
 * @feature change conf mode *
 *****************************/

void reConf() {
    int mode = 0;

    printf("Which mode?(1.manual 2.automatic)\n");

    do{
        scanf("%d", &mode);
    } while (mode != 1 && mode != 2);

    FILE *fp = fopen("_conf.ini", "w+");

    if (mode == 1) {
        fprintf(fp, "manual");
    } else {
        fprintf(fp, "automatic");
    }

    fclose(fp);
}