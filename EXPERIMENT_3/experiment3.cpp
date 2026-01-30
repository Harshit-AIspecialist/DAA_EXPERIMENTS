class Solution {
  public:
 
  
    bool traverse(int start, vector<vector<int>> graph, vector<bool>visited,int n, int count){
        if(count == n){
            return true;
        }
        visited[start] = true;
        for(int nei:graph[start]){
           
            if(!visited[nei]){
                if(traverse(nei,graph,visited,n,count+1)){
                    return true;
                }
            }
        }
        visited[start] = false;
        return false;
    }
    bool check(int n, int m, vector<vector<int>> edges)
        
     {
        vector<vector<int>>graph(n+1);
        for(vector<int> e:edges){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 1;i<=n;i++){
            vector<bool>visited(n+1,false);
            if(traverse(i,graph,visited,n,1)){
                return true;
            }
        }
            
        return false;
        
    }
};
