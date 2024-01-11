#include <stdio.h>

//function to check whether a number can be placed in a specific cell
int check(int sudoku[][9], int baris, int kolom, int nomor){
    //cek baris dan kolom
    for(int i = 0; i < 9; i++){
        if(sudoku[baris][i] == nomor || sudoku[i][kolom] == nomor){
            return 0;
        }
    }
//check 3x3 box
    int mulaibaris = baris - baris % 3;
    int mulaikolom = kolom - kolom % 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sudoku[i + mulaibaris][j + mulaikolom] == nomor){
                return 0;
            }
        }
    }
    return 1;
}

//function solving sudoku 
int solveSudoku(int sudoku[][9], int baris, int kolom){
    if(baris == 9 && kolom == 9){
        return 1;
    }
    if(kolom == 9){
        baris++;
        kolom = 0;
    }
    if(sudoku[baris][kolom] != 0){
        return solveSudoku(sudoku, baris, kolom + 1);
    }
    for(int nomor = 1; nomor <= 9; nomor++){
        if(check(sudoku, baris, kolom, nomor)){
            sudoku[baris][kolom] = nomor;
            if (solveSudoku(sudoku, baris, kolom + 1)){
                return 1;
            }
        }
    }
    sudoku[baris][kolom] = 0;
    return 0;
}
//input fucntion 
int main() {
    char ulang;
    int sudoku[9][9];
        printf ("++------------Program Penyelesaian Sudoku------------++\n");
        printf ("_______________________________________________________\n\n");
    do{
    for (int i = 0; i < 9; i++){
        printf("Masukkan baris %d dari sudoku (pisahkan dengan spasi) = ", i+1);
        for (int j = 0; j < 9; j++){
            scanf("%d", &sudoku[i][j]);
        }
    }

    if(solveSudoku(sudoku, 0, 0)){
        printf("\n+-----------+-----------+-----------+\n");
        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 10; j++)
            printf("| %d ", sudoku[i-1][j-1]);
            printf("|\n");
            if (i % 3 == 0)
                printf("+-----------+-----------+-----------+\n");
        }
    }
    else{
      printf("\n\nInput Bukan Sudoku\n\n");
    }

    printf("\nUlangi Program? (Ya: y | Tidak: t) : ");
    scanf(" %c", &ulang);
    }
    while(ulang=='y'||ulang=='Y');
    return 0;
}
