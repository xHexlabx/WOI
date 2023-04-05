#include<bits/stdc++.h>

using namespace std ;

long long line [1000002] ;
long long q , n , s , p , MAX = INT_MIN , cnt = 0 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> q ; 

    while(q -- ){
        cin >> s >> p >> n ;
        line[s] += n ;
        line[p + 1] -= n ;
    }

    for(int i = 1 ; i < 1000002 ; i ++ ){
        line[i] += line[i - 1] ;
        MAX = max(MAX , line[i]) ;
    }

    for(int i = 1 ; i <= 1000000 ; i ++ ){
        if(line[i] == MAX)cnt ++ ;
    }

    cout << MAX << ' ' << cnt ;

    return 0 ;
}