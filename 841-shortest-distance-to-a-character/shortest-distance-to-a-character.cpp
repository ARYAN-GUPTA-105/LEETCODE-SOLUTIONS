class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        unordered_set<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (s[i] == c)
                st.insert(i);
        for (int i = 0; i < n; i++) {
            int dist = INT_MAX;
            for (auto& x : st) {
                if (dist > abs(i - x))
                    dist = abs(i - x);
            }
            ans.push_back(dist);
        }
        return ans;
    }
};