
#include <stdio.h>
#include <string.h>

#define N 5

char *nodes[N] = {
    "Root",
    "Documents",
    "Downloads",
    "FileA.txt",
    "FileB.txt"
};

int graph[N][N] = {
    {0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int visited[N];
int found;

int getNodeIndex(char target[]) {
    int i;

    for (i = 0; i < N; i++) {
        if (strcmp(nodes[i], target) == 0)
            return i;
    }

    return -1;
}

void BFS(int start, char target[]) {
    int queue[N];
    int front = 0, rear = 0;
    int i, current;

    memset(visited, 0, sizeof(visited));
    found = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        current = queue[front++];
        printf("%s ", nodes[current]);

        if (strcmp(nodes[current], target) == 0)
            found = 1;

        for (i = 0; i < N; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nBFS: File found\n");
    else
        printf("\nBFS: File not found\n");
}

void DFS(int current, char target[]) {
    int i;

    visited[current] = 1;
    printf("%s ", nodes[current]);

    if (strcmp(nodes[current], target) == 0)
        found = 1;

    for (i = 0; i < N; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            DFS(i, target);
        }
    }
}

int main() {
    char target[50];
    int start = 0;

    printf("FILE SYSTEM USING BFS AND DFS\n");

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable nodes:\n");
    for (int i = 0; i < N; i++) {
        printf("%s\n", nodes[i]);
    }

    printf("\nStarting node: Root\n");
    printf("Enter target file or directory: ");
    scanf("%49s", target);

    if (getNodeIndex(target) == -1) {
        printf("Target node does not exist in the graph.\n");
        return 0;
    }

    BFS(start, target);

    memset(visited, 0, sizeof(visited));
    found = 0;

    printf("\nDFS Traversal: ");
    DFS(start, target);

    if (found)
        printf("\nDFS: File found\n");
    else
        printf("\nDFS: File not found\n");

    return 0;
}
