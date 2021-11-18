#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"

MyGPIO_Struct_TypeDef GPIO_Struct;
MyGPIO_Struct_TypeDef GPIO;
MyGPIO_Struct_TypeDef GPIO2;
float cnt=0.0;
float alpha=0.0;
float teta=0.0;
float pourcentage = 0.0;

int main(void){
	MyTimer_Struct_TypeDef Timer_Codeur;
	MyTimer_Struct_TypeDef TIM; 
	TIM.Timer = TIM4; 
	TIM.ARR = 1000-1; 
	TIM.PSC = 1440-1; 
	
	
	GPIO_Struct.GPIO = GPIOB; 
	GPIO_Struct.GPIO_Pin = 6; 
	GPIO_Struct.GPIO_Conf = AltOut_Ppull; 
	MyGPIO_Init(&GPIO_Struct); 
	
	MyTimer_Base_Init(&TIM); 
		
	//MyTimer_ActiveIT(TIM2, 1, CallBack); 
 
	MyTimer_PWM(TIM4,1);	
	Timer_Codeur.Timer = TIM2;

	MyTimer_Base_Init ( &Timer_Codeur );
	
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
		alpha=cnt/4.0;
		
		if(alpha<45.0 || alpha>315.0){
			teta = 0.0;
		}
		
		if (alpha>180.0){
			alpha=360.0-alpha;
			teta=((alpha*2.0)/3.0)-30.0;
		}
		else{
			teta=((alpha*2.0)/3.0)-30.0;
		}		
		pourcentage = (teta/18.0) + 5.0;		
		
		Set_PWM_Cycle(TIM.Timer, 1, (char) pourcentage);
	}
}

