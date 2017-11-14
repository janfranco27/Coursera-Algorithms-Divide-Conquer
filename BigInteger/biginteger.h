#ifndef biginteger_H
#define biginteger_H

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

class BigInteger {
public:
    BigInteger(const char* value="0");
    BigInteger& operator+=(const BigInteger& rhs);
    BigInteger& operator*=(const BigInteger& rhs);
    
    friend bool operator==(const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator!=(const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator< (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator<=(const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator> (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator>=(const BigInteger& lhs, const BigInteger& rhs);
    
    friend BigInteger operator+(BigInteger lhs, const BigInteger& rhs);
    friend BigInteger operator*(BigInteger lhs, const BigInteger& rhs);
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& dt);  
    
private:
    std::vector<int> digits;
    void manageCarry();
};

#endif
