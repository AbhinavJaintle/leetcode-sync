class Solution {
public:
    vector<vector<int>>helper(vector<int>&nums,int n)
    {
        //base case
        if(n==1)
        {
            return {{nums[n-1]}};
        }
        
        int lastEle=nums[n-1];
        //obtain all the permutations of rest of the elements in the array
        vector<vector<int>>permut=helper(nums,n-1);
        
        //insert the last element at different positions to obtain new permutations
        vector<vector<int>>newPermut;
        for(int i=0;i<permut.size();i++)
        {
            for(int j=0;j<=permut[i].size();j++)
            {
                vector<int>temp=permut[i];
                temp.insert(temp.begin()+j,lastEle);
                newPermut.push_back(temp);
            }
        }
        return newPermut;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans=helper(nums,n);
        return ans;
    }
};