// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 8

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode = 0, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}
int main() {
 int n, u;
  n = 8;
    
    int Graph[MAX][MAX] = {
    // 0 1 2 3 4 5 6 7
      {0, 8, 9, 11, 0, 0, 0, 0},
        {0, 0, 0, 0, 10, 0, 0, 0}, //화살표 방향 잘보자
        {0, 6, 0, 3, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 8, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 12, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 0}
    };

 /* 결과 보면 0 노드에서 1까지 가는 최단 거리 : 8
  0 노드에서 2까지 가는 최단 거리 : 9
  0 노드에서 3까지 가는 최단 거리 : 11 .. 등 이렇게 나타낼 수 있다 */

  u = 0; //시작 노드
  Dijkstra(Graph, n, u);

  return 0;
}
