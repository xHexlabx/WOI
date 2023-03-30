#include<bits/stdc++.h>

using namespace std ;

long long n ;// <= 10^16;

int m ; // <= 100000

long long idx[100001] ;// ascending order ;

vector<pair<long long  , long long>>vec ;

int main(){


    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 1 ; i <= m ; i++){
        cin >> idx[i] ;
    }

    long long l = 0 , r = 1e16 + 1 ;


    while(l < r){

        vec.clear() ;
        long long mid = (l + r) >> 1 ;

        vec.push_back({0 , 0}) ;
        for(int i = 1 ; i <= m ; i ++ ){
            vec.push_back({idx[i] - mid , idx[i] + mid}) ;
        }
        vec.push_back({n + 1 , n + 1}) ;

        bool can = true ;

        for(int i = 1 ; i <= m + 1 ; i ++ ){
            if(! (vec[i - 1].second + 1 >= vec[i].first) ){
                can = false ;
            }
        }

        if(can){
            r = mid ;
        }
        else {
            l = mid + 1 ;
        }
    }
    
    cout << l ;

    return 0 ;
}