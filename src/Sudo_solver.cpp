//============================================================================
// Name        : Sudo_solver.cpp
// Author      : Yan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int set_bound(int num){
    if(num<=3){
        return 4;
    }else if(num>3 && num<=6){
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
    
    int i_x = set_bound(x);
    int i_y = set_bound(y);
    cout << i_x << " "<< i_y;
    for(int check_y=i_y-3;check_y<i_y;check_y++){
        for(int check_x=i_x-3;check_x<i_x;check_x++){
            if(box[x][y]==box[check_x][check_y]&& check_y!=y && check_x!= x){
                return 0;
            }
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

int initial(int box[][10]){
    ifstream file("raw.txt");
    string line;
    int convert;
    int count_left=81;
    for(int y=1; y<10; y++){
        getline(file,line);
        istringstream bubble(line);
        for(int x=1; x<10; x++){
            bubble >> convert;
            if(convert!=0){
                count_left--;
            }
            box[x][y]=convert;
        }
    }
    return count_left;
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

