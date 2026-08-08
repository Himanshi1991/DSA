/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>

#define MAX 1000

int main() {
    int N;
    int queue[MAX], stack[MAX];
    int top = -1;

    // Input size
    scanf("%d", &N);

    // Input queue
    for (int i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }

    // Push all queue elements into stack
    for (int i = 0; i < N; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack and print
    for (int i = 0; i < N; i++) {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    for (int i = 0; i < N; i++) {
        printf("%d", queue[i]);

        if (i < N - 1)
            printf(" ");
    }

    return 0;
}