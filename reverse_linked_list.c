#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
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

// Function to print the elements of the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL; //create a pointer to previous element
    struct ListNode *current = head;
    struct ListNode *next;
    //struct ListNode *final;
    struct ListNode* newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(newNode == NULL){
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    if(head==NULL){ //case for when list is empty
        return NULL;
    }
    //create the tail node with value of first element pointing to NULL
    newNode->val = head->val;
    newNode->next = NULL; //point to previous element

    //Loop until the final node points to NULL
    while(current->next != NULL){
        //define the next node from the original list
        next = current->next;
        prev = current;
        current = next;

        //create a new node which points to previously created one
        struct ListNode* nextNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        nextNode->val = current->val; //give value of current element
        nextNode->next = newNode; //point to previous element

        //update previous reverse list node
        newNode = nextNode;
    }
    
    return newNode;
}



int main(){
    //create an example list
    // Create nodes
    struct ListNode* head = createNode(1);
    struct ListNode* second = createNode(2);
    struct ListNode* third = createNode(3);

     // Connect nodes to form a linked list
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    //test reverse function 
    printList(reverseList(head));

    return 0;


}