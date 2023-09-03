#include <stdio.h>
#include <stdlib.h>

struct edge {
    int u, v, cost;
};

typedef struct edge edge;

int find(int v, int parent[]) {
    if (parent[v] == -1)
        return v;
    return parent[v] = find(parent[v], parent);
}

int compare(const void* a, const void* b) {
    return ((edge*)a)->cost - ((edge*)b)->cost;
}

void kruskal(int n, edge e[], int m) {
    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = -1;

    int count = 0;
    int sum = 0;

    for (int i = 0; i < m; i++) {
        int u = e[i].u;
        int v = e[i].v;

        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if (parent_u != parent_v) {
            printf("%d -- %d\t%d\n", u, v, e[i].cost);
            count++;
            sum += e[i].cost;
            parent[parent_u] = parent_v;

            if (count == n - 1)
                break;
        }
    }

    printf("\nTotal cost: %d\n", sum);
}

int main() {
    int n, m;
    printf("Enter the number of vertices (houses): ");
    scanf("%d", &n);

    printf("Enter the number of edges (water pipe connections): ");
    scanf("%d", &m);

    edge e[m];
    printf("Enter the details of each edge (source vertex, destination vertex, cost):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].cost);
    }

    // Sort the edges in ascending order based on cost
    qsort(e, m, sizeof(edge), compare);

    printf("\nThe minimum spanning tree edges are:\n");
    printf("Edge\tCost\n");
    kruskal(n, e, m);

    return 0;
}