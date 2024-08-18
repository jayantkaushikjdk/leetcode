class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> num(n);
        num[0] = 1;
        int i = 0, j = 0, k = 0;
        for (int t = 1; t < n; ++t) {
            num[t] = min({ num[i] * 2, num[j] * 3, num[k] * 5 });
            if (num[t] == num[i] * 2) ++i;
            if (num[t] == num[j] * 3) ++j;
            if (num[t] == num[k] * 5) ++k;
        }
        return num.back();
    }
};