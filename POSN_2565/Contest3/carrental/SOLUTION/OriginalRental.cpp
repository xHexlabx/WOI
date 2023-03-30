#include<bits/stdc++.h>
#define ll long long int
#define d double

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	ll cost = 0,N,M,T;
	cin >> T;
	cin >> N;
	while(N > 0){
		while( N > 8){
			cost += 300;
			N -= 15;
		}
		while(N > 3){
			cost += 150;
			N -= 5;
		}
		while(N > 1){
			cost += 80;
			N -= 2;
		}
		while(N > 0){
			cost += 50;
			N--;
		}
	}
	for(int i = 0 ; i < T ; i++){
        cin >> M;
        if(cost <= M) cout << M-cost << "\n";
        else cout << -1 << "\n";

	}


/*
    1       120
    2       170
    5       380
    10      750
    24      1500


*/
}
