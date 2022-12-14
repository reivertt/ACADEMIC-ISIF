#include <stdio.h>

//iki bikin e wis ada di database
//max 100 dosen ae wis
struct dosenfile
{
    char dsnname[50];
    char nip[5];
};
// struct dosenfile dosen[100];

//mapel jg max 50
struct mapelfile
{
    char mkname[50]; 
    char mkcode[5];
    int sks;

    //grade
    int uts;
    int eas;
    int avg;
    int finalgrade;
};
// struct mapelfile mapel[50];

//input dewe
struct mahasiswafile
{
    char mhsname[50];
    char nrp[5];
    
    //pointer
    char dosen[20];
    int skstotal;

    struct mapelfile mapel[10];
};
// struct mahasiswafile mhs[100];

void input_dosen();
void show_dosen();
void reset_dosen();

void input_mata_kuliah();
void show_mata_kuliah();
void reset_mata_kuliah();

void input_mahasiswa();
void show_mahasiswa();
void reset_mahasiswa();

void input_nilai();
void show_nilai();
void clear_nilai();

void assign_matkul();

void header();
void tag();
void ingfo();
void trademark();
void loading();


/*
TODO MAKE A GODDAMNED LOGIN SCREEN
base this off of chocolate
* Welcome to The Chocolate Academic Management System
! redesign stuff so that its separated into student and administrator ig
? OR
! make it like keanu's 

! Status:
todo input_dosen() ->           fix this shit
* show_dosen() ->           done

todo input_mata_kuliah() ->    fix this shit
* show_mata_kuliah() ->     done

* input_mahasiswa() ->      done
* show_mahasiswa() ->       somewhat done

todo assign_matkul() ->     not done (hardest mwehe)

todo input_nilai() ->       not done
todo show_nilai() ->        not done
*/