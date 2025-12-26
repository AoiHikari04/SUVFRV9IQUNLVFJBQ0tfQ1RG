#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void win(){
    FILE *fp;
    char flag[100];

    fp = fopen("flag.txt", "r");
    if (fp == NULL) {
        printf("Failed to open flag.txt\n");
        fflush(stdout);
        exit(1);
    }

    fgets(flag, sizeof(flag), fp);
    fclose(fp);

    printf("Congratulations! Here's your flag: %s\n", flag);
    fflush(stdout);
    exit(0);
}

void vuln(){
    char buffer[90];

    printf("Enter here : ");
    fflush(stdout);
    gets(buffer);

}

int main(){
    
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);

    printf("Welcome to baby_bof\n");
    fflush(stdout);

    vuln();

    printf("Thank you for playing\n");
    fflush(stdout);
    return 0;
}
