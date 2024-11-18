#include "searching.h"

int main() {
    const char* expression = "13 / 4 + 5 * ( 2 - 8 )";

    TreeNode* root = buildExpressionTree(expression);

    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");

    printf("Levelorder traversal: ");
    levelOrder(root);

    return 0;
}
