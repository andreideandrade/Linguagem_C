#include <stdio.h>
#include <stdlib.h>

/*     ------------------------------  CONSTANTES PARA IMPRIMIR NA FICHA DE CADASTRO    ---------------------------   */
const char	RECEPCAO[45] = {"\nFaça seu cadastro para ser atendido.\n"},
        	CPF[25] = {"\nInforme seu CPF:\t"},
        	NOME[25]={"\nInforme seu nome:\t"},
        	SEXO[25]={"\nInforme seu sexo:\t"},
        	IDADE[25]={"\nInforme sua idade:\t"};
/*     ------------------------------  STRUCT DE CADASTRO  --------------------------------------------------------   */
struct cadastro{
    char	nome[200];//{ "Sem nome"},
	char	 cpf[16],// = {"000.000.000-00"},
	char
        sexo[3],//={"0"},
        idade[5];//={"0"};
};  //  Lista de cadastro do paciente
/*     ------------------------------  Funções de protótipos para inicialização -----------------------------------   */
int linha();
int pesquisa(int pergunta);


/*	-------------------------	FUNÇÃO PRINCIPAL ----------------------------	*/
int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "");                   //   FORMATA LETRAS
    struct cadastro ficha;                             //   CHAMA STRUCT DE CADASTRO DE PACIENTE
    int resposta=0,
        total=0,                                       //   Variaveis do questionario
        soma[10]{5,1,1,1,3,10,1,1,10,3},               //   VETOR POPULADO COM PONTUAÇÃO DAS PESQUISAS
        resultado[10];                                 //   VETOR POPULADO COM RESPOSTAS DAS PESQUISAS
/*     ------------------------------  Entrada de dados para struct  ----------------------------------------------

    printf(RECEPCAO);                                  //  MENSAGEM DE RECEPÇÃO
    printf(CPF);    scanf("%s", ficha.cpf);     //  MENSAGEM CPF
    printf(NOME);   scanf("%s", ficha.nome);    //  MENSAGEM NOME
    printf(SEXO);   scanf("%s", ficha.sexo);    //  MENSAGEM SEXO
    printf(IDADE);  scanf("%s", ficha.idade);   //  MENSAGEM IDADE
  ------------------------------  IMPRIME EM TELA AS PERGUNTAS UMA DE CADA VEZ   ----------------------------    */

//=======================================     CORRIGIR COM DEFEITO ========================================================
   for (int i = 0; i < 10; ++i)
   {
       printf("%d",pesquisa(i));
//       CONTINUAR DAQUI
//       Criar as funçoes aos poucos

   }

    //  =========================================  CORRIGIR COM DEFEITO===========================================================

    printf("\nTotal no for\t%d\n", total);
    printf("\nTotal resultado\t%d\n", total);
/*     ------------------------------  TESTE DE SAÍDA DE DADOS   --------------------------------------------------   */
    printf("\nDados do Paciente:\n");
    printf("\nCPF:  %s\nNome:   %s \nSexo:  %s \nIdade: %s \n", ficha.cpf, ficha.nome, ficha.sexo, ficha.idade);
    linha();                                                 // imprime linha
/*     ------------------------------  AVALIA O RESULTADO E DIRECIONA PACIENTE O A ALA INDICADA   -----------------   */
    printf("\nDirija-se para ala:\t");
    if( total > 19 )        //  Risco Alto!
    {
        printf("Risco Alto!\n");
    }
    else if( total > 9 )    //  Risco Médio!
    {
        printf("Risco Médio!\n");
    }
    else                    //  Risco Baixo!
    {
        printf("Risco Baixo!\n");
    }
    return 0;




/*	-------------------------	FIM DO MAIN ----------------------------	*/
	system("pause");
	return 0;
}

/*     ------------------------------  OUTRAS FUNÇÕES -------------------------------------------------------------   */
int pesquisa(int pergunta)  //  Lista com as perguntas da pesquisa
{
        switch (pergunta)
        {
            case 0 :
                printf("\np1 - Tem Febre? (5 pontos)");
                break;
            case 1:
                printf("\np2  - Tem dor de cabeça? (1 ponto)");
                break;
            case 2:
                printf("\np3  - Tem secreção nasal ou espirros? (1 ponto)");
                break;
            case 3:
                printf("\np4  - Tem dor/irritação na garganta? (1 ponto)");
                break;
            case 4:
                printf("\np5  - Tem tosse seca? (3 pontos)");
                break;
            case 5:
                printf("\np6  - Tem dificuldade respiratória? (10 pontos)");
                break;
            case 6:
                printf("\np7  - Tem dores no corpo? (1 ponto)");
                break;
            case 7:
                printf("\np8  - Tem diarréia? (1 ponto)");
                break;
            case 8:
                printf("\np9  - Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19? (10 pontos)");
                break;
            case 9:
                printf("\np10  - Esteve em locais com grande aglomeração? (3 pontos)");
                break;
        }
        return (pergunta);
}

int linha()                 //  IMPRIME UMA LINHA PARA SEPARAÇÃO DE BLOCOS DE TEXTO
{
    printf("\n");
    for (int i = 0; i < 60; ++i) {
        printf("-");
    }
    printf("\n");
    return 0;
}
/*     ------------------------------  MANIPULAÇÃO DE ARQUIVOS EM BLOCO TXT ---------------------------------------   */