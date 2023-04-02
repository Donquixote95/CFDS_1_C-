#include <iostream>
#include <list>
#include <vector>

using namespace std;

// vertex를 verctor index 넘버와 같다고 가정하고 시작

// binary search tree, tree, graph를 백지에 써서 할 수 있을 정도가 되어야 한다.

/*
    Let's implement our class undi_graph that provides
    (1) BFS (2) DFS preorder (3) DFS postorder
*/ 

// Define undi_graph
class undi_graph {
    int vNum; //vertex 갯수
    vector<vector<int>> neighbors; // vertex를 integer로 나타내기로 했으므로 vector가 int가 될 수 밖에 없다. 
    // 위 두 개는 Private으로 둔다.

public:
    undi_graph(const int& num, const vector< vector<int> > & edges); // call by value 역할을 하면서도 copy가 필요없기 때문에, 그리고 함수 내에서 값을 바꾸면 안 되니까 const를 해줘야 한다. myVNum, myEdges 모두 바꿀 필요가 없다.
    void visitAction(const int& v); // v라는 vertex를 받아오면 v를 출력해주면 된다. 그리고 바꿀 필요가 없으니까 const

    void bfs(void);

    void dfs(const int& mode);
    void dfs_help(const int& mode, const int& v, vector<bool>& visited);
};

// Construct a graph using vertices and edges 
undi_graph::undi_graph(const int& num, const vector< vector<int> >& edges)
           : neighbors(num, vector<int>(0)) //vertex 갯수가 num 갯수만큼 있어야 한다, 각 list는 empty인 상태로 출력
            // 여기선 neighbors(10, vector<int>(0))이 되는데, 
            // vector<int>(0)이 10개 있는 list가 된다. 
            // vector<int>(0)은 dynamic array object which contains 0 element이다. 
           {
    vNum = num;
    printf("edges.size() = %d\n", edges.size());
    for (int i=0; i < edges.size(); i++){ //STL의 size() 함수는 컨테이너의 size를 return한다.
        neighbors[edges[i][0]].push_back(edges[i][1]); //edge가 여러개가 있는데, i 하나마다 edge 1개씩, edge는 vertex의 pair로 되어있는데, 
                                                       // 반대쪽 pair를 추가해준다.
        // if edges[i] is (u,v), add v to the u's neighbor list and
        //                       add u to the v's neighbor list
        neighbors[edges[i][1]].push_back(edges[i][0]); 
// initialization 없이 여기까지 하면 오류가 난다.
// neighbors는 아직 실체가 없기 때문이다. initialize를 해줘야 메모리 공간에 벡터가 잡힌다.
    }
}

/* Print the vertex on the screen */
void undi_graph::visitAction(const int& v){
    cout << v << " "; //빈 공간 하나를 놓아둬서 보기 편하게.
}

/* Visit all verticies in the graph with breadth-first search */
void undi_graph::bfs(void){
    // 아래 벡터는 bool을 hold할 수 있는 dynamic array object
    vector<bool> visited(vNum, false); //vNum은 this 포인터를 사용해서 직접 가져올 수 있다. graph의 멤버니까.
    // vNum의 갯수만큼 false가 담긴 dynamic array가 만들어진다.
    list<int> q;

    // for loop을 돌려야 disconnected된 node(vertex)도 방문할 수 있다.
    for (int v=0; v<vNum; v++){
        q.push_back(v);
        int currV;

        while (!q.empty()) { //doubly linked list.empty()를 하면, empty일 때 true, not empty일 때 false를 return한다.
            currV = q.front(); //return the first item
            q.pop_front(); //remove the first item

//visited vector의 currV 값으로 index하면 
//초기 가정에 의해 current vertex(node)의 True, False 값이 return된다.
            if (!visited[currV]){ 
                visited[currV] = true; //vector 내 값을 true로 바꿔준다.
                visitAction(currV); //currV 값을 print한다.

            // Range-based for loop
 // n은 의미가 있는 variable이 아니라 range-based for loop을 돌리기 위한 것.
 // 아래에서는 neighbors[currV] 내 값들을 doubly linked list인 q에 push_back 해준다.
                for (const int& n : neighbors[currV]){ //n을 for loop 내부에서 바꾸지 않겠다.
                    q.push_back(n);
                }
            }
        }
    }
}

// Visit all the vertices that are connected to the input vertex "v"
void undi_graph::dfs_help(const int& mode, const int& v, vector<bool>& visited){ // 앞에 두 개는 const를 붙이고 왜 visited를 안 붙였나? visited라는 vector는 바꿀 것이기 때문에.
    if (!visited[v]){
        visited[v] = true;
        if (mode == 0){
            visitAction(v);
        }
        // visit v's neighbors
        for (const int& n : neighbors[v]){
            dfs_help(mode, n, visited);
        }

        if (mode == 1){
            visitAction(v);
            }
        }
}

/* Visit all vertices in the graph with depth-first search */
void undi_graph::dfs(const int& mode){
    vector<bool> visited(vNum, false);

    for (int v=0; v<vNum; v++){
        dfs_help(mode, v, visited);
    }
}



// Graph Implementation using STL
int main(void){
    // Graph construction using 10 vectices
    int myVNum = 10;
    vector<vector<int>> myEdges{
        {0,1}, {1,4}, {1,5}, {2,3}, {4,6}, {5,6}, {5,7}, {6,9}, {7,8}
    };

    undi_graph myGraph(myVNum, myEdges);


    cout << "[BFS] ";       // Breadth First Search
    myGraph.bfs();
    cout << endl;

    cout << "[DFS preorder] ";       // Depth First Search - Preorder
    myGraph.dfs(0);
    cout << endl;

    cout << "[DFS postorder] ";       // Depth First Search - Postorder
    myGraph.dfs(1);
    cout << endl;
    
    return 0;
}

// myPair <int> myObject (100, 75);
    // cout<<myObject.getMax()<<"\n";

    // vector<int> v {1};
    // int a[2];
    // cout <<"&v = " << &v <<endl;
    // cout <<"&v[0] = " << &v[0] <<endl;
    // cout <<"&v[1] = " << &v[1] <<endl;
    // cout <<"&a = " << &a <<endl;
    // cout <<"&a[0] = " << &a[0] <<endl;
    // cout <<"&a[1] = " << &a[1] <<endl;