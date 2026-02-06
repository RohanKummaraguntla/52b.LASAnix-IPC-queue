/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *a, int priority)
{
	node* newNode = new node;
	newNode->data = a;
	
	newNode->priority = priority;
	newNode->link = NULL;

	if (front == NULL || priority < front->priority)
	{
		newNode->link = front;
		front = newNode;
		
		
		return;
	}

	node* current = front;
	while (current->link != NULL && current->link->priority <= priority)
	{
	    
	    
		current = current->link;
	}
	newNode->link = current->link;
	current->link = newNode;
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	if (front == NULL)
		return NULL;
	return front->data;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	if (front == NULL)
		return;

	node* t = front;
	front = front->link;
	delete t;
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	node* ptr = front;
	while (ptr != NULL)
	{
		std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
		ptr = ptr->link;
	}

}
long PQueue::getCur(){
    return current;
}
long PQueue::getFlag(){
    return flag;
}
void PQueue::setFlag(long flag){
    this->flag=flag;
}
