#include <cstddef>
#include <cstdint>
#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
#include <optional>
#include <type_traits>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* root, int& sub_node_num, int &count) {
    int res = root->val;
    int left_sub_node_num = 0, right_sub_node_num = 0;
    if(root->left != nullptr) {
        left_sub_node_num = 1;
        res += helper(root->left, left_sub_node_num, count);
    }
    
    if(root->right != nullptr) {
        right_sub_node_num = 1;
        res += helper(root->right, right_sub_node_num, count);
    }
    sub_node_num = sub_node_num + left_sub_node_num + right_sub_node_num;
    if(res / sub_node_num == root->val) {
        count ++;
    }
    return res;
}

int averageOfSubtree(TreeNode *root) {
    int count = 0, sub_node_num = 1;
    helper(root, sub_node_num, count);
    return count;
}


TreeNode * CreateBinaryTree1(std::vector<std::optional<int>> &tree_value, TreeNode *node, int i, int n) {
    if(i < n) {
        if(tree_value[i] == std::nullopt) {
            node = nullptr;
            return node;
        }
        node = new TreeNode(*tree_value[i]);
        node->left = CreateBinaryTree1(tree_value, node->left, 2 * i + 1, n);
        node->right = CreateBinaryTree1(tree_value, node->right, 2 * i + 2, n);
    }
    return node;
}

void Inorder(TreeNode *root) {
    if(root == nullptr) {
        return ;
    }
    Inorder(root->left);
    std::cout << root->val << " ";
    Inorder(root->right);
}

void Preorder(TreeNode *root) {
    if(root == nullptr) {
        return ;
    }
    std::cout << root->val << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(TreeNode *root) {
    if(root == nullptr) {
        return ;
    }
    Postorder(root->left);
    Postorder(root->right);
    std::cout << root->val << " ";
}

void LevelOrderHelper(TreeNode *root, std::vector<std::vector<int>> &result, int depth) {
    if(root == nullptr) return ;
    if(result.size() == depth) result.push_back(std::vector<int>());
    result[depth].push_back(root->val);
    LevelOrderHelper(root->left, result, depth + 1);
    LevelOrderHelper(root->right, result, depth + 1);
}
 
void LevelOrder(TreeNode *root) {
    if(root == nullptr) {
        return ;
    }
    std::vector<std::vector<int>> result;
    LevelOrderHelper(root, result, 0);
    std::cout << result.size() << std::endl;
}

void QuickSort(int nums[], int l, int r) {
    if(l >= r) return;
    int i = l - 1, j = r + 1, base = nums[ (l + r) >> 1];
    while(i < j) {
        do {
            ++ i;
        } while(nums[i] < base);

        do {
            -- j;
        }while(nums[j] > base);
        if(i < j) swap(nums[i], nums[j]);
    }
    QuickSort(nums, l, j);
    QuickSort(nums, j + 1, r);
}

int MidSearch(int nums[], int n, int value) {
    int l = 0, r = n - 1;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(nums[mid] <= value) l = mid;
        else r = mid - 1;
    }
    return r;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty() && inorder.empty()) return nullptr;
    if(preorder[0] == -1 && inorder[0] == -1) {
        return new TreeNode(-1);
    }
    int root_value = preorder[0];
    TreeNode *root = new TreeNode(root_value);

    std::vector<int> left_inorder, right_inorder;

    int left_size = 0, index = 0;
    while(root_value != inorder[index]) {
        left_inorder.push_back(inorder[index]);
        ++ index;
    }
    left_size = index;
    index = index + 1;  
    while(index < inorder.size()) {
        right_inorder.push_back(inorder[index]);
        ++ index;
    }

    std::vector<int> left_preorder, right_preorder;
    index = 1;
    while(index < left_size + 1) {
        left_preorder.push_back(preorder[index]);
        ++ index;
    }

    while(index < preorder.size()) {
        right_preorder.push_back(preorder[index]);
        ++ index;
    }

    root->left = buildTree(left_preorder, left_inorder);
    root->right = buildTree(right_preorder, right_inorder);
    return root;
}


int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    std::cout << preorder.size() << " " << inorder.size() << std::endl;
    TreeNode *root = buildTree(preorder, inorder);
    // LevelOrder(root);
    Preorder(root) ;
    return 0;
}