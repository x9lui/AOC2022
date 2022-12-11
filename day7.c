#include <stdio.h>
#include <string.h>
#include "readV2.c"
#include "day7DS.h"

#define INPUT "input.txt"

void addDir(Directory*,char*);
void addFil(Directory*, char*, File**,int*);
int part1(Directory*, File*, int*);
void part2(Directory*,File*, int *, int);
int calcSize(Directory*,File*);


int main(){
    
    FILE *f;
    f = fopen(INPUT,"r");

    //We are going to save all the files here:
    File *storage;
    int nS = 0; //number of files in storage
    storage = malloc(sizeof(File));
    

    //Root directory
    Directory root;
    root.lsed = 0;
    root.nDir = 0;
    root.nFil = 0;
    root.counted = 0;

    //Working directory
    Directory *wd;
    wd = &root;

    skipLine(f);
    char *s;
    while(readLine(f,&s)!=2){
        //Commands
        switch(s[2]){
            case 'c': //cd
                switch(s[5]){
                    case '.': //cd ..
                        wd = wd->prev;
                break;
                    case '/': //cd /
                        wd = &root;
                break;
                    default:
                        //search the dir by name and make it our current dir
                        for(int i=0;i<wd->nDir;i++){
                            if(strcmp(wd->dirs[i]->name, field(s,' ',3)) == 0){
                                wd = wd->dirs[i];
                                break;
                            }
                        }

                }
        break;
            case 'l': //ls

                //Listed before?
                if((*wd).lsed==0){
                    //Store content
                    while(readLine(f,&s)!=2 && s[0]!='$'){
                        

                        //Directory or file?
                        if(s[0] == 'd'){ //Directory 
                            addDir(wd,s);
                        }else{ //File
                            addFil(wd,s,&storage,&nS);
                        }
                    }

                    (*wd).lsed = 1; //Now the directory is listed
                    backLine(f);
                }
        break;
        }
    }

    //Part 1
    int solution = 0;
    int inUse = part1(&root,storage,&solution);
    printf("Part 1: %i\n",solution);

    //Part 2
    /*
    int choosed = 10000000;
    int *ptr;
    ptr = &choosed;
    int toFree = 70000000 - inUse;
    part2(&root,storage,ptr,toFree);
    printf("Part 2: %i", *ptr); 
    */
}





void addDir(Directory *wd,char *s){
    Directory *newDir;
    newDir = malloc(sizeof(Directory));

    if( wd->nDir != 0){
        wd->nDir++;
        wd->dirs = realloc(wd->dirs, wd->nDir*sizeof(Directory*));

    }else{
        wd->nDir = 1;
        wd->dirs = malloc(sizeof(Directory*));

    }

    newDir->name = malloc((strlen(field(s,' ',2))+1) * sizeof(char));

    //Initialization values
    strcpy(newDir->name, field(s,' ',2));
    newDir->prev = wd;
    newDir->lsed = 0;
    newDir->nDir = 0;
    newDir->nFil = 0;
    newDir->counted = 0;
    wd->dirs[(wd->nDir)-1] = newDir;
}

void addFil(Directory *wd,char *s, File **storage, int *nS){
    //Add the directory to the storage
    (*nS)++;
    *storage = realloc(*storage, *(nS)*sizeof(File));
    (*storage)[*nS-1].parent = wd;
    (*storage)[*nS-1].name = malloc((strlen(field(s,' ',2))+1) * sizeof(char));
    strcpy((*storage)[*nS-1].name,field(s,' ',2));
    (*storage)[*nS-1].size = strToNum(field(s,' ',1));

    if(wd->nFil!=0){
        wd->nFil++;
        wd->FilInd = realloc(wd->FilInd, wd->nFil*sizeof(int));
        wd->FilInd[wd->nFil-1] = *nS-1;
    }else{
        wd->FilInd = malloc(sizeof(int));
        wd->FilInd[0] = *nS-1;
        wd->nFil = 1;
    }

}


//Recursive function to make the calculus of part 1
int part1(Directory *dir, File *storage, int *solution){
    int dirSize = 0;

    //First sum the size of contained files
    for(int i = 0; i<dir->nFil; i++){
        dirSize += storage[dir->FilInd[i]].size;
    }
    

    //Now sum the size of the contained directories
    for(int i = 0; i<dir->nDir; i++){
        dirSize += part1(dir->dirs[i],storage,solution);
    }

    
    if(dirSize<=100000 && dir->counted == 0){
        *solution += dirSize;
        dir->counted=1;
    }

    return dirSize;
}

//Recursive function to find the directory to free in part 2
void part2(Directory *dir, File *storage, int *choosed, int toFree){
    
    for(int i = 0; i<dir->nDir; i++){
        part2(dir->dirs[i],storage,choosed,toFree);
    }

    int dirSize = calcSize(dir,storage);

    printf("%i\n",dirSize);
    if(*choosed>=dirSize && dirSize>=toFree){
        printf("here\n\n\n");
        *choosed = dirSize;
    }

}

//Recursive function to calculate the size of a directory
int calcSize(Directory *dir, File *storage){
    int dirSize = 0;

    //First sum the size of contained files
    for(int i = 0; i<dir->nFil; i++){
        dirSize += storage[dir->FilInd[i]].size;
    }
    //MULTIPLE COUNTING?

    //Now sum the size of the contained directories
    for(int i = 0; i<dir->nDir; i++){
        dirSize += calcSize(dir->dirs[i],storage);
    }
    return dirSize;

}