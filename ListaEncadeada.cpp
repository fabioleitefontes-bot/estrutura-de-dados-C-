/*
	Name: listasEncadeadas.cpp
	Author: Fabio.Fonts 
	Date: 17/11/25 08:50
	Description: implementação de lista encadeada
*/
 #include<windows.h>
 #include<stdio.h>
 #include<conio.h>
 #include<locale.h>
 #include<stdlib.h>
 
 typedef struct No
 {
 	char nome[10];
 	int idade;
 	No *prox;
 };
 
 //variavel global
 int tamanho; //tamanho da lista
 
 //seção de prototipação
 
 int Vazia(No *);
 No *alocaMemoria();
 void insereFim(No *);
 No *retiraFim(No *);
 void insereInicio(No *);
 No * retiraInicio(No *);
 void exibirLista(No *);
 void iniciarLista(No *);
 int menu();
 void tratarOpcao(No *); 
 
 
 
 
 main() //início do programa
 {
    setlocale(LC_ALL,"portuguese");
    
 No *Lista = (No *) malloc(sizeof(No));
 if(!Lista){
 		printf("\nnão há espaço na memória pra criar lista\n");
 		exit(1);
 }
 else{
 	insereFim(Lista);
 }
 
 	
 } //fim do progama
 
 //funçao para apresentar o menu
 
 int menu()
 {
 	;
 }
 
 //função para tratar a escolha da opcao de menu
 void tratarOpcao()
 {
 	;
 }
 //função para inicializar a lista
 void iniciarLista(No *Lista)
 {
 	Lista->prox = NULL;
 	tamanho = 0;
 }
 //função que testa se a lista está vazia
 
 int Vazia(No *Lista)
 {
 	if(Lista->prox == NULL)
 		return 1;//está vazia
 	else
	 	return 0;	
 	
 }
 
 //função para alocação de memoria para um Nó
 No *alocaMemoria()
 {
 	No *novo = (No *) malloc(sizeof(No));
 	if(!novo){
 		printf("\nnão há espaço na memória\n");
 		exit(1);
	 }
	 else{
	 	printf("nome: "); scanf("%s", &novo->nome);
	 	
	 	printf("idade: "); scanf("%s", &novo->idade);
	 	return novo;
	 }
 }
 //funcao para inserir um nó no fim da lista
 void insereFim(No *Lista){
 	No *novo = alocaMemoria();
 	novo->prox = novo;
 	if(Vazia(Lista))
 	Lista->prox;
 	else{
 		No *tmp = Lista->prox;
 		while(tmp != NULL)
 		tmp = tmp->prox;
 		tmp->prox = novo;
	 }
	 tamanho++;
	 puts("novo elemento inserido com sucesso");
 }
 
 //imprimir lista
 
 void exibirLista(No *Lista)
 {
 	if(Vazia(Lista))
		puts("----->>>>  lista vazia");
	else
	{
		No *tmp;
		tmp = Lista->prox;
		printf("lista: ");
		while(tmp != NULL){
			printf("|%s", tmp->nome);
			printf(" %d anos|", tmp->idade);
			printf("==> ");
			tmp= tmp->prox;
		}
	}	 	
 }
 
 
 
 
 
 
