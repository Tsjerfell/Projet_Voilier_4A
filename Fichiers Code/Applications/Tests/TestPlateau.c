#include "MyTimer.h" 
#include "UART.h"
#include "Driver_GPIO.h"


signed char	vitesserotation=0;
float vitessef ;

void vitesse (){
	
	if (vitesserotation != USART1->DR) {
	        vitesserotation = USART1->DR; 
					vitessef = (float)vitesserotation;
	        if (vitessef>=0){
						   MyGPIO_Reset(GPIOB,5);
						   Set_PWM_Cycle(TIM4,'1',(vitessef) );
					} else{
						MyGPIO_Set (GPIOB,5);
						Set_PWM_Cycle(TIM4,'1',((vitessef)*(-1)) );
					}
				}
			}

 				
int main(void){
	
MyGPIO_Struct_TypeDef SENS;
MyGPIO_Struct_TypeDef PWM;
MyTimer_Struct_TypeDef TIMER4;
MyGPIO_Struct_TypeDef GPIO_USART_RX = {GPIOA, 10, In_PullDown}; 

	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPAEN |  RCC_APB2ENR_USART1EN; 
	RCC->APB2ENR |= RCC_APB1ENR_TIM4EN; 

	TIMER4.Timer = TIM4;
	TIMER4.ARR = 3600; //Pour une fréquence de 20kHz
	TIMER4.PSC = 1; 

	MyTimer_Base_Init(&TIMER4);
	
  //Configuration du GPIO et initialisation de la PWM 
	PWM.GPIO = GPIOB; 
	PWM.GPIO_Pin = 6; 
	PWM.GPIO_Conf = AltOut_Ppull; 
	MyGPIO_Init(&PWM); 
	
	SENS.GPIO = GPIOB; 
	SENS.GPIO_Pin = 5; //bit de sens PC6
	SENS.GPIO_Conf = Out_Ppull; 
	MyGPIO_Init(&SENS);
	UART_Init(USART1, RX, 9600);
	MyGPIO_Init(&GPIO_USART_RX); 
	

  UART_ActiveIT(USART1, 3,vitesse);
	
	MyTimer_PWM(TIM4, '1'); 
	MyTimer_Base_Start(TIM4); 
	
	do
	{
		
	}while(1) ; 


}

