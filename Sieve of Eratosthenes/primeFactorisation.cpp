// Prime Factorisation using the Smallest prime factor

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

void primeFactor(int n) {
    int spf[100] = {0};
    for(int i=2; i<=n; i++) {
        spf[i] = i;
    }

    for(int i=2; i<=n; i++) {
        if(spf[i] == i) {
            for(int j=i*i; j<=n; j+=i) {
                if(spf[j]==j) {
                    spf[j] = i;
                }
            }
        }
    }

    while(n!=1) {
        cout<<spf[n]<<" ";
        n /= spf[n];
    }cout<<endl;
}

int main() {
    int n; cin>>n;
    primeFactor(n);

    return 0;
}