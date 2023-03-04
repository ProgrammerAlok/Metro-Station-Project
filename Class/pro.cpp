
#include "Station.cpp"
#include<vector>
#include <fstream>

using namespace std;

class Graph
{
private:
    int v_no, e_no;
    int **arr;


protected:
    void allPath(vector<vector<Station>>, int, int, bool*, string);

    vector<vector<int>> getAdjList();

    vector<string> getStationList();

    vector<Station> getObjectList(vector<string>);

    vector<pair<int, int>> getEdgeList();

    vector<vector<Station>> getAdjListOfStation();
    

public:
    Graph();
    void createGraph(int, int);
    void printAllPath(int);
    void printAllPath(int, int);
    ~Graph();

    void printStationList();



    
};

void Graph::printStationList()
{
    int f = 0;
    cout << "\n ::::::::::: ALL STATION LIST ARE  GIVEN BELOW :::::::::::  \n" <<  endl;
    cout << "    Station Code    " << "     " << "    Station Name     " <<  endl;
    cout << "--------------------" << "     " << "---------------------" <<  endl;
    for(auto i : getStationList()) {
        cout << "         " << f++ << "          " << "          " << i << endl;
        cout << "-------------------------------------------------------" <<  endl;
    }
}


void Graph::allPath(vector<vector<Station>> a, int src, int dest, bool vis[], string s)
{

    if(src==dest){
        cout << " " << s << " " << endl;
        return;
    }

    vis[src] = true;

    for(Station i : a[src]){
        if(vis[i.getNo()] == false){
            allPath( a, i.getNo(), dest, vis, s + " -> " + i.getName() + " ( S.C: " + to_string(i.getNo()) + " ) "  ); 
        }       
    }

    vis[src] = false;

}


void Graph::printAllPath(int src)
{

    int i;

    vector<string> allStation = getStationList();

    vector<vector<Station>> adjList = getAdjListOfStation();
 
    string s = "\n\n\n  " + allStation[src] + " ( S.C: " + to_string(src) + " ) ";

    bool vis[v_no];

    for(i=0; i<v_no; i++)
        vis[i] = false;

    cout<<endl;
    cout<<endl;

    for(i=0; i<v_no; i++) {
        if(i != src)
            allPath(adjList, src, i, vis, s); // i === dest

        cout<<endl;
        cout<<endl;
    }


}

void Graph::printAllPath(int src, int dest)
{

    int i;

    vector<string> allStation = getStationList();

    vector<vector<Station>> adjList = getAdjListOfStation();
 
    string s = "\n\n\n  " + allStation[src] + " ( S.C: " + to_string(src) + " ) ";

    bool vis[v_no];

    for(i=0; i<v_no; i++)
        vis[i] = false;

    cout<<endl;
    cout<<endl;


    allPath(adjList, src, dest, vis, s); // i === dest

}

vector<vector<Station>> Graph::getAdjListOfStation()
{

    vector<Station> ObjList = getObjectList(getStationList());

    vector<vector<Station>> adjStation;

    vector<Station> t;

    int i, j;

    for(i=0; i<v_no; i++){
        adjStation.emplace_back(t);
    }

    for(i=0; i<v_no; i++){
        for(j=0; j<v_no; j++){
            if(arr[i][j] == 1){
                adjStation[i].emplace_back(ObjList[j]);
            }
        }
    }

    return adjStation;
}

/*
vector<vector<int>> Graph::getAdjList()
{
    int i, j;

    vector<vector<int>> v;

    vector<int> t;

    for(i=0; i<v_no; i++)
        v.emplace_back(t);


    for(i=0; i<v_no; i++){
        for(j=0; j<v_no; j++){
            if(arr[i][j]==1){
                v[i].emplace_back(j);
            }
        }
    }

    return v;
}
*/

void Graph::createGraph(int v, int e)
{
    // cout << "\n\n\n this is getobjlist. \n\n\n" ;

    v_no = v;
    e_no = e;

    vector<string> s = getStationList();

    vector<Station> objList = getObjectList(s);

    int i, j;

    arr = new int*[v_no];

    for(i=0; i<v_no; i++){
        arr[i] = new int[v_no];
    }

    //Station *tmp = new Station(-1, "none");

    for(i=0; i<v_no; i++){
        for(j=0; j<v_no; j++){
            arr[i][j] = 0;
        }
    }

    vector<pair<int, int>> edgeList = getEdgeList();

    for(i=0; i<e_no; i++){
        int p, q;

        //cout << "Enter the two vertex no :: " ;
        //cin >> p >> q;

        p = edgeList[i].first;
        q = edgeList[i].second;

        arr[p][q] = arr[q][p] = 1;
    }
    // cout << "\n this is create graph. \n" ;

    
}

vector<Station> Graph::getObjectList(vector<string> stationList)
{
    // cout << "\n\n\n this is getobjlist. \n\n\n" ;


    int i, n = stationList.size();

    vector<Station> ObjList;

    for(i=0; i<v_no; i++)
        ObjList.emplace_back( *(new Station(i, stationList[i])) );

    return ObjList;

}

vector<pair<int, int>> Graph::getEdgeList()
{
    // cout << "\n this is edgelist. \n" ;

    vector<pair<int, int>> edgeList;

    int a, b;

    ifstream in("../Resource/Edge_List.txt");    

    for (int i = 0; i < e_no; i++)
    {
        in>>a>>b;
        pair<int, int> p(a, b);
        edgeList.emplace_back(p);
    }

    in.close();

    return edgeList;

}


vector<string> Graph::getStationList()
{

    int i;

    string s;

    vector<string> stationName;

    ifstream in("../Resource/Station_Name_List.txt");

    for (i = 0; i < v_no; i++)
    {
        getline(in, s);
        stationName.emplace_back(s);
    }

    in.close();

    return stationName;

}

Graph::Graph()
{
    arr = NULL;
    v_no = e_no = 0;
}

Graph::~Graph()
{
    int i;
    for(i=0; i<v_no; i++)
        delete arr[i];
    delete [] arr;
}
