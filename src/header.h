/*
 * header.h
 *
 *  Created on: May 15, 2016
 *      Author: ehsan
 */


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

struct NODE{
	int number;
	struct NODE *next_;
};

/* constants*/
#define SIZE 4

/* functions */
// functions
void do_mode();
int  do_rekursive(int x);
void run();
//int  do_determinate(int n, int matrix[SIZE][SIZE]);
int do_determinate(int n, int **matrix);
double **read_file(char *file_name);

// linked list
void run_linked_list();
void append(struct NODE *list, int num);
void display_list(struct NODE *list);
void remove_(struct NODE *list, int num);
int get_random();

