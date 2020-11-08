#include "gen_tree.h"

using namespace std;
using namespace tree_generator_by_ouuan;

void myOutputEdge(ostream& os, int u, int pa)
{
	os << u + 1 << ' ' << pa + 1 << ' ' << randint(1, 10) << endl;
}

int main()
{
	// cout << Tree("ch20,0al5,1,20") << endl;
	// cout << Tree("bi30,0sw20,30fl10,50") << endl;

	Tree t(100);
	cout << t << endl;

	return 0;
}