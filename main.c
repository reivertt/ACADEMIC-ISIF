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
    trademark();
    system("pause");

    while(1){
        system("cls");
        //center align
        printf("Please enter your credentials\n");
        printf("Available Profiles\n");
        printf("____________________    ____________________\n");
        printf("|   Administrator   |   |     Student      |\n");
        printf("|         1         |   |         2        |\n");
        printf("|     pass:79       |   |                  |\n");
        printf("____________________    ____________________\n");
        printf("\n");
        printf("\n");
        printf("\t\t\t\tSystem Information(9)");
        printf("\t\t\t\tPower Off(0)");
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
                printf("Please enter your credentials...");
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
                    printf("1. Course Management\n");
                    printf("2. Student Advisor Management\n");
                    printf("3. Student Grades\n");
                    printf("9. Exit\n");
                    printf("Enter your choice: ");
                    int schoice;
                    scanf("%d", &schoice);
                    
                    if (schoice == 1){
                        printf("course management\n");
                    }
                    else if (schoice == 2){
                        printf("student advisor management\n");
                    }
                    else if (schoice == 3){
                        printf("student grades\n");
                    }
                    else if (schoice == 9){
                        printf("exiting\n");
                        loading();
                        break;
                    }
                    else {
                        printf("invalid choice\n");
                        system("pause");
                    }
                }
            }
        }
        else if (choice == 2){      //! ini kurang 1 bagian, student part which is pretty massive tbh
            system("cls");
            printf("============================================================\n");
            printf("|           Informatics Engineering Student Portal          |\n");
            printf("============================================================\n");
            printf("Loading");
            loading();
            printf("Login Successful!\n");
            sleep(2);
            system("cls");

            while(1){
                printf("Welcome to the Informatics Engineering Student Portal!\n");
                printf("What would you like to do?\n");
                printf("1. Show Registered Students\n");
                printf("2. Register a Student\n");
                printf("3. Show Available Courses\n");
                printf("4. View Student\n");  //assign a course
                printf("9. Log out\n");
                int schoice;
                scanf("%d", &schoice);
                if (schoice == 1){
                    show_mahasiswa();
                    system("pause");
                }
                else if (schoice == 2){
                    input_mahasiswa();
                }
                else if (schoice == 3){
                    show_mata_kuliah();
                    system("pause");
                }
                else if (schoice == 4){
                    //! dont forget to do this pls
                    printf("pardon sir, that isnt implemented yet mwehe\n");
                    printf("This is where you view a student's data and possibly assign a course or even delete the whole data!\n");
                    system("pause");
                }
                else if (schoice == 9){
                    printf("Logging out");
                    loading();
                    break;
                }
            }
        }
        else {
            printf("Invalid input, please try again\n");
            continue;
        }
    }
    return 0;
}