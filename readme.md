# Trabalho AED - Sistema CRUD de Locais, Veículos e Pedidos

Este projeto é um sistema CRUD (Create, Read, Update, Delete) em C++ para gerenciamento de **Locais**, **Veículos** e **Pedidos**, desenvolvido como trabalho para a disciplina de Algoritmos e Estruturas de Dados (AED).

---

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
│   ├── database/
│   │   ├── database.bin
│   │   └── repositorio.h
│   └── funcs/
│       ├── localService.h
│       ├── pedidoService.h
│       ├── systemService.h
│       ├── veiculoService.h
│       └── verificadores/        
│
├── src/
│   └── main.cpp


```

---

## Descrição dos Componentes

- **include/classes/**: Classes principais do sistema:
  - `Endereco.h`: Representa um endereço (rua, cidade, estado).
  - `Local.h`: Representa um local físico com endereço e coordenadas.
  - `Veiculo.h`: Representa um veículo com placa, modelo, local e status.
  - `Pedido.h`: Representa um pedido com origem, destino, peso e status.

- **include/database/**:
  - `repositorio.h`: Implementa o repositório central, responsável por armazenar, buscar, atualizar, remover e persistir locais, veículos e pedidos.
  - `database.bin`: Arquivo binário gerado automaticamente para persistência dos dados.

- **include/funcs/**:
  - `localService.h`, `veiculoService.h`, `pedidoService.h`: Serviços para operações CRUD de cada entidade, interagindo com o repositório.
  - `systemService.h`: Funções utilitárias do sistema, como salvar/carregar banco de dados, calcular distâncias e gerenciar entregas.

- **src/main.cpp**: Ponto de entrada do programa, com menu interativo para o usuário.

- **.vscode/**: Configurações para facilitar a compilação e depuração no Visual Studio Code.

---

## Funcionalidades

- **Cadastro, listagem, edição e remoção de Locais, Veículos e Pedidos**
- **Validação de dados** (placa, endereço, coordenadas, peso, etc)
- **Persistência automática dos dados** em arquivo binário (`database/database.bin`)
- **Gerenciamento de entregas**: seleção automática do veículo mais próximo e atualização do status do pedido e do veículo
- **Menu interativo** no terminal para todas as operações

---

## Como Compilar e Executar

### Pré-requisitos

- **Compilador C++** (g++ recomendado, disponível via MSYS2 no Windows)
- **Visual Studio Code** (opcional) com as extensões:
  - C/C++
  - Code Runner (opcional)

### Compilação Manual

No terminal, na raiz do projeto:

```sh
g++ -Iinclude -g -o SLEM src/main.cpp
```

### Execução

No Windows:

```sh
SLEM.exe
```

No Linux/Mac:

```sh
./main
```

### Compilação e Execução pelo VS Code (F5)

1. Certifique-se de que os arquivos `.vscode/tasks.json` e `.vscode/launch.json` estão configurados conforme o projeto.
2. Pressione **F5** para compilar e executar com depuração.

---

## Observações Importantes

- **Persistência:** Os dados são salvos automaticamente ao sair do programa e carregados ao iniciar. O arquivo `database/database.bin` é criado na primeira execução.
- **Diretório de execução:** Execute o programa sempre a partir da raiz do projeto para garantir que o arquivo de banco de dados seja encontrado.
- **Validações:** O sistema valida placas, endereços, coordenadas e outros campos para evitar dados inconsistentes.
- **IDs:** IDs de locais, veículos e pedidos são gerados automaticamente e são únicos.
- **Limitações:** O sistema utiliza `std::vector` para armazenar os dados em memória. Não há limite fixo de registros, apenas o limite de memória do computador.

---

## Exemplo de Uso

Ao rodar o programa, você verá um menu como este:

```
Bem-vindo ao SLEM!
Selecione uma opção:
1. Locais
2. Veículos
3. Pedidos
4. Gerenciar Entregas
0. Sair
```

Cada opção leva a submenus para adicionar, listar, editar ou remover registros.

---

## Autoria

Desenvolvido por Pedro para a disciplina de Algoritmos e Estruturas de
