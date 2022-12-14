#include <stdio.h>
#include <windows.h>
#include "header.h"

/*
* main program is moreless finished
TODO i gotta somehow figure out how to successfully implement the input function
TODO second on the list is to assign stuff and add linear search
golly linear search sounds fun
*/

int main(){
    sleep(3);
    trademark();
    system("pause");

    while(1){
        system("cls");
        //center align
        printf("Please enter your credentials\n");
        printf("Available Profiles\n");
        printf("____________________  ____________________\n");
        printf("|   Administrator   | |     Student      |\n");
        printf("|         1         | |         2        |\n");
        printf("____________________  ____________________\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1){
            printf("============================================================\n");
            printf("|        Informatics Engineering Administrator Portal       |\n");
            printf("============================================================\n");
        }
        else if (choice == 2){
            system("cls");
            printf("============================================================\n");
            printf("|           Informatics Engineering Student Portal          |\n");
            printf("============================================================\n");
            printf("Please enter your credentials...");
            // scanf("%s");
            system("cls");
            printf("Loading...\n");
            sleep(1);
            printf("Login Successful!\n");
            sleep(2);
            system("cls");
            printf("Welcome to the Informatics Engineering Student Portal!\n");
            printf("What would you like to do?\n");
            printf("1. Student Information\n");
            printf("2. Course Information\n");
            printf("9. Log out\n");
            int schoice;
            scanf("%d", &schoice);
            if (schoice == 1){
                system("cls");
                printf("Welcome to the Student Information Portal\n");
                printf("What would you like to do?\n");
                printf("1. View registered students\n");
                printf("2. View student information\n");
                printf("3. Register a student\n");
                printf("9. Back\n");
                int sschoice;
                scanf("%d", &sschoice);
                if (sschoice == 1){
                    system("cls");
                    show_mahasiswa();
                    system("pause");
                }
                else if (sschoice == 2){
                    system("cls");
                    printf("Enter the student's NRP: ");
                    //todo how do i do this?
                }
                else if (sschoice == 3){
                    system("cls");
                    input_mahasiswa();
                }
                else if (sschoice == 9){
                    break;
                }
                else {
                    printf("Invalid input, please try again\n");
                    continue;
                }
            }
        }
        else {
            printf("Invalid input, please try again\n");
            continue;
        }
    }
    while(1){
        system("cls");
        header();   

        printf("Welcome to the (bootleg) University Academic Portal\n");
        printf("What would you like to do?\n");
        printf("1. Academic Participants\n");
        printf("2. College Subjects\n");
        printf("3. Student Grades\n");
        printf("4. System Information\n");
        printf("9. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        if (choice == 1){
            system("cls");
            while(1){
                system("cls");
                int subchoice;
                printf("Welcome to the Academic Community Portal\n");
                printf("What would you like to do?\n");
                printf("1. Input Lecturer\n");
                printf("2. Input Student\n");
                printf("3. View Registered Lecturers\n");
                printf("4. View Registered Students\n");
                printf("9. Back\n");
                
                scanf("%d", &subchoice);
                if (subchoice == 1){
                    system("cls");
                    inputdosen();
                }
                else if (subchoice == 2){
                    system("cls");
                    input_mahasiswa();
                }
                else if (subchoice == 3){
                    system("cls");
                    show_dosen();
                    system("pause");
                }
                else if (subchoice == 4){
                    system("cls");
                    show_mahasiswa();
                    system("pause");
                }
                else if (subchoice == 9){
                    system("cls");
                    break;
                }
                else{
                    printf("Invalid input, please try again\n");
                }
            }
        }
        else if (choice == 2){
            system("cls");
            while(1){
                int subchoice;
                printf("Welcome to the College Subjects Portal\n");
                printf("What would you like to do?\n");
                printf("1. Input College Subjects\n");
                printf("2. View College Subjects\n");
                printf("9. Back\n");
                
                scanf("%d", &subchoice);
                if (subchoice == 1){
                    system("cls");
                    input_mata_kuliah();
                }
                else if (subchoice == 2){
                    system("cls");
                    show_mata_kuliah();
                }
                else if (subchoice == 9){
                    system("cls");
                    break;
                }
                else{
                    printf("Invalid input, please try again\n");
                }
            }
        }
        else if (choice == 3){
            system("cls");
            while(1){
                int subchoice;
                printf("Welcome to the Student Grades Portal\n");
                printf("What would you like to do?\n");
                printf("1. Input Student Grades\n");
                printf("2. View Student Grades\n");
                printf("9. Back\n");
                
                scanf("%d", &subchoice);
                if (subchoice == 1){
                    system("cls");
                    input_nilai();
                }
                else if (subchoice == 2){
                    system("cls");
                    show_nilai();
                }
                else if (subchoice == 9){
                    system("cls");
                    break;
                }
                else{
                    printf("Invalid input, please try again\n");
                }
            }
        }
        else if (choice == 4){
            system("cls");
            ingfo();
            printf("Pencet 1 untuk bank soal eas 2022\n");
            int ans;
            scanf("%d", &ans);
            if (ans == 1) {
                tag();
                printf("loh loh gabole gitu, yaudah ini easter egg aja deh :3\n");
            } else{

            }
            printf("\n");
            system("pause");
        }
        else if (choice == 9){
            system("cls");
            printf("Thank you for using this program\n");
            break;
        }
        else{
            printf("Invalid input, please try again\n");
        }
    }
    return 0;
}