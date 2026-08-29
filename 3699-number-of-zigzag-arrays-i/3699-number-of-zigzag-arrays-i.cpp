class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m, 1), down(m, 1);
        vector<long long> newUp(m), newDown(m);
        vector<long long> prefUp(m + 1), prefDown(m + 1);

        for (int len = 2; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            long long totalUp = prefUp[m];

            for (int v = 0; v < m; v++) {
                newUp[v] = prefDown[v];
                newDown[v] = (totalUp - prefUp[v + 1] + MOD) % MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;

        for (int v = 0; v < m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};