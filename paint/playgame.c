
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "playgame.h"
#include "canvas.h"
#include "commands.h"
#include <ctype.h>

bool check_if_linear(int startrow, int startcol, int endrow, int endcol)
{//this function checks if the arguments entered create a linear slope
 //if the slope is linear, it returns true, if not, false

    if (abs((endrow - startrow)) == abs((endcol - startcol)) || (startrow == endrow) || (startcol == endcol))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void playgame()
{
//this is the main function where the game is played, it uses a do-while loop and breaks when the user enters 'q' to quit

    char command;
    //Array to store the command
    char character2;
    //if the user utilized the 'a' or 'd' command character2 is the 'r' or 'c' they enter after
    char filename[100];
    //filename 
    int arg1, arg2, arg3, arg4;
    //integer points when writing, deleting, and erasing

    
    do
    {
    
    char* input = read_any_len_str();
    //parsing a string into input
    int len = strlen(input);
    //length of the string returns above
    switch (input[0])
    {//using a switch statement because the command is a single character, the cases are below:
        case 'q':
          //this case exits the program
          exit(0);         
          break;
        case 'h':
          //this case displays the help options
            if(len == 1){
            help_command();
            printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
            }
            else{
                printf("Invalid command. Type 'h' for help.");
            }
            break;
        case 'w':
           //this case writes to the canvas
           sscanf(input, "%c %d %d %d %d", &command, &arg1, &arg2, &arg3, &arg4);
           //the sscanf reads the string, ignoring whitespace and parses it into its respective argument variables
           if (check_if_linear(arg1, arg2, arg3, arg4))
           //checking if the points are linear
            {
                if (arg1 < arg3 && arg4 > arg2)
                {//this block gets called when writing diaganal, R2L (right to left), from bottom to top (bottom to top)
                    write_on_board_diagR2L_B2T(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                    
                }

                else if (arg1 > arg3 && arg2 > arg4)
                {//this block gets called when writing diagonl, R2L, from top to bottom
                    write_on_board_diagR2L_T2B(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }

                else if (arg1 > arg3 && arg4 > arg2)
                {//this block gets called when writing diagonal, L2R, from top to bottom
                    write_on_board_diagL2R_T2B(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }

                else if (arg3 > arg1 && arg2 > arg4)
                {//this block gets called when writing diagonal, L2R, from bottom to top
                    write_on_board_diagL2R_B2T(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }
                else if (arg1 == arg3 && arg4 > arg2)
                {//tihs block gets called when writing horozontal, L2R
                    write_on_board_horoztonal_L2R(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }

                else if (arg1 == arg3 && arg2 > arg4)
                {//this block gets called when writing horozontal, R2L
                    write_on_board_horozontal_R2L(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }

                else if (arg1 < arg3 && arg2 == arg4)
                {//this block gets called when writing vertical, B2T (bottom to top)
                    write_on_board_vertical_B2T(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }

                else if (arg1 > arg3 && arg2 == arg4)
                {//this block gets called when writing vertical, T2B
                    write_on_board_vertical_T2B(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }

                else if (arg1 == arg3 && arg2 == arg4)
                {//this block gets called if the user wants to write a single point
                    
                    write_on_board_single(canvas.board, arg1, arg2, arg3, arg4);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }
            }
            else
            {
                printf("Points Do Not Form A Straight Line");
            }
            break;

        case 'e':
               //this case is called if the user wants to erase a point
               sscanf(input, "%c %d %d", &command, &arg1, &arg2);
               
               erase_on_board(canvas.board, arg1, arg2);
               printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
               break;

        case 'a':
                //this case gets called if the user wants to add a row or column
                sscanf(input, "%c %c %d", &command, &character2, &arg1);
                
                if(character2 == 'r'){
                    //if adding a row
                    canvas.num_rows = canvas.num_rows + 1;
                    canvas.row_num_for_board = canvas.row_num_for_board + 1;
                    add_row(&canvas.board, arg1);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }
                else if(character2 == 'c'){
                    //if adding a column
                    canvas.num_cols = canvas.num_cols + 1;
                    add_col(canvas.board, arg1);
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }

                break;
        case 'd':
                //this case gets called when deleting a row or column
                sscanf(input, "%c %c %d", &command, &character2, &arg1);
                
                if(character2 == 'r'){
                //if the second character is an r, then delete row
                    delete_row(&canvas.board, arg1);
                    canvas.row_num_for_board = canvas.row_num_for_board - 1;
                    canvas.num_rows = canvas.num_rows - 1;
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }
                
                else if(character2 == 'c'){
                //if the second character is a c, then delete column
                    delete_col(&canvas.board, arg1);
                    canvas.num_cols = canvas.num_cols - 1;
                    printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
                }
            break;

       
        case 'r': 
               //this case resizes the array
               sscanf(input, "%c %d %d", &command, &arg1, &arg2);
               
               if(arg1 < 1 && arg2 < 1){
                continue;
               }
               
               else {
                resize_array(&canvas.board,arg1,arg2);
                canvas.num_rows = arg1;
                canvas.row_num_for_board = arg1;
                canvas.num_cols = arg2;
            
                printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
               }
            break;



        case 's':
            //this case is called when saving a file
            sscanf(input, "%c %s", &command, filename);
            file_save(filename);
            printcanvas(canvas.board, canvas.num_rows, canvas.num_cols, canvas.row_num_for_board);
            break;  
        
        case 'l':
            //sscanf(input, "%c %s", &command, filename);
            //file_open(filename);

        break;
        
        default:
            printf("Invalid command. Type 'h' for help.");
            break;
        }
      
    } while (true); 
}

