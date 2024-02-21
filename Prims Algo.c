#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with the minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to calculate and print the minimum cost of the MST
void printMSTCost(int key[], int V) {
    int minCost = 0;
    for (int i = 1; i < V; i++) {
        minCost += key[i];
    }
    printf("Minimum cost of the Minimum Spanning Tree: %d\n", minCost);
}

// Function to implement Prim's algorithm for a given graph represented using adjacency matrix
void primMST(int graph[][100], int V) {
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut
    int mstSet[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include first vertex in MST
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update the key only if the graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMSTCost(key, V);
}

int main() {
    int V; // Number of vertices in the graph
    printf("Enter number of nodes: ");
    scanf("%d", &V);

    int graph[100][100]; // Assuming maximum size for the adjacency matrix

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V); // Find the Minimum Spanning Tree and print the minimum cost

    return 0;
}
