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
	int i,j;
	int det = 0;
	int **arr;

	//arr = read_file("data.txt");

	arr = (int **)calloc(SIZE, sizeof(int *));
	for(i = 0; i < SIZE; i++)
	   arr[i] = (int * )calloc(SIZE, sizeof(int));

	int arr0[SIZE][SIZE] = { {0, 2, 5, 1},
							 {4, 5, 6, 3},
							 {1, 1, 1, 2},
							 {1, 1, 1, 7} };

	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			 arr[i][j] = arr0[i][j];

	det = do_determinate(SIZE, arr);
	printf("det: %d", det);
//	free(arr);
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

/*
 * calculate determinate
 */
//int do_determinate(int n, int matrix[SIZE][SIZE])
int do_determinate(int n, int **matrix)
{
	int i,j;
	int element;
	int det = 0;
	//int temp[SIZE][SIZE];
	int **temp;
	int row, coulumn;
	//temp = calloc(n * n, sizeof(int *));

	temp = (int **)calloc(n, sizeof(int *));
	for(i = 0; i < n; i++)
	   temp[i] = (int * )calloc(n, sizeof(int));

//	printf("*************************************\n");
//	for (i = 0; i < SIZE; ++i) {
//		for (j = 0; j < SIZE; ++j) {
//			printf("%d ", matrix[i][j]);
//		}
//		printf("\n");
//	}


//	printf("***************\n");
//	for (i = 0; i < n; ++i) {
//		for (j = 0; j < n; ++j) {
//			temp[i][j] = j;
//			printf("%d ", temp[i][j]);
//		}
//		printf("\n");
//	}

	printf("***************\n");
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf("%d ", temp[i][j]);
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
			free(temp);
		}

		return det;
	}

}


