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
void Led(unsigned int *cmp);													//sous programme de gestion des leds allum� avec un sch�ma pr�cis

const unsigned short Tab_Led[4]={Vert,Rouge,Orange,Bleu}; //tableau contenant les leds a llum� ainsi que leurs sens

int main(void){
	//unsigned int push_time = 0;
	unsigned int cmp = 0;
	config_initial();
	while(1){
		if(HAL_GPIO_ReadPin(GPIOA,Bouton)){										//V�rifie si le bouton est appuy�
			while(HAL_GPIO_ReadPin(GPIOA,Bouton));							//AntiRebond au noveau du bouton permettant aussi d'effectuer l'action apr�s relachement du bouton
			wait(10);																	
			Led(&cmp);														//Sous programme g�rant la led a llum� selon le nombre de fois o� le bouton a �t� appuy�
			cmp++;															//Incr�mentation du nombre de fois o� le bouton a �t� apuy�
			if(cmp == 4)													//V�rification si nombre de fois ou le bouton a �t� appuy� n'est pas hors de limite
				cmp=0;
		}
		/*while(HAL_GPIO_ReadPin(GPIOA,Bouton)){					//Code du main pour
			wait(100);
			push_time++;
		}
		Led_Dessin(&push_time);*/
	}
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
	monBouton.Mode = GPIO_MODE_INPUT;
	monBouton.Pin = GPIO_PIN_0;	
	
	//Activation des configuration effectu� auparavant
	HAL_GPIO_Init(GPIOD,&Leds);
	HAL_GPIO_Init(GPIOA,&monBouton);
	
}

void Led(unsigned int *cmp){				
	HAL_GPIO_WritePin(GPIOD,Vert | Orange | Rouge | Bleu,Off);				//Eteint toutes les leds
	HAL_GPIO_WritePin(GPIOD,Tab_Led[*cmp],On);												//Allume la led correspondant au nombre de fois que nous avons appuy� sur le bouton
	
	/*switch(*cmp){																				//Switch Case permettant de g�rer la Led a allum� selon le nombre de fois o� le bouton a �t� appuy�
		case 0:																						
			HAL_GPIO_WritePin(GPIOD,Vert,On);
			break;
		case 1:																						
			HAL_GPIO_WritePin(GPIOD,Vert,Off);
			HAL_GPIO_WritePin(GPIOD,Rouge,On);
			break;
		case 2:																						
			HAL_GPIO_WritePin(GPIOD,Rouge,Off);
			HAL_GPIO_WritePin(GPIOD,Orange,On);
			break;
		case 3:																						
			HAL_GPIO_WritePin(GPIOD,Orange,Off);
			HAL_GPIO_WritePin(GPIOD,Bleu,On);
			break;
		case 4:																						
			HAL_GPIO_WritePin(GPIOD,Bleu,Off);
			*cmp = 0;																				//remise � z�ro du nombre d'appuie du bouton 
			break;
	}*/
}

/*void Led_Dessin(unsigned int *time_push){								//Sous programme utilisant le temps d'appuie du bouton pour effectuer des actions sur les leds
	unsigned int i;
	if(*time_push <= 5 && *time_push > 0){
			for(i=0;i<2;i++){
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
				wait(500);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);
				wait(500);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
				wait(500);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1);
				wait(500);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,0);
			}
		}
	else if(*time_push <= 20 && *time_push > 5){
			for(i=0;i<10;i++){
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1);
				wait(200);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,0);
				wait(200);
			}
	}
	else if(*time_push > 20){
			for(i=0;i<10;i++){
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,1);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,1);
				wait(200);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,0);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,1);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,1);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,0);
				wait(200);
			}
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,0);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,0);
	}
		*time_push = 0;
		return;
}*/

void wait (unsigned int time){
	for(int i = 0; i<time*4000;i++); //16MHz/4ms for 4M loops/sec => 1ms=4k loops
}