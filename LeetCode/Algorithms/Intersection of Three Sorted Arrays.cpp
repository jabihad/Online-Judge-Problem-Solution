class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i, cnt[2010];
        for(i=1;i<=2000;i++)
            cnt[i] = 0;
        vector<int> res;
        for(i=0;i<arr1.size();i++)
            cnt[arr1[i]]++;
        for(i=0;i<arr2.size();i++)
            cnt[arr2[i]]++;
        for(i=0;i<arr3.size();i++)
            cnt[arr3[i]]++;
        for(i=1;i<=2000;i++)
            if(cnt[i]==3)
                res.push_back(i);
        
        return res;
    }
};
