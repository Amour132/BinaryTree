#include <iostream>

using namespace std;

//翻转二叉树
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution1 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

//二叉树的最大深度
class Solution2 {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);

		return left>right ? left + 1 : right + 1;
	}
};

//二叉树的最小深度
int Min(int a, int b)
{
	return a < b ? a : b;
}
class Solution3 {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);

		return (left && right) ? 1 + Min(left, right) : 1 + left + right;
	}
};