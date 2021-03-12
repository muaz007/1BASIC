#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }


    void addEdge(int v, int w);

    void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}


void Graph::greedyColoring()
{
    int result[V];


    result[0]  = 0;


    for (int u = 1; u < V; u++)
        result[u] = -1;
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;


    for (int u = 1; u < V; u++)
    {

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;


        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;

        result[u] = cr;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }


    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;
}




int main()
{   int m;
    int n;
    cout<<"enter the total number of meetings to be organised";
    cin>>m;
    cout<<"enter the number of distinct overlapping membership pairs";
    cin>>n;
    Graph g1(m);
    for(int i=1; i<=n ; i++){
    int k=0;
    int j=0;
    cout<<"provide the meeting number x";
    cin>>k;
    cout<<"provide another meeting number having overlapping membersip with x";
    cin>>j;
    g1.addEdge(k, j);
    }
    cout << "minimum number of hours required \n";
    g1.greedyColoring();


    return 0;
}
