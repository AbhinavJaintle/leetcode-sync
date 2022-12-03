class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> m;
        for(auto&i:s){
            m[i]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto&i:m){
            pq.push({i.second,i.first});
        }
        string temp;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            for(int i = 0; i<t.first; i++){
                temp.push_back(t.second);
            }
        }
        return temp;
    }
};