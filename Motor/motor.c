#include  "motor.h"

void motor_start_stop(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2)   									
{
	  /* 
	                      电机停止函数
	Param:*   htim：定时器
	          CHANNEL_IN2、CHANNEL_IN1：定时器通道		
		*/
		HAL_TIM_PWM_Stop(htim, CHANNEL_IN1);			//关闭CH1通道输出
		HAL_TIM_PWM_Stop(htim, CHANNEL_IN2);			//关闭CH2通道输出
}

void motor_advance(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2, uint32_t velocity)										
{
	  /* 
	                      电机前进函数
	Param:*   htim：定时器
	          CHANNEL_IN2、CHANNEL_IN1：定时器通道	
	          velocity:修改占空比 	
		*/
	HAL_TIM_PWM_Stop(htim, CHANNEL_IN1);				//关闭CH1通道输出
	HAL_Delay(50);											//延时
	HAL_TIM_PWM_Start(htim, CHANNEL_IN2);			//开启CH2通道输出
	__HAL_TIM_SetCompare(htim,CHANNEL_IN2,velocity);			//给定初始速度（占空比xx%）
	velocity = velocity;											//加速变量 复位
}
 
void motor_Back(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2, uint32_t velocity)											
{
	  /* 
	                      电机后退函数
	Param:*   htim：定时器
	          CHANNEL_IN2、CHANNEL_IN1：定时器通道	
	          velocity:修改占空比 	
		*/
	HAL_TIM_PWM_Stop(htim, CHANNEL_IN2);				//关闭CH2通道输出
	HAL_Delay(50);											//延时
	HAL_TIM_PWM_Start(htim, CHANNEL_IN1);				//开启CH1通道输出
	__HAL_TIM_SetCompare(htim,CHANNEL_IN1,velocity);			//给定初始速度（占空比xx%）  修改占空比语句
	velocity = velocity;											//加速变量 复位
}

void motor_hasten(TIM_HandleTypeDef *htim ,uint32_t channel, uint32_t velocity)											
{
		/* 
	                      电机加速函数
	Param:    *htim：定时器
	          CHANNEL_IN2、CHANNEL_IN1：定时器通道		
		*/
	if(velocity <= 8399)										//判断占空比是否为100%
	{
		velocity += 800;									//更改占空比（增加10%）
		__HAL_TIM_SetCompare(htim,channel,velocity);//每次增加10%
	}
}

