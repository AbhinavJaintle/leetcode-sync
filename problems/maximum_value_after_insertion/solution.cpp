class Solution {
public:
    string maxValue(string n, int x) {
       string temp;
       int flag = 0;
       if(n[0]=='-'){
           temp.push_back(n[0]);
           for(int i = 1; i<n.length(); i++){
               if(flag==0){
                   if(n[i]-'0'<=x){
                       temp.push_back(n[i]);
                   }
                   else{
                       temp+=to_string(x);
                       temp.push_back(n[i]);
                       flag = 1;
                   }
               }
               else{
                   temp.push_back(n[i]);
               }
           }
       } 
       else{
           for(int i = 0; i<n.length(); i++){
               if(flag==0){
                   if(n[i]-'0'>=x){
                       temp.push_back(n[i]);
                   }
                   else{
                       temp+=to_string(x);
                       temp.push_back(n[i]);
                       flag = 1;
                   }
               }
               else{
                   temp.push_back(n[i]);
               }
           }
       }
       if(flag==0){
           temp+=to_string(x);
       }
       return temp;
    }
};