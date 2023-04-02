#include<bits/stdc++.h>

using namespace std ;

struct coor {
    int x , y  ;
} ;

const long long mod = 1e9 + 7 ;
long long dp[1001][1001] ;

coor warp[1001][1001] ;
bool is_warp[1001][1001] ;

int n , m , k , sx , sy , dx  ,dy ;

int main(){


    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n >> k ;


    for(int i = 0 ; i < k ; i ++ ){
        cin >> sx >> sy >> dx >> dy ;
        warp[dx][dy] = {sx , sy} ;
        is_warp[dx][dy] = true ;
    }

    dp[1][1] = 1 ;

    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] ;
            dp[i][j] %= mod ;
            if(is_warp[i][j]){
                dp[i][j] += dp[warp[i][j].x][warp[i][j].y] ;
            }
            dp[i][j] %= mod  ;
        }
    }

    cout << dp[m][n] ;

    return 0 ;
}