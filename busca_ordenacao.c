#include <stddef.h>
#include "busca_ordenacao.h"

typedef struct struct_aluno{
    char nome[50];
    int matricula;
    int nota1;
    int nota2;
    int nota3;
    int nota4;
};

ALUNO cria_aluno(int matricula, int nota1, int nota2, int nota3, int nota4){
    ALUNO aluno;
    aluno = (ALUNO) malloc(sizeof(struct struct_aluno));
    aluno->matricula = matricula;
    aluno->nota1 = nota1;
    aluno->nota2 = nota2;
    aluno->nota3 = nota3;
    aluno->nota4 = nota4;

    return (aluno);
}

void imprime_aluno(ALUNO aluno){
    if(aluno->matricula == -1){
        printf("Aluno nao encontrado!\n");
        return;
    }

    printf("Matricula: %d\n", aluno->matricula);
    printf("Nota 1: %d\n", aluno->nota1);
    printf("Nota 2: %d\n", aluno->nota2);
    printf("Nota 3: %d\n", aluno->nota3);
    printf("Nota 4: %d\n", aluno->nota4);
}

ALUNO busca_sequencial(ALUNO listaAlunos[], int matricula){
    for(int i = 0; i < 6; i++){
        if(listaAlunos[i]->matricula == matricula){
            return listaAlunos[i];
        }
    }

    ALUNO alunoErro = (ALUNO) malloc(sizeof(struct struct_aluno));
    alunoErro->matricula = -1;

    return alunoErro;
}

ALUNO busca_binaria(ALUNO listaAlunos[], int matricula){
    int primeiro = 0;
    int ultimo = 5;

    while(primeiro <= ultimo){
        int meio = (int) (primeiro + ultimo) / 2;

        if(listaAlunos[meio]->matricula == matricula){
            return listaAlunos[meio];
        }
        else if(listaAlunos[meio]->matricula > matricula){
            ultimo = meio - 1;
        }
        else if(listaAlunos[meio]->matricula < matricula){
            primeiro = meio + 1;
        }
    }

    ALUNO alunoErro = (ALUNO) malloc(sizeof(struct struct_aluno));
    alunoErro->matricula = -1;

    return alunoErro;
}

void bubble_sort(ALUNO listaAlunos[], int tamanhoLista){
    for(int x = 1; x < tamanhoLista; x++){
        for(int i = 0; i < tamanhoLista - 1; i++){
            if(listaAlunos[i]->matricula > listaAlunos[i + 1]->matricula){
                ALUNO alunosAux = listaAlunos[i];
                listaAlunos[i] = listaAlunos[i + 1];
                listaAlunos[i + 1] = alunosAux;
            }
        }
    }
}

void insertion_sort(ALUNO listaAlunos[], int tamanhoLista){

    for (int i = 1; i < tamanhoLista; i++)
    {
        ALUNO alunoAux = listaAlunos[i];

        int j = i - 1;
        while (j >= 0 && listaAlunos[j]->matricula > alunoAux->matricula)
        {
            listaAlunos[j + 1] = listaAlunos[j];
            j = j - 1;
        }
        listaAlunos[j + 1] = alunoAux;
    }
}

void selection_sort(ALUNO listaAlunos[], int tamanhoLista){
    for(int i = 0; i < tamanhoLista - 1; i++){
        for(int j = i + 1; j < tamanhoLista; j++){
            if(listaAlunos[j]->matricula < listaAlunos[i]->matricula){
                ALUNO alunoAux = listaAlunos[j];
                listaAlunos[j] = listaAlunos[i];
                listaAlunos[i] = alunoAux;
            }
        }
    }
}
