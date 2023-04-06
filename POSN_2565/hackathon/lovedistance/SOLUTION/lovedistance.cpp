#include<bits/stdc++.h>

using namespace std ;

struct edge {
    int node ;
    long long weight ;
};

struct state {
    int node ;
    long long weight ;
    bool operator < (const state & rhs) const {
        return rhs.weight < weight ;
    }
};

int dest1 , dest2 , n , m , x , y ;
long long w ;
long long dis[2][20001] ;

vector<edge>adj[20001] ;

void sssp(int src , int round){

    priority_queue<state>pq ;

    dis[round][src] = 0 ;
    pq.push({src , 0}) ;

    while(!pq.empty()){

        auto temp = pq.top() ;
        pq.pop() ;

        int prev = temp.node ;
        int weight = temp.weight ;

        for(auto i : adj[prev]){

            int current = i.node ;
            long long current_weight = weight + i.weight ;

            if(current_weight < dis[round][current]){
                dis[round][current] = current_weight ;
                pq.push({current , current_weight}) ;
            }
        }

    }
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m >> dest1 >> dest2 ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y >> w ;
        adj[x].push_back({y , w}) ;
        adj[y].push_back({x , w}) ;
    }

    for(int i = 1 ; i <= 20000 ; i ++ ){
        dis[0][i] = LLONG_MAX ;
        dis[1][i] = LLONG_MAX ;
    }

    sssp(dest1 , 0) ;
    sssp(dest2 , 1) ;

    for(int i = 1 ; i <= n ; i ++ ){
        cout << dis[0][i] << ' ' << dis[1][i] << '\n' ; 
    }

    return 0 ;
}