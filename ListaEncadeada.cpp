#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

typedef struct No
{
	char nome[10];
	int idade;
	struct No *prox;
} No;

//variavel global
int tamanho;

//protótipos
int Vazia(No *);
No *alocaMemoria();
void insereFim(No *);
No *retiraFim(No *);
void insereInicio(No *);
No * retiraInicio(No *);
void exibirLista(No *);
void iniciarLista(No *);
int menu();
void tratarOpcao(No *, int); 

main()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	GetConsoleScreenBufferInfo(hConsole,&consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	setlocale(LC_ALL,"portuguese");

	No *Lista = (No *) malloc(sizeof(No));

	if(!Lista){
		printf("\nnão há espaço na memória pra criar lista\n");
		exit(1);
	}

	iniciarLista(Lista);

	int opc =0;

	do{
		opc = menu();
		tratarOpcao(Lista, opc);
			SetConsoleTextAttribute(hConsole,13);
		system("pause");
			SetConsoleTextAttribute(hConsole,7);
		system("cls");
	}while(opc);
}

int menu()
{
	int opc;

	puts("1 - escolha sua opção");
	puts("-=-=-=-=-=-=-=-=-=-");

	printf("1 - zerar a lista\n");
	printf("2 - exibir a lista\n");
	printf("3 - inserir um elemento no final da lista\n");
	printf("4 - inserir elemento no início da lista\n");
	printf("5 - excluir um elemento do fim da lista\n");
	printf("6 - excluir um elemento no início da lista\n");
	printf("7 - finalizar o programa\n");

	puts("-=-=-=-=-=-=-=-=-=-");

	printf("opção: ");
	scanf("%d", &opc);

	return opc;
}

void tratarOpcao(No *Lista, int opc)
{
	switch(opc)
	{
		case 1:
			iniciarLista(Lista);
			break;

		case 2:
			exibirLista(Lista);
			break;

		case 3:
			insereFim(Lista);
			break;

		case 4:
			insereInicio(Lista);
			break;

		case 5:
			retiraFim(Lista);
			break;

		case 6:
		{
			No *removido = retiraInicio(Lista);
			if(removido != NULL)
				free(removido);
			break;
		}

		case 7:
			exit(0);

		default:
			printf("opção está inválida");						 		
	}
}

void iniciarLista(No *Lista)
{
	Lista->prox = NULL;
	tamanho = 0;
}

int Vazia(No *Lista)
{
	return (Lista->prox == NULL);
}

No *alocaMemoria()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	GetConsoleScreenBufferInfo(hConsole,&consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	No *novo = (No *) malloc(sizeof(No));

	if(!novo){
		printf("\nnão há espaço na memória\n");
		exit(1);
	}
	SetConsoleTextAttribute(hConsole,3);
	printf("nome: ");
	SetConsoleTextAttribute(hConsole,7);
	scanf("%s", novo->nome);
	SetConsoleTextAttribute(hConsole,12);
	printf("idade: ");
	SetConsoleTextAttribute(hConsole,7);
	scanf("%d", &novo->idade);

	return novo;
}

void insereInicio(No *Lista)
{
	No *novo = alocaMemoria();
	No *head = Lista->prox;
	Lista->prox = novo;
	novo->prox = head;
	puts("No inserido no INICIO da Lista!!!");
	tamanho++;
}

No * retiraInicio(No* Lista){
	if(Lista->prox == NULL)  // CORRIGIDO AQUI
	{
		puts("a lista está vazia");
		return NULL;
	}	
	else{
		No* temp = Lista->prox;
		Lista->prox = temp->prox;
		tamanho--;
		return temp;
	}
}

No* retiraFim(No * Lista){
	if(Lista->prox == NULL)
	{
		puts("a lista está vazia");
		return NULL;
	}	
	else{
		No *ultimo = Lista->prox;
		No *penultimo = Lista;
		
		while(ultimo->	prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->	prox;
		}
	penultimo->prox = NULL;	
	puts("Nó excluido com sucesso");
	tamanho--;
	return ultimo;	}	
	}

void insereFim(No *Lista)
{
	No *novo = alocaMemoria();
	novo->prox = NULL;

	if(Vazia(Lista))
	{
		Lista->prox = novo;
	}
	else
	{
		No *tmp = Lista->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}

	tamanho++;
	puts("novo elemento inserido com sucesso");
}

void exibirLista(No *Lista)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	GetConsoleScreenBufferInfo(hConsole,&consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	if(Vazia(Lista))
	{
		puts("\n======> Lista vazia!");
	}
	else
	{
		No *tmp = Lista->prox;

		printf("Lista: ");

		while(tmp != NULL)
		{
			printf("%s | %d", tmp->nome, tmp->idade);

			SetConsoleTextAttribute(hConsole,11);
			printf(" ===> ");
			SetConsoleTextAttribute(hConsole,saved_attributes);

			tmp = tmp->prox;
		}
	}
}
