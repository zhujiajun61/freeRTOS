#include "bsp_led.h"
#include "usart.h"
#include "sys.h"

#include "FreeRTOS.h"
#include "task.h"
#include "key.h"

/***********************��������***************************/
static void LED1_Task(void* parameter);
static void LED2_Task(void* parameter);
static void AppTaskCreate(void);
static void KEY_Task(void* parameter);






/***********************��������*************************/
static TaskHandle_t AppTaskCreate_Handle = NULL;
static TaskHandle_t LED1_Task_Handle = NULL;
static TaskHandle_t LED2_Task_Handle = NULL;
static TaskHandle_t KEY_Task_Handle = NULL;






/**********************************************************/
static void BSP_init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	LED_Init();
	KEY_Init();
	uart_init(115200);
}

int main(void)
{
	BaseType_t xReturn = pdPASS;
	BSP_init();
	
	xReturn =xTaskCreate((TaskFunction_t)		AppTaskCreate,
											 (const char*)			"AppTaskCreate",
											 (uint16_t)					512,
											 (void*)						NULL,
											 (UBaseType_t)      1,
											 (TaskHandle_t*)		&AppTaskCreate_Handle);
	if(pdPASS == xReturn) //�������񣬿�������
	{printf("start");
		vTaskStartScheduler();}
	else 	
		return-1;
											 
											 
	while(1);

}


static void LED1_Task(void* parameter)
{
	while(1)
	{
		printf("����1������\r\n");
		LED1_ON;
		vTaskDelay(500);
		LED1_OFF;
		vTaskDelay(500);
	}
}

static void LED2_Task(void* parameter)
{
	while(1)
	{
		printf("����2������\r\n");
		LED2_ON;
		vTaskDelay(500);
		LED2_OFF;
		vTaskDelay(500);
	}
}

static void KEY_Task(void* parameter)
{
	while(1)
	{
		//printf("KEY�������\r\n");
		switch(KEY_Scan(0)){
			case KEY0_PRES:
				printf("LED1����");
				vTaskSuspend(LED1_Task_Handle);
				break;
			case KEY1_PRES:
				printf("LED1�ָ�");
				vTaskResume(LED1_Task_Handle);
				break;
		}
		vTaskDelay(20);
	}
}

static void AppTaskCreate(void)
{
	BaseType_t xReturn = pdPASS;//����һ��������Ϣ����ֵ��Ĭ��ΪpdPASS
	taskENTER_CRITICAL();//�����ٽ���
	
	xReturn = xTaskCreate((TaskFunction_t)		LED1_Task,
												(const char*)				"LED1_Task",
												(uint16_t)					512,
												(void*)							NULL,
												(UBaseType_t)				3,
												(TaskHandle_t*)			&LED1_Task_Handle);									
	if(pdPASS == xReturn) printf("����LED1����ɹ�\r\n");
	
	xReturn = xTaskCreate((TaskFunction_t)		LED2_Task,
												(const char*)				"LED2_Task",
												(uint16_t)					512,
												(void*)							NULL,
												(UBaseType_t)				4,
												(TaskHandle_t*)			&LED2_Task_Handle);									
	if(pdPASS == xReturn) printf("����LED2����ɹ�\r\n");
												
	xReturn = xTaskCreate((TaskFunction_t)		KEY_Task,
												(const char*)				"KEY_Task",
												(uint16_t)					512,
												(void*)							NULL,
												(UBaseType_t)				5,
												(TaskHandle_t*)			&KEY_Task_Handle);									
	if(pdPASS == xReturn) printf("����KEY����ɹ�\r\n");
												
	vTaskDelete(AppTaskCreate_Handle);
	taskEXIT_CRITICAL();
}				



















