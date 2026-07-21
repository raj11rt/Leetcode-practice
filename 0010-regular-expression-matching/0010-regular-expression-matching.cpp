class Solution {
public:
    vector<vector<int>> dp;
    bool f(int i, int j, string &s, string &p) {
        if (j == p.size()) return i == s.size();
        if (dp[i][j] != -1) return dp[i][j];
        bool match = i < s.size() && 
                     (s[i] == p[j] || p[j] == '.');

        
        if (j + 1 < p.size() && p[j + 1] == '*')
            return dp[i][j] = f(i, j + 2, s, p) ||
                              (match && f(i + 1, j, s, p));
        return dp[i][j] = match && f(i + 1, j + 1, s, p);
    }
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
        return f(0, 0, s, p);
    }
};