class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long sum=0;
        unordered_map<char,unordered_map<string,int>> m;
        for(auto&i:ideas){
            m[i[0]][i.substr(1,i.length()-1)]++;
        }
        for(int i =0; i<26; i++){
          if(m['a'+i].size()){
            for(int j =0; j<26; j++){
                long long temp=0;
                if(i!=j&&m['a'+j].size()){
                    for(auto&k:m['a'+j]){
                        if(m['a'+i][k.first]){
                            temp++;
                        }else{
                            m['a'+i].erase(k.first);
                        }
                    }
                    // cout<<"temp: "<<temp<<" m['a'+i].size(): "<<m['a'+i].size()<<" m['a'+j].size(): "<<m['a'+j].size()<<endl;
                    sum+=(m['a'+i].size()-temp)*(m['a'+j].size()-temp);
                }
            }
          }
        }
          
        return sum;
    }
};