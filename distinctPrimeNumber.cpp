#include<bits/stdc++.h>
#define MAX 1e6
using namespace std;
using ll = long long;


vector<ll> isprime(MAX,1);
vector<ll> countpf(MAX,0);


void make_sv(){

    isprime[0] = 0;
    isprime[1] = 0;
    isprime[2] = 1;
    for(ll i=2; i<MAX; i++){
        if(isprime[i]){
            for(ll j=i+i; j<MAX; j+=i){
                isprime[j] = 0;
            }
        }
    }


    countpf[0] = 0;
    countpf[1] = 0;

    for(ll i=2; i <  MAX; i++){
        if(isprime[i]){
            countpf[i] = 1;
            for(ll j=i+i; j<MAX; j+=i){
                countpf[j]++;
            }
        }
    }

}


void print_sv(ll n){
    for(ll i=0; i<n; i++){
        cout << " Number i = "<< i <<", Prime = "<< isprime[i] << ", No. Factors = " << countpf[i] << "\n";
    }
}
