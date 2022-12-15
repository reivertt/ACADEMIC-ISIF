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
    FILE *sfp = fopen("mahasiswa.txt", "r+");
    struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}, 0};
    char temp[5], ttemp;


    if (sfp == NULL){
        printf("File not found\n");
        return;
    }
    
    printf("\nFile found\n");
    
    while(1){
        struct mahasiswafile mtemp = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}, 0};
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
            //!iki hrs direvisi lagi huek (hilangin temp)
            system("cls");
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

    struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}, 0};

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

void manage_student(){
    while(1){
        FILE *sfp = fopen("mahasiswa.txt", "r+");
        struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}, 0};
        if (sfp == NULL){
            printf("File not found\n");
            fclose(sfp);
            return;
        }

        system("cls");
        printf("====================================================\n");
        printf("|     Welcome to The Student Management Portal     |\n");
        printf("====================================================\n");
        show_mahasiswa();
        printf("Who would you like to view?\n");
        printf("Input '000' to cancel operation\n");
        char tremp[5];
        scanf("\n%s", tremp);

        if (strcmp(tremp, "000") == 0){
            printf("Operation cancelled");
            loading();
            system("cls");
            break;
        }

        int lim = atoi(tremp);
        fseek(sfp, (lim - 1) * sizeof(struct mahasiswafile), SEEK_SET);
        if (!fread(&mhs, sizeof(struct mahasiswafile), 1, sfp)){
            printf("Student not found\n");
            system("pause");
        }
        else {
            while (1){
                system("cls");
                printf("Student found!\n");
                printf("Viewing for: %s\n", mhs.mhsname);
                printf("What would you like to do?\n");
                printf("1. View Student Data\n");  //shows nrp advisor 
                printf("2. View Enrolled Courses\n"); //shows courses
                printf("3. Assign a Course\n");
                printf("4. Resign from a Course\n");
                printf("5. View Course Grades\n"); //looks for that course and then shows course grade
                printf("6. Delete Data\n");
                printf("9. Return to Main Menu\n");

                printf("Input: ");
                int choice;
                scanf("%d", &choice);

                if (choice == 1){
                    system("cls");
                    printf("Student Name: %s\n", mhs.mhsname);
                    printf("Student NRP: %s\n", mhs.nrp);
                    printf("Advisor: %s\n", mhs.dosen);
                    printf("Registered Courses: %d\n", mhs.count);
                    printf("Total Credits: %d\n", mhs.skstotal);
                    system("pause");
                }
                else if (choice == 2){
                    //shows courses
                    system("cls");
                    printf("Student: %s\n", mhs.mhsname);
                    printf("is currently is enrolled in %d course(s) and has %d credit(s)\n", mhs.count, mhs.skstotal);
                    printf("=================================================\n");
                    for (int i = 0; i < mhs.count; i++){
                        printf("Course name: %s\n", mhs.mapel[i].mkname);
                        printf("Course code: %s\n", mhs.mapel[i].mkcode);
                        printf("Course credits: %d\n", mhs.mapel[i].sks);
                    }
                    system("pause");
                }
                else if (choice == 3){
                    //assign a course
                    while(1){
                        system("cls");
                        printf("Assigning a course\n");
                        printf("Student: %s\n", mhs.mhsname); 
                        printf("is currently is enrolled in %d course(s) and has %d credit(s)\n", mhs.count, mhs.skstotal);
                        show_mata_kuliah();
                        printf("Input course code: ");
                        char temp[10];
                        scanf("%s", temp);

                        system("cls");
                        printf("Searching");
                        loading();

                        //checks if its already assigned
                        int bloo = 0;
                        for (int i = 0; i < mhs.count; i++){
                            if (!strcmp(temp, mhs.mapel[i].mkcode)){
                                printf("Course already assigned\n");
                                bloo = 1;
                                break;
                            }
                        }
                        if (bloo == 0){
                            //if it aint then go assign it
                            FILE *mkfp = fopen("mata_kuliah.txt", "r");
                            struct mapelfile mk = {"", "", 0, 0, 0, 0, 0};
                            
                            if (mkfp == NULL){
                                printf("File not found\n");
                                fclose(mkfp);
                                break;
                            }

                            int lim = atoi(temp);
                            fseek(mkfp, (lim - 1) * sizeof(struct mapelfile), SEEK_SET);
                            if (!fread(&mk, sizeof(struct mapelfile), 1, mkfp)) {
                                printf("Course not found\n");
                            }
                            else {
                                printf("Course found!\n");
                                printf("Course Name: %s\n", mk.mkname);
                                printf("Course Credits: %d\n", mk.sks);
                                printf("Course Code: %s\n", mk.mkcode);

                                if (mhs.skstotal + mk.sks > MAX){
                                    printf("Student cannot enroll in more than %d credits\n", MAX);
                                    printf("Returning to previous menu");
                                    loading();
                                    break;
                                }

                                printf("Are you sure you want to assign this course? (y/n): ");
                                char ttemp;
                                scanf("\n%c", &ttemp);
                                if (ttemp == 'y'){
                                    mhs.mapel[mhs.count] = mk;
                                    mhs.count++;
                                    mhs.skstotal += mk.sks;
                                    fwrite(&mhs, sizeof(struct mahasiswafile), 1, sfp);
                                    printf("Course assigned\n");
                                }
                                else {
                                    printf("Course not assigned\n");
                                }
                            }
                        }
                        printf("Assign another course? (y/n): ");
                        char ttemp;
                        scanf("\n%c", &ttemp);
                        if (ttemp == 'n'){
                            break;
                        }
                    }
                    printf("Returning to previous menu");
                    loading();
                    system("cls");
                }
                else if (choice == 4){
                    //resign from a course
                    while(1){
                        system("cls");
                        printf("Student: %s\n", mhs.mhsname);
                        printf("is currently is enrolled in %d course(s) and has %d credit(s)\n", mhs.count, mhs.skstotal);
                        printf("=================================================\n");
                        printf("Course code\tCourse name\n");
                        for (int i = 0; i < mhs.count; i++){
                            printf("%s %s\n", mhs.mapel[i].mkcode, mhs.mapel[i].mkname);
                        }
                        printf("=================================================\n");
                        printf("Enter '000' to return to previous menu\n");
                        printf("Input course code to be resigned: ");
                        char temp[10];
                        scanf("%s", temp);

                        if (!strcmp(temp, "000")){
                            break;
                        }

                        for (int i = 0; i < mhs.count; i++){
                            if (!strcmp(temp, mhs.mapel[i].mkcode)){
                                printf("Course found!\n");
                                printf("Course Name: %s\n", mhs.mapel[i].mkname);
                                printf("Course Credits: %d\n", mhs.mapel[i].sks);
                                printf("Course Code: %s\n", mhs.mapel[i].mkcode);

                                printf("Are you sure you want to resign from this course? (y/n): ");
                                char ttemp;
                                scanf("\n%c", &ttemp);
                                if (ttemp == 'y'){
                                    for (int j = i; j < mhs.count - 1; j++){
                                        mhs.mapel[j] = mhs.mapel[j + 1];
                                    }
                                    mhs.count--;
                                    mhs.skstotal -= mhs.mapel[i].sks;
                                    fwrite(&mhs, sizeof(struct mahasiswafile), 1, sfp);
                                    printf("Course resigned\n");
                                }
                                else {
                                    printf("Course not resigned\n");
                                }
                                break;
                            }
                        }
                        printf("Resign from another course? (y/n): ");
                        char ttemp;
                        scanf("\n%c", &ttemp);
                        if (ttemp == 'n'){
                            printf("Returning to previous menu");
                            loading();
                            break;
                        }
                    }


                }
                else if (choice == 5){
                    //looks for that course and then shows course grade
                }
                else if (choice == 6){
                    //lengkapin with courses
                    printf("You are about to delete data regarding:\n");
                    printf("Student Name: %s\n", mhs.mhsname);
                    printf("Student NRP: %s\n", mhs.nrp);
                    printf("Advisor: %s\n", mhs.dosen);

                    printf("Are you sure? (y/n): ");
                    char ttemp;
                    scanf("\n%c", &ttemp);
                    if (ttemp == 'y'){
                        //ini masih nyisa
                        strcpy(mhs.mhsname, "");
                        strcpy(mhs.nrp, "");
                        strcpy(mhs.dosen, "");
                        fwrite(&mhs, sizeof(struct mahasiswafile), 1, sfp);
                        fclose(sfp);
                        printf("Data has been deleted.");
                        printf(" Returning to main menu\n");
                        loading();
                        system("cls");
                        break;
                    }
                    else{
                        printf("Data has not been deleted.");
                    }
                }
                else if (choice == 9){
                    printf("Returning to main menu\n");
                    loading();
                    system("cls");
                    break;
                }
                else{
                    printf("Invalid input\n");
                }
            }
        }
        fclose(sfp);
    }
}