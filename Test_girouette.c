#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

void Callback(void){
	MyGPIO_Toggle(GPIOC, 10);
}

int main(void) {
	MyGPIO_Struct_TypeDef GPIO;
	MyGPIO_Struct_TypeDef GPIO2;
	MyTimer_Struct_TypeDef Timer1_Test;
	Timer1_Test.Timer = TIM2;

	MyTimer_Base_Init ( &Timer1_Test );
	
	
	GPIO.GPIO=GPIOA;
	GPIO.GPIO_Pin=0;
	GPIO.GPIO_Conf=In_PullDown;
	MyGPIO_Init(&GPIO);
	
	GPIO2.GPIO=GPIOA;
	GPIO2.GPIO_Pin=1;
	GPIO2.GPIO_Conf=In_PullDown;
	MyGPIO_Init(&GPIO2);
	

	Init_Codeur(Timer1_Test.Timer);

	while(1) ;
}

