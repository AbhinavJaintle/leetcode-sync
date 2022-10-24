class Solution {
public:
    int unique(int index, unordered_map<char,int> m, vector<string>& arr, string curr){
        if(index==arr.size()){
            return curr.length();
        }
        int flag = 0;
        for(auto&i:arr[index]){
            if(m[i]==1){
                flag = 1;
                break;
            }
        }
        int len;
        if(flag==0){
            int temp1 = unique(index+1,m,arr,curr);
            for(auto&i:arr[index]){
                m[i]=1;
            }
            curr+=arr[index];
            int temp2 = unique(index+1,m,arr,curr);
            len = max(temp1,temp2);
        }
        else{
            len = unique(index+1,m,arr,curr);
        }
        return len;
    }
    int maxLength(vector<string>& arr) {
        string curr;
        unordered_map<char,int> m;
        for(auto&i:arr){
            unordered_map<char,int> mt;
            int temp = 0;
            for(auto&j:i){
                if(mt[j]==1){
                    temp=1;
                    break;
                }
                mt[j]=1;
            }
            if(temp==1){
                i="";
            }
        }
        return unique(0,m,arr,curr);
    }
};