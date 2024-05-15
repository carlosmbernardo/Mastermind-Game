#include <iostream>
#include <ctime>
#include <string>
using namespace std;

    int main() {
        int opcao;    
        int code_1, code_2, code_3, code_4;
        int tent_1, tent_2, tent_3, tent_4;
        int PosicaoCorreta, PosicaoIncorreta;
        int tentativasRestantes;

        do {
            cout << "Menu do Jogador, Escolha uma opção:\n";
            cout << "1. Jogar\n";
            cout << "2. Sobre\n";
            cout << "3. Sair\n";
            cin >> opcao;

            switch (opcao) {
                case 1: { //CASO DE SELECIONADO "JOGAR" INICIA O JOGO, GERANDO OS CODIGOS E SOLICITANDO AO USUARIO INICIAR AS TENTATIVAS.
                    srand(time(NULL));
                    tentativasRestantes = 10;

                    // Gerar os números secretos individualmente.
                    code_1 = rand() % 6 + 1;
                    do {
                        code_2 = rand() % 6 + 1;
                    } while (code_2 == code_1);
                    do {
                        code_3 = rand() % 6 + 1;
                    } while (code_3 == code_1 || code_3 == code_2);
                    do {
                        code_4 = rand() % 6 + 1;
                    } while (code_4 == code_1 || code_4 == code_2 || code_4 == code_3);

                    cout << "Bem-vindo ao Mastermind!\n";
                    cout << "Você tem 10 tentativas para adivinhar o código secreto.\n";

                    while (tentativasRestantes > 0) {
                        cout << "Digite sua tentativa (4 números de 1 a 6): ";
                        cin >> tent_1 >> tent_2 >> tent_3 >> tent_4;

                        PosicaoCorreta = 0;
                        PosicaoIncorreta = 0;

                        // Verificar cada número individualmente aumentando em 1 sempre que o numero estiver correto na posição incorreta ou estiver na posição correta.
                        if (tent_1 == code_1)PosicaoCorreta++;
                        else if (tent_1 == code_2 || tent_1 == code_3 || tent_1 == code_4) PosicaoIncorreta++;

                        if (tent_2 == code_2) PosicaoCorreta++;
                        else if (tent_2 == code_1 || tent_2 == code_3 || tent_2 == code_4) PosicaoIncorreta++;

                        if (tent_3 == code_3) PosicaoCorreta++;
                        else if (tent_3 == code_1 || tent_3 == code_2 || tent_3 == code_4) PosicaoIncorreta++;

                        if (tent_4 == code_4) PosicaoCorreta++;
                        else if (tent_4 == code_1 || tent_4 == code_2 || tent_4 == code_3)
                            PosicaoIncorreta++;

                        cout << "Números corretos e na posição correta: " << PosicaoCorreta << endl;
                        cout << "Números corretos, mas na posição incorreta: " << PosicaoIncorreta << endl;

                        if (PosicaoCorreta == 4) {
                            cout << "Parabéns! Você acertou o código secreto!\n";
                            break;
                        } else {
                            tentativasRestantes--;
                            cout << "Tentativas restantes: " << tentativasRestantes << endl;
                        }
                    }

                    if (tentativasRestantes == 0) { //EM CASO DAS TENTATIVAS ZERAREM, O JOGO EXIBIRÁ  UMA MENSAGEM INFORMANDO O FIM DE JOGO E LEVARÁ O JOGADOR AO MENU.
                        cout << "Você excedeu o número máximo de tentativas. O código secreto era: ";
                        cout << code_1 << " " << code_2 << " " << code_3 << " " << code_4 << endl;
                    }

                    break;
                }
                case 2: { //MOSTRA OS CRIADORES/DATA/ORIENTADOR
                    cout << "Equipe de Desenvolvimento:\n";
                    cout << "- Gustavo Molde\n";
                    cout << "- Kaynan Matheus Wisenteiner\n";
                    cout << "- Welby Roberto Pereira junior\n";
                    cout << "- Carlos Miguel Bernardo\n";
                    cout << "- 5/mai - 12/mai\n";
                    cout << " Maio/2024\n";
                    cout << "Professor/Disciplina: Rafael Ballotin/Algoritmos e Programação\n";
                    break;
                }
                case 3: {
                    cout << "Obrigado por jogar! Até mais.\n";
                    break;
                }
                default: {
                    cout << "Opção inválida. Por favor, tente novamente.\n";
                    break;
                }
            }
        } while (opcao != 3);

        return 0;
    }