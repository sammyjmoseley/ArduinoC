//
// Created by Samuel Moseley on 11/21/17.
//

#ifndef ARDUINOC_BIGINT_H
#define ARDUINOC_BIGINT_H

typedef unsigned char u_char;

class BigInt {
public:
    BigInt* operator * (BigInt* other);
private:
    u_char num[];
};


#endif //ARDUINOC_BIGINT_H
