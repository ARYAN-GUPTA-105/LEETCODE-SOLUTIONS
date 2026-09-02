class Solution {
public:
    vector<double> internalAngles(vector<int>& s) {
        sort(s.begin(), s.end());
        double pie = 3.14159265358979323846;
        vector<double> ans;
        if (s[0] + s[1] <= s[2])
            return ans;
        double a = s[0], b = s[1], c = s[2];
        double aa = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.00;
        double bb = acos((a * a + c * c - b * b) / (2 * a * c)) * 180.00;
        double cc = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.00;
        aa /= pie;
        bb /= pie;
        cc /= pie;
        ans.push_back(aa);
        ans.push_back(bb);
        ans.push_back(cc);
        sort(ans.begin(), ans.end());
        return ans;
    }
};