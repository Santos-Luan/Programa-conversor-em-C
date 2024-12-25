#include <stdio.h>

void converterVelocidade(float valor, int opcao) {
    float convertido;
    
    switch(opcao) {
        case 1: // km/h para m/s
            convertido = valor / 3.6;
            printf("%.2f km/h é igual a %.2f m/s\n", valor, convertido);
            break;
        case 2: // km/h para mph
            convertido = valor / 1.609;
            printf("%.2f km/h é igual a %.2f mph\n", valor, convertido);
            break;
        case 3: // m/s para km/h
            convertido = valor * 3.6;
            printf("%.2f m/s é igual a %.2f km/h\n", valor, convertido);
            break;
        case 4: // m/s para mph
            convertido = valor * 2.237;
            printf("%.2f m/s é igual a %.2f mph\n", valor, convertido);
            break;
        case 5: // mph para km/h
            convertido = valor * 1.609;
            printf("%.2f mph é igual a %.2f km/h\n", valor, convertido);
            break;
        case 6: // mph para m/s
            convertido = valor / 2.237;
            printf("%.2f mph é igual a %.2f m/s\n", valor, convertido);
            break;
        default:
            printf("Opção inválida\n");
    }
}

int main() {
    float valor;
    int opcao;
    
    printf("Digite o valor da velocidade: ");
    scanf("%f", &valor);
    
    printf("Escolha a conversão desejada:\n");
    printf("1. km/h para m/s\n");
    printf("2. km/h para mph\n");
    printf("3. m/s para km/h\n");
    printf("4. m/s para mph\n");
    printf("5. mph para km/h\n");
    printf("6. mph para m/s\n");
    
    printf("Digite a opção: ");
    scanf("%d", &opcao);
    
    converterVelocidade(valor, opcao);
    
    return 0;
}

