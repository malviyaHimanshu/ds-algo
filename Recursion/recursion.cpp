// Playing with recursion

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

int sum(int n) {
    if(n==0)
        return 0;
    return n + sum(n-1);
}

// calculate n^p
int power(int n, int p) {
    if(p==0)
        return 1;
    return n * power(n, p-1);
}

// calculate factorial of n
int factorial(int n) {
    if(n==0)
        return 1;
    return n * factorial(n-1);
}

// print nth fibonacci number
int fibonacci(int n) {
    if(n==1 || n==0)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    cout<<sum(4)<<endl;
    cout<<power(2, 10)<<endl;
    cout<<factorial(5)<<endl;
    cout<<fibonacci(5)<<endl;

    return 0;
}