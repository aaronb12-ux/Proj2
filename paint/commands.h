#ifndef COMMANDS_H
#define COMMANDS_H

void help_command();

void erase_on_board(char** board, int row, int col);

void write_on_board_diagR2L_B2T(char** board, int start_row, int start_column, int end_row, int end_column); //GOOD
void write_on_board_diagR2L_T2B(char** board, int startrow, int startcol, int endrow, int endcol); //GOOD 

void write_on_board_diagL2R_T2B(char** board, int startrow, int startcol, int endrow, int endcol); //GOOD
void write_on_board_diagL2R_B2T(char** board, int startrow, int startcol, int endrow, int endcol); //GOOD


void write_on_board_horoztonal_L2R(char** board, int startrow, int startcol, int endrow, int endcol); //GOOD
void write_on_board_horozontal_R2L(char** board, int startrow, int startcol, int endrow, int endcol); //GOOD

void write_on_board_vertical_B2T(char** board, int startrow, int startcol, int endrow, int endcol); //GOOD
void write_on_board_vertical_T2B(char** board, int startrow, int startcol, int endrow, int endcol);

void write_on_board_single(char** board, int startrow, int startcol, int endrow, int endcol);


void add_row(char** *board, int rownum);
void add_col(char** board, int colnum);



void delete_row(char** *board, int rownum);
void delete_col(char** *board, int numcol);

void resize_array(char ***array, int new_rows, int new_columns);


void file_save(char* destFile);


char* read_any_len_str(); 
char* append(char val, char* str, int* size);
#endif
