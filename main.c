#include "searching.h"
#include "huff.h"

int main() {
    char expression[1000];
    printf("Enter an arithmetic expression: ");
    if (fgets(expression, sizeof(expression), stdin)) {
        // 개행 문자 제거
        size_t len = strlen(expression);
        if (len > 0 && expression[len - 1] == '\n') {
            expression[len - 1] = '\0'; // 개행 문자를 NULL로 치환
        }

        printf("You entered: %s\n", expression);
    } else {
        fprintf(stderr, "Error reading input.\n");
    }
    
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

    char input[1000];
    printf("Enter a string with over 50 characters: ");
    fgets(input, sizeof(input), stdin);

    // create huffman tree
    HuffmanNode* rootHuff = createHuffmanTree(input);

    // create huffman code
    char codes[256][256] = { 0 };
    char code[256];
    generateCodes(rootHuff, code, 0, codes);

    printf("Huffman code:\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i][0] != '\0') {
            printf("%c: %s\n", i, codes[i]);
        }
    }
    // encoding
    char encoded[10000];
    encode(input, codes, encoded);
    printf("\nencoded string: %s\n", encoded);

    // decoding
    char decoded[1000];
    decode(encoded, rootHuff, decoded);
    printf("\ndecoded string: %s\n", decoded);

    return 0;
}
