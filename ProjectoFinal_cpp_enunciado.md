# Enunciado — RH Avançado: Projecto Final

## Objetivo

Usando o **mini-sistema RH que já implementaste** em https://github.com/JoaoPTVilares/Exercicios/blob/main/Calendario.md, expandir o programa para adicionar novas funcionalidades que permitam um acompanhamento mais detalhado dos colaboradores.
O foco é **prático e incremental**: não reescrever o que já existe, mas construir **sobre a base existente**.

O novo sistema deve continuar a permitir:

* Gestão de colaboradores (CRUD básico)
* Marcação de férias/faltas
* Visualização de calendário mensal com indicação de fins de semana
* Persistência em ficheiro com encriptação  dos nomes

e incluir as **funcionalidades novas**:

---
## Requisitos Originais a manter

* Estrutura básica `Colaborador` com nome
* Adicionar colaborador
* Marcar/Desmarcar férias e faltas (dia/mês/ano)
* Listar colaboradores
* Visualizar calendário mensal com férias (F), faltas (X) e fins-de-semana
* Não marcar férias/faltas ao fim de semana
* Guardar/carregar ficheiros com encriptação simples
* Verificação de dias válidos (mês/ano, bissexto)
* Evitar duplicados ou pedir confirmação
* Código modular e organizado (`.h/.cpp`)

> Estes requisitos **devem continuar a funcionar**


---

## Novos Requisitos 

### 1 Relatórios Mensais

* Função que imprime um relatório do mês para todos os colaboradores.
* Mostrar: total de dias de férias (`F`) e faltas (`X`) por colaborador.

### 2 Busca de Colaborador

* Permitir procurar um colaborador pelo **nome** ou **ID**.
* Mostrar: dados básicos do colaborador e o **calendário do mês atual**.

### 3 Estatísticas de Departamento

* Mostrar total de dias de férias e faltas **por departamento**.
* Indicar o departamento com mais ausências.

### 4 Aviso de Conflito de Férias

* Antes de marcar férias, avisar se outro colaborador do mesmo departamento já tem férias naquele dia.

### 5 Dashboard Resumido

* Tabela mensal com:

  ```
  Nome      Férias  Faltas  Dias restantes
  Alice     3       1       17
  Bob       5       0       15
  ```
* Permite visão rápida de toda a equipa.

### 6 Formação / Cursos

* Cada colaborador pode ter uma lista de **formações, cursos ou certificações**.
* Estrutura sugerida:

```cpp
struct Formacao {
    std::string nome_curso;
    std::string data_conclusao;
};
std::vector<Formacao> formacoes;
```

* Funcionalidades CRUD:

  * Adicionar curso
  * Editar dados de curso
  * Remover curso
  * Listar cursos do colaborador

### 7 Notas / Observações Internas

* Cada colaborador pode ter uma lista de **notas internas ou observações**.
* Estrutura sugerida:

```cpp
struct Nota {
    std::string texto;
    std::string data;
};
std::vector<Nota> notas;
```

* Funcionalidades CRUD:

  * Adicionar nota
  * Editar nota
  * Remover nota
  * Listar notas

### 8 Exportação de Calendário / Relatório 

* Gerar ficheiro `.txt` ou `.csv` com calendário de férias/faltas de um colaborador ou de toda a equipa.

### 9 Interface e Experiência de Consola 

* Menu interativo com opções numeradas.
* Mensagens de erro, confirmação, cores ou alinhamento para melhor leitura.

---
# Exemplo do Menu e Funcionalidades — RH Avançado

```
=============================
      RH AVANÇADO
=============================

1. Listar colaboradores
2. Adicionar colaborador
3. Marcar férias/faltas
4. Visualizar calendário do colaborador
5. Buscar colaborador por ID ou nome
6. Gerir formações/cursos de um colaborador
7. Gerir notas/observações de um colaborador
8. Relatórios mensais
9. Estatísticas por departamento
10. Dashboard resumido
0. Sair
-----------------------------
Escolha uma opção: 1

Lista de Colaboradores:
ID: 1 | Nome: Alice | Departamento: Marketing
ID: 2 | Nome: Bob   | Departamento: TI
ID: 3 | Nome: Carla | Departamento: RH

Pressione Enter para continuar...

-----------------------------
Escolha uma opção: 6

--- FORMACOES / CURSOS DE ALICE ---
1. Listar formações
2. Adicionar formação
3. Editar formação
4. Remover formação
0. Voltar
Escolha uma opção: 2

Nome do curso: C++ Avançado
Data de conclusão: 2025-11-15
Formação adicionada com sucesso!

-----------------------------
Escolha uma opção: 7

--- NOTAS / OBSERVAÇÕES DE ALICE ---
1. Listar notas
2. Adicionar nota
3. Editar nota
4. Remover nota
0. Voltar
Escolha uma opção: 2

Texto da nota: Excelente desempenho no último projeto.
Data: 2025-11-10
Nota adicionada com sucesso!

-----------------------------
Escolha uma opção: 0
```

## Detalhes do Menu

* O menu principal lista todas as funcionalidades, numeradas.
* Submenus para cada colaborador (Formações e Notas) permitem **CRUD destas funcionalidades**.
* Mensagens claras confirmam ações como adicionar ou editar.

## Regras e Boas Práticas

* Modularização: criar funções novas em módulos `.h/.cpp` separados se necessário.
* Validar entradas: dias, meses, anos, duplicados, IDs válidos.
* Persistência: continuar a gravar e ler do mesmo ficheiro com encriptação/desencriptação.

---

## Entrega

* Até 23:00 de 20 Novembro de 2025
* Repositorio github com o codigo fonte em diretório organizado (`colaborador.h/cpp`, `io.h/cpp`, `main.cpp`, etc.);
* Ficheiro de dados de exemplo gerado pelo programa;
* README com instruções de compilação e utilização;
* Apresentação individual do funcionamento do projecto.

---

## Critérios de Avaliação

| Critério                                               | Peso |
| ------------------------------------------------------ | ---- |
| Funcionamento das funcionalidades | 80%  |
| Validações e tratamento de erros                       | 10%  |
| Documentação e interface                               | 10%  |

---
