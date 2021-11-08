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
	Timer1_Test.Timer = TIM3;

	MyTimer_Base_Init ( &Timer1_Test );
	
	
	GPIO.GPIO=GPIOC;
	GPIO.GPIO_Pin=7;
	GPIO.GPIO_Conf=Out_Ppull;
	MyGPIO_Init(&GPIO);
	
	GPIO2.GPIO=GPIOB;
	GPIO2.GPIO_Pin=4;
	GPIO2.GPIO_Conf=Out_Ppull;
	MyGPIO_Init(&GPIO2);
	

	Init_Codeur(Timer1_Test.Timer);

	while(1) ;
}

