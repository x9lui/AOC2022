#include <stdio.h>
#include <stdlib.h>
#include "read.c"
#define INPUT "input.txt"

void one();
void two();

int main(){
    //one();
    two();
}

void one(){
    FILE *f;
    f = fopen(INPUT,"r");

    char *s, bf[4];
    int l;
    int t = 0;
    while((readLine(f,&s,&l))!=2){
        for(int i=0; i<l-3;i++){
            //Copying 4 elements to the buffer
            for(int j=0;j<4;j++){
                bf[j] = s[i+j];
            }
            if(repeated(bf,4)==0){
                t+=i+4;
                break;
            }
        }
    }
    printf("%i",t);
}

void two(){
    FILE *f;
    f = fopen(INPUT,"r");

    char *s, bf[14];
    int l;
    int t = 0;
    while((readLine(f,&s,&l))!=2){
        for(int i=0; i<l-13;i++){
            //Copying 14 elements to the buffer
            for(int j=0;j<14;j++){
                bf[j] = s[i+j];
            }
            if(repeated(bf,14)==0){
                t+=i+14;
                break;
            }
        }
    }
    printf("%i",t);
}