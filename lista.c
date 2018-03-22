#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 45
 typedef struct {
	int matricula;
	char nome[30];
	float nota1, nota2, nota3;

}aluno;

typedef struct {
	int qtd;
	 aluno dados[MAX];
}Lista;

Lista* cria_Lista(){
	Lista *li;
	li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		li->qtd = 0;
	}
	return li;
}
int tamanho_lista(Lista *li){
	if(li == NULL){
		return -1;
	}else{
		return li->qtd;
	}
}
int lista_cheia(Lista *li){
	if(li == NULL){
		return -1;
	}
	return (li->qtd == MAX);
}
int lista_vazia(Lista *li){
	if(li == NULL){
		return -1;
	}
	return (li->qtd == 0);
}

int insere_lista(Lista *li){
	if(li == NULL){
		return 0;
	}
	if(lista_cheia(li)){
		return 0;
	}
	printf("Nome do aluno:");
	scanf("%s",& li->dados[li->qtd].nome);
	printf("Matricula:");
	scanf("%d",& li->dados[li->qtd].matricula);
	printf("Nota1 do aluno:");
	scanf("%f",& li->dados[li ->qtd].nota1);
	printf("Nota2 do aluno:");
	scanf("%f",& li->dados[li ->qtd].nota2);
	printf("Nota3 do aluno:");
	scanf("%f",& li->dados[li ->qtd].nota3);

	li->qtd++;
	return 1;
}
int Buscar_aluno(Lista*li){
int posi;
aluno Aluno;
int x;
	printf("Digite 1 para prucurar por nome:\n");
	printf("Digite 2 para prucurar por matricula:\n");
	printf("Digite 3 para prucurar por posicao:\n");
	scanf("%d",& x);
	
	if(x=1){
		int i;
		printf("Nome do aluno:");
		scanf("%s",&Aluno.nome);
			for(i=0; i < li->qtd; i++){
				if( strcmp(li->dados[i].nome,Aluno.nome) == 0 ){
					return i;		
				}		
			}
		printf("Nao encontrou o Nome");
		return -1;
	}
	if(x=2){
		int i;
		printf("Digite o numero da matricula:");
		scanf("%d",Aluno.matricula);
			for( i=0; i< li->qtd ;i++){
				if(li->dados[i].matricula==Aluno.matricula){
					return i;	
				}
			}
		}
	if(x=3){
		printf("Digite a posicao:");
		scanf("%d",posi);
		
				if(posi >= 0){
					return posi-1;	
				}
					else{
						printf("Posicao invalida");
						return -1;
					}
		}
	return -1;
}

void remover_aluno(Lista*li){

int x=Buscar_aluno(li);
int i =0;
	if(x ==-1){
		for (i = x; i < li->qtd; i++ ){
		li->dados[i]= li->dados[i+1];
		}
			li->qtd--;
			printf("Aluno removido");
	}
}

void Aluno_aprovado(Lista*li){
	int x = Buscar_aluno(li);
	float soma = (li->dados[x].nota1) + (li->dados[x].nota2) + (li->dados[x].nota3);
	
	if(soma >= 60 ){
	printf("Nome %s:",li->dados[x].nome);	
		printf("APROVADO");
	}
		else {
		printf("Nome %s:",li->dados[x].nome);
				printf("Reprovado");
		
		}
		
}
void Lista_alunos(Lista*li){
	float soma,soma1;
	int i;

		for( i=0; i< li->qtd;i++){
			printf("Posicao: %d", i+1);					
			printf("Nome: %s",li->dados[i].nome);			
			printf("Matricula: %d", li->dados[i].matricula);			
			printf("Nota 1: %f",li->dados[i].nota1);				
			printf("Nota 2: %f\n",li->dados[i].nota2);		
			printf("Nota 3: %f\n",li->dados[i].nota3);
	
			soma = (li->dados[i].nota1) + (li->dados[i].nota2) + (li->dados[i].nota3);
 			soma1 = (li->dados[i].nota1) + (li->dados[i].nota2) + (li->dados[i].nota3)/li->qtd;
		 }

	printf("Soma total:%f",soma);
	printf("Media:%f",soma1);
}



int main (){
Lista*li= cria_Lista();

int op,x,y,z,soma;


do{
		printf ("1-Adicionar Aluno.\n");
		printf ("2-Buscar Aluno.\n");
		printf ("3-Verificar se um aluno esta aprovado.\n ");
		printf ("4-Mostrar todos os alunos e a soma e a media.\n");
		printf ("5-Remover Aluno.\n");
		printf ("0-Sair.\n");
		scanf ("%d",&op);
		system("cls");
			switch (op){	
				case 1:	
					x = insere_lista(li);
					break;
			
				case 2:
					if(li->qtd==0){
					printf("Lista Vazia");
					}else{
					printf ("  .::Buscar aluno::.\n");
					y = Buscar_aluno(li);
					if (y != -1){
						printf("Posicao:%d", y+1);					
						printf("Nome: %s\n",li->dados[y].nome);			
						printf("Matricula: %d\n", li->dados[y].matricula);			
						printf("Nota 1: %f\n",li->dados[y].nota1);				
						printf("Nota 2: %f\n",li->dados[y].nota2);		
						printf("Nota 3: %f\n",li->dados[y].nota3);
					}
				}			
					break;
				
			case 3:
				if(li->qtd==0){
					printf("lista vazia.\n");
				}
					else{
						Aluno_aprovado(li);	
					}
			break;	
			
			case 4:
				if(li->qtd==0){
					printf("lista vazia.\n");
				}
		  			else {
					  
					  Lista_alunos(li);
					  }
			break;
			
			case 5:
				if(li->qtd==0){
					printf("lista vazia.\n");
				}
					else {
					  	remover_aluno(li);
					}
			break;
				
			case 0:
				printf("Saindo...");
			break;
				
			default: 
				printf ("Opcao invalida...\n");	
					
		}
		printf("\n");
		system("pause");
		system("cls");
}while(op!=0);
return 0 ;
}

