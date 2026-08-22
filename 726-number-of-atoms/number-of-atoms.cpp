class Solution {
public:
    string countOfAtoms(string f) {
        stack<unordered_map<string, int>> s;
        s.push({});
        int i = 0, n = f.length();
        while (i < n) {
            if (f[i] == '(')
                s.push({}), i++;
            else if (f[i] == ')') {
                unordered_map<string, int> t = s.top();
                s.pop();
                i++;
                int st = i;
                while (i < n && isdigit(f[i]))
                    i++;
                int mp = st < i ? stoi(f.substr(st, i - st)) : 1;
                for (auto& x : t)
                    s.top()[x.first] += x.second * mp;
            } else {
                int st = i++;
                while (i < n && islower(f[i]))
                    i++;
                string e = f.substr(st, i - st);
                st = i;
                while (i < n && isdigit(f[i]))
                    i++;
                int cnt = st < i ? stoi(f.substr(st, i - st)) : 1;
                s.top()[e] += cnt;
            }
        }
        unordered_map<string, int> ans = s.top();
        vector<string> vec;
        for (auto& x : ans)
            vec.push_back(x.first);
        sort(vec.begin(), vec.end());
        string fans;
        for (auto& e : vec) {
            fans += e;
            if (ans[e] > 1)
                fans += to_string(ans[e]);
        }
        return fans;
    }
};