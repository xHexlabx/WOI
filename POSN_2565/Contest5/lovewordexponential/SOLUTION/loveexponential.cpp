#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7 ;

vector<vector<long long>> mul (vector<vector<long long>>a , vector<vector<long long>>b){

    int i_size = a.size();
    int j_size = a[0].size() ;
    int k_size = b[0].size() ;

    vector<vector<long long>>temp(i_size , vector<long long>(k_size , 0)) ;

    for(int i = 0 ; i < i_size ; i++){
        for(int j = 0 ; j < j_size ; j++){
            for(int k = 0 ; k < k_size ; k++){
                temp[i][k] += a[i][j] * b[j][k] ;
                temp[i][k] %= mod ;
            }
        }
    }

    return temp ;
}

vector<vector<long long>>power[64] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    vector<vector<long long>>mat = { {1 , 1} , {1 , 0} } ;
    vector<vector<long long>>identity = {{1 , 0} , {0  ,1} } ;

    power[0] = identity ;
    power[1] = mat ;
    
    for(int i = 2 ; i < 64 ; i ++ ){
        power[i] = mul(power[i - 1] , power[i - 1]) ;
    }

    long long n ; cin >> n ; 
    
    if(n == 1 || n == 2){
        vector<vector<long long>>ans = {{1} , {1}} ;
        cout << ans[0][0] ;
        return 0 ;
    }

    n -- ;
    
    int cnt = 1 ;

    while(n){
        if(n & 1){
            identity = mul(identity , power[cnt]) ;
        }
        n >>= 1 ; 
        cnt ++ ;
    }

    vector<vector<long long>>ans = mul(identity , { {1} , {1} }) ;

    cout << ans[1][0] ;

    return 0 ;
}
