class Solution {
public:
    int countEven(int num) {
        int sum=0;
        for(int i = 2; i<=num; i++){
            string temp=to_string(i);
            int n = 0;
            for(auto&j:temp){
                n+=j-'0';
            }
            if(n%2==0)sum++;
        }
        return sum;
    }
};