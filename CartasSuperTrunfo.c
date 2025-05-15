#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Dados das cartas (poderiam ser lidos como no desafio anterior)
    char estado1 = 'A';
    char codigo1[] = "A01";
    char cidade1[] = "São Paulo";
    int populacao1 = 12325000;
    float area1 = 1521.11;
    float pib1 = 699.28;
    int pontos_turisticos1 = 50;
    float densidade1 = populacao1 / area1;
    
    char estado2 = 'B';
    char codigo2[] = "B02";
    char cidade2[] = "Rio de Janeiro";
    int populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50;
    int pontos_turisticos2 = 30;
    float densidade2 = populacao2 / area2;
    
    int opcao;
    int vencedor; // 1 para carta 1, 2 para carta 2, 0 para empate
    
    do {
        // Exibe o menu de opções
        printf("\n=== SUPER TRUNFO DE PAÍSES ===\n");
        printf("Cartas disponíveis:\n");
        printf("1. %s (%s)\n", cidade1, codigo1);
        printf("2. %s (%s)\n", cidade2, codigo2);
        printf("\nEscolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        // Limpa o buffer do teclado
        while(getchar() != '\n');
        
        switch(opcao) {
            case 0:
                printf("Saindo do jogo...\n");
                break;
                
            case 1: // População
                printf("\nComparando POPULAÇÃO:\n");
                printf("%s: %d habitantes\n", cidade1, populacao1);
                printf("%s: %d habitantes\n", cidade2, populacao2);
                
                if(populacao1 > populacao2) {
                    vencedor = 1;
                } else if(populacao2 > populacao1) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }
                break;
                
            case 2: // Área
                printf("\nComparando ÁREA:\n");
                printf("%s: %.2f km²\n", cidade1, area1);
                printf("%s: %.2f km²\n", cidade2, area2);
                
                if(area1 > area2) {
                    vencedor = 1;
                } else if(area2 > area1) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }
                break;
                
            case 3: // PIB
                printf("\nComparando PIB:\n");
                printf("%s: %.2f bilhões de reais\n", cidade1, pib1);
                printf("%s: %.2f bilhões de reais\n", cidade2, pib2);
                
                if(pib1 > pib2) {
                    vencedor = 1;
                } else if(pib2 > pib1) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }
                break;
                
            case 4: // Pontos Turísticos
                printf("\nComparando PONTOS TURÍSTICOS:\n");
                printf("%s: %d pontos\n", cidade1, pontos_turisticos1);
                printf("%s: %d pontos\n", cidade2, pontos_turisticos2);
                
                if(pontos_turisticos1 > pontos_turisticos2) {
                    vencedor = 1;
                } else if(pontos_turisticos2 > pontos_turisticos1) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }
                break;
                
            case 5: // Densidade Demográfica
                printf("\nComparando DENSIDADE DEMOGRÁFICA:\n");
                printf("%s: %.2f hab/km²\n", cidade1, densidade1);
                printf("%s: %.2f hab/km²\n", cidade2, densidade2);
                
                // Regra invertida para densidade (menor valor vence)
                if(densidade1 < densidade2) {
                    vencedor = 1;
                } else if(densidade2 < densidade1) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
                continue; // Volta para o início do loop
        }
        
        // Exibe o resultado da comparação (exceto para opção 0)
        if(opcao >= 1 && opcao <= 5) {
            printf("\nRESULTADO: ");
            if(vencedor == 1) {
                printf("%s vence!\n", cidade1);
            } else if(vencedor == 2) {
                printf("%s vence!\n", cidade2);
            } else {
                printf("Empate!\n");
            }
        }
        
    } while(opcao != 0);
    
    return 0;
}
