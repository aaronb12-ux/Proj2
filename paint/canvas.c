#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"

char** createcanvas(int num_rows,int num_cols){
//this function creates the canvas. It is creates with an "*" in empty spaces. It returns the board because its stored as a variable
char** board = (char **)malloc(num_rows * sizeof(char *));

   for (int row = 0; row < num_rows; ++row){
      
      board[row] = (char *)malloc(num_cols * sizeof(char));
         
            for (int col = 0; col < num_cols; ++col){
         
            board[row][col] = '*';
      }
   }
return board;
}  

void printcanvas(char** board, int num_rows, int num_cols, int num_row_for_grid){
//this function prints the canvas. Each time its called it prints the updated value, depending on if there were any changes to it
for (int row = 0; row < num_rows; ++row){
        
        printf("%d ", num_row_for_grid - 1);
        
        num_row_for_grid = num_row_for_grid - 1;
        
        for (int col = 0; col < num_cols; ++col){
            
            printf("%c ", board[row][col]);
      }
      printf("\n");
   }
      
printf(" ");
    for (int col = 0; col < num_cols; ++col){
      printf(" %d", col);
   }
}











