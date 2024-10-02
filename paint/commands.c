#include <stdio.h>
#include <stdlib.h>
#include "playgame.h"
#include "commands.h"
#include "canvas.h"
#include <ctype.h>



char* read_any_len_str() {
	char cur_char;
	char* str = NULL;
	int cur_size = 0;
  printf("\n");
  printf("Enter your command: ");
	scanf(" %c", &cur_char);
  while(cur_char != '\n')
  {
   str = append(cur_char, str, &cur_size);
   scanf("%c", &cur_char);
  }

	if(cur_size > 0){
	  str = append('\0', str, &cur_size);
  }
	return str;
}




char* append(char val, char* str, int* size){
	(*size)++;
	str = (char*)realloc(str, *size * sizeof(char));
	str[*size - 1] = val;
	return str;

}
   



void help_command(){
  
  printf("\nCommands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");

}

void write_on_board_diagR2L_B2T(char** board, int startrow, int startcol, int endrow, int endcol){
//this function writes on the board diagonaly up and to the right. But with this function, the first set of points entered is lower in the grid than the last two
int j = startcol - 1;
  //the startc olumn has to be whatever the chosen column is minus 1, because we begin the draw by adding one to j in the loop below
for(int i = canvas.num_rows - startrow; i >= startrow - endrow;  --i){
  //starting at the bottom right of the canvas. While 'i' is less than the start of the row - the of the row, run the following      
       
        if(board[i - 1][j + 1] != '*' && board[i - 1][j + 1] != '/'){
          board[i - 1][j + 1] = '+';
        }
        
        else{
         board[i - 1][j + 1] = '/';
         }
  //because its a diagonal up and to the right, we start at the bottom right of the grid, its (i - 1) because we move up the arraw and (j + 1) because we move to the right of the grid  
        j++;
        if(j == endcol){
            break;
         }
  //once j is equal to the endcol, break the loop
      }
  }

//fix
void write_on_board_diagR2L_T2B(char** board, int startrow, int startcol, int endrow, int endcol){
//this function writes on the board diagonaly up and to the right. But with this function, the first set of points entered is higher in the grid than the last two
  int j = startcol + 1;

  for(int i = canvas.num_rows - startrow - 2; i <= startrow - endrow + 50; ++i ){
       

       if(board[i + 1][j - 1] != '*' && board[i + 1][j - 1] != '/'){
          board[i + 1][j - 1] = '+';
         }
        
        else{
         board[i + 1][j - 1] = '/';
         }
       
       j--;
       if(j == endcol){
        break;
        
    }
  }
}


void write_on_board_diagL2R_T2B(char** board, int startrow, int startcol, int endrow, int endcol){
  //this function writes diagonal lines going from left to right. But this function is called when the first two set of points is higher in the grid than the second two
int j = startcol - 1;
   
for(int i = canvas.num_rows - startrow - 2; i <= ((canvas.num_rows - startrow - 2) + startrow) ; ++i){

   
        if(board[i + 1][j + 1] != '*' && board[i + 1][j + 1] != '\\'){
          board[i + 1][j + 1] = '+';
        }
        
        else{
         board[i + 1][j + 1] = '\\';
         }



     j++;
   if(j == endcol){
    break;
   }
  }
}


void write_on_board_diagL2R_B2T(char** board, int startrow, int startcol, int endrow, int endcol){
  //this function writes diagonal lines going from left to right. 
  //It is only called when the first pair of points is lower in the grid than the second pair
int j = startcol + 1;

for(int i = canvas.num_rows - startrow; i >= canvas.num_rows - endrow; --i){
  
  if(board[i - 1][j - 1] != '*' && board[i - 1][j - 1] != '\\'){
          board[i - 1][j - 1] = '+';
        }
        
        else{
         board[i - 1][j - 1] = '\\';
         }
  j--;
  if(j == endcol){
    break;
   }
  }
}



void write_on_board_horoztonal_L2R(char** board, int startrow, int startcol, int endrow, int endcol){
//this function writes a horoztonal line form left to right, 
//it is passed if the the starting column is greater than the ending column, but the row is the same
int i = canvas.num_rows - startrow - 1;


for(int j = startcol; j <= endcol; ++j){
  
  if(board[i][j] != '*' && board[i][j] != '-'){
    board[i][j] = '+';
  }
  else{
    board[i][j] = '-';
  }
  
  
  
  }
}

void write_on_board_horozontal_R2L(char** board, int startrow, int startcol, int endrow, int endcol){
//this function writs a horotonal line from right to left,
//it is passed if the starting column is less than the end column, but the row is the same

int i = canvas.num_rows - startrow - 1;

for(int j = startcol; j >= endcol; --j){
  
  if(board[i][j] != '*' && board[i][j] != '-'){
    board[i][j] = '+';
  }
  else{
    board[i][j] = '-';
  }
  

  }
}


void write_on_board_vertical_B2T(char** board, int startrow, int startcol, int endrow, int endcol){
//this function writes a vertical line from bottom to top
//is it called if the starting row is less than the ending row, but the column is the same
int j = startcol;

for(int i = canvas.num_rows - startrow - 1; i >= canvas.num_rows - endrow - 1; --i){
  
  
  if(board[i][j] != '*' && board[i][j] != '|'){
    board[i][j] = '+';
  }
  
  else{
      board[i][j] = '|';
  }

   }
}



void write_on_board_vertical_T2B(char** board, int startrow, int startcol, int endrow, int endcol){
//this function writes a vertical line from top to bottom
//is it called if the starting row is greater than the bottom row, but the column is the same

int j = startcol;

for(int i = canvas.num_rows - startrow - 1; i <= canvas.num_rows - endrow - 1; ++i){
 
 if(board[i][j] != '*' && board[i][j] != '|'){
    board[i][j] = '+';
  }
  
  else{
      board[i][j] = '|';
  }

   }

}

void write_on_board_single(char** board, int startrow, int startcol, int endrow, int endcol){

int row = canvas.num_rows - startrow - 1;


if (board[row][startcol] != '*' && board[row][startcol] != '-'){
  board[row][startcol] = '+';
}

else{
board[row][startcol] = '-';
}


}


void erase_on_board(char** board, int eraserow, int erasecol){
//this function erases whatever is at that specific spot on the board. It converts it to a "*"
int erase_row = canvas.num_rows - eraserow - 1;
board[erase_row][erasecol] = '*';

}

void add_row(char** *board, int rownum){
//this function adds a row to the board
//the row is added at the argument 'rownum' position

*board = (char**)realloc(*board, (canvas.num_rows + 1) * sizeof(char*));

int actualRow = canvas.num_rows - rownum - 1;

for(int i = canvas.num_rows; i > actualRow; i--){
  (*board)[i] = (*board)[i - 1];
}

(*board)[actualRow] = (char*)malloc(canvas.num_cols * sizeof(char));

for(int j = 0; j < canvas.num_cols; j++){
  (*board)[actualRow][j] = '*';
}

}

void add_col(char** board, int colnum){
//this function adds a column to the board
//the column is added at 'colnum' location


for(int i = 0; i < canvas.num_rows; i++){
  board[i] =(char*)realloc(board[i], (canvas.num_cols + 1) * sizeof(char));

  for(int j = canvas.num_cols; j > colnum; j--){
    
    board[i][j] = board[i][j - 1];
  
  }
    board[i][colnum] = '*';
}

}

    
    
void delete_row(char** *board, int rownum)
{
//this function deletes a row from the board at 'rownum'
int actualRow = canvas.num_rows - rownum - 1;

free((*board)[actualRow]);


for(int i = actualRow; i < canvas.num_rows - 1; i++)
{
 (*board)[i] = (*board)[i + 1];
}

*board = (char**)realloc(*board, (canvas.num_rows - 1) * sizeof(char*));



}
    
      
void delete_col(char** *board, int numcol)
{
//this function deletes a column from the board at 'numcol'
for(int i = 0; i < canvas.num_rows; i++)
{
  for(int j = numcol; j < canvas.num_cols - 1; j++){
    (*board)[i][j] = (*board)[i][j + 1];
  }

  (*board)[i] = (char*)realloc((*board)[i],(canvas.num_cols - 1) * sizeof(char));

}

}
    
void resize_array(char ***array, int new_rows, int new_columns) {
    //this function resizes the array
    char **resized_array = (char **)malloc(new_rows * sizeof(char *));
   
    
    for (int i = 0; i < new_rows; i++) {
        resized_array[i] = (char *)malloc(new_columns * sizeof(char));
        
        }
  
    int start_row = canvas.num_rows - new_rows;
    int start_column = 0;
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_columns; j++) {
            if (start_row + i >= 0 && start_row + i < canvas.num_rows && start_column + j >= 0 && start_column + j < canvas.num_cols) {
                resized_array[i][j] = (*array)[start_row + i][start_column + j];
            } else {
               
                resized_array[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < canvas.num_rows; i++) {
        free((*array)[i]);
    }
    free(*array);

    
    *array = resized_array;

}



 void file_save(char* destFile) {     
  //this function saves the current canvas to an outfile to be viewed in txt
  //first parameter is the file you want to read from, the second is the file you want to write to.
 
    FILE *file = fopen(destFile, "w");
    
    
    if (file == NULL) {
        printf("Error opening file %s for writing.\n", destFile);
        return;
    }

    for (int i = 0; i < canvas.num_rows; i++) {
        for (int j = 0; j < canvas.num_cols; j++) {
            
            fprintf(file, "%c ", canvas.board[i][j]);

        }
        fprintf(file, "\n");
    }

    fclose(file);

 }


 void file_open(char* srcfile)
 {

    FILE *file = fopen(srcfile, "r");

     if (file == NULL) {
        printf("Error opening file %s for writing.\n", srcfile);
        return;
    
    //read the contents of the file and store it into the current array

    
    
    }


 }


  








