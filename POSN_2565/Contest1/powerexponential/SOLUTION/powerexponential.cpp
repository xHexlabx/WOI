#include<bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7 ;

long long power(long long n , long long k){

    long long res = 1 ;
    long long total = n ;

    while(k){
        if(k & 1){
            res *= total ;
            res %= mod ;
        }
        k >>= 1 ;
        total *= total ;
        total %= mod ;
    }

    return res ;
}

int n ;

long long res = 0 , a , p ; 

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);
    
    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> a >> p ;
        res += power(a , p) ;
        res %= mod ;
    }

    cout << res ;

    return 0 ;
}