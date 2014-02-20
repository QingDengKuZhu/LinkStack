/*****************
**栈的链式数据结构
*****************/
#ifndef DATA_H
#define DATA_H

#include "Main_First.h"

typedef int Elem;

/*
**结点数据结构.
*/
typedef struct Node
{
	Elem data;			/*数据域.*/
	struct Node *pNext;	/*指针域.*/

}NODE, *PNODE;

/*
**链式栈的数据结构.
*/
typedef struct LinkStack
{
	PNODE pBottom;			/*栈底指针.*/
	PNODE pTop;			/*栈顶指针,始终指向栈顶元素的下一个位置.*/

}LINKSTACK, *PLINKSTACK;


#endif