#include<bits/stdc++.h>

using namespace std ;

struct node {
    long long x , y ;
    
    bool operator < (const node & rhs)const {
        if(x != rhs.x)return x < rhs.x ;
        else return y < rhs.y ;
    }

};

long long cal(node a , node b){
    return abs(a.x - b.x) + abs(a.y - b.y) ;
}

long long n , t , k ;

node towers[100001] ;

long long closest(int l ,  int r){

    if(l == r)return LLONG_MAX ;
    if(r - l == 1)return cal(towers[l] , towers[r]) ;

    long long mid = (l + r) >> 1 ;
    long long dis = min(closest(l , mid) , closest(mid + 1 , r)) ;

    long long ll = max((long long)0 , mid - 8) , rr = min(n - 1 , mid + 8);

    for(int i = ll ; i <= rr ; i ++ ){
        if(i == mid)continue ;
        dis = min(dis , cal(towers[i] , towers[mid])) ;
    }

    return dis ;

}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> t >> k ;

    for(int i = 0 ; i < n  ; i ++ ){
        cin >> towers[i].x >> towers[i].y ;
    }

    sort(towers , towers + n) ;

    long long dis = closest(0 , n - 1) ;

    cout << dis << '\n' ;

    if ( dis * t > k ){
        cout << "NO TIME = "<< dis * t ;
    } 
    else {
        cout << "YES TIME = "<< dis * t ;
    }

    return 0 ;
}