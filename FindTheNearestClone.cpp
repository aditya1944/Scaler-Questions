#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
long bfs(long currentVertex, vector<bool> &visited, vector<vector<long> >&adjacencyList, unordered_set<long> &se){
    queue<long> q;
    long minDistance = 1;
    q.push(currentVertex);
    while(!q.empty()){
        currentVertex = q.front();
        visited[currentVertex] = true;
        q.pop();
        for(auto adjacentVertex: adjacencyList[currentVertex]){
            if(!visited[currentVertex]){
                if(se.find(adjacentVertex)!=se.end()){
                    return minDistance;
                }
                q.push(adjacentVertex);
            }            
        }
        ++minDistance;
    }
    return INT_MAX;
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    long totalEdges = graph_from.size();
    unordered_set<long> se;
    int minDistance = INT_MAX;
    //make adjacency List
    vector<vector<long> > adjacencyList(graph_nodes+1);
    for(long index = 0;index<totalEdges;++index){
        if(ids[graph_from[index]-1]==val){
            se.insert(graph_from[index]);
        }
        if(ids[graph_to[index]-1]==val){
            se.insert(graph_to[index]);
        }
        adjacencyList[graph_from[index]].push_back(graph_to[index]);
    }
    //adjacencyList is ready
    //apply bfs on the node which has color equal to val;
    //se has all vertex which has same color equal to val;
    for(int currentVertex: se){
        //apply bfs on currentVertex
        vector<bool> visited(graph_nodes+1,false);
        int currentDistance = bfs(currentVertex, visited, adjacencyList,se);
        minDistance = min(minDistance, currentDistance);
    }
    if(minDistance==INT_MAX){
        return -1;
    }
    cout<<minDistance;
    return minDistance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
