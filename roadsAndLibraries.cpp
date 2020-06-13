#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
    int val;
    int rank;
    Node *parent;
};
class DisJointSet{
    private:
        unordered_map<int,Node*> hash;
        Node* findSet(Node * node){
            if(node->parent == node){
                return node;
            }
            node->parent = findSet(node->parent);
            return node->parent;
        }
    public: 
        void MakeSet(int data){
            Node * node = new Node();
            node->val = data;
            node->parent = node;
            node->rank = 0;
            hash.insert(make_pair(data,node));
        }
        void Union(int d1, int d2){
            Node *n1 = hash[d1];
            Node *n2 = hash[d2];

            Node *p1 = findSet(n1);
            Node *p2 = findSet(n2);

            if(p1==p2){
                return ;
            }
            if(p1->rank>=p2->rank){
                p1->rank = (p1->rank==p2->rank)?p1->rank+1:p1->rank;
                p2->parent = p1;
            }
            else{
                p1->parent = p2;
            }
        }
        int findSet(int data){
            return findSet(hash[data])->val;
        }
};

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int> > cities) {
    //no. of cities is n;
    if(c_road>c_lib){
        return n*c_lib;
    }
    int returnValue = 0;
    //find no. of connected components
    //make adjacency List
    int noVisitedNodes = 0;
    //vector<bool> visited(n,false);
    DisJointSet *se = new DisJointSet();
    for(int vertex = 1;vertex<=n;++vertex){
        se->MakeSet(vertex);
    }
    for(int index = 0;index<cities.size();++index){
        int fromVertex = cities[index][0];
        int toVertex = cities[index][1];
        if(se->findSet(fromVertex)!=se->findSet(toVertex)){
            returnValue+=c_road;
            se->Union(fromVertex, toVertex);
        }
    }
    //now check how many sets are there
    unordered_set<int> parent;
    for(int vertex = 1; vertex<=n;++vertex){
        parent.insert(se->findSet(vertex));
    }
    returnValue+=(parent.size()*c_lib);
    cout<<returnValue;
    return returnValue;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
