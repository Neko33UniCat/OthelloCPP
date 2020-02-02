#include <iostream>
#include "include/BitBoard.hpp"
#include "include/Functions.hpp"
using namespace std;

int main()
{
    int n;
    BitBoard bb;
    bb.Score();
    bb.Show();
    while(true){
        if((~(bb.Black | bb.White)) == (u_long)0) {
            break;
        }
        if(bb.canOnBlack()!=0){
            cout<<"TurnBlack"<<endl;
            cin >> n;
            bb.ReverseTurnBlack(n);
            bb.Score();
            bb.Show();
        }
        if(bb.canOnWhite()!=0){
            cout<<"TurnWhite"<<endl;
            cin >> n;
            bb.ReverseTurnWhite(n);
            bb.Score();
            bb.Show();
        }
    }
    return 0;
}                       
