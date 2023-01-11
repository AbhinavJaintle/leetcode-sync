class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        if(arr.size()%2!=0) return false;
        vector<int> neg;
        vector<int> pos;
        for(auto&i:arr){
            if(i<0) neg.push_back(i);
            else pos.push_back(i);
        }
        if(neg.size()%2!=0) return false;
        sort(neg.begin(),neg.end(),greater<int>());
        sort(pos.begin(),pos.end());
        unordered_map<int,int> m;
        
        for(int i = 0; i<neg.size(); i++){
            if(neg[i]%2==0&&m[neg[i]]!=0){m[neg[i]]--;}
            else{ m[2*neg[i]]++;}
        }
        for(int i = 0; i<pos.size(); i++){
            if(pos[i]%2==0&&m[pos[i]]!=0) m[pos[i]]--;
            else m[2*pos[i]]++;
        }
        
        for(auto&i:m){
            if(i.second!=0) return false;
        }
        return true;
    }
};