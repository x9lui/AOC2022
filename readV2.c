#include <stdio.h>
#include <stdlib.h>

//Returns 1 if the line is in blank, a 2 if EOF and 0 if none of these two 
int readLine(FILE *f, char **s){
    char ch;
    int i = 0;
    *s = malloc(sizeof(char));
    while((ch=fgetc(f)) && ch!=EOF && ch!='\n'){
        i++;
        *s = realloc(*s,(i+1)*sizeof(char));
        (*s)[i-1] = ch;
        
    }

    if(i){
        i++;
        //Add null character
        *s = realloc(*s,(i+1)*sizeof(char));
        (*s)[i-1] = '\0';
        return 0;
    }else if(ch=='\n'){
        return 1;
    }else{
        return 2;
    }
}

void skipLine(FILE *f){
    char ch;
    while((ch=fgetc(f)) && ch!=EOF && ch!='\n'){}
}

void backLine(FILE *f){
    char ch;
    int c = 0; //counter of endlines
    fseek(f,-1,SEEK_CUR);
    while((ch=fgetc(f)) && c!=2){
        if(ch == '\n'){
            c++;
        }
        fseek(f,-2,SEEK_CUR);
    }
    fseek(f,1,SEEK_CUR);
}

//Returns the field of a stirng separated by a separator characters
char *field(char *s,char sep,int fld){
    int fldI = 1; //Cursor of actual field in loop
    char ch;
    int i = 0;
    int j = 0;
    char *s2 = malloc(sizeof(char));

    while(fldI<=fld && s[i]!='\0'){
        if(s[i]==sep){
            fldI++;
        }else if(fldI==fld){
            j++;
            s2 = realloc(s2, (j+1)*sizeof(char));
            s2[j-1] = s[i];
        }
        i++;
    }
    return s2;
}

int strToNum(char *s){
    int i = 0;
    int n = 0;
    while(s[i]!='\0'){
        n*=10;
        n+=s[i]-48;
        i++;
    }
    return n;
}

int charToNum(char c){
    return c - 48;
}