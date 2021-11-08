#include "MySpi.h"

void My_Spi_init( SPI_TypeDef* Spi){
	
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN; //Enable SPI1 clock
	SPI1 ->CR1 |= (0x3>3); //Horloge de 4,5MHz. Pas de macro
	SPI1 -> CR1 |= SPI_CR1_CPHA;
	
	
}
