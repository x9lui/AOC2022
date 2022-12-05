#include <stdio.h>
#include <stdlib.h>

void one();
void two();
int getElement();

int main(){
    //one();
    two();
}

void one(){
    FILE *f;
    f = fopen("input.txt","r");
    int r1,r2,s1,s2;
    int t = 0;
    char ch;
    do{
        
        r1 = getElement(f);
        r2 = getElement(f);
        s1 = getElement(f);
        s2 = getElement(f); 

        if(r1<=s1 && s2 <= r2){
            t++;
        }else if(s1<=r1 && r2<=s2){
            t++;
        }

        if((ch=fgetc(f)) && ch != EOF){
            fseek(f,-1,SEEK_CUR);
        }


    }while(ch!=EOF);

    printf("%i",t);
}

void two(){
    FILE *f;
    f = fopen("input.txt","r");
    int r1,r2,s1,s2;
    int t = 0;
    char ch;
    do{
        
        r1 = getElement(f);
        r2 = getElement(f);
        s1 = getElement(f);
        s2 = getElement(f); 

        if(r1<=s1 && s1<=r2){
            t++;
        }else if(s1<=r1 && r1<=s2){
            t++;
        }


        //Next character is EOF?
        if((ch=fgetc(f)) && ch != EOF){
            fseek(f,-1,SEEK_CUR);
        }


    }while(ch!=EOF);

    printf("%i",t);
}


//Getting an element and skipping the next separator
int getElement(FILE *f){
    char ch;
    int n = 0;
    while((ch=fgetc(f)) && 48<=ch && ch<=57){
        n*=10;
        n+=ch-48;
    }
    return(n);
}