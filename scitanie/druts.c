#include <stdio.h>
#include <stdint.h>
#include <string.h>
static unsigned long xtime(unsigned long x){
	return ((x<<1) ^ (((x>>7) & 1) * 0x1b));
}
static uint8_t Multiply(uint8_t x, uint8_t y){
  	return ((y & 1) * x) ^
       ((y>>1 & 1) * xtime(x)) ^
       ((y>>2 & 1) * xtime(xtime(x))) ^
       ((y>>3 & 1) * xtime(xtime(xtime(x)))) ^
       ((y>>4 & 1) * xtime(xtime(xtime(xtime(x)))))^
       ((y>>5 & 1) * xtime(xtime(xtime(xtime(xtime(x)))))) ^
       ((y>>6 & 1) * xtime(xtime(xtime(xtime(xtime(xtime(x)))))))^
       ((y>>7 & 1) * xtime(xtime(xtime(xtime(xtime(xtime(xtime(x))))))));
}

void main(){

        uint8_t x, y;
        uint8_t result;
// vstupy z prikladu 4.3 (2.tyzden), vysledok ma byt 0xFE
        x = 0xAA;
        y = 0xbb;

        result = Multiply( x, y );
        printf("Res = 0x%02x", result);
        return;
}

