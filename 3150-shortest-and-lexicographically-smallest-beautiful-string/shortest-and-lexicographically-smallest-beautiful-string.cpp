class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = s;
        int i = 0;
        int j = 0;
        int cnt = 0;
        int n = s.length();
        for (char ch : s)
            if (ch == '1')
                cnt++;
        if (cnt < k)
            return "";
        cnt = 0;
        while (j < n) {
            if (s[j] == '1')
                cnt++;
            if (cnt == k) {
                while (i < j && s[i] == '0')
                    i++;
                string curr = s.substr(i, j - i + 1);
                if (ans.length() > curr.length())
                    ans = curr;
                else if (ans.length() == curr.length())
                    ans = min(ans, curr);
                if (s[i] == '1')
                    cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};