#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*
todo implement the input function cause what the fuck is this
todo somehow figure out how to print shit cause thats still beyond my capablities
! get good
*/

void input_mahasiswa(){
    system("cls");
    FILE *sfp = fopen("mahasiswa.txt", "w+");
    struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}};
    char temp[5], ttemp;


    if (sfp == NULL){
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
        printf("You are about to input data regarding:\n");
        printf("Student Name: %s\n", mtemp.mhsname);
        printf("Student NRP: %s\n", mtemp.nrp);
        printf("Advisor: %s\n", mtemp.dosen);

        printf("Continue? (y/n): ");
        scanf("\n%c", &ttemp);
        if(ttemp == 'y'){
            mhs = mtemp;
            printf("Inserted data is as follows:\n");
            printf("Student Name: %s\n", mhs.mhsname);
            printf("Student NRP: %s\n", mhs.nrp);
            printf("Advisor: %s\n", mhs.dosen);

            int lim = atoi(mhs.nrp);
            fseek(sfp, (lim - 1) * sizeof(struct mahasiswafile), SEEK_SET);
            fwrite(&mhs, sizeof(struct mahasiswafile), 1, sfp);
            
            printf("Data saved\n");
        }
        else{
            printf("Data not saved\n");
        }

        printf("Continue inputting data? (y/n): ");
        scanf("\n%c", &ttemp);
        if (ttemp == 'y'){
            system("cls");
            continue;
        }
        else{
            printf("Input cancelled\n");
            printf("Returning to main menu\n");
            loading();
            system("cls");
            break;
        }
        fclose(dosenfp);
    }
    fclose(sfp);
}

void show_mahasiswa(){
    FILE *sfp = fopen("mahasiswa.txt", "r");
    if (sfp == NULL){
        printf("File not found\n");
        return;
    }

    struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}};

    printf("Registered Students\n");
    printf("------------------------\n");
    printf("Student NRP\tStudent Name\tAdvisor Name\n");
    while(!feof(sfp)){
        if (fread(&mhs, sizeof(struct mahasiswafile), 1, sfp) != 0 && strcmp(mhs.mhsname, "") != 0){
            printf("%s\t%s\t%s\n", mhs.nrp, mhs.mhsname, mhs.dosen);
        }
    }
    printf("\n");
    fclose(sfp);
}

void reset_mahasiswa(){
    //*this is probably gonna get heavily altered tomorrow
    system("cls");
    FILE *sfp = fopen("mahasiswa.txt", "r+");
    struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}};

    if (sfp == NULL){
        printf("File not found\n");
        fclose(sfp);
        return;
    }

    while(1){
        system("cls");
        printf("=============================================\n");
        printf("|     Student Data Deletion in Progress     |\n");
        printf("=============================================\n");
        show_mahasiswa();

        printf("Input Student NRP to delete: ");
        char temp[5];
        scanf("\n%s", temp);
        int lim = atoi(temp);
        fseek(sfp, (lim - 1) * sizeof(struct mahasiswafile), SEEK_SET);
        if (!fread(&mhs, sizeof(struct mahasiswafile), 1, sfp)) {
            printf("Student not found\n");
        }
        else {
            printf("You are about to delete data regarding:\n");
            printf("Student Name: %s\n", mhs.mhsname);
            printf("Student NRP: %s\n", mhs.nrp);
            printf("Advisor: %s\n", mhs.dosen);

            printf("Are you sure? (y/n): ");
            char ttemp;
            scanf("\n%c", &ttemp);
            if (ttemp == 'y'){
                strcpy(mhs.mhsname, "");
                strcpy(mhs.nrp, "");
                strcpy(mhs.dosen, "");
                fwrite(&mhs, sizeof(struct mahasiswafile), 1, sfp);
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
            printf("Returning to main menu\n");
            loading();
            system("cls");
            break;
        }
    }
    fclose(sfp);
}