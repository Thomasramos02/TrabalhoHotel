#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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
    int data_entrada;
    int data_saida;
    int quantidade_diarias;
    int codigo_cliente;
    int numero_quarto;
    int quantidade_hospedes;
} Estadia;


typedef struct {
    int numero;
    int capacidade;
    bool disponivel;
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
int gerarCodigoAleatorio() {
    return rand() % 1000 + 1; // Gera um código aleatório entre 1 e 1000
}

int calcularDiarias(int data_entrada, int data_saida) {
    // Esta função assume que as datas estão no formato AAAAMMDD
    int ano_entrada = data_entrada / 10000;
    int mes_entrada = (data_entrada / 100) % 100;
    int dia_entrada = data_entrada % 100;

    int ano_saida = data_saida / 10000;
    int mes_saida = (data_saida / 100) % 100;
    int dia_saida = data_saida % 100;

    struct tm entrada = {0, 0, 0, dia_entrada, mes_entrada - 1, ano_entrada - 1900};
    struct tm saida = {0, 0, 0, dia_saida, mes_saida - 1, ano_saida - 1900};

    time_t entrada_time = mktime(&entrada);
    time_t saida_time = mktime(&saida);

    double seconds = difftime(saida_time, entrada_time);
    int dias = seconds / (60 * 60 * 24);

    return dias;
}

void inicializarQuartos() {
    FILE *arquivoQuartos;
    Quarto quarto;
    int quantidadeQuartos = 10;  // Número de quartos que deseja gerar

    arquivoQuartos = fopen("quartos.txt", "w");
    if (arquivoQuartos == NULL) {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return;
    }

    srand(time(NULL));  // Inicializa a semente do gerador de números aleatórios

    for (int i = 1; i <= quantidadeQuartos; i++) {
        quarto.numero = i;
        quarto.capacidade = rand() % 4 + 1;  // Capacidade entre 1 e 4 hóspedes
        quarto.disponivel = rand() % 2;  // Disponibilidade aleatória (0 ou 1)
        fprintf(arquivoQuartos, "%d %d %d\n", quarto.numero, quarto.capacidade, quarto.disponivel);
    }

    fclose(arquivoQuartos);
    printf("Quartos inicializados com sucesso!\n");
}
// Implementação das funções de cadastro

void cadastrarCliente() {
    FILE *arquivo;
    Cliente novoCliente;

    srand(time(NULL)); // Inicializa a semente para geração de números aleatórios

    novoCliente.codigo = gerarCodigoAleatorio(); // Gera um código aleatório para o cliente

    printf("Código do cliente: %d\n", novoCliente.codigo);

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
    novoFuncionario.codigo = gerarCodigoAleatorio();

    printf("o código do funcionário: %d \n",novoFuncionario.codigo);

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
    inicializarQuartos(); // Inicializa os quartos com disponibilidade aleatória
    
    FILE *arquivoEstadias, *arquivoQuartos, *arquivoQuartosAux;
    Estadia estadiaNova;
    Quarto quarto;
    bool quartoEncontrado = false;

    printf("Digite o código de estadia: ");
    scanf("%d", &estadiaNova.codigo_estadia);

    printf("Digite a data de entrada (AAAAMMDD): ");
    scanf("%d", &estadiaNova.data_entrada);

    printf("Digite a data de saída (AAAAMMDD): ");
    scanf("%d", &estadiaNova.data_saida);

    estadiaNova.quantidade_diarias = calcularDiarias(estadiaNova.data_entrada, estadiaNova.data_saida);
    printf("Quantidade de diárias: %d\n", estadiaNova.quantidade_diarias);

    printf("Digite o código do cliente: ");
    scanf("%d", &estadiaNova.codigo_cliente);

    printf("Digite a quantidade de hóspedes: ");
    scanf("%d", &estadiaNova.quantidade_hospedes);

    arquivoQuartos = fopen("quartos.txt", "r");
    if (arquivoQuartos != NULL) {
        while (fscanf(arquivoQuartos, "%d %d %d", &quarto.numero, &quarto.capacidade, &quarto.disponivel) != EOF) {
            if (quarto.capacidade >= estadiaNova.quantidade_hospedes && quarto.disponivel) {
                estadiaNova.numero_quarto = quarto.numero;
                quartoEncontrado = true;
                break;
            }
        }
        fclose(arquivoQuartos);
    }

    if (!quartoEncontrado) {
        printf("Nenhum quarto disponível para a quantidade de hóspedes desejada.\n");
        return;
    }

    arquivoEstadias = fopen("estadias_cadastro.txt", "a");
    if (arquivoEstadias == NULL) {
        printf("Erro ao abrir o arquivo de estadias.\n");
        return;
    }

    fprintf(arquivoEstadias, "%d %d %d %d %d %d %d\n", 
        estadiaNova.codigo_estadia, estadiaNova.data_entrada, estadiaNova.data_saida, 
        estadiaNova.quantidade_diarias, estadiaNova.codigo_cliente, 
        estadiaNova.numero_quarto, estadiaNova.quantidade_hospedes);

    fclose(arquivoEstadias);

    // Atualiza o arquivo de quartos para marcar o quarto como indisponível
    arquivoQuartosAux = fopen("quartos_aux.txt", "w");
    arquivoQuartos = fopen("quartos.txt", "r");
    if (arquivoQuartos != NULL && arquivoQuartosAux != NULL) {
        while (fscanf(arquivoQuartos, "%d %d %d", &quarto.numero, &quarto.capacidade, &quarto.disponivel) != EOF) {
            if (quarto.numero == estadiaNova.numero_quarto) {
                quarto.disponivel = false; // Marca o quarto como indisponível
            }
            fprintf(arquivoQuartosAux, "%d %d %d\n", quarto.numero, quarto.capacidade, quarto.disponivel);
        }
        fclose(arquivoQuartos);
        fclose(arquivoQuartosAux);
        remove("quartos.txt");
        rename("quartos_aux.txt", "quartos.txt");
    }

    printf("Estadia cadastrada com sucesso!\n");
}


void darBaixaEstadia() {
    FILE*arquivo;
    Quarto baixaEstadia;


    printf("Digite o numero do quarto: \n");
    scanf("%d", &baixaEstadia.numero);

    printf("Digite a quantidade de hospedes: \n");
    scanf("%d",&baixaEstadia.capacidade);


    arquivo =fopen("baixa_Estadia.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(arquivo, "Quarto %d\n",baixaEstadia.numero);
    fprintf(arquivo, "Quantidade de hospedes: %d\n  ",baixaEstadia.capacidade); //colocar o numero de diarias
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

    while (fscanf(arquivo, "%d %s %s %d", &cliente.codigo, cliente.nome, cliente.endereco, &cliente.telefone) != EOF) {
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

    while (fscanf(arquivo, "%d %s %d %s %f", &funcionario.codigo, funcionario.nome, &funcionario.telefone, funcionario.cargo, &funcionario.salario) != EOF) {
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

    while (fscanf(arquivo, "%d %d %d %d %d", &estadia.codigo_estadia, &estadia.data_entrada, &estadia.data_saida, &estadia.quantidade_diarias, &estadia.numero_quarto) != EOF) {
        if (estadia.codigo_estadia == codigoPesquisa) {
            printf("\n\nCódigo: %d\n",estadia.codigo_estadia);
            printf("Data de entrada: %d\n",estadia.data_entrada);
            printf("Data de saida: %d\n",estadia.data_saida);
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
