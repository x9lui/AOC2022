
typedef struct Directory_{
    char *name;
    struct Directory_  *prev;
    int nFil;
    int *FilInd; //indexes of his files in file array (storage)
    int nDir;
    struct Directory_ **dirs; //Array of pointers to directories
    int lsed; //0 if not listed before and 1 if listed
    int counted; //0 if not counted
}Directory;


typedef struct{
    struct Directory_ *parent;
    char *name;
    int size;
}File;