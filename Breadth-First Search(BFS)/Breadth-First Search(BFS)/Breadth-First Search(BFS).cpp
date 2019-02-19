/*2019/02/19 EliMoon 
  Just Test Code
  Enjoy! */

/*BFS알고리즘은 그래프 탐색 알고리즘입니다. 
깊이 탐색방식(DFS)와 같이 사용되는 너비 탐색방식 알고리즘 입니다.
그래프의 인접 노드를 차례대로 방문하며 전체 탐색을 진행합니다.*/

#include "pch.h"
#include <iostream>
#include <vector> //vector를 사용하기 위함
#include <queue> //queue를 사용하기 위함

using namespace std;
#define g 8 //배열 정의

vector<int> list[g]; //그래프와의 연결관계 (그래프를 담기 위함)
int visit[g]; //노드 g를 방문한 적이 있으면 1이고 아니면 0 (방문한 노드를 담기 위함)


int main()
{
	queue<int> q;

	int node = 1; //시작노드를 1로
	q.push(node); //시작 노드를 큐에다 push
	visit[node] = 1; //시작노드를 방문했음

	while (!q.empty()) //큐가 비어있지 않을 동안 반복
	{

		int it = q.front(); //큐의 가장 앞애 있는 노드
		q.pop(); //25라인의 it를 큐에 pop

		for (int j = 0; j < list[it].size(); j++) //가장 인접한 노드중
		{
			int there = list[it][j];

			if (visit[it] == 0) //아직 방문하지 않은 노드를 큐에 push
			{
				q.push(it);
				visit[it] = 1;
			}
		}
		//반복~
	}
}


