#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        for(int i = 0; i < n; i++) cin >> arr[i];

        int dp[n + 1] = {1}, ans = 1;

        // for(int x: dp) cout << x << " ";
        // cout << endl;

        for(int i =  1; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){

                if(arr[j] < arr[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }

        }
        cout << ans << endl;

    }

    return 0;
}
