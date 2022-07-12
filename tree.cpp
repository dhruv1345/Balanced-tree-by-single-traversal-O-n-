class Solution {
public:
    
    pair<int,bool> solve(TreeNode* root){
        if(root==NULL){
            return make_pair(0,true);
        }
        pair<int,bool> leftAns=solve(root->left);
        pair<int,bool> rightAns=solve(root->right);
        
        int leftHeight = leftAns.first;
        int rightHeight = rightAns.first;
        
        bool diff =abs(leftHeight - rightHeight) <= 1;
        
        bool leftBalanced = leftAns.second;
        bool rightBalanced = rightAns.second;
        
        if(leftBalanced && rightBalanced && diff){
            return make_pair(max(leftHeight,rightHeight)+1,true);
        }
        else{
            return make_pair(max(leftHeight,rightHeight)+1,false);
        }
        
    }
    
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans=solve(root);
        return ans.second;
    }
};
