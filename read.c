#include <stdio.h>
#include <stdlib.h>

//Returns 1 if the line is in blank, a 2 if EOF and 0 if none of these two 
int readLine(FILE *f, char **s, int *l){
    char ch;
    int i = 0;
    *s = malloc(sizeof(char));
    while((ch=fgetc(f)) && ch!=EOF && ch!='\n'){
        *s = realloc(*s,(i+1)*sizeof(char));
        (*s)[i] = ch;
        i++;
    }
    *l = i+1;
    if(i){
        return 0;
    }else if('\n'){
        return 1;
    }else{
        return 2;
    }
}

void skipLine(FILE *f){
    char ch;
    while((ch=fgetc(f)) && ch!=EOF && ch!='\n'){}
}

//Gives the number in a field of the acutal line (make sure the file pointer is in the start position of the line), separated by sep
int fieldN(FILE *f,char sep,int fld){
    int fldI = 1; //Cursor of actual field in loop
    char ch;
    int n = 0;
    while((ch=fgetc(f)) && ch!=EOF && ch!='\n' && fldI<=fld){
        if(ch==sep){
            fldI++;
        }else if(fldI==fld){
            n*=10;
            n+=ch-48;
        }
    }
    //Go to the start of the line
    if(ch == '\n'){
        fseek(f,-2,SEEK_CUR);
    }
    while(ch!=EOF && (ch=fgetc(f)) && ch!= '\n'){
        fseek(f,-2,SEEK_CUR);
    }
    
    return n;
}