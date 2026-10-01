class Solution {
public:
    bool isAwsm(string str){
        for(int i{};i<str.size();++i){
            if(!((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z')||(str[i]-'0'>=0 && str[i]-'0'<=9)||(str[i]=='_'))) return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<bool>vec(n,true);
        for(int i{0};i<n;++i){
            if(code[i]=="") vec[i]=false;
            if(!isAwsm(code[i])) vec[i]=false;
            if(!isActive[i]) vec[i]=false;
            if(!((businessLine[i]=="electronics")||(businessLine[i]=="grocery")||(businessLine[i]=="pharmacy")||(businessLine[i]=="restaurant"))) vec[i]=false;
        }
        vector<pair<string,string>>ans;
        for(int i{};i<n;++i){
            if(vec[i]==true){
                ans.push_back({businessLine[i],code[i]});
            }
        }
        sort(ans.begin(),ans.end());
        vector<string>str;
        for(int i{};i<ans.size();++i){
            str.push_back(ans[i].second);
        }
        return str;
    }
};