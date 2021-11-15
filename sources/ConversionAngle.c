#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

MyGPIO_Struct_TypeDef GPIO_Struct;


int main(void){
	MyTimer_Struct_TypeDef TIM; 
	TIM.Timer = TIM4; 
	TIM.ARR = 9000-1; 
	TIM.PSC = 4000-1; 
	
	
	GPIO_Struct.GPIO = GPIOB; 
	GPIO_Struct.GPIO_Pin = 6; 
	GPIO_Struct.GPIO_Conf = AltOut_Ppull; 
	MyGPIO_Init(&GPIO_Struct); 
	

	MyTimer_Base_Init(&TIM); 
	
	
	//MyTimer_ActiveIT(TIM2, 1, CallBack); 
  
	MyTimer_PWM(TIM4,1);

	
	Set_PWM_Cycle(TIM4,1,20);
	
	
	
	
	
	int cnt=0;
	int alpha=0;
	int teta=0;
	MyGPIO_Struct_TypeDef GPIO;
	MyGPIO_Struct_TypeDef GPIO2;
	MyTimer_Struct_TypeDef Timer_Codeur;
	Timer_Codeur.Timer = TIM3;

	MyTimer_Base_Init ( &Timer1_Test );
	
	
	GPIO.GPIO=GPIOA;
	GPIO.GPIO_Pin=0;
	GPIO.GPIO_Conf=In_PullDown;
	MyGPIO_Init(&GPIO);
	
	GPIO2.GPIO=GPIOA;
	GPIO2.GPIO_Pin=1;
	GPIO2.GPIO_Conf=In_PullDown;
	MyGPIO_Init(&GPIO2);
	
	Init_Codeur(Timer_Codeur.Timer);
	
	while(1){
		cnt=Timer_Codeur.Timer->CNT;
		alpha=cnt/4;
		
		if(alpha<45 || alpha>315){
			teta = 0;
		}
		
		if (alpha>180){
			alpha=360-alpha;
			teta=((alpha*2)/3)-30;
		}
		else{
			teta=((alpha*2)/3)-30;
		}
		
		pourcentage = (teta/18) + 5;
		
		Set_PWM_Cycle(TIM.Timer, 1, (char) pourcentage);
	}
}