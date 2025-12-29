#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>


void dfs(std::vector<int> money, int const idx, int const remain, long long& count) {
    if (remain == 0) {
        count++;
        return;
    }
    if (remain < 0 || idx >= money.size()) {
        return;
    }
    
    // 1원 동전을 5원일때까지 사용
    // 2원 동전을 4원일떄까지
    for (int k = 0; remain - k * money[idx] >= 0; k++) {
        dfs(money, idx + 1, remain - k * money[idx], count);
    }
}

int solution(int n, std::vector<int> money) {
    // long long count = 0;
    // dfs(money, 0, n, count);
    // constexpr int MOD = 1000000007;
    // return count % MOD;
    
    constexpr int MOD = 1000000007;
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int coin : money) {
        for (int j = coin; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
    }
    
    return static_cast<int>(dp[n]);
}
