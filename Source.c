#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;

Node *tree1, *tree2, *tree3;

void push(int a, Node **tree)
{
	if ((*tree) == NULL) {
		(*tree) = malloc(sizeof(Node));
		(*tree)->data = a;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		return;
	}

	if (a > (*tree)->data)
	{
		push(a, &(*tree)->right);
	}
	else if (a < (*tree)->data)
	{
		push(a, &(*tree)->left);
	}
}

void LeftPrint(Node *root) {
	if (root == NULL)
	{
		return;
	}
	LeftPrint(root->left);
	printf("%d ", root->data);
	LeftPrint(root->right);
}

void StructLeftPrint(Node *root, int tab)
{
	if (root == NULL)
	{
		return;
	}
	StructLeftPrint(root->left, tab + 1);
	for (int i = 0; i < tab; i++)
	{
		printf(" ");
	}
	printf("%d\n", root->data);
	StructLeftPrint(root->right, tab + 1);
}

Node *CopyTree(Node *node) {
	if (node == NULL)
		return NULL;

	Node *newNode = malloc(sizeof(Node));
	newNode->data = node->data;
	newNode->left = CopyTree(node->left);
	newNode->right = CopyTree(node->right);

	return newNode;
}

int check(Node *n1, Node *n2)
{
	if (n1->data != n2->data || n1->left == NULL && n2->left != NULL || n1->left != NULL && n2->left == NULL || n1->right == NULL && n2->right != NULL || n1->right != NULL && n2->right == NULL) {
		return 0;
	}
	if (n1->left == NULL && n1->right == NULL && n2->left == NULL && n2->right == NULL) {
		return 1;
	}
	if (n1->left == NULL && n2->left == NULL && n1->right != NULL && n2->right != NULL) {
		return check(n1->right, n2->right);
	}
	if (n1->left != NULL && n2->left != NULL && n1->right == NULL && n2->right == NULL) {
		return check(n1->left, n2->left);
	}

	return (check(n1->left, n2->left) && check(n1->right, n2->right));
}

int main() {
	int n, s;

	printf_s("Building tree #1\n");
	printf("Element amount: ");
	scanf_s("%i", &n);

	for (int i = 0; i < n; i++) {
		printf("Enter a number: ");
		scanf_s("%i", &s);
		push(s, &tree1);
	}

	printf("\nTree #1: ");
	LeftPrint(tree1);
	printf("\n\n");

	int n1, s1;

	printf("Building tree #2\n");
	printf("Element amount: ");
	scanf_s("%i", &n1);

	for (int i = 0; i < n1; i++) {
		printf("Enter a number: ");
		scanf_s("%i", &s1);
		push(s1, &tree2);
	}

	printf("\nTree #2: ");
	LeftPrint(tree2);
	printf("\n\n");

	printf("Copying tree #1 to tree #3\n");
	tree3 = CopyTree(tree1);
	printf("Tree #3: ");
	LeftPrint(tree3);
	printf("\n\n");

	printf("Comparing tree #1 to tree #3\n");
	if (check(tree1, tree3))
	{
		printf("Tree #1 and tree #3 are identical\n");
	}
	else
	{
		printf("Tree #1 and tree #3 are different\n");
		StructLeftPrint(tree1, 0);
		StructLeftPrint(tree3, 0);
	}

	printf("\nComparing tree #2 to tree #3\n");
	if (check(tree2, tree3))
	{
		printf("Tree #2 and tree #3 are identical\n");
	}
	else
	{
		printf("Tree #2 and tree #3 are different\n");
		printf("Tree #2 structure:\n");
		StructLeftPrint(tree2, 0);
		printf("Tree #3 structure:\n");
		StructLeftPrint(tree3, 0);
	}
	return 0;
}
