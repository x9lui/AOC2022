#include <stdio.h>
#include "readV2.c"
#define INPUT "input.txt"

int visible(int[99][99],int,int);
int scenicScore(int[99][99],int,int);

//The input is a matrix 99x99
int main(){
    FILE *f;
    f = fopen(INPUT,"r");
    char *s;

    int forest[99][99];
    for(int i = 0; i<99; i++){
        readLine(f,&s);
        for(int j = 0; j<99; j++){
            forest[i][j] = charToNum(s[j]);
        }
    }

    //Part 1
    int visibles = 0;
    for(int i = 0; i<99; i++){
        for(int j = 0; j<99; j++){
            visibles += visible(forest,i,j);
        }
    }
    printf("Part 1: %i\n",visibles);

    //Part2
    int maxScore = 0;
    for(int i = 0; i<99; i++){
        for(int j = 0; j<99; j++){
            if(scenicScore(forest,i,j)>maxScore){
                maxScore = scenicScore(forest,i,j);
            }
        }
    }
    printf("Part 2: %i",maxScore);

}

//return 1 if visible and 0 if not
int visible(int forest[99][99],int x, int y){

    int hT = 0;
    int hB = 0;
    int hL = 0;
    int hR = 0;

    //Top
    for(int i=x-1; i>=0; i--){
        if(forest[i][y] >= forest[x][y]){
            hT++;
        }
    }

    //Bottom
    for(int i=x+1; i<99; i++){
        if(forest[i][y] >= forest[x][y]){
            hB++;
        }
    }

    //Left
    for(int i=y-1; i>=0; i--){
        if(forest[x][i] >= forest[x][y]){
            hL++;
        }
    }

    //Right
    for(int i=y+1; i<99; i++){
        if(forest[x][i] >= forest[x][y]){
            hR++;
        }
    }
    if(hT && hB && hL && hR){
        return 0;
    }else{
        return 1;
    }
}

int scenicScore(int forest[99][99],int x, int y){

    //Trees that can be seen in each direction
    int tT = 0;
    int tB = 0;
    int tL = 0;
    int tR = 0;

    //Top
    for(int i=x-1; i>=0; i--){
        tT++;
        if(forest[i][y] >= forest[x][y]){
            break;
        }
    }

    //Bottom
    for(int i=x+1; i<99; i++){
        tB++;
        if(forest[i][y] >= forest[x][y]){
            break;
        }
    }

    //Left
    for(int i=y-1; i>=0; i--){
        tL++;
        if(forest[x][i] >= forest[x][y]){
            break;
        }
    }

    //Right
    for(int i=y+1; i<99; i++){
        tR++;
        if(forest[x][i] >= forest[x][y]){
            break;
        }
    }
    return tT * tB * tL * tR;
}