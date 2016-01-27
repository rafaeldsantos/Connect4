/*---------------------------------------------------------------------------
	AUTORES: NOME: LUCAS SANTOS DE ALMEIDA  RA: 408190
			 		 NOME: RAFAEL DANILO DOS SANTOS RA: 408654

	ETAPA DOIS DO JOGO CONECT FOUR ONDE SÃO INSERIDAS AS PEÇAS DE DOIS JOGADORES
	E O PRIMEIRO A COMPLETAR 4 PEÇAS JUNTAS EM ALGUMA LINHA, COLUNA OU DIAGONAL
	É O VENCEDOR.
	PS: FOI ACRESCENTADO O NIVEL NORMAL E EASY
	ULTIMA MODIFICACAO 24/12/12 - FELIZ NATAL :D
  --------------------------------------------------------------------------*/

//bibliotecas e defines para o programa
#include<stdio.h>
#include<string.h>
#include<time.h>
#include <stdlib.h>
#include <unistd.h>
#define LINHA 7
#define COLUNA 6
#if defined(win_nt)
#define CLEAR system("cls")
#elif defined(linux) || defined(macintoch)
#define CLEAR system("clear")
#else
#error "SISTEMA OPERACIONAL INCOMPATIVEL"
#endif
//faz a animação
void animaVetor(int m[LINHA][COLUNA], int jogada, int posicao, int ficha){
	int i=0;	
	for(i=0;i<LINHA;i++){
		if(i==posicao){
		m[i][jogada]=1;
		}
		if(m[i][jogada]!=1)
		{		
			m[i][jogada]=ficha;
			system("clear");
			desenhaMATRIZ(m);
			usleep(90000);
			m[i][jogada]=0;
		}else{
		//system("clear");
		//printVetor(v);
		m[i][jogada]=0;
		break;
		}
	}
}


//função para inicializar toda a matriz com 0s
int iniciaMATRIZ(int m[LINHA][COLUNA])
{
  int i,j;
  for (i=0;i<LINHA; i++)
    {
      for(j=0;j<COLUNA;j++)
	{
	  m[i][j]=0;
	}
    }
}

//função para mostrar a matriz no prompt
int desenhaMATRIZ(int m[LINHA][COLUNA])
{
  int i,j;
  for (i=0;i<LINHA; i++)
    {
      for(j=0;j<COLUNA;j++)
	{
	  printf("%d\t", m[i][j]);
	}
      printf("\n");
    }
}

//função para realizar a jogada inserindo 1 se for o primeiro jogador e -1 se for o segundo
int fazerJogada(int m[LINHA][COLUNA], int jogada, int jogador)
{
  int i;
  for(i=LINHA-1;i>=0;i--){
	  if((m[i][jogada]== 1 || m[i][jogada] == -1) && i==0) return 0;
      if(m[i][jogada]==0){
		if(jogador%2==0){
			animaVetor(m,jogada,i,1);
			m[i][jogada]=1;				
  		    return 1;
		} else {
			animaVetor(m,jogada,i,-1);
			m[i][jogada]=-1;				
  		    return 1;
		}
	  }
  }
}
//função que verifica todas a possibilidades de peças juntas para identificar um ganhador
int verifica(int matriz[LINHA][COLUNA], int jogador, char player2[]){
int i,j, cont=0, coluna = 0,//auxiliar para percorrer a diagonal
 linha = 0;//linha auxiliar para percorrer a diagonal

	//procura em todas as linhas
	for (i=0;i<LINHA; i++){
		cont = 0;
	    for(j=0;j<COLUNA;j++){
			if(jogador%2 == 0){
				if(matriz[i][j] == 1) cont++;
				if(matriz[i][j] == 0 || matriz[i][j] == -1) cont = 0;
				if(cont == 4){
					printf("Player 1 Ganhou!\n");
					return 1;
				}
			} else {
				if(matriz[i][j] == -1) cont++;
				if(matriz[i][j] == 0 || matriz[i][j] == 1) cont = 0;
				if(cont == 4){
					printf("%s Ganhou!\n",player2);
					return 1;
				}
			}
	     }
    }
	//procura em todas as colunas
	for (i=0;i<COLUNA; i++){
		cont = 0;
    	for(j=0;j<LINHA;j++){
			if(jogador%2 == 0){
				if(matriz[j][i] == 1) cont++;
				if(matriz[j][i] == 0 || matriz[j][i] == -1) cont = 0;
				if(cont == 4){
					printf("Player 1 Ganhou!\n");
					return 1;
				}
			} else {
				if(matriz[j][i] == -1) cont++;
				if(matriz[j][i] == 0 || matriz[j][i] == 1) cont = 0;
				if(cont == 4){
					printf("%s Ganhou!\n",player2);
					return 1;
				}
			}
		}
    }
	//procura nas diagonais das linhas de 1-4 e colunas de 0 até a quantidade maxima de colunas possivel da diagonal
	for (i=0;i<4; i++){
		cont = 0;
		
		if(i==0 || i== 1){ coluna = 6; }
		else if(i==2){ coluna = 5; }
		else { coluna = 4; }

    	for(j=0;j<coluna;j++){
			if(jogador%2 == 0){
				if(matriz[i+j][j] == 1) cont++;
				if(matriz[i+j][j] == 0 || matriz[i+j][j] == -1) cont = 0;
				if(cont == 4){
					printf("Player 1 Ganhou!\n");
					return 1;
				}
			} else {
				if(matriz[i+j][j] == -1) cont++;
				if(matriz[i+j][j] == 0 || matriz[i+j][j] == 1) cont = 0;
				if(cont == 4){
					printf("%s Ganhou!\n",player2);
					return 1;
				}
			}
		}
    }
	//procura nas diagonais das linhas de 1-4 e colunas de 6 até a quantidade minima de colunas posivel da diagonal
	for (i=0;i<4; i++){
		cont = 0;
		linha = i;

		if(i==0 || i== 1){ coluna = 0; }
		else if(i==2){ coluna = 1; }
		else { coluna = 2; }

    	for(j=COLUNA-1;j >= coluna;j--){
			if(jogador%2 == 0){
				if(matriz[linha][j] == 1) cont++;
				if(matriz[linha][j] == 0 || matriz[linha][j] == -1) cont = 0;
				if(cont == 4){
					printf("Player 1 Ganhou!\n");
					return 1;
				}
			} else {
				if(matriz[linha][j] == -1) cont++;
				if(matriz[linha][j] == 0 || matriz[linha][j] == 1) cont = 0;
				if(cont == 4){
					printf("%s Ganhou!\n",player2);
					return 1;
				}
			}
		linha++;
		}
    }
	//procura nas diagonais da matriz[0][2] e [0][3]
	for(i=1; i < 3; i++){
		linha = 0;
		cont = 0;
		for(j=i; j < COLUNA; j++){
						
			if(jogador%2 == 0){
				if(matriz[linha][j] == 1) cont++;
				if(matriz[linha][j] == 0 || matriz[linha][j] == -1) cont = 0;
				if(cont == 4){
					printf("Player 1 Ganhou!\n");
					return 1;
				}
			} else {
				if(matriz[linha][j] == -1) cont++;
				if(matriz[linha][j] == 0 || matriz[linha][j] == 1) cont = 0;
				if(cont == 4){
					printf("%s Ganhou!\n",player2);
					return 1;
				}
			}
		linha++;
		}
	}
	//procura nas diagonais da matriz[0][5] e [0][4]
	for(i=1; i < 3; i++){
		linha = 0;
		cont = 0;
		for(j=(COLUNA - 1) - i; j >= 0; j--){
			if(jogador%2 == 0){
				if(matriz[linha][j] == 1) cont++;
				if(matriz[linha][j] == 0 || matriz[linha][j] == -1) cont = 0;
				if(cont == 4){
					printf("Player 1 Ganhou!\n");
					return 1;
				}
			} else {
				if(matriz[linha][j] == -1) cont++;
				if(matriz[linha][j] == 0 || matriz[linha][j] == 1) cont = 0;
				if(cont == 4){
					printf("%s Ganhou!\n",player2);
					return 1;
				}
			}
		linha++;
		}
	}
	return 0;
}

int nivelNORMAL(int matriz[LINHA][COLUNA], int listaColuna[COLUNA],int listaLinha[LINHA]){
int i,j, cont=0, coluna = 0,//auxiliar para percorrer a diagonal
 linha = 0,//linha auxiliar para percorrer a diagonal
 comeco,i2,cont_c;

/* DESCRIÇÃO: Essa funcao implementa a estrategia do computador para o nivel NORMAL
** A primeira estrategia consiste em verificar se existe alguma condição de vitoria, observando
** as colunas e depois as linhas respectivamente, caso não exista nenhuma o computador observa 
** existe alguma condição de vitoria para o jogador e tenta bloquear na seguinte ordem, linha, 
** coluna, diagonal.
** Se não existe nenhuma condição de vitoria, o computador faz uma jogada aleatoria, que nos
** testes realizados tornaram o jogo bastante imprevisivel e dinamico.
** OBSERVAÇÕES: Os parametros listaColuna[] e listaLinha[] marcam linhas e colunas que  
** computador não deve verificar mais, caso contrario computador sempre faria a mesma jogada
** quando uma condição está satisfeita para ataque ou bloqueio.
*/


//faz a jogada para vencer verticalmente se for possivel
	for (i=0;i<COLUNA; i++){
		cont = 0;
    for(j=0;j<LINHA;j++){
			if(matriz[j][i] == -1) cont++;
			if(matriz[j][i] == 0 || matriz[j][i] == 1) cont = 0;
			if(cont == 3 && listaColuna[i] != 1){						
				listaColuna[i]=1;
				return i;
			}
		}
  }
//faz a jogada para vencer horizontalmente se for possivel
	for (i=0;i<LINHA; i++){
		cont = 0;
    for(j=0;j<COLUNA;j++){
			if(listaLinha[i]!=1){
			if(matriz[i][j] == -1) {
				cont++; 
				if(cont == 1){
					comeco=j;
				}
			}
			if(matriz[i][j] == 0 || matriz[i][j] == 1) {cont = 0;}
			if(cont == 3){
				if (comeco==0){
					listaLinha[i]=1;					
					return j+1;
				}else if(comeco == COLUNA-3){
					listaLinha[i]=1;
					return comeco-1;
				}	
			}else if (cont == 2){
				if(comeco>1){
					if(matriz[i][comeco-2]==-1){
						listaLinha[i]=1;
						return comeco-1;
					} else if (matriz[i][j] < COLUNA-2){
						if(matriz[i][j+2]==-1){
						listaLinha[i]=1;
							return j+1;						
						}
					}
				} else if(j < COLUNA-2){
					if(matriz[i][j+2]==-1){
						listaLinha[i]=1;
						return j+1;
					}
				}			
			}
			}//if
	  }
  }

	//bloqueia as linhas caso seja uma condiçao de derrota obvia.
	for (i=0;i<LINHA; i++){
		cont = 0;
    for(j=0;j<COLUNA;j++){
			if (listaLinha[i]!=1){
			if(matriz[i][j] == 1) {
				cont++; 
				if(cont == 1){
					comeco=j;
				}
			}
			if(matriz[i][j] == 0 || matriz[i][j] == -1) {cont = 0;}
			if(cont == 3){
				if(comeco>0){
					if(matriz[i][comeco-1]==0){
						listaLinha[i]=1;
						return comeco-1;
					}else {
						listaLinha[i]=1;
						return j+1;
					}
				} else {
					return j+1;
				}
			}else if (cont == 2){
				if(comeco>1){
					if(matriz[i][comeco-2]==1){
							listaLinha[i]=1;
						return comeco-1;
					} else if (matriz[i][j] < COLUNA-2){
						if(matriz[i][j+2]==1){
							listaLinha[i]=1;
							return j+1;						
						}
					}
				} else if(j < COLUNA-2){
					if(matriz[i][j+2]==1){
						listaLinha[i]=1;
						return j+1;
					}
				}
				if(comeco>0){listaLinha[i]=1;return comeco-1;}
					else {listaLinha[i]=1;return j+2;}
			}
		}//if
	  }
  }
	//bloqueia as colunas caso seja uma condiçao de derrota obvia
	for (i=0;i<COLUNA; i++){
		cont = 0;
    for(j=0;j<LINHA;j++){
			if(listaColuna[i]!=1){
				if(matriz[j][i] == 1) cont++;
				if(matriz[j][i] == 0 || matriz[j][i] == -1) cont = 0;
				if(cont == 3){
					listaColuna[i]=1;
					return i;
				}
			}
		}
  }


//bloqueia as diagonais caso seja uma condicao de derrota obvia
	for(i=3;i<LINHA; i++){
		for(j=0;j<COLUNA; j++){
			if( (j < 4) && matriz[i][j] == -1 ){
			cont_c = 0;
				for(i2=0; i2 < 2; i2++){
					if(matriz[(i-i2)-1][(j+i2)+1]==-1) cont_c++;
				}
				if(cont_c==2){
					for(i2=LINHA-1; i2 > i; i2--){
						if(i+1 < i2 && j > 0 && matriz[i+1][j-1] != 0) break; 
						if(i+1 == LINHA || j == 0) break;
						if(i+1 == i2 && matriz[i2][j-1]==0) return j;
						if(i+1 < i2 && matriz[i2][j-1]==0) break;
					}

					for(i2=LINHA-1; i2 > i-4; i2--){
						if((i-3 >= 0 && j+3 <= 5) && matriz[i-3][j+3] != 0) break;
						if(i-3 == i2 && matriz[i2][j+3]==0) return j+4;
						if(i-3 < i2 && matriz[i2][j+3]==0) break;
					}
				}
			}

			if( (j > 1) && matriz[i][j] == -1 ){
				cont_c = 0;
				for(i2=0; i2 < 2; i2++){
					if(matriz[(i-i2)-1][(j-i2)-1]==-1) cont_c++;
				}
				if(cont_c==2){
					for(i2=LINHA-1; i2 > i; i2--){
						if(i+1 < i2 && j < 5 && matriz[i+1][j+1] != 0) break; 
						if(i+1 == LINHA || j == 5) break;
						if(i+1 == i2 && matriz[i2][j+1]==0) return j+2;
						if(i+1 < i2 && matriz[i2][j+1]==0) break;
					}

					for(i2=LINHA-1; i2 > i-4; i2--){
						if(i-3 >= 0 && j-3 >= 0 && matriz[i-3][j-3] != 0) break;
						if(i-3 == i2 && matriz[i2][j-3]==0) return j-2;
						if(i-3 < i2 && matriz[i2][j-3]==0) break;
					}
				}
			} 

			if( (j < 4) && matriz[i][j] == 1 ){
				cont = 0;
				for(i2=0; i2 < 2; i2++){
					if(matriz[(i-i2)-1][(j+i2)+1]== 1) cont++;
				}
				if(cont==2){
					for(i2=LINHA-1; i2 > i; i2--){
						if(i+1 < i2 && j > 0 && matriz[i+1][j-1] != 0) break; 
						if(i+1 == LINHA || j == 0) break;
						if(i+1 == i2 && matriz[i2][j-1]==0) return j;
						if(i+1 < i2 && matriz[i2][j-1]==0) break;
					}

					for(i2=LINHA-1; i2 > i-4; i2--){
						if(i-3 >= 0 && j+3 <= 5 && matriz[i-3][j+3] != 0) break;
						if(i-3 == i2 && matriz[i2][j+3]==0) return j+4;
						if(i-3 < i2 && matriz[i2][j+3]==0) break;
					}
				}
			}

			if((j > 1) && matriz[i][j] == 1 ){
				cont = 0;
				for(i2=0; i2 < 2; i2++){
					if(matriz[(i-i2)-1][(j-i2)-1]== 1) cont++;
				}
				if(cont==2){
					for(i2=LINHA-1; i2 > i; i2--){
						if(i+1 < i2 && j < 5 && matriz[i+1][j+1] != 0) break; 
						if(i+1 == LINHA || j == 5) break;
						if(i+1 == i2 && matriz[i2][j+1]==0) return j+2;
						if(i+1 < i2 && matriz[i2][j+1]==0) break;
					}

					for(i2=LINHA-1; i2 > i-4; i2--){
						if(i-3 >= 0 && j-3 >= 0 && matriz[i-3][j-3] != 0) break;
						if(i-3 == i2 && matriz[i2][j-3]==0) return j-2;
						if(i-3 < i2 && matriz[i2][j-3]==0) break;
					}
				}
			}
		}
	}


return rand()%COLUNA+1;
}

void limpaLista (int lista[], int tam) {
	int i;
	for(i=0;i<tam;i++){
		lista[i]=0;
	}

}

int main ()
{
  int matriz[LINHA][COLUNA], jogada=0, menu, modo,nivel,
	jogador=0,//par player 1 impar player 2
	//os dois vetores listam as jogadas permitidas para o COMPUTADOR, evita repitições de açoes
	listaColuna[COLUNA], listaLinha[LINHA];
	char player2[21] ="Player 2";
	srand(time(NULL));
	limpaLista(listaColuna,COLUNA);
	limpaLista(listaLinha,LINHA);
  iniciaMATRIZ(matriz);//função para inicializar a matriz com 0s
	CLEAR;
  printf("1-START GAME\n2-EXIT GAME\n");//menu do jogo
	scanf("%d", &menu);
	if(menu == 2) return 0;//'EXIT GAME' finaliza o jogo
	CLEAR;
	printf("1-ONE PLAYER\n2-TWO PLAYERS\n");
	scanf("%d", &modo);
	if(modo == 1) {
		strcpy(player2, "O Computador");
		CLEAR;
		printf("1-EASY\n2-NORMAL\n");
		scanf("%d", &nivel);
	}
	//laço infinito para continuar o jogo até existir um vencedor
	while(menu){
		//tratamento de erro para o usuario nao digitar um numero de coluna inexistente
		do{
			CLEAR;//limpa o prompt
			desenhaMATRIZ(matriz);//mostra a matriz no prompt
			if(jogador%2==0){
				printf("PLAYER 1 INDIQUE A COLUNA: ");
		  		scanf("%d", &jogada);
			} else if (modo == 2) {
				printf("%s INDIQUE A COLUNA: ",player2);
		  		scanf("%d", &jogada);
			}	else if (nivel == 1){ 
					jogada = rand() % COLUNA+1;
			} else if (nivel == 2){
					jogada = nivelNORMAL(matriz,listaColuna,listaLinha)+1;
			}
		usleep(300);//evita que a jogada aconteça muito rápido
		} while((jogada < 1 || jogada > 6) && matriz[0][jogada]!=0);
		//função que realiza a jogada do usuario
	  	if (fazerJogada(matriz, jogada-1, jogador)){
		 	CLEAR;
		  	desenhaMATRIZ(matriz);//limpa o prompt e mostra a nova matriz com a peça colocada
			if (verifica(matriz, jogador, player2)) break;//se existir um vencedor jogo finalizado
			jogador++;
		} 
 	}
//}
  return 0;
}
