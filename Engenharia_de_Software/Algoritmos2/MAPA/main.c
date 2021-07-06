#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*  -------------------------------  VARIAVEIS   CONSTANTES -------------------------------------------------------   */
const char  INICIO[45] =        "\nCadastre seus dados para ser atendido: \n",
            CPF[10] =           "\nCPF: ",
            NOME[10] =          "\nNOME: ",
            SEXO[10] =          "\nSEXO: ",
            IDADE[10] =         "\nIDADE: ",
            SIMOUNAO[50] =      "\nDigite ( S ) para SIM ou ( N ) para NÃO.\n\t-->\t",
            PERGUNTA_1[50] =    "Tem Febre? (5 pontos)",
            PERGUNTA_2[50] =    "Tem dor de cabeça? (1 ponto)",
            PERGUNTA_3[50] =    "Tem secreção nasal ou espirros? (1 ponto)",
            PERGUNTA_4[50] =    "Tem dor/irritação na garganta? (1 ponto)",
            PERGUNTA_5[50] =    "Tem tosse seca? (3 pontos)",
            PERGUNTA_6[50] =    "Tem dificuldade respiratória? (10 pontos)",
            PERGUNTA_7[50] =    "Tem dores no corpo? (1 ponto)",
            PERGUNTA_8[50] =    "Tem diarréia? (1 ponto)",
            PERGUNTA_9[100] =   "Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19? (10 pontos)",
            PERGUNTA_10[60] =   "Esteve em locais com grande aglomeração? (3 pontos)";

int valores[10] = { 5, 1, 1, 1, 3, 10, 1, 1, 10, 3 },
    soma = 0,
    tri;

char decide;

/*  -------------------------------  VARIAVEIS DE ENTRADA DE DADOS DO PACIENTE -------------------------------------  */


    char    entCPF[200],
            entNome[200],
            entSexo[200],
            entIdade[200];

/*  -------------------------------  FUNÇÃO CADASTRO ---------------------------------------------------------------  */
int gravaTxt(char gravaDados[200]);

int cadastro(int ent)
{

    switch (ent) {
        case 0:
            printf(CPF);
            scanf("%s", &entCPF);
            gravaTxt(entCPF);
            getchar();
            break;
        case 1:
            printf(NOME);
            scanf("%200[^\n]s", &entNome);  // IMPRIME FRASE INTEIRA
            gravaTxt(entNome);
            getchar();
            break;
        case 2:
            printf(SEXO);
            scanf("%s", &entSexo);
            gravaTxt(entSexo);
            getchar();
            break;
        case 3:
            printf(IDADE);
            scanf("%s", &entIdade);
            gravaTxt(entIdade);
            getchar();
            break;
    }
}

int limpa()                                                  // Mantem tela e cache limpos
{
    fflush(stdin);          // limpa cache
    system("cls");      // limpa tela
    return 0;
}

int linha()                                                  // Imprime uma linha para formatação
{
    printf("\n");
    for (int i = 0; i < 52; i++) {
        printf("-");
    }
    printf("\n");
    return  0;
}

char resposta()          // Entrada de teclado ( S ) para SIM e ( N ) para NÃO
{

    if(decide == 's' || decide == 'S')
    {
        //printf("\nOk!\n");
        soma = soma + valores[tri];
        //getchar();
    }
    else if(decide == 'n' || decide == 'N')
    {
        //printf("Não deu certo! ");
        //getchar();
    }
    else
    {
        printf("%s", SIMOUNAO);
        scanf("%s", &decide);
        resposta();
    }
}

int triagem(int p)
{

    switch (p) {
        case 0:
            printf("%s %s", PERGUNTA_1, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 1:
            printf("%s %s", PERGUNTA_2, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 2:
            printf("%s %s", PERGUNTA_3, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 3:
            printf("%s %s", PERGUNTA_4, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 4:
            printf("%s %s", PERGUNTA_5, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 5:
            printf("%s %s", PERGUNTA_6, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 6:
            printf("%s %s", PERGUNTA_7, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 7:
            printf("%s %s", PERGUNTA_8, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 8:
            printf("%s %s", PERGUNTA_9, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
        case 9:
            printf("%s %s", PERGUNTA_10, SIMOUNAO);
            scanf("%s", &decide);
            resposta(decide);
            break;
    }
}



int main()
{
    setlocale(LC_ALL, "Portuguese");                         //  FORMATA PADRÃO PORTUGUES
    linha();
/*     ------------------------------------ Cadastro de dados pessoais do paciente ---------------------------------- */
    printf(INICIO);
    for (int cad = 0; cad < 4; cad++)
    {
        cadastro(cad);
    }
/*     ------------------------------------ Triagem para decisão de encaminhamentos --------------------------------- */
    linha();
    for (tri = 0; tri < 11; ++tri)
    {
        linha();
        triagem(tri);
    }
/*     ------------------------ Encaminha paciente para a ALA de acordo com sintomas  -------------------------------- */
    if(soma > 19)
    {
        printf("\nALTO RISCO\n");
    }
    else if(soma > 9)
    {
        printf("\nMÉDIO RISCO\n");
    }
    else
    {
        printf("\nBAIXO RISCO\n");
    }


/*     -------------------------------------------------------------------------------------------------------------- */
    getchar();
//    system("pause");   ( APENAS NO WINDOWS )                  // MANTEM SISTEMA ABERTO ATÉ PRECIONAR QUALQUER TECLA
    return 0;
}   // fim do MAIN

int gravaTxt(char gravaDados[200])
{
    FILE *ponteiroTXT; // cria um ponteiro para o arquivo

    ponteiroTXT = fopen("Registro.txt", "a");   // ABRE O ARQUIVO

    if(ponteiroTXT == NULL) // TESTE SE O ARQUIVO FOI ABERTO COM SUCESSO.
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }
/*     -------------------------------  CONTEUDO A SER GRAVADO VAI AQUI --------------------------------------------- */

    fprintf(ponteiroTXT, "\n%s", gravaDados);
    //fputs(gravaDados, ponteiroTXT);

/*     -------------------------------------------------------------------------------------------------------------- */
    fclose(ponteiroTXT);    // FECHA ARQUIVO
    printf("Dados gravados com sucesso!");

}
/*
    Para finalizar deve ser salvo em um arquivo com os dados do paciente e qual sua pontuação de sintomas
    para que seja realizada possíveis auditorias por parte da direção do hospital.

    função de entrada de dados como o scanf, gets, etc. Isso se dá pois em algumas situações o buffer do
    teclado mantém “lixo de memória”, prejudicando a próxima operação de entrada do programa;
  * */