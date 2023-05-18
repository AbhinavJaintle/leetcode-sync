/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> v = {};
    int n = 0; 
    int i = 0;

    void helper(int index, vector<NestedInteger>& nestedList){
        if(index>=nestedList.size())return;
        if(nestedList[index].isInteger()){
            v.push_back(nestedList[index].getInteger());
        }
        else helper(0,nestedList[index].getList());
        helper(index+1, nestedList);
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(0,nestedList);
        n = v.size();
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i<n;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */