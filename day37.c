/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int value) {
    if (size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = size - 1;

    // Shift larger elements to the right
    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;
}

// Delete highest priority element (smallest)
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Peek highest priority element
void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[0]);
    }
}

int main() {
    int N, value;
    char op[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}