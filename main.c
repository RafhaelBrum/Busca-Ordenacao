#include <stdio.h>
#include <stdlib.h>
#include "busca_ordenacao.h"

int main()
{
    // criacao do Array de alunos e populando 6 casas
    ALUNO alunos[6];

    ALUNO aluno1 = cria_aluno(0, 1, 1, 1, 1);
    ALUNO aluno2 = cria_aluno(1, 2, 2, 2, 2);
    ALUNO aluno3 = cria_aluno(2, 3, 3, 3, 3);
    ALUNO aluno4 = cria_aluno(3, 4, 4, 4, 4);
    ALUNO aluno5 = cria_aluno(4, 5, 5, 5, 5);
    ALUNO aluno6 = cria_aluno(5, 6, 6, 6, 6);

    alunos[3] = aluno1;
    alunos[5] = aluno2;
    alunos[1] = aluno3;
    alunos[0] = aluno4;
    alunos[2] = aluno5;
    alunos[4] = aluno6;

    printf("======= Lista desordenada =======\n");

    for(int i = 0; i < 6; i++){
        printf("\nIndice %d: \n\n", i);
        imprime_aluno(alunos[i]);
    }

    bubble_sort(alunos, 6);
    insertion_sort(alunos, 6);
    selection_sort(alunos, 6);

    printf("\n======= Lista ordenada =======\n");

    for(int i = 0; i < 6; i++){
        printf("\nIndice %d: \n\n", i);
        imprime_aluno(alunos[i]);
    }

    ALUNO alunoBuscaSequencial = busca_sequencial(alunos, 2);

    printf("\n==== BUSCA SEQUENCIAL ====\n\n");
    imprime_aluno(alunoBuscaSequencial);

    ALUNO alunoBuscaBinaria = busca_binaria(alunos, 3);

    printf("\n==== BUSCA BINARIA ====\n\n");
    imprime_aluno(alunoBuscaBinaria);

    alunoBuscaBinaria = busca_binaria(alunos, 7);

    printf("\n==== BUSCA BINARIA INEXISTENTE ====\n\n");
    imprime_aluno(alunoBuscaBinaria);

    alunoBuscaSequencial = busca_sequencial(alunos, -1);

    printf("\n==== BUSCA SEQUENCIAL INEXISTENTE ====\n\n");
    imprime_aluno(alunoBuscaSequencial);

    return 0;
}
