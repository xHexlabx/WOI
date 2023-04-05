#include<bits/stdc++.h>

using namespace std;

struct coor {
    long long x , y ;
};

long long m , n , w  , q ;

coor warp[501] ;

long long dp[501][501] ;

long long cal(coor src , coor dest){
    return abs(src.x - dest.x) + abs(src.y - dest.y) ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> w >> q ;

    for(int i = 0 ; i < w ; i ++ ){
        cin >> warp[i * 2].x >> warp[i * 2].y ;
        cin >> warp[i * 2 + 1].x >> warp[i * 2 + 1].y ;
    }

    for(int i = 0 ; i < 2 * w ; i ++ ){
        for(int j = 0 ; j < 2 * w ; j ++ ){
            dp[i][j] = INT_MAX ;
            if(i == j)dp[i][j] = 0 ;
        }
    }

    for(int i = 0 ; i < 2 * w ; i ++ ){
        dp[i * 2][i * 2 + 1] = 0 ;
        dp[i * 2 + 1][i * 2] = 0 ;
    }

    for(int i = 0 ; i < 2 * w ; i ++){
        for(int j = 0 ; j < 2 * w ; j ++){
            dp[i][j] = min(dp[i][j] , cal(warp[i] , warp[j]));
        }
    }

    for(int k = 0 ; k < 2 * w ; k ++ ){
        for(int i = 0 ; i < 2 * w ; i ++ ){
            for(int j = 0 ; j < 2 * w ; j ++ ){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]) ;
            }
        }
    }

    
    while(q -- ){

        coor src , dest ;

        cin >> src.x >> src.y >> dest.x >> dest.y ;

        long long dis = cal(src , dest) ;

        for(int i = 0 ; i < 2 * w ; i ++ ){
            for(int j = 0 ; j < 2 * w ; j ++ ){
                if(i == j) continue ;
                dis = min(dis , cal(src , warp[i]) + dp[i][j] + cal(warp[j] , dest)) ;
            }
        }

        cout << dis << '\n' ;

    }
    
    return 0 ;
}