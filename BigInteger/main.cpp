#include <string>
#include <iostream>
#include "biginteger.h"

int main() {
    BigInteger a = "3141592653589793238462643383279502884197169399375105820974944592";
    BigInteger b = "2718281828459045235360287471352662497757247093699959574966967627";
    std::cout << a + b << std::endl;
    std::cout << a * b << std::endl;
    return 0;
}
