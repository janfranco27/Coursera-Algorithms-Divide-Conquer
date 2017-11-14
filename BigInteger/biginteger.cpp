#include "biginteger.h"

BigInteger::BigInteger(const char* value) {
    int i = 0;
    while(value[i] != '\0') {
        digits.insert(digits.begin(), value[i++] - '0');
    }
}

BigInteger& BigInteger::operator+=(const BigInteger& rhs) {
    for(int i = 0; i < rhs.digits.size(); i++) {
        if(this->digits.size() <= i)
            this->digits.push_back(0);
        this->digits[i] += rhs.digits[i];
    }
    manageCarry();
    return *this;
}

BigInteger operator+(BigInteger lhs, const BigInteger& rhs) {
    lhs += rhs;
    return lhs;
}


BigInteger& BigInteger::operator*=(const BigInteger& rhs) {
    std::vector<int> result(1, 0);
    for(int i = 0; i < rhs.digits.size(); i++) {
        for(int j = 0; j < this->digits.size(); j++) {
            if(result.size() <= i+j)
                result.push_back(0);

            result[i+j] += rhs.digits[i] * this->digits[j];
        }
    }
    this->digits = result;
    manageCarry();
    return *this;
}

BigInteger operator*(BigInteger lhs, const BigInteger& rhs) {
    lhs *= rhs;
    return lhs;
}

void BigInteger::manageCarry() {
    for(int i = 0; i < this->digits.size(); i++) {
        int carry = this->digits[i] / 10;
        this->digits[i] = this->digits[i] % 10;
        if (carry) {
            if (this->digits.size() != i+1)
                this->digits[i+1] += carry;
            else
                this->digits.push_back(carry);
        }
    }            
}

std::ostream& operator<<(std::ostream& os, const BigInteger& number) {
    for(int i=number.digits.size()-1; i >= 0; i--)
        os << number.digits[i];
    return os;
}

bool operator==(const BigInteger& lhs, const BigInteger& rhs) {
    if(lhs.digits.size() != rhs.digits.size()) return false;
    for(int i = 0; i < lhs.digits.size(); i++) {
        if(lhs.digits[i] != rhs.digits[i]) return false;
    }
    return true;
}

bool operator< (const BigInteger& lhs, const BigInteger& rhs) {
    if(lhs.digits.size() > rhs.digits.size()) return false;
    if(lhs.digits.size() < rhs.digits.size()) return true;
    for(int i=lhs.digits.size() - 1; i >= 0; i--) {
        if(lhs.digits[i] > rhs.digits[i]) return false;
        if(lhs.digits[i] < rhs.digits[i]) return true;
    }
    return true;
}

bool operator!=(const BigInteger& lhs, const BigInteger& rhs){return !operator==(lhs,rhs);}
bool operator> (const BigInteger& lhs, const BigInteger& rhs){return  operator< (rhs,lhs);}
bool operator<=(const BigInteger& lhs, const BigInteger& rhs){return !operator> (lhs,rhs);}
bool operator>=(const BigInteger& lhs, const BigInteger& rhs){return !operator< (lhs,rhs);}
