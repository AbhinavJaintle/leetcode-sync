class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int x=1; 
        int y = n-1;
        while(1<2){
            string t1 = to_string(x);
            string t2 = to_string(y);
            int flag=0;
            for(auto&i:t1){
                if(i=='0'){
                    x++;
                    y--;
                    flag++;
                    break;
                }
            }
            if(flag==1) continue;
            for(auto&i:t2){
                if(i=='0'){
                    x++;
                    y--;
                    flag++;
                    break;
                }
            }
            if(flag==1) continue;
            return {x,y};
        }
        return {};
    }
};