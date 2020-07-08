#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
 int i, j, lin, col, cont=1, jogadas=0;
 char letra; //gerar letras
 char jogo[4][4]; //matriz do jogo
 char resultado[4][4]; //matriz resultado
 char let;
 srand(time(NULL)); //aleatorio

 letra = 65; //VALE A
// GERANDO MATRIZ RESULTADO
 for (i=0; i<4; i++){ //carregando com letras ordenadamente
    for (j=0; j<4; j++){
         resultado[i][j] = letra++;
    }
 }

resultado[3][3] = ' '; //local onde o campo vazio deve ficar

 for (i=0; i<4; i++){ //carregando com ?
    for (j=0; j<4; j++){
         jogo[i][j] = '?';
    }
 }
//ALEATORIO CAMPO VAZIO
     lin = rand() % 4;
     col = rand() % 4;
     jogo[lin][col] = ' '; //campo vazio

letra = 65; //REDEFININDO PARA 'A'

  //ALEATORIO LETRAS
   for (i=0; i<15; i++){
        lin = rand() % 4;
        col = rand() % 4;
        if (jogo[lin][col] == '?'){
            jogo[lin][col] = letra++;
        }
        else
        i--;
    }


do {
        system("CLS");//limpa tela

        printf("QUEBRA CABECA DESLIZANTE o//\n\nDigite a letra, em maiuscula, que deseja realocar.\n\n");

        printf("Voce esta em sua jogada numero %d \n\n",cont); //imprime quantas jogadas já foram

        //Imprime nome das colunas da matriz
        printf("  "); //Espacamento para numero de linha
        for(j=0;j<4;j++)
            printf(" %d",j);

        printf("\n");


        for(i=0;i<4;i++) //Imprime matriz visual do jogo
        {   printf("%2d",i); //Imprime numero da linha
            for(j=0;j<4;j++)
            { printf(" %c",jogo[i][j]); }
             printf("\n");}

    printf("Letra: "); //recebe letra do usuário
    scanf("%c", &let);


     for(i=0;i<4;i++){ //acha a linha e a coluna da letra
        for(j=0;j<4;j++){
           if (jogo[i][j] == let){
                lin = i;
                col = j;
            }}}


if (jogo[lin][col] !=' '){
    if ((col>0) && (jogo[lin][col-1] ==' '))
        {(jogo[lin][col-1] = jogo[lin][col]);  jogo[lin][col] = ' '; cont++;}
    if ((col<3) && (jogo[lin][col+1] ==' '))
        {(jogo[lin][col+1] =jogo[lin][col]);   jogo[lin][col] = ' '; cont++;}
    if ((lin>0) && (jogo[lin-1][col] ==' '))
        {(jogo[lin-1][col] = jogo[lin][col]);  jogo[lin][col] = ' '; cont++;}
    if ((lin<3) && (jogo[lin+1][col] ==' '))
        {(jogo[lin+1][col] = jogo[lin][col]);  jogo[lin][col] = ' '; cont++;}

}



}while (resultado[i][j] != jogo[i][j]);

printf("Parabens, voce venceu!!\n");
printf("Voce terminou o jogo em %d jogadas", cont);
return 0;
}
