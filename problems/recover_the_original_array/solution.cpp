class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
		//sorting the nums array
        sort(nums.begin(),nums.end());
        
		//we'll try every nums[i] as first element of higher array excpet nums[0]
		//as it is first element of lower
        for(int i=1;i<size(nums);i++)
        {
            vector<int> a;
			//pushing minimum element in lowest
            a.push_back(nums[0]);
			
			//calculating k after assuming nums[i] as first element of higher
            int k = nums[i] - a.back();
            
			//in case k is odd or k = 0, skip !
            if(k&1 || k == 0) continue;
            
            multiset<int> st(nums.begin(),nums.end());
			
			//delete used elements ,ie, nums[0] and nums[i]
            st.erase(st.find(a.back())) , st.erase(st.find(nums[i]));
			
            while(!st.empty())
            {
                // now current minimum value will be part of lower array, so pushing it to a
				// and deleting from multiset
                a.push_back(*st.begin());
                st.erase(st.begin());
				
				//now corresponding element in higher should be
				// last pushed element in lower + current k
                auto it = st.find(a.back() + k);
				
				//if we cann't find corresponding element in higher, we'll break the loop
                if(it == st.end()) break;
				
				//else delete it from multiset
                st.erase(it);
            }
            
			//now if our multiset is empty, ie , we have used all the elements then
			// it is clear that current value of k is the right choice
			// increment every value of lower by k/2 as higher[i] - lower[i] = 2*k
			// and we need to add k to lower[i] to make current array
            if(st.empty())
            {
                for(auto &val : a) val += k/2;
                // cout<<"\n";
                return a;
            }
            
        }
        
        assert(false);
        
    }
};