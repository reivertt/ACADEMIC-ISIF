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