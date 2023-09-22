#include <stdio.h>
#include <string.h>
#include <conio.h>

struct score
{
    unsigned Points : 3;
    unsigned Games : 3;
    unsigned Sets : 3;
    unsigned TB : 5;
    unsigned totalP : 10;
};

struct player
{
    char name[32];
    struct score sc;
};

void initializeScore(struct score *sc)
{
    sc->Points = 0;
    sc->Games = 0;
    sc->Sets = 0;
    sc->TB = 0;
    sc->totalP = 0;
}

void printScore(struct score sc)
{
    printf("Points: %d, Games: %d, Sets: %d, TB: %d, Total Points: %d\n", sc.Points, sc.Games, sc.Sets, sc.TB, sc.totalP);
}

void printMatchResult(struct player player1, struct player player2)
{
    printf("\nPlacar Total:\n");
    printf("%s: %d sets\n", player1.name, player1.sc.Sets);
    printf("%s: %d sets\n", player2.name, player2.sc.Sets);
}

int main()
{
    struct player player1, player2;
    int setsToWin;
    char player1PointKey, player2PointKey, undoKey;
    
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", player1.name);
    
    printf("Digite o nome do Jogador 2: ");
    scanf("%s", player2.name);
    
    printf("Digite o número de sets para vencer (3 ou 5): ");
    scanf("%d", &setsToWin);

    printf("Digite a tecla para marcar ponto para %s: ", player1.name);
    player1PointKey = getch();
    printf("%c\n", player1PointKey);
    
    printf("Digite a tecla para marcar ponto para %s: ", player2.name);
    player2PointKey = getch();
    printf("%c\n", player2PointKey);

    printf("Digite a tecla para desfazer a marcação (undo): ");
    undoKey = getch();
    printf("%c\n", undoKey);

    initializeScore(&player1.sc);
    initializeScore(&player2.sc);

    while (player1.sc.Sets < setsToWin && player2.sc.Sets < setsToWin)
    {
        // Simulação de um set (para demonstração)
        // Vamos supor que o Jogador 1 ganha o set
        player1.sc.Sets++;
        
        // Reinicializa a pontuação para o próximo set
        initializeScore(&player1.sc);
        initializeScore(&player2.sc);
        
        // Imprime o placar do set
        printf("\nPlacar do Set:\n");
        printScore(player1.sc);
        printScore(player2.sc);
    }

    printMatchResult(player1, player2);

    if (player1.sc.Sets > player2.sc.Sets)
    {
        printf("\n%s venceu a partida!\n", player1.name);
    }
    else
    {
        printf("\n%s venceu a partida!\n", player2.name);
    }

    return 0;
}
