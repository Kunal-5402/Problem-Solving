class Solution {
public:
    int mod = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        long long ans = power(x, n / 2);
        ans *= ans;
        ans %= mod;
        if (n % 2 == 1) {
            ans *= x;
            ans %= mod;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {

        long long int prime = n / 2;
        long long int even = n - prime;

        long long int p_c = power(4, prime) % mod;
        long long int e_c = power(5, even) % mod;

        return (int)((p_c * e_c) % mod);
    }
};