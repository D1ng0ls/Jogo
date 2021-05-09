package me.jogo;

import java.util.Random;
import java.util.Scanner;

public class JogoEduardo {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Random gerador = new Random();

        int number, erro, resp, dif = 0, opc, opcao, tentativas = 0, dificuldade, lFac = 0, lMed = 0, lDif = 0;
        String[] nickFac = new String[1000];
        String[] nickMed = new String[1000];
        String[] nickDif = new String[1000];
        int[] pontFac = new int[1000];
        int[] pontMed = new int[1000];
        int[] pontDif = new int[1000];

        do {

            //menu principal
            System.out.println("\n-- Menu Principal --");
            System.out.print("1- Jogar\n2- Dificuldade(");

            if (dif == 0) {
                System.out.println("Fácil)");
            } else if (dif == 1) {
                System.out.println("Média)");
            } else if (dif == 2) {
                System.out.println("Difícil)");
            } else {
                System.out.println("Personalizada)");
            }

            System.out.println("3- Como jogar\n4- Ranking\n5- Sair");
            opc = entrada.nextInt();

            //jogo
            if (opc == 1) {
                number = gerador.nextInt(100);
                erro = 0;

                //jogo na dificuldade fácil - padrão
                if (dif == 0) {
                    for (int i = 1; i <= 20; ++i) {
                        System.out.println("\nTentativa Nº" + i + " :");
                        System.out.println("Digite um número de 0 a 100:");
                        resp = entrada.nextInt();

                        if (erro == 10) {
                            System.out.println("\nNão foi desta vez! Tente novamente!");
                            opc = 0;
                        }

                        if (resp > number) {
                            System.out.println("\nO número gerado é menor que o número digitado:");
                            ++erro;
                        } else if (resp < number) {
                            System.out.println("\nO número gerado é maior que o número digitado:");
                            ++erro;
                        } else {
                            System.out.println("\nParabéns você acertou!");
                            System.out.println("Sua pontuação: " + (1000 - erro * 50));
                            i = 21;
                            opc = 0;

                            System.out.println("\nDeseja cadastrar sua pontuação?\n1- Sim\n2- Não");
                            int escolha = entrada.nextInt();

                            if (escolha == 1) {
                                entrada.nextLine();

                                System.out.println("\nDigite um apelido para o cadastro:");
                                nickFac[lFac] = entrada.nextLine();
                                pontFac[lFac] = 1000 - erro * 50;

                                System.out.println("\nDemonstração da exibição:\nApelido: " + nickFac[lFac] + " Pontuação: " + pontFac[lFac]);

                                ++lFac;
                            }
                        }
                    }

                    //jogo na dificuldade média
                } else if (dif == 1) {
                    for (int i = 1; i <= 10; ++i) {
                        System.out.println("\nTentativa Nº" + i + " :");
                        System.out.println("Digite um número de 0 a 100:");
                        resp = entrada.nextInt();

                        if (erro == 10) {
                            System.out.println("\nNão foi desta vez! Tente novamente!");
                            opc = 0;
                        }

                        if (resp > number) {
                            System.out.println("\nO número gerado é menor que o número digitado:");
                            ++erro;
                        } else if (resp < number) {
                            System.out.println("\nO número gerado é maior que o número digitado:");
                            ++erro;
                        } else {
                            System.out.println("\nParabéns você acertou!");
                            System.out.println("Sua pontuação: " + (1000 - erro * 100));
                            i = 21;
                            opc = 0;

                            System.out.println("\nDeseja cadastrar sua pontuação?\n1- Sim\n2- Não");
                            int escolha = entrada.nextInt();

                            if (escolha == 1) {
                                entrada.nextLine();

                                System.out.println("\nDigite um apelido para o cadastro:");
                                nickMed[lMed] = entrada.nextLine();
                                pontMed[lMed] = 1000 - erro * 100;

                                System.out.println("\nPrévia:\nApelido: " + nickMed[lMed] + " Pontuação: " + pontMed[lMed]);

                                ++lMed;
                            }
                        }
                    }

                    //jogo na dificuldade difícil
                } else if (dif == 2) {
                    for (int i = 1; i <= 5; ++i) {
                        System.out.println("\nTentativa Nº" + i + " :");
                        System.out.println("Digite um número de 0 a 100:");
                        resp = entrada.nextInt();

                        if (erro == 5) {
                            System.out.println("\nNão foi desta vez! Tente novamente!");
                            opc = 0;
                        }

                        if (resp > number) {
                            System.out.println("\nO número gerado é menor que o número digitado:");
                            ++erro;
                        } else if (resp < number) {
                            System.out.println("\nO número gerado é maior que o número digitado:");
                            ++erro;
                        } else {
                            System.out.println("\nParabéns você acertou!");
                            System.out.println("Sua pontuação: " + (1000 - erro * 200));
                            i = 21;
                            opc = 0;

                            System.out.println("\nDeseja cadastrar sua pontuação?\n1- Sim\n2- Não");
                            int escolha = entrada.nextInt();

                            if (escolha == 1) {
                                entrada.nextLine();

                                System.out.println("\nDigite um apelido para o cadastro:");
                                nickDif[lDif] = entrada.nextLine();
                                pontDif[lDif] = 1000 - erro * 200;

                                System.out.println("\nPrévia:\nApelido: " + nickDif[lDif] + " Pontuação: " + pontDif[lDif]);

                                ++lDif;
                            }
                        }
                    }

                    //jogo na dificuldade personalizada
                } else {
                    for (int i = 1; i <= tentativas; ++i) {
                        System.out.println("\nTentativa Nº" + i + " :");
                        System.out.println("Digite um número de 0 a 100:");
                        resp = entrada.nextInt();

                        if (erro == tentativas) {
                            System.out.println("\nNão foi desta vez! Tente novamente!");
                            opc = 0;
                        }

                        if (resp > number) {
                            System.out.println("\nO número gerado é menor que o número digitado:");
                            erro++;
                        } else if (resp < number) {
                            System.out.println("\nO número gerado é maior que o número digitado:");
                            erro++;
                        } else {
                            System.out.println("\nParabéns você acertou!");
                            i = tentativas + 1;
                            opc = 0;
                        }
                    }
                }

            //menu das dificuldades
            } else if (opc == 2){
                do {
                    System.out.println("\n-- Menu Dificuldades --");
                    System.out.println("1- Fácil\n2- Média\n3- Difícil\n4- Personalizada -> Sem pontuação!\n5- Sair");
                    opcao = entrada.nextInt();

                    System.out.print("Dificuldade mudada para: ");

                    if (opcao == 1) {
                        System.out.println("Fácil");
                        dif = 0;
                        opc = 0;
                    } else if (opcao == 2) {
                        System.out.println("Média");
                        dif = 1;
                        opc = 0;
                    } else if (opcao == 3) {
                        System.out.println("Difícil");
                        dif = 2;
                        opc = 0;
                    } else if (opcao == 4) {
                        System.out.println("Personalizada");
                        dif = 3;
                        opc = 0;

                        do {
                            System.out.println("\nDigite a quantidade tentativas que irá utilizar:");
                            tentativas = entrada.nextInt();

                            if (tentativas < 1 || tentativas > 100) {
                                System.out.println("\nDigite uma quantidade entre 1 e 100!:");
                            }
                        } while (tentativas < 1 || tentativas > 100);
                    } else if (opcao == 5) {
                        System.out.println("Anterior");
                        opc = 0;
                    }
                } while (opcao < 1 || opcao > 5);

            //tutorial
            } else if (opc == 3) {
                System.out.println("""

                        --COMO JOGAR--

                        -> O jogador terá algumas tentativas de acertar um número aleatório gerado de 0 a 1000;
                        -> Cada tentativa que o jogador usar e errar, perderá alguns pontos;
                        -> A quantidade de tentativas muda de acordo com a dificuldade:
                                FÁCIL         -> 20 Tentativas;
                                MÉDIA         -> 10 Tentativas;
                                DIFÍCIL       ->  5 Tentativas;
                                PERSONALIZADA -> Devem ser determinadas.


                        --PONTUAÇÃO--

                        -> A pontuação máxima é de 300 pontos;
                        -> O valor do desconto dos pontos muda conforme a dificuldade:
                        -- Considere as fórmulas abaixo para sua respectiva dificuldade --
                                FÁCIL         -> PONTOS = 1000 - (ERROS*50);
                                MÉDIA         -> PONTOS = 1000 - (ERROS*100);
                                DIFÍCIL       -> PONTOS = 1000 - (ERROS*200);
                                PERSONALIZADA -> SEM PONTUAÇÃO.


                        --OBJETIVO--

                        -> Acertar o número gerado com a menor quantidade de tentativas;
                        -> Marcar a maior quantidade de pontos possível.""");
                opc = 0;

            //menu ranking
            } else if (opc == 4) {
                do {
                    System.out.println("\n-- Menu Ranking --");
                    System.out.println("1- Fácil\n2- Média\n3- Difícil\n4- Sair");
                    dificuldade = entrada.nextInt();

                    //exibição de pontuação da dificuldade fácil
                    if (dificuldade == 1) {
                        System.out.println("\n-- Ranking - Fácil --");

                        for (int i = 0; i <= 1000; i++) {
                            if (pontFac[i] > 0) {
                                System.out.println("Apelido: " + nickFac[i] + " Pontuação: " + pontFac[i]);
                            } else {
                                i = 1001;
                            }
                        }

                        opc = 0;

                    //exibição de pontuação da dificuldade média
                    } else if (dificuldade == 2) {
                        System.out.println("\n-- Ranking - Média --");

                        for (int i = 0; i <= 1000; i++) {
                            if (pontFac[i] > 0) {
                                System.out.println("Apelido: " + nickMed[i] + " Pontuação: " + pontMed[i]);
                            } else {
                                i = 1001;
                            }
                        }

                        opc = 0;

                    //exibição de pontuação da dificuldade difícil
                    } else if (dificuldade == 3) {
                        System.out.println("\n-- Ranking - Difícil --");

                        for (int i = 0; i <= 1000; i++) {
                            if (pontFac[i] > 0) {
                                System.out.println("Apelido: " + nickDif[i] + " Pontuação: " + pontDif[i]);
                            } else {
                                i = 1001;
                            }
                        }

                        opc = 0;
                    } else if (dificuldade == 4) {
                        opc = 0;
                    }
                } while (dificuldade < 1 || dificuldade > 4);

            //saída
            } else {
                System.out.println("\nAté breve!");
            }
        } while (opc < 1 || opc > 5);
    }
}