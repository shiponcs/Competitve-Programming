#include <bits/stdc++.h>
using namespace std;
char s[10];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

struct node{
    int r, c, path;
}nn, tt;

bool vis[10][10];

int bfs()
{
    if(s[0] == s[3] && s[1] == s[4]) return 0;
    memset(vis, false, sizeof(vis));
    queue <node> Q;
    tt.r = s[0] - 'a' + 1, tt.c = s[1] - '0', tt.path = 0;;
    Q.push(tt);
    vis[tt.r][tt.c] = true;
    while(!Q.empty()){
        tt = Q.front();
        Q.pop();

        for(int i = 0; i < 8; i++){
            int tx = tt.r + dx[i];
            int ty = tt.c + dy[i];
            if(tx > 0 && ty > 0 && tx <= 8 && ty <= 8 && !vis[tx][ty]){
                vis[tx][ty] = true;
                if( tx == s[3] - 'a' + 1 && ty == s[4] - '0' ) return (tt.path + 1);
                nn.r = tx, nn.c = ty, nn.path = tt.path + 1;
                Q.push(nn);
            }
        }
    }
}

int main()
{
    while(gets(s)){
        printf("To get from %c%c to %c%c takes %d knight moves.\n", s[0], s[1], s[3], s[4], bfs());
    }
    return 0;
}
