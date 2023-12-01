#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <stack> //深度优先搜索
#include <queue> //广度优先搜索
#include <vector> //二维邻接表存储
class Graph
{
public:
    Graph(int vertices); // 构造函数，初始化顶点数和邻接表

    void addEdge(int v, int w); // 添加边，无向图的边是双向的

    void DFS(int startVertex); // 执行深度优先遍历

    void BFS(int startVertex); // 执行广度优先遍历

private:
    int vertices;                                // 顶点数
    std::vector<std::vector<int>> adjacencyList; // 邻接表
};

#endif // GRAPH_H