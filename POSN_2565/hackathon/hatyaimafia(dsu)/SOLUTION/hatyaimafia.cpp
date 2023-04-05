#include<bits/stdc++.h>

using namespace std;

int pa[200001] , group[200001] , x , y , rootx , rooty ;

int fp(int x){
    if(pa[x] == x)return x ;
    return pa[x] = fp(pa[x]) ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    int n , q ;

    cin >> n >> q ;
    
    for(int i = 1 ; i <= n ; i ++ ){
        pa[i] = i ;
        group[i] = 1 ;
    }
    
    while(q -- ){
        cin >> x >> y ;
        rootx = fp(x) ;
        rooty = fp(y) ;
        group[rootx] += group[rooty] ;
        group[rooty] = 0 ;
        pa[rooty] = rootx ;
    }

    sort(group , group + 200000 , greater<int>()) ;

    for(int i = 0 ; i < n ; i ++ ){
        if(group[i] > 0){
            cout << group[i] << ' ';
        }
        else {
            break ;
        }
    }

    return 0 ;
}