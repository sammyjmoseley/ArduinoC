//
// Created by Samuel Moseley on 11/21/17.
//

#include <BigInt.h>
#include <USBAPI.h>

BigInt::BigInt(char c) {
    this->num[0] = c;
}

void shift_left(U_CHAR * dest, const U_CHAR * number, int n) {
    for (int i = sizeof(number); i>=0; i--) {
        dest[i] = number[i] << n;
        if ((i - 1 - n/CHAR_BIT_SIZE) >= 0) {
            dest[i] = ((number[i - 1 - n/CHAR_BIT_SIZE] >> (CHAR_BIT_SIZE - (n % CHAR_BIT_SIZE))) << (n % CHAR_BIT_SIZE));
        }
    }
}

void add(U_CHAR* a, U_CHAR b) {
    int i = 0;
    bool cont = true;
    while (cont) {
        a[i] = a[i] + b;
        cont = a[i] < b;
        b = 1;
    }
}


BigInt* BigInt::operator*(BigInt *other) {
    BigInt* ret = new BigInt(0);

    for (int i = 0; i < sizeof(this->num[0]); i++) {
        for (int j = 0; j < sizeof(other->num[0]); j++) {
            int m = ((int) this->num[i])*((int) other->num[j]);
            ret->num[i+j] += (char)m;
            for (int k = 8; k < INT_SIZE; k+=8) {
                ret->num[i+j+k/8] += (char)(m<<8);
            }
        }
    }

    return ret;
}

void subtraction_helper(BigInt* subtractand, BigInt* subtractor) {

}

BigInt* BigInt::operator%(BigInt *other) {

}

bool BigInt::operator>(BigInt *other) {
    int a_sz = sizeof(this->num[0]);
    int b_sz = sizeof(other->num[0]);

    for (int i = max(a_sz, b_sz) - 1; i >= 0; i--) {
        char a = i < a_sz ? this->num[i] : 0c;
        char b = i < b_sz ? other->num[i] : 0c;

        if (a > b) {
            return true;
        } else if (b < a) {
            return true;
        }
    }

    return false;
}

bool BigInt::operator==(BigInt *other) {
    int a_sz = sizeof(this->num[0]);
    int b_sz = sizeof(other->num[0]);

    for (int i = max(a_sz, b_sz) - 1; i >= 0; i--) {
        char a = i < a_sz ? this->num[i] : 0c;
        char b = i < b_sz ? other->num[i] : 0c;

        if (a != b) {
            return false;
        }
    }

    return true;
}

bool BigInt::operator>=(BigInt *other) {
    return this > other || this == other;
}

bool BigInt::operator<=(BigInt *other) {
    return !(this > other);
}

bool BigInt::operator<(BigInt *other) {
    return !(this >= other);
}