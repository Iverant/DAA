#include<stdio.h>

int MAX;
int Stack[100];
int top = -1;

void push(int vertex) {
    Stack[++top] = vertex;
}

int pop() {
    return Stack[top--];
}

int isEmpty() {
    return top == -1;
}

void DFS(int vertex, int n, int adjMatrix[MAX][MAX], int visited[]) {
    visited[vertex] = 1;
    int i;
    for (i = 0; i < n; ++i) {
        if (adjMatrix[vertex][i] && !visited[i]) {
            DFS(i, n, adjMatrix, visited);
        }
    }
    push(vertex);
}

void topologicalSort(int n, int adjMatrix[MAX][MAX]) {
    int visited[100] = {0};
    int i;
    for (i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFS(i, n, adjMatrix, visited);
        }
    }
    printf("Topological Sort: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &MAX);
    int adjMatrix[MAX][MAX];

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < MAX; ++i) {
        for (j = 0; j < MAX; ++j) {
            scanf("%dc ", &adjMatrix[i][j]);
        }
    }
    topologicalSort(MAX, adjMatrix);
    return 0;
}