//
//  main.c
//  ma
//
//  Created by 潘若冰 on 2016/11/28.
//  Copyright © 2016年 潘若冰. All rights reserved.
//

#include <stdio.h>
int l = 0;
int a[5][5],book[5][5] = {1};
int flag = 1;
void horse(int x,int y,int step)
{
    int next[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
    int tx,ty,k;
    if(step==25){
        for (int i = 0; i<5; i++) {
            for (int j = 0; j<5; j++) {
                if (book[i][j]==0) {
                    flag = 0;
                }
            }
        }
        if (flag==1) {
            l++;
            return;
        }
        else
            flag = 1;
    }
    
    for (k = 0; k<8; k++) {
        tx = x+next[k][0];
        ty = y+next[k][1];
        if (tx<0||tx>4||ty<0||ty>4) {
            continue;
        }
        if (book[tx][ty]==0) {
            book[tx][ty] = 1;
//            printf("%d %d ",tx,ty);
            horse(tx,ty,step+1);
            book[tx][ty] = 0;
        }
    }
    return;
}
int main(int argc, const char * argv[]) {
    horse(0,0,1);
    printf("%d",l);
    return 0;
}
