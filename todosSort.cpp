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
 long int trocas = 0, comp = 0;
 
   void bubblesort(int *, int);
   void selectionSort(int *, int);
   void insertionSort(int*, int);
   
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
	//int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int vet[100000];
	int vet2[100000];
	int vet3[100000];
	
	
	int tam = sizeof(vet)/sizeof(int);
	srand(time(NULL));
	for(int i =0; i<tam; i++){
		vet[i] = rand()%10000;
		vet2[i] = rand()%10000;
		vet3[i] = rand()%10000;
}
	
	puts("vetor original\n");
	 	for(int i=0; i < tam; i++){
	 			SetConsoleTextAttribute(hConsole, 10);
	 		printf("[%lld]", vet[i]);
	 			SetConsoleTextAttribute(hConsole, 7);
	 		}
	 		
	//int vet2[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};

	// --- CRONÔMETRO BUBBLE ---
	t_inicio = clock(); 
	bubblesort(vet, tam);	
	t_fim = clock();
	tempo_bubble = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC;

	SetConsoleTextAttribute(hConsole, 15);
 	 puts("\n \n		bubble sort");
	 puts("\n =====>>>>");
	 	SetConsoleTextAttribute(hConsole, 7);			
	 printf("\n\nquantidade de comparações: "); 
	  SetConsoleTextAttribute(hConsole, 11);
	   printf("[%lld]", comp);
	    SetConsoleTextAttribute(hConsole, 7);
	 printf("\n\nquantidade de trocas:"); 
	 SetConsoleTextAttribute(hConsole, 11);
	 printf("[%lld]", trocas);
	 SetConsoleTextAttribute(hConsole, 7);
	 printf("\n\nTempo: %.5f segundos", tempo_bubble); // Exibe o tempo
	
	// Resetando contadores
	trocas= 0, comp=0;
	//int vet3[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};

	// --- CRONÔMETRO SELECTION ---
	t_inicio = clock();
	selectionSort(vet2, tam);
	t_fim = clock();
	tempo_selection = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC;

	 SetConsoleTextAttribute(hConsole, 15);	
	 puts("\n\n		selection sort");
	 puts("\n=====>>>>");		
	 	SetConsoleTextAttribute(hConsole, 7);	
	 printf("\n\nquantidade de comparações: "); 
	  SetConsoleTextAttribute(hConsole, 14);
	   printf("[%lld]", comp);
	    SetConsoleTextAttribute(hConsole, 7);
	 printf("\n\nquantidade de trocas:"); 
	 SetConsoleTextAttribute(hConsole, 14);
	 printf("[%lld]", trocas);
	 SetConsoleTextAttribute(hConsole, 7);
	 printf("\n\nTempo: %.5f segundos", tempo_selection); // Exibe o tempo
	 
	 	// Resetando contadores
	trocas= 0, comp=0;
	//int vet4[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};

	// --- CRONÔMETRO INSERTION ---
	t_inicio = clock();
	insertionSort(vet3, tam);
	t_fim = clock();
	tempo_selection = ((double)(t_fim - t_inicio)) / CLOCKS_PER_SEC;

	 SetConsoleTextAttribute(hConsole, 15);	
	 puts("\n\n		insertion sort");
	 puts("\n=====>>>>");		
	 	SetConsoleTextAttribute(hConsole, 7);	
	 printf("\n\nquantidade de comparações: "); 
	  SetConsoleTextAttribute(hConsole, 3);
	   printf("[%lld]", comp);
	    SetConsoleTextAttribute(hConsole, 7);
	 printf("\n\nquantidade de trocas:"); 
	 SetConsoleTextAttribute(hConsole, 3);
	 printf("[%lld]", trocas);
	 SetConsoleTextAttribute(hConsole, 15);
	 printf("\n\nTempo: %.5f segundos", tempo_selection); // Exibe o tempo
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
  void insertionSort(int *V, int tam){
 	
 	int i, j, chave;
 	
 	for(i=1; i < tam; i++){
 		chave = V[i];
 		j = i -1;
 		while(j>=0 && chave < V[j]){
 			V[j+1] = V[j];
 			j--;
 			comp++;
 			trocas++;
		 }
		 V[j+1]= chave;
		 trocas++;
	 }
 }
 
