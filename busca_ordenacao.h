typedef struct struct_aluno * ALUNO;

ALUNO cria_aluno(int matricula, int nota1, int nota2, int nota3, int nota4);

void imprime_aluno(ALUNO aluno);

ALUNO busca_sequencial(ALUNO listaAlunos[], int matricula);

ALUNO busca_binaria(ALUNO listaAlunos[], int matricula);

void bubble_sort(ALUNO listaAlunos[], int tamanhoLista);

void insertion_sort(ALUNO listaAlunos[], int tamanhoLista);

void selection_sort(ALUNO listaAlunos[], int tamanhoLista);
