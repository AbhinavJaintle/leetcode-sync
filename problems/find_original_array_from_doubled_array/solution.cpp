class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        map<int,int> m;
        for(auto&i:changed){
            m[i]++;
        }
        sort(changed.begin(),changed.end());
        for(auto&i:changed){
            if(m[i]!=0&&m[2*i]!=0){
                ans.emplace_back(i);
                m[i]--;
                m[2*i]--;
            }
        }
        for(auto&i:m){
            if(i.second!=0){
                return {};
            }
        }
        if((double)ans.size()!=(double)changed.size()/2){
            return {};
        }
        return ans;
    }
};