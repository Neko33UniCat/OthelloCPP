#ifndef BitBoard_hpp
#define BitBoard_hpp
#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <vector>
#include "Functions.hpp"

using namespace std;
using u_long = unsigned long;

class BitBoard
{
private:
    /* data */
public:
    u_long Black;
    u_long White;
    int Turn; //0...Black,1...White,
    u_long canOnBlack();
    u_long canOnWhite();
    void ReverseTurnBlack(int id);
    void ReverseTurnWhite(int id);
    int canPut[64];
    void Show();
    void Score();
    BitBoard();
};


BitBoard::BitBoard()
{
    Black = 0b0000000000000000000000000000100000010000000000000000000000000000;
    White = 0b0000000000000000000000000001000000001000000000000000000000000000;
}

u_long BitBoard::canOnBlack(){
    u_long white = White;
    u_long black = Black;
    u_long blank = ~(white | black);
    u_long mobility = 0;
    u_long horizon_mask = 0x7e7e7e7e7e7e7e7e;
    u_long vertical_mask = 0x00FFFFFFFFFFFF00;
    u_long all_mask = 0x007e7e7e7e7e7e00;
    
    //右側の処理    (今置いてある黒石の右側でおける場所があるか)
    u_long w = white & horizon_mask;
    u_long t = w & (black >> 1);
    t |= w & (t >> 1);
    t |= w & (t >> 1);
    t |= w & (t >> 1);
    t |= w & (t >> 1);
    t |= w & (t >> 1);
    mobility |= blank & (t >> 1);
    
    //左側
    w = white & horizon_mask;
    t = w & (black << 1);
    t |= w & (t << 1);
    t |= w & (t << 1);
    t |= w & (t << 1);
    t |= w & (t << 1);
    t |= w & (t << 1);
    mobility |= blank & (t << 1);
    
    //下側
    w = white & vertical_mask;
    t = w & (black >> 8);
    t |= w & (t >> 8);
    t |= w & (t >> 8);
    t |= w & (t >> 8);
    t |= w & (t >> 8);
    t |= w & (t >> 8);
    mobility |= blank & (t >> 8);
    
    //上側
    w = white & vertical_mask;
    t = w & (black << 8);
    t |= w & (t << 8);
    t |= w & (t << 8);
    t |= w & (t << 8);
    t |= w & (t << 8);
    t |= w & (t << 8);
    mobility |= blank & (t << 8);
    
    //左下
    w = white & all_mask;
    t = w & (black >> 7);
    t |= w & (t >> 7);
    t |= w & (t >> 7);
    t |= w & (t >> 7);
    t |= w & (t >> 7);
    t |= w & (t >> 7);
    mobility |= blank & (t >> 7);
    
    w = white & all_mask;
    t = w & (black << 7);
    t |= w & (t << 7);
    t |= w & (t << 7);
    t |= w & (t << 7);
    t |= w & (t << 7);
    t |= w & (t << 7);
    mobility |= blank & (t << 7);
    
    w = white & all_mask;
    t = w & (black >> 9);
    t |= w & (t >> 9);
    t |= w & (t >> 9);
    t |= w & (t >> 9);
    t |= w & (t >> 9);
    t |= w & (t >> 9);
    mobility |= blank & (t >> 9);
    
    w = white & all_mask;
    t = w & (black << 9);
    t |= w & (t << 9);
    t |= w & (t << 9);
    t |= w & (t << 9);
    t |= w & (t << 9);
    t |= w & (t << 9);
    mobility |= blank & (t << 9);

    // ShowIDs(mobility);
    return mobility;
}
u_long BitBoard::canOnWhite(){
    u_long black = Black;
    u_long white = White;
    u_long blank = ~(white | black);
    u_long mobility = 0;
    u_long horizon_mask = 0x7e7e7e7e7e7e7e7e;
    u_long vertical_mask = 0x00FFFFFFFFFFFF00;
    u_long all_mask = 0x007e7e7e7e7e7e00;

    u_long b = black & horizon_mask;
    u_long t = b & (white >> 1);
    t |= b & (t >> 1);
    t |= b & (t >> 1);
    t |= b & (t >> 1);
    t |= b & (t >> 1);
    t |= b & (t >> 1);
    mobility |= blank & (t >> 1);

    b = black & horizon_mask;
    t = b & (white << 1);
    t |= b & (t << 1);
    t |= b & (t << 1);
    t |= b & (t << 1);
    t |= b & (t << 1);
    t |= b & (t << 1);
    mobility |= blank & (t << 1);  

    b = black & vertical_mask;  
    t = b & (white >> 8);
    t |= b & (t >> 8);
    t |= b & (t >> 8);
    t |= b & (t >> 8);
    t |= b & (t >> 8);
    t |= b & (t >> 8);
    mobility |= blank & (t >> 8);

    b = black & vertical_mask;  
    t = b & (white << 8);
    t |= b & (t << 8);
    t |= b & (t << 8);
    t |= b & (t << 8);
    t |= b & (t << 8);
    t |= b & (t << 8);
    mobility |= blank & (t << 8);

    b = black & all_mask;  
    t = b & (white >> 7);
    t |= b & (t >> 7);
    t |= b & (t >> 7);
    t |= b & (t >> 7);
    t |= b & (t >> 7);
    t |= b & (t >> 7);
    mobility |= blank & (t >> 7);

    b = black & all_mask;  
    t = b & (white << 7);
    t |= b & (t << 7);
    t |= b & (t << 7);
    t |= b & (t << 7);
    t |= b & (t << 7);
    t |= b & (t << 7);
    mobility |= blank & (t << 7);

    b = black & all_mask;  
    t = b & (white >> 9);
    t |= b & (t >> 9);
    t |= b & (t >> 9);
    t |= b & (t >> 9);
    t |= b & (t >> 9);
    t |= b & (t >> 9);
    mobility |= blank & (t >> 9);

    b = black & all_mask;  
    t = b & (white << 9);
    t |= b & (t << 9);
    t |= b & (t << 9);
    t |= b & (t << 9);
    t |= b & (t << 9);
    t |= b & (t << 9);
    mobility |= blank & (t << 9);
    // ShowIDs(mobility);
    return mobility;
}
void BitBoard::ReverseTurnBlack(int id){
    u_long all_mask = 0x007e7e7e7e7e7e00;
    u_long horizon_mask = 0x7e7e7e7e7e7e7e7e;
    u_long vertical_mask = 0x00FFFFFFFFFFFF00;
    u_long w = (u_long)0;
    u_long b = Black;
    u_long rev = (u_long)0; //反転位置

    u_long t = id;
    u_long p = (u_long)0;
    w = White & horizon_mask;
    //横
    for(int i = 1; i <= 7; i++){
        t = id + i;
        if(((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if(((u_long)1 << t & b)){ //黒なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if(((u_long)1 << t & w)){//白なら
            p = p | ((u_long)1<<t);
        }
    }
    for(int i = 1; i <= 7; i++){
        t = id - i;
        if(((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if(((u_long)1 << t & b)){ //黒なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if(((u_long)1 << t & w)){//白なら
            p = p | ((u_long)1<<t);
        }
    }
    for(int i = 1; i <= 7; i++){
        t = id + 7*i;
        if(((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if(((u_long)1 << t & b)){ //黒なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if(((u_long)1 << t & w)){//白なら
            p = p | ((u_long)1<<t);
        }
    }
    //縦
    w = White & vertical_mask;
    for(int i = 1; i <= 7; i++){
        t = id + 8*i;
        if(((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if(((u_long)1 << t & b)){ //黒なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if(((u_long)1 << t & w)){//白なら
            p = p | ((u_long)1<<t);
        }
    }
    for(int i = 1; i <= 7; i++){
        t = id - 8*i;
        if(((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if(((u_long)1 << t & b)){ //黒なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if(((u_long)1 << t & w)){//白なら
            p = p | ((u_long)1<<t);
        }
    }
    //斜め
    w = White & all_mask;
    for(int i = 1; i <= 7; i++){
        t = id - 7*i;
        if(((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if(((u_long)1 << t & b)){ //黒なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if(((u_long)1 << t & w)){//白なら
            p = p | ((u_long)1<<t);
        }
    }
    for(int i = 1; i <= 7; i++){
        t = id + 9*i;
        if(((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if(((u_long)1 << t & b)){ //黒なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if(((u_long)1 << t & w)){//白なら
            p = p | ((u_long)1<<t);
        }
    }
    for(int i = 1; i <= 7; i++){
        t = id - 9*i;
        if(((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if(((u_long)1 << t & b)){ //黒なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if(((u_long)1 << t & w)){//白なら
            p = p | ((u_long)1<<t);
        }
    }
    Black ^= ((u_long)1 << id) | rev;
    White ^= rev;
}
void BitBoard::ReverseTurnWhite(int id){
    u_long all_mask = 0x007e7e7e7e7e7e00;
    u_long horizon_mask = 0x7e7e7e7e7e7e7e7e;
    u_long vertical_mask = 0x00FFFFFFFFFFFF00;
    u_long b = (u_long)0;
    u_long w = White;
    u_long rev = (u_long)0; //反転位置

    u_long t = id;
    u_long p = (u_long)0;
    b = Black & horizon_mask;
    for (int i = 1; i <= 7; i++){
        t = id + i;
        if (((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//隣が白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if((u_long)1 << t & w){//白なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if((u_long)1 << t & b){//黒なら
            p = p | (u_long)1 << t;
        }
    }
     for (int i = 1; i <= 7; i++){
        t = id - i;
        if (((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//隣が白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if((u_long)1 << t & w){//白なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if((u_long)1 << t & b){//黒なら
            p = p | (u_long)1 << t;
        }
    }

    b = Black & vertical_mask;
    for (int i = 1; i <= 7; i++){
        t = id + 8*i;
        if (((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//隣が白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if((u_long)1 << t & w){//白なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if((u_long)1 << t & b){//黒なら
            p = p | (u_long)1 << t;
        }
    }
     for (int i = 1; i <= 7; i++){
        t = id - 8*i;
        if (((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//隣が白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if((u_long)1 << t & w){//白なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if((u_long)1 << t & b){//黒なら
            p = p | (u_long)1 << t;
        }
    }

    b=Black & all_mask;
    for (int i = 1; i <= 7; i++){
        t = id + 7*i;
        if (((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//隣が白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if((u_long)1 << t & w){//白なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if((u_long)1 << t & b){//黒なら
            p = p | (u_long)1 << t;
        }
    }
     for (int i = 1; i <= 7; i++){
        t = id - 7*i;
        if (((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//隣が白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if((u_long)1 << t & w){//白なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if((u_long)1 << t & b){//黒なら
            p = p | (u_long)1 << t;
        }
    }

    for (int i = 1; i <= 7; i++){
        t = id + 9*i;
        if (((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//隣が白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if((u_long)1 << t & w){//白なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if((u_long)1 << t & b){//黒なら
            p = p | (u_long)1 << t;
        }
    }
     for (int i = 1; i <= 7; i++){
        t = id - 9*i;
        if (((u_long)1 << t & w)==(u_long)0 && ((u_long)1 << t & b)==(u_long)0){//隣が白でも黒でもない
            //ひっくり返せない
            p = (u_long)0;
            break;
        }else if((u_long)1 << t & w){//白なら
            rev = rev | p;//revに反映
            p = (u_long)0;//初期化
            break;
        }else if((u_long)1 << t & b){//黒なら
            p = p | (u_long)1 << t;
        }
    }
    White ^= ((u_long)1<<id) | rev;
    Black ^= rev;
}
void BitBoard::Show(){
    // for(int i = 0; i >= 0; i--){
    //     for(int j = 7; j >= 0; j--){
    //         int id = 8*i + j;
    //         if(Black & (u_long)1 << id){
    //             cout << "b ";
    //         }else if(White & (u_long)1 << id){
    //             cout << "w ";
    //         }else{
    //             cout << "* ";
    //         }
    //     }
    //     cout<<'\n';
    // }
    cout<<" "<<"  0   1   2   3   4   5   6   7  "<<endl;
    cout<<" "<<"+---+---+---+---+---+---+---+---+"<<endl;
    for (int i = 0; i <= 7; i++)
    {
        cout<<(char)(65+i)<<'|';
        for(int j=0;j<=7;j++){
            int id = i*8+j;
            u_long flag = (u_long)1 << id;
            if(Black & flag){
                cout<<" b  ";
            }else if(White & flag){
                cout<<" w  ";
            }else{
                cout<<" *  ";
            }
        }
        cout<<'\n';
        cout<<" +"<<endl;
    }
    cout<<endl;
}
void BitBoard::Score(){
    cout<<"Black : " << bitCount(Black) << '-' << bitCount(White) << " : White"<<endl;
}
#endif
