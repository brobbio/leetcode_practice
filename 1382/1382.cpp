using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>


vector<int> inOrder(TreeNode* root){
    vector<int> ordered = {};
    if(root == NULL){
        return {};
    }else{
        vector<int> left = inOrder(root->left);
        vector<int> right = inOrder(root->right);
        left.push_back(root->val);
        left.insert( left.end(), right.begin(), right.end() );
        return left;
    }
    
}

TreeNode* vecToTree(vector<int> inorder){
    TreeNode* root = new TreeNode();
    int n = inorder.size();
    int midpoint = n/2;
    int mid = inorder[midpoint];
    if(n==0){
        return NULL;
    }else{
        if(n==1 || n==2 || n == 3){
            if(n==1){
                root->val = inorder[0];
                root->left = NULL;
                root->right = NULL;
            }
            if(n==2){
                root->val = inorder[0];
                root->left = NULL;
                TreeNode* hijo = new TreeNode(inorder[1]);
                root->right = hijo;
            }
            if(n==3){
                root->val = inorder[1];
                TreeNode* hijoIzq = new TreeNode(inorder[0]);
                TreeNode* hijoDer = new TreeNode(inorder[2]);
                root->left = hijoIzq;
                root->right = hijoDer;
            }
        }else{
            vector<int> leftTree = std::vector<int>(inorder.begin(),inorder.begin()+midpoint);
            vector<int> rightTree = std::vector<int>(inorder.begin()+midpoint+1,inorder.end());
            root->val = mid;
            root->left = vecToTree(leftTree);
            root->right = vecToTree(rightTree);
        }
        return root;
    }
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> treeToVec = inOrder(root);
    TreeNode* res = vecToTree(treeToVec);
    return res;
}
