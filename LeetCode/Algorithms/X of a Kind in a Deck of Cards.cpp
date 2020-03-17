class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int i, j, cnt[10100]={}, gcd=0;
        set<int> s;
        set<int> :: iterator it;
        for(i=0;i<deck.size();i++){
            cnt[deck[i]]++;
            s.insert(deck[i]);
        }
        for(it=s.begin();it!=s.end();it++)
            gcd = __gcd(gcd, cnt[*it]);
        //cout<<gcd<<endl;
        if(gcd>=2)
            return true;
        return false;
        
    }
};
