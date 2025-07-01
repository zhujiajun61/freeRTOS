#include "list.h"

//定义列表根节点
struct xLIST  List_Test;


//定义节点
ListItem_t List_Item1;
struct xLIST_ITEM List_Item2;
struct xLIST_ITEM List_Item3;



int main(void)
{
	vListInitialise(&List_Test);
	
	vListInitialiseItem(&List_Item1);
	List_Item1.xItemValue = 1;
	
	vListInitialiseItem(&List_Item2);
	List_Item1.xItemValue = 2;
	
	vListInitialiseItem(&List_Item3);
	List_Item1.xItemValue = 3;
	
	
	vListInsert(&List_Test,&List_Item2);
	vListInsert(&List_Test,&List_Item1);
	vListInsert(&List_Test,&List_Item3);
	
	
	uxListRemove(&List_Item3);
	for(;;)
	{
		
	}
	
}

