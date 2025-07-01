#ifndef __LIST_H
#define __LIST_H

#include  "portmacro.h"

typedef struct xLIST_ITEM//��ͨ�ڵ�(�б���)             һ��Ҫע���Сд��ĸ
{
	TickType_t xItemValue;
	struct xLIST_ITEM * pxNext;
	struct xLIST_ITEM * pxPrevious;   /* ָ������ǰһ���ڵ� */	
	void * pvOwner;					   /* ָ��ӵ�иýڵ���ں˶���ͨ����TCB */
	void *  pvContainer;		       /* ָ��ýڵ����ڵ����� */
}ListItem_t;
   /* �ڵ����������ض��� */



/* mini�ڵ�ṹ�嶨�壬��Ϊ˫������Ľ�β
   ��Ϊ˫����������β�����ģ�ͷ����β��β����ͷ */
typedef struct xMINI_LIST_ITEM //�������һ���ڵ�
{
	TickType_t xItemValue;                      /* ����ֵ�����ڰ����ڵ����������� */
	struct xLIST_ITEM *  pxNext;                /* ָ��������һ���ڵ� */
	struct xLIST_ITEM *  pxPrevious;            /* ָ������ǰһ���ڵ� */
}MiniListItem_t;
 //struct xMINI_LIST_ITEM ;  /* ��С�ڵ����������ض��� */



/* ����ṹ�嶨�� */
typedef struct xLIST//���ڵ�(�б�)
{
	UBaseType_t uxNumberOfItems;    /* ����ڵ������ */
	ListItem_t *  pxIndex;			/* ����ڵ�����ָ�� */
	MiniListItem_t xListEnd;		/* �������һ���ڵ� */
} List_t;


void vListInitialise( List_t * const pxList );
void vListInitialiseItem( ListItem_t * const pxItem );
void vListInsertEnd( List_t * const pxList, ListItem_t * const pxNewListItem );
void vListInsert( List_t * const pxList, ListItem_t * const pxNewListItem );
UBaseType_t uxListRemove( ListItem_t * const pxItemToRemove );

#endif
