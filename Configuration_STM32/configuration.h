#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_



#define LED_Port	GPIOD
#define Green			GPIO_PIN_12
#define Orange		GPIO_PIN_13
#define Red				GPIO_PIN_14
#define Blue 			GPIO_PIN_15
#define Button_Pin	GPIO_PIN_0
#define TIMER4		4
#define Led_all		Green | Orange | Red | Blue




//extern TIM_TypeDef * ENABLE_TIMER_CHOICE(unsigned char timer);
//void Timer_Mode_Config(unsigned int mode, unsigned int polarity);
//void Timer_PWM_OC_Pulse_Channel(unsigned int channel, unsigned int pulse);


//void GPIO_Configuration(unsigned int GPIO, GPIO_InitTypeDef * GPIO_Config, unsigned int mode, unsigned int Pin, unsigned int alternate)



#endif
