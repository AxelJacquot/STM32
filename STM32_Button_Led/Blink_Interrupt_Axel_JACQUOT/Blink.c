#include "stm32f4xx_hal.h"

#define Bouton GPIO_PIN_0

#define Vert GPIO_PIN_12
#define Orange GPIO_PIN_13
#define Rouge GPIO_PIN_14
#define Bleu GPIO_PIN_15
#define On GPIO_PIN_SET
#define Off GPIO_PIN_RESET


void config_initial(void);
void wait(unsigned int time);
void Led_Dessin(unsigned int *time_push);
unsigned int i;

unsigned short Tab_Led[6]={Rouge,Orange,Vert,Bleu,0};

int main(void){
	config_initial();
	while(1){}
}
void config_initial(void){
	
	//Activation des ports A et D
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
		
	//Configuration des pins 12,13,14 et 15  du port D coorepondant au Leds de la carte
	GPIO_InitTypeDef Leds;
	Leds.Mode = GPIO_MODE_OUTPUT_PP;
	Leds.Pin = Vert | Orange | Rouge | Bleu;
	
	//Configuration du pin 0 du port A correspondant au bouton_User de la carte
	GPIO_InitTypeDef monBouton;
	monBouton.Mode = GPIO_MODE_IT_FALLING;													//Le bouton est lance une interruption apr�s chaque appuie du bouton
	monBouton.Pin = Bouton;	
	
	//Activation des configuration effectu� auparavant
	HAL_GPIO_Init(GPIOD,&Leds);
	HAL_GPIO_Init(GPIOA,&monBouton);
	
	HAL_NVIC_SetPriority(EXTI0_IRQn, 5, 5); 												// PreemptPriority = 5, SubPriority = 5
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	static unsigned char cmp = 0;																		//D�clarartion d'un variable en static se qui nous permet qu'elle soit garder en m�moire un fois l'interruption fini
	while(HAL_GPIO_ReadPin(GPIOA,Bouton));													//Antirebond
	wait(10);
	HAL_GPIO_WritePin(GPIOD,Vert | Orange | Rouge | Bleu,Off);			//Eteint toutes les leds
	HAL_GPIO_WritePin(GPIOD,Tab_Led[cmp],On);												//Allume la led correspondant au nombre de fois que nous avons appuy� sur le bouton
	cmp++;																													//Incr�mentation du nombre de fois ou le bouton a �t� appuy�
	if(cmp == 6)																										//V�rification si nombre de fois ou le bouton a �t� appuy� n'est pas hors de limite
		cmp=0;																												//Remise � z�ro du nombre d'appuie du bouton
}
void EXTI0_IRQHandler(void){
 HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void wait (unsigned int time){
	for(i = 0; i<time*4000;i++); //16MHz/4ms for 4M loops/sec => 1ms=4k loops
	return;
}