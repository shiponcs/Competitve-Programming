#include <bits/stdc++.h>
using namespace std;
#define optimize              ios_base::sync_with_stdio(false)
#define FOR(i, a, n)          for(int i = a; i < n; i++)
#define from_0_till(x)          for(int i = 0; i < x; i++)
#define LL                    long long
#define ULL                   unsigned long long
#define YES()                 printf("YES\n")
#define NO()                  printf("NO\n")
#define NL()                  printf("\n")
#define PI                    acos(-1)
#define veci                  vector <int>
#define vecll                 vector < long long >
#define p_b                   push_back
#define e_b                   emplace_back   
#define pii                   pair < int, int >
#define pci                   pair <char, int >
#define psi                   pair <string, int>
#define m_p                   make_pair
#define max3(a, b, c)         max(a, max(b, c))
#define min3(a, b, c)         min(a, min(b, c))
#define valid(tx,ty)          (tx>=0&&tx<C&&ty>=0&&ty<R)
#define MX                    10000001
#define mod                   1e9 + 7
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%I64d",&a)
#define sf2ll(a,b)            scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pf1ll(a)              printf("%I64d\n",a);
#define pf2ll(a,b)            printf("%I64d %I64d\n",a,b)
#define pf3ll(a,b,c)          printf("%I64d %I64d %I64d\n",a,b,c)
#define STRTOLOWER(x)         std::transform (x.begin(), x.end(), x.begin(), ::tolower)
#define STRTOUPPER(x)         std::transform (x.begin(), x.end(), x.begin(), ::toupper)
#define STRTOUCFIRST(x)       std::transform (x.begin(), x.begin()+1, x.begin(),  ::toupper); std::transform (x.begin()+1, x.end(),   x.begin()+1,::tolower)
//int a[MX], b[MX], sol[MX];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
//int dx = {1, 1, 2, 2, -1, -1, -2, -2}
//int dy = {2, -2, 1, -1, 2, -2, 1, -1}
int t, tt, n, N, l, r, c, cnt, L, R, C, m, mn, q = 1e9 + 9, mx = 0, height, width;

bool check = false;
char grid[509][509];
int vis[509][509], ans[509][509];
void bfs(int x, int y)
{
	queue <pii> Q;
	Q.push({x, y});
	vis[x][y] = 1;
	if(grid[x][y] == 'C') cnt++;	
	while(!Q.empty()){
		pii u = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++){
			int sx = u.first + dx[i], sy = u.second + dy[i];
			if(sx < 0  || sy < 0 || sx >= n || sy >= m) continue;
			if(!vis[sx][sy] && grid[sx][sy] != '#'){
				if(grid[sx][sy] == 'C') cnt++;

				vis[sx][sy] = 1;
				Q.push({sx, sy});
			}
		} 
		
	}
}

int main()
{ 
    //freopen("input.txt", "r", stdin);
    sf1(t);
	while(t--){
		sf3(n, m, q);
		FOR(i, 0, n) scanf("%s", grid[i]);
		printf("Case %d:\n", ++C); 
		memset(ans, -1, sizeof ans);
		
	/*	for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				
					
				
				}
				
			
			}
		}*/
		
		
		FOR(i, 0, q){
			sf2(r, c);
			
			if(ans[r - 1][c - 1] == -1 && grid[r - 1][c - 1] != '#'){
					cnt = 0;
					memset(vis, 0, sizeof vis);
					bfs(r - 1, c - 1);
				for(int i1 = 0; i1 < n; i1++)
					for(int j1 = 0; j1 < m; j1++)
						if(vis[i1][j1]) ans[i1][j1] = cnt;
				}
			
			if(ans[r - 1][c - 1] != -1){ pf1(ans[r - 1][c - 1]);}
			else pf1(0);
			
		}
		
	}
	


    return 0;
}




















