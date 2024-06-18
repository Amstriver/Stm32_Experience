#ifndef _MOTOR_H
#define _MOTOR_H

#include "main.h"

void motor_start_stop(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2);
void motor_advance(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2, uint32_t velocity);
void motor_Back(TIM_HandleTypeDef *htim ,uint32_t CHANNEL_IN1,uint32_t CHANNEL_IN2, uint32_t velocity);
void motor_hasten(TIM_HandleTypeDef *htim ,uint32_t channel, uint32_t velocity);

#endif 
