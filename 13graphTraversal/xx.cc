#include <iostream>

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
void Graph::DFS(int startVertex)
{
    std::vector<bool> visited(vertices, false);  // 记录顶点是否被访问过
    std::stack<int> stack; //用于DFS的栈

    visited[startVertex] = true;
    std::cout << "DFS starting from vertex " << startVertex << ": ";

    stack.push(startVertex);

    while(!stack.empty())
    {
        int currentVertex = stack.top();
        std::cout << currentVertex << " ";

        stack.pop();

        //遍历当前顶点的所有邻接顶点
        for(int neighbor: adjacencyList[currentVertex])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
    std::cout<<std::endl;
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
    // 从第一个顶点开始进行深度优先遍历
    graph.DFS(0);
    return 0;
}