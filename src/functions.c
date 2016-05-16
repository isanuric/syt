/*
 * functions.c
 *
 *  Created on: May 15, 2016
 *      Author: ehsan
 */

#include "header.h"


/*
 *
 */
void run()
{
	int size01 = 3;
	int det = 0;
	int arr[SIZE][SIZE] = { {0, 2, 5, 1}, {4, 5, 6, 3}, {1, 1, 1, 2}, {1, 1, 1, 7} };
	//arr = read_file("data.txt");
	det = do_determinate(SIZE, arr);
	printf("det: %d", det);
}

/*
 *
 */
void do_mode()
{
	int i;
	for (i = 0; i < 10; ++i)
		printf("%d mod 3: %d\n", i, i%3);
}

/*
 *
 */
int do_rekursive(int x)
{
	if(x){
		printf("x=%d, ", x);
		return x * do_rekursive(x-1);
	}
	return 1;
}


int do_determinate(int n, int matrix[SIZE][SIZE])
{
	int i,j;
	int element;
	int det = 0;
	int temp[SIZE][SIZE];
	int row, coulumn;

	printf("*************************************\n");
	for (i = 0; i < SIZE; ++i) {
		for (j = 0; j < SIZE; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	if(n==1){
		det = matrix[0][0];
		return det;
	}else if(n==2){
		det = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
		return det;
	}
	else
	{
		for (element = 0; element < n; ++element)
		{
			row = 0;
			coulumn = 0;
			for (i = 1; i < n; ++i)
			{
				for (j = 0; j < n; ++j)
				{
					if (j==element)
						continue;

					temp[row][coulumn] = matrix[i][j];
					coulumn++;

					if (coulumn==n-1)
					{
						row++;
						coulumn = 0;
					}
				}
			}
			det = det + pow(-1,element) * matrix[0][element] * do_determinate(n-1, temp);
		}
		return det;
	}

}


/*
 * read file in a dynamic two dimensional array
 */
double **read_file(char *file_name)
{
	int i = 0;
	int j = 0;
	int max = 0;
	int var;
	int row;
	int count=0;
	double d;
	static double **arr_input;
	FILE *file;
	FILE *file2;

	file = fopen(file_name, "r");
	if(file==NULL)	{
		fprintf(stderr, "error! unable to open file.\n");
		return -1;
	}

	/* number of xyz data groups in file*/
	while(fscanf(file, "%lf", &d)==1){
		count++;
		if(count%3 == 0) max++;
	}
	fclose(file);

	/* dynamic array allocation */
	arr_input = malloc(max*sizeof(double*));
	for (row = 0; row < max; ++row)
		arr_input[row] = malloc(3*sizeof(double));

	/* add XYZ parametes into array*/
	file = fopen(file_name, "r");
	while( fscanf(file, "%lf", &d)==1 ){
		arr_input[i][j] = d;
		j++;
		//printf("---> %g ", arr_input[i][j++]);
		if(j == 3){
			i++;
			j=0;
			//printf("\n");
		}
	}
	fclose(file);

	printf("open file:\n");
	for ( var = 0; var < max; ++var){
		printf("XYZ %d: ", var);
		for ( j = 0; j < 3; ++j)
             printf("%.3lf ", arr_input[var][j]);
		printf("\n");
	}
	printf("\n");
	return arr_input;
}
