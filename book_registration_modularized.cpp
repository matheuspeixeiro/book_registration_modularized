/* Programa completo de baixa complexidade usando struct para cadastrar 5 livros */

/*declaracao das bibliotecas*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>

/*declaracao das variaveis e constantes*/
int idMenu=1, contador=0;
const int maximo = 5;

/*declaracao de funcoes*/
void cadastrar(), imprimir();

/* Instanciamento da struct cadastro livros*/
struct cadastro{
	int codigo;
	int isbn;
	char nome[51];
	char autor[31];
	int paginas;
	char editora[41];
	float preco;
};

struct cadastro livros[maximo];

/* funcao principal */
main(){
	do {
	//MAIN = MENU
	system("cls");
	printf("Menu principal!\nInforme uma operacao\n\t< 1- inserir livros >");
	printf("\n\t< 2- imprimir livros cadastrados >\n\t< 9- sair da aplicacao >\n");
	scanf("%d", &idMenu);
	switch(idMenu){
		case 1:
			if (contador<maximo){
				//chama funcao de cadastro
				cadastrar();
			} else {
				system("cls");
				printf("\nMaxima quantidade de livros cadastrada!\n\n");
				system("pause");
			}
			
			break;
		case 2:
			if (contador>0){
				//chama funcao de impressao
				imprimir();
			} else {
				system("cls");
				printf("\nNenhum livro foi cadastrado!\n\n");
				system("pause");
			}
			
			break;
		case 9:
			//encerra a aplicacao
			printf("\n\n");
			system("pause");
		}
	} while (idMenu != 9);
}

/* funcao cadastrar */
void cadastrar(){
	// Entrada de dados - estrutura de repeticao para inserir
	char resp='S';
	while(contador<maximo) {
		system("cls");
		printf("\n{ Livro %d }", contador+1);
		//codigo
		printf("\nCodigo..: ");
		scanf("%d", &livros[contador].codigo);
		//isbn
		printf("\nIsbn..: ");
		scanf("%d", &livros[contador].isbn);
		//Nome
		printf("\nNome..: ");
		fflush(stdin);
		gets(livros[contador].nome);
		//Autor
		printf("\nAutor..: ");
		fflush(stdin);
		gets(livros[contador].autor);
		//Paginas
		printf("\nNumero de paginas..: ");
		scanf("%d", &livros[contador].paginas);
		//Editora
		printf("\nEditora..: ");
		fflush(stdin);
		gets(livros[contador].editora);
		//Preco
		printf("\nPreco..: ");
		scanf("%f", &livros[contador].preco);
		
		//Controle de fluxo
		if(contador<maximo-1){ //qtd-1 porque o contador comeca em 0
			printf("\nDeseja inserir mais? <S/N> ");
			resp = toupper(getche());
			printf("\n");
		}
		
		// verificando a resposta
		if (resp == 'N'){
			//contador aqui devido o break abaixo
			contador++;
			break;
		}
		contador++;
	}
}

/* funcao imprimir */
void imprimir(){
	system("cls");
	int i=0;
	do{
		//Nome e Autor
		printf("Livro ");
		puts(livros[i].nome);
		printf("Autor: ");
		puts(livros[i].autor);
		//Codigo, ISBN, Paginas, Preco
		printf("Codigo: %d\nISBN: %d\nPaginas: %d\nPreco: R$%.2f\n\n", livros[i].codigo,livros[i].isbn,livros[i].paginas,livros[i].preco);
		
		i++;
	} while (i<contador);
	system("pause");
}
