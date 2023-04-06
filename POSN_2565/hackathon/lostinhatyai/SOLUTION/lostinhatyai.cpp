#include<bits/stdc++.h>

using namespace std;

struct coor {
    int x , y ;
};

string graph [1001] , s ;
int arr[1001][1001] , m , n , quest , cnt = 0 ;
bool visited[1001][10001] ;
queue<coor>q ;

int dir[4] = {0 , 0 , - 1,  1} ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;


    cin >> m >> n >> quest ;

    for(int i = 1 ;  i <= m ; i ++ ){
        cin >> s ;
        graph[i] = "#" + s ;
    }

    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            if(graph[i][j] == '#' || visited[i][j])continue;
            cnt ++ ;
            visited[i][j] = true ;
            arr[i][j] = cnt ;
            q.push({i , j}) ;
            
            while(!q.empty()){

                auto temp = q.front() ;
                q.pop() ;
                int x = temp.x , y = temp.y ;

                for(int k = 0 ; k < 4 ; k ++ ){

                        int nowx = x + dir[k] , nowy = y + dir[3 - k] ;
                        if(nowx < 1 || nowx > m || nowy < 1 || nowy > n)continue ;
                        if(visited[nowx][nowy] || graph[nowx][nowy] == '#')continue ;
                        arr[nowx][nowy] = cnt ;
                        visited[nowx][nowy] = true ;
                        q.push({nowx , nowy}) ;
                    
                }

            }
        }
    }
    
    while(quest -- ){
        coor a , b ;
        cin >> a.x >> a.y >> b.x >> b.y ; 
        if(arr[a.x][a.y] == arr[b.x][b.y] && arr[a.x][a.y] != 0 && arr[b.x][b.y] != 0){
            cout << "YES\n" ;
        }
        else {
            cout << "NO\n" ;
        }
    }

    return 0 ;
}