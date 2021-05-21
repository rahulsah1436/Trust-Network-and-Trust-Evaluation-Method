/*Trust evaluation Implementation in trust network considering 1000 nodes*/
#include <bits/stdc++.h>
#define ll long long int
#define MAXN 1000

using namespace std;

vector<int>adj[MAXN];
int visited[MAXN];
map<pair<int,int>,double>mp;
// Function for printing the found path in network
void printpath(vector<int>& path)
{
	cout<<"\nPath : ";
	int size = path.size();
	for (int i = 0; i < size-1; i++)
		cout << path[i] << " -> ";
	cout<<path[size-1]<<"\n";
}
double effective_trust(vector<int>& path)
{
	double T=0,Decay_rate=0.5;
	for(int i=0 ; i<path.size()-1 ; i++)
	{
		if(i==0)
			T=mp[{path[i],path[i+1]}];
		else
		{
			T*=mp[{path[i],path[i+1]}]*(1-Decay_rate);
			Decay_rate*=1.5;
		}
			
	}
	cout<<"Multiplicative Trust : "<<T<<"\n";
	int number_of_nodes=path.size();
	int path_length=number_of_nodes-1;
	cout<<"\nNumber of nodes : "<<number_of_nodes<<"\nPath Length : "<<path_length<<"\n";
	double Weight=(1-(path_length-2))/((number_of_nodes-1)*1.0);
	double ET=T*Weight*1.0;
	return ET;
}

/*Function to check if current vertex is already present in path*/
int isNotVisited(int x, vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		if (path[i] == x)
			return 0;
	return 1;
}

//function for finding paths in graph from source to destination
void Trust_Propagate_Algorithm(int src,int dst)
{
	/*create a queue which stores the paths*/
	queue<vector<int> > q;
	double propagative_trust=0; //average of effective trust of all the path from source to destination
	vector<int> path; //stores the path from soure to destination
	path.push_back(src);
	q.push(path);
	int count=0;
	while (!q.empty()) {
		path = q.front();
		q.pop();
		int last = path[path.size() - 1];

		// if last vertex is the desired destination then print the path
		if (last == dst)
		{
			count++;
			printpath(path);
			cout<<"\nEffective Trust of the path : "<<effective_trust(path)<<"\n";
			propagative_trust+=effective_trust(path);
		}
				

		// traverse to all the nodes connected to
		// current vertex and push new path to queue
		for (int i = 0; i < adj[last].size(); i++) {
			if (isNotVisited(adj[last][i], path)) {
				vector<int> newpath(path);
				newpath.push_back(adj[last][i]);
				q.push(newpath);
			}
		}
	}
	propagative_trust/=count*1.0;
	cout<<"\nPropagative Trust : "<<propagative_trust;
}

// driver program
int main()
{
	int number_of_nodes,edges;
	cout<<"Enter number of nodes in the network :";
	cin>>number_of_nodes;
	cout<<"\nEnter number of connections : ";
	cin>>edges;
	cout<<"\nEnter the edges : ";
	for(int i=0 ; i<edges ; i++)
	{
		cout<<"\nEdge-"<<(i+1)<<" : ";
		int a,b;
		cin>>a>>b;
		/*Randomly generated trust between two nodes*/
		double direct_trust=((rand()+1)%100)/100.0;
		cout<<"\nAssigned Weight ("<<a<<","<<b<<") : "<<direct_trust<<"\n";
		mp[{a,b}]=direct_trust;
		adj[a].push_back(b);
		//adj[b].push_back(a); //As we are considering directed graph as because if A trust B then B trust A may be false	
	}
	int src, dst; 
	cout<<"Enter the source(Trustor) and destination(Trustee) node : ";
	cin>>src>>dst;
	cout << "\nPath from source(Trustor) " << src
		<< " to destination(Trustee) " << dst << " are \n";
	Trust_Propagate_Algorithm(src, dst);
	cout << "\nPath from destination(Trustee) " << dst
		<< " to source(Trustor) " << src << " are \n";
	Trust_Propagate_Algorithm(dst,src);
	return 0;
}

