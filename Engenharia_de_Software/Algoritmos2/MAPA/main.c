#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
/*  ---------------------------------------  VARIAVEIS   CONSTANTES -------------------------------------------------*/
const char  INICIO[45] = "\nCadastre seus dados para ser atendido: \n",
            CPF[10] = "\nCPF: ",
            NOME[10] = "\nNOME: ",
            SEXO[10] = "\nSEXO: ",
            IDADE[10] = "\nIDADE: ";

/*  -------------------------------  VARIAVEIS DE ENTRADA DE DADOS DO PACIENTE -------------------------------------  */
char    entCPF[200],
        entNome[200],
        entSexo[200],
        entIdade[200];

int cadastro(int ent)                                        // FUNÇÃO CADASTRO
{

    switch (ent) {
        case 0:
            printf(CPF);
            scanf("%s", &entCPF);
            getchar();
            break;
        case 1:
            printf(NOME);
            scanf("%200[^\n]s", &entNome);  // IMPRIME FRASE INTEIRA
            getchar();
            break;
        case 2:
            printf(SEXO);
            scanf("%s", &entSexo);
            getchar();
            break;
        case 3:
            printf(IDADE);
            scanf("%s", &entIdade);
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

int main() {
    setlocale(LC_ALL, "Portuguese");                         //  FORMATA PADRÃO PORTUGUES
    linha();

/*     ------------------------------------ Cadastro de dados pessoais do paciente ---------------------------------- */
    for (int cad = 0; cad < 4; cad++)
    {
        printf(INICIO);
        cadastro(cad);
    }

    linha();

//    system("pause");   ( APENAS NO WINDOWS )                  // MANTEM SISTEMA ABERTO ATÉ PRECIONAR QUALQUER TECLA


//                                      TESTE DE MESA
/*     ----------------------------------------------------------------------------------------------------- */



/*     ----------------------------------------------------------------------------------------------------- */

    getchar();
    return 0;
}
/*     ----------------------------------------------------------------------------------------------------- */

/*     ----------------------------------------------------------------------------------------------------- */
/*      Triagem para decidir para onde o paciente será direcionado
 *
 * Após o cadastro o paciente deve responder a um questionário de sintomas no qual cada sintoma terá um
peso para avaliação do risco de COVID, os sintomas são:
- Tem Febre? (5 pontos)
- Tem dor de cabeça? (1 ponto)
- Tem secreção nasal ou espirros? (1 ponto)
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