// HR_Even_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct pair_number
{
	int a;
	int b;
};

class Graph
{
public:
	int N;
private:
	list<int> *adj;

private:
	void visit_from_node(int a, bool vis[], int& c)
	{
		vis[a] = true;
		c++;

		list<int>::iterator it;
		for (it = adj[a].begin(); it != adj[a].end(); it++)
		{
			if (!vis[*it])
				visit_from_node(*it, vis, c);
		}
	}

public:

	Graph(int n)
	{
		N = n;
		adj = new list<int>[N];
	}

	void addEdge(int a, int b)
	{
		adj[a].push_back(b);
	}

	int visit_from_edge(int a, int b)
	{
		bool* visited = new bool[N];
		
		for (int i = 0; i < N; i++)
			visited[i] = i == b;

		int count = 0;
		visit_from_node(a, visited, count);

		return count;
	}

};

int main(int argc, char **argv) {

	pair_number* connections;
	int N, M, node, other;

	cin >> N;
	cin >> M;

	connections = new pair_number[M];
	Graph* g = new Graph(N);

	for (int i = 0; i < M; i++)
	{
		cin >> node;
		cin >> other;

		connections[i].a = node - 1;
		connections[i].b = other - 1;
		
		g->addEdge(node - 1, other - 1);
		g->addEdge(other - 1, node - 1);
	}

	int node_count = 0;
	int cuts = 0;
	for (int i = 0; i < M; i++)
	{
		node_count = g->visit_from_edge(connections[i].a, connections[i].b);

		if (node_count % 2 == 0)
		{
			cuts++;
		}
	}

	cout << endl << cuts;

	int stop;
	cin >> stop;

	return 0;
}

