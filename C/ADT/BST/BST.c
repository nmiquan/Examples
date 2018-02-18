#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct TreeNode *Tree;

Tree makeNode(int data) {
    Tree newNode = malloc(sizeof(TreeNode));
    assert(newNode != NULL);

    newNode->data = data;
    newNode->left = newNode->right = NULL; 

    return newNode;
}

Tree insertNode(Tree t, int data) {
    if (t == NULL) {
        return makeNode(data); 
    }

    if (data > t->data)
        t->right = insertNode(t->right, data);
    else if (data < t->data)
        t->left = insertNode(t->left, data);
    return t;
}

Tree freeTree(Tree t) {
    if (t != NULL) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

int TreeHeight(Tree t) {
    if (t == NULL) return 0;
    int hL = 1 + TreeHeight(t->left);    
    int hR = 1 + TreeHeight(t->right);
    if (hL > hR) return hL;
    else return hR;
}

Tree printTree(Tree t, int treeHeight, int depth) {
    if (t != NULL) {
        printTree(t->left, treeHeight, depth+1);

        int i;
        for (i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("%d\n", t->data);

        printTree(t->right, treeHeight, depth+1);
    } 
    else {
       int i;
       /* Adding a new line if the node is empty */
       printf("\n");

       /* add a newline for each external node associated to the empty node 
       // Given a empty node in the tree,
       // pow(2, treeHeight - depth + 1) = # external nodes of the tree 
                                           rooted at the given empty node 
       // in other words,
       the height of the tree rooted at the given empty node  */

       //for (i = 0; i < pow(2, treeHeight - depth + 1) - 1; i++)  
       //    printf("#\n");

    }
}

int TreeNumNodes(Tree t) {
    if (t != NULL) {
        return 1 + TreeNumNodes(t->left) + TreeNumNodes(t->right);
    } else return 0;
}

Tree selectNode(Tree t, int n) {
    // select the nth largest item in a tree with N nodes
    // 0-based index
    if (t != NULL) {
        // find the number of nodes that are smaller than the current
        int numNodesL = TreeNumNodes(t->left); 
        if (n == numNodesL) return t; 
        // look into tree->right if there are not enough nodes that are smaller than the current node
        // that is looking for node with larger key 
        // n is transformed by (n-numNodesL-1), that is, the number of smaller nodes needed
        // to find the nth node in the right tree
        else if (n > numNodesL) 
            return selectNode(t->right, n-numNodesL-1);
        // if current node has more smaller nodes than needed
        // look into tree->left
        else if (n < numNodesL)
            return selectNode(t->left, n);
    } else return NULL;
}

Tree rotateRight(Tree t) {
    if (t != NULL && t->left != NULL) {
        //Tree temp1 = t->left->right;
        //Tree temp2 = t->left;
        //t->left->right = t;
        //t->left = temp1;
        //printTree(t, TreeHeight(t), 0);
        //printf("--------------\n");
        //t = temp2;
        //return t;

        Tree temp = t->left;
        t->left = t->left->right;
        temp->right = t;
        //printf("Rotate Right--------------\n");
        //printTree(temp, TreeHeight(temp), 0);
        return temp;
    } else return t;
}

Tree rotateLeft(Tree t) {
    if (t == NULL && t->right == NULL) 
        return t;
    Tree temp = t->right;
    t->right = t->right->left;
    temp->left = t;
    //printf("Rotate Left--------------\n");
    //printTree(temp, TreeHeight(temp), 0);
    return temp;
}

Tree insertAVL(Tree t, int data) {
    if (t == NULL) {
        return makeNode(data); 
    }
    
    if (data == t->data) return t; 

    else if (data > t->data)
        t->right = insertAVL(t->right, data);
    else if (data < t->data)
        t->left = insertAVL(t->left, data);
    
    int hL = TreeHeight(t->left);
    int hR = TreeHeight(t->right);

    if ((hL - hR) > 1) {
    //    //if (t->left->right != NULL)
    //    //    t->left->right = rotateLeft(t->left->right);
        if (data > t->left->data)
            t->left = rotateLeft(t->left);
        t = rotateRight(t);
    }
    else if ((hR - hL) > 1) {
    //    //if (t->right->left != NULL)
    //    //    t->right->left = rotateRight(t->right->left);
        if (data < t->right->data)
            t->right = rotateRight(t->right);
        t = rotateLeft(t);
    }

    return t;
}

Tree _deleteNode(Tree t) {
    // find the left most node in the right subtree of deleting node
    // replace the found node with its right child

    if (t->left != NULL) {
        if (t->left->left == NULL) { 
            Tree temp = t->left;
            t->left = t->left->right; 
            return temp;
        }
        else 
            return _deleteNode(t->left);
    } else return NULL;
}

Tree deleteNode(Tree t, int data) {
    if (t == NULL) return t;

    if (t != NULL) {
        if (data > t->data)
            t->right = deleteNode(t->right, data);
        else if (data < t->data) 
            t->left = deleteNode(t->left, data);
        else {
            if (t->left != NULL && t->right == NULL){
                Tree temp = t; 
                t = t->left;
                temp->left = NULL;
                freeTree(temp);
                return t;
            } else if (t->right != NULL && t->left == NULL) {
                Tree temp = t;
                t = t->right;
                temp->right = NULL;
                freeTree(temp);
                return t;
            } else if (t->right == NULL && t->left == NULL) {
                freeTree(t);
                t = NULL;
                return t;
            } else {
                // traverse inorder down t->right
                // find the left most node of t->right
                // replace left pointer of this node's parent by
                // this node's right child
                // assign t->left to this node's left pointer
                // assign t->right to this node's right pointer
                Tree temp = _deleteNode(t->right); 
                if (temp != NULL) {
                    temp->left = t->left;
                    temp->right = t->right;
                    free(t);
                    t = NULL;
                } else {
                    t->right->left = t->left;
                    temp = t->right;
                    free(t);
                    t = NULL;
  
                }
                return temp;
            }
        }
    }
}

Tree deleteAVL(Tree t, int data) {
    if (t != NULL) {
        if (data == t->data) {
            t = deleteNode(t, data);
                if (t != NULL) { 
                int hL = TreeHeight(t->left);
                int hR = TreeHeight(t->right);
                if ((hL - hR) > 1) {
                    if (data > t->left->data)
                        t->left = rotateLeft(t->left);
                    t = rotateRight(t);
                } else if ((hR - hL) > 1) {
                    if (data < t->right->data)
                        t->right = rotateRight(t->right);
                    t = rotateLeft(t);
                }
            }

            return t;
        }

        else if (data < t->data)
            t->left = deleteAVL(t->left, data);
        else
            t->right = deleteAVL(t->right, data);
    } else return t; 
}

Tree partition(Tree t, int n) {
    // bring the node nth to become the root of the tree
    if (t != NULL) {
        int numNodesL = TreeNumNodes(t->left);
        if (numNodesL == n) return t; 
        else if (numNodesL < n) {
            t->right = partition(t->right, n-numNodesL-1);
            t = rotateLeft(t);
            return t;
            }
        else if (numNodesL > n) {
            t->left = partition(t->left, n);
            t = rotateRight(t); 
            return t;
        }
    } else return NULL;
}

Tree rebalance(Tree t) {
    if (t != NULL) {
        int numNodes = TreeNumNodes(t);
        if (numNodes == 2) return t;
        t = partition(t, numNodes/2);
        printf("------------------\n");
        printTree(t, TreeHeight(t), 0);
        printf("++++++++++++++++++\n");
        t->left = rebalance(t->left);
        t->right = rebalance(t->right);
        return t;
    } return t;
}

Tree insertAtRoot(Tree t, int data) {
    if (t == NULL) {
        return makeNode(data);
    }
 
    //Tree newNode = makeNode(data);
    else if (data > t->data) {
        //newNode->right = t;
        //newNode = rotateLeft(newNode);
        t->right = insertAtRoot(t->right, data);
        printf("Before rotation-------------\n");
        printTree(t, TreeHeight(t), 0);
        t = rotateLeft(t);
    } else if (data < t->data) {
        //newNode->left = t;
        //newNode = rotateRight(newNode);
        t->left = insertAtRoot(t->left, data);
        printf("Before rotation-------------\n");
        printTree(t, TreeHeight(t), 0);
        t = rotateRight(t);
    }
    //return newNode;
    return t;
}

void main(void) {
    Tree aTree = NULL;
    int anInt;
    char aStr[256];

    // Why can't the while loop access aTree initialized here ?
    //int arr[8] = {200, 300, 250, 275, 310, 100, 150, 9};
    int arr[6] = {12,10,8,6,4,2};
    for (int i = 0; i < 6; i++) {
        aTree = insertAVL(aTree, arr[i]);
    }
    printf("\n");
    printTree(aTree, TreeHeight(aTree), 0);
    printf("-----------------\n");

    while (scanf("%s %d", aStr, &anInt) != EOF) {
        if (strcmp(aStr, "insert") == 0)
            aTree = insertNode(aTree, anInt); 
        else if (strcmp(aStr, "delete") == 0)
            aTree = deleteNode(aTree, anInt);
        else if (strcmp(aStr, "select") == 0)
            printf("%d\n", selectNode(aTree, anInt)->data);
        else if (strcmp(aStr, "partition") == 0)
            aTree = partition(aTree, anInt);
        else if (strcmp(aStr, "rebalance") == 0)
            aTree = rebalance(aTree);
        else if (strcmp(aStr, "insertAVL") == 0)
            aTree = insertAVL(aTree, anInt);
        else if (strcmp(aStr, "deleteAVL") == 0)
            aTree = deleteAVL(aTree, anInt);
        printf("+++++++++++++++++\n");
        printTree(aTree, TreeHeight(aTree), 0);
        printf("-----------------\n");
    }

    //aTree = deleteNode(aTree, arr[0]);
    //printf("+++++++++++++++++\n");
    //printTree(aTree, TreeHeight(aTree), 0);
    //printf("-----------------\n");
   
    //printf("test rotate right\n"); 
    //aTree = rotateRight(aTree);
    //printf("+++++++++++++++++\n");
    //printTree(aTree, TreeHeight(aTree), 0);
    //printf("-----------------\n");

    //printf("test rotate left\n"); 
    //aTree = rotateLeft(aTree);
    //printf("+++++++++++++++++\n");
    //printTree(aTree, TreeHeight(aTree), 0);
    //printf("-----------------\n");

    //while (scanf("%d", &anInt) != EOF) {
    //    aTree = insertAtRoot(aTree, anInt); 
    //    //printf("-----------------------\n");
    //    //printTree(aTree, TreeHeight(aTree), 0);
    //}

    printf("\n");
    printf("Tree Height: %d\n", TreeHeight(aTree));
    printf("Left Tree Height: %d\n", TreeHeight(aTree->left));
    printf("Right Tree Height: %d\n", TreeHeight(aTree->right));
    printf("Tree Num Nodes: %d\n", TreeNumNodes(aTree));
    //printTree(aTree, TreeHeight(aTree), 0);
}
