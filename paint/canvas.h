#ifndef PRINTCANVAS_H
#define PRINTCANVAS_H

typedef struct canvas_struct{
    int num_rows;
    int num_cols;
    int row_num_for_board;
    char** board;
}canvas_struct;

extern canvas_struct canvas;

char** createcanvas(int num_rows, int num_cols);
void printcanvas(char** board, int num_rows, int num_cols, int num_row_for_grid);
//void resize_board(struct canvas_struct *canvas, int num_rows, int num_cols);



#endif


//follow connectn. first create the board