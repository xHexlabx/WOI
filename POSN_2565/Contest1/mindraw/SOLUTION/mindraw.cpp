#include<bits/stdc++.h>

using namespace std;

int n ;
long long x , sum = 0 ; 
priority_queue<long long , vector<long long> , greater<long long>>pq ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> x ;
        if(x == 0){
            if(!pq.empty()){
                sum += pq.top() ;
                pq.pop() ;
            }
        }
        else {
            pq.push(x) ;
        }
    }

    cout << sum ;
    
    return 0 ;
}