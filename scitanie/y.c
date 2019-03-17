/*--------------------------------------------------------*/
/*Vyhotovil: Martin Chlebovec                             */
/*Bezpecnost v pocitacovych systemoch                     */
/*Implementacia Multiply a xtime funkcie pre cisla > uint8*/
/*Vyjadrenie vysledkov v DEC a BIN tvare                  */
/*--------------------------------------------------------*/

#include <stdio.h>
#include "aes.h"
#include <stdint.h>
#include <string.h>
static uint8_t xtime(uint8_t x){
	return ((x<<1) ^ (((x>>7) & 1) * 0x1b));
}
static uint8_t Multiply(uint8_t  x, uint8_t  y){
  	return (((y & 1) * x) ^
       ((y>>1 & 1) * xtime(x)) ^
       ((y>>2 & 1) * xtime(xtime(x))) ^
       ((y>>3 & 1) * xtime(xtime(xtime(x)))) ^
       ((y>>4 & 1) * xtime(xtime(xtime(xtime(x)))))); /* this last call to xtime() can be omitted */
}

void main(){
	uint8_t cislo1, decimal_num, remainder, base = 1, binary = 0;
	uint8_t cislo2, decimal_num2, remainder2, base2 = 1, binary2 = 0;	
	printf("Zadajte operandy v rozsahu 0 - 255 \n");
	printf("Zadajte operand c. 1: \n");
    	scanf("%ld", &cislo1);
	printf("Zadajte operand c. 2: \n");
  	scanf("%ld", &cislo2);
    	decimal_num = cislo1;
    	decimal_num2 = cislo2;
    	while (cislo1 > 0){
        	remainder = cislo1 % 2;
        	binary = binary + remainder * base;
        	cislo1 = cislo1 / 2;
        	base = base * 10;
    	}
	while (cislo2 > 0){
        	remainder2 = cislo2 % 2;
        	binary2 = binary2 + remainder2 * base2;
        	cislo2 = cislo2 / 2;
        	base2 = base2 * 10;
    	}
    	printf("Zadany operand 1: %d\n", decimal_num);
    	printf("Operand 1 binarne: %ld\n", binary);
	printf("Zadany operand 2: %d\n", decimal_num2);
    	printf("Operand 2 binarne: %ld\n", binary2);
	printf("-------------------------------------------\n");	
	//unsigned long operacia_or;
	//operacia_or = decimal_num | decimal_num2;
	//printf("Vysledok bitovej operacie OR: %d\n", operacia_or);
	//unsigned long operacia_xor;
	//operacia_xor = decimal_num ^ decimal_num2;
	//printf("Vysledok bitovej operacie XOR: %d\n", operacia_xor);

	//NASOBENIE FAKTOROM 2
	 uint8_t res = xtime(decimal_num);
	printf("Vysledok xtime operand 1: %d\n", res);
	uint8_t  remainder3, base3 = 1, binary3 = 0;
	while (res > 0){
                remainder3 = res % 2;
                binary3 = binary3 + remainder3 * base3;
                res = res / 2;
                base3 = base3 * 10;
       }
	printf("xtime binarne pre operand 1: %ld\n", binary3);

	uint8_t  res2 = xtime(decimal_num2);
        printf("Vysledok xtime operand 2: %d\n", res2);
        uint8_t remainder4, base4 = 1, binary4 = 0;
        while (res2 > 0){
                remainder4 = res2 % 2;
                binary4 = binary4 + remainder4 * base4;
                res2 = res2 / 2;
                base4 = base4 * 10;
        }
        printf("xtime binarne pre operand 2: %ld\n", binary4);
	uint8_t  res3 = Multiply(decimal_num, decimal_num2);
 	printf("Vysledok operacie Multiply: %d\n", res3);
	uint8_t remainder5, base5 = 1, binary5 = 0;
	while (res3 > 0){
                remainder5 = res3 % 2;
                binary5 = binary5 + remainder5 * base5;
                res3 = res3 / 2;
                base5 = base5 * 10;
        }
	printf("Vysledok operacie Multiply binarne: %ld\n", binary4);
}
