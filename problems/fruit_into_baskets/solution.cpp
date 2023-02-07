class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int prev1=-2;
        int prev2=-2;
        int count =0;
        int start=0;
        int maxi=0;
        int sum=0;
        unordered_map<int,int> m;
        for(int i = 0; i<fruits.size(); i++){
            if(!m[fruits[i]])count++;
            m[fruits[i]]++;
            if(count==1){
                prev1= fruits[i];
            }
            if(count==2){
                if(prev1!=fruits[i])prev2=fruits[i];
            }
            sum++;
            if(count==3){
                while(m[prev1]&&m[prev2]){
                    m[fruits[start]]--;
                    sum--;
                    start++;
                }
                if(m[prev1]==0){
                    prev1=fruits[i];
                }
                else{
                    prev2=fruits[i];
                }
                count--;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};