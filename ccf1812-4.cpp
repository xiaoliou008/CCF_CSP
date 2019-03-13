#include<iostream>
#include<map>
using namespace std;
int main()
{
	unsigned n, m, root;
	cin >> n >> m >> root;
	multimap<unsigned, pair<unsigned, unsigned>> arcs;
	map<unsigned, unsigned> nodes;
	for(unsigned i=0;i<m;i++)
	{
		unsigned v, u, t;
		cin >> v >> u >> t;
		pair<unsigned, unsigned> sides = {v, u};
		arcs.insert({t, sides});
		nodes[v]++;
		nodes[u]++;
	}
	bool not_smallest = true;
	auto riter = arcs.rbegin();
	unsigned maxt = 0;
	while(not_smallest && riter!=arcs.rend())
	{
		maxt = riter->first;
		unsigned v = riter->second.first, u = riter->second.second;
		if(nodes[v] > 1 && nodes[u] > 1){
			nodes[v]--;
			nodes[u]--;
			riter++;
		}
		else not_smallest = false;
	}
	cout << maxt;
	return 0;
}
