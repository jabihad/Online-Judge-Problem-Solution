class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i, j, k, l;
        vector<int> r1, r2, r;
        for(i=0;i<A.size();i++){
            if(A[i]%2==0)
                r1.push_back(A[i]);
            else
                r2.push_back(A[i]);
        }
        for(i=0;i<r1.size();i++)
            r.push_back(r1[i]);
        for(i=0;i<r2.size();i++)
            r.push_back(r2[i]);
        
        return r;
    }
};
