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
long long ans, s, p, q;
bool check = false;
string s1, s2;
int dp1[31][31], sz1, sz2;
LL dp2[31][32];
int LCS()
{
	for(int i = 1; i <= sz1; i++){
		for(int j = 1; j <= sz2; j++){
			if(s1[i - 1] == s2[j - 1]) dp1[i][j] = 1 + dp1[i - 1][j - 1];
			else dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
		}
	}
	return dp1[sz1][sz2];
	
}

LL call()
{
	for(int i = 0; i <= sz1; i++)
		dp2[i][0] = 1;
	for(int i = 0; i <= sz2; i++)
		dp2[0][i] = 1;
	
	for(int i = 1; i <= sz1; i++){
		for(int j = 01; j <= sz2; j++){
			if(s1[i - 1] == s2[j - 1]) 
				dp2[i][j] = dp2[i - 1][j - 1];
			else if
				(dp1[i - 1][j] == dp1[i][j - 1]) dp2[i][j] = dp2[i][j - 1] + dp2[i - 1][j];
			else if(dp1[i - 1][j] > dp1[i][j - 1]) dp2[i][j] = dp2[i - 1][j];
			else dp2[i][j] = dp2[i][j - 1];
		}
	}
	 
	return dp2[sz1][sz2];
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    optimize; 
    //freopen("input.txt", "r", stdin);
    cin >> t;
	while(t--){
		memset(dp1, 0, sizeof dp1); 
		cin >> s1 >> s2;
		sz1  = s1.size(), sz2 = s2.size();
		
		cout << "Case " << ++C << ": ";
		
		cout << sz1 + sz2 - LCS() << ' ';
		cout << call() << endl;
	}
   return 0;
}























