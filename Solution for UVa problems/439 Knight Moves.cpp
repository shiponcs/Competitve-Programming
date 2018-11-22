#include <bits/stdc++.h>
using namespace std;
#define r first
#define c second
char s[10];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//struct node{
//    int r, c, path;
//}dest, tt;

bool vis[10][10];

int bfs()
{
    if(s[0] == s[3] && s[1] == s[4]) return 0;
    memset(vis, false, sizeof(vis));
    queue < pair < int, int > > Q;
    int path[10][10];
    pair < int, int > tt, dest;
    tt.r = s[0] - 'a' + 1, tt.c = s[1] - '0', path[tt.r][tt.c] = 0;

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
                if( tx == s[3] - 'a' + 1 && ty == (s[4] - '0') )  return ( path[tt.r][tt.c] + 1);
                path[tx][ty] = path[tt.r][tt.c] + 1;
                Q.push(make_pair(tx, ty));
            }
        }
    }
}

int main()
{
    while(gets(s)){
        printf("To get from %c%c to %c%c takes %d knight moves.\n", s[0], s[1], s[3], s[4], bfs());
       // printf("%s\n", s);
    }
    return 0;
}

