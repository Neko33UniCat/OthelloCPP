#ifndef Brain_hpp
#define Brain_hpp
#include "BitBoard.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


class Gene_A
{
public:
	double a;
	double b;
	double c;
	double k;
	Gene_A(double pa = 0.0,double pb = 0.0,double pc = 0.0,double pk = 0.0);
};
Gene_A::Gene_A(double pa,double pb,double pc ,double pk){
	a = pa;
	b = pb;
	c = pc;
	k = pk;
}
class Brain_A
{
	public:
		double Scoreing(BitBoard board);
		Brain_A();	
		Gene_A gene();
};
#endif /* Brain_hpp */