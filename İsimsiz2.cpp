#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct intersectedNode {
    int data;
    int index1;
    int index2;
    struct intersectedNode* next;
};

struct intersectedNode* createIntersectedNode(int data, int index1, int index2) {
    struct intersectedNode* newNode = (struct intersectedNode*)malloc(sizeof(struct intersectedNode));
    newNode->data = data;
    newNode->index1 = index1;
    newNode->index2 = index2;
    newNode->next = NULL;
    return newNode;
}

struct intersectedNode* intersected_nodes(struct node* list1, struct node* list2) {
    struct intersectedNode* result = NULL;
    int index1 = 0, index2 = 0;
    while (list1 != NULL) {
        index2 = 0; 
        struct node* temp2 = list2;
        while (temp2 != NULL) {
            if (list1->data == temp2->data) {
                struct intersectedNode* newNode = createIntersectedNode(list1->data, index1, index2);
                newNode->next = result;
                result = newNode;
            }
            temp2 = temp2->next;
            index2++;
        }
        list1 = list1->next;
        index1++;
    }
    return result;
}

void append(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct node* list) {
    struct node* current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printIntersectedNodes(struct intersectedNode* list) {
    struct intersectedNode* current = list;
    while (current != NULL) {
        printf("%d %d %d\n", current->data, current->index1, current->index2);
        current = current->next;
    }
}

int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;

    int input;
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        append(&list1, input);
    }
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        append(&list2, input);
    }

    struct intersectedNode* result = intersected_nodes(list1, list2);
    if (result == NULL) {
        printf("-1\n");
    } else {
        printIntersectedNodes(result);
    }
    
    return 0;
}
