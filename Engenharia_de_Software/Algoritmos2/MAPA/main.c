#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("João cabeção\n");   // Teste da função locale

    system("pause");

    return 0;
}

/*     ----------------------------------------------------------------------------------------------------- */
/*      Cadastro inicial do paciente

- CPF
- Nome
- Sexo
- Idade

 */
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