#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int value;
    struct Node *left,*right;
    int height;
};

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key)
{

    if (node == NULL)
        return(newNode(key));
    if (key < node->value)
        node->left  = insert(node->left, key);
    else if (key > node->value)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->value)
        return rightRotate(node);
    if (balance < -1 && key > node->right->value)
        return leftRotate(node);
    if (balance > 1 && key > node->left->value)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->value )
        root->left = deleteNode(root->left, key);
    else if( key > root->value )
        root->right = deleteNode(root->right, key);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
            free(temp);
        }
        else
        {
            struct Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    if (root == NULL)
      return root;
     root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

struct Node* search(struct Node* root, int key)
{
	struct Node* current=NULL;
	if(root==NULL)
		return NULL;
	if(root->value==key)
		return root;
	else if(key < root->value)
		current=search(root->left, key);
	else if(key > root->value)
		current=search(root->right, key);
	return current;
}

int main()
{
  struct Node *root = NULL,*temp;
 int n,x,check=1;  cout<<"Enter the nuber of nodes for the tree\n";
 cin>>n; cout<<"\nEnter the nodes\n";
 for(int i=0;i<n;i++){
	 cin>>x;
	 root = insert(root, x);
	}
    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);
    do{
    cout<<"\nEnter the operation to perform: 1=Insert 2=Delete 3=Search: ";
    cin>>x;
    int y;
    switch(x){
	case 1:
		cout<<"\n Enter the Number to insert: ";
		cin>>y;
		root = insert(root, y);
    		printf("Preorder traversal of the AVL tree after insertion is \n");
    		preOrder(root);
	break;
	case 2:
		cout<<"\n Enter the Number to delete: ";
		cin>>y;
		root = deleteNode(root, y);
    		printf("\nPreorder traversal after deletion of %d is \n",y);
		preOrder(root);
	break;
	case 3:
		cout<<"\n Enter the Number to Search: ";
		cin>>y;
		temp=search(root, y);
		if(temp)
			cout<<"\nNode found at height: "<<(floor(log2(n))+1-height(temp));
		else
			cout<<"\nNode not found";
	break;
	}
	cout<<"\nWant to continue then press 1 else 0: ";
	cin>>check;
    }
	while(check);
    return 0;}

