#include <iostream>
#include "include/BitBoard.hpp"
#include "include/Functions.hpp"
#include "include/Othello.hpp"
using namespace std;

int main()
{
    string n;
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
            while(InArry(canput,InputID(n))==false){
                cout<<"cannot put"<<endl;
                cin >> n;
            }
            bb.ReverseTurnBlack(InputID(n));
            bb.Score();
            bb.Show();
        }
        if(bb.canOnWhite()!=0){
            cout<<"TurnWhite"<<endl;
            cin >> n;
             while(InArry(canput,InputID(n))==false){
                cout<<"cannot put"<<endl;
                cin >> n;
            }
            bb.ReverseTurnWhite((InputID(n)));
            bb.Score();
            bb.Show();
        }
    }
    if(bitCount(bb.Black)>bitCount(bb.White)){
        cout<<"Black Win!"<<endl;
    }else if(bitCount(bb.White)>bitCount(bb.Black)){
        cout<<"White Win!"<<endl;
    }else{
        cout<<"Draw"<<endl;
    }
    return 0;
}                       
