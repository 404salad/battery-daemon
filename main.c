#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <string.h>

int main() {
    MessageBoxA(NULL, "Message", "Title", MB_OK);
    FILE *fp = popen("bash check.sh", "r");
    if (fp == NULL) {
        perror("popen error");
        exit(EXIT_FAILURE);
    }

    int c;
    char percent[2] = "";
    while ((c = fgetc(fp)) != EOF) {
        char charStr[2];
        sprintf(charStr, "%c", c);
        strcat(percent, charStr);    
    }
    if (pclose(fp) == -1) {
        perror("pclose error");
        exit(EXIT_FAILURE);
    }

    int battery = atoi(percent);
    if(battery>20) {
        puts("suffient battery");
    }
    else {
        puts("charge now");
    }


    return 0;
}

