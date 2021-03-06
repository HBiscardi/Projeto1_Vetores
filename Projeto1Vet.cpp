#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int idUsuario[1000], vacina[1000], i=0, opc, cont=0,x=0;
char nome[1000][50], eMail[1000][50], sexo[1000][10], endereco[1000][150];
double altura[1000];

int menu();
void cadastrarId();
void cadastrarNome();
void cadastrarSexo();
void cadastrarAltura();
void cadastrarVacina();
void cadastrarEmail();
void ordenacaoVetor();
void cadastrarEndereco();
void pesquisar();
void backup();
int buscaBinariaId(int id[], int tamamnho, int x);
//int idUsuario[i], int vacina[i],nome[i], eMail[i], sexo[i], endereco[i], altura[i]//
int main(){
	
	do{
		opc = menu();
		switch(opc){
			case 1:
				system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tCadastrar Novo usuario");
				printf("\n============================================================================================\n");
				cadastrarId();
				cadastrarNome();
				cadastrarEmail();
				cadastrarSexo();
				cadastrarVacina();
				cadastrarEndereco();
				cadastrarAltura();
				i++;
				cont++;
				printf("\n\t\t\tCadastro realizado com sucesso!!!\n\n");				
				system("pause");
				
				break;
				
			case 2:
					ordenacaoVetor();
					system("cls");
					printf("\n============================================================================================\n");
					printf("\t\t\tUsuarios Cadastrados");
					printf("\n============================================================================================\n");
				for(i=0;i<cont;i++){
					if(idUsuario[i]!= 0){
						printf("\n\tID Usuario...........................................: %i\n", idUsuario[i] );
						printf("\tNome.................................................: %s", nome[i]);
						printf("\tEmail cadastrado.....................................: %s\n",eMail[i]);
						printf("\tSexo.................................................: %s\n", sexo[i]);
						printf("\tTomou vacina?........................................: ");
					
						if(vacina[i] == 1){
							printf("SIM\n");
						}else{
							printf("NAO\n");
						}
						printf("\tEndereco.............................................: %s", endereco[i]);
						printf("\tAltura...............................................:  %.2f\n", altura[i]);
						printf("\n");					
					}					
				}
			system ("pause");
				break;
			case 3:
				system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tPesquisar Usuarios Cadastrados");
				printf("\n============================================================================================\n");
				pesquisar();
						
			system ("pause");
				break;
			case 4:
				system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tExcluir Usuarios Cadastrados");
				printf("\n============================================================================================\n");
					//insira aqui a fun????o excluir//
			system ("pause");
			break;
			case 5:
				system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tEditar Usuarios Cadastrados");
				printf("\n============================================================================================\n");
					//insira aqui a fun????o Editar//
			system ("pause");
				break;
			case 6:
               system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tRealizar Backup");
				printf("\n============================================================================================\n");
					backup();
			system ("pause");
				break;
			case 7 :
               system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tRestaurar Backup");
				printf("\n============================================================================================\n");
					//insira aqui a fun????o restaurar Backup//
			system ("pause");
				break;
		}

	}while(opc !=8);

	return 0;
}
int menu(){
system ("cls");
	int opcao=0;
	do{
		system ("cls");
		printf("\n==============================================================\n");
		printf("\tSelecione uma opcao: ");
		printf("\n==============================================================\n");
		printf(" [1]\tCadastrar Novo Usuario\n");
		printf(" [2]\tListar Usuarios Cadastrados\n");
		printf(" [3]\tPesquisar Usuario\n");
		printf(" [4]\tExcluir Cadastro\n");
		printf(" [5]\tEditar Cadastro\n");
		printf(" [6]\tBackup\n");
		printf(" [7]\tSair\n");
		printf("\nOpcao desejada: ");
		scanf("%d", &opcao);
		getchar();
		printf("\n");
		if(opcao > 7 || opcao < 1){
			printf("\n\tATENCAO!!!\n\n");
			printf("\tOpcao Invalida\n\n");
			system("pause");
		}
	}while(opcao == 0);
return opcao;
}
void cadastrarId(){
	int idTemp;
	do{
		srand(time(NULL));
		idTemp = rand()%100;

	}while (idTemp == idUsuario[i]);

	idUsuario[i] = idTemp;
	printf("ID Usuario...................................................: %i\n", idUsuario[i]);
}
void cadastrarNome(){
	do{
		printf("Informe seu nome.............................................: ");
   		fgets(nome[i],sizeof(nome[i]), stdin);
		if (strlen(nome[i])== 1){

			printf("Este campo nao pode ser vazio\n");
		}
	}while(strlen(nome[i])== 1);
}
void cadastrarSexo(){
	do{
		printf("Informe sexo: Masculino, Feminino ou Nao-declarado...........: ");
   		scanf("%s", sexo[i]);
		fflush(stdin);
   		strupr(sexo[i]); //fun????o que converte a string para mai??sculo.
		if(strcmp(sexo[i],"MASCULINO")!=0 && strcmp(sexo[i],"FEMININO")!=0 && strcmp(sexo[i], "NAO-DECLARADO")!=0){
			printf("Erro, opcao invalida\n");
		}
	}while(strcmp(sexo[i],"MASCULINO")!=0 && strcmp(sexo[i],"FEMININO")!=0 && strcmp(sexo[i], "NAO-DECLARADO")!=0);
}
void cadastrarEndereco(){
	fflush(stdin);
	do{
		printf("Informe seu Endereco.........................................: ");
   		fgets(endereco[i],sizeof(endereco[i]), stdin);
		if (strlen(endereco[i])== 1){

			printf("Este campo nao pode ser vazio\n");
		}
	}while(strlen(endereco[i])== 1);
}
void cadastrarAltura(){
	do{
		printf("Informe sua altura separada por '.'ponto: ex: 1.60...........: ");
		scanf("%lf", &altura[i]);
		if (altura[i] < 1 || altura[i] > 2){
			printf("Erro, altura invalida\n");
			printf("valor n??o pode ser superior a 2.00 mts\n");
		}
	}while(altura[i] < 1 || altura[i] > 2);
}
void cadastrarVacina(){
	do{
		printf("Tomou a vacina? digite [1] para SIM ou [2] para NAO..........: ");
		scanf("%d", &vacina[i]);
		if (vacina[i] < 1 || vacina[i] > 2){
			printf("Erro, opcao invalida\n");
		}
	}while(vacina[i] < 1 || vacina[i] > 2);
}
void cadastrarEmail(){

char *validador;
	do{
		printf("Informe o seu e-mail.........................................: ");
		scanf("%s", eMail[i]);
		strlwr(eMail[i]); //fun????o que converte a string para minusculo.
		validador = strchr(eMail[i],'@'); //fun????o que percorre a string comparando o caractere @ com cada caractere da string, caso n??o encontre retorna NULL.
		if(validador == NULL){
			printf("digite um e-mail valido\n");
		}
	}while(validador == NULL);
}
void ordenacaoVetor(){
	
	int aux_idUsuario,contador=0, aux_vacina, j=0;
	char Aux_nome[50], auxEmail[50], auxSexo[10],auxEndereco[150];
	double auxAltura;
	
	
	for(i = 0; i < cont; i++){
		for(j = i+1; j < cont; j++){
			if(idUsuario[i] > idUsuario[j]){
				
				aux_idUsuario = idUsuario[i];
				idUsuario[i] = idUsuario[j];
				idUsuario[j] = aux_idUsuario;
				
				strcpy(Aux_nome,nome[i]);// strcpy funcao da biblioteca string.h para copiar um vetor de string para outro.
				strcpy(nome[i],nome[j]);
				strcpy(nome[j],Aux_nome);
				
				strcpy(auxEmail,eMail[i]); 
				strcpy(eMail[i],eMail[j]);
				strcpy(eMail[j],auxEmail);
				
				strcpy(auxSexo,sexo[i]);
				strcpy(sexo[i],sexo[j]);
				strcpy(sexo[j],auxSexo);
				
				aux_vacina = vacina[i];
				vacina[i] = vacina[j];
				vacina[j] = aux_vacina;
				
				strcpy(auxEndereco,endereco[i]);
				strcpy(endereco[i],endereco[j]);
				strcpy(endereco[j],auxEndereco);
				
				auxAltura = altura[i];
				altura[i] = altura[j];
				altura[j] = auxAltura;								
			}	
		}
	}			
}
void pesquisar(){
	
	int idPesquisado, opcao, resultado=0, identificador=0;
	char opcao2[50];
	do{
		printf("\nInforme a opcao de pesquisa:\n[1] ID\n[2] EMAIL\n");
		scanf("%d",&opcao);
		printf("\nOpcao desejada: %d\n\n",opcao);
		
		if(opcao < 1 || opcao > 2){
			printf("Erro, opcao invalida\n\n");			
		}		
	}while(opcao < 1 || opcao > 2);
	
	
	switch(opcao){
		case 1:
			printf("Digite o Id que deseja procurar: ");
			scanf("%d", &idPesquisado);
			resultado = buscaBinariaId(idUsuario, cont,idPesquisado);
			
			if(resultado != -1){
				printf("Valor %d foi encontrado na posicao %d que tem o valor %d\n",idPesquisado,resultado, idUsuario[resultado]);
				printf("\n\tID Usuario...........................................: %i\n", idUsuario[resultado] );
				printf("\tNome.................................................: %s", nome[resultado]);
				printf("\tEmail cadastrado.....................................: %s\n",eMail[resultado]);
				printf("\tSexo.................................................: %s\n", sexo[resultado]);
				printf("\tTomou vacina?........................................: ");
				if(vacina[i] == 1){
					printf("SIM\n");
				}else{
					printf("NAO\n");
				}
				printf("\tEndereco.............................................: %s", endereco[resultado]);
				printf("\tAltura...............................................:  %.2f\n", altura[resultado]);
				printf("\n");
			}else{
			printf("Valor nao encontrado\n");	
			break;			
		case 2:
			
				printf("Informe o e-mail......................................: ");
				scanf("%s", opcao2);
				fflush(stdin);
				strlwr(opcao2); //fun????o que converte a string para minusculo.
				for(i=0;i<cont;i++){
					if(strcmp(opcao2,eMail[i])==0){
						printf("\n\tID Usuario...........................................: %i\n", idUsuario[i] );
						printf("\tNome.................................................: %s", nome[i]);
						printf("\tEmail cadastrado.....................................: %s\n",eMail[i]);
						printf("\tSexo.................................................: %s\n", sexo[i]);
						printf("\tTomou vacina?........................................: ");
					
						if(vacina[i] == 1){
							printf("SIM\n");
							}else{
							printf("NAO\n");
							}
							printf("\tEndereco.............................................: %s", endereco[i]);
							printf("\tAltura...............................................:  %.2f\n", altura[i]);
							printf("\n");
							identificador++;					
					}
				}
					if(identificador==0){
						printf("Nao Localizado, tente novamente.\n");
						printf("%s\n", opcao2);
						printf("%s\n", eMail[i]);

					}
			break;
		}
	}
}
int buscaBinariaId(int id[1000], int tamanho, int x){
	int inicio = 0, fim = tamanho - 1, meio;
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		
		if(x==id[meio]){
			return meio;
		}else if(x < id[meio]){
			fim = meio - 1;
			
		}else{
			inicio = meio + 1;			
		}		
	}
	return -1;	
}
void backup(){
	
	/*int idUsuario[1000], vacina[1000], i=0, opc, cont=0;
	char nome[1000][50], eMail[1000][50], sexo[1000][10], endereco[1000][150];
	double altura[1000];*/		
	
	int bkp_idUsuario[1000], bkp_vacina[1000];
	char bkp_nome[1000][50], bkp_eMail[1000][50], bkp_sexo[1000][10], bkp_endereco[1000][150];
	double bkp_altura[1000];
	
	int opcao=0, i=0;
	
	do{
		printf("[1] Sim\n[2] Nao\n[3] Restaurar backup\n", opcao);/* imprime na tela a opcao para o usuario*/	
		scanf("%d", &opcao);//le a opcao desejada/
		
		printf("Opcao desejada: %d\n", opcao);	/* imprime a opcao desejada */	
		
		if(opcao < 1 || opcao > 3){/* valida a opcao informada pelo usuario*/
			printf("\nErro, opcao invalida\n\n");/*imprime erro casa a opcao seja diferente da informada*/			
		}		
		
	}while(opcao < 1 || opcao > 3);	/* estrutura de repeticao que executa pelo menos uma vez e enquanto as condi????es forem verdadeira*/
	
	
	if(opcao == 1){
		if(idUsuario[i]!=NULL){
			for(i = 0; i < 1000; i++){
				bkp_idUsuario[i] = idUsuario[i];
				strcpy(bkp_nome[i],nome[i]);
				strcpy(bkp_eMail[i], eMail[i]);
				strcpy(bkp_sexo[i],sexo[i]);
				bkp_vacina[i] = vacina[i];
				strcpy(bkp_endereco[i],endereco[i]);
				bkp_altura[i] = altura[i];
				x++;/* contador para verificar se existe backup	*/
		}	
		printf("\n==============================================================\n");
		printf("\tBackup realizado com sucesso");//imprime mensagem para visualisacao do usuario.
		printf("\n==============================================================\n");
			
		}else{
			printf("\n==============================================================\n");
			printf("\tBase de dados vazia, Backup nao realizado ");
			printf("\n==============================================================\n");			
		}		
	}else if (opcao == 2){
		printf("\n==============================================================\n");
		printf("\tBackup nao realizado ");
		printf("\n==============================================================\n");		
	}else if(x != 0){
		for(i = 0; i < 1000; i++){
				idUsuario[i] = bkp_idUsuario[i];
				strcpy(nome[i],bkp_nome[i]);
				strcpy(eMail[i],bkp_eMail[i]);
				strcpy(sexo[i],bkp_sexo[i]);
				vacina[i]= bkp_vacina[i] ;
				strcpy(endereco[i],bkp_endereco[i]);
				altura[i]= bkp_altura[i];
				x++;/* contador para verificar se existe backup	*/
		}			
		printf("\n==============================================================\n");
		printf("\tBackup Restaurado ");
		printf("\n==============================================================\n");		
	}else{
		printf("\n==============================================================\n");
		printf("\tNao existe Backup para restauracao, operacao nao realizada ");
		printf("\n==============================================================\n");
	}		
		
	for(i = 0; i < cont; i++){	
		if(idUsuario[i] != 0 || x != 0 ){			
			printf("\n\tID Usuario...........................................: %i\n", bkp_idUsuario[i] );
			printf("\tNome.................................................: %s\n", bkp_nome[i]);
			printf("\tEmail cadastrado.....................................: %s",bkp_eMail[i]);
			printf("\n\tSexo.................................................: %s\n", bkp_sexo[i]);
			printf("\tTomou vacina?........................................: ");
			
			if(bkp_vacina[i] == 1){
				printf("SIM\n");
			}else if(bkp_vacina[i] == 2){
				printf("NAO\n");
				}else{
					printf(" \n");		
				}	
			printf("\tEndereco.............................................: %s\n", bkp_endereco[i]);
			printf("\tAltura...............................................:  %.2f", bkp_altura[i]);
			printf("\n");		
		}
	}
}