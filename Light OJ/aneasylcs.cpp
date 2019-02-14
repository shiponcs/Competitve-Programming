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
int ans, s, p, q, sz1, sz2;
bool check = false;
string s1, s2;
int lcs[109][109];
string str[109][109];



int main()
{
 
    //freopen("input.txt", "r", stdin);
    cin >> t;
	while(t--){
		cin >> s1 >> s2;
		sz1 = s1.size(), sz2 = s2.size();
		memset(lcs, 0, sizeof lcs);
		for(int i = 0; i < 109; i++) str[i][0] = str[0][i] = "";
		
		for(int i = 1; i <= sz1; i++){
			for(int j = 1; j <= sz2; j++){
				if(s1[i - 1] == s2[j - 1]) lcs[i][j] = 1 + lcs[i - 1][j - 1], str[i][j] = str[i - 1][j - 1] + s1[i - 1];
				else if(lcs[i - 1][j] == lcs[i][j - 1]) lcs[i][j] = lcs[i- 1][j], str[i][j] = min(str[i][j - 1], str[i - 1][j]);
				else if(lcs[i - 1][j] > lcs[i][j - 1]) lcs[i][j] = lcs[i - 1][j], str[i][j] = str[i - 1][j];
				else lcs[i][j] = lcs[i][j - 1], str[i][j] = str[i][j - 1];
 			}
		}
		
		cout << "Case " << ++C << ": " << (lcs[sz1][sz2] ? str[sz1][sz2] : ":(" ) << endl;
	
	}


    return 0;
}
















