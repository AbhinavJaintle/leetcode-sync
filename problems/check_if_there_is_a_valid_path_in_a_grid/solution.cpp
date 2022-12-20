
class Solution {
public:
    bool f(vector<vector<int>>& g, int i, int j, vector<vector<int>>& vis) {
        if(i == g.size() - 1 && j == g[0].size() - 1) {
            return true;
        }
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || vis[i][j])
            return false;
        vis[i][j] = 1;
        bool ans = false;
        if(g[i][j] == 1) {
            if(j - 1 >= 0 && (g[i][j - 1] == 1 || g[i][j - 1] == 4 || g[i][j - 1] == 6)) {
                ans |= f(g, i, j - 1, vis);
            }
            if(j + 1 < g[0].size() && (g[i][j + 1] == 1 || g[i][j + 1] == 3 || g[i][j + 1] == 5)) {
                ans |= f(g, i, j + 1, vis);
            }
        }
        
        else if(g[i][j] == 2) {
            if(i - 1 >= 0 && (g[i - 1][j] == 2 || g[i - 1][j] == 3 || g[i - 1][j] == 4)) {
                ans |= f(g, i - 1, j, vis);
            }
            if(i + 1 < g.size() && (g[i + 1][j] == 2 || g[i + 1][j] == 5 || g[i + 1][j] == 6)) {
                ans |= f(g, i + 1, j, vis);
            }
        }
        
        else if(g[i][j] == 3) {
            if(j - 1 >= 0 && (g[i][j - 1] == 1 || g[i][j - 1] == 4 || g[i][j - 1] == 6)) {
                ans |= f(g, i, j - 1, vis);
            }
            if(i + 1 < g.size() && (g[i + 1][j] == 2 || g[i + 1][j] == 5 || g[i + 1][j] == 6)) {
                ans |= f(g, i + 1, j, vis);
            }
        }
        
        else if(g[i][j] == 4) {
            if(i + 1 < g.size() && (g[i + 1][j] == 2 || g[i + 1][j] == 6 || g[i + 1][j] == 5)) {
                ans |= f(g, i + 1, j, vis);
            }
            if(j + 1 < g[0].size() && (g[i][j + 1] == 1 || g[i][j + 1] == 5 || g[i][j + 1] == 3)) {
                ans |= f(g, i, j + 1, vis);
            }
        }
        
        else if(g[i][j] == 5) {
            if(i - 1 >= 0 && (g[i - 1][j] == 2 || g[i - 1][j] == 3 || g[i - 1][j] == 4)) {
                ans |= f(g, i - 1, j, vis);
            }
            if(j - 1 >= 0 && (g[i][j - 1] == 1 || g[i][j - 1] == 6 || g[i][j - 1] == 4)) {
                ans |= f(g, i, j - 1, vis);
            }
        }
        
        else if(g[i][j] == 6) {
            if(i - 1 >= 0 && (g[i - 1][j] == 2 || g[i - 1][j] == 3 || g[i - 1][j] == 4)) {
                ans |= f(g, i - 1, j, vis);
            }
            if(j + 1 < g[0].size() && (g[i][j + 1] == 1 || g[i][j + 1] == 5 || g[i][j + 1] == 3)) {
                ans |= f(g, i, j + 1, vis);
            }
        }
        vis[i][j] = 0;
        return ans;
    }
    
    bool hasValidPath(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return f(g, 0, 0, vis);
    }
};
