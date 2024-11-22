#include "searching.h"
#include "huff.h"

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

    char input[1000];
    printf("50자 이상의 문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    // 허프만 트리 생성
    HuffmanNode* rootHuff = createHuffmanTree(input);

    // 허프만 코드 생성
    char codes[256][256] = { 0 };
    char code[256];
    generateCodes(rootHuff, code, 0, codes);

    printf("Huffman codes:\n");
    for (int i = 0; i < 256; i++) {
        if (codes[i][0] != '\0') {
            printf("%c: %s\n", i, codes[i]);
        }
    }
    // 부호화
    char encoded[10000];
    encode(input, codes, encoded);
    printf("\nEncoded String: %s\n", encoded);

    // 복호화
    char decoded[1000];
    decode(encoded, rootHuff, decoded);
    printf("\nDecoded String: %s\n", decoded);

    return 0;
}
