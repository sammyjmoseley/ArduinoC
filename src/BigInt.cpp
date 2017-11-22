//
// Created by Samuel Moseley on 11/21/17.
//

#include "BigInt.h"

void shift_left(u_char * dest, const u_char * number, int n) {
    for (int i = sizeof(number); i>=0; i--) {
        dest[i] = number[i] << n;
        if ((i - 1 - n/CHAR_BIT_SIZE) >= 0) {
            dest[i] = ((number[i - 1 - n/CHAR_BIT_SIZE] >> (CHAR_BIT_SIZE - (n % CHAR_BIT_SIZE))) << (n % CHAR_BIT_SIZE));
        }
    }
}

void add(u_char* a, u_char b) {
    int i = 0;
    bool cont = true;
    while (cont) {
        a[i] = a[i] + b;
        cont = a[i] < b;
        b = 1;
    }
}


BigInt* BigInt::operator*(BigInt *other) {
    BigInt ret();


}