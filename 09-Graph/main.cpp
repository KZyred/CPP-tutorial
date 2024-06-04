#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    void printGraph()
    {
        unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
        while (kvPair != adjList.end())
        {
            cout << kvPair->first << ": [";
            unordered_set<string>::iterator edge = kvPair->second.begin();
            bool first = true;
            while (edge != kvPair->second.end())
            {
                if (!first)
                {
                    cout << ", ";
                }
                cout << *edge;
                edge++;
                first = false;
            }
            cout << "]" << endl;
            kvPair++;
        }
    }

    //   +=====================================================+
    //   |               WRITE YOUR CODE HERE                  |
    //   | Description:                                        |
    //   | - This method adds a vertex to the graph.           |
    //   | - It checks if the vertex already exists.           |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   | - Returns true if vertex added, false otherwise.    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Utilizes unordered_map for adjacency list.        |
    //   | - 'adjList' holds the graph data.                   |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    bool addVertex(string vertex)
    {
        // cách 1:
        // if (adjList.find(vertex) != adjList.end())
        // {
        //     return false;
        // }
        // adjList.insert({vertex, {}});
        // return true;

        // cách 2:
        if (adjList.count(vertex) == 0)
        {
            adjList[vertex]; // chỗ này hơi khó hiểu
            return true;
        }
        return false;
    }

    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method adds an edge between vertex1 and      |
    //   |   vertex2 in the graph.                             |
    //   | - Checks if both vertices exist in the graph.       |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   | - Returns true if edge is successfully added.       |
    //   | - Returns false if either vertex does not exist.    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses 'adjList' to hold the graph's adjacency list.|
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    bool addEdge(string vertex1, string vertex2)
    {
        if ((adjList.count(vertex1) == 0) || (adjList.count(vertex2) == 0))
        {
            return false;
        }
        adjList[vertex1].insert(vertex2);
        adjList[vertex2].insert(vertex1);
        return true;
    }
    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method removes an edge between vertex1 and   |
    //   |   vertex2 in the graph.                             |
    //   | - Checks if both vertices exist in the graph.       |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   | - Returns true if edge is successfully removed.     |
    //   | - Returns false if either vertex does not exist.    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses 'adjList' to update the graph's adjacency    |
    //   |   list.                                             |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    bool removeEdge(string vertex1, string vertex2)
    {
        if ((adjList.count(vertex1) == 0) || (adjList.count(vertex2) == 0))
        {
            return false;
        }
        adjList[vertex1].erase(vertex2);
        adjList[vertex2].erase(vertex1);
        return true;
    }
    // cách 1
    bool removeVertexNG(string vertex)
    {
        if (adjList.count(vertex) != 0)
        {
            for (auto i : adjList[vertex]) // sẽ xảy ra lỗi chiều dày của unordered_set -> ko dùng cách này
            {
                adjList[vertex].erase(i);
            }
            adjList.erase(vertex);
            return true;
        }
        return false;
    }
    // cách 2
    bool removeVertex(string vertex)
    {
        if (adjList.count(vertex) != 0)
        {
            for (auto otherVertex : adjList.at(vertex))
            {
                adjList.at(otherVertex).erase(vertex);
            }
            adjList.erase(vertex);
            return true;
        }
        return false;
    }
};
