#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



// Function to create a new node with given data
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

struct TreeNode* create_tree(int data){
    struct TreeNode* new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if(new == NULL){
        perror("Mem allocation failed");
        exit(EXIT_FAILURE);
    }
    new ->val = data;
    new ->left = NULL;
    new ->right = NULL;
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct TreeNode* node)
{
    if (node == NULL)
        return;
 
    // First recur on left child
    printInorder(node->left);
 
    // Then print the data of node
    printf("%d ", node->val);
 
    // Now recur on right child
    printInorder(node->right);
}

// Given a binary tree, print its nodes in preorder
void printPreorder(struct TreeNode* node)
{
    if (node == NULL)
        return;
 
    // First print data of node
    printf("%d ", node->val);
 
    // Then recur on left subtree
    printPreorder(node->left);
 
    // Now recur on right subtree
    printPreorder(node->right);
}

/*
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
                                                                                                                                                                                                                                                                                                                 if(head ==NULL){ //we have found the last element in tree
        return true;
    }
    if(root ==NULL){
        return false;
    }
    if(head->val == root->val){
        if(rand() % 1 <0.5){
            isSubPath(head->next , root->left);
        }
        else{
            isSubPath(head->next , root->right);
        }
        
    }
    else{
        
            if(rand() % 1 <0.5){
            isSubPath(head , root->left);
        }
        else{
            isSubPath(head , root->right);
        }
        
            
        }
    return false;
}
// */
// bool found =0;

// bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    
//     if(head == NULL){
//         return true;
//     }
//     if (root == NULL){
//         return false;
//     }
//     if(root->val == head->val){
//         if(head->next ==NULL){
//             found=1;
//             return true; //we have reached the end of the loop
//         }
//         else{
//             isSubPath(head->next, root->left);
//             isSubPath(head->next, root->right);
//         }
//         //perform depth search
        
//     }
//     else{
// // Then recur on left subtree
//     isSubPath(head, root->left);   
//     isSubPath(head, root->right);
//     }
//     return found;
// }

    
    
    
bool check_match(struct ListNode* head, struct TreeNode* root){
    if(head ==NULL){ //solution has been found once the end of the list nodes has been reached
            return true;
        }
    if(root == NULL || root->val != head->val){ //if head doesn't match current node return false or if there is no current node
        return false;
    }
    return (check_match(head->next, root->left) || check_match(head->next, root->right)); //check the next child nodes along
}


bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (root == NULL){ //return false if there is no current node
        return false;
    }
    if(check_match(head, root)) {return true;} //perform search
    return (isSubPath(head, root->left) || isSubPath(head, root->right)); //check children for current head
}

int main(){
    //create the list
    struct ListNode *head = createNode(1);
    struct ListNode* second = createNode(4);
    struct ListNode* third = createNode(2);
    struct ListNode* fourth = createNode(6);
    struct ListNode* fith = createNode(8);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fith;

    //create the tree
    struct TreeNode* t_head = create_tree(1);
    struct TreeNode* t_second1 = create_tree(4);
    struct TreeNode* t_second2 = create_tree(4);
    struct TreeNode* t_third = create_tree(2);
    struct TreeNode* t_third2 = create_tree(2);
    struct TreeNode* t_fourth1 = create_tree(1);
    struct TreeNode* t_fourth2 = create_tree(6);
    struct TreeNode* t_fourth3 = create_tree(8);
    struct TreeNode* t_fith1 = create_tree(1);
    struct TreeNode* t_fith2 = create_tree(3);

    t_head->left = t_second1;
    t_head->right = t_second2;
    t_second1->left = t_third;
    t_third->left = t_fourth1;

    t_second2->left = t_third2;
    t_third2->left = t_fourth2;
    t_third2->right = t_fourth3;
    t_fourth3->left = t_fith1;
    t_fourth3->right = t_fith2;

    //printInorder(t_head);
    //printf("\n");
    printPreorder(t_head);
    printf("%d", isSubPath(head,t_head));


    return 0;
}