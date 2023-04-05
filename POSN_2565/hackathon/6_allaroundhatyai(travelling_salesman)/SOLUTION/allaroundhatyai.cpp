#include<bits/stdc++.h>

using namespace std ;

bool visited[21] ;
int MAX = 0 , n , arr[21][21];

void solve(int current , int sum , int cnt ) {
    if(current == n){
        MAX = max(MAX , sum) ;
        return ;
    }
    else {
        for(int i = 1 ; i <= n ; i ++ ){
            if(!visited[i]){
                visited[i] = true ;
                solve(i , sum + arr[i][cnt + 1] , cnt + 1) ;
                visited[i] = false ;
            }
        }
    }
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ;  i++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> arr[i][j] ;
        }
    }

    visited[0] = true ;
    solve(0 , 0 , 0) ;

    cout << MAX ;
    
    return 0 ;
}