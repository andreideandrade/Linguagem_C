#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*  ---------------------------------- ESTA FUNÇÃO ABRE E FECHA UM ARQUIVO  ----------------------------------------  */
int abreArquivo()
{
    // criando a variável ponteiro para o arquivo
	FILE *pont_arq;

	//abrindo o arquivo
	pont_arq = fopen("arquivo.txt", "a");

	// fechando arquivo
	fclose(pont_arq);

	if (pont_arq == NULL)
{
    printf("ERRO! O arquivo não foi aberto!\n");
}
else
   {
     printf("O arquivo foi aberto com sucesso!");
   }

	getch();
	//system("pause");
	return(0);
}

/*  ---------------------------------- ESTA FUNÇÃO ABRE E GRAVA UMA PALAVRA NO ARQUIVO  ----------------------------  */
int abreEgrava()
{

	FILE *pont_arq; // cria variável ponteiro para o arquivo
	char palavra[20]; // variável do tipo string

	//abrindo o arquivo com tipo de abertura w -> apaga tudo dentro do arquivo e reescreve
	//abrindo o arquivo com tipo de abertura a  -> Escreve na frente do arquivo

	pont_arq = fopen("arquivo_palavra.txt", "a");

	//testando se o arquivo foi realmente criado
	if(pont_arq == NULL)
	{
	printf("Erro na abertura do arquivo!");
	return 1;
	}

	printf("Escreva uma palavra para testar gravacao de arquivo: ");
	scanf("%s", palavra);

	//usando fprintf para armazenar a string no arquivo
	fprintf(pont_arq, "%s\n", palavra);

	//usando fclose para fechar o arquivo
	fclose(pont_arq);

	printf("Dados gravados com sucesso!");

	getch();
	return 0;
}

/*  -------------------------- ESTA FUNÇÃO FAZ A LEITURA DE UM ARQUIVO E EXIBE NA TELA  ----------------------------  */
int leituradeArquivo()
{
	FILE *pont_arq;
	char texto_str[61];

	//abrindo o arquivo_frase em modo "somente leitura"
	pont_arq = fopen("arquivo_palavra.txt", "r");

	//enquanto não for fim de arquivo o looping será executado
	//e será impresso o texto
	while(fgets(texto_str, 60, pont_arq) != NULL)
	printf("%s", texto_str);

	//fechando o arquivo
	fclose(pont_arq);

	getch();
	return(0);
}

int main(void)
{
    abreArquivo();              // Cria ou se já existe abre e fecha arquivo
    abreEgrava();               // Cria ou se já existe grava palavra em arquivo
    leituradeArquivo();         // Faz a leitura de arquivos txt e exibe na tela

/* ---------------------------------------   BANCADA DE TESTE    --------------------------------------------------   */



/* ---------------------------------------------    FIM     -------------------------------------------------------   */
    return 0;
}