/*
 * PWM.c
 *
 *  Created on: 3 juin 2021
 *      Author: mario
 */
#include "main.h"
#include "PWM.h"
#include "tim.h"

void MP_setPWM(TIM_HandleTypeDef *htim,int Channel,int valeur_16b){
	if (valeur_16b > 65535 && valeur_16b < 0)
		return;
	else {
      	HAL_TIM_PWM_Start(htim,Channel);
		if (Channel == TIM_CHANNEL_1){
			htim->Instance->CCR1 = valeur_16b;
		}
		else if (Channel == TIM_CHANNEL_2){
			htim->Instance->CCR2 = valeur_16b;
		}
	}
}
