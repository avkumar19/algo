#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    void AddLink(int id)
    {
        next.push_back(id);
    }

public:
    vector <int> next;
};

void FindAllPathsAt(vector <Node> &all_nodes, int id, vector < vector<int> > &all_paths, vector <int> tmp)
{
    tmp.push_back(id);

    if(all_nodes[id].next.size() == 0) {
        all_paths.push_back(tmp);
        return;
    }

    for(size_t i=0; i < all_nodes[id].next.size(); i++) {
        vector <int> tmp2(tmp);
        FindAllPathsAt(all_nodes, all_nodes[id].next[i], all_paths, tmp2);
    }
}

void PrintPaths(const vector < vector<int> > &all_paths) 
{    
    for(size_t i=0; i < all_paths.size(); i++) {
        
        if(all_paths[i].size() == 1) {
            continue;
        }

        cout << all_paths[i][0];
    
        for(size_t j=1; j < all_paths[i].size(); j++) {
            cout << " -- > " << all_paths[i][j];
        }

        cout << endl;
    }
}

int main()
{	cout << "Enter the number of vertices" << endl;
	int V;
	cin >> V;
    vector <Node> all_nodes(V);
    for(int i = 0; i < V; i++){
    	cout << "enter the number of nodes connected to node "<< i << endl;
    	int num;
    	cin >> num;
    	cout << "Enter them" << endl;
    	while(num--){
    		int nd;
    		cin >> nd;
    		all_nodes[i].AddLink(nd);
		}
	}
    vector <int> tmp; 

    for(size_t i=0; i < all_nodes.size(); i++) {
        vector < vector<int> > all_paths;
        FindAllPathsAt(all_nodes, i, all_paths, tmp);

        cout << "All paths at node " << i << endl;
        PrintPaths(all_paths);
    }

    return 0;
}

