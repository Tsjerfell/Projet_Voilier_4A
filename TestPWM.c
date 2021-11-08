#include "MyTimer.h" 
#include "GPIO.h"
#include "stm32f10x.h"

MyGPIO_Struct_TypeDef GPIO_Struct;

void CallBack (void) 
{
	MyGPIO_Toggle (GPIO_Struct.GPIO, GPIO_Struct.GPIO_Pin);
}

int main(void)
{
	//Configuration + Activation du Timer
 //RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ; 
 //TIM2->ARR = 1000 -1 ; 
 //TIM2->PSC = 4000-1; 
 //TIM2->CR1 = TIM2->CR1 | TIM_CR1_CEN; 
	
 //Configuration du timer 
	MyTimer_Struct_TypeDef TIM; 
	TIM.Timer = TIM2; 
	TIM.ARR = 9000-1; 
	TIM.PSC = 4000-1; 
	
	/*GPIO_Struct.GPIO = GPIOC; 
	GPIO_Struct.GPIO_Pin = 10; 
	GPIO_Struct.GPIO_Conf = Out_Ppull; 
	MyGPIO_Init(&GPIO_Struct);*/
	
	
	GPIO_Struct.GPIO = GPIOA; 
	GPIO_Struct.GPIO_Pin = 1; 
	GPIO_Struct.GPIO_Conf = AltOut_Ppull; 
	MyGPIO_Init(&GPIO_Struct); 
	

	MyTimer_Base_Init(&TIM); 
	
	
	//MyTimer_ActiveIT(TIM2, 1, CallBack); 
  
	MyTimer_PWM(TIM2,2);

	
	Set_PWM_Cycle(TIM2,2,20);
	
 do
	{
		
	}while(1) ; 
}


