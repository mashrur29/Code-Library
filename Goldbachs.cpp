#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    long long i, lim=sqrt(n);

    if(n%2==0) return false;

    for(i=3; i<=lim; i+=2) {
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    long long n;
    cin>>n;

    if(n%2==0) {
        if(n==2) cout<<"1"<<endl;
        else cout<<"2"<<endl;
    } else if(isPrime(n)) cout<<"1"<<endl;
    else if(n&1) {
        if(isPrime(n-2)) cout<<"2"<<endl;
        else cout<<"3"<<endl;
    }

    return 0;
}

