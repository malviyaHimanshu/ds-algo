// Sieve of Eratosthenes
// Print all the Prime numbers till n

#include<iostream>
#include<math.h>
#pragma GCC optimise("Ofast")
using namespace std;

/*
    find all the prime number till 50
        - Traverse through all the number
            if it is divisible by prime number then mark it
        - finally print all the Unmarked Numbers

        2   3   4   5   6   7   8   9   10
    11  12  13  14  15  16  17  18  19  20
    21  22  23  24  25  26  27  28  29  30
    31  32  33  34  35  36  37  38  39  40
    41  42  43  44  45  46  47  48  49  50

    - take 2 (unmarked), start from 2 square i.e. 4
        4 is divisible by 2 -> mark it
        6 is divisible by 2 -> mark it
        .
        .

    - next take 3 (unmarked), start from 3 square i.e. 9
        9 divisible by 3 -> mark it
        12 divisible by 3 -> mark it
        .
        .

    - similarly do for all and print all the unmarked numbers (prime numbers)
*/

void primeSieve(int n) {
    bool prime[100] = {false};
    for(int i=2; i<=n; i++) {
        // if the number is not marked already
        if(!prime[i]) {
            // start from i square and mark all with i steps
            // s.t. they are divisible by i
            for(int j=i*i; j<=n; j+=i) {
                prime[j] = true;
            }
        }
    }
    
    // print all the unmarked
    for(int i=2; i<=n; i++) {
        if(!prime[i]) {
            cout<<i<<" ";
        }
    }cout<<endl;
}

int main() {
    int n; cin>>n;
    primeSieve(n);

    return 0;
}