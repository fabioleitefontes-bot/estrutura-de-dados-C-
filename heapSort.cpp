/*
	Name: heap sort
	Author: Fabio.Fonts 
	Date: 05/05/2025
	Description: programa para demostrar o uso do método de ordenação heap sort
*/
 #include<windows.h>
 #include<stdio.h>
 #include<locale.h>
 #include<time.h>
 
 void heapfy(int*, int, int);
 void heapSort(int*, int);
 void swap(int*, int*);
 void imprimir(int*);
 int tam;
 
 main()
 
 {
    setlocale(LC_ALL,"portuguese");
    //sessão de cores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD cor_original = csbi.wAttributes; 
    	SetConsoleTextAttribute(hConsole, 15);//negrito
    	SetConsoleTextAttribute(hConsole, 7);//branco
int vet[] = {17, 38, 2, 2, 44, 25, 19, -4, 30, 10};
 	int i;
 	tam = sizeof(vet)/sizeof(int);
 	SetConsoleTextAttribute(hConsole, 15);
 	puts("	vetor original: ");
 	SetConsoleTextAttribute(hConsole, 10);
 	imprimir(vet);
 	heapSort(vet, tam);
 		SetConsoleTextAttribute(hConsole, 15);//negrito
 	puts("\n	vetor ordenado:");
 		SetConsoleTextAttribute(hConsole, 9);//negrito
 		imprimir(vet);
 		SetConsoleTextAttribute(hConsole, 7);
 } //fim do progama
 
 //troca de elementos
 void swap(int*a, int*b){
 	int aux = *a;
 	*a = *b;
 	*b = aux;
 }
 //função que testa se os  pais são maiores ou menores que os filhos
 //invoca o swap pra fazer a troca
 void heapfy(int *V, int n, int i){
 	int maior = i;
 	int esq = 2*i +1;
 	int dir = 2*i +2;
 	
 	// se o filho da esq for maior que o pai
 	if(esq<n && V[esq] > V[maior])
 		maior = esq;
 	// se o filho da direita for maior que o pai
 	if(dir<n && V[dir] > V[maior])
 		maior = dir;
 	
	 if(maior != i){
	 	swap(&V[i], &V[maior]); 
	 	//troca os elementos
	 	heapfy(V,n,maior);
	 }	
 }
 //função principal que monta a arvore e verifica as regras max || min heap
 void heapSort(int *V, int n){
 	
 	for(int i = n/2-1; i >=0; i--){
 		heapfy(V,n,i);}
 	// troca a raiz com ultimo elemento e reduz a arvóre
	 for(int i = n-1; i>0; i--){
	 	
	 	swap(&V[0], &V[i]);
	 	heapfy(V,i,0);
	 }	
	 
 }
 void imprimir(int*V){
  for(int i = 0; i<tam; i++)
	printf("[%d]", V[i]); 
}
 
 
 
 
 
 
 
