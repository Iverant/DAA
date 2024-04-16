#include<stdio.h>

int MAX;
int stack[100];
int top = -1;

void push(int vertex){
    stack[++top] = vertex;
}

int pop(){
    return stack[top--];
}

int isEmpty(){
    return top == -1;
}

void dfs(int vertex, int n, int adjMat[MAX][MAX], int visited[]){
    visited[vertex] = 1;
    int i;

    for(i = 0; i<n; ++i){
        if(adjMat[vertex][i] && !visited[i]){
            dfs(i, n, adjMat, visited);
        }
    }
    push(vertex);
}

void toposort(int n, int adjMat[MAX][MAX]){
    int visited[100] = {0};
    int i;

    for (i = 0; i<n; ++i){
        if(!visited[i]){
            dfs(i, n, adjMat, visited);
        }
    }
    printf("topological sort: \n");
    
    while (!isEmpty()) {
        printf("%d ", pop());
    }
}

int main(){
    int n , i , j;
     printf("Enter the number of vertices: ");
    scanf("%d", &MAX);
    int adjMatrix[MAX][MAX];

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < MAX; ++i) {
        for (j = 0; j < MAX; ++j) {
            scanf("%dc ", &adjMatrix[i][j]);
        }
    }
    toposort(MAX, adjMatrix);
    return 0;
}
