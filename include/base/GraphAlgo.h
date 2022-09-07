#include "stdafx.h"
/*///////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////Matrix///////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////
*/

class GraphAdjMatrix
{
public:
	GraphAdjMatrix( int numVertices );
	~GraphAdjMatrix();
private:
	bool** AdjMatrix;
	int numVertices;

	void AddEdge( int i, int j );
	void RemoveEdge( int i, int j );
	void PrintGraph();
};

GraphAdjMatrix::GraphAdjMatrix( int numVertices )
{
	std::cout << "Making Undirected Graph: " << numVertices << "x" << numVertices << std::endl;
	this->numVertices = numVertices;

	AdjMatrix = new bool*[numVertices];

	for( int i = 0; i < numVertices; i++ )
	{
		AdjMatrix[i] = new bool[numVertices];

		for( int j = 0; j < numVertices; j++ )
			AdjMatrix[i][j] = false;
	}

	this->PrintGraph();

	std::cout << "Added Edges : (0, 1) (0, 2) (1, 2) (2, 0) (2, 3)"  << std::endl;
	this->AddEdge(0, 1);
	this->AddEdge(0, 2);
	this->AddEdge(1, 2);
	this->AddEdge(2, 0);
	this->AddEdge(2, 3);
	this->PrintGraph();
}

GraphAdjMatrix::~GraphAdjMatrix()
{
	for( int i = 0; i < this->numVertices; i++ )
		delete [] AdjMatrix[i];

	delete [] AdjMatrix;
}

void GraphAdjMatrix::AddEdge( int i, int j )
{
	AdjMatrix[i][j] = true;
    AdjMatrix[j][i] = true;
}


void GraphAdjMatrix::RemoveEdge( int i, int j )
{
	AdjMatrix[i][j] = false;
    AdjMatrix[j][i] = false;
}

void GraphAdjMatrix::PrintGraph()
{
	for( int i = 0; i < this->numVertices; i++ )
	{
		std::cout << i << ": ";
		for( int j = 0; j < this->numVertices; j++ )
			std::cout << AdjMatrix[i][j] << " ";

		std::cout <<"\n";
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////LIST///////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////
*/

class GraphAdjList
{
public:
	GraphAdjList();
	~GraphAdjList();
private:
	std::map<int, std::list<int>> adjList;
	std::map<int , bool> visited;


	void AddEdge( int src, int dest );
	void PrintGraph();
	void GraphAdjList::DFS( int v );
};

GraphAdjList::GraphAdjList( )
{
	std::cout << "Added Edges : (0, 1) (0, 2) (1, 2) (2, 0) (2, 3)"  << std::endl;
	this->AddEdge(0, 1);
	this->AddEdge(0, 2);
	this->AddEdge(1, 2);
	this->AddEdge(2, 0);
	this->AddEdge(2, 3);
	
	this->PrintGraph();
	std::cout << "Depth First Traversal (starting from vertex 2): \n";
	//this->DFS( 2 );	// 2 0 1 3
	//this->DFS( 1 );	// 1 2 0 3
	std::cout << std::endl;
}

GraphAdjList::~GraphAdjList()
{
}

void GraphAdjList::AddEdge( int u, int v )
{
	adjList[u].push_back( v ); // add v in u's list
}

// DFS algorithm
void GraphAdjList::DFS( int v )
{
	// Mark curernt node as visited and print it
	//std::cout << "Stack Node->" << std::endl;
	visited[v] = true;

	std::cout << v << " ";

	// Explor as far as possible along the current branch
	std::list<int>::iterator itr;
	for( itr = adjList[v].begin(); itr != adjList[v].end(); ++itr )
	{
		if( visited[*itr] == false )
			DFS( *itr );
	}
}

void GraphAdjList::PrintGraph()
{
	std::cout << "Printing the Graph..." << std::endl; 
	for (auto const& itr : adjList)
	{
		for (int i : itr.second)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}