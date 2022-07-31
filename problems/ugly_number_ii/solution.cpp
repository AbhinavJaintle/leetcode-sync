class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> s;
        pq.push(1);
        s.insert(1);
        long long res = -1;
        while (n--) {
            long long cus = pq.top();
            pq.pop();
            res = cus;
            long long two = cus * 2;
            long long three = cus * 3;
            long long five = cus * 5;
            if (!s.count(two)) {
                pq.push(two);
                s.insert(two);
            }
            if (!s.count(three)) {
                pq.push(three);
                s.insert(three);
            }
            if (!s.count(five)) {
                pq.push(five);
                s.insert(five);
            }
        }
        return (int)res;
    }
};