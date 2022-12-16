#include <stdio.h>
#include <windows.h>
#include "header.h"

/*
? main program is moreless finished
TODO make the struct in struct work(?)
todo fix up visual stuff:
    * center align
    * change into morioh institute of technology
    * update header funct
    * 
*/

int main(){
    trademark();
    sleep(5);

    while(1){
        system("cls");
        //center align and adjust this for further use tmorrow
        printf("==============================================================================================================================\n");
        printf("\t\t\t\t\t\tPlease enter your credentials\n");
        printf("\t\t\t\t\t\t    Available Profiles\n");
        printf("\t\t\t\t\t____________________    ____________________\n");
        printf("\t\t\t\t\t|   Administrator   |   |      Student      |\n");
        printf("\t\t\t\t\t|         1         |   |         2         |\n");
        printf("\t\t\t\t\t|     pass:79       |   |                   |\n");
        printf("\t\t\t\t\t____________________    ____________________\n");
        printf("\n");
        printf("\n");
        printf("System Information(9)\n");
        printf("Power Off(0)\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1){
            int tries = 4, access = 0;
            while (tries--){
                system("cls");
                printf("============================================================\n");
                printf("|        Informatics Engineering Administrator Portal       |\n");
                printf("============================================================\n");
                printf("Please enter your credentials: ");
                int pass;
                scanf("%d", &pass);
                if (pass == 79){
                    printf("Welcome Administrator!\n");
                    printf("Loading");
                    loading();
                    access = 1;
                    system("cls");
                    break;
                }
                else{
                    system("cls");
                    printf("Loading\n");
                    loading();
                    printf("Incorrect Password!\n");
                    printf("You have %d tries left\n", tries);
                    system("pause");
                }
            }
            if (tries == 0){
                printf("You have exceeded the number of tries\n");
                printf("Exiting");
                loading();
                sleep(2);
                system("cls");
                continue;
            }
            if (access == 1){
                while(1){
                    system("cls");
                    printf("Welcome to the Informatics Engineering Administrator Portal!\n");
                    printf("Please select an option\n");
                    printf("1. Show Available Courses\n");
                    printf("2. Register a Course\n");
                    printf("3. Delete a Course\n");
                    printf("4. Show Available Student Advisors\n");
                    printf("5. Register a Student Advisors\n");
                    printf("6. Retire a Student Advisor\n");
                    printf("7. Student Grades\n");
                    printf("9. Exit\n");
                    printf("Enter your choice: ");
                    int schoice;
                    scanf("%d", &schoice);
                    
                    if (schoice == 1){
                        system("cls");
                        show_mata_kuliah();
                        system("pause");
                    }
                    else if (schoice == 2){
                        input_mata_kuliah();
                    }
                    else if (schoice == 3){
                        reset_mata_kuliah();
                    }
                    else if (schoice == 4){
                        system("cls");
                        show_dosen();
                        system("pause");
                    }
                    else if (schoice == 5){
                        input_dosen();
                    }
                    else if (schoice == 6){
                        reset_dosen();
                    }
                    else if (schoice == 7){
                        menu_grade();
                    }
                    else if (schoice == 9){
                        system("cls");
                        printf("Logging out");
                        loading();
                        break;
                    }
                    else {
                        system("cls");
                        printf("invalid choice\n");
                        system("pause");
                    }
                }
            }
        }
        else if (choice == 2){
            system("cls");
            printf("============================================================\n");
            printf("|           Informatics Engineering Student Portal          |\n");
            printf("============================================================\n");
            printf("Loading");
            loading();
            printf("Login Successful!\n");
            sleep(2);

            while(1){
                system("cls");
                printf("Welcome to the Informatics Engineering Student Portal!\n");
                printf("What would you like to do?\n");
                printf("1. Show Registered Students\n");
                printf("2. Register a Student\n");
                printf("3. Show Available Courses\n");
                printf("4. Manage Student Information\n");  //assign a course and or back down
                printf("9. Log out\n");
                int schoice;
                scanf("%d", &schoice);
                if (schoice == 1){
                    system("cls");
                    show_mahasiswa();
                    system("pause");
                }
                else if (schoice == 2){
                    input_mahasiswa();
                }
                else if (schoice == 3){
                    system("cls");
                    show_mata_kuliah();
                    system("pause");
                }
                else if (schoice == 4){
                    //! dont forget to do this pls
                    system("cls");
                    manage_student();
                }
                else if (schoice == 9){
                    system("cls");
                    printf("Logging out");
                    loading();
                    break;
                }
            }
        }
        else if (choice == 9){
            header();
            printf("Known Bugs:\n");
            printf("1. When doing anything related to a file, data wont automatically update\n");
            printf("   you would need to restart the program to see the changes\n");
            printf("2. Incorrect format (should've been Morioh Institute of Technology), due\n");
            printf("   to the time constraint and student's continuously deteriorating health, he gave up.\n");
            //todo add easter egg
            system("pause");
        }
        else if (choice == 0){
            printf("Shutting down");
            loading();
            printf("Thank you for using this program\n");
            break;
        }
        else {
            printf("Invalid input, please try again\n");
            continue;
        }
    }
    return 0;
}