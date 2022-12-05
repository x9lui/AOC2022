#include <stdio.h>
#include <stdlib.h>
#include "day5DS.h" //data structs
#include "read.c"

#define INPUT "input.txt"


void one();
void two();

//I have adaptated the functions to my input, so I can skip coding more functions
int main(){
    //one();
    two();
}


void one(){
    FILE *f;
    f = fopen(INPUT,"r");
    char *s;
    int l;
    Stack stacks[9];
    for(int i = 0; i<9; i++){
        stacks[i].last = -1;
    }

    //Read the stack line by line
    for(int i = 0; i<8; i++){
        int pos = 1; //Position in which crate is in the input
        readLine(f,&s,&l);

        //Storing each element in each stack, j identifies the stack in the array
        for(int j = 0; j<9; j++){

            if(65<=s[pos] && s[pos]<=90){

                stacks[j].last++;
                //Pushing the element in the array
                for(int k = stacks[j].last; k>=0; k--){
                    stacks[j].element[k] = stacks[j].element[k-1];
                }

                stacks[j].element[0] = s[pos];
            }
            pos+=4;
        }
    }

    skipLine(f);
    skipLine(f);
    
    int qty, src, dst;
    char ch;
    while((ch=fgetc(f)) && ch!=EOF){
        fseek(f,-1,SEEK_CUR);
        qty = fieldN(f,' ',2);
        src = fieldN(f,' ',4)-1;
        dst = fieldN(f,' ',6)-1;
        skipLine(f);

        //Move the stacks
        for(int i=0;i<qty;i++){ 
            stacks[dst].last++;
            stacks[dst].element[stacks[dst].last] = stacks[src].element[stacks[src].last];
            stacks[src].last--;
            
        }
    }
    
    //Print solution
    for(int i=0;i<9;i++){
        if(stacks[i].last>=0){
            printf("%c",stacks[i].element[stacks[i].last]);
        }
    }
    
    
}

void two(){
    FILE *f;
    f = fopen(INPUT,"r");
    char *s;
    int l;
    Stack stacks[9];
    for(int i = 0; i<9; i++){
        stacks[i].last = -1;
    }

    //Read the stack line by line
    for(int i = 0; i<8; i++){
        int pos = 1; //Position in which crate is in the input
        readLine(f,&s,&l);

        //Storing each element in each stack, j identifies the stack in the array
        for(int j = 0; j<9; j++){

            if(65<=s[pos] && s[pos]<=90){

                stacks[j].last++;
                //Pushing the element in the array
                for(int k = stacks[j].last; k>=0; k--){
                    stacks[j].element[k] = stacks[j].element[k-1];
                }

                stacks[j].element[0] = s[pos];
            }
            pos+=4;
        }
    }

    skipLine(f);
    skipLine(f);
    
    int qty, src, dst;
    char ch;
    while((ch=fgetc(f)) && ch!=EOF){
        fseek(f,-1,SEEK_CUR);
        qty = fieldN(f,' ',2);
        src = fieldN(f,' ',4)-1;
        dst = fieldN(f,' ',6)-1;
        skipLine(f);

        //Move the stacks
        stacks[src].last-=qty;
        for(int i=0;i<qty;i++){ 
            stacks[dst].last++;
            stacks[dst].element[stacks[dst].last] = stacks[src].element[stacks[src].last+i+1];
        }
    }
    
    //Print solution
    for(int i=0;i<9;i++){
        if(stacks[i].last>=0){
            printf("%c",stacks[i].element[stacks[i].last]);
        }
    }
    
}