#include<bits/stdc++.h>

using namespace std ;

long long p[51] ;
char word[5] = {' ' , 'L' , 'O' , 'V' , 'E'} ;
int q , n  ;
long long k ;

char solve(int n , long long k){

    if(n <= 4){
        return word[n] ;
    }

    else if(k <= p[n - 4]){
        return solve(n - 4 , k) ;
    }

    else if(k <= p[n - 4] + p[n - 3]){
        return solve(n - 3 , k - p[n - 4]) ;
    }

    else if(k <= p[n - 4] + p[n - 3] + p[n - 2]){
        return solve(n - 2 , k - p[n - 4] - p[n - 3]) ;
    }
    else return solve(n - 1 , k - p[n - 4] - p[n - 3] - p[n - 2] ) ;
}

int main(){


    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> q ;

    p[1] = 1 ;
    p[2] = 1 ;
    p[3] = 1 ;
    p[4] = 1 ;
    
    for(int i = 5 ; i  <= 50 ; i ++ ){
        p[i] = p[i - 4] + p[i - 3] + p[i - 2] + p[i - 1] ;
    }

    while(q -- ){
        cin >> n >> k ;
        cout << solve(n , k) << '\n' ;
    }

    return 0 ;
}