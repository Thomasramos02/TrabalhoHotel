#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das estruturas
typedef struct {
    int codigo;
    char nome[50];
    char endereco[50];
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
    int valor_diaria;
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

    fprintf(arquivo, "codigo do cliente: %d\n",novoCliente.codigo);
    fprintf(arquivo, "nome do cliente: %s\n",novoCliente.nome);
    fprintf(arquivo, "endereço do cliente: %s\n",novoCliente.endereco);
    fprintf(arquivo, "telefone do cliente: %d\n",novoCliente.telefone);
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
    }{

    fprintf(arquivo,"codigo do funcionario: %d\n",novoFuncionario.codigo);
    fprintf(arquivo,"nome do funcionario: %s\n",novoFuncionario.nome);
    fprintf(arquivo,"Telefone do funcionario: %d\n",novoFuncionario.telefone);
    fprintf(arquivo,"Cargo do funcionario cadastrado: %s\n",novoFuncionario.cargo);
    fprintf(arquivo,"Salario do funcionario: %f",novoFuncionario.salario);
    fclose(arquivo);

    printf("Funcionário cadastrado com sucesso!\n");
    }
}

void cadastrarEstadia() {

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

        fprintf(arquivo,"codigo da estadia: %d\n",estadiaNovo.codigo_estadia);
        fprintf(arquivo,"data de entrada: %s\n",estadiaNovo.data_entrada);
        fprintf(arquivo,"data de saida: %s\n",estadiaNovo.data_saida);
        fprintf(arquivo,"diarias: %d\n",estadiaNovo.quantidade_diarias);
        fprintf(arquivo,"numero do quarto : %d",estadiaNovo.numero_quarto);
        fclose(arquivo);
    }


void darBaixaEstadia() {
    FILE*arquivo;
    Quarto baixaEstadia;

    int diarias = 150;
    baixaEstadia.valor_diaria = diarias * baixaEstadia.valor_diaria;

    printf("Digite o numero do quarto: \n");
    scanf("%d",baixaEstadia.numero_quarto);

    printf("Digite a quantidade de hospedes: \n");
    scanf("%d",&baixaEstadia.quantidade_hospedes);


    arquivo =fopen("baixa_Estadia.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(arquivo, "Quarto %d\n",baixaEstadia.numero_quarto);
    fprintf(arquivo, "Quantidade de hospedes: %d\n  ",baixaEstadia.quantidade_hospedes); //colocar o numero de diarias
    fprintf(arquivo, "Valor total a ser pago : %d",baixaEstadia.valor_diaria);
    fclose(arquivo);
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

    while (fscanf(arquivo, "%d %s %s %d", &cliente.codigo, cliente.nome, cliente.endereco, cliente.telefone) != EOF) {
        if (cliente.codigo == codigoPesquisa) {
            printf("Código: %d\n", cliente.codigo);
            printf("Nome: %s\n", cliente.nome);
            printf("Endereço: %s\n", cliente.endereco);
            printf("Telefone: %d\n", cliente.telefone);
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
    }else{

    while (fscanf(arquivo, "%d %s %d %s %f", &funcionario.codigo, funcionario.nome, funcionario.telefone, funcionario.cargo, &funcionario.salario) != EOF) {
        if (funcionario.codigo == codigoPesquisa) {
            printf("Código: %d\n", funcionario.codigo);
            printf("Nome: %s\n", funcionario.nome);
            printf("Telefone: %d\n", funcionario.telefone);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Salário: %.2f\n", funcionario.salario);
            fclose(arquivo);
            return;
        }
    }
    
    }

    printf("Funcionário não encontrado.\n");
    fclose(arquivo);
}

void pesquisarEstadiasCliente() {
    FILE *arquivo;
    int codigoPesquisa;
    Estadia estadia;

    printf("Digite o código da estadia: ");
    scanf("%d", &codigoPesquisa);

    arquivo = fopen("estadias_cadastro.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }else{

    while (fscanf(arquivo, "%d %s %s %d %d", &estadia.codigo_estadia, estadia.data_entrada, estadia.data_saida, &estadia.quantidade_diarias, &estadia.numero_quarto) != EOF) {
        if (estadia.codigo_estadia == codigoPesquisa) {
            printf("\n\nCódigo: %d\n",estadia.codigo_estadia);
            printf("Data de entrada: %s\n",estadia.data_entrada);
            printf("Data de saida: %s\n",estadia.data_saida);
            printf("Quantidade de diarias: %d\n",estadia.quantidade_diarias);
            printf("numero do quarto: %d\n",estadia.numero_quarto);
            fclose(arquivo);
            return;
        }
    }
    
    }

    printf("Estadia não encontrado.\n");
    fclose(arquivo);
}
}
