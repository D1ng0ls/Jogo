#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

using namespace std;

//declara��o das variveis
int rank=1, rank_tabela, num, personalizado=20, pontos, acertou=0, jogadas, dificuldade=1, aleatorio, tentativas=0, opcao;
double dificuldade_rank[1000], pontos_rank[1000];
char nick_rank[5][35];

//declara��o das fun��es
int menu();
int menu_jogo();
int menu_dificuldade();
void tudo();
void facil();
void medio();
void dificil();
void personalizada();
void tutorial();
void rank_();


int main(){
	
	setlocale (LC_ALL,"Portuguese");
	
	opcao=menu();
	
	tudo();
}

//tudo do jogo
void tudo(){
	int escolha=1, menuA=0, rept=0;
	
	if(opcao==1){
		while(rept==0){
			rept=1;
				//menu do jogo
			escolha=menu_jogo();
			
			if(escolha==1){
				srand((unsigned)time(0));
				aleatorio = rand() % 1000;
					//Jogo na dificuldade f�cil
				if(dificuldade==1){
					facil();
				}
				else{
						//Jogo na dificuldade m�dia
					if(dificuldade==2){
						medio();
					}
					else{
							//Jogo na dificuldade dif�cil
						if(dificuldade==3){
							dificil();
						}
						else{
							//Jogo na dificuldade personalizada
							personalizada();
						}
					}
				}
			}
			else{
				if(escolha==2){
						//menu das dificuldades do jogo
					escolha=menu_dificuldade();
					
					if(escolha==1){
					printf("\nDIFICULDADE MUDADA PARA: F�CIL\n");
					
					dificuldade=1;
					
					system("pause");
					system("cls");
					}
					else{
						if(escolha==2){
							printf("\nDIFICULDADE MUDADA PARA: M�DIA\n");
							
							dificuldade=2;
							
							system("pause");
							system("cls");
						}
						else{
							if(escolha==3){
								printf("\nDIFICULDADE MUDADA PARA: DIF�CIL\n");
								
								dificuldade=3;
								
								system("pause");
								system("cls");
							}
							else{
									//Defini��o das tentativas para o modo personalizado
								if(escolha==4){
									dificuldade=4;
									while(menuA<1){
										printf("\nDIFICULDADE MUDADA PARA: PERSONALIZADA\n\n");
										printf("DIGITE A QUANTIDADE DE TENTATIVAS QUE VOC� PRETENDE JOGAR: ");
										scanf("%d", &personalizado);
										
										if(personalizado<=0){
											printf("DIGITE UM VALOR INTEIRO MAIOR QUE 0!!!\n");
											
											menuA--;
										}
										
										menuA++;
									}
									
									system("pause");
									system("cls");
								}
								else{
									if(escolha==5){
										rept=1;
									}
									else{
										rept=0;
										system("pause");
										system("cls");
									}
								}
							}
						}
					}
					
					rept=0;
				}
				else{
					if(escolha==3){
						tutorial();
					}
					else{
						main();
					}
				}
			}
		}
	}
	else{
		if(opcao==2){
			rank_();
		}
	}
}

//																		-----MENUS-----

//menu do inicio do jogo
int menu(){
	int opc=0;
	
	system("cls");
	
	while(opc<1 || opc>3){
		printf("--ADIVINHE O N�MERO-- \n\n");
		printf("1-JOGAR\n2-RANKING\n3-SAIR\n");
		scanf("%d", &opc);
	}
	
	return opc;
}

//menu de dentro do jogo
int menu_jogo(){
	int opc=0;
	
	system("cls");
	
	while(opc<1 || opc>4){
		printf("--MENU-- \n\n");
		printf("1-JOGAR\n");
		
		if(dificuldade==1){
			printf("2-DIFICULDADE: F�CIL\n");
		}
		else{
			if(dificuldade==2){
				printf("2-DIFICULDADE: M�DIA\n");
			}
			else{
				if(dificuldade==3){
					printf("2-DIFICULDADE: DIF�CIL\n");
				}
				else{
					printf("2-DIFICULDADE: PERSONALIZADO - (SEM PONTUA��O)\n");
				}
			}
		}
		
		printf("3-COMO JOGAR\n4-SAIR\n");
		scanf("%d", &opc);
	}
	
	system("cls");
	return opc;
}

//menu das dificuldades
int menu_dificuldade(){
	int opc=0;
	
	system("cls");
	
	while(opc<1 || opc>5){
		printf("--DIFICULDADE--\n");
		printf("1-F�CIL\n2-M�DIA\n3-DIF�CIL\n4-PERSONALIZADO - (SEM PONTUA��O)\n5-SAIR\n");
		scanf("%d", &opc);
	}
	
	return opc;
}

//																		-----EXTRAS-----

//tutorial do jogo
void tutorial(){
	printf("					--COMO JOGAR-- \n\n");
	printf("-> O JOGADOR TER� ALGUMAS TENTATIVAS DE ACERTAR UM N�MERO ALEAT�RIO GERADO DE 0 A 1000;\n");
	printf("-> CADA TENTATIVA QUE O JOGADOR USAR E ERRAR ELE PERDER� ALGUNS PONTOS;\n");
	printf("-> A QUANTIDADE DE TENTATIVAS MUDA DE ACORDO COM A DIFICULDADE: \n");
	printf("	F�CIL -- 10 TENTATIVAS;\n	M�DIA -- 06 TENTATIVAS;\n	DIF�CIL -- 03 TENTATIVAS;\n	PERSONALIZADA -- DEVEM SER DETERMINADAS.\n\n");
	
	printf("					--PONTUA��O--\n\n");
	printf("-> A PONTUA��O M�XIMA � DE 300 PONTOS;\n");
	printf("-> O VALOR DO DESCONTO DOS PONTOS MUDA CONFORME A DIFICULDADE: \n");
	printf("-CONSIDERE AS FORMULAS ABAIXO PARA SUA RESPECTIVA DIFICULDADE-\n");
	printf("	F�CIL -- PONTOS = 300-(ERROS*30);\n	M�DIA -- PONTOS = 300-(ERROS*50);\n	DIF�CIL -- PONTOS = 300-(ERROS*100);\n	PERSONALIZADA -- SEM PONTUA��O.\n\n");
	
	printf("					--OBJETIVO-- \n\n\n");
	printf("-> ACERTAR O N�MERO GERADO COM MENOS TENTATIVAS;\n");
	printf("-> MARCAR A MAIOR QUANTIDADE DE PONTOS POSSIVEIS.\n\n");
	
	system("pause");
	system("cls");
	tudo();
}

//rank dos jogadores
void rank_(){
	int opc=0;
	
	while(opc<1 || opc>4){
		system("cls");
		printf("--RANKING--\n");
			//Escolha do ranking por dificuldade
		printf("OP��ES:\n1-F�CIL\n2-M�DIO\n3-DIF�CIL\n4-SAIR\n");
		scanf("%d", &opc);
		system("cls");
			//Ranking da dificuldade f�cil
		if(opc==1){
			printf("NICK:          PONTUA��O:          DIFICULDADE:\n\n");
			for(rank_tabela=0;rank_tabela<=1000;rank_tabela++){
				if(dificuldade_rank[rank_tabela]==1){
					printf("%s          %g          F�CIL\n", nick_rank[rank_tabela], pontos_rank[rank_tabela]);
				}
			}
			
			system("pause");
			rank_();
		}
		else{
				//Ranking da dificuldade m�dia
			if(opc==2){
				printf("NICK:          PONTUA��O:          DIFICULDADE:\n\n");
				for(rank_tabela=1;rank_tabela<=1000;rank_tabela++){
					if(dificuldade_rank[rank_tabela]==2){
						printf("%s          %g          M�DIA\n", nick_rank[rank_tabela], pontos_rank[rank_tabela]);
					}
				}
				
				system("pause");
				rank_();
			}
			else{
					//Ranking da dificuldade dif�cil
				if(opc==3){
					printf("NICK:          PONTUA��O:          DIFICULDADE:\n\n");
					for(rank_tabela=1;rank_tabela<=1000;rank_tabela++){
						if(dificuldade_rank[rank_tabela]==3){
							printf("%s          %g          DIF�CIL\n", nick_rank[rank_tabela], pontos_rank[rank_tabela]);
						}
					}
					
					system("pause");
					rank_();
				}
				else{
					if(opc==4){
						main();
					}
				}
			}
		}
	}
	
	system("pause");
	system("cls");
}

//																		-----JOGO-----

//jogo na dificuldade f�cil
void facil(){
	int opc=0;
	
	tentativas=0;
	
	printf("QUANTIDADE DE TENTATIVAS: 10\n");
	//printf("O N�MERO GERADO FOI: %d\n", aleatorio);
	
	for(jogadas=1;jogadas<=10;jogadas++){
		printf("DIGITE UM N�MERO ENTRE 0 E 1000: ");
		scanf("%d", &num);
		
		if(num==aleatorio){
			printf("\nPARAB�NS VOC� ACERTOU!!!\n");
			acertou=1;
			jogadas=11;
		}
		else{
			if(num<aleatorio){
				printf("DICA: O N�MERO GERADO � MAIOR QUE O DIGITADO\n");
				tentativas++;
			}
			else{
				printf("DICA: O N�MERO GERADO � MENOR QUE O DIGITADO\n");
				tentativas++;
			}
		}
	}
	
	system("pause");
	system("cls");
							//Exibi��o dos pontos e cadastro para o ranking
	if(acertou==1){
		pontos=300-(tentativas*30);
		
		printf("VOC� MARCOU: %d PONTOS!\n", pontos);
		printf("DESEJA SALVAR SUA PONTUA��O?\n1-SIM\n2-N�O\n");
		scanf("%d", &opc);
		
		if(opc==1){
			pontos_rank[rank] = pontos;
			dificuldade_rank[rank] = dificuldade;
			printf("DIGITE UM APELIDO: ");
			scanf("%s", &nick_rank[rank]);
			printf("PR�VIA: %s          %g          F�CIL\n", nick_rank[rank], pontos_rank[rank]);
			rank++;	
		}
	}
	else{
		printf("O N�MERO GERADO FOI: %d\n", aleatorio);
		printf("N�O FOI DESTA VEZ :(\n");
	}
	
	acertou=0;
	system("pause");
	system("cls");
	tudo();
}

//jogo na dificuldade m�dia
void medio(){
	int opc=0;
	
	tentativas=0;
	printf("QUANTIDADE DE TENTATIVAS: 6\n");
	//printf("O N�MERO GERADO FOI: %d\n", aleatorio);
	for(jogadas=1;jogadas<=6;jogadas++){
		printf("DIGITE UM N�MERO ENTRE 0 E 1000: ");
		scanf("%d", &num);
		if(num==aleatorio){
			printf("\nPARAB�NS VOC� ACERTOU!!!\n");
			acertou=1;
			jogadas=7;
		}
		else{
			if(num<aleatorio){
				printf("DICA: O N�MERO GERADO � MAIOR QUE O DIGITADO\n");
				tentativas++;
			}
			else{
				printf("DICA: O N�MERO GERADO � MENOR QUE O DIGITADO\n");
				tentativas++;
			}
		}
	}
	
	system("pause");
	system("cls");
						//Exibi��o dos pontos e cadastro para o ranking
	if(acertou==1){
		pontos=300-(tentativas*50);
		
		printf("VOC� MARCOU: %d PONTOS!\n", pontos);
		printf("DESEJA SALVAR SUA PONTUA��O?\n1-SIM\n2-N�O\n");
		scanf("%d", &opc);
		
		if(opc==1){
			pontos_rank[rank] = pontos;
			dificuldade_rank[rank] = dificuldade;
			
			printf("DIGITE UM APELIDO: ");
			scanf("%s", &nick_rank[rank]);
			printf("PR�VIA: %s          %g          M�DIA\n", nick_rank[rank], pontos_rank[rank]);
			
			rank++;
		}
	}
	else{
		printf("N�O FOI DESTA VEZ :(\n");
		printf("O N�MERO GERADO FOI: %d\n", aleatorio);	
	}
	
	acertou=0;
	system("pause");
	system("cls");
	tudo();
}

//jogo na dificuldade dificil
void dificil (){
	int opc=0;
	
	tentativas=0;
	
	printf("QUANTIDADE DE TENTATIVAS: 3\n");
	//printf("O N�MERO GERADO FOI: %d\n", aleatorio);
	
	for(jogadas=1;jogadas<=3;jogadas++){
		printf("DIGITE UM N�MERO ENTRE 0 E 1000: ");
		scanf("%d", &num);
		
		if(num==aleatorio){
			printf("\nPARAB�NS VOC� ACERTOU!!!\n");
			acertou=1;
			jogadas=4;
		}
		else{
			if(num<aleatorio){
				printf("DICA: O N�MERO GERADO � MAIOR QUE O DIGITADO\n");
				tentativas++;
			}
			else{
				printf("DICA: O N�MERO GERADO � MENOR QUE O DIGITADO\n");
				tentativas++;
			}
		}
	}
	
	system("pause");
	system("cls");
					//Exibi��o dos pontos e cadastro para o ranking
	if(acertou==1){
		pontos=300-(tentativas*100);
		
		printf("VOC� MARCOU: %d PONTOS!\n", pontos);
		printf("DESEJA SALVAR SUA PONTUA��O?\n1-SIM\n2-N�O\n");
		scanf("%d", &opc);
		
		if(opc==1){
			pontos_rank[rank] = pontos;
			dificuldade_rank[rank] = dificuldade;
			
			printf("DIGITE UM APELIDO: ");
			scanf("%s", &nick_rank[rank]);
			printf("PR�VIA: %s          %g          DIF�CIL\n", nick_rank[rank], pontos_rank[rank]);
			
			rank++;
		}
	}
	else{
		printf("N�O FOI DESTA VEZ :(\n");
		printf("O N�MERO GERADO FOI: %d\n", aleatorio);
	}
	
	acertou=0;
	system("pause");
	system("cls");
	tudo();
}

//jogo na dificuldade personalizada
void personalizada(){
	printf("QUANTIDADE DE TENTATIVAS: %d\n", personalizado);
	
	for(jogadas=1;jogadas<=personalizado;jogadas++){
		printf("DIGITE UM N�MERO ENTRE 0 E 1000: ");
		scanf("%d", &num);
		
		if(num==aleatorio){
			printf("\nPARAB�NS VOC� ACERTOU!!!\n");
			acertou=1;
			jogadas=personalizado;
		}
		else{
			if(num<aleatorio){
				printf("DICA: O N�MERO GERADO � MAIOR QUE O DIGITADO\n");
			}
			else{
				printf("DICA: O N�MERO GERADO � MENOR QUE O DIGITADO\n");
			}
		}
	}
	
	if(acertou!=1){
		printf("N�O FOI DESTA VEZ :(\n");
		printf("O N�MERO GERADO FOI: %d\n", aleatorio);
	}
	
	acertou=0;
	system("pause");
	tudo();
}
