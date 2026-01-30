#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>adjlist;
vector<int>path;
vector<bool>visited;
int v = 5;

bool hasedge(int u,int v){
    for(int x:adjlist[u]){
        if(x==v){
            return true;
        }
    }
    return false;
}

bool solve(int u, int cnt){
    if(cnt==v){
        return true;

    }
    for(int x:adjlist[u]){
        if(!visited[x]){
            visited[x] = true;
            path.push_back(x);
            if(solve(v,cnt+1)) return true;
        visited[x] = false;
        path.pop_back();}
    }
    return false;
}
int main(){
    
    int t = 1;
    while(t--){
       
        adjlist={
            {1,2},
            {0},
            {0}
            // {1,3},
            // {0,2,3,4},
            // {1,4},
            // {0,1,4},
            // {1,2,3}
        };
        visited.assign(v,false);
        path.push_back(0);
        visited[0] = true;
        if(solve(0,1)){
            for(int i :path){
                cout<<i<<" ";
            }
            cout<<0<<endl;
        }
        else cout<<"NO PATH"<<endl;
    }
}
