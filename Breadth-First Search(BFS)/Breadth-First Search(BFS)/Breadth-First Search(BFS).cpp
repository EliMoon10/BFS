/*2019/02/19 EliMoon : Update 2019/03/29
  Just Test Code
  Enjoy! */

/*BFS알고리즘은 그래프 탐색 알고리즘입니다. 
깊이 탐색방식(DFS)와 같이 사용되는 너비 탐색방식 알고리즘 입니다.
그래프의 인접 노드를 차례대로 방문하며 전체 탐색을 진행합니다.*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using index_t = std::vector<int>::size_type;

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for (vector<int>::size_type i = 0; i < graph[tmp].size(); i++) {
			if (check[graph[tmp][i]] == false) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}

}

int main() {

	int n = 2;
	int m = 3;
	int start = 1;
	//cin >> n >> m >> start;

	vector<int> graph[n + 1];
	bool check[n + 1];
	fill(check, check + n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// Sorting사용 이유: 차후 node를 순차적으로 접근해야하기 때문
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	//bfs
	bfs(start, graph, check);
	printf("\n");

	return 0;
}
