class Solution {
  public:
  struct node{
      int freq;
      node* left;
      node* right;
      node(int f){
          freq =f;
          left = right = nullptr;
      }
  };
  struct compare{
      bool operator()(node*a, node* b){
          return a->freq > b->freq;
      }
  };
  void preorder(node*  root,string code,vector<string>&ans){
      if(!root) return;
      if(!root->left && !root->right){
          ans.push_back(code);
          return;
      }
      preorder(root->left, code +"0", ans);
      preorder(root->right, code+"1",ans);
  }
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<node*,vector<node*>,compare>q;
        
        for(int i = 0;i<N;i++){
            q.push(new node(f[i]));
        }
        while(q.size()>1){
            node* left = q.top();
            q.pop();
            node* right = q.top();
            q.pop();
            node* parent = new node(left->freq+right->freq);
            parent->left = left;
            parent->right = right;
            q.push(parent);
        }
        vector<string>ans;
        preorder(q.top(),"",ans);
        return ans;
        
    }
};
