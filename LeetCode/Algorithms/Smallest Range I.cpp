class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int sz, mn, mx;
        sz = A.size();
        if(sz==1)
            return 0;
        sort(A.begin(), A.end());
        mn = A[0];
        mx = A[sz-1];
        if(mx-mn<=2*K)
            return 0;
        return mx-K-mn-K;
    }
};
