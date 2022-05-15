#include <iostream>

/*
 *
 *  SORRY FOR SIDE EFFECTS :)
 *
 *  algorithm did just for fun
 *
 */

int n;

int* used;
int** graph;

bool dfs(int top) {
    used[top] = 1;

    for (int i = 0; i < n; i++)
        if (i != top && graph[i][top] == 1 && used[i] == 0) {
            std::cout << i + 1 << " ";
            dfs(i);
        }

    std::cout << std::endl;

    return true;
}

int main() {
    std::cout << "Enter count of tops: ";
    std::cin >> n;

    graph = new int*[n];
    used = new int[n]{};

    std::cout << "Enter matrix:\n";

    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        used[i] = 0;

        for (int j = 0; j < n; j++)
            std::cin >> graph[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            used[j] = 0;

        std::cout << i + 1 << ":\n";

        dfs(i);
    }

    return 0;
}
