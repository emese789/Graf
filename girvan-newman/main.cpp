#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ifstream ifs("elek.txt");
    int nodeCount, edgeCount;
    ifs>>nodeCount>>edgeCount;

    vector<pair<pair<int, int>, int>> edges;
    edges.resize(edgeCount);
    vector<vector<int>> sz;
    sz.resize(nodeCount);

    int l, r;
    for (int i = 0; i < edgeCount; i++)
    {
        ifs>>l>>r;
        l--;
        r--;
        edges[i].first.first = l;
        edges[i].first.second = r;
        sz[l].push_back(r);
        sz[r].push_back(l);
    }

    int orgEdgeCount = edgeCount;
    for (int remEdges = 0; remEdges < orgEdgeCount; remEdges++)
    {
        for (int i = 0; i<edgeCount; i++)
            edges[i].second = 0;

        for (int startNode = 0; startNode < nodeCount; startNode++)
        {
            vector<bool> visited;
            visited.resize(nodeCount);
            for (int i = 0; i < nodeCount; i++)
                visited[i] = false;


            queue<int> nodeQueue;
            nodeQueue.push(startNode);
            visited[startNode] = true;

            while (!nodeQueue.empty())
            {
                int cur = nodeQueue.front();
                nodeQueue.pop();

                for (int i = 0; i < sz[cur].size(); i++)
                {
                    int target = sz[cur][i];
                    if (visited[target] == 0)
                    {
                        visited[target] = 1;
                        nodeQueue.push(target);

                        for (int f = 0; f < edges.size(); f++)
                        {
                            if ((edges[f].first.first == cur && edges[f].first.second == target) ||
                                (edges[f].first.second == cur && edges[f].first.first == target))
                                edges[f].second++;
                        }
                    }
                }

            }

        }

        int selection = 0;
        for (int i = 1; i < edges.size(); i++)
        {
            if (edges[i].second > edges[selection].second)
                selection = i;
        }

        cout<<edges[selection].first.first+1<<"-"<<edges[selection].first.second+1<<" removed\n";
        edges[selection] = edges[edges.size()-1];
        edges.pop_back();
        edgeCount--;

    }
}
