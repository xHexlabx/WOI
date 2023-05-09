#include<bits/stdc++.h>

using namespace std ;

struct coor {

    long long idx , val ;
    bool operator < (const coor & rhs)const { 
        return idx < rhs.idx ;
    }
};

vector<coor>vec ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    int n , q ;
    long long idx , val ;
    long long l , r ;

    cin >> n >> q ;
    while(n -- ){
        cin >> idx >> val ;
        vec.push_back({idx , val});
    }
    sort(vec.begin(), vec.end());

    while(q -- ){
        cin >> l >> r ; 
        long long res = 0 ;
        for(auto i : vec){
            if(l <= i.idx && i.idx <= r){
                res += i.val ;
            }
            if(i.idx > r)break ;
        }
        cout << res << '\n' ;
    }
    return 0 ;  
}