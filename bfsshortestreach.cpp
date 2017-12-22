//https://www.hackerrank.com/challenges/bfsshortreach/problem
#include <vector>
#include <limits>
#include <unordered_set>
#include <queue>
#define STD_DIST 6

int main() {
	int q;
	FILE* f = stdin;
//	FILE* f = fopen("bfsshortestreach1.in", "r");

	fscanf(f, "%i", &q);

	for (int i = 0; i < q; i++) { //run through all the queries
		int n, m;
		fscanf(f, "%d %d", &n, &m);

		std::vector<std::unordered_set<int>> adj(n + 1);
		std::vector<int> dist(n + 1); //everything is false by default
		std::fill(dist.begin(), dist.end(), std::numeric_limits<int>::max());
		std::queue<int> queue;

		for (int j = 0; j < m; j++) { //get all the edges
			int u, v;
			fscanf(f, "%d %d", &u, &v);
			adj[u].insert(v);
			adj[v].insert(u);
		}

		int s;
		fscanf(f, "%d", &s);
		//do bfs from s
		dist[s] = 0;
		queue.push(s);
		while (!queue.empty()) {
			int u = queue.front();
			queue.pop();

			for (int v : adj[u]) {
				if (dist[v] > dist[u] + STD_DIST) {
					dist[v] = dist[u] + STD_DIST;
					queue.push(v);
				}
			}

		}

		//print out
		for (int k = 1; k <= n; k++) {
			if (k != s) {
				if (dist[k] == std::numeric_limits<int>::max()) {
					printf("-1 ");
				} else {
					printf("%d ", dist[k]);
				}
			}
		}
		printf("\n");
	}


}
