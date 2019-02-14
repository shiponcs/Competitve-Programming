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
//int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
//int dx = {1, 1, 2, 2, -1, -1, -2, -2}
//int dy = {2, -2, 1, -1, 2, -2, 1, -1}
int t, tt, n, N, l, r, c, cnt, L, R, C, m, mn = 1e9 + 9, mx = 0, height, width;
int ans, s, p, q;
bool check = false;
int dp[10009], ar[10000];

int solve()
{
		//include the first house, exclude the last house
		int ans = 0;
		dp[1] = ar[0];
		for(int i = 2; i < n; i++){
			dp[i] = max(dp[i - 1], dp[i - 2] + ar[i -1]);
		}
		
		ans = dp[n - 1];
		//cout << ans << endl;
		//vice-versa, in essence starting from second house to last house
		memset(dp, 0, sizeof dp);
		dp[2] = ar[1]; 	
		
		for(int i = 3; i <= n; i++){
			dp[i] = max(dp[i - 1], dp[i - 2] + ar[i - 1]);
		}
		//cout << dp[n] << endl;
		return max(ans, dp[n]);
}	


int main()
{
    cin.tie(0);
    cout.tie(0);
    optimize; 
    //freopen("input.txt", "r", stdin);
    cin >> t;
    while(t--){
    	ans = 0;
    	memset(ar, 0, sizeof ar);
    	memset(dp, 0, sizeof dp);
    	cin >> n;
    	
    	for(int i = 0; i < n; i++) cin >> ar[i]; 
    	cout << "Case " << ++C << ": ";
		
		cout << solveforodd() << endl;
    }
	


    return 0;
}
























