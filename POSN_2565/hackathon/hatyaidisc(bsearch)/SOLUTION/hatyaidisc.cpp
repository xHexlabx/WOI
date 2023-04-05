#include<bits/stdc++.h>

using namespace std ;

long long discs[1000001] ;
long long n , q , l , r ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> discs[i] ;
    }
    
    while(q -- ){
        cin >> l >> r ;
        int idxl , idxr ;
        idxl = lower_bound(discs , discs + n , l) - discs ;
        idxr = upper_bound(discs , discs + n , r) - discs ;
        cout << idxr - idxl << '\n' ;
    }
    
    return 0 ;
}