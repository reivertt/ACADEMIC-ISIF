#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void input_mata_kuliah(){
    system("cls");
    FILE *mkdat = fopen("mata_kuliah.txt", "w+");
    struct mapelfile mapel = {"", "", 0, 0, 0, 0, 0};

    if (mkdat == NULL){
        printf("File not found\n");
        return;
    }
    
    printf("File found\n");
    char temp[5];

    while(1){
        printf("College Subject Input\n");
        printf("------------------------\n");
        printf("College Subject Code: ");
        scanf("\n%s", temp);
        
        if (strcmp(temp, "000") == 0){
            printf("Input cancelled\n");
            system("cls");
            break;
        }
        
        strcpy(mapel.mkcode, temp);
        printf("College Subject Name: ");
        scanf("\n%[^\n]%*c", mapel.mkname);

        int lim = atoi(mapel.mkcode);
        fseek(mkdat, (lim - 1) * sizeof(struct mapelfile), SEEK_SET);
        fwrite(&mapel, sizeof(struct mapelfile), 1, mkdat);
        system("cls");
    }
    fclose(mkdat);
}

void show_mata_kuliah(){
    system("cls");
    FILE *mkdat = fopen("mata_kuliah.txt", "r");
    if (mkdat == NULL){
        printf("File not found\n");
        return;
    }
    
    printf("File found\n");
    struct mapelfile mapel = {"", "", 0, 0, 0, 0, 0};
    
    printf("Available College Subjects\n");
    printf("------------------------\n");
    printf("Course Code\nName of the Course\n");
    while(!feof(mkdat)){
        if (fread(&mapel, sizeof(struct mapelfile), 1, mkdat) != 0 && strcmp(mapel.mkname, "") != 0){
            printf("%s\t%s\n", mapel.mkcode, mapel.mkname);
        }
    }

    printf("\n...press any key to continue\n");
    printf("\n");
    system("pause > null");
    
    fclose(mkdat);
}