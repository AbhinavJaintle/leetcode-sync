class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
     vector<int> arr = nums;   
     sort(arr.begin(),arr.end());
    int diff=INT_MAX;
    int ans=0;
    
	for(int i=0;i<arr.size();i++){        // fixing the first element 
	
        int left = i+1;      // set a pointer at starting (next to the fixed element) 
		
        int right = arr.size()-1;    // set another pointer at end of the array
		
        while(left<right){
            if(arr[i]+arr[left]+arr[right]==target){
                return target;
            }else if(abs(arr[i]+arr[left]+arr[right]-target)<diff){  //abs(): returns the absolute value of an integer number
                diff=abs(arr[i]+arr[left]+arr[right]-target);
                ans = arr[i]+arr[left]+arr[right];
            }
			
            if(arr[i]+arr[left]+arr[right]>target){
                right--;
            }else{
                left++;
            }
        }
    }
    return ans;
}   
};