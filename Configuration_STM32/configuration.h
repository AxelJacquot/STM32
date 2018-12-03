#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "stm32f4xx_hal.h"

#define LED_Port	GPIOD
#define Green			GPIO_PIN_12
#define Orange		GPIO_PIN_13
#define Red				GPIO_PIN_14
#define Blue 			GPIO_PIN_15
#define Button_Pin	GPIO_PIN_0
#define TIMER4		4
#define Led_all		Green | Orange | Red | Blue

/*void Timer_Mode_OCPWM_Config(TIM_HandleTypeDef * Timer, unsigned int mode, unsigned int polarity);
void Timer_PWM_OCPWM_Pulse_Channel(TIM_HandleTypeDef * Timer, unsigned int channel, unsigned int pulse);
void ENABLE_CLK_TIMER_CHOICE(TIM_TypeDef * timer);
void Timer_Config(TIM_HandleTypeDef * Timer, TIM_TypeDef * timer_choice, unsigned int prescaler, unsigned int period);
void Timer_Mode_IC_Config(TIM_HandleTypeDef * Timer, unsigned int polarity, unsigned int filter, unsigned int selection, unsigned int prescaler);

void ENABLE_CLK_GPIO(GPIO_TypeDef * GPIO);
void GPIO_Configuration(GPIO_TypeDef * GPIO, unsigned int mode, unsigned int Pin, unsigned int alternate);*/



//extern TIM_TypeDef * ENABLE_TIMER_CHOICE(unsigned char timer);
//void Timer_Mode_Config(unsigned int mode, unsigned int polarity);
//void Timer_PWM_OC_Pulse_Channel(unsigned int channel, unsigned int pulse);


//void GPIO_Configuration(unsigned int GPIO, GPIO_InitTypeDef * GPIO_Config, unsigned int mode, unsigned int Pin, unsigned int alternate)



#endif
