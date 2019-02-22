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

bool check = false;

bool cmp(pii fi, pii se)
{
	if(fi.first < se.first) return true;
	
	if(fi.first == se.first) return fi.second < se.second;
	
	return false;
}

inline LL minn(LL a, LL b)
{

	return (a > b ? b : a);
}


int main()
{
    cin.tie(0);
    cout.tie(0);
    optimize; 
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    long long a[n + 1] = {0} , cost[n + 1] = {0}, ans[m + 1] = {0};
    vector <pii> vv;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {cin >> cost[i]; vv.p_b({cost[i], i});}
    
    sort(vv.begin(), vv.end(), cmp); 
    
    FOR(i1, 0, m){
    
    	LL ans = 0;
    	cin >> t >> tt;
		t--;
		LL tmp = minn(a[t], tt);
			    	
    	ans += cost[t] * tmp;
    	tt -= tmp, a[t] -= tmp;

	//	for(auto x: vv) cout << x.first << ' ' << x.second << endl;
    	
    	//vector <pii> vv1 = vv;
    	
    	
    	//for(auto x: vv1) cout << x.first << ' ' << x.second << endl;
    	
    	for(; l < n && tt != 0; l++){
    		    		
    		
    			LL tmp1 = minn(tt, a[vv[l].second]);
    			ans += vv[l].first * tmp1;
    			a[vv[l].second] -= tmp1;
    			tt -= tmp1;
    			if(tt == 0) break;
    		
    	}
    	
    	
    	
    	
    	if(tt) ans = 0;
    	cout << ans << '\n';
    }
    
   // FOR(i, 0, m) cout << ans[i] << endl;
    
    return 0;
}
















