#include <stdio.h>
#include <string.h>
#include <locale.h>

void criptografarmensagem(char texto[], int chave[2][2], char resultado[]) 
{
    int tamanho = strlen(texto);
    
    for (int i = 0; i < tamanho - 1; i += 2) 
    {
        int letra1 = texto[i] - 'A';        
        int letra2 = texto[i + 1] - 'A';    
        resultado[i] = ((chave[0][0] * letra1 + chave[0][1] * letra2) % 26) + 'A';
        resultado[i + 1] = ((chave[1][0] * letra1 + chave[1][1] * letra2) % 26) + 'A';
    }

    
    if (tamanho % 2 != 0) 
    {
        int letra1 = texto[tamanho - 1] - 'A';
        resultado[tamanho - 1] = ((chave[0][0] * letra1) % 26) + 'A';
    }
}

int main() 
{
    char mensagemEntrada[50];           
    char mensagemCodificada[50];         
    int chave[2][2] = { {6, 10}, {4, 7} }; 
    
    printf("Digite a mensagem que deseja criptografar(apenas letras): ");
    fgets(mensagemEntrada, sizeof(mensagemEntrada), stdin);
    mensagemEntrada[strcspn(mensagemEntrada, "\n")] = '\0';
    int posicao = 0;
    for (int i = 0; mensagemEntrada[i] != '\0'; i++) 
    {
        if (mensagemEntrada[i] >= 'a' && mensagemEntrada[i] <= 'z') 
        {
            mensagemEntrada[posicao++] = mensagemEntrada[i] - 32; 
        } 
        else if (mensagemEntrada[i] >= 'A' && mensagemEntrada[i] <= 'Z') 
        {
            mensagemEntrada[posicao++] = mensagemEntrada[i]; 
        }
    }
    mensagemEntrada[posicao] = '\0'; 

    printf("Texto original: %s\n", mensagemEntrada);
    criptografarmensagem(mensagemEntrada, chave, mensagemCodificada);
    printf("Mensagem criptografada: %s\n", mensagemCodificada);

    return 0;
}
