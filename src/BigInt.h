//
// Created by Samuel Moseley on 11/21/17.
//

#ifndef ARDUINOC_BIGINT_H
#define ARDUINOC_BIGINT_H

#ifndef INT_SIZE
#define INT_SIZE sizeof(int)
#endif

#ifndef CHAR_BIT_SIZE
#define CHAR_BIT_SIZE 8
#endif

typedef unsigned char U_CHAR;

class BigInt {
public:
    BigInt(char c);
    BigInt* operator * (BigInt* other);
    BigInt* operator % (BigInt* other);
    bool operator > (BigInt* other);
    bool operator == (BigInt* other);
    bool operator < (BigInt* other);
    bool operator >= (BigInt* other);
    bool operator <= (BigInt* other);
private:
    U_CHAR num[];
};

class BigInt;


#endif //ARDUINOC_BIGINT_H
