#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void input_mata_kuliah(){
    system("cls");
    FILE *coursefp = fopen("mata_kuliah.txt", "r+");
    struct mapelfile mapel = {"", "", 0, 0, 0, 0, 0};

    if (coursefp == NULL){
        printf("File not found\n");
        return;
    }
    
    printf("File found\n");
    char temp[5];

    while(1){
        system("cls");
        printf("===============================================\n");
        printf("|     College Course Creation in Progress     |\n");
        printf("===============================================\n");
        printf("Course ID: ");
        scanf("\n%s", temp);
        
        strcpy(mapel.mkcode, temp);
        printf("Course Name: ");
        scanf("\n%[^\n]%*c", mapel.mkname);
        printf("Course Credit: ");
        scanf("\n%d", &mapel.sks);

        system("cls");
        printf("You are about to input data regarding:\n");
        printf("Course Name: %s\n", mapel.mkname);
        printf("Course ID: %s\n", mapel.mkcode);
        printf("Course Credit: %d\n", mapel.sks);

        printf("continue? (y/n): ");
        char ttemp;
        scanf("\n%c", &ttemp);
        if (ttemp == 'y'){
            system("cls");
            printf("Inserted data is as follows:\n");
            printf("Course Name: %s\n", mapel.mkname);
            printf("Course ID: %s\n", mapel.mkcode);
            printf("Course Credit: %d\n", mapel.sks);

            int lim = atoi(mapel.mkcode);
            fseek(coursefp, (lim - 1) * sizeof(struct mapelfile), SEEK_SET);
            fwrite(&mapel, sizeof(struct mapelfile), 1, coursefp);

            printf("Data saved\n");
        }
        else{
            printf("Data not saved\n");
        }
        printf("Continue inputting data? (y/n): ");
        scanf("\n%c", &ttemp);
        if (ttemp == 'n'){
            printf("Input cancelled\n");
            printf("Returning to main menu\n");
            loading();
            system("cls");
            break;
        }
    }
    fclose(coursefp);
}

void show_mata_kuliah(){
    system("cls");
    FILE *coursefp = fopen("mata_kuliah.txt", "r");
    struct mapelfile mapel = {"", "", 0, 0, 0, 0, 0};
    
    if (coursefp == NULL){
        printf("File not found\n");
        fclose(coursefp);
        return;
    }
    
    printf("File found\n");
    
    printf("Available College Subjects\n");
    printf("------------------------\n");
    printf("Course Code\nName of the Course\n");
    while(!feof(coursefp)){
        if (fread(&mapel, sizeof(struct mapelfile), 1, coursefp) != 0 && strcmp(mapel.mkname, "") != 0){
            printf("%s\t%s\n", mapel.mkcode, mapel.mkname);
        }
    }

    printf("\n");
    fclose(coursefp);
}

void reset_mata_kuliah(){
    system("cls");
    FILE *coursefp = fopen("mata_kuliah.txt", "r+");
    struct mapelfile mapel = {"", "", 0, 0, 0, 0, 0};
    
    if (coursefp == NULL){
        printf("File not found\n");
        fclose(coursefp);
        return;
    }

    while(1){
        system("cls");
        printf("============================================\n");
        printf("|     Course Data Deletion in Progress     |\n");
        printf("============================================\n");
        show_mata_kuliah();

        printf("Enter the course code to delete: ");
        char temp[5];
        scanf("\n%s", temp);
        int lim = atoi(temp);
        fseek(coursefp, (lim - 1) * sizeof(struct mapelfile), SEEK_SET);
        if (!fread(&mapel, sizeof(struct mapelfile), 1, coursefp)){
            printf("Data not found\n");
        }
        else {
            printf("You are about to delete data regarding:\n");
            printf("Course Name: %s\n", mapel.mkname);
            printf("Course ID: %s\n", mapel.mkcode);
            printf("Course Credit: %d\n", mapel.sks);

            printf("Are you sure? (y/n): ");
            char ttemp;
            scanf("\n%c", &ttemp);
            if (ttemp == 'y'){
                strcpy(mapel.mkname, "");
                strcpy(mapel.mkcode, "");
                mapel.sks = 0;
                fwrite(&mapel, sizeof(struct mapelfile), 1, coursefp);
                printf("Data has been deleted.");
            }
            else{
                printf("Data has not been deleted.");
            }
        }

        printf(" Do you still wish to delete more data? (y/n): ");
        char ctemp;
        scanf("\n%c", &ctemp);
        if (ctemp == 'n'){
            printf("Deletion cancelled\n");
            printf("Returning to main menu\n");
            loading();
            system("cls");
            break;
        }
    }   
    fclose(coursefp);
}