#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição das estruturas
typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
    int telefone;
} Cliente;

typedef struct {
    int codigo;
    char nome[50];
    int telefone;
    char cargo[50];
    float salario;
} Funcionario;

typedef struct {
    int codigo_estadia;
    char data_entrada[11];
    char data_saida[11];
    int quantidade_diarias;
    int codigo_cliente;
    int numero_quarto;
} Estadia;

typedef struct {
    int numero_quarto;
    int quantidade_hospedes;
    float valor_diaria;
    char status[20];
} Quarto;

// Funções de cadastro
void cadastrarCliente();
void cadastrarFuncionario();
void cadastrarEstadia();
void darBaixaEstadia();

// Funções de pesquisa
void pesquisarCliente();
void pesquisarFuncionario();
void pesquisarEstadiasCliente();

// Função principal
int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Cadastrar funcionário\n");
        printf("3. Cadastrar estadia\n");
        printf("4. Dar baixa em estadia\n");
        printf("5. Pesquisar cliente\n");
        printf("6. Pesquisar funcionário\n");
        printf("7. Pesquisar estadias de um cliente\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarFuncionario();
                break;
            case 3:
                cadastrarEstadia();
                break;
            case 4:
                darBaixaEstadia();
                break;
            case 5:
                pesquisarCliente();
                break;
            case 6:
                pesquisarFuncionario();
                break;
            case 7:
                pesquisarEstadiasCliente();
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 8);

    return 0;
}

// Implementação das funções de cadastro
void cadastrarCliente() {
    FILE *arquivo;
    Cliente novoCliente;

    printf("Digite o código do cliente: ");
    scanf("%d", &novoCliente.codigo);

    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente.nome);

    printf("Digite o endereço do cliente: ");
    scanf("%s", novoCliente.endereco);

    printf("Digite o telefone do cliente: ");
    scanf("%d", &novoCliente.telefone);

    arquivo = fopen("clientes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d %s %s %d\n", novoCliente.codigo, novoCliente.nome, novoCliente.endereco, novoCliente.telefone);
    fclose(arquivo);

    printf("Cliente cadastrado com sucesso!\n");
}

void cadastrarFuncionario() {
    FILE *arquivo;
    Funcionario novoFuncionario;

    printf("Digite o código do funcionário: ");
    scanf("%d", &novoFuncionario.codigo);

    printf("Digite o nome do funcionário: ");
    scanf("%s", novoFuncionario.nome);

    printf("Digite o telefone do funcionário: ");
    scanf("%d", &novoFuncionario.telefone);

    printf("Digite o cargo do funcionário: ");
    scanf("%s", novoFuncionario.cargo);

    printf("Digite o salário do funcionário: ");
    scanf("%f", &novoFuncionario.salario);

    arquivo = fopen("funcionarios.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d %s %d %s %.2f\n", novoFuncionario.codigo, novoFuncionario.nome, novoFuncionario.telefone, novoFuncionario.cargo, novoFuncionario.salario);
    fclose(arquivo);

    printf("Funcionário cadastrado com sucesso!\n");
}

    void cadastrarEstadia() { //CadastrarEstadia
        FILE *arquivo;
        Estadia estadiaNovo;

        printf("Digite o código de estadia: ");
        scanf("%d", &estadiaNovo.codigo_estadia);

        printf("Digite a data de entrada: ");
        scanf("%s", estadiaNovo.data_entrada);

        printf("Digite a data de saida: ");
        scanf("%s", estadiaNovo.data_saida);

        printf("Digite a quantidade de diarias: ");
        scanf("%d", &estadiaNovo.quantidade_diarias);

        printf("Digite o codigo do cliente: ");
        scanf("%d", &estadiaNovo.codigo_cliente);

        printf("Digite o numero do quarto: ");
        scanf("%d", &estadiaNovo.numero_quarto);

        arquivo = fopen("estadias_cadastro.txt", "a");
        if(arquivo == NULL){
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        fprintf(arquivo, "%d %s %s %d %d %d", estadiaNovo.codigo_estadia, estadiaNovo.data_entrada, estadiaNovo.data_saida, estadiaNovo.quantidade_diarias, estadiaNovo.codigo_cliente, estadiaNovo.numero_quarto);
        fclose(arquivo);
    }

void darBaixaEstadia() {

}

// Implementação das funções de pesquisa
void pesquisarCliente() {
    FILE *arquivo;
    int codigoPesquisa;
    Cliente cliente;

    printf("Digite o código do cliente: ");
    scanf("%d", &codigoPesquisa);

    arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fscanf(arquivo, "%d %s %s %s", &cliente.codigo, cliente.nome, cliente.endereco, cliente.telefone) != EOF) {
        if (cliente.codigo == codigoPesquisa) {
            printf("Código: %d\n", cliente.codigo);
            printf("Nome: %s\n", cliente.nome);
            printf("Endereço: %s\n", cliente.endereco);
            printf("Telefone: %s\n", cliente.telefone);
            fclose(arquivo);
            return;
        }
    }

    printf("Cliente não encontrado.\n");
    fclose(arquivo);
}

void pesquisarFuncionario() {
    FILE *arquivo;
    int codigoPesquisa;
    Funcionario funcionario;

    printf("Digite o código do funcionário: ");
    scanf("%d", &codigoPesquisa);

    arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fscanf(arquivo, "%d %s %s %s %f", &funcionario.codigo, funcionario.nome, funcionario.telefone, funcionario.cargo, &funcionario.salario) != EOF) {
        if (funcionario.codigo == codigoPesquisa) {
            printf("Código: %d\n", funcionario.codigo);
            printf("Nome: %s\n", funcionario.nome);
            printf("Telefone: %s\n", funcionario.telefone);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Salário: %.2f\n", funcionario.salario);
            fclose(arquivo);
            return;
        }
    }

    printf("Funcionário não encontrado.\n");
    fclose(arquivo);
}

void pesquisarEstadiasCliente() {
    // Implemente aqui o código para pesquisar estadias de um cliente
}
