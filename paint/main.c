#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "canvas.h"
#include "playgame.h"


canvas_struct canvas;


void set_up(int num_rows, int num_cols, int row_num_for_board){
//this function sets up the board. It creates the board and prints the initial blank board
canvas.board = createcanvas(num_rows, num_cols);
printcanvas(canvas.board, num_rows, num_cols, row_num_for_board);
playgame();

}


bool not_valid_arg(int num_rows ,int num_cols){
//this function checks if the number of rows or columns entered is less than 0
if(canvas.num_rows < 0 || canvas.num_cols < 0){
   return true;
}//if either the number of rows or columns is less than 0, then return true
else{
    return false;
}
}

int main(int argc, char *argv[]){
//the main function takes the argument of the command lines arguments


if(argc == 1){
//if there is only one argument entered, then rows and columns default to 10
   canvas.num_rows = 10;
   canvas.row_num_for_board = 10;
   canvas.num_cols = 10;
   set_up(canvas.num_rows,canvas.num_cols, canvas.row_num_for_board);

}


else if (argc == 2 || argc > 3){
//if there are only two arguments, or greater than three, then default to 10  
    printf("Wrong number of command line arguments entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.\n");
    canvas.num_rows = 10;
    canvas.row_num_for_board = 10;
    canvas.num_cols = 10;
    set_up(canvas.num_rows,canvas.num_cols, canvas.row_num_for_board);
    //the first condition to check if is the user entered less than 2 command line arguments
    //if this is true, then the number of rows and columns defaults to 10
}


else if (argc == 3){
   //if the user enters 2 command line arguments
 canvas.num_rows = atoi(argv[1]);
  //number of rows is argument 1
 canvas.row_num_for_board = atoi(argv[1]);
  //number of rows when printing the board is argument 1
 canvas.num_cols = atoi(argv[2]);
  //number of columns is argument 2

 
 if(not_valid_arg(canvas.num_rows,canvas.num_cols)){
 //checking if the arguments are valid; greater than 0   
    if(canvas.num_rows < 1){
    printf("The number of rows is less than 1.\nMaking default board of 10 X 10.\n");
    }
    else if(canvas.num_cols < 1){
    printf("The number of columns is less than 1.\nMaking default board of 10 X 10.\n");
   }

    canvas.num_rows = 10;
    canvas.row_num_for_board = 10;
    canvas.num_cols = 10;
    set_up(canvas.num_rows,canvas.num_cols, canvas.row_num_for_board);
   //if the user enters an argument less than 1, then the following error message is printed
  }

  set_up(canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
  //if the command line arguments are valid, then the game can be set up
}

return 0;

}