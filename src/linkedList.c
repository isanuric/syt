/*
 * linkedList.c
 *
 *  Created on: May 23, 2016
 *      Author: isan
 */


#include "header.h"



void run_linked_list()
{
	int count = get_random();
//	int make_list = 1;
	struct NODE *list;
	list = (struct NODE*)malloc(sizeof(struct NODE));
//	list->number = 10;
//	list->next_ = NULL;
	while(count > 0)
	{
		append(list, count);
		count--;
	}

	/* delete element */
	remove_(list, 5);
	display_list(list);
	free(list);



}


void append(struct NODE *list, int num)
{
	while(list->next_!= NULL)
		list = list->next_;
	list->next_ = (struct NODE *)malloc(sizeof(struct NODE));
	list->next_->number = num;
	list->next_->next_ = NULL;
}

void display_list(struct NODE *list)
{
  int newline = 0;
  while (list->next_ != NULL)
  {
    printf("%d ", list->number);
    list = list->next_;
    newline++;
    if(newline%10 == 0)
    	printf("\n");
  }
  printf("%d", list->number);
}

/*
 *
 */
void remove_(struct NODE *list, int num)
{
	struct NODE *temp;
	temp = (struct NODE*)malloc(sizeof(struct NODE));

	if(list->number==num)
	{
		/* remove the node */
		temp = list->next_;
		free(list);
		list = temp;
	}else{
		while(list->next_->number!=num)
			list=list->next_;

		temp = list->next_->next_;
		free(list->next_);
		list->next_=temp;
	}
}
/*
 *
 */
int get_random()
{
	int rand_;

	do {
		srand(time(NULL));
		rand_ = rand() / 10000000;
	} while (rand_ > 200);

	printf("random size: %d\n", rand_);
	return rand_;
}
