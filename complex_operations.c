#include <stdio.h>
#include <math.h>

typedef struct complex_num_struct {
    double real;
    double imag;
} complex_num;

complex_num add(complex_num num1, complex_num num2);
complex_num subtract(complex_num num1, complex_num num2);
complex_num multiply(complex_num num1, complex_num num2);
complex_num divide(complex_num num1, complex_num num2);
complex_num power(complex_num num, double n);

void main() {
    complex_num num1, num2;
    double n;
    printf("\nEnter the real part of number 1:- ");
    scanf("%lf", &num1.real);
    printf("\nEnter the imaginary part of number 1 :- ");
    scanf("%lf", &num1.imag);
    printf("\nEnter the real part of number 2:- ");
    scanf("%lf", &num2.real);
    printf("\nEnter the imaginary part of number 2:- ");
    scanf("%lf", &num2.imag);
    printf("\nEnter the value of power to raise num1 to:- ");
    scanf("%lf", &n);
    printf("\nnum 1:- %f + j(%f)", num1.real, num1.imag);
    printf("\nnum 2:- %f + j(%f)", num2.real, num2.imag);
    
    complex_num addition = add(num1, num2);
    complex_num subtraction = subtract(num1, num2);
    complex_num multiplication = multiply(num1, num2);
    complex_num division = divide(num1, num2);
    complex_num pow = power(num1, n);
    
    printf("\nThe addition is:- %f + i(%f)", addition.real, addition.imag);
    printf("\nThe subtraction is:- %f + i(%f)", subtraction.real, subtraction.imag);
    printf("\nThe multiplication is:- %f + i(%f)", multiplication.real, multiplication.imag);
    printf("\nThe division is:- %f + i(%f)", division.real, division.imag);
    printf("\nThe power is:- %f + i(%f)", pow.real, pow.imag);
}

complex_num add(complex_num num1, complex_num num2) {
    complex_num result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    
    return result;
}

complex_num subtract(complex_num num1, complex_num num2) {
    complex_num result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    
    return result;
}

complex_num multiply(complex_num num1, complex_num num2) {
    complex_num result;
    result.real = num1.real * num2.real - num1.imag * num2.imag;
    result.imag = num1.real * num2.imag + num1.imag * num2.real;
    
    return result;
}

complex_num divide(complex_num num1, complex_num num2) {
    complex_num result;
    
    double magnitude_square = pow(num2.real, 2) + pow(num2.imag, 2);
    num2.imag = -num2.imag;
    
    result = multiply(num1, num2);
    result.real = result.real / magnitude_square;
    result.imag = result.imag / magnitude_square;
    
    return result;
}

complex_num power(complex_num num, double n) {
    complex_num result;
    
    double magnitude = sqrt(pow(num.real, 2) + pow(num.imag, 2));
    
    result.real = pow(magnitude, n) * cos(n * atan(num.imag / num.real));
    result.imag = pow(magnitude, n) * sin(n * atan(num.imag / num.real));
    
    return result;
}
