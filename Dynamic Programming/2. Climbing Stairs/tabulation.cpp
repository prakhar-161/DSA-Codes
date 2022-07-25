// tabulation method
#include<iostream>
using namespace std;

int climbingStairs(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << climbingStairs(n) << "\n";
    return 0;
}