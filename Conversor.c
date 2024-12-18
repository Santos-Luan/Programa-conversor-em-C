#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// void convesao_comprimento();
// void convesao_massa();
// void convesao_volume();
// void convesao_temperatura();
// void convesao_velocidade();
// void convesao_energia();
// void convesao_area();
// void convesao_tempo();
// void convesao_ArmDados();

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
      // case 1:
      //   convesao_comprimento();
      //   break;
      // case 2:
      //   convesao_massa();
      //   break;
      // case 3:
      //   convesao_volume();
      //   break;
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
      //   convesao_area();
      //   break;
      // case 8:
      //   convesao_tempo();
      //   break;
      // case 9:
      //   convesao_ArmDados();
      //   break;
    case 0:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  }
  return 0;
}
