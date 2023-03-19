#include<bits/stdc++.h>

using namespace std;

int n , k , i = 0 , j = 0 , ans = 0 ;
int a[100001] , b[100001] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n >> k ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> a[i] ;
    }
    for(int i = 0 ; i < n ; i ++ ){
        cin >> b[i] ;
    }

    sort(a , a + n , greater<int>()) ;
    sort(b , b + n) ;

    while(i < n && j < n){

        if(a[i] + b[j] > k){
            ans ++ ;
            i ++ ;
            j ++ ;
        }
        else {
            j ++ ;
        }
    }

    cout << ans ;
    
    return 0 ;
}