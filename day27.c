/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find a node with given value
struct Node* findNode(struct Node *head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

// Get length of linked list
int getLength(struct Node *head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection point
struct Node* getIntersectionNode(struct Node *head1, struct Node *head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    if (len1 > len2) {
        diff = len1 - len2;
        while (diff--)
            head1 = head1->next;
    } else {
        diff = len2 - len1;
        while (diff--)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, x;

    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head1, x);
    }

    scanf("%d", &m);

    int second[m];

    for (i = 0; i < m; i++)
        scanf("%d", &second[i]);

    // Build second list.
    // If a value exists in first list, connect from that node onward.
    for (i = 0; i < m; i++) {
        struct Node *intersect = findNode(head1, second[i]);

        if (intersect != NULL) {
            if (head2 == NULL)
                head2 = intersect;
            else {
                struct Node *temp = head2;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = intersect;
            }
            break;
        } else {
            insertEnd(&head2, second[i]);
        }
    }

    struct Node *ans = getIntersectionNode(head1, head2);

    if (ans)
        printf("%d\n", ans->data);
    else
        printf("No Intersection\n");

    return 0;
}