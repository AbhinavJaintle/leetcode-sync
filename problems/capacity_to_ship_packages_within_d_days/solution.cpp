class Solution {
	public:
		bool help(int m,vector<int> & v,int d)
		{

		int load=0; //my bag currently empty
		int days=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]>m)return false; //if the current weight is itself more than our capacity we have no option but to need more capacity
			load+=v[i]; // we add the current weight to our bag
			if(load>m) // if the bag is out of capacity then do the follwing 
			{ 
				days++; // increase the number of days we have used 
				load=v[i]; // start we a fresh bag with current weight in it 
			}

		}
		if(load>0)days++;  // if the last collected load is more than 0 ie something is collected in the last load then increase days
		if(days<=d)return true;  // if days we took is less than or equal to the givin no. of days then we return true
		return false;  // if it is more than the givin no. of days then we return false
	}
	int shipWithinDays(vector<int>& v, int d) 
	{
		int s=0,e=INT_MAX/2;
		int ans=INT_MAX;
		while(s<=e)
		{
			int mid=(s+e)/2; // our capacity
			if(help(mid,v,d)) // if we are able to collect all the weights usign this capacity then we check with lesser capacity
			{
				ans=min(ans,mid); // our ans is min of last ans and current capacity
				e=mid-1;
			}
			else s=mid+1; // else we try to increase the capacity 
		}
		return ans;
	}
};