class ProductOfNumbers {
public:
    vector<int> arr;
    ProductOfNumbers() {
        
    }
    int curr = -1;
    void add(int num) {
        arr.push_back(num);
        curr++;
    }
    
    int getProduct(int k) {
        int ans = 1;
        int n = curr;
        while(k&&ans!=0){
            ans*=arr[n];
            n--;
            k--;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */