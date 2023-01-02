class Solution {
public:
    int level(int a){
        int steps1=0;
        int temp=a;
        while(temp){
            temp/=2;
            steps1++;
        }
        return steps1;
    }
    int helper(int a, int b){
        int steps1=level(a);
        int steps2=level(b);
        int sum=steps1+steps2+1;
        if(steps1>steps2){
            while(steps1!=steps2){
                steps1--;
                if(a%2==0) a/=2;
                else{
                    a-=1;
                    a/=2;
                }
            }
        }
        else{
            while(steps2!=steps1){
                steps2--;
                if(b%2==0) b/=2;
                else{
                    b-=1;
                    b/=2;
                }
            }
        }
        while(a!=b){
            if(a%2==0) a/=2;
            else{
                a-=1;
                a/=2;
            }
            if(b%2==0) b/=2;
            else{
                b-=1;
                b/=2;
            }
        }
        sum-=2*level(a);
        return sum;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto&i:queries){
            ans.push_back(helper(i[0],i[1]));
        }
        return ans;
    }
};