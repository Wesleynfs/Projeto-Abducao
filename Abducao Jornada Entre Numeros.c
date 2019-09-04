
			/* ==================================================================================================================================
			*	UNIFACEAR - FACULDADE EDUCACIONAL ARAUCÁRIA
			*	Nome da Aplicação: Abdução : Jornada Entre Numeros.exe                          Nome de Fonte: Abdução : Jornada Entre Numeros.c
			*	Propósito: Desenvolvimento de um jogo educacional para auxiliar nos estudos do ensino fundamental.
			*	Programador: Wesley de Araujo									                Data de entrega final 1º Bimestre 09/04/2019
			*  ==================================================================================================================================
			*/

			#include <conio.h>
			#include <stdio.h>
			#include <stdlib.h>
			#include <windows.h>
			#include <locale.h>
			#include <string.h>
			#include <mmsystem.h>		// para musicas .wav
		

			#define cima 72
			#define baixo 80
			#define esquerda 75
			#define direita 77
			
			#define WHITE "\x1b[0m"
			#define RESET "\x1b[0m"

			int musica = 0;		char som;   char som2;		int rmusic;

			char nome[50] = "DESCONHECIDO";		// <==== Essa variavel é o próprio nome do jogador

			int password = 0;	int senha = 0;

			char usuario[100]; // <===== Essa variavel é para os nomes dentro do .txt de LEITURA

			char escolha ;		// <==== Variavel escolha loop Iniciar jogo ou sair do jogo

			char key ;		// <==== Variavel de mudança de tela

			int escolha_personagem = 1 ;	// <==== Variavel

			int cor = 3;		// <==== Variavel para mudar a cor do jogo todo

			int numero_1 = 0; int numero_2 = 0; int resultado = 0; int resposta; int nivel = 1; //Variaveis para a tela de questao do jogo

			int pontuacao = 0; int maior_pontuacao = 0; int hp = 100; // Variaveis para pontuacao do jogador e pontos de vida

			int boa = 0; // Variavel que retorna se o usuario acertou ou errou a questão

			int boss = 0; // Variavel que conta quantas vezes o boss foi vencido

			char sensor1 = 32; char sensor2 = 32; char sensor3 = 32; char sensor4 = 32; char sensor5 = 32; char sensor6 = 32; char sensor7 = 32;
			char sensor8 = 32; char sensor9 = 32; char sensor10 = 32; char sensor11 = 32; char sensor0 = 32;

			int moves = 0;

			// Contagem de movimentos;

			int jogo;



			//====================================================================================================================================//


			int Som_errado() {

				Beep(300,100);
				Beep(300,100);
				Beep(300,100);
				Beep(250,100);

			}

			int Som_Movimento() {

				Beep(250,100);

			}

			int Som_Acertou() {

				Beep(400,100);
				Beep(500,200);
				Beep(600,200);
				Beep(500,200);
				Beep(600,200);

			}

			int Som_Questao() {


				Beep(500,50);
				Beep(600,50);
				Beep(400,50);
				Beep(700,50);
				Beep(400,50);
				Beep(600,50);
				Beep(500,50);

			}



			void gotoxy (int x , int y) {

				COORD cordenada;

				cordenada.X = x;
				cordenada.Y = y;

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cordenada);

				/* Board ou tela de fundo */

			}

			//====================================================================================================================================//




		void apagar_cursor() {

			CONSOLE_CURSOR_INFO cursor = {1, FALSE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

		}


		int randomizer_coluna() {

			return 1+(rand() % 118);

		}

		int randomizer_linha() {

			return 1+(rand() % 13);

		}

		void alien_1(int coluna , int linha) {
				
			gotoxy(coluna,linha);
			printf(" _/_\\_\n");
			gotoxy(coluna,linha + 1);
			printf("(o_o_o)\n");
			gotoxy(coluna,linha + 2);
			printf(" / | \\\n");
		
		}

		void alien_2(int coluna , int linha) {

			gotoxy(coluna,linha);
			printf("  \\ /\n");
			gotoxy(coluna,linha + 1);
			printf("<(o.o)>\n");
			gotoxy(coluna,linha + 2);
			printf(" //^\\\\\n");

		}

			int tela_menu() {

				system("cls");

				if (cor == 1) {

					system("color 04");	// Vermelho

				} else if (cor == 2) {

					system("color F0");	// Branco e preto

				} else if (cor == 3) {

					system("color 0A");	// Verde

				} else if (cor == 4) {

					system("color 03"); // Azul meio claro

				} else if (cor == 5) {

					system("color 0F"); // Cinza

				}

				key = 0;

				setlocale(LC_ALL, "Portuguese");

					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                     >>>>>>>>>> Ola Usuario Bem Vindo ao Abdução : Jornada Entre Numeros <<<<<<<<<<                   =\n");
					printf("=                                                                                                            *         =\n");
					printf("=                                              *                                        *                    *         =\n");
					printf("=                                              *                                        *                    *         =\n");
					printf("=                                              *             *         o###o            *                    *         =\n");
					printf("=                                                            *       o#######o          *                    *         =\n");
					printf("=   Jogo (1)                                 _o###o_         *     o#####Y#####o                _o###o_                =\n");
					printf("=                                          ##   o###o        *   d#######Y#######b            o###o   ##               =\n");
					printf("=   Opções (2)                             #      o##o          d########Y########b          o##o      #               =\n");
					printf("=                                                   o##o       d#########Y#########b        o#o                        =\n");
					printf("=   Instruções (3)                                    o##o_   |#####################|    _o##o                         =\n");
					printf("=                                                __     o####| O#ooo############ooo#O |####o     __                    =\n");
					printf("=   Créditos (4)                               o#####o     ##o ##     o#######o     ## o##     o####o                  =\n");
					printf("=                                            _##o  o###o_      ##o  X   o###o   X  o##      _####o  o##_               =\n");
					printf("=   Sair do Jogo (5)                                    o#####o ###o     ###     o### o#####o                          =\n");
					printf("=                                               o##o      o####  ###o__ o###o __o### #####o       o##o          *      =\n");
					printf("=                                              o######o_         o#################o          _o######o         *      =\n");
					printf("=                                     *      o##o   o#####o_      o###############o       _o#####o   o##o       *      =\n");
					printf("=                                     *      ##o        o######o_ o###         ###o   _o######o       o##       *      =\n");
					printf("=                                     *      ##o           o#####o o###       #### o#####o           o##               =\n");
					printf("=                                     *       o##o           o##### ####_____##### #####o           o##o               =\n");
					printf("=                                     *         oo                  o###########o                   oo                 =\n");
					printf("=                                     *                   *           o#######o           *                            =\n");
					printf("=                                     *                   *                               *                            =\n");
					printf("=                                                         *                               *                            =\n");
					printf("=                                                         *                                                            =\n");
					printf("========================================================================================================================\n");

				fflush(stdin);
				escolha = getch();

			}

			void tela_pontuacao_user() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				FILE * txt;

				txt = fopen("pontuacao.txt","r");

				fscanf(txt,"%d",&maior_pontuacao);

				fclose(txt);

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                              A pontuação geral mais alta é :  %i                                    =\n",maior_pontuacao);
				printf("=                                                                                                                      =\n");
				printf("=                                              Voltar (ESC)                                                            =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				fflush(stdin);
				key = getch();


			}



			void tela_personalizar_personagem() {

				Som_Movimento();

				system("cls");

				key = 0;

				printf("========================================================================================================================\n");
				printf("=                                        Bem vindo a tela de personalizações                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                       Escolha como quer que seu personagem seja                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                           Digite (1) Para modo Alien I                                               =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                           Digite (2) Para modo Alien II                                              =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                   _/_\\_                                                     \\ /                      =\n");
				printf("=           Alien I >>>            (o_o_o)                       Alien II >>>               ((o.o))                    =\n");
				printf("=                                   / | \\                                                    //^\\\\                   =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                   Voltar (ESC)                                                       =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				key = getch();

			}

			int login() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                       Bem vindo ao ABDUÇÃO : JORNADA ENTRE NUMEROS                                   =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=    Usuário :                                                                                                         =\n");
				printf("=    Senha :                                                                                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                     Sair (ESC)                                                       =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");

			}


			void tela_creditos() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                          Abdução : Jornada Entre Numeros                                             =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                     UNIFACEAR - FACULDADE EDUCACIONAL ARAUCÁRIA                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=    Nome da Aplicação: Abdução : Jornada Entre Numeros.exe     Nome de Fonte: Abdução : Jornada Entre Numeros.c       =\n");
				printf("=                                                                                                                      =\n");
				printf("=          Propósito: Desenvolvimento de um jogo educacional para auxiliar nos estudos do ensino fundamental.          =\n");
				printf("=                                                                                                                      =\n");
				printf("=               Programador: Wesley de Araujo               Data de entrega final 1º Bimestre 09/04/2019               =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                   Voltar (ESC)                                                       =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				key = getch();
				fflush(stdin);
			}

			void tela_opcoes() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");
				
				if (musica != 0) {
					
					som = 'X';
                    som2 = '\0';
					
				} else {
					
					som2 = 'X';
                    som = '\0';
					
				}

				printf("========================================================================================================================\n");
				printf("=                                             Bem vindo ao menu de opções                                              =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                             Personalizar Personagem (1)                                              =\n");
				printf("=                                             Mudar cor (2)                                                            =\n");
				printf("=                                             Musica (3)                                                               =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                             =====      =====                                                         =\n");
				printf("=                                    Ligado   = %c =      = %c =  Desligado                                              =\n",som,som2);
				printf("=                                             =====      =====                                                         =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                   Voltar (ESC)                                                       =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				key = getch();
				fflush(stdin);


			}

            void como_jogar() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=   Como Jogar :            Certo                           ||                    Errado                               =\n");
				printf("=                                                           ||                                                         =\n");
				printf("=                                                           ||                                                         =\n");
				printf("=                                                           ||                                                         =\n");
				printf("=                           (<>++<>)                        ||                         *                (<>++<>)       =\n");
				printf("=                            /|||||\\                        ||                         *                /|||||\\        =\n");
				printf("=                                                           ||                         *                               =\n");
				printf("=                             *                             ||                         *                               =\n");
				printf("=                             *                             ||                         *                               =\n");
				printf("=                             *                             ||                         *                               =\n");
				printf("=                             *             ___             ||                         *                  ___          =\n");
				printf("=                             *           ||TAB||           ||                         *                ||TAB||        =\n");
				printf("=                             *            -----            ||                         *                 -----         =\n");
				printf("=                             *                             ||                         *                               =\n");
				printf("=                             *                             ||                         *                               =\n");
				printf("=                             *                             ||                         *                               =\n");
				printf("=                             *                             ||                         *                               =\n");
				printf("=                                                           ||                                                         =\n");
				printf("=                           _/_\\_                           ||                       _/_\\_                             =\n");
				printf("=                          (o_o_o)                          ||                      (o_o_o)                            =\n");
				printf("=                           / | \\                           ||                       / | \\                             =\n");
				printf("=                                                           ||                                                         =\n");
				printf("=                                                           ||                                                         =\n");
				printf("=                                                           ||                                                         =\n");
				printf("=                                                                                                          (Enter)     =\n");
				printf("========================================================================================================================\n");				
				getchar();

            }

			void tela_login_errado() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                           USUÁRIO OU SENHA INCORRETOS!!                                              =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                    (Enter)                                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");				
				getchar();
				getchar();
			}

			void tela_login_certo() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                               LOGIN FEITO COM SUCESSO                                                =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                    (Enter)                                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");				
				getchar();
				getchar();
			}

			void tela_inicio_jogo() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=      Em uma galáxia muito distante...                                         Abdução : Jornada Entre Numeros        =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Seu nome é %s                                                                                              =\n",nome);
				printf("=                                                                                                                      =\n");
				printf("=      >>> No ano de 2077 voce estava no trabalho e então decide sair para tomar um ar...                              =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Então você sai da sala de trabalho e atende o telefone, mas DERREPENTE um clarão aparece no céu e....       =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Você foi ABDUZIDO!!! , após isso você sai sem saber onde está.. mas encontra uma nave abandonada            =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Dentro dela existem alguns arquivos, ignorando-os você acha uma cadeira com uma espécie                     =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> De controle da nave e então derrepente APARECE UM ALIEN falando coisas em outras linguas                    =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Você com medo, aperta um botão e a nave começa flutuar, e o alien consegue sair pela porta da nave          =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Sem saber você acaba despertando a raiva dele que o persegue dentro de sua própria nave        ||           =\n");
				printf("=                                                                                                         ||           =\n");
				printf("=      >>> Os controles da nave são diferentes porém existem numeros espalhados pela tela               # || #         =\n");
				printf("=                                                                                                        #  #          =\n");
				printf("=      >>> Voce decide usa-los para facilitar seu voo, mas não sabe o que pode ocorrer após fazer isso    ##           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                      (<>++<>)        =\n");
				printf("=                                                 Pressione (Enter)                                     /|||||\\       =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				
				getchar();
				
				Som_Movimento();

				system("cls");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=      Dentro da nave                                                           Abdução : Jornada Entre Numeros        =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Após alguns minutos na nave você perde o controle por alguns instantes e ve uma tela acender a sua frente   =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Um outro alien aparece porém MAIOR E MAIS ASSUSTADOR, ele consegue falar a lingua humana                    =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Então diz...                                                                                                =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Fugir não é o suficiente humano!, mostre sua sabedoria e eu pensarei em deixa-lo sair daqui                 =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Você não pensou duas vezes e começou a lutar contra a nave alienigena através de multiplicações             =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Tanto por sua vida quanto para voltar ao planeta terra!!                                                    =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> ALGUNS MINUTOS APÓS ISSO...                                                                                 =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> Outro alien entra em contato com você através da mesma tela... ele diz estar do seu lado, e mostra uma dica =\n");
				printf("=                                                                                                                      =\n");
				printf("=      >>> De como seguir, ele diz (EXISTE APENAS UM MÉTODO DE SAIR, ATINGINDO UMA PONTUAÇÂO MAIOR QUE 1500 PONTOS)    =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                 Pressione (Enter)                                                    =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				
				getchar();

				Som_Movimento();
				
				system("cls");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=        SEM RAIVA       COM RAIVA                                  FIQUE DE OLHO NO MEDIDOR DE RAIVA DO ALIEN!        =\n");
				printf("=                                                                                                                      =\n");
				printf("=          = = =          = = =                                                                                        =\n");
				printf("=          =   =          = # =                                     ELE SOBE CASO VOCÊ APERTE (TAB) E ELE ESTEJA       =\n");
				printf("=          =   =          = # =                                                                                        =\n");
				printf("=          =   =          = # =                                                                                        =\n");
				printf("=          =   =          = # =                                     FORA DA MIRA, PROCURE DEIXAR SUA NAVE ALINHADA     =\n");
				printf("=          =   =          = # =                                                                                        =\n");
				printf("=          =   =          = # =                                                                                        =\n");
				printf("=          =   =          = # =                                     COM O ALINIGENA E ENTÃO APERTE (TAB)               =\n");
				printf("=          =   =          = # =                                                                                        =\n");
				printf("=          =   =          = # =                                                                                        =\n");
				printf("=          =   =          = # =                                     SE VOCÊ ERRAR O ALIEN IRÁ SE ENFURECER QUANDO      =\n");
				printf("=          =   =          = # =                                                                                        =\n");
				printf("=          = = =          = = =                                                                                        =\n");
				printf("=                                                                   COMPLETAR SUA BARRA DE RAIVA E ENTÃO               =\n");
				printf("=                                                                                                                      =\n");
				printf("=      (PARA DIMINUIR A RAIVA MOVIMENTE-SE)                                                                            =\n");
				printf("=                                                                   TERÁ O DIREITO DE TIRAR 10 PONTOS DE VIDA DA       =\n");
				printf("=               (PELO TABULEIRO)                                                                                       =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                   SUA NAVE                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");

				getchar();
				
				system("cls");

				fflush(stdin);
			}


			void tela_instrucoes() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                             Bem vindo menu de instruções                                             =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=          As Instruções são bem simples, use as setas (Cima,Baixo,Direta,Esquerda)                                    =\n");
				printf("=                                                                                                                      =\n");
				printf("=          Para movimentar-se pelo planeta                                                                             =\n");
				printf("=                                                                                                                      =\n");
				printf("=          E nos menus digite o numero correspondente para entrar ou sair de uma opção .                               =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                       # # #      # # #      # # #      # # #      #############                                      =\n");
				printf("=                     #       #  #       #  #       #  #       #   #             #                                     =\n");
				printf("=   Movimentos  ===>  # cima #   #  baix #  #  esq  #  #  dir  #   #     TAB     # <=== Atacar o Alien com matemática  =\n");
				printf("=                     #       #  #       #  #       #  #       #   #             #                                     =\n");
				printf("=                       # # #      # # #      # # #      # # #      #############                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                   Voltar (ESC)                                                       =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				key = getch();
				fflush(stdin);
			}

		void tela_add_usuario() {

			Som_Movimento();

				system("cls");
				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                              Tela de adicionar usuarios                                              =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                   Digite (1) Para adicionar um nome e entao digite                                   =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                   Nome :                                                                             =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                   Senha :                                                                            =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                 (ESC) para voltar                                                    =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");

				key = getch();

		}

		void tela_logar() {

			Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                              Usuário nao cadastrado!                                                 =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                        Vá para : Jogo >> Cadastrar Usuário                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                    (ENTER)                                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");

		}

			void tela_confirmacao() {

				Som_Movimento();

				system("cls");

				system("color 0F");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                             Alteração feita com sucesso!!                                            =\n");
				printf("=                                                       (ENTER)                                                        =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				getch();

			}

			void tela_sair() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                             Bem vindo a tela sair                                                    =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                               Certeza??                                                              =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                               Sim (s) ou Nao (n)                                                     =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                               Voltar (ESC)                                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				key = getch();
				fflush(stdin);
			}


			void tela_cadastro() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");


				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                            Abdução : Jornada Entre Numeros                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                               Jogar (Espaço)                                                         =\n");
				printf("=                                               Cadastrar Usuário (1)                                                  =\n");
				printf("=                                               Pontuação (2)                                                          =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                               Voltar (ESC)                                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");

				key = getch();
				fflush(stdin);

			}


			void tela_mudar_cor() {

				Som_Movimento();

				system("cls");

				key = 0;

				setlocale(LC_ALL, "Portuguese");

				printf("========================================================================================================================\n");
				printf("=                                                                                                                      =\n");
				printf("=                                        Bem vindo, escolha sua galáxia                                                =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                              (1) - NGC 6946      >>> (Vermelho)                                      =\n");
				printf("=                                              (2) - Via Láctea    >>> (Branco)                                        =\n");
				printf("=                                              (3) - Andrômeda     >>> (Verde)                                         =\n");
				printf("=                                              (4) - Messier 104   >>> (Azul)                                          =\n");
				printf("=                                              (5) - IC 5152       >>> (Preto)                                         =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                               Voltar (ESC)                                                           =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("=                                                                                                                      =\n");
				printf("========================================================================================================================\n");
				key = getch();

			}

		int tela_errou() {

			Som_Movimento();

					system("cls");
					printf("========================================================================================================================\n");
					printf("=                                   *                                                                                  =\n");
					printf("=                                   *              Desista HUMANO!!!!!                                                 =\n");
					printf("=    *                                           Alien (O ATORMENTADOR)                      *                         =\n");
					printf("=    *                                                                                       *                         =\n");
					printf("=    *                                                                                       *                         =\n");
					printf("=    *                                                  o###o                                                          =\n");
					printf("=    *                                                o#######o                                                        =\n");
					printf("=                             _o###o_               o#####Y#####o                _o###o_                  *            =\n");
					printf("=                           ##   o###o            d#######Y#######b            o###o   ##                 *            =\n");
					printf("=                           #      o##o          d########Y########b          o##o      #                 *            =\n");
					printf("=                                    o##o       d#########Y#########b        o#o                          *            =\n");
					printf("=                                      o##o_   |#####################|    _o##o                           *            =\n");
					printf("=                *                __     o####| O#ooo############ooo#O |####o     __                                   =\n");
					printf("=                *              o#####o     ##o ##     o#######o     ## o##     o####o                                 =\n");
					printf("=                *            _##o  o###o_      ##o  X   o###o   X  o##      _####o  o##_                              =\n");
					printf("=                *                       o#####o ###o     ###     o### o#####o                                         =\n");
					printf("=                *               o##o      o####  ###o__ o###o __o### #####o       o##o             *                  =\n");
					printf("=                *              o######o_         o#################o          _o######o            *                  =\n");
					printf("=                             o##o   o#####o_      o###############o       _o#####o   o##o          *                  =\n");
					printf("=                             ##o        o######o_ o###         ###o   _o######o       o##          *                  =\n");
					printf("=                             ##o           o#####o o###       #### o#####o           o##           *                  =\n");
					printf("=                              o##o           o##### ####_____##### #####o           o##o                              =\n");
					printf("=                                oo                  o###########o                   oo                                =\n");
					printf("=                                                      o#######o                                                       =\n");
					printf("=                                                                                                                      =\n");
					printf("=           MIRA ERRADA HAHAHAHA !!!                   RAIVA + 10!!!!!!                     TENTE NOVAMENTE            =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");
		
		}

		int Resposta_boa() {

			Som_Movimento();

					setlocale(LC_ALL, "Portuguese");
					system("cls");
					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                  Desista HUMANO!!!!!                                                 =\n");
					printf("=                                                Alien (O ATORMENTADOR)                                                =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                       o###o                                                          =\n");
					printf("=                                                     o#######o                                                        =\n");
					printf("=                             _o###o_               o#####Y#####o                _o###o_                               =\n");
					printf("=                           ##   o###o            d#######Y#######b            o###o   ##                              =\n");
					printf("=                           #      o##o          d########Y########b          o##o      #                              =\n");
					printf("=                                    o##o       d#########Y#########b        o#o                                       =\n");
					printf("=                                      o##o_   |#####################|    _o##o                                        =\n");
					printf("=                                 __     o####| O#ooo############ooo#O |####o     __                                   =\n");
					printf("=                               o#####o     ##o ##     o#######o     ## o##     o####o                                 =\n");
					printf("=                             _##o  o###o_      ##o  X   o###o   X  o##      _####o  o##_                              =\n");
					printf("=                                        o#####o ###o     ###     o### o#####o                                         =\n");
					printf("=                                o##o      o####  ###o__ o###o __o### #####o       o##o                                =\n");
					printf("=                               o######o_         o#################o          _o######o                               =\n");
					printf("=                             o##o   o#####o_      o###############o       _o#####o   o##o                             =\n");
					printf("=                             ##o        o######o_ o###############o   _o######o       o##                             =\n");
					printf("=                             ##o           o#####o o############## o#####o           o##                              =\n");
					printf("=                              o##o           o##### ####=====##### #####o           o##o                              =\n");
					printf("=                                oo                  o###########o                   oo                                =\n");
					printf("=                                                      o#######o                                                       =\n");
					printf("=                                                                                                                      =\n");
					printf("=               Apenas um ato de sorte humano!                           Pressione uma seta para voltar ao jogo        =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");

					

		}

		int Resposta_ruim() {

					if (boss == 1) {

						system("cls");
						printf("UNIVERSO RED DESBLOQUEADO E O ALIEN DOMINOU O UNIVERSO\nCONTINUE JOGANDO OU PRESSIONE ESC PARA SAIR\nMEUS PARABENS!!! VOCE FINALIZOU O JOGO!!!");
						system("pause");

						return;

					} else {

						Som_Movimento();
						

					setlocale(LC_ALL, "Portuguese");
					system("cls");
					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                  Desista HUMANO!!!!!                                                 =\n");
					printf("=                                                Alien (O ATORMENTADOR)                                                =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                       o###o                                                          =\n");
					printf("=                                                     o#######o                                                        =\n");
					printf("=                             _o###o_               o#####Y#####o                _o###o_                               =\n");
					printf("=                           ##   o###o            d#######Y#######b            o###o   ##                              =\n");
					printf("=                           #      o##o          d########Y########b          o##o      #                              =\n");
					printf("=                                    o##o       d#########Y#########b        o#o                                       =\n");
					printf("=                                      o##o_   |#####################|    _o##o                                        =\n");
					printf("=                                 __     o####| O#ooo############ooo#O |####o     __                                   =\n");
					printf("=                               o#####o     ##o ##     o#######o     ## o##     o####o                                 =\n");
					printf("=                             _##o  o###o_      ##o  X   o###o   X  o##      _####o  o##_                              =\n");
					printf("=                                        o#####o ###o     ###     o### o#####o                                         =\n");
					printf("=                                o##o      o####  ###o__ o###o __o### #####o       o##o                                =\n");
					printf("=                               o######o_         o#################o          _o######o                               =\n");
					printf("=                             o##o   o#####o_      o###############o       _o#####o   o##o                             =\n");
					printf("=                             ##o        o######o_ o###         ###o   _o######o       o##                             =\n");
					printf("=                             ##o           o#####o o###       #### o#####o           o##                              =\n");
					printf("=                              o##o           o##### ####_____##### #####o           o##o                              =\n");
					printf("=                                oo                  o###########o                   oo                                =\n");
					printf("=                                                      o#######o                                                       =\n");
					printf("=                                                                                                                      =\n");
					printf("=               COMO O PLANEJADO hahahaha!!                              Pressione uma seta para voltar ao jogo        =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");
					return;				
						
					}

		}

			int tela_nivel_boss() {

				Som_Movimento();

					setlocale(LC_ALL, "Portuguese");
					system("cls");
					system("color 4F");
					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                       Alien Atormentador (BOSS FIGHT)                                                                =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                  o###o                                                                               =\n");
					printf("=                                o#######o                                                                             =\n");
					printf("=        _o###o_               o#####Y#####o                _o###o_                                                    =\n");
					printf("=      ##   o###o            d#######Y#######b            o###o   ##                                                   =\n");
					printf("=      #      o##o          d########Y########b          o##o      #                                                   =\n");
					printf("=               o##o       d#########Y#########b        o#o                                                            =\n");
					printf("=                 o##o_   |#####################|    _o##o                                                             =\n");
					printf("=           __     o####| O#ooo############ooo#O |####o     __                                                         =\n");
					printf("=         o#####o     ##o ##     o#######o     ## o##     o####o                                                       =\n");
					printf("=       _##o  o###o_      ##o  X   o###o   X  o##      _####o  o##_                                                    =\n");
					printf("=                  o#####o ###o     ###     o### o#####o                                                               =\n");
					printf("=          o##o      o####  ###o__ o###o __o### #####o       o##o                                                      =\n");
					printf("=         o######o_         o#################o          _o######o                                                     =\n");
					printf("=       o##o   o#####o_      o###############o       _o#####o   o##o                                                   =\n");
					printf("=       ##o        o######o_ o###############o   _o######o       o##                                                   =\n");
					printf("=       ##o           o#####o o###o-----o#### o#####o           o##                                                    =\n");
					printf("=        o##o           o##### ####_____##### #####o           o##o                                                    =\n");
					printf("=          oo                  o###########o                   oo                                                      =\n");
					printf("=                                o#######o                                                                             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                RESPONDA CORRETAMENTE OU SERA ANIQUILADO!!!!!!!!!        %i   X   %i   /   %i   =   ?                 =\n",numero_1,numero_2,numero_2);
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");
					gotoxy(75,19);
					scanf("%i",&resposta);
					return;
			}

			int Game_Over() {
				
				Som_Movimento();

					system("cls");
					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                                            Abdução : Jornada Entre Numeros                                           =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                         GAME-OVER!! Sua pontuação foi de : %i                                        =\n",pontuacao);
					printf("=                                                                                                                      =\n");
					printf("=                                                         (Enter)                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");
					getchar();

			}

		int tela_pergunta_1() {

			Som_Movimento();

					setlocale(LC_ALL, "Portuguese");

					system("cls");

					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=               Responda correto ou será aniquilado!!, Se estiver correto continue sua jornada!, se não...             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                             PERCA 10 PONTOS DE VIDA!!!!!                                             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                 %i   +   %i                                                            =\n",numero_1,numero_2);
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");
					gotoxy(65,12);
					scanf("%i",&resposta);
					return;
					

		}

		int tela_pergunta_2() {

				Som_Movimento();

					setlocale(LC_ALL, "Portuguese");

					system("cls");

					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=               Responda correto ou será aniquilado!!, Se estiver correto continue sua jornada!, se não...             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                             PERCA 10 PONTOS DE VIDA!!!!!                                             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                 %i   -   %i                                                            =\n",numero_1,numero_2);
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");
					gotoxy(65,12);
					scanf("%i",&resposta);
					return;

		}

		int tela_pergunta_3() {

			Som_Movimento();

					setlocale(LC_ALL, "Portuguese");

					system("cls");

					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=               Responda correto ou será aniquilado!!, Se estiver correto continue sua jornada!, se não...             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                             PERCA 10 PONTOS DE VIDA!!!!!                                             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                 %i   X   %i                                                            =\n",numero_1,numero_2);
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");
					gotoxy(65,12);
					scanf("%i",&resposta);
					return;

		}

		int tela_pergunta_4() {

			Som_Movimento();

					setlocale(LC_ALL, "Portuguese");

					system("cls");

					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=               Responda correto ou será aniquilado!!, Se estiver correto continue sua jornada!, se não...             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                             PERCA 10 PONTOS DE VIDA!!!!!                                             =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                 %i   /   %i                                                            =\n",numero_1,numero_2);
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("========================================================================================================================\n");
					gotoxy(65,12);
					scanf("%i",&resposta);
					return;

		}

			void tela_questao() {

					srand(time(NULL));

								if (pontuacao < 100) {

									nivel = 1;

								} else if ((pontuacao >= 100) && (pontuacao < 200)) {

									nivel = 2;

								} else if ((pontuacao >= 200) && (pontuacao < 300)) {

									nivel = 3;

								} else if ((pontuacao >= 300) && (pontuacao < 1499)) {

									nivel = 4;

								} else if (pontuacao >= 1500) {

									nivel = 5;

								}


						if (nivel == 1) {

							numero_1 = 1+rand() % 10;
							numero_2 = 1+rand() % 10;
							resultado = numero_1 + numero_2;

						} else if (nivel == 2) {

							numero_1 = 1+rand() % 10;
							numero_2 = 1+rand() % 10;
							resultado = numero_1 - numero_2;

						} else if (nivel == 3) {

							numero_1 = 1+rand() % 10;
							numero_2 = 1+rand() % 20;
							resultado = numero_1 * numero_2;

						} else if (nivel == 4) {

							numero_1 = 10+(rand() % 100);
							numero_2 = rand() % 10;
							resultado = numero_1 / numero_2;

						} else if (nivel == 5) {

							numero_1 = 1+rand() % 10;
							numero_2 = 1+rand() % 10;							
							resultado = numero_1 * numero_2 / numero_2;
																	

						}
							if (nivel == 1) {
								
								tela_pergunta_1();

							} else if (nivel == 2) {

								tela_pergunta_2();

							} else if (nivel == 3) {

								tela_pergunta_3();

							} else if (nivel == 4) {

								tela_pergunta_4();

							} else if (nivel == 5) {

								tela_nivel_boss();

							}


						if (resposta == resultado) {

							Som_Acertou();
							Resposta_boa();
							pontuacao = pontuacao + 10;


						} if (resposta != resultado) {

							Som_errado();
							Resposta_ruim();
							hp = hp - 10;

						}

			}

			void tela_jogo() {

				 int coluna = 53 ; int linha = 16 ; char tecla = 0; int Pos_alien_x = 0; int Pos_alien_y = 0;

					system("cls");

					gotoxy(coluna-4,linha);
					printf("___");

					gotoxy(coluna-4,linha+1);
					printf("___");

					gotoxy(coluna-11,linha+3);
					printf("___");

					gotoxy(coluna-11,linha);
					printf("___");

					gotoxy(coluna-4,linha-1);
					printf("___");

					gotoxy(coluna-11,linha+3);
					printf("___");

					gotoxy(coluna-11,linha-3);
					printf("___");

					gotoxy(coluna-35,linha+10);
					printf("                    Pressione a seta (baixo) para assumir o controle HUMANO!");
					gotoxy(coluna-40,linha+11);
					printf("                       LEMBRE-SE NO TABULEIRO APERTE (TAB) PARA ATACAR!!!!!!!");


						if (escolha_personagem == 1) {

								gotoxy(coluna,linha);
								printf("   _/_\\_		\n");
								gotoxy(coluna,linha + 1);
								printf("  (o_o_o)		\n");
								gotoxy(coluna,linha + 2);
								printf("   / | \\		\n");

						} else if (escolha_personagem == 2) {

								gotoxy(coluna,linha);
								printf("     \\ / 		\n");
								gotoxy(coluna,linha + 1);
								printf("   <(o.o)>		\n");
								gotoxy(coluna,linha + 2);
								printf("    //^\\\\		\n");


						} else {

							printf("PERSONAGEM NAO DEFINIDO.. SAINDO..");
							sleep(2);


						}
						getch();

					jogo = 1;

					while (jogo == 1) {


						switch (moves) {

							case 0 : sensor0 = 32;
									sensor1 = 32;
									sensor2 = 32;
									sensor3 = 32;
									sensor4 = 32;
									sensor5 = 32;
									sensor6 = 32;
									sensor7 = 32;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 1 : sensor0 = 35;
									sensor1 = 32;
									sensor2 = 32;
									sensor3 = 32;
									sensor4 = 32;
									sensor5 = 32;
									sensor6 = 32;
									sensor7 = 32;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 2 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 32;
									sensor3 = 32;
									sensor4 = 32;
									sensor5 = 32;
									sensor6 = 32;
									sensor7 = 32;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 3 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 32;
									sensor4 = 32;
									sensor5 = 32;
									sensor6 = 32;
									sensor7 = 32;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 4 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 32;
									sensor5 = 32;
									sensor6 = 32;
									sensor7 = 32;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 5 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 35;
									sensor5 = 32;
									sensor6 = 32;
									sensor7 = 32;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 6 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 35;
									sensor5 = 35;
									sensor6 = 32;
									sensor7 = 32;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 7 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 35;
									sensor5 = 35;
									sensor6 = 35;
									sensor7 = 32;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 8 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 35;
									sensor5 = 35;
									sensor6 = 35;
									sensor7 = 35;
									sensor8 = 32;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 9 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 35;
									sensor5 = 35;
									sensor6 = 35;
									sensor7 = 35;
									sensor8 = 35;
									sensor9 = 32;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 10 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 35;
									sensor5 = 35;
									sensor6 = 35;
									sensor7 = 35;
									sensor8 = 35;
									sensor9 = 35;
									sensor10 = 32;
									sensor11 = 32;
							break;
							case 11 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 35;
									sensor5 = 35;
									sensor6 = 35;
									sensor7 = 35;
									sensor8 = 35;
									sensor9 = 35;
									sensor10 = 35;
									sensor11 = 32;
							break;
							case 12 : sensor0 = 35;
									sensor1 = 35;
									sensor2 = 35;
									sensor3 = 35;
									sensor4 = 35;
									sensor5 = 35;
									sensor6 = 35;
									sensor7 = 35;
									sensor8 = 35;
									sensor9 = 35;
									sensor10 = 35;
									sensor11 = 35;
						}

					int tela() {
								
							
										
					system("cls");

					printf("========================================================================================================================\n");
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                                      =\n");
					printf("=          %c                                                                                                %c          =\n",42,42);
					printf("=                                                                         %c                                            =\n",42);
					printf("=                                                                                                                      =\n");
					printf("=                                                                                                 %c                    =\n",42);
					printf("=                                                     %c                                                                =\n",42);
					printf("=                    %c                                                                                                 =\n",42);
					printf("=                                                                                                                      =\n");
					printf("=                                                                             %c                                        =\n",42);
					printf("=                                   %c                                                                                  =\n",42);
					printf("=           %c                                                                                                          =\n",42);
					printf("=                                                                                                       %c              =\n",42);
					printf("=                                                                                                                      =\n");
					printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ( Nivel %i ) = = =\n",nivel);
					printf("= %c =                                                                                                                  =\n",sensor11);
					printf("= %c =                                    %c                                                         %c                   =\n",sensor10,42,42);
					printf("= %c =                                                       %c                                                          =\n",sensor9,42);
					printf("= %c =             %c                                                               %c                                    =\n",sensor8,42,42);
					printf("= %c =                                                                                                                  =\n",sensor7);
					printf("= %c =                                                                                                                  =\n",sensor6);
					printf("= %c =                            %c                                          %c                                          =\n",sensor5,42,42);
					printf("= %c =                                                                                                                  =\n",sensor4);
					printf("= %c =                                                                                                                  =\n",sensor3);
					printf("= %c =                                                                                                  %c               =\n",sensor2,42);
					printf("= %c =                %c                                  %c                                                              =\n",sensor1,42,42);
					printf("= %c =                                                                            %c                                     =\n",sensor0,42);
					printf("========================================================================================================================\n");
					printf(" >>  Cordenadas na galaxia  | %i | %i |   Pontos de vida   | %i%c |  Pontuação  | %i | ################  Sair (Esc) << ",coluna,linha,hp,37,pontuacao);
					fflush(stdin);

						Pos_alien_x = 3+(rand() % 110);	Pos_alien_y = 3+(rand() % 10); 

						gotoxy(Pos_alien_x,Pos_alien_y);
						printf("(<>++<>)");
						gotoxy(Pos_alien_x,Pos_alien_y+1);
						printf("/|||||\\");

					}

							tecla = getch();

						if (( tecla == baixo ) && ( linha < 23 )) {

							if (moves != 0) {

								moves = moves-1;

							}

							Som_Movimento();
							linha = linha + 3;
							tela();

						if (escolha_personagem == 1) {

							alien_1(coluna,linha);

						} else if (escolha_personagem == 2) {

							alien_2(coluna,linha);


						} else {

							printf("PERSONAGEM NAO DEFINIDO.. SAINDO..");
							sleep(2);
							break;

						}


						} else if (( tecla == cima ) && ( linha > 16 )) {

							if (moves != 0) {

								moves = moves-1;

							}

							Som_Movimento();
							linha = linha - 3;
							tela();


						if (escolha_personagem == 1) {

							alien_1(coluna,linha);

						} else if (escolha_personagem == 2) {

							alien_2(coluna,linha);

						} else {

							printf("PERSONAGEM NAO DEFINIDO.. SAINDO..");
							sleep(2);
							break;

						}


						} else if ((tecla == direita) && (coluna < 106)) {

							if (moves != 0) {

								moves = moves-1;

							}

							Som_Movimento();
							coluna = coluna + 6;
							tela();


						if (escolha_personagem == 1) {

							alien_1(coluna,linha);

						} else if (escolha_personagem == 2) {

							alien_2(coluna,linha);

						} else {

							printf("PERSONAGEM NAO DEFINIDO.. SAINDO..");
							sleep(2);
							break;

						}


						} else if ((tecla == esquerda) && (coluna > 6)) {

							if (moves != 0) {

								moves = moves-1;

							}

							Som_Movimento();
							coluna  = coluna - 6;
							tela();


						if (escolha_personagem == 1) {

							alien_1(coluna,linha);

						} else if (escolha_personagem == 2) {

							alien_2(coluna,linha);

						} else {

							printf("PERSONAGEM NAO DEFINIDO.. SAINDO..");
							sleep(2);
							break;

						}


						} else if (tecla == 27) {

							pontuacao = 0;
							hp = 100;
							moves = 0;
							break;					// Sai do jogo para o menu


						} else if (hp <= 0) {

							Game_Over();
							hp = 100;
							moves = 0;

								if (pontuacao > maior_pontuacao) {

									maior_pontuacao = pontuacao;

									FILE * txt;

									txt = fopen("pontuacao.txt","w");

									fprintf(txt,"%d",maior_pontuacao);

									fclose(txt);

								} else {

									pontuacao = 0;

								}

							pontuacao = 0;
							break;					// Sai do jogo para o menu

						} else if (tecla == 9) {	//Tab

							if (moves < 12) {

								moves = moves + 2;	

							} else {

								hp = hp - 10;

							}

								if ((Pos_alien_x == coluna) || (Pos_alien_x == coluna+1)|| (Pos_alien_x == coluna+2) || (Pos_alien_x == coluna+3) || (Pos_alien_x == coluna-3) || (Pos_alien_x == coluna-2)|| (Pos_alien_x == coluna -1) || (Pos_alien_x == coluna+6)|| (Pos_alien_x == coluna-6)|| (Pos_alien_x == coluna+5)|| (Pos_alien_x == coluna+4)|| (Pos_alien_x == coluna-5)|| (Pos_alien_x == coluna-4)) {

									Som_Questao();
									tela_questao();
									tecla = getch();

								} else {
								
									printf("\a");
									tela_errou();

								}

							}

						}


					}

				// Fim das Telas do Jogo, Abaixo Código fonte com lógica 

			int main (void) {

				apagar_cursor();

				setlocale(LC_ALL, "Portuguese");

				SetConsoleTitle("Abducao : Jornada Entre Numeros");

					// Comentar Linha abaixo caso compilação falhe ou nao exista o arquivo .wav na pasta //
		
		music:
					
					rmusic = 1+rand()%5;
		
				if (musica == 1) {
		
					if (rmusic == 1) {
						
						PlaySound(TEXT("Sound1.wav"),NULL,SND_ASYNC);
						
						
					} if (rmusic == 2) {
						
						PlaySound(TEXT("Sound2.wav"),NULL,SND_ASYNC);
						
						
					} if (rmusic == 3) {
						
						PlaySound(TEXT("Sound3.wav"),NULL,SND_ASYNC);
						
						
					} if (rmusic == 4) {
						
						PlaySound(TEXT("Sound4.wav"),NULL,SND_ASYNC);
						
						
					} if (rmusic == 5){
						
						PlaySound(TEXT("Sound5.wav"),NULL,SND_ASYNC);
						
					}
		

				} else if ((musica == 0) || (rmusic != 0)){
					
					PlaySound(NULL, 0, 0);
					
				}
				
				escolha = 0;

				while (escolha != 1000) {

					tela_menu();		// ********************** TELA INICIAL (PONTO ZERO) ************************

					if (escolha == 49) {

						tela_cadastro();		// ********************** TELA CADASTRO OU NOVO JOGO ************************

					if ( key == 32 ) {

						login();
						gotoxy(16,4);
						scanf("%s",&usuario);
						gotoxy(14,5);
						scanf("%i",&senha);

						system("cls");

							FILE *arquivo;

							arquivo = fopen("login.txt","r");

							if ((arquivo == NULL)||(nome == NULL)) {

								tela_logar();
								getch();
								escolha = 0;

							}

							fscanf(arquivo,"%s",&nome);
							fscanf(arquivo,"%i",&password);

								if (strcmp(usuario,nome) == 0) {

									if (senha == password) {

										tela_login_certo();
										tela_inicio_jogo();
                                        como_jogar();
										tela_jogo();

									}

								} else {

									tela_login_errado();
									escolha = 0;

								}

						fclose(arquivo);

					}

						if (key == 50) {

							tela_pontuacao_user();


							if (key == 27) {

								escolha = 0;

							}

						} else {

							escolha = 0;

					}

						if (key == 49) {

							//tela onde cadastra nome no arquivo player_list.txt

								FILE *arquivo;
								arquivo = fopen("login.txt","w");

								if (arquivo == NULL) {

										printf("Nao foi possivel abrir o arquivo\n");
										printf("Digite algo para retornar ao menu anterior\n");
										getch();

										escolha = 49; //////////

								} else {

										tela_add_usuario();

											if (key == 27) {

												escolha = 0;

											} else {

												gotoxy(43,16);
												fgets(nome , 50 , stdin);
												gotoxy(44,18);
												fscanf(stdin,"%i",&password);
												fprintf(arquivo,"%s",nome);
												fprintf(arquivo,"%i",password);
												fclose(arquivo);			// Finalizar arquivo .txt com segurança
												escolha = 0;

										}
								}
						} 

					} if (escolha == 50) {

						tela_opcoes();		// ********************** TELA OPCOES ************************

							if (key == 49) {

								tela_personalizar_personagem();

									if (key == 27) {

										key = 49;

									}

									if (key == 49) {

										// Armazenando o personagem na variavel
										escolha_personagem = 1;
										tela_confirmacao();
										key = 49;

									} else if (key == 50) {

										escolha_personagem = 2;
										tela_confirmacao();
										key = 49;

									} else {

										key = 49;

									}

							} if (key == 50) {

								tela_mudar_cor();

									if (key == 49) {

										tela_confirmacao();

											cor = 1;		// Cor DARK

										escolha = 49;

									}

									if (key == 50) {

										tela_confirmacao();

											cor = 2;		// Cor WHITE

										escolha = 49;

									}

									if (key == 51) {

										tela_confirmacao();

											cor = 3;

										escolha = 49;

									}

									if (key == 52) {

										tela_confirmacao();

											cor = 4;

										escolha = 49;

									}

									if (key == 53) {

										tela_confirmacao();

											cor = 5;

										escolha = 49;

									}

									if (key == 27) {

										escolha = 50;

									}

							} else if ((key == 51) && (musica == 0)) {
								
								musica = 1;
								goto music;	
								
							} else if ((key == 51) && (musica == 1)) {
								
								musica = 0;
								goto music;
								
							} else {

								escolha = 49;

							}

					}

					if (escolha == 51) {

						tela_instrucoes();		// ********************** TELA INSTRUÇÕES ************************
						escolha = 49;
					}

					if (escolha == 52) {

						tela_creditos();	// ********************** TELA CREDITOS ************************
						escolha = 49;

					}

					if ((escolha == 53)||(escolha == 27)) {

						tela_sair();	// ********************** TELA SAIR ************************

						if ((key == 115) || (key == 13) || (key == 83)) {		//Enter ou S

							return 0;		//Comando para sair

						} if ((key == 27)||(key == 110)||(key == 78)) {

							escolha = 49;

						}

					}

					else

					{

						escolha = 0;	// ********************** PARA NAO CRASHAR AO APERTAR QUALQUER COISA ************************

					}
				}

				return 0;

			}


