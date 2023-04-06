#include<bits/stdc++.h>

using namespace std;

struct coor {
    long long x , y ;
};

long long cal(coor a , coor b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

coor towers[10001] ;

long long dis[10001] ;

bool visited[10001] ;

long long ans = 0 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    for(int i = 1 ; i <= 10000 ; i ++ ){
        dis[i] = INT_MAX  ;
    }

    int n ; cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> towers[i].x >> towers[i].y ;
    }

    int now , idx , MIN ;

    visited[1] = true ;
    dis[1] = 0 ;
    now = 1 ;

    for(int i = 2 ; i <= n ; i ++ ){
        MIN = INT_MAX ;
        for(int j = 1 ; j <= n ; j ++ ){

            if(visited[j])continue ;

            dis[j] = min(dis[j] , cal(towers[now] , towers[j])) ;

            if(dis[j] < MIN){
                MIN = dis[j] ;
                idx = j ;
            }
        }

        visited[idx] = true ;
        ans += MIN ;
        now = idx ;

    }

    cout << ans ;
    
    return 0 ;
}