class Solution {
public:
    unordered_map<int,int> m;
    int count =0;
    void helper(int n){
        if(n%2==0){
            if(m[2]==0){
                count++;
                m[2]++;
            }
            while(n%2==0){
                n/=2;
            }
        }

    for (int i = 3; i <= sqrt(n); i = i + 2){
            if(n%i==0){
                if(m[i]==0){
                    count++;
                    m[i]++;
                }
                while(n%i==0){
                    n/=i;
                }
            }
    }

    if (n > 2){
        if(m[n]==0){
            count++;
            m[n]++;
        }
    }
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        m.clear();
        for(auto&i:nums){
            helper(i);
        }
        return count;
    }
};