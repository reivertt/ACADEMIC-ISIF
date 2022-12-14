#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void input_dosen(){
    system("cls");
    FILE *fp = fopen("dosen.txt", "r+");
    struct dosenfile dosen = {"", ""};

    if (fp == NULL){
        printf("File not found\n");
        return;
    }
    
    printf("File found\n");
    char temp[5];

    while(1){
        printf("Dosenname and NIP Input\n");
        printf("------------------------\n");
        printf("Dosen NIP: ");
        scanf("\n%s", temp);
        
        if (strcmp(temp, "000") == 0){
            printf("Input cancelled\n");
            system("cls");
            break;
        }
        
        strcpy(dosen.nip, temp);
        printf("Dosen name: ");
        scanf("\n%[^\n]%*c", dosen.dsnname);

        int lim = atoi(dosen.nip);
        fseek(fp, (lim - 1) * sizeof(struct dosenfile), SEEK_SET);
        fwrite(&dosen, sizeof(struct dosenfile), 1, fp);
        system("cls");
    }
    fclose(fp);
}

void show_dosen(){
    FILE *fp = fopen("dosen.txt", "r");
    struct dosenfile dosen = {"", ""};

    if (fp == NULL){
        printf("File not found\n");
        fclose(fp);
        return;
    }
    
    printf("File found\n");
    printf("Nama Dosen\tNIP\n");
    while (!feof(fp)){
        if (fread(&dosen, sizeof(struct dosenfile), 1, fp) != 0 && strcmp(dosen.dsnname, "") != 0){
            printf("%s\t\t%s\n", dosen.dsnname, dosen.nip);
        }
    }
    printf("\n");
    fclose(fp);
}
