#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

/*
pS为指向栈的指针,且pS不为NULL.
*/

void InitStack(PLINKSTACK pS)
{
	pS->pBottom  = (PNODE)malloc(sizeof(NODE));
	if (!pS->pBottom)
	{
		printf("链式栈初始化失败!\n");
		exit(ERROR);
	}

	pS->pTop = pS->pBottom;		/*刚初始化后,栈为空,此时栈指针与栈底指针相等.*/

	return;
}



void DestroyStack(PLINKSTACK pS)
{
	PNODE p = pS->pBottom;
	while (p != pS->pTop)
	{
		p = p->pNext;
		free(pS->pBottom);
		pS->pBottom = p;
	}/*栈顶指针指向的结点未释放.*/

	free(pS->pTop);	
	pS->pBottom = NULL;
	pS->pTop = NULL;
	
	return;
}

void ClearStack(PLINKSTACK pS)
{
	if (TRUE == StackEmpty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pBottom->pNext;
		PNODE q = NULL;

		while (p != pS->pTop)
		{
			q = p->pNext;
			free(p);
			p = q;
		}/*栈顶指针和栈底指针指向的结点未释放.*/

		free(pS->pTop);
		pS->pTop = pS->pBottom;
		return;
	}

}

BOOL StackEmpty(PLINKSTACK pS)
{
	if (pS->pBottom == pS->pTop)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

size_t StackLength(PLINKSTACK pS)
{
	PNODE p = pS->pBottom;
	size_t length = 0;

	while (p != pS->pTop)
	{
		++length;
		p = p->pNext;
	}

	return length;
}

STATUS GetTop(PLINKSTACK pS, Elem *e)
{
	if (TRUE ==StackEmpty(pS))
	{
		return FAILE;
	}
	else
	{
		PNODE p = pS->pBottom;
		PNODE q = NULL;
		
		while (p != pS->pTop)
		{
			q = p;
			p = p->pNext;
		}
		
		*e = q->data;
		return OK;
	}
}

void Push(PLINKSTACK pS, const Elem v)
{
	PNODE pNewTop = (PNODE)malloc(NODE);
	if (!pNewTop)
	{
		printf("入栈过程中有错误!\n");
		exit(ERROR);
	}

	pS->pTop->data = v;
	pS->pTop->pNext = pNewTop;
	pS->pTop = pNewTop;
	return OK
}

STATUS Pop(PLINKSTACK pS, Elem *e)
{
	if (TRUE ==StackEmpty(pS))
	{
		return FAILE;
	}
	else
	{
		PNODE p = pS->pBottom;
		PNODE q = NULL;
		
		while (p != pS->pTop)
		{
			q = p;
			p = p->pNext;
		}
		
		*e = q->data;
		free(pS->pTop);
		pS->pTop = q;
		return OK;
	}

}

void TraveStack(PLINKSTACK pS)
{
	PNODE p = pS->pBottom;

	while (p != pS->pTop)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}

	return;
}
