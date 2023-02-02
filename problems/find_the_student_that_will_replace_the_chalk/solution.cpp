class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long prev=0;
        int index=0;
        for(auto&i:chalk){
            long long temp = i+prev;
            if(temp>k)return index;
            index++;
            i+=prev;
            prev=i;
        }
        long long temp=k;
        temp%=chalk[chalk.size()-1];
        for(int i = 0; i<chalk.size(); i++){
            if(temp<chalk[i])return i;
        }
        return -1;
    }
};