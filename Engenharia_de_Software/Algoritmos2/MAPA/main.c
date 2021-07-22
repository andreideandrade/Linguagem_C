#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct paciente{ char entNome[200], entSexo[30] , entCPF[20]; int entIdade; };

/*  -------------------------------  VARIAVEIS   CONSTANTES -------------------------------------------------------   */
const char  INICIO[45]      =   "\n\tCadastre seus dados para ser atendido: \n",
        SIMOUNAO[53]    =   "\n\tDigite ( S ) para SIM ou ( N ) para NÃO.\n\t-->\t",
        PERGUNTA_1[50]  =   "\n\tTem Febre?",
        PERGUNTA_2[50]  =   "\n\tTem dor de cabeça?",
        PERGUNTA_3[50]  =   "\n\tTem secreção nasal ou espirros?",
        PERGUNTA_4[50]  =   "\n\tTem dor/irritação na garganta?",
        PERGUNTA_5[50]  =   "\n\tTem tosse seca?",
        PERGUNTA_6[50]  =   "\n\tTem dificuldade respiratória?",
        PERGUNTA_7[50]  =   "\n\tTem dores no corpo?",
        PERGUNTA_8[50]  =   "\n\tTem diarréia?",
        PERGUNTA_9[110] =   "\n\tEsteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19?",
        PERGUNTA_10[100]=  	"\n\tEsteve em locais com grande aglomeração?";

/*  -------------------------------  VARIAVEIS PARA REGISTRO EM ARQUIVO ---------------------------------------------   */
char    CPF[100]           = "\n\tCPF:\t",
        NOME[210]          = "\n\tNOME:\t",
        SEXO[30]           = "\n\tSEXO:\t",
        IDADE[50]          = "\n\tIDADE:\t",
        RESULTADO[50]      = "\n\tPontuação: ",
        gravaResultado[55], decide;

int valores[10] = { 5, 1, 1, 1, 3, 10, 1, 1, 10, 3 }, soma = 0, tri;

/*  -------------------------------  CLONE FUNÇÃO ---------------------------------------------------------------  */
void limpa();
void linha();

/*  ---------------------------------   FUNÇÃO CRIA E GRAVA DADOS DA MEMORIA EM ARQUIVO ----------------------------- */
int gravaTxt(char gravaDados[200]){
    FILE *ponteiro;				// cria um ponteiro para o arquivo
    ponteiro = fopen("Registro.txt", "a");	// Cria ou abre um arquivo
    // Testa se o arquivo foi aberto com sucesso
    if(ponteiro == NULL){ printf("Erro na abertura do arquivo!"); return 1;  }
    fputs(gravaDados, ponteiro);		// Grava dados no arquivo de texto
    fclose(ponteiro);				// Fecha arquivo
    return 0;
}

/*  -------------------------------  FUNÇÃO CONTROLE DE RESPOSTA -----------------------------------------------------  */

void resposta(char a){          		// Entrada de teclado ( S ) para SIM e ( N ) para NÃO
    if(a == 's' || a == 'S'){ soma += valores[tri]; }
    else if(a == 'n' || a == 'N');		// Recebe caractere 'n' e não incrementa a variavel "soma"
    else{
        printf("%s", SIMOUNAO);			// Caso digite outro caractere retorna a função em loop.
        scanf("%s", &decide);
        resposta(decide);
    }

}
/*  -------------------------------  FUNÇÃO TRIAGEM (Perguntas ao paciente) ------------------------------------------  */
int triagem(int p){
    switch (p){

        case 0:
            printf("%s %s", PERGUNTA_1, SIMOUNAO );
            break;

        case 1:
            printf("%s %s", PERGUNTA_2, SIMOUNAO );
            break;

        case 2:
            printf("%s %s", PERGUNTA_3, SIMOUNAO );
            break;

        case 3:
            printf("%s %s", PERGUNTA_4, SIMOUNAO );
            break;

        case 4:
            printf("%s %s", PERGUNTA_5, SIMOUNAO );
            break;

        case 5:
            printf("%s %s", PERGUNTA_6, SIMOUNAO );
            break;

        case 6:
            printf("%s %s", PERGUNTA_7, SIMOUNAO );
            break;

        case 7:
            printf("%s %s", PERGUNTA_8, SIMOUNAO );
            break;

        case 8:
            printf("%s %s", PERGUNTA_9, SIMOUNAO );
            break;

        case 9:
            printf("%s %s", PERGUNTA_10, SIMOUNAO);
            break;
    }
    if (p < 10){  scanf("%s", &decide);  resposta(decide); }
    return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");                         //  FORMATA PADRÃO PORTUGUES
    struct paciente cadastro;
/*     ------------------------------------ Cadastro de dados pessoais do paciente ---------------------------------- */
    linha(); printf(INICIO);

    linha();
    printf(CPF);  scanf("%s", &cadastro.entCPF);  fflush(stdin);

    linha();
    printf(NOME);  scanf("%200[^\n]s", &cadastro.entNome); fflush(stdin);

    linha();
    printf(SEXO); scanf("%s", &cadastro.entSexo);  fflush(stdin);

    linha();
    printf(IDADE); scanf("%d", &cadastro.entIdade); limpa();

    /*     ------------------------------------ Triagem para decisão de encaminhamentos --------------------------------- */

    for (tri = 0; tri < 11; ++tri){  linha();  triagem(tri);  limpa(); }
/*  ------------------------ Executa Função gravaTxt() - Para salvar dados coletados para arquivo    ---------------   */

    gravaTxt("\n| ------------------------------------------------ | \n");

    sprintf( gravaResultado, "\t%s %s", CPF, cadastro.entCPF );           // Concatena String e Inteiro
    gravaTxt( gravaResultado);

    sprintf( gravaResultado, "\t%s %s", NOME, cadastro.entNome );           // Concatena String e Inteiro
    gravaTxt(gravaResultado);

    sprintf( gravaResultado, "\t%s %s", SEXO, cadastro.entSexo );           // Concatena String e Inteiro
    gravaTxt(gravaResultado);

    sprintf( gravaResultado, "\t%s %d", IDADE, cadastro.entIdade );           // Concatena String e Inteiro
    gravaTxt(gravaResultado);

    sprintf( gravaResultado, "\t%s %d",RESULTADO, soma );           // Concatena String e Inteiro
    gravaTxt(gravaResultado);

    /*     ------------------------ Encaminha paciente para a ALA de acordo com sintomas  -------------------------------- */

    limpa();

    if(soma > 19){ printf("\n\n\tDirija-se para a ala de alto risco.\n");  }
    else if(soma > 9){ printf("\n\n\tDirija-se para ala de médio risco.\n");  }
    else{ printf("\n\n\tDirija-se para ala de baixo risco.\n"); }

    printf("\n\tPrecione Enter para finalizar");
    getchar();
    return 0;
}   // fim do MAIN

/*     -------------------------------  Mantem tela e cache limpos -------------------------------------------------   */

void limpa(){ fflush(stdin);  system("cls"); }

/*     -------------------------------  Imprime uma linha para formatação -------------------------------------------   */

void linha(){
    printf("\n");
    for (int i = 0; i < 52; i++) { printf("-");  }
    printf("\n");
}