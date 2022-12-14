#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void input_dosen(){
    system("cls");
    FILE *dosenfp = fopen("dosen.txt", "w+");
    struct dosenfile dosen = {"", ""};

    if (dosenfp == NULL){
        printf("File not found\n");
        return;
    }
    
    printf("File found\n");
    char temp[5];

    while(1){
        system("cls");
        printf("====================================================\n");
        printf("|     Student Advisor Registration in Progress     |\n");
        printf("====================================================\n");
        printf("Dosen NIP: ");
        scanf("\n%s", temp);
        
        strcpy(dosen.nip, temp);
        printf("Dosen name: ");
        scanf("\n%[^\n]%*c", dosen.dsnname);

        system("cls");
        printf("You are about to input data regarding:\n");
        printf("Advisor's Name: %s\n", dosen.dsnname);
        printf("NIP: %s\n", dosen.nip);

        printf("continue? (y/n): ");
        char ttemp;
        scanf("\n%c", &ttemp);
        if (ttemp == 'y'){
            system("cls");
            printf("Inserted data is as follows:\n");
            printf("Advisor's Name: %s\n", dosen.dsnname);
            printf("NIP: %s\n", dosen.nip);

            int lim = atoi(dosen.nip);
            fseek(dosenfp, (lim - 1) * sizeof(struct dosenfile), SEEK_SET);
            fwrite(&dosen, sizeof(struct dosenfile), 1, dosenfp);

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
    fclose(dosenfp);
}

void show_dosen(){
    FILE *dosenfp = fopen("dosen.txt", "r");
    struct dosenfile dosen = {"", ""};

    if (dosenfp == NULL){
        printf("File not found\n");
        fclose(dosenfp);
        return;
    }
    
    printf("File found\n");

    printf("Nama Dosen\tNIP\n"); //todo fix this lmao
    while (!feof(dosenfp)){
        if (fread(&dosen, sizeof(struct dosenfile), 1, dosenfp) != 0 && strcmp(dosen.dsnname, "") != 0){
            printf("%s\t\t%s\n", dosen.dsnname, dosen.nip);
        }
    }
    printf("\n");
    fclose(dosenfp);
}

void reset_dosen(){
    system("cls");
    FILE *dosenfp = fopen("dosen.txt", "r+");
    struct dosenfile dosen = {"", ""};

    if (dosenfp == NULL){
        printf("File not found\n");
        fclose(dosenfp);
        return;
    }

    while(1){
        system("cls");
        printf("=============================================\n");
        printf("|     Advisor Data Deletion in Progress     |\n");
        printf("=============================================\n");
        show_dosen();

        printf("Input NIP to delete: ");
        char temp[5];
        scanf("\n%s", temp);
        int lim = atoi(temp);
        fseek(dosenfp, (lim - 1) * sizeof(struct dosenfile), SEEK_SET);

        if (!fread(&dosen, sizeof(struct dosenfile), 1, dosenfp)){
            printf("Data not found\n");
        }
        else {
            printf("You are about to delete data regarding:\n");
            printf("Advisor Name: %s\n", dosen.dsnname);
            printf("NIP: %s\n", dosen.nip);

            printf("Are you sure? (y/n): ");
            char sure;
            scanf("\n%c", &sure);
            if (sure == 'y'){
                strcpy(dosen.dsnname, "");
                strcpy(dosen.nip, "");
                fwrite(&dosen, sizeof(struct dosenfile), 1, dosenfp);
                printf("Data has been deleted.");
            }
            else{
                printf("Data has not been deleted.");
            }
        }
        
        printf(" Continue deleting data? (y/n): ");
        char more;
        scanf("\n%c", &more);
        if (more == 'n'){
            printf("Deletion cancelled\n");
            printf("Returning to main menu");
            loading();
            system("cls");
            break;
        }
    }
    fclose(dosenfp);
}