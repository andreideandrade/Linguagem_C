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
struct cadastro {
    char    entCPF[200],
            entNome[200],
            entSexo[200],
            entIdade[200];
};
/*  -------------------------------  FUNÇÃO CADASTRO ---------------------------------------------------------------  */
int cadastro(int ent)
{
    struct cadastro paciente;
    switch (ent) {
        case 0:
            printf(CPF);
            scanf("%s", &paciente.entCPF);
            getchar();
            break;
        case 1:
            printf(NOME);
            scanf("%200[^\n]s", &paciente.entNome);  // IMPRIME FRASE INTEIRA
            getchar();
            break;
        case 2:
            printf(SEXO);
            scanf("%s", &paciente.entSexo);
            getchar();
            break;
        case 3:
            printf(IDADE);
            scanf("%s", &paciente.entIdade);
            getchar();
            break;
    }
    return ent;
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

int triagem(int p){

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
/*     -------------------------------------------------------------------------------------------------------------- */
    linha();

    for (tri = 0; tri < 11; ++tri)
    {
        linha();
        triagem(tri);
    }
//                                      TESTE DE MESA
/*     ----------------------------------------------------------------------------------------------------- */

    


    /*     ----------------------------------------------------------------------------------------------------- */
    getchar();
//    system("pause");   ( APENAS NO WINDOWS )                  // MANTEM SISTEMA ABERTO ATÉ PRECIONAR QUALQUER TECLA
    return 0;
}
/*     ----------------------------------------------------------------------------------------------------- */

/*     ----------------------------------------------------------------------------------------------------- */
/*      Triagem para decidir para onde o paciente será direcionado
 *
 * Após o cadastro o paciente deve responder a um questionário de sintomas no qual cada sintoma terá um
peso para avaliação do risco de COVID, os sintomas são:
1 Tem Febre? (5 pontos)
2 Tem dor de cabeça? (1 ponto)
3 Tem secreção nasal ou espirros? (1 ponto)
- Tem dor/irritação na garganta? (1 ponto)
- Tem tosse seca? (3 pontos)
- Tem dificuldade respiratória? (10 pontos)
- Tem dores no corpo? (1 ponto)
- Tem diarréia? (1 ponto)
- Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19? (10 pontos)
- Esteve em locais com grande aglomeração? (3 pontos)

OBS: Caso o usuário indique que SIM (S) soma o valor, caso seja indicado NÃO (N) não soma o valor.

 */
/*     ----------------------------------------------------------------------------------------------------- */

/*
 O encaminhamento será feito para 3 alas, as de Risco Baixo, Risco Médio e Risco Alto.
Para o risco baixo o total de pontos dos sintomas deverão ser de 0 a 9;
Para o risco médio de 10 a 19 pontos;
 para o risco alto de 20 ou mais pontos.

Após preenchimento indicar para qual ala o paciente deverá se dirigir
 * */

/*     ----------------------------------------------------------------------------------------------------- */

/*
 Para finalizar deve ser salvo em um arquivo com os dados do paciente e qual sua pontuação de sintomas
para que seja realizada possíveis auditorias por parte da direção do hospital.

 * */

//system(“pause”) – chamada de sistema que “pausa” o programa e o faz aguardar pelo usuário;
//* system(“cls”) – chamada de sistema que limpa os caracteres que foram impressos na tela anteriormente;
//* fflush(stdin) – – limpar o buffer do teclado. Essa função deve sempre ser utilizada após ter utilizado alguma
//função de entrada de dados como o scanf, gets, etc. Isso se dá pois em algumas situações o buffer do
//teclado mantém “lixo de memória”, prejudicando a próxima operação de entrada do programa;