class DetectSquares {
    map<pair<int,int>,int> m;
public:
    DetectSquares() {
        m.clear();
    }
    
    void add(vector<int> point) {
        m[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int sum = 0;
       
        for(auto&i:m){
            if(i.first.first==point[0]||i.first.second==point[1]){
                int a = (i.first.first==point[0]) ? abs(i.first.second-point[1]):0;
                int temp = 0;
                if(a!=0){
                    if(i.first.first==point[0]){
                        temp+=m[{i.first.first-a,i.first.second}]*m[{point[0]-a,point[1]}];
                        temp+=m[{i.first.first+a,i.first.second}]*m[{point[0]+a,point[1]}];
                    }
                    
                }
                sum+=temp*i.second;

            }
        }
        return sum;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */