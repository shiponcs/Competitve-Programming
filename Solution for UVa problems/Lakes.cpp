#include <bits/stdc++.h>
using namespace std;
#define optimize              ios_base::sync_with_stdio(false)
#define FOR(i, a, n)          for(int i = a; i < n; i++)
#define from_0_to(x)          for(int i = 0; i < x; i++)
#define LL                    long long
#define ULL                   unsigned long long
#define YES()                 printf("YES\n")
#define NO()                  printf("NO\n")
#define NL()                  printf("\n")
#define PI                    acos(-1)
#define veci                  vector <int>
#define vecll                 vector < long long >
#define p_b                   push_back
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
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%I64d %I64d\n",a,b)
#define pf3ll(a,b,c)          printf("%I64d %I64d %I64d\n",a,b,c)
#define STRTOLOWER(x)         std::transform (x.begin(), x.end(), x.begin(), ::tolower)
#define STRTOUPPER(x)         std::transform (x.begin(), x.end(), x.begin(), ::toupper)
#define STRTOUCFIRST(x)       std::transform (x.begin(), x.begin()+1, x.begin(),  ::toupper); std::transform (x.begin()+1, x.end(),   x.begin()+1,::tolower)
//int a[MX], b[MX], sol[MX];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int t, tc, n, cnt, N, p, q, r, c, R, C,  m, mn = 1e9 + 9, mx = 0, tt, height, width;
long long ans;
bool check = false, check1 = false;
string grid[99];
int vis[99][99];
map <char, bool> maap;

void dfs(int x, int y)
{
	if(vis[x][y]) return;
	vis[x][y] = 1, cnt++;
	FOR(k, 0, 4){
		int sx = x + dx[k],
			sy = y + dy[k];
		if(sx < 0 || sy < 0 || sx >= r || sy >= c) continue;
		if(grid[sx][sy] == '0') dfs(sx, sy);
	}
}

int main()
{
	sf1(t);
	tc = t;
	while(t){
		if(tc != t) NL();
		sf2(p, q);

		string ss;
		getchar();
		r = 0, c = 0; //row, column
		while( getline(cin, ss) && ss.size() > 0 ){
			grid[r++] = ss;
			c = ss.size();
			check = true;
		}

		memset(vis, 0, sizeof vis);
		cnt = 0;
		dfs(p - 1, q - 1);
		pf1(cnt);
		if(check) t--;
		check = false;
	}
    return 0;
}


















