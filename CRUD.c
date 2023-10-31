#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define MAX_NOME 40

typedef struct endereco
{
    char logradouro[12];
    int numero;
    int complemento;
    char bairro[40];
    char cidadeNome[60];
    char UF[2];
    
} endereco;

typedef struct registro
{
    char nome[MAX_NOME + 1];
    char dataNascimento[11];
    char telefone[12];
    char RG[12];
    char CPF[12];
    endereco endereco;

} registro;

void padronizar(char *documento)
{
    for (int i = 0; i < strlen(documento);i++ )
    {
        if ((isspace(documento[i]) == 0x20))
        {
            if(documento[i+1] != 0) documento[i] = documento[i+1];  
            
            else return;
            
        }
    }


    return;
}

void registroUsuario(registro *usuarios, int i)
{
    system(CLEAR);

    printf("\nPor favor digite o nome: ");
    scanf(" %40[^\n]s", usuarios[i].nome);

    printf("\nPor favor digite a data de nascimento (AAAA/MM/DD): ");
    scanf(" %[^\n]s", usuarios[i].dataNascimento);
    padronizar(usuarios[i].dataNascimento);

    printf("\nDigite o numero do seu telefone ((99) 99999-9999): ");
    scanf(" %[^\n]s", usuarios[i].telefone);
    padronizar(usuarios[i].telefone);

    printf("\nDigite seu RG: ");
    scanf(" %[^\n]s", usuarios[i].RG);
    padronizar(usuarios[i].RG);

    printf("\nDigite seu CPF: ");
    scanf(" %[^\n]s", usuarios[i].CPF);
    padronizar(usuarios[i].RG);

    printf("\n%s\n%s\n%s\n", usuarios[i].nome, usuarios[i].dataNascimento, usuarios[i].telefone);

}

void registroEndereco (registro *usuarios, int i)
{
    
    printf("Digite seu logradouro");
    scanf(" %[^/n]s", usuarios[i].endereco.logradouro);


    return;
}

int main()
{
    registro usuarios[100];
    int usuariosCadastrados = 0;

    printf("Olá, boas vindas ao registrador de usuarios\nEscolha a opção deseja\n");

    while (true)
    {
        printf("    [1] - Registrar usuario\n    [2] - Gerar relatorio\n    [3] - Deletar um usuario\n    [0] - Sair\n");
        int opcao;
        scanf("%i", &opcao);
        
        switch (opcao)
        {
        case 1:
            usuariosCadastrados++;
            registroUsuario(usuarios, usuariosCadastrados);
            break;
        case 2:
            // TODO relatorio
            break;
        case 3:
            // TODO deletar
            break;
        case 0:
            return 0;
            break;
        default:
            printf("\nEscolha invalida...");
            Sleep(2000);
            system(CLEAR);
            break;
        }
    }
}