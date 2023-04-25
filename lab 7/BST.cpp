#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//search node
struct node *searchNode(struct node *node,int key){
    if(node == NULL) return NULL;
    else if(node -> key == key ) return node;
    else if(node -> key > key) return searchNode(node->left,key);
    else return searchNode(node->right,key);
}

// Inorder traversal
void traverseInOrder(struct node* root) {

    if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }

}

//creat a node
struct node* NNode(int value) {
    struct node* Nnode = (struct node*)malloc(sizeof(struct node));
    Nnode->key = value;
    Nnode->left = NULL;
    Nnode->right = NULL;

    return Nnode;
}
// Insert a node
// No repeating nodes
struct node* insertNode(struct node* node, int key) {

    if (node == NULL) {
        return NNode(key);
    }

    if (node->key < key) {
        node->right = insertNode(node->right, key);
    }

    else if (node->key > key) {
        node->left = insertNode(node->left, key);
    }

    return node;

}


// Deleting a node
//Find minimum key value of the tree
struct node* minValNode(struct node* node) {

    struct node* current = node;

    while (current && current->left != NULL) {
        current = current-> left;
    }

    return current;
}

// Deleting a node
struct node* deleteNode(struct node* root, int key) {

    if (root == NULL) {
        return root;
    }

    if (root->key > key) {
        root->left = deleteNode(root->left, key);
    }

    else if (root->key < key) {
        root->right = deleteNode(root->right, key);
    }

    else {

        if ((root->left == NULL) && (root->right == NULL)) {
            return NULL;
        }

        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }

    return root;

}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}

