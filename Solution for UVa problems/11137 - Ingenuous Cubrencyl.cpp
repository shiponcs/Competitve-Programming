#include<bits/stdc++.h>
using namespace std;

long long dp[10010];
int n, t, l, k, p;
int main()
{
    dp[0] = 1;

      //it counts mirrors. uh hu.
      for(int i = 0; i <= 10000; i++){

        for(int i1 = 1; i1 <= 21; i1++){
            k = i1 * i1 * i1;

            if(i + k <= 10000)  dp[i + k] += dp[i];
        }
    }

    /* for(int i1 = 1; i1 <= 21; i1++){
         k = i1 * i1 * i1;
        for(int i = 0; i <= 10000; i++){
            if(k + i <= 10000) dp[i + k] += dp[i];
        }
    }*/

    while(cin >> n){
        cout << dp[n] << endl;
    }

    return 0;
}
