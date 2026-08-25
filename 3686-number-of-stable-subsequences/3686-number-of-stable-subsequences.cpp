class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        const long long MOD = 1e9 + 7;

        long long E1 = 0;
        long long E2 = 0;
        long long O1 = 0;
        long long O2 = 0;

        for (int x : nums) {
            long long nE1 = E1;
            long long nE2 = E2;
            long long nO1 = O1;
            long long nO2 = O2;

            if (x % 2 == 0) {

                // [x] by itself
                nE1++;

                // O1 + even → E1
                nE1 += O1;

                // O2 + even → E1
                nE1 += O2;

                // E1 + even → E2
                nE2 += E1;

            } else {

                // [x] by itself
                nO1++;

                // E1 + odd → O1
                nO1 += E1;

                // E2 + odd → O1
                nO1 += E2;

                // O1 + odd → O2
                nO2 += O1;
            }

            E1 = nE1 % MOD;
            E2 = nE2 % MOD;
            O1 = nO1 % MOD;
            O2 = nO2 % MOD;
        }

        return (E1 + E2 + O1 + O2) % MOD;
    }
};