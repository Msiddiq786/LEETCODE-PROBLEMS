class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x, ans = 0;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long sq = mid * mid;

            if (sq == x) return mid;

            if (sq < x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

// int mySqrt(int x) {
//     int i = 1;

//     while ((long long)i * i <= x) {
//         if ((long long)i * i == x)
//             return i;
//         i++;
//     }

//     return i - 1;
// }

// };