#include<bits/stdc++.h>

using namespace std;

bool visited[21] ;
int arr[21][21] , n ;
int res = 0 , MAX = 0 , idx ;

int main(){

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> arr[i][j] ;
        }
    }

    for(int j = 1 ; j <= n ; j ++ ){
        MAX = 0 ;
        for(int i = 1 ; i <= n ; i ++ ){
            if(!visited[i] && arr[i][j] > MAX){
                MAX = arr[i][j] ;
                idx = i ;
            }
        }
        visited[idx] = true ;
        res += MAX ;
    }

    cout << res ;
    return 0 ;
}