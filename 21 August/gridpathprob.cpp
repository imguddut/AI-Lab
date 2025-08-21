#include <bits/stdc++.h>
using namespace std;

// Function to count paths in an m x n grid
int countPaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base case
    dp[0][0] = 1;

    // Fill DP table
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int main() {
    int m = 3, n = 3;
    cout << "Grid Path Problem (" << m << "x" << n << " grid)\n";
    cout << "Total unique paths: " << countPaths(m, n) << endl;
    return 0;
}
