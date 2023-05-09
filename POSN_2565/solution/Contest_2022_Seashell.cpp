#include<bits/stdc++.h>

using namespace std;

struct seashell {
    long long idx , val ;
};

struct query {
    long long l , r ;
};

const int N = 3 * 1e4 + 1;
int n , q ;
long long l , r ;

vector<long long>v ;
vector<seashell>seashells ;
vector<query> queries;

void coordinate_compress () {
    sort(v.begin(), v.end()) ;
    v.erase( unique (v.begin() , v.end()) , v.end() ) ;
}

int get_idx (long long val) {
    return lower_bound(v.begin() , v.end() , val) - v.begin() ;
}

int qs[N] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        long long idx , val ; cin >> idx >> val; 
        v.push_back(idx) ;
        seashells.push_back({idx , val}) ;
    }

    for(int i = 1 ; i <= q ; i ++ ){
        cin >> l >> r ;
        v.push_back(l) ;
        v.push_back(r) ;
        queries.push_back({l , r}) ;
    }

    v.push_back(LLONG_MIN) ;
    v.push_back(LLONG_MAX) ;

    coordinate_compress() ;

    for(auto i : seashells){
        long long idx = get_idx(i.idx) ;
        long long val = i.val ;
        qs[idx] += val;
    }

    for(int i = 1 ; i < N ; i ++ ){
        qs[i] += qs[i - 1];
    }

    for(auto i : queries){
        
        int l = get_idx(i.l) ;
        int r = get_idx(i.r) ;

        cout << qs[r] - qs[l - 1] << '\n' ;

    }

    return 0 ;

}