#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void convesao_comprimento();
void convesao_massa();
void convesao_volume();
void convesao_temperatura();
void convesao_velocidade();
void convesao_energia();
void convesao_area();
void convesao_tempo();
void convesao_ArmDados();
void conversao_pressao();

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
    printf("10. Pressão\n");
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
    case 4:
      convesao_temperatura();
      break;
    case 5:
      convesao_velocidade();
      break;
    case 6:
      convesao_energia();
      break;
    case 7:
      convesao_area();
      break;
    case 8:
      convesao_tempo();
      break;
    case 9:
      convesao_ArmDados();
      break;
    case 10:
      conversao_pressao();
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

void convesao_ArmDados()
{
  double valor, resultado;
  int origem, destino;

  // Fatores de conversão para bytes
  double fatores_para_bytes[] = {
      0.125,          // bits para bytes
      1.0,            // bytes para bytes
      1024,           // kilobytes para bytes
      1048576,        // megabytes para bytes
      1073741824,     // gigabytes para bytes
      1099511627776.0 // terabytes para bytes
  };

  char unidades[][10] = {
      "bits",
      "bytes",
      "kilobytes",
      "megabytes",
      "gigabytes",
      "terabytes"};

  int total_unidades = sizeof(fatores_para_bytes) / sizeof(fatores_para_bytes[0]);

  // Solicita a unidade de origem
  printf("\nUnidades disponíveis para conversão:\n");
  for (int i = 0; i < total_unidades; i++)
  {
    printf("%d. %s\n", i + 1, unidades[i]);
  }
  printf("Escolha o número correspondente à unidade de origem: ");
  scanf("%d", &origem);

  // Verifica se a unidade de origem é válida
  if (origem < 1 || origem > total_unidades)
  {
    printf("Opção inválida. Tente novamente.\n");
    return;
  }

  // Solicita a unidade de destino
  printf("\nAgora escolha o número correspondente à unidade de destino: ");
  scanf("%d", &destino);

  // Verifica se a unidade de destino é válida
  if (destino < 1 || destino > total_unidades)
  {
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

void convesao_comprimento()
{
  // Declaração de variáveis
  double valor, resultado;
  int origem, destino;

  // Fatores de conversão para metros
  double fatores_para_metros[] = {1000, 1.0, 0.01, 0.001, 0.0254, 1609.34, 0.3048, 0.9144};
  char unidades[][15] = {"km", "metros", "centimetros", "milimetros", "polegadas", "milhas", "pes", "jardas"};
  int total_unidades = sizeof(fatores_para_metros) / sizeof(fatores_para_metros[0]);

  // Exibe as unidades disponíveis
  printf("\nUnidades disponíveis:\n");
  for (int i = 0; i < total_unidades; i++)
  {
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
  if (origem < 1 || origem > total_unidades || destino < 1 || destino > total_unidades)
  {
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

void convesao_massa()
{
  double valor, resultado;
  int origem, destino;

  // Fatores de conversão para grama
  double fatores_para_gramas[] = {
      1000000, // Tonelada para grama
      1000,    // KG para grama
      1.0,     // Grama para grama
  };

  char unidades[][15] = {
      "toneladas",
      "quilogramas",
      "gramas"};

  int total_unidades = sizeof(fatores_para_gramas) / sizeof(fatores_para_gramas[0]);

  // Solicita a unidade de origem
  printf("\nUnidades disponíveis para conversão:\n");
  for (int i = 0; i < total_unidades; i++)
  {
    printf("%d. %s\n", i + 1, unidades[i]);
  }
  printf("Escolha o número correspondente à unidade de origem: ");
  scanf("%d", &origem);

  // Verifica se a unidade de origem é válida
  if (origem < 1 || origem > total_unidades)
  {
    printf("Opção inválida. Tente novamente.\n");
    return;
  }

  // Solicita a unidade de destino
  printf("\nAgora escolha o número correspondente à unidade de destino: ");
  scanf("%d", &destino);

  // Verifica se a unidade de destino é válida
  if (destino < 1 || destino > total_unidades)
  {
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

void convesao_velocidade() {
    float convertido;
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

void convesao_volume()
{
  int unidadeVolume;
  float valor;

  printf("Qual a unidade de volume que voce possui para converter? \n");
  printf("1 - Litros \n2 - Mililitros \n3 - Metros Cubicos \n");
  scanf("%d", &unidadeVolume);

  if (unidadeVolume == 1)
  { // Litros
    printf("Litros: ");
    scanf("%f", &valor);
    printf("%.6f Mililitros\n", valor * 1000);
    printf("%.6f Metros Cubicos\n", valor / 1000);
  }
  else if (unidadeVolume == 2)
  { // Mililitros
    printf("Mililitros: ");
    scanf("%f", &valor);
    printf("%.6f Litros\n", valor / 1000);
    printf("%.6f Metros Cubicos\n", valor / 1000000);
  }
  else if (unidadeVolume == 3)
  { // Metros cúbicos
    printf("Metros Cubicos: ");
    scanf("%f", &valor);
    printf("%.6f Litros\n", valor * 1000);
    printf("%.6f Mililitros\n", valor * 1000000);
  }
  else
  {
    printf("Valor incorreto, retorne ao menu para selecionar as opções! \n");
  }
}

void convesao_area()
{
  double valor, resultado;
  int opcao;

  // Pergunta ao usuário qual a conversão que ele deseja fazer
  printf("Escolha uma opção de conversão de área:\n");
  printf("1. Metros quadrados para Centímetros quadrados\n");
  printf("2. Centímetros quadrados para Metros quadrados\n");
  printf("Digite sua opção (1 ou 2): ");
  scanf("%d", &opcao);

  // Verifica a opção escolhida e realiza a conversão
  if (opcao == 1)
  {
    // Metros quadrados para centímetros quadrados
    printf("Digite o valor em metros quadrados: ");
    scanf("%lf", &valor);
    resultado = valor * 10000; // 1 m² = 10.000 cm²
    printf("%.2f metros quadrados é igual a %.2f centímetros quadrados.\n", valor, resultado);
  }
  else if (opcao == 2)
  {
    // Centímetros quadrados para metros quadrados
    printf("Digite o valor em centímetros quadrados: ");
    scanf("%lf", &valor);
    resultado = valor * 0.0001; // 1 cm² = 0.0001 m²
    printf("%.2f centímetros quadrados é igual a %.6f metros quadrados.\n", valor, resultado);
  }
  else
  {
    printf("Opção inválida! Tente novamente.\n");
  }
}

void convesao_temperatura()
{
  float celsius, kelvin, fahrenheit;
  int opcao = 0;

  // Usuario escolhe o tipo de temperatura a ser convertida
  printf("\n");
  printf("Escolha o tipo de temperatura a ser modificada: \n");
  printf("1- Celsius \n");
  printf("2- Kelvin \n");
  printf("3- Fahrenheit \n");

  // Recebe o tipo de temperatura a ser alterada
  printf("Digite uma opcao valida: ");
  scanf("%d", &opcao);

  // Entra em um switch que depende da opcao inserida
  switch (opcao)
  {
  case 1:

    // Recebe a temperatura em Celsius
    printf("Digite a temperatura a ser convertida em Celsius: ");
    scanf("%f", &celsius);
    printf("\n");

    fahrenheit = (celsius * 1.8) + 32;
    kelvin = celsius + 273.15;

    printf("Kelvin: %2.2f \n", kelvin);
    printf("Fahrenheit: %2.2f \n", fahrenheit);
    break;

  case 2:

    // Recebe a temperatura em Kelvin
    printf("Digite a temperatura a ser convertida em Kelvin: ");
    scanf("%f", &kelvin);
    printf("\n");

    celsius = kelvin - 273.15;
    fahrenheit = ((kelvin - 273.15) * 1.8) + 32;

    printf("Celsius: %2.2f \n", celsius);
    printf("Fahrenheit: %2.2f \n", fahrenheit);
    break;

  case 3:

    // Recebe a temperatura em Fahrenheit
    printf("Digite a temperatura a ser convertida em Fahrenheit: ");
    scanf("%f", &fahrenheit);
    printf("\n");

    celsius = (fahrenheit - 32) / 1.8;
    kelvin = ((fahrenheit - 32) / 1.8) - 273.15;

    printf("Kelvin: %2.2f \n", kelvin);
    printf("Celsius: %2.2f \n", celsius);
    break;

  default:

    printf("Opcao invalida. \n");

    break;
  }
}

// Função para realizar a conversão de potência
void convesao_energia()
{
  double watts, quilowatts, cavalos_vapor;
  int opcao = 0;

  // Menu para o usuário escolher a unidade de entrada
  printf("\n");
  printf("Escolha a unidade de potência a ser convertida:\n");
  printf("1- Watts\n");
  printf("2- Quilowatts\n");
  printf("3- Cavalos-Vapor\n");

  // Recebe a escolha do usuário
  printf("Digite uma opção válida: ");
  scanf("%d", &opcao);

  // Processa a conversão com base na escolha
  switch (opcao)
  {
  case 1:
    // Recebe o valor em Watts
    printf("Digite o valor em Watts: ");
    scanf("%lf", &watts);

    // Converte para Quilowatts e Cavalos-Vapor
    quilowatts = watts / 1000.0;
    cavalos_vapor = watts / 735.5;

    // Exibe os resultados
    printf("Quilowatts: %.2lf\n", quilowatts);
    printf("Cavalos-Vapor: %.2lf\n", cavalos_vapor);
    break;

  case 2:
    // Recebe o valor em Quilowatts
    printf("Digite o valor em Quilowatts: ");
    scanf("%lf", &quilowatts);

    // Converte para Watts e Cavalos-Vapor
    watts = quilowatts * 1000.0;
    cavalos_vapor = watts / 735.5;

    // Exibe os resultados
    printf("Watts: %.2lf\n", watts);
    printf("Cavalos-Vapor: %.2lf\n", cavalos_vapor);
    break;

  case 3:
    // Recebe o valor em Cavalos-Vapor
    printf("Digite o valor em Cavalos-Vapor: ");
    scanf("%lf", &cavalos_vapor);

    // Converte para Watts e Quilowatts
    watts = cavalos_vapor * 735.5;
    quilowatts = watts / 1000.0;

    // Exibe os resultados
    printf("Watts: %.2lf\n", watts);
    printf("Quilowatts: %.2lf\n", quilowatts);
    break;

  default:
    // Mensagem para opção inválida
    printf("Opção inválida.\n");
    break;
  }
}

// Função para ler dados, converter pressão e exibir o resultado
void conversao_pressao() {
    double valor, resultado;
    int unidadeOrigem, unidadeDestino;

    printf("Digite o valor da pressão: ");
    scanf("%lf", &valor);

    printf("Escolha a unidade de origem:\n");
    printf("1 - ATM\n2 - bar\n3 - Pa\n4 - psi\n");
    scanf("%d", &unidadeOrigem);

    printf("Escolha a unidade de destino:\n");
    printf("1 - ATM\n2 - bar\n3 - Pa\n4 - psi\n");
    scanf("%d", &unidadeDestino);

    // Converter a unidade de origem para ATM
    double valorATM = 0.0;
    if (unidadeOrigem == 1) { // ATM
        valorATM = valor;
    } else if (unidadeOrigem == 2) { // bar
        valorATM = valor / 1.01325;
    } else if (unidadeOrigem == 3) { // Pa
        valorATM = valor / 101325.0;
    } else if (unidadeOrigem == 4) { // psi
        valorATM = valor / 14.6959;
    } else {
        printf("Unidade de origem inválida!\n");
        return;
    }

    // Converter de ATM para a unidade de destino
    if (unidadeDestino == 1) { // ATM
        resultado = valorATM;
    } else if (unidadeDestino == 2) { // bar
        resultado = valorATM * 1.01325;
    } else if (unidadeDestino == 3) { // Pa
        resultado = valorATM * 101325.0;
    } else if (unidadeDestino == 4) { // psi
        resultado = valorATM * 14.6959;
    } else {
        printf("Unidade de destino inválida!\n");
        return;
    }

    // Exibir o resultado
    printf("Resultado: %.2lf\n", resultado);
}
