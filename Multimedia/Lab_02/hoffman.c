#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct {
    Node *data[MAX];
    int size;
} MinHeap;

Node* createNode(char ch, int freq) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void insertHeap(MinHeap *heap, Node *node) {
    int i = heap->size++;
    while (i && node->freq < heap->data[(i - 1) / 2]->freq) {
        heap->data[i] = heap->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->data[i] = node;
}

Node* extractMin(MinHeap *heap) {
    Node *min = heap->data[0];
    Node *last = heap->data[--heap->size];
    int i = 0, smallest;
    while (2 * i + 1 < heap->size) {
        int left = 2 * i + 1, right = 2 * i + 2;
        smallest = left;
        if (right < heap->size && heap->data[right]->freq < heap->data[left]->freq)
            smallest = right;
        if (last->freq <= heap->data[smallest]->freq) break;
        heap->data[i] = heap->data[smallest];
        i = smallest;
    }
    heap->data[i] = last;
    return min;
}

void printCodes(Node *root, char *code, int depth) {
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        printf("%c: %s\n", root->ch, code);
        return;
    }
    if (root->left) {
        code[depth] = '0';
        printCodes(root->left, code, depth + 1);
    }
    if (root->right) {
        code[depth] = '1';
        printCodes(root->right, code, depth + 1);
    }
}

int main() {
    int n, i, freq[100];
    char chars[100];
    char code[100];
    MinHeap heap = {.size = 0};

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &chars[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Frequency of %c: ", chars[i]);
        scanf("%d", &freq[i]);
        insertHeap(&heap, createNode(chars[i], freq[i]));
    }

    while (heap.size > 1) {
        Node *left = extractMin(&heap);
        Node *right = extractMin(&heap);
        Node *merged = createNode('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        insertHeap(&heap, merged);
    }

    printf("\nHuffman Codes:\n");
    printCodes(heap.data[0], code, 0);
    return 0;
}
b