#include <bits/stdc++.h>
using namespace std;

int n, x, y;
queue<int> q[100007];

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        if(x==1) {
            scanf("%d%d", &x, &y);
            q[y].push(x);
        } else if(x==2) {
            scanf("%d", &y);
            if(!q[y].empty()) {
                q[y].pop();
            }
        } else if(x==3) {
            scanf("%d", &y);
            if(!q[y].empty()) {
                printf("%d\n", q[y].front());
            } else {
                printf("-1\n");
            }
        } else {
            scanf("%d", &y);
            printf("%d\n", q[y].size());
        }
    }
    return 0;
}