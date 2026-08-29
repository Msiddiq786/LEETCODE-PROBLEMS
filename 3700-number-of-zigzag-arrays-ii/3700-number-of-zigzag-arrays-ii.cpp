#include <vector>
using namespace std;

class Solution {
    long long MOD = 1e9 + 7;

    // Multiplies two matrices
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int sz = A.size();
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < sz; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Binary matrix exponentiation
    vector<vector<long long>> power(vector<vector<long long>> base, long long exp) {
        int sz = base.size();
        vector<vector<long long>> res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) res[i][i] = 1;
        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;
        // Matrix T: transition from state j to state i
        vector<vector<long long>> T(sz, vector<long long>(sz, 0));

        // States 0 to m-1: Last move was UP, next must be DOWN
        // States m to 2m-1: Last move was DOWN, next must be UP
        for (int x = 0; x < m; x++) {
            int downState = x;        // Value x, came from UP (next must be < x)
            int upState = x + m;      // Value x, came from DOWN (next must be > x)
            
            // To be DOWN next, current must have been UP: valid next are y < x
            for (int y = 0; y < x; y++) T[y][upState] = 1;
            
            // To be UP next, current must have been DOWN: valid next are y > x
            for (int y = x + 1; y < m; y++) T[y + m][downState] = 1;
        }

        // Compute T^(n-1)
        vector<vector<long long>> resMat = power(T, n - 1);

        // Initial vector (all states for array of length 1)
        vector<long long> start_vec(sz, 1);
        vector<long long> final_vec(sz, 0);

        // Multiply: result = resMat * start_vec
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                final_vec[i] = (final_vec[i] + resMat[i][j] * start_vec[j]) % MOD;
            }
        }

        long long ans = 0;
        for (long long val : final_vec) ans = (ans + val) % MOD;
        return (int)ans;
    }
};