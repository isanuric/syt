/*
 * linkedList.c
 *
 *  Created on: May 23, 2016
 *      Author: isan
 */


#include "header.h"



void run_linked_list()
{
	struct NODE *list;
	list = (struct NODE*)malloc(sizeof(struct NODE));
	list->number = 10;
	list->next_ = NULL;
	append(list, 11);
	append(list, 12);
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
  while (list->next_ != NULL)
  {
    printf("%d ", list->number);
    list = list->next_;
  }
  printf("%d", list->number);
}
