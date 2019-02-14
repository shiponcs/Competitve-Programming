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
int ar[29][3], dp[29][3];

/*int solve(int house, int paint)
{
	if(house < 0) return mn;
	if(house == 0) return ar[house][paint];
	if(tr[house][paint] != -1) return tr[house][paint];
	
	if(paint == 0) return ar[house][paint] + min(solve(house - 1, 1), solve(house -1, 2));
	if(paint == 1) return ar[house][paint] + min(solve(house - 1, 0), solve(house -1, 2));
	if(paint == 2) return ar[house][paint] + min(solve(house - 1, 1), solve(house -1, 0));
	
}


recursive DP gives TLE.

*/

int main()
{

    //freopen("input.txt", "r", stdin);
    cin >> t;
    while(t--){
    	memset(ar, 0, sizeof ar);
    	memset(dp, -1, sizeof dp);
    	 
    	sf1(n);

    	FOR(i, 0, n) sf3(ar[i][0], ar[i][1], ar[i][2]);
    	
		//ans = min3( solve(n - 1, 0), solve(n - 1, 1), solve(n - 1, 2));
    	
    	//we can start from any sid, first initial house is selected without condition
    	//so, if we start from the last house (n - 1), then, remember it's our base case.
    	
    	
    	FOR(i, 0, 3)dp[n - 1][i] = ar[n - 1][i];
    	
    	//now we need apply dp from house n - 2 to 0, 
    	for(int i = n - 2; i >= 0; i--){
    		for(int paint = 0; paint < 3; paint++){
    			if(paint == 0) dp[i][paint] = min(dp[i + 1][1], dp[i + 1][2]) + ar[i][paint];
    			else if(paint == 1) dp[i][paint] = min(dp[i + 1][0], dp[i + 1][2] ) + ar[i][paint];	
				else dp[i][paint] = min(dp[i + 1][1], dp[i + 1][0]) + ar[i][paint];
    		}
    	}
    	
    	ans = min3(dp[0][0], dp[0][1], dp[0][2]);
    	printf("Case %d: ", ++C);
    	pf1(ans);
    
    }


















    return 0;
}



