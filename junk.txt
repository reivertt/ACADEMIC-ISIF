#include <stdio.h>

// struct dosenfile
// {
//     char dsnname[50];
//     char dnip[20];
// };
// struct dosenfile dosen[100];

// struct mapelfile
// {
//     char mkname[50];
//     char mkcode[20];
//     int sks;
// };
// struct mapelfile mapel[50];

// int main(){
//     FILE *fp = fopen("data.txt", "r+");
//     if(fp == NULL){
//         printf("File not found\n");
//         return 0;
//     }
//     else{
//         printf("File found\n");
//         // scan for dosenname and dosencode
//         printf("Dosenname and NIP Input\n\n");
//         for (int i = 0; i < sizeof(dosen); i++){
//             char temp[50];
//             printf("Input dosen code : ");
//             scanf("\n%s", temp);
//             if (strcmp(temp, "000") == 0){
//                 break;
//             }
//             else {
//                 strcpy(dosen[i].dnip, temp);
//                 printf("Input dosen name : ");
//                 scanf("\n%[^\n]%*c", dosen[i].dsnname);
//             }
//         }

//         //scan for mapelname, mapelcode, and sks
//         printf("Mapelname, Mapelcode, and SKS Input\n\n");
//         for (int i = 0; i < 50; i++){
//             char temp[50];
//             printf("Input mapel code : ");
//             scanf("%s", temp);
//             if (strcmp(temp, "000") == 0){
//                 break;
//             }
//             else {
//                 strcpy(mapel[i].mkcode, temp);
//                 printf("Input mapel name : ");
//                 scanf("\n%[^\n]%*c", mapel[i].mkname);
//                 printf("Input sks : ");
//                 scanf("\n%d", &mapel[i].sks);
//             }
//         }
        
//         fwrite(dosen, sizeof(dosen), 1, fp);
//         fread(dosen, sizeof(dosen), 1, fp);
//         // print dosenname and dosencode
//         printf("\nContoh print dosenname dan dosencode\n");
//         printf("\n");
//         printf("====================================\n");
//         printf("Dosenname\t|\tDosencode\n");
//         for (int i = 0; i < sizeof(dosen); i++){
//             printf("%s\t\t|\t%s\n", dosen[i].dsnname, dosen[i].dnip);
//         }



//         fwrite(mapel, sizeof(mapel), 1, fp);
//     }
// }

// while(1){
    //     system("cls");
    //     header();   

    //     printf("Welcome to the (bootleg) University Academic Portal\n");
    //     printf("What would you like to do?\n");
    //     printf("1. Academic Participants\n");
    //     printf("2. College Subjects\n");
    //     printf("3. Student Grades\n");
    //     printf("4. System Information\n");
    //     printf("9. Exit\n");
        
    //     int choice;
    //     scanf("%d", &choice);
    //     if (choice == 1){
    //         system("cls");
    //         while(1){
    //             system("cls");
    //             int subchoice;
    //             printf("Welcome to the Academic Community Portal\n");
    //             printf("What would you like to do?\n");
    //             printf("1. Input Lecturer\n");
    //             printf("2. Input Student\n");
    //             printf("3. View Registered Lecturers\n");
    //             printf("4. View Registered Students\n");
    //             printf("9. Back\n");
                
    //             scanf("%d", &subchoice);
    //             if (subchoice == 1){
    //                 system("cls");
    //                 inputdosen();
    //             }
    //             else if (subchoice == 2){
    //                 system("cls");
    //                 input_mahasiswa();
    //             }
    //             else if (subchoice == 3){
    //                 system("cls");
    //                 show_dosen();
    //                 system("pause");
    //             }
    //             else if (subchoice == 4){
    //                 system("cls");
    //                 show_mahasiswa();
    //                 system("pause");
    //             }
    //             else if (subchoice == 9){
    //                 system("cls");
    //                 break;
    //             }
    //             else{
    //                 printf("Invalid input, please try again\n");
    //             }
    //         }
    //     }
    //     else if (choice == 2){
    //         system("cls");
    //         while(1){
    //             int subchoice;
    //             printf("Welcome to the College Subjects Portal\n");
    //             printf("What would you like to do?\n");
    //             printf("1. Input College Subjects\n");
    //             printf("2. View College Subjects\n");
    //             printf("9. Back\n");
                
    //             scanf("%d", &subchoice);
    //             if (subchoice == 1){
    //                 system("cls");
    //                 input_mata_kuliah();
    //             }
    //             else if (subchoice == 2){
    //                 system("cls");
    //                 show_mata_kuliah();
    //             }
    //             else if (subchoice == 9){
    //                 system("cls");
    //                 break;
    //             }
    //             else{
    //                 printf("Invalid input, please try again\n");
    //             }
    //         }
    //     }
    //     else if (choice == 3){
    //         system("cls");
    //         while(1){
    //             int subchoice;
    //             printf("Welcome to the Student Grades Portal\n");
    //             printf("What would you like to do?\n");
    //             printf("1. Input Student Grades\n");
    //             printf("2. View Student Grades\n");
    //             printf("9. Back\n");
                
    //             scanf("%d", &subchoice);
    //             if (subchoice == 1){
    //                 system("cls");
    //                 input_nilai();
    //             }
    //             else if (subchoice == 2){
    //                 system("cls");
    //                 show_nilai();
    //             }
    //             else if (subchoice == 9){
    //                 system("cls");
    //                 break;
    //             }
    //             else{
    //                 printf("Invalid input, please try again\n");
    //             }
    //         }
    //     }
    //     else if (choice == 4){
    //         system("cls");
    //         ingfo();
    //         printf("Pencet 1 untuk bank soal eas 2022\n");
    //         int ans;
    //         scanf("%d", &ans);
    //         if (ans == 1) {
    //             tag();
    //             printf("loh loh gabole gitu, yaudah ini easter egg aja deh :3\n");
    //         } else{

    //         }
    //         printf("\n");
    //         system("pause");
    //     }
    //     else if (choice == 9){
    //         system("cls");
    //         printf("Thank you for using this program\n");
    //         break;
    //     }
    //     else{
    //         printf("Invalid input, please try again\n");
    //     }
    // }