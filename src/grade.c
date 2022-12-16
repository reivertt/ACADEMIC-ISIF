#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void menu_grade(){
    while(1){
        system("cls");
        FILE *sfp = fopen("mahasiswa.dat", "rb+");
        struct mahasiswafile mhs = {"", "", "", 0, {"", "", 0, 0, 0, 0, 0}, 0};
        if (sfp == NULL){
            printf("File not found\n");
            fclose(sfp);
            return;
        }
        
        printf("Welcome to The Student Grade Management Portal!\n");
        show_mahasiswa();
        printf("Input '000' to cancel\n");
        printf("Who would you like to manage?\n");

        char temp[10];
        scanf("%s", temp);

        if (strcmp(temp, "000") == 0){
            printf("Operation cancelled");
            loading();
            fclose(sfp);
            break;
        }

        int lim = atoi(temp);
        fseek(sfp, (lim * sizeof(struct mahasiswafile)), 1);
        if (!fread(&mhs, sizeof(struct mahasiswafile), 1, sfp)){
            printf("Student not found\n");
            system("pause");
        }
        else {
            while(1){
                system("cls");
                printf("Student Found!\n");
                printf("Viewing for: %s\n", mhs.mhsname);
                printf("What would you like to do?\n");
                printf("1. Show Enrolled Courses\n");
                printf("2. Manage Grades\n");
                printf("3. Show Student Grade Report\n");
                printf("4. Clear All Grades\n");
                printf("9. Back\n"); 

                int choice;
                scanf("%d", &choice);

                if (choice == 1){
                    system("cls");
                    printf("Student : %s\n", mhs.mhsname);
                    printf("is enrolled in %d course(s)\n", mhs.count);
                    printf("Code\tName\n");
                    for (int i = 0; i < mhs.count; i++){
                        printf("%s\t%s\n", mhs.mapel[i].mkcode, mhs.mapel[i].mkname);
                    }
                    printf("\n");
                    system("pause");
                }
                else if (choice == 2){
                    while(1){
                        system("cls");
                        printf("Student : %s\n", mhs.mhsname);
                        printf("is enrolled in %d course(s)\n", mhs.count);
                        printf("Code\tName\n");
                        for (int i = 0; i < mhs.count; i++){
                            printf("%s\t%s\n", mhs.mapel[i].mkcode, mhs.mapel[i].mkname);
                        }
                        printf("\n");
                        printf("Input '000' to cancel\n");
                        printf("Which course would you like to manage?\n");

                        char temp[10];
                        scanf("%s", temp);

                        if (strcmp(temp, "000") == 0){
                            printf("Operation cancelled");
                            loading();
                            break;
                        }
                        
                        int lim = -1;
                        for (int i = 0; i < mhs.count; i++){
                            if (!strcmp(temp, mhs.mapel[i].mkcode)){
                                lim = i;
                                break;
                            }
                        }

                        if (lim == -1) {
                            printf("Course not found\n");
                            break;
                        }

                        while(1){
                            system("cls");
                            printf("Course Found!\n");
                            printf("Student: %s", mhs.mhsname);
                            printf("Viewing for: %s\n", mhs.mapel[lim].mkname);
                            printf("What would you like to do?\n");
                            printf("1. Input Grades\n");
                            printf("2. Show Grades\n");
                            printf("3. Delete Grades\n");
                            printf("9. Back\n"); 

                            int choice;
                            scanf("%d", &choice);

                            if (choice == 1){
                                system("cls");
                                printf("Input Grades for %s\n", mhs.mapel[lim].mkname);
                                
                                printf("Input UTS: ");
                                scanf("%lf", &mhs.mapel[lim].uts);
                                printf("Input EAS: ");
                                scanf("%lf", &mhs.mapel[lim].eas);
                                mhs.mapel[lim].avg = (mhs.mapel[lim].uts + mhs.mapel[lim].eas) / 2;
                                
                                if (mhs.mapel[lim].avg >= 80){
                                    mhs.mapel[lim].finalgrade = 'A';
                                }
                                else if (mhs.mapel[lim].avg >= 70){
                                    mhs.mapel[lim].finalgrade = 'B';
                                }
                                else if (mhs.mapel[lim].avg >= 60){
                                    mhs.mapel[lim].finalgrade = 'C';
                                }
                                else if (mhs.mapel[lim].avg >= 50){
                                    mhs.mapel[lim].finalgrade = 'D';
                                }
                                else {
                                    mhs.mapel[lim].finalgrade = 'E';
                                }

                                system("cls");
                                printf("Student %s's", mhs.mhsname);
                                printf("grades for %s has been calculated\n", mhs.mapel[lim].mkname);
                                printf("Midterms: %.2lf\nFinals: %.2lf\nAverage: %.2lf\nFinal Grade: %c\n", mhs.mapel[lim].uts, mhs.mapel[lim].eas, mhs.mapel[lim].avg, mhs.mapel[lim].finalgrade);
                                printf("Are you sure you want to save these grades? (y/n) ");
                                char temp;
                                scanf("%c", &temp);
                                if (temp == 'y'){
                                    fwrite(&mhs, sizeof(struct mahasiswafile), 1, sfp);
                                    printf("Grades saved\n");
                                }
                                else {
                                    printf("Operation cancelled\n");
                                }
                                system("pause");
                            }
                            else if (choice == 2){
                                system("cls");
                                printf("Showing Grades for %s\n", mhs.mapel[lim].mkname);
                                printf("Midterms: %.2lf\nFinals: %.2lf\nAverage: %.2lf\nFinal Grade: %c\n", mhs.mapel[lim].uts, mhs.mapel[lim].eas, mhs.mapel[lim].avg, mhs.mapel[lim].finalgrade);
                                system("pause");
                            }
                            else if (choice == 3){
                                printf("Deleting Grades for %s\n", mhs.mapel[lim].mkname);
                                printf("Are you sure? (y/n) ");
                                char temp;
                                scanf("%c", &temp);
                                if (temp == 'y'){
                                    mhs.mapel[lim].uts = 0;
                                    mhs.mapel[lim].eas = 0;
                                    mhs.mapel[lim].avg = 0;
                                    mhs.mapel[lim].finalgrade = ' ';
                                    fwrite(&mhs, sizeof(struct mahasiswafile), 1, sfp);
                                    printf("Grades deleted\n");
                                }
                                else {
                                    printf("Operation cancelled\n");
                                    system("pause");
                                }
                            }
                            else if (choice == 9){
                                printf("Returning to course selection menu");
                                loading();
                                break;
                            }
                        }
                        
                    }
                }
                else if (choice == 3){
                    system("cls");
                    printf("Student Grade Report\n");
                    printf("Student : %s\n", mhs.mhsname);
                    printf("Code\tName\t\tUTS\tEAS\tAVG\tGrade\n");
                    for (int i = 0; i < mhs.count; i++){
                        printf("%s\t%s\t\t%.2lf\t%.2lf\t%.2lf\t%c\n", mhs.mapel[i].mkcode, mhs.mapel[i].mkname, mhs.mapel[i].uts, mhs.mapel[i].eas, mhs.mapel[i].avg, mhs.mapel[i].finalgrade);
                    }
                    printf("\n");
                    system("pause");
                }
                else if (choice == 4){
                    system("cls");
                    printf("Clearing all grades\n");
                    for (int i = 0; i < mhs.count; i++){
                        mhs.mapel[i].uts = 0;
                        mhs.mapel[i].eas = 0;
                        mhs.mapel[i].avg = 0;
                    }
                    fwrite(&mhs, sizeof(struct mahasiswafile), 1, sfp);
                    printf("All grades cleared\n");
                    system("pause");
                }
                else if (choice == 9){
                    printf("Exiting");
                    loading();
                    fclose(sfp);
                    break;
                }
                else {
                    printf("Invalid choice\n");
                    system("pause");
                }
            }
        }
    }
}