#include <iostream>
#include "vector.h"

using namespace containers;
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	std::cout<<v.size()<<" "<<v.capacity()<<" "<<v[0]<<"\n";
	v.insert(v.begin()+1, 30);
	std::cout<<v.pop_back()<<" "<<v.pop_back()<<" "<<v.pop_back()<<"\n";
	return 0;
}