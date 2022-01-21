#include "stm8s.h"
#include "milis.h"
#include "stm8_hd44780.h"
#include "spse_stm8.h" 
#include "delay.h"
#include <stdio.h>
#define _ISOC99_SOURCE
#define _GNU_SOURCE

void setup(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    lcd_init(); //inicializace LCD
    GPIO_Init(GPIOB,GPIO_PIN_6,GPIO_MODE_OUT_PP_LOW_SLOW); // výstup PB6 buzzer
    GPIO_Init(GPIOB, GPIO_PIN_7,GPIO_MODE_IN_FL_NO_IT); // vstup B7 tlačítko encoderu
    GPIO_Init(GPIOC, ((GPIO_Pin_TypeDef)(GPIO_PIN_1 | GPIO_PIN_2)),GPIO_MODE_IN_PU_NO_IT); //inicializace pinů C1 a C2 pro enkoder 
    TIM1_DeInit();
    TIM1_TimeBaseInit(8, TIM1_COUNTERMODE_UP, 60, 8); //inicializace enkoderu
    TIM1_EncoderInterfaceConfig(TIM1_ENCODERMODE_TI12,TIM1_ICPOLARITY_FALLING,TIM1_ICPOLARITY_FALLING);
    TIM1_Cmd(ENABLE);
}

void delay_ms(uint16_t ms) {
    uint16_t  i;
    for (i=0; i<ms; i = i+1){
        _delay_us(250);
        _delay_us(248);
        _delay_us(250);
        _delay_us(250);
    }
}

int main(void)
{
    char text[32];
    uint32_t pomocna = 0;
    unsigned int present_value = 0x0000;   // promenne pro ncoder (hodnoty)
    unsigned int previous_value = 0x0001;


    
    setup();

    lcd_gotoxy(0, 0);
    sprintf(text,"pocatecni cas:");
    lcd_puts(text);

    lcd_gotoxy(0, 1);
    sprintf(text,"cas do konce:");
    lcd_puts(text);

    while (1) {
        if(GPIO_ReadInputPin(GPIOB,GPIO_PIN_7)==RESET){ //tlacitko ncoderu
            
            while(present_value>0){ //while se točí dokud present_value není 0 
                present_value = present_value -1;
