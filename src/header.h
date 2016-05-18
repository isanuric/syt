/*
 * header.h
 *
 *  Created on: May 15, 2016
 *      Author: ehsan
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 4

void do_mode();
int  do_rekursive(int x);
void run();
//int  do_determinate(int n, int matrix[SIZE][SIZE]);
int do_determinate(int n, int **matrix);
double **read_file(char *file_name);
