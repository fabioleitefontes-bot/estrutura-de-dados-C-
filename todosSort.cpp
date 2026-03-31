/*
	Name: todosMetodos
	Author: Fabio.Fonts 
	Date: 17/11/25 08:50
	Description: nesteprograma iremos apresentar o desempenho de todos os métodos de ordenaçã0
*/
 #include<windows.h>
 #include<stdio.h>
 #include<locale.h>
 #include<time.h>
 int trocas = 0, comp = 0;
 
   void bubblesort(int *, int);
   void selectionSort(int *, int);
 main()
 {
  // --- VARIÁVEIS DE TEMPO ---
	 clock_t t_inicio, t_fim;
	 double tempo_bubble, tempo_selection;

   	 //sessão de cores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD cor_original = csbi.wAttributes; 
    
    setlocale(LC_ALL,"portuguese");
	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int tam = sizeof(vet)/sizeof(int);
	
	puts("vetor original\n");
	 	for(int i=0; i < tam; i++){
	 			SetConsoleTextAttribute(hConsole, 10);
	 		printf("[%d]", vet[i]);
	 			SetConsoleTextAttribute(hConsole, 7);
	 		}
	 		
	int vet2[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};

	// --- CRONÔMETRO BUBBLE ---
	t_inicio = clock(); 
	bubblesort(vet2, tam);	
	t_fim = clock();
	tempo_bubble = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC;

	SetConsoleTextAttribute(hConsole, 15);
 	 puts("\n \n		bubble sort");
	 puts("\n =====>>>>");
	 	SetConsoleTextAttribute(hConsole, 7);			
	 printf("\n\nquantidade de comparações: "); 
	  SetConsoleTextAttribute(hConsole, 11);
	   printf("[%d]", comp);
	    SetConsoleTextAttribute(hConsole, 7);
	 printf("\n\nquantidade de trocas:"); 
	 SetConsoleTextAttribute(hConsole, 11);
	 printf("[%d]", trocas);
	 SetConsoleTextAttribute(hConsole, 7);
	 printf("\nTempo: %f segundos", tempo_bubble); // Exibe o tempo
	
	// Resetando contadores
	trocas= 0, comp=0;
	int vet3[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};

	// --- CRONÔMETRO SELECTION ---
	t_inicio = clock();
	selectionSort(vet3, tam);
	t_fim = clock();
	tempo_selection = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC;

	 SetConsoleTextAttribute(hConsole, 15);	
	 puts("\n\n		selection sort");
	 puts("\n=====>>>>");		
	 	SetConsoleTextAttribute(hConsole, 7);	
	 printf("\n\nquantidade de comparações: "); 
	  SetConsoleTextAttribute(hConsole, 14);
	   printf("[%d]", comp);
	    SetConsoleTextAttribute(hConsole, 7);
	 printf("\n\nquantidade de trocas:"); 
	 SetConsoleTextAttribute(hConsole, 14);
	 printf("[%d]", trocas);
	 SetConsoleTextAttribute(hConsole, 7);
	 printf("\nTempo: %f segundos", tempo_selection); // Exibe o tempo
 } //fim do progama
 void selectionSort(int *S, int tam){
 	
 	int i, j, menor, chave, aux;
	 //laço externo que itera do início ao fim do vetor
 	for(i=0; i < tam-1; i++){
 		
 		//assume que o menor elemento está na primeira posição do vetor
 		chave = i;
 		menor = i+1;
 		//laço interno para descobrir quem é o menor el
 			for(j= i+1; j < tam; j++){
 				if(S[j] < S[menor])
 					menor = j;
 					comp++;
 				
		 	}
		 	comp++;
		 	
		 //troca o menor elemento encontrando pelo elemento que está na chave
		 if(S[menor] < S[chave]){
		 	aux = S[chave];
		 	S[chave] = S[menor];
		 	S[menor] = aux;
		 	trocas++;
		 }
	 }	
 }
 
  void bubblesort(int *vet, int tam) {
    int aux;
    trocas = comp = 0;
    do {
        int i = 0;
        while(i < tam - 1) {
            comp++;
            if(vet[i] > vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                trocas++;
            }
            i++;
        }
        tam--;
     
    } while(tam > 1);
  
  	
  }
