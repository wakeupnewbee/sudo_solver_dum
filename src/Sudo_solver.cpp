//============================================================================
// Name        : Sudo_solver.cpp
// Author      : Yan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int set_bound(int num){
    if(num<=3){
        return 4;
    }else if(3<num<=6){
        return 7;
    }else{
        return 10;   
    }
}

int check(int box[][10], int x, int y){
    for(int idx=1; idx<10;idx++){
        if(box[x][y]==box[idx][y]&& idx!=x){
            return 0;
        }
    }
    for(int idy=1;idy<10;idy++){
        if(box[x][y]==box[x][idy]&& idy!=y){
            return 0;
        }
    }
    return 1;
}


void f_s(int box[][10],int x,int y,int* left){
    if(y==10){
        return;
    }
    if(box[x][y]==0){
        for(int n=1; n<10; n++){
            box[x][y]=n;
            if(check(box,x,y)){
                *left = *left - 1;
                if(x<=8){
                    f_s(box,x+1,y,left);
                }else{
                    f_s(box,1,y+1,left);//process to the next
                }
                if(*left==0) return;
            }
        }
        *left = *left + 1;
        box[x][y]=0;
        return;
    }else{
        if(x<10){
            f_s(box,x+1,y,left);
        }else{
            f_s(box,1,y+1,left);
        }
        return;
    }
}



int main()
{
    int box[10][10]={
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}};

    int left = 81;
    f_s(box,1,1,&left);
    cout<< "Done recursion" << endl;

    for(int m=1;m<10;m++){
        for(int n=1;n<10;n++){
            cout << box[n][m] <<" ";
        }
        cout << endl;
    }

    return 0;
}

