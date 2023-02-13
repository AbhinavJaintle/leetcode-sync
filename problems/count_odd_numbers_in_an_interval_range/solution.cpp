class Solution {
public:
    int countOdds(int low, int high) {
        int sum = (high-low+1)/2;
        return (low%2==0||high%2==0)||(high==low+1)?sum:sum+1;
    }
};