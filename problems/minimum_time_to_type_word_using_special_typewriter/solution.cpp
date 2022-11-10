class Solution {
public:
    int minTimeToType(string word) {
        int count = 0;
        char curr = 'a';
        for(auto&i:word){
            if(i>curr){
                count+=min(i-curr,26-(i-curr))+1;
            }
            else{
                count+=min(curr-i,26-(curr-i))+1;
            }
            curr=i;
        }
        return count;
    }
};