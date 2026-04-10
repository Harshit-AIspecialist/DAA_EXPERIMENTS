bool solve(int i,int sum,vector<int>& arr,int target,vector<vector<int>>&dp){ //DECISION VERSION
    if(sum == target) return true;
    if(i == arr.size()||sum>target) return false;
    bool take = false;
    if(dp[i][sum]!=-1) return dp[i][sum];
    if(arr[i]+sum<= target){
        take = solve(i+1,sum +arr[i],arr,target,dp);
    }
    bool nontake = solve(i+1,sum,arr,target,dp);
    return dp[i][sum] = take or nontake;
    
}
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,0,arr,sum,dp);
    
    }






//VERIFICATION VERSION

bool solve(int i, int sum, vector<int>& arr, int target, vector<vector<int>>& dp, vector<int>& path) {
    if (sum == target) return true;
    if (i == arr.size() || sum > target) return false;
    if (dp[i][sum] != -1) return dp[i][sum];
    if (sum + arr[i] <= target) {
        path.push_back(arr[i]);
        if (solve(i + 1, sum + arr[i], arr, target, dp, path)) {
            return dp[i][sum] = true;
        }
        path.pop_back();
    }
    if (solve(i+ 1, sum, arr, target,dp, path)) {
        return dp[i][sum]= true;
    }
    return dp[i][sum]= false;
}
vector<int> subsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+ 1,-1));
    vector<int> path;
    if (solve(0, 0, arr, target, dp, path))
        return path;
    return {};
}
