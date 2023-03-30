#include<bits/stdc++.h>

using namespace std ;

int arr[100002], n , ans = 0 ;

class Fenwick {

    public : 

        int fw[100002] ;

        void update(int idx , int val){
            for(; idx <= 100000 ; idx += (idx & -idx)){
                fw[idx] += val ;
            }
        }

        int query(int idx){
            int res = 0 ;
            for(; idx > 0 ; idx -= (idx & -idx)){
                res += fw[idx] ;
            }
            return res ;
        }
}fw ;

int main(){


    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
        ans += fw.query(100001) - fw.query(arr[i]) ;
        fw.update(arr[i] , 1) ;
    }
    
    cout << ans ;
    
    return 0 ;
}