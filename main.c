#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[30], autor[20], editora[30];
	int ano;
}LIVRO;

typedef struct no{
	LIVRO conteudo;
	struct no *prox;
}NO_PILHA;

typedef struct {
	NO_PILHA *topo;
}PILHA;



void criaPilha (PILHA *pilha){
	pilha = NULL;
}


//Início da Função tamanho 
int tamanho(PILHA *pilha){
	int cont = 0;
	NO_PILHA *aux = pilha->topo;
	if(aux == NULL)
		return cont;
	else{
		do{
			aux = aux->prox;
			cont++;
		}while(aux != NULL);
		return cont;
	}
}

//Início da Função liberaPilha
void liberaPilha (PILHA *pilha){
	NO_PILHA *aux = pilha->topo;
	if (aux == NULL)
		printf (" Na pilha nÃo existem elementos! \n");
	else{
		do{
			aux = pilha->topo->prox;
			free (pilha->topo);
			pilha->topo = aux;
			printf (" Pilha esvaziada com sucesso! \n");
		}while (aux != NULL);
	}
}

//Início da Função empilhar
void empilhar (PILHA *pilha, LIVRO dados){
	NO_PILHA *novo = (NO_PILHA*) malloc (sizeof(NO_PILHA));
	if (novo != NULL)	{
		novo->conteudo = dados;
		novo->prox = pilha->topo;
		pilha->topo = novo;
		printf ("Inserido com sucesso! \n");
	}	
}


//Início da Função desempilhar
void desempilhar (PILHA *pilha){
	NO_PILHA *aux;
	if (pilha->topo == NULL)
		printf ("Vazia \n");
	else	{
		aux = pilha->topo;
		pilha->topo = pilha->topo->prox;
		free(aux);
		printf (" Livro removido com sucesso! \n");
	}
}

//Início da Função listar
void listar (PILHA *pilha){
	NO_PILHA *aux = pilha->topo;
	if (aux == NULL)
		printf ("Nao existem livros cadastrados \n");
	else{ 
		do{
			printf (" NOME: %s \n", aux->conteudo.nome);
			printf (" ANO: %d \n", aux->conteudo.ano);
			printf (" AUTOR: %s \n", aux->conteudo.autor);
			printf (" EDITORA: %s \n \n", aux->conteudo.editora);
			aux = aux->prox;
		}while (aux != NULL);
	}
}

//Início da Função pesquisar
void pesquisar (PILHA *pilha, int ano){
	NO_PILHA *aux = pilha->topo;
	int armazena;
	if (aux == NULL)
		printf ("Nao existem livros cadastrados \n");
	else{
		do{
			if (aux->conteudo.ano == ano){
				printf ("\n NOME: %s \n", aux->conteudo.nome);
				printf (" ANO: %d \n", aux->conteudo.ano);
				printf (" AUTOR: %s \n", aux->conteudo.autor);
				printf (" EDITORA: %s \n \n", aux->conteudo.editora);
			}
			else{
				armazena = 1;
			}
		}while (aux != NULL);
		if (armazena == 1)
			printf ("Livro nao encontraodo \n");
	}
}

//Incío da Função main
int main (){
	PILHA *pilha = NULL;
	LIVRO dados;
	int op, ano;
	criaPilha(pilha);
	
	do{
		printf (" \n \tESCOLHA UMA OPCAO DE MENU \n");
		printf ("----------------------------------------- \n");
		printf (" 1 - Empilhar Livros \n");
		printf (" 2 - Desempilhar Livros \n");
		printf (" 3 - Listar Todos os Livros \n");
		printf (" 4 - Pesquisar Livros \n");
		printf (" 5 - Esvaziar \n");
		printf (" 6 - Tamanho \n");
		printf (" 7 - Sair \n");
		printf (" Opcao: ");
		scanf ("%d", &op);
		
		switch (op){
			case 1:
				printf (" \n \t INSERCAO DE LIVROS \n");
				printf ("----------------------------------------- \n");
				printf (" Fornecas as informacoes abaixo \n");
				printf (" NOME: ");
				scanf ("%s", dados.nome);
				printf (" AUTOR: ");
				scanf ("%s", dados.autor);
				printf (" EDITORA: ");
				scanf ("%s", dados.editora);
				printf (" ANO: ");
				scanf ("%d", &dados.ano);
				empilhar(&pilha, dados);
				break;
			case 2:
				printf (" \n \t REMOCAO DE LIVROS \n");
				printf ("----------------------------------------- \n");
				desempilhar(&pilha);
				break;
			case 3:
				printf (" \n \t TODOS LIVROS CADASTRADOS \n");
				printf ("----------------------------------------- \n");
				listar(&pilha);
				break;
			case 4:
				printf (" \n \t PESQUISA DE LIVROS \n");
				printf ("----------------------------------------- \n");
				printf (" Informe o ano \n");
				printf (" ANO: ");
				scanf ("%d", &ano);
				pesquisar (&pilha, ano);
				break;
			case 5:
				printf (" \n \t ESVAZIANDO A PILHA \n");
				printf ("----------------------------------------- \n");
				liberaPilha (&pilha);
				break;
			case 6:
				printf (" \n \t TAMANHO \n");
				printf ("----------------------------------------- \n");
				printf (" Tamanho: %d ",tamanho(&pilha));
				break;
			case 7:
				printf  (" Programa Encerrado \n");
				break;
			default:
				printf (" Escolha uma valor valido \n");
		}
	}while (op != 7);
}