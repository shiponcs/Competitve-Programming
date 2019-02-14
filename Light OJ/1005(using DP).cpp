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
int t, tt, n, N, l, r, c, cnt, L, R, C, m, k, mn = 1e9 + 9, mx = 0, height, width;
long long ans, s, p, q;
bool check = false;
int binomial_coeff[31][31];
ULL factorial[31];

int bin_coeff_funct(int n, int r)
{
	if(binomial_coeff[n][r] != -1) return binomial_coeff[n][r]; 
	if(n == r || r == 0) return binomial_coeff[n][r] = 1;
	if(r == 1) return binomial_coeff[n][r] = n;
	return bin_coeff_funct(n - 1, r - 1) + bin_coeff_funct(n - 1, r);
}

void fact()
{
	factorial[0] = factorial[1] = 1;
	for(int i = 2; i < 31; i++)
		factorial[i] = factorial[i - 1] * (ULL)i;
}


int main()
{
    cin.tie(0);
    cout.tie(0);
    optimize; 
    memset(binomial_coeff, -1, sizeof binomial_coeff);
    
    FOR(i, 0, 31)
    	FOR(j, 0, i + 1)
    		binomial_coeff[i][j] = bin_coeff_funct(i, j);
    		
    fact();
    
    //freopen("input.txt", "r", stdin);
    cin >> t;
	while(t--){
		cin >> n >> k;
		
	//	cout << (ULL)binomial_coeff[n][k] <<  ' ' << (ULL)factorial[k] << endl;
		cout << "Case " << ++C << ": ";
		if(k > n) cout << "0\n";
		else if (k == 0) cout << "1\n";
		else {
			cout << (ULL)binomial_coeff[n][k] * binomial_coeff[n][k] * factorial[k] << endl;
		}
	}


    return 0;
}

/*
I was tired and sick of this problem, as I was beginner in DP but I managed to solve using math.
Finally, after a lot of observations, I came to figure it out as,
ans = k! * nCk * nCk 
In essence, taking a k * k square from the n * n,(by, nCk * nCk ways)
and, you can prove that, you can arrange k rooks in k * k square in k! ways.
 
*/








