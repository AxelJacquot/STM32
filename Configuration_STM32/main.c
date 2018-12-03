//#include "configuration.h"
#include "configuration.c"

void wait (unsigned int time);
void Led(unsigned char *led);
TIM_HandleTypeDef TIM_Handle;

int main(void){
	unsigned char cmp = 0;
	GPIO_Configuration(GPIOA, GPIO_MODE_INPUT, Button_Pin,0);
	GPIO_Configuration(GPIOD, GPIO_MODE_AF_PP, Green | Orange | Red | Blue, GPIO_AF2_TIM4);
	Timer_Config(&TIM_Handle,TIM4, 16000, 2000);
	Timer_Mode_OCPWM_Config(&TIM_Handle, TIM_OCMODE_PWM2, TIM_OCPOLARITY_HIGH);
	Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_1, 250);
	Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_4, 1500);
	HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_1);
	HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_4);
	while(1){
		/*if(HAL_GPIO_ReadPin(GPIOA,Button_Pin)){										//V?rifie si le bouton est appuy?
			while(HAL_GPIO_ReadPin(GPIOA,Button_Pin));							//AntiRebond au noveau du bouton permettant aussi d'effectuer l'action apr?s relachement du bouton
			wait(10);																	
			Led(&cmp);														//Sous programme g?rant la led a llum? selon le nombre de fois o? le bouton a ?t? appuy?
			cmp++;															//Incr?mentation du nombre de fois o? le bouton a ?t? apuy?
			if(cmp == 4)													//V?rification si nombre de fois ou le bouton a ?t? appuy? n'est pas hors de limite
				cmp=0;
		}*/
	}
}
	
/*void Led(unsigned char *led){
	if(*led == 0){
		Timer_Config(&TIM_Handle,TIM4, 16000, 2000);
		Timer_Mode_OCPWM_Config(&TIM_Handle, TIM_OCMODE_PWM2, TIM_OCPOLARITY_HIGH);
		Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_1, 250);
		Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_2, 500);
		Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_3, 1000);
		Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_4, 1500);
		HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_1);
		HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_2);
		HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_3);
		HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_4);
	}
	else if (*led==1){
		HAL_TIM_OC_Stop(&TIM_Handle, TIM_CHANNEL_1);
		HAL_TIM_OC_Stop(&TIM_Handle, TIM_CHANNEL_2);
		HAL_TIM_OC_Stop(&TIM_Handle, TIM_CHANNEL_3);
		HAL_TIM_OC_Stop(&TIM_Handle, TIM_CHANNEL_4);
	}
	else if(*led == 2){
		Timer_Config(&TIM_Handle, TIM4, 16000,6000);
		//Timer_Mode_OCPWM_Config(&TIM_Handle, TIM_OCMODE_PWM2, TIM_OCPOLARITY_HIGH);
		Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_1, 625);
		Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_2, 1250);
		Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_3, 2500);
		Timer_PWM_OCPWM_Pulse_Channel(&TIM_Handle, TIM_CHANNEL_4, 5000);
		HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_1);
		HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_2);
		HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_3);
		HAL_TIM_OC_Start(&TIM_Handle, TIM_CHANNEL_4);
	}
	else{
		HAL_TIM_OC_Stop(&TIM_Handle, TIM_CHANNEL_1);
		HAL_TIM_OC_Stop(&TIM_Handle, TIM_CHANNEL_2);
		HAL_TIM_OC_Stop(&TIM_Handle, TIM_CHANNEL_3);
		HAL_TIM_OC_Stop(&TIM_Handle, TIM_CHANNEL_4);
	}
	
}*/
	

	

void wait (unsigned int time){
	for(int i = 0; i<time*4000;i++); //16MHz/4ms for 4M loops/sec => 1ms=4k loops
}
