#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "include/graph.h"

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}
void Graph::addEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v); // 对于无向图，边是双向的
}

//广度优先遍历
void Graph::BFS(int startVertex)
{
    std::vector<bool> visited(vertices, false);//记录顶点是否被访问
    std::queue<int> q; //用于BFS的队列

    visited[startVertex] =true; // 记录顶点是否被访问过
    std::cout << "BFS starting from vertex " << startVertex << ": ";
    q.push(startVertex);
    while (!q.empty()) 
    {
        int currentVertex = q.front();
        std::cout<<currentVertex<<" ";
        q.pop();

        //遍历当前顶点的所有邻接顶点
        for(int neighbor: adjacencyList[currentVertex])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    std::cout << std::endl;

}


int main() 
{
    //创建一个包含5个顶点的图
    Graph graph(5);
    
    //添加边
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    // 从第一个顶点开始进行广度优先遍历
    graph.BFS(0);
    return 0;
}