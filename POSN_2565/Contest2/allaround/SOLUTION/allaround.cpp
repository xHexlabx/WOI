#include<bits/stdc++.h>

using namespace std;

int MAX = INT_MIN , n , arr[21][21] ;
bool visited[21] ;

void solve(int count , int total){

    if(count == n + 1){
        MAX = max(MAX , total) ;
    }
    else {

        for(int i = 1 ; i <= n ; i ++ ){
            if(!visited[i]){
                visited[i] = true ;
                solve(count + 1 , arr[i][count] + total) ;
                visited[i] = false ;
            }
        }
    }
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> arr[i][j] ;
        }
    }

    solve(1 , 0) ;

    cout << MAX ;

    return 0 ;
}