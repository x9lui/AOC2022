#include <stdio.h>
#include <stdlib.h>

int calories(FILE*);
void one();
void two();

int main(){
    //one();
    two();
}

void one(){
    FILE *f;
    f = fopen("input.txt","r");
    int max = 0;
    int cal;
    int tCal = 0;
    do{
        do{
            cal = calories(f);
            tCal +=cal;
        }while(cal!=-1 && cal!=-2);
        
        //Correcting the addition of -1 or -2
        tCal-=cal;

        if(tCal>max){
            max = tCal;
        }

        tCal = 0;

    }while(cal!=-2);

    printf("%i",max);
}

void two(){
    FILE *f;
    f = fopen("input.txt","r");
    //Vector for storing the top 3 snacks calories
    int max[3] = {0,0,0};
    int cal;
    int tCal = 0;
    int t = 0;
    do{
        do{
            cal = calories(f);
            tCal +=cal;
        }while(cal!=-1 && cal!=-2);
        
        //Correcting the addition of -1 or -2
        tCal-=cal;

        //Storing top 3
        for(int i = 0; i<3; i++){
            if(max[i]<tCal){
                max[i] = tCal;
                break;
            }
        }

        tCal = 0;

    }while(cal!=-2);

    for(int i = 0; i<3; i++){
        t += max[i];
    }
    printf("%i",t);
}


//Return calories in each line, -1 if there is a blank line and -2 if EOF
int calories(FILE *f){
    char ch;
    if((ch=fgetc(f)) && ch=='\n'){
        return -1;
    }else if(ch ==EOF){
        return -2;
    }else{
        fseek(f,-1,SEEK_CUR);
        int n = 0;
        while((ch=fgetc(f)) && 48<=ch && ch<=57){
            n*=10;
            n+=ch-48;
        }
        return n;
    }
}