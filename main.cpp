#include <iostream>

/*
 *
 *  SORRY FOR SIDE EFFECTS :)
 *
 *  algorithm did just for fun
 *
 */

int n;

bool* used;
bool** graph;

void dfs(int top) {
    used[top] = true;

    for (int i = 0; i < n; i++)
        if (graph[top][i] && !used[i]) {
            std::cout << i + 1 << " ";
            dfs(i);
            std::cout << std::endl;
        }
}

int main() {
    std::cout << "Enter count of tops: ";
    std::cin >> n;

    graph = new bool*[n];
    used = new bool[n]{};

    std::cout << "Enter matrix:\n";

    for (int i = 0; i < n; i++) {
        graph[i] = new bool[n];
        used[i] = false;

        for (int j = 0; j < n; j++)
            std::cin >> graph[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            used[j] = false;

        std::cout << i + 1 << ":\n";

        dfs(i);
    }

    return 0;
}
