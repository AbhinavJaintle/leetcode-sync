class FrequencyTracker {
public:
    unordered_map<int,int> m1, m2;
    FrequencyTracker() {
        m1.clear();
        m2.clear();
    }
    
    void add(int number) {
        m2[m1[number]]--;
        m1[number]++;
        m2[m1[number]]++;
    }
    
    void deleteOne(int number) {
        if(m1[number]!=0){
            m2[m1[number]]--;
            m2[m1[number]-1]++;
            m1[number]--;
        }
    }
    
    bool hasFrequency(int frequency) {
        return m2[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */