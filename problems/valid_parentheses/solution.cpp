class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> parens{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> open;
        for (char c : s) {
            if (parens.count(c)) {
                open.push(c);
            } else if (!open.empty() && parens[open.top()] == c) {
                open.pop();
            } else {
                return false;
            }
        }
        return open.empty();
    }
};