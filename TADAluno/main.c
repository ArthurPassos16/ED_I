#include <stdio.h>
#include "cofo.h"

int main(){
    Cofo *c;
    Aluno aluno;
    int a=12;
    c=cofCreate(5);
    strcpy(aluno.nome,"Arthur");
    aluno.cpf=123456789;
    aluno.saldoBanco=1000;
    cofInsert(c,&aluno);
    a=cofRemove(c,123456789);
    printf("%d\n",a);
    a=cofQuery(c,123456789);
    printf("%d\n",a);
    a=cofDestroy(c);
    return 0;
}
