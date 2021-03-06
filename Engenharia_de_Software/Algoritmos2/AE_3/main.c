#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>

/*  -----------------------------------     VARIAVEIS DO SISTEMA    ----------------------------------------------    */
int i,
    j,
    lin,
    linha,
    coluna,
    teste,
    entrada,
    qCartelas,
    nCartelas[200][11];

/*  -----------------------------------     LIMPA TELA e TECLADO    ----------------------------------------------    */
int limpaTela()
{
    fflush(stdin);
    //system("clear");
    return 0;
}
/*  ---------------------------- IMPRIME UMA LINHA PARA DIVISÃO E FORMATAÇÃO NA TABELA    ------------------------    */
int divisao()
{
    for (lin = 0; lin < 51; ++lin) {
        printf("-");
    }
    printf("\n");
    return 0;
}
/*  ------------------------ ENTRADA DE DADOS - Pergunta quantas cartelas vai ser impresso    --------------------    */
int quantCartelas()
{
    printf("Quantas cartelas deseja imprimir: ");
    scanf("%d", &qCartelas);
    limpaTela();
    return 0;
}
/*  ------------------------------------------     POPULA MATRIZ    ----------------------------------------------    */
int populaMatriz()
{
    for (   linha = 0; linha < qCartelas; ++linha)
    {   // for linha
        nCartelas[linha][0] = linha + 1;                // Carrega coluna 0 da matriz para localizar a cartela

        for (coluna = 1; coluna < 11 ; ++coluna)        //  carrega matriz com numeros aleatorios da cartela
        {   // for coluna
            entrada = rand() % 99;
            while (entrada == 0 )                      //  Corrige erro de entrada 0
            {
                entrada = rand() % 99;
            }
            nCartelas[linha][coluna] = entrada;        // POPULA MATRIZ COM VALOR ALEATORIO
        }   //  fim for coluna
    }       //  fim for linha
    return 0;
}
/*  --------------------------------------     CORRIGE REPETIDAS    ----------------------------------------------    */
int corrigeRepetidas()
{
    for (i = 0; i < qCartelas; ++i)                                         // FOR QUANTIDADE DE CARTELAS
    {
        for (linha = 1; linha < qCartelas; ++linha)                         // FOR LINHA
        {
            for (coluna = 1; coluna < 11; ++coluna)                         // FOR COLUNA
            {
                for (teste = 1; teste < 11; ++teste)                        // FOR TESTE
                {
                    if( coluna != teste )                                    // IF PULA LOCALIZAÇÃO
                    {
                        if(nCartelas[linha][coluna] == nCartelas[linha][teste]) // IF MATRIZ
                        {
                            nCartelas[linha][teste] = rand() % 99;
                        }   // FIM DO IF MATRIZ
                    }       // FIM DO IF PULA LOCALIZAÇÃO
                }           // FIM DO FOR TESTE
            }               // FIM DO FOR COLUNA
        }                   // FIM DO FOR LINHA
    }                       // FIM DO FOR QUANTIDADE DE CARTELAS
    return 0;
}
/*  ------------------------------     IMPRIME RESULTADO NA TELA    ----------------------------------------------    */
int imprimeCartelas()
{
    printf("LISTA DE CARTELAS DO BINGO:\n");

    divisao();                      // IMPRIME UMA LINHA PARA DIVISÃO

    for ( i = 0; i < qCartelas; ++i) //     IMPRIME A MATRIZ CORRIGIDA
    {

        printf("\nCartela: %d \n",nCartelas[i][0]); // NUMERO DA CARTELA

        for (j = 1; j < 11; ++j)
        {
            printf("| %d ", nCartelas[i][j]);       // DEZENAS DO JOGO
        }

        printf(" |\n");

        divisao();                  // IMPRIME UMA LINHA PARA DIVISÃO
    }
    return 0;
}
/*  ---------------------------------------     FUNÇÃO PRINCIPAL    ----------------------------------------------    */
int main()
{
    srand(time(NULL));              //  CHAMA FUNÇÃO DE TEMPO PARA NÚMEROS ALEATÓRIOS

    quantCartelas();                // ENTRADA DE QUANTIDADES DE CARTELAS

    populaMatriz();                 // POPULA MATRIZ

    corrigeRepetidas();             // CORRIGE REPETIDAS

    imprimeCartelas();              // IMPRIME RESULTADO NA TELA

    //system("pause");
    getchar();
    return 0;
}