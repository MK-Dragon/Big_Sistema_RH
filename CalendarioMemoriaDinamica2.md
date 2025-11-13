
Em C++  implementar um mini-sistema de RH (adicionar colaboradores, marcar férias/faltas e visualizar calendário mensal com indicação de fins de semana). Tudo feito só com   iostream, fácil de compilar e usar.


# Enunciado do Exercício: Mini-Sistema RH — Calendário de Férias/Faltas
### Objetivo
Implementar um mini-sistema RH em C++ que permita gerir colaboradores e marcar férias e faltas, visualizar o calendário mensal com marcações e aplicar uma encriptação pedagógica ao gravar nomes em ficheiro.

### Requisitos mínimos
1. Estrutura de dados:
   - `struct Colaborador { std::string nome; /* ... */ }` ou equivalente;

2. Funcionalidades (interface de consola):
   - Adicionar colaborador;
   - Marcar/Desmarcar férias e faltas (por dia, mês e ano);
   - Listar colaboradores;
   - Visualizar calendário mensal de um colaborador com indicação de férias (F), faltas (X) e fins-de-semana;
   - Guardar e carregar dados para/desde ficheiro (txt ou csv) ao sair/iniciar.
3. Validações:
   - Verificar dias válidos para o mês/ano (bisexto);
   - Evitar duplicados (nomes iguais) ou pedir confirmação.
4. Persistência e privacidade:
   - Ao gravar ficheiros, aplicar uma encriptação  (Cifra) nos  nomes dos colaboradores; ao ler, desencriptar;

5. Código:
   - Separar código em módulos/files (ex.: `colaborador.h/.cpp`, `io.h/.cpp`, `main.cpp`);
   - Utilizar boas práticas: funções pequenas, tratamento de erros básicos, comentários claros.
6. Extras opcionais (valorizados na avaliação):
   - Interface de consola com cores/alinhamento;

### Entregáveis
- Código fonte (ficheiros .cpp, .h) organizados num diretório com README contendo instruções de compilação e uso.
- Ficheiro de dados de exemplo (gerado pelo programa).
- Breve documentação (1 página): explicação da estrutura do programa, utilização da Cifra.

### Critérios de avaliação
- Funcionamento das funcionalidades obrigatórias (60%);
- Qualidade do código e modularização (15%);
- Persistência (gravação/leitura correta) e aplicação da encriptação pedagógica (10%);
- Validações e tratamento de erros (10%);
- Documentação e apresentação (5%).

### Tempo sugerido na aula
-  120 minutos.

### Entrega

- Envio de link do repository github do projecto

(só será avaliado o código commited até ás 23h do dia de hoje )