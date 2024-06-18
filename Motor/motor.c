#include  "motor.h"

void motor_start_stop(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2)   									
{
	  /* 
	                      ���ֹͣ����
	Param:*   htim����ʱ��
	          CHANNEL_IN2��CHANNEL_IN1����ʱ��ͨ��		
		*/
		HAL_TIM_PWM_Stop(htim, CHANNEL_IN1);			//�ر�CH1ͨ�����
		HAL_TIM_PWM_Stop(htim, CHANNEL_IN2);			//�ر�CH2ͨ�����
}

void motor_advance(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2, uint32_t velocity)										
{
	  /* 
	                      ���ǰ������
	Param:*   htim����ʱ��
	          CHANNEL_IN2��CHANNEL_IN1����ʱ��ͨ��	
	          velocity:�޸�ռ�ձ� 	
		*/
	HAL_TIM_PWM_Stop(htim, CHANNEL_IN1);				//�ر�CH1ͨ�����
	HAL_Delay(50);											//��ʱ
	HAL_TIM_PWM_Start(htim, CHANNEL_IN2);			//����CH2ͨ�����
	__HAL_TIM_SetCompare(htim,CHANNEL_IN2,velocity);			//������ʼ�ٶȣ�ռ�ձ�xx%��
	velocity = velocity;											//���ٱ��� ��λ
}
 
void motor_Back(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2, uint32_t velocity)											
{
	  /* 
	                      ������˺���
	Param:*   htim����ʱ��
	          CHANNEL_IN2��CHANNEL_IN1����ʱ��ͨ��	
	          velocity:�޸�ռ�ձ� 	
		*/
	HAL_TIM_PWM_Stop(htim, CHANNEL_IN2);				//�ر�CH2ͨ�����
	HAL_Delay(50);											//��ʱ
	HAL_TIM_PWM_Start(htim, CHANNEL_IN1);				//����CH1ͨ�����
	__HAL_TIM_SetCompare(htim,CHANNEL_IN1,velocity);			//������ʼ�ٶȣ�ռ�ձ�xx%��  �޸�ռ�ձ����
	velocity = velocity;											//���ٱ��� ��λ
}

void motor_hasten(TIM_HandleTypeDef *htim ,uint32_t channel, uint32_t velocity)											
{
		/* 
	                      ������ٺ���
	Param:    *htim����ʱ��
	          CHANNEL_IN2��CHANNEL_IN1����ʱ��ͨ��		
		*/
	if(velocity <= 8399)										//�ж�ռ�ձ��Ƿ�Ϊ100%
	{
		velocity += 800;									//����ռ�ձȣ�����10%��
		__HAL_TIM_SetCompare(htim,channel,velocity);//ÿ������10%
	}
}

