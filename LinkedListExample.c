#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

struct _nodet{
int key;
struct _nodet *npt;
struct _nodet *ppt;

};

typedef struct _nodet node;

node *insert(node *h1ptr){
char aar[3];
fflush(stdin);
int vals;
printf("Insert random positive 3 digit value to assign node: ");
fgets(aar,sizeof(aar),stdin);
vals = atoi(aar);
node *reptr = (node *) malloc(sizeof(node));
reptr->key = vals;
if (h1ptr == NULL){
    reptr->npt = NULL;
    reptr->ppt = NULL;
} else {
    h1ptr->ppt = reptr;
    reptr->npt = h1ptr;
    reptr->ppt = NULL;
}
return reptr;
}

void printer(node *npptr){
    printf("VALS: ");
    if(npptr != NULL){
    while(npptr !=NULL){
        printf(" %d ",npptr->key);
        npptr = npptr->npt;
    }
    } else {
    printf("Empty LL.");
    }
    printf("\n");
}

void maxnode(node *npptr){
    printf("Maxval: ");
    if(npptr != NULL){
    int mval = npptr->key;
    while(npptr !=NULL){
        if (npptr->key > mval){
            mval = npptr->key;
        }
        npptr = npptr->npt;
    }
    printf(" %d ",mval);
    } else {
    printf("Empty LL.");
    }
    printf("\n");
}

void minode(node *npptr){
    printf("Minval: ");
    if(npptr != NULL){
        int minval = npptr->key;
    while(npptr !=NULL){
        if (npptr->key < minval){
            minval = npptr->key;
        }
        npptr = npptr->npt;
    }
    printf(" %d ",minval);
    } else {
    printf("Empty LL.");
    }
    printf("\n");
}


void nodesearch(node *npptr){
    if(npptr != NULL){
    char aar[3];
fflush(stdin);
int kval;
printf("Insert value to find: ");
fgets(aar,sizeof(aar),stdin);
kval = atoi(aar);
    printf("Does value exist?: ");
    char exstat = 'N';
    while(npptr !=NULL){
        if (kval == npptr->key){
            exstat = 'Y';
        }
        npptr = npptr->npt;
    }
    printf(" %c ",exstat);
    } else {
    printf("Empty LL.");
    }
    printf("\n");
}

node * nodedelete(node *npptr){
    if(npptr != NULL){
node *rethead = npptr;
    char aar[3];
fflush(stdin);
int kval;
printf("Insert value to delete: ");
fgets(aar,sizeof(aar),stdin);
kval = atoi(aar);
    printf("Has value(s) been found and deleted?: ");
    char exstat = 'N';
    while(npptr != NULL){
        if (kval == npptr->key){
            exstat = 'Y';
        if(npptr->ppt == NULL && npptr->npt == NULL){
            printf(" %c ",exstat);
            printf("\n");
            free(npptr);
            return NULL;
        }
            else if (npptr->ppt == NULL){
                rethead = npptr->npt;
                npptr->npt->ppt = NULL;

            }
        else if (npptr->npt == NULL) {
            npptr->ppt->npt = NULL;
        }
            else {
            npptr->npt->ppt = npptr->ppt;
            npptr->ppt->npt = npptr->npt;
            }
            free(npptr);
            break;
        }

        npptr = npptr->npt;
    }
    printf(" %c ",exstat);
    printf("\n");
    return rethead;
    } else {
    printf("Empty LL.");
    printf("\n");
    return NULL;
    }
}



node *decider(node *heptr, bool * stata){
int dval;
char arr[2];
fflush(stdin);
printf("Enter 0 to quit, 1 to insert node, 2 to delete node, 3 to print all nodes, 4 to search node, 5 for maxnode, 6 for minode, 7 to delete all nodes: ");
fgets(arr,sizeof(arr),stdin);
dval = atoi(arr);
switch (dval){
    case 0:
        *stata = false;
        return NULL;
        break;
    case 1:
        printf("Inserting: \n");
        heptr = insert(heptr);
        return heptr;
        break;
    case 2:
        printf("deleting: \n");
        heptr = nodedelete(heptr);
        return heptr;
        break;
    case 3:
        printf("Printing: \n");
        printer(heptr);
        return heptr;
        break;
    case 4:
        printf("Searching: \n");
        nodesearch(heptr);
        return heptr;
        break;
    case 5:
        printf("Maxnode: \n");
        maxnode(heptr);
        return heptr;
        break;
    case 6:
        printf("Minnode: \n");
        minode(heptr);
        return heptr;
        break;
    default :
        return heptr;
        break;
}
}


int main()
{
    node *hptr = NULL;
    bool stat = true;
    while(1){
    hptr = decider(hptr,&stat);

    if(stat == false){
        break;
    }

    fflush(stdin);
    }
    return 0;
}
