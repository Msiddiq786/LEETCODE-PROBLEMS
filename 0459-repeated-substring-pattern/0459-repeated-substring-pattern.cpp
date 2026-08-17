class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int N = s.size();
        string S = s+s;
         S.erase(0,1);
         S.pop_back();
        int pos = S.find(s);

if (pos != string::npos)
    return true;
else
    return false;
    }
};