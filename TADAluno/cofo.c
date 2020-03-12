#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"
#define TRUE 1
#define FALSE 0

Cofo *cofCreate(int n){
    Cofo *c;
    if(n>0){
        c = (Cofo *)malloc(sizeof(Cofo));
        if(c!=NULL){
            c->alunos=(Aluno *)malloc(sizeof(Aluno)*n);
            if(c->alunos!=NULL){
                c->nElms=0;
                c->maxElms=n;
                return c;
            }
        }
    }
    return NULL;
}

int cofInsert(Cofo *c, Aluno *aluno){
    if(c!=NULL){
        if(c->nElms<c->maxElms){
            c->alunos[c->nElms].cpf = aluno->cpf;
            strcpy(c->alunos[c->nElms].nome, aluno->nome);
            c->alunos[c->nElms].saldoBanco = aluno->saldoBanco;
            c->nElms++;
            return TRUE;
        }
    }
    return FALSE;
}

int cofQuery(Cofo *c, int key){
    int i;
    if(c!=NULL){
        if(c->nElms>0){
            i=0;
            while(c->alunos[i].cpf!=key && i<c->nElms){
                i++;
            }
            if(c->alunos[i].cpf==key){
                return c->alunos[i].cpf;
            }
        }
    }
    return -1;
}

int cofRemove(Cofo *c, int key){
    int i,j,cpf;
    if(c!=NULL){
        if(c->nElms>0){
            i=0;
            while(c->alunos[i].cpf!=key && i<c->nElms){
                i++;
            }
            if(c->alunos[i].cpf==key){
                cpf=c->alunos[i].cpf;
                for(j=i;j<c->nElms-2;j++){
                    c->alunos[j]=c->alunos[j+1];
                }
                c->nElms--;
                return c->alunos[i].cpf;
            }
        }
    }
    return -1;
}

int cofDestroy(Cofo *c){
    if(c!=NULL){
        if(c->nElms==0){
            free(c->alunos);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}
