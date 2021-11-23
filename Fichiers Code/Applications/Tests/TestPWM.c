#include "MyTimer.h" 
#include "Driver_GPIO.h"
#include "stm32f10x.h"

//MyGPIO_Struct_TypeDef GPIO_Struct;
MyGPIO_Struct_TypeDef GPIO;
MyTimer_Struct_TypeDef TIM;

/*
void CallBack (void) 
{
	MyGPIO_Toggle (GPIO_Struct.GPIO, GPIO_Struct.GPIO_Pin);
}
*/

int main(void)
{
 //Configuration du timer 
	//MyTimer_Struct_TypeDef TIM; 
	//TIM.Timer = TIM2; 
	//TIM.ARR = 9000-1; 
	//TIM.PSC = 4000-1; 
	//Configuration + Activation du Timer
 //RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ; 
 //TIM2->ARR = 1000 -1 ; 
 //TIM2->PSC = 4000-1; 
 //TIM2->CR1 = TIM2->CR1 | TIM_CR1_CEN; 
	/*GPIO_Struct.GPIO = GPIOC; 
	GPIO_Struct.GPIO_Pin = 10; 
	GPIO_Struct.GPIO_Conf = Out_Ppull; 
	MyGPIO_Init(&GPIO_Struct);*/

	//Timer
	TIM.Timer=TIM2;
	TIM.ARR = 9000-1; 
	TIM.PSC = 4000-1;


	MyTimer_Base_Init(&TIM);
	MyTimer_Base_Start(TIM.Timer);

	//GPIO
	GPIO.GPIO=GPIOA;
	GPIO.GPIO_Pin=1;
	GPIO.GPIO_Conf=AltOut_Ppull;
	MyGPIO_Init(&GPIO);


	//PWM
	MyTimer_PWM(TIM.Timer, 2);
	Set_PWM_Cycle(TIM.Timer,2,80);
	
	
	//MyTimer_ActiveIT(TIM2, 1, CallBack); 
  
	
 do
	{
		
	}while(1) ; 
}


