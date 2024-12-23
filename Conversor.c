#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void convesao_comprimento();
void convesao_massa();
void convesao_volume();
// void convesao_temperatura();
// void convesao_velocidade();
// void convesao_energia();
void convesao_area();
void convesao_tempo();
void convesao_ArmDados();

int main()
{
  setlocale(LC_ALL, "Portuguese");
  int loop = 1;

  while (loop != 0)
  {
    printf("\nUnidade de Conversão\n");
    printf("1. Comprimento\n");
    printf("2. Massa\n");
    printf("3. Volume\n");
    printf("4. Temperatura\n");
    printf("5. Velocidade\n");
    printf("6. Potência\n");
    printf("7. Área\n");
    printf("8. Tempo\n");
    printf("9. Dados\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &loop);

    switch (loop)
    {
       case 1:
        convesao_comprimento();
       break;
       case 2:
         convesao_massa();
         break;
      case 3:
        convesao_volume();
        break;
      // case 4:
      //   convesao_temperatura();
      //   break;
      // case 5:
      //   convesao_velocidade();
      //   break;
      // case 6:
      //   convesao_energia();
      //   break;
      // case 7:
        convesao_area();
        break;
      case 8:
        convesao_tempo();
        break;
      case 9:
         convesao_ArmDados();
         break;
    case 0:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
    system("Pause");
    system("cls");
  }
  return 0;
}

void convesao_ArmDados() {
    double valor, resultado;
    int origem, destino;

    // Fatores de conversão para bytes
    double fatores_para_bytes[] = {
        0.125,  // bits para bytes
        1.0,    // bytes para bytes
        1024,   // kilobytes para bytes
        1048576, // megabytes para bytes
        1073741824, // gigabytes para bytes
        1099511627776.0 // terabytes para bytes
    };

    char unidades[][10] = {
        "bits", 
        "bytes", 
        "kilobytes", 
        "megabytes", 
        "gigabytes", 
        "terabytes"
    };

    int total_unidades = sizeof(fatores_para_bytes) / sizeof(fatores_para_bytes[0]);

    // Solicita a unidade de origem
    printf("\nUnidades disponíveis para conversão:\n");
    for (int i = 0; i < total_unidades; i++) {
        printf("%d. %s\n", i + 1, unidades[i]);
    }
    printf("Escolha o número correspondente à unidade de origem: ");
    scanf("%d", &origem);

    // Verifica se a unidade de origem é válida
    if (origem < 1 || origem > total_unidades) {
        printf("Opção inválida. Tente novamente.\n");
        return;
    }

    // Solicita a unidade de destino
    printf("\nAgora escolha o número correspondente à unidade de destino: ");
    scanf("%d", &destino);

    // Verifica se a unidade de destino é válida
    if (destino < 1 || destino > total_unidades) {
        printf("Opção inválida. Tente novamente.\n");
        return;
    }

    // Solicita o valor a ser convertido
    printf("\nDigite o valor a ser convertido (%s): ", unidades[origem - 1]);
    scanf("%lf", &valor);

    // Converte o valor para bytes e depois para a unidade de destino
    double valor_em_bytes = valor * fatores_para_bytes[origem - 1];
    resultado = valor_em_bytes / fatores_para_bytes[destino - 1];

    // Exibe o resultado da conversão
    printf("\n%.4f %s é igual a %.4f %s\n", valor, unidades[origem - 1], resultado, unidades[destino - 1]);
}

void convesao_comprimento() {
    // Declaração de variáveis
    double valor, resultado;
    int origem, destino;

    // Fatores de conversão para metros
    double fatores_para_metros[] = {1000,1.0, 0.01, 0.001, 0.0254, 1609.34, 0.3048, 0.9144};
    char unidades[][15] = {"km","metros", "centimetros","milimetros", "polegadas", "milhas", "pes", "jardas"};
    int total_unidades = sizeof(fatores_para_metros) / sizeof(fatores_para_metros[0]);

    // Exibe as unidades disponíveis
    printf("\nUnidades disponíveis:\n");
    for (int i = 0; i < total_unidades; i++) {
        printf("%d. %s\n", i + 1, unidades[i]);
    }

    // Solicita o valor e as unidades de origem e destino
    printf("Escolha o número da unidade de origem: ");
    scanf("%d", &origem);

    printf("Escolha o número da unidade de destino: ");
    scanf("%d", &destino);

        printf("\nDigite o valor a ser convertido: ");
    scanf("%lf", &valor);

    // Verifica se as opções de origem e destino são válidas
    if (origem < 1 || origem > total_unidades || destino < 1 || destino > total_unidades) {
        printf("Opção inválida. Tente novamente.\n");
        return;
    }

    // Converte o valor para metros e depois para a unidade de destino
    double valor_em_metros = valor * fatores_para_metros[origem - 1];
    resultado = valor_em_metros / fatores_para_metros[destino - 1];

    // Exibe o resultado da conversão
    printf("\n%.4f %s é igual a %.4f %s\n", valor, unidades[origem - 1], resultado, unidades[destino - 1]);
}
//-------------------> 8. Unidades de tempo (segundos, minutos, horas).
void convesao_tempo()
{

  int time;

  printf("Qual a unidade de tempo que você possui para converter? \n ");
  printf("1 - Horas \n 2 - Minutos \n 3 - Segundos \n");
  scanf("%d", &time);

  if (time == 1)
  {
    printf("Hora: ");
    scanf("%i", &time);
    printf("%i Minutos \n", time * 60);
    printf("%i Segundos \n", (time * 60) * 60);
  }
  else if (time == 2)
  {
    printf("Minutos: ");
    scanf("%i", &time);
    printf("%i Horas \n", time / 60);
    printf("%i Segundos \n", time * 60);
  }
  else if (time == 3)
  {
    printf("Segundos: ");
    scanf("%i", &time);
    printf("%i Horas \n", (time / 60) / 60);
    printf("%i Minutos \n", time / 60);
  }
  else
  {
    printf("Valor incorreto, retorne ao menu para selecionar as opções! \n");
  }
}

void convesao_massa() {
    double valor, resultado;
    int origem, destino;

    // Fatores de conversão para grama
    double fatores_para_gramas[] = {
        1000000,  // Tonelada para grama
        1000,    // KG para grama
        1.0,   // Grama para grama
    };

    char unidades[][15] = {
        "toneladas",
        "quilogramas",
        "gramas"
    };

    int total_unidades = sizeof(fatores_para_gramas) / sizeof(fatores_para_gramas[0]);

    // Solicita a unidade de origem
    printf("\nUnidades disponíveis para conversão:\n");
    for (int i = 0; i < total_unidades; i++) {
        printf("%d. %s\n", i + 1, unidades[i]);
    }
    printf("Escolha o número correspondente à unidade de origem: ");
    scanf("%d", &origem);

    // Verifica se a unidade de origem é válida
    if (origem < 1 || origem > total_unidades) {
        printf("Opção inválida. Tente novamente.\n");
        return;
    }

    // Solicita a unidade de destino
    printf("\nAgora escolha o número correspondente à unidade de destino: ");
    scanf("%d", &destino);

    // Verifica se a unidade de destino é válida
    if (destino < 1 || destino > total_unidades) {
        printf("Opção inválida. Tente novamente.\n");
        return;
    }

    // Solicita o valor a ser convertido
    printf("\nDigite o valor a ser convertido (%s): ", unidades[origem - 1]);
    scanf("%lf", &valor);

    // Converte o valor para gramas e depois para a unidade de destino
    double valor_em_gramas = valor * fatores_para_gramas[origem - 1];
    resultado = valor_em_gramas / fatores_para_gramas[destino - 1];

    // Exibe o resultado da conversão
    printf("\n%.4f %s é igual a %.4f %s\n", valor, unidades[origem - 1], resultado, unidades[destino - 1]);
}

void convesao_volume() {
  int unidadeVolume;
  float valor;

  printf("Qual a unidade de volume que voce possui para converter? \n");
  printf("1 - Litros \n2 - Mililitros \n3 - Metros Cubicos \n");
  scanf("%d", &unidadeVolume);

  if (unidadeVolume == 1) { // Litros
    printf("Litros: ");
    scanf("%f", &valor);
    printf("%.6f Mililitros\n", valor * 1000);
    printf("%.6f Metros Cubicos\n", valor / 1000);
  } else if (unidadeVolume == 2) { // Mililitros
    printf("Mililitros: ");
    scanf("%f", &valor);
    printf("%.6f Litros\n", valor / 1000);
    printf("%.6f Metros Cubicos\n", valor / 1000000);
  } else if (unidadeVolume == 3) { // Metros cúbicos
    printf("Metros Cubicos: ");
    scanf("%f", &valor);
    printf("%.6f Litros\n", valor * 1000);
    printf("%.6f Mililitros\n", valor * 1000000);
  } else {
    printf("Valor incorreto, retorne ao menu para selecionar as opções! \n");
  }
}

void convesao_area() {
    double valor, resultado;
    int opcao;

    // Pergunta ao usuário qual a conversão que ele deseja fazer
    printf("Escolha uma opção de conversão de área:\n");
    printf("1. Metros quadrados para Centímetros quadrados\n");
    printf("2. Centímetros quadrados para Metros quadrados\n");
    printf("Digite sua opção (1 ou 2): ");
    scanf("%d", &opcao);

    // Verifica a opção escolhida e realiza a conversão
    if (opcao == 1) {
        // Metros quadrados para centímetros quadrados
        printf("Digite o valor em metros quadrados: ");
        scanf("%lf", &valor);
        resultado = valor * 10000;  // 1 m² = 10.000 cm²
        printf("%.2f metros quadrados é igual a %.2f centímetros quadrados.\n", valor, resultado);
    } 
    else if (opcao == 2) {
        // Centímetros quadrados para metros quadrados
        printf("Digite o valor em centímetros quadrados: ");
        scanf("%lf", &valor);
        resultado = valor * 0.0001;  // 1 cm² = 0.0001 m²
        printf("%.2f centímetros quadrados é igual a %.6f metros quadrados.\n", valor, resultado);
    } 
    else {
        printf("Opção inválida! Tente novamente.\n");
    }
}

