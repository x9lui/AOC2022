#include <stdio.h>
#include <stdlib.h>

void one();
void two();

int main(){
    one();
    two();
}

void one(){

    FILE *f;

    f = fopen("input.txt","r");
    char op,me;
    int sc = 0;

    while((op=fgetc(f))&&op!=EOF){
        fseek(f,1L,SEEK_CUR);
        me=fgetc(f);
        switch(me){
            //Stone X loses to paper B
            case 'X':
                sc++;
                switch(op){
                    case 'A':
                        sc+=3;
                    break;

                    case 'B':
                    //Loses
                    break;

                    case 'C':
                        sc+=6;
                    break;
                }
            break;

            //Paper Y loses to scissors C
            case 'Y':
                sc+=2;
                switch(op){
                    case 'A':
                        sc+=6;
                    break;

                    case 'B':
                        sc+=3;
                    break;

                    case 'C':
                    //Loses
                    break;
                }
            break;

            //Scissors Z loses to stone A
            case 'Z':
                sc+=3;
                switch(op){
                    case 'A':
                        //Loses
                    break;

                    case 'B':
                        sc+=6;
                    break;

                    case 'C':
                        sc+=3;
                    break;
                }
            break;
        }
        fseek(f,1,SEEK_CUR);
        
    
    }
    fclose(f);
    printf("%i",sc);
}

void two(){

    FILE *f;

    f = fopen("input.txt","r");
    char op,me;
    int sc = 0;

    while((op=fgetc(f))&&op!=EOF){
        fseek(f,1L,SEEK_CUR);
        me=fgetc(f);
        switch(me){

            //Lose
            case 'X':
                switch(op){
                    //Op stone, respond with scissors
                    case 'A':
                        sc+=3;
                    break;
                    //Op paper, respond with stone
                    case 'B':
                        sc+=1;
                    break;
                    //Op scisscors, respond with paper
                    case 'C':
                        sc+=2;
                    break;
                }
            break;

            //Draw
            case 'Y':
                switch(op){
                    //Stone + draw
                    case 'A':
                        sc+=4;
                    break;
                    //Paper + draw
                    case 'B':
                        sc+=5;
                    break;
                    //Scissors + draw
                    case 'C':
                        sc+=6;
                    break;
                }
            break;

            //Win
            case 'Z':
                switch(op){
                    //Op stone, respond with paper
                    case 'A':
                        sc+=8;
                    break;
                    //Op paper, respond with scissors
                    case 'B':
                        sc+=9;
                    break;
                    //Op scissors, respond with stone
                    case 'C':
                        sc+=7;
                    break;
                }
            break;
        }
        fseek(f,1,SEEK_CUR);
    
    }
    fclose(f);
    printf("%i",sc);
}