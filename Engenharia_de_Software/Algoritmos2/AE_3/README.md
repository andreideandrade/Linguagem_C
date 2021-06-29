# 1ª QUESTÃO

Para ajudar a construção de uma praça, uma comunidade resolveu criar um bingo beneficente. Você como
membro ativo da comunidade e profissional de tecnologia se propos a criar um programa em C no qual
gere de forma aleatória as cartelas do bingo.

- Crie uma opção para digitar a quantidade de cartelas a serem criadas
- Cada cartela do bingo deve ser armazenada em um vetor de tamanho 10.
- Os números da cartela devem ser de 0 a 99
- A cartela não pode ter números repetidos, deve ser feita uma conferencia
- Dica:
- Para gerarmos números aleatórios em C, podemos utilizar o comando "rand" e "srand"

Tenha como base o seguinte código:

 ´´ #include <stdio.h>  ´´
 ´´ #include <stdlib.h> ´´
 ´´ #include <time.h> ´´
 ´´ int main()  ´´
 ´´ { ´´
 ´´ int i;  ´´
 ´´ //comando utilizado para criação de números aleatório ´´
 ´´ srand( time(NULL) ); ´´
 ´´ for(i=1 ; i <= 10 ; i++){ ´´
 ´´ //imprime um número aleatório de 1 a 99 ´´
 ´´ printf("Numero %d: %d\n",i, rand() % 99); ´´
 ´´ } ´´
 ´´ } ´´

A sua atividade deve ser entregue em um arquivo de código fonte para linguagem C (extensão .c).
Algumas funções que serão úteis durante o desenvolvimento do programa:
* system(“pause”) – chamada de sistema que “pausa” o programa e o faz aguardar pelo usuário;
* system(“cls”) – chamada de sistema que limpa os caracteres que foram impressos na tela anteriormente;
* fflush(stdin) – limpar o buffer do teclado. Essa função deve sempre ser utilizada após ter utilizado alguma
função de entrada de dados como o scanf, gets, etc. Isso se dá pois em algumas situações o buffer do
teclado mantém “lixo de memória”, prejudicando a próxima operação de entrada do programa;
* A função setlocale(LC_ALL, "Portuguese") da biblioteca locale.h pode ser útil, caso você queira que os
acentos e pontuações da língua portuguesa sejam impressos corretamente.
