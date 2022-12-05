#include <stdio.h>
#include <stdlib.h>

void one();
void two();
int value(int);

int main(){
    one();
    two();
}

void one(){
    //Backpack
    char *bp;
    //Compartments
    char *cp1,*cp2;
    char ch;
    int bpSize, hBpSize;
    FILE *f;
    f = fopen("input.txt","r");
    int t = 0;
    
    bp = malloc(sizeof(char));

    do{
        int i = 0;
        //Filling a vector with the elements of a backpack and measuring his size
        while((ch=fgetc(f)) && ch!='\n' && ch!=EOF){
            bp[i] = ch;
            i++; 
            bp = realloc(bp,(i+1)*sizeof(char));
        }


        //Dividing the backpack in a two compartments
        bpSize = i+1;
        hBpSize = bpSize/2;
        cp1 = malloc((hBpSize)*sizeof(char));
        cp2 = malloc((hBpSize)*sizeof(char));
        for(int o = 0; o<(hBpSize); o++){
            cp1[o] = bp[o];
        }

        for(int o = 0; o<hBpSize ;o++){
            cp2[o] = bp[o + (hBpSize)];
        }

        //Finding common element in these compartments
        char cm = 0;
        for(int o = 0; o<hBpSize; o++){
            for(int u = 0; u<hBpSize; u++){
                if(cp1[o]==cp2[u]){
                    cm = cp1[o];
                }
            }
        }

        t+=value(cm);

        
    }while(ch!=EOF);

    free(bp);
    free(cp1);
    free(cp2);
    
    printf("%i",t);
}

void two(){
    //Backpacks
    char *bp1,*bp2,*bp3;
    char ch;
    int bpSize;
    FILE *f;
    f = fopen("input.txt","r");
    int t = 0;
    
    bp1 = malloc(sizeof(char));
    bp2 = malloc(sizeof(char));
    bp3 = malloc(sizeof(char));

    do{
        int i = 0;
        int o = 0;
        int u = 0;

        //Filling vectors with the elements of a backpack and measuring his size
        while((ch=fgetc(f)) && ch!='\n' && ch!=EOF){
            bp1[i] = ch;
            i++; 
            bp1 = realloc(bp1,(i+1)*sizeof(char));
        }

        while((ch=fgetc(f)) && ch!='\n' && ch!=EOF){
            bp2[o] = ch;
            o++; 
            bp2 = realloc(bp2,(o+1)*sizeof(char));
        }

        while((ch=fgetc(f)) && ch!='\n' && ch!=EOF){
            bp3[u] = ch;
            u++; 
            bp3 = realloc(bp3,(u+1)*sizeof(char));
        }




        //Finding common element in the backpacks
        char cm = 0;
        for(int c = 0; c<i; c++){
            for(int d=0; d<o;d++){
                for(int e=0; e<u; e++){
                    if(bp1[c]==bp2[d] && bp1[c]==bp3[e]){
                        cm = bp1[c];
                    }
                }
            }
        }

        t+=value(cm);
    }while(ch!=EOF);

    printf("%i",t);
}

//Calculate the value of the element using ASCII values
int value(int x){
    if(65<=x && x<=90){
        return(x-38);
    }else if(97<=x && x<=122){
        return(x-96);
    }else{
        return(0);
    }

}