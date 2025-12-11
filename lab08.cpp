#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned, int = 1);
unsigned fib(unsigned, int = 0, int = 1);
unsigned mult(unsigned, unsigned, int = 0);
unsigned power(unsigned, unsigned, int = 1);
unsigned product(unsigned, unsigned, int = 1);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned fact(unsigned n, int product) {
    // base cases (combined)
    if (n <= 1) {
        //return 1;
        return product;
    }

    // recursive case
    //unsigned res = fact(n - 1);
    //return res * n;
    return fact(n - 1, product * n);
}

unsigned fib(unsigned n, int a, int b) {
    // base case 1
    if (n == 0) {
        //return 0;
        return a;
    }

    // base case 2
    else if (n == 1) {
        //return 1;
        return b;
    }

    // recursive case
    //return fib(n - 1) + fib(n - 2);
    return fib(n-1, b, a+b);
}

unsigned mult(unsigned x, unsigned y, int product) {
    // base case
    if (y == 0) {
        //return 0;
        return product;
    }

    // recursive case
    //unsigned res = mult(x, y - 1);
    //return res + x;
    return mult(x, y - 1, product + x);
}

unsigned power(unsigned x, unsigned y, int product) {
    // base case
    if (y == 0) {
        //return 1;
        return product;
    }

    // recursive case
    //unsigned res = power(x, y - 1);
    //return res * x;
    return power (x, y -1, product *x);
}

unsigned product(unsigned x, unsigned y, int producte) {
    // base case
    if (x == y) {
        //return x;
        return producte;
    }

    // recursive case
    //unsigned p = product(x + 1, y);
    //return p * x;
    return product(x, y-1, producte*y);
}
