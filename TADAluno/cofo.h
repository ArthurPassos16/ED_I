#ifndef cofo_h
#define cofo_h
    #ifndef cofo.c
        typedef struct aluno{
            char nome[50];
            int cpf;
            int saldoBanco;
        }Aluno;

        typedef struct cofo{
            int nElms;
            int maxElms;
            Aluno *alunos;
        }Cofo;

        Cofo *cofCreate(int n);
        int cofInsert(Cofo *c, Aluno *aluno);
        int cofQuery(Cofo *c, int key);
        int cofRemove(Cofo *c, int key);
        int cofDestroy(Cofo *c);
    #else
        typedef struct cofo Cofo;
        typedef struct aluno Aluno;
        extern Cofo *cofCreate(int n);
        extern int cofInsert(Cofo *c, Aluno *aluno);
        extern int cofQuery(Cofo *c, int key);
        extern int cofRemove(Cofo *c, int key);
        extern int cofdestroy(Cofo *c);
    #endif
#endif
