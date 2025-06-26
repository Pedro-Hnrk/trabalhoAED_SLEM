# Trabalho AED - Sistema CRUD de Locais, Veículos e Pedidos

Este projeto é um sistema CRUD (Create, Read, Update, Delete) em C++ para gerenciamento de **Locais**, **Veículos** e **Pedidos**, desenvolvido como trabalho para a disciplina de Algoritmos e Estruturas de Dados (AED).

## Estrutura do Projeto

```
trabalho_AED/
│
├── include/
│   ├── classes/
│   │   ├── Endereco.h
│   │   ├── Local.h
│   │   ├── Veiculo.h
│   │   └── Pedido.h
│   └── funcs/
│       ├── systemCRUD.h
│       └── verificadores/
│           ├── verificadorLocal.h
│           ├── verificadorPedido.h
│           └── verificadorVeiculo.h
│
├── src/
│   └── main.cpp
│
└── .vscode/
    ├── c_cpp_properties.json
    ├── launch.json
    └── tasks.json
```

## Descrição dos Componentes

- **classes/**: Contém as classes principais do sistema:
  - `Endereco.h`: Representa um endereço (rua, cidade, estado).
  - `Local.h`: Representa um local físico com endereço e coordenadas.
  - `Veiculo.h`: Representa um veículo com placa, modelo, local e status.
  - `Pedido.h`: Representa um pedido com origem, destino e peso.

- **funcs/**: Funções utilitárias e lógica de negócio:
  - `systemCRUD.h`: Implementa o CRUD para locais, veículos e pedidos.
  - `verificadores/`: Funções para validação de dados (endereços, locais, veículos, pedidos).

- **src/main.cpp**: Exemplo de uso do sistema CRUD.

- **.vscode/**: Configurações para facilitar a compilação e depuração no Visual Studio Code.

## Como Compilar e Executar

### Pré-requisitos

- **Compilador C++** (g++ recomendado, disponível via MSYS2 no Windows)
- **Visual Studio Code** com as extensões:
  - C/C++
  - Code Runner (opcional)

### Compilação Manual

No terminal, na raiz do projeto:

```sh
g++ -Iinclude -g -o main src/main.cpp
```

### Execução

No Windows:

```sh
main.exe
```

No Linux/Mac:

```sh
./main
```

### Compilação e Execução pelo VS Code (F5)

1. Certifique-se de que os arquivos `.vscode/tasks.json` e `.vscode/launch.json` estão configurados conforme o projeto.
2. Pressione **F5** para compilar e executar com depuração.

## Observações

- O sistema utiliza arrays fixos de tamanho 100 para armazenar locais, veículos e pedidos.
- As validações de dados são feitas nos arquivos `verificador*.h`.
- O código é modularizado para facilitar manutenção e expansão.

## Autoria

Desenvolvido por Pedro para a disciplina de Algoritmos e Estruturas de Dados.

---