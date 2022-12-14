#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*
todo implement the input function cause what the fuck is this
todo somehow figure out how to print shit cause thats still beyond my capablities
! get good
*/

//? figure out how to declare a struct

void input_mahasiswa(){
    system("cls");
    FILE *fp = fopen("mahasiswa.txt", "r+");
    struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}};
    char temp[5], ttemp;


    if (fp == NULL){
        printf("File not found\n");
        return;
    }
    
    printf("\nFile found\n");
    
    while(1){
        struct mahasiswafile mtemp = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}};
        printf("Student Input\n");
        printf("Input '000' to cancel operation\n");
        printf("------------------------\n");
        printf("Student NRP: ");
        scanf("\n%s", mtemp.nrp);
        
        if (strcmp(mtemp.nrp, "000") == 0){
            printf("Input cancelled\n");
            system("cls");
            break;
        }

        printf("Student Name: ");
        scanf("\n%[^\n]%*c", mtemp.mhsname);
        
        struct dosenfile sdosen = {"", "" };
        FILE *dosenfp = fopen("dosen.txt", "r");

        while(1){
            system("cls");
            show_dosen();
            printf("Assign an Advisor for %s\n", mtemp.mhsname);
            printf("Advisor's NIP Code: ");
            scanf("\n%s", temp);
            int dlim = atoi(temp);
            if (!fseek(dosenfp, (dlim - 1) * sizeof(struct dosenfile), SEEK_SET)){
                fread(&sdosen, sizeof(struct dosenfile), 1, dosenfp);
                strcpy(mtemp.dosen, sdosen.dsnname);
                system("cls");
                printf("Advisor succesfully assigned\n");
                break;
            }
            printf("Invalid NIP, please try again!\n");
        }
        
        system("cls");
        printf("The data that will be inputted is:\n");
        printf("Student Name: %s\n", mtemp.mhsname);
        printf("Student NRP: %s\n", mtemp.nrp);
        printf("Advisor: %s\n", mtemp.dosen);
        printf("The inserted will be saved to the database, make sure it is correct!\n");
        printf("Continue? (y/n): ");
        scanf("\n%c", &ttemp);
        if(ttemp == 'y'){
            mhs = mtemp;
            printf("Inserted data is as follows:\n");
            printf("Student Name: %s\n", mhs.mhsname);
            printf("Student NRP: %s\n", mhs.nrp);
            printf("Advisor: %s\n", mhs.dosen);

            int lim = atoi(mhs.nrp);
            fseek(fp, (lim - 1) * sizeof(struct mahasiswafile), SEEK_SET);
            fwrite(&mhs, sizeof(struct mahasiswafile), 1, fp);
            
            printf("Data saved\n");
        }
        else{
            printf("Data not saved\n");
        }

        printf("Do you want to input another student? (y/n): ");
        scanf("\n%c", &ttemp);
        if (ttemp == 'y'){
            continue;
        }
        else{
            break;
        }
    }
}

void show_mahasiswa(){
    FILE *fp = fopen("mahasiswa.txt", "r");
    if (fp == NULL){
        printf("File not found\n");
        return;
    }

    struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}};

    printf("Registered Students\n");
    printf("------------------------\n");
    printf("Student NRP\tStudent Name\tAdvisor Name\n");
    while(!feof(fp)){
        if (fread(&mhs, sizeof(struct mahasiswafile), 1, fp) != 0 && strcmp(mhs.mhsname, "") != 0){
            printf("%s\t%s\t%s\n", mhs.nrp, mhs.mhsname, mhs.dosen);
        }
    }
    printf("\n");
    fclose(fp);
}