class Solution {
public:

    bool palindrome(string &s, int left, int right){
        while(left<right){
            if(s[left]!= s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(int start, string &s,vector<string>& path, vector<vector<string>>& ans){
        if(start == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i =start;i<s.size();i++){
            if(palindrome(s,start,i)){
                path.push_back(s.substr(start,i-start+1));
                solve(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>path;
        solve(0,s,path, ans);
        return ans;
    }
};
