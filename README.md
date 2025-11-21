# Big_Sistema_RH
No seguimento do Exercício do mini_sistema_RH, agora adicionando vários melhoramentos e novas funcionabilidades.

## Enunciado do projecto/exercício:
- https://github.com/JoaoPTVilares/Exercicios/blob/main/CalendarioMemoriaDinamica2.md
- https://github.com/JoaoPTVilares/Exercicios/blob/main/ProjectoFinal.md

<br><br>
<hr><hr>
<br><br>

# Como Funciona??
Ao correr o programa, este verifica se existem ficheiros com dados de sessões anteriores e carrega-os, caso não encontre nada, ele carrega dados de Demo.

## Menu Principal
Neste menu temos várias opções como "Exit", esta opção grava os dados atuais para o ficheiro e enserra o programa.

## (1) List Employees
Só Lista os Employees (dah!) nada de mais.

## (2) Add Employee
Permite, como o nome indica (dah!) adicionar Employees. Sendo que vai perdir o nome e (talvez) no futuro outros dados. <br>
Ao criar o Employee, este é iniciado e adicionado à lista de Employees, que pode depois ser consultada no ponto anterior.

## (3) Mark Vacation / (5) Mark absences
Como o nome indica, é para marcar férias. É mostrada a lista de Employees e pedido o numero do pretendido. <br>
Depois de introduzido o numero do employee pretendido é perguntado o numero de dias a adicionar. <br>
São então mostrados os dias de Férias e de Faltas que o employee tem para ajuda visual... <br>
(Há formas melhores de fazer isto... mas não me veio nenhuma à cabeça por isso para já fica assim). <br>
Quando é inserida a data é verificado o formato da data inserida, se o dia é um fim de semana e se já está marcado. Se for inserida uma data já marcada é dado um erro a condizer e é dada a opção de substituir falta por férias ou viceverssa (dependendo do que estejamos a marcar).

## (4) Remove Vacation / (5) Mark absences
Funcina com o marcar faltas e férias, mas remove, tendo os erros e substituições a condizer. É também verificado se o dia não não tem nada para remever... 

## (7) Employee's Monthly Calendar (a Joia da Coroa)
Para não ser diferente... esta opção mostra os employees e pede o numero do employee a ver. Depois pede o mes e ano a ver. Depois mostra o calendário, este pode não ter nem férias nem faltas marcadas. <br>
Nota: eu recuso-me a respirar perto da função que desenha este calendário! Finalmente Funciona! E como se diz na minha terra "Se não está avariado não se mexe!"

## (8) Employee's Monthly Report
Permite escolher um Empregado, mes e ano e imprime o calendário com as faltas e férias do mesmo.

## (9) Find Employee By Name or ID
Encontra um Empregado por nome ou ID e mostra uma Dashboard com dados de férias e o departamento do mesmo.

## (10) Add New Department
Permite adicionar um novo departamento ao sistema.

## (11) Change Employee's Department
Permite alterar o Departamento a que o funcionário está assuciado.

## (12) Department Status
Mostra os dias de faltas e férias para um determinado departamento à escolha do utilizador.

## (13) Monthly Dashboard
A _Monthly Dashboard_ mostra as faltas e férias de todos os colaburadores para o més atual.

## (14) Courses
Permite escolher um colaborador e gerir os Cursos que este tem assuciados. Neste menu podemos adionar, editar e remover Cursos.

## (15) Notes
Permite escolher um colaborador e gerir as Notas que este tem assuciados. Neste menu podemos adionar, editar e remover Notas.

## (16) Export Employee's Report
Permite escolher um colaborador e um ano para gerar um ficehiro .txt com o nome, departamento, dias de férias, faltas e quantos dias de férias restão ao mesmo.

## (17) Export Department's Report
Este menu permit escolher um Departamento e o ano que queremos, Depois gera-nos um relatório com o nome do Departamento, total de dias de férias de todos os colaboradores e os dias em que essas férias calham. É de notar que os dias não repetem, pelo que o numero total de férias pode ser superior ao numero de dias mostrados, porque 2 colegas pode ter férias no memso dia para irem à pesca juntos.

<br><br>
<hr><hr>
<br><br>

# Instalação e Correr
É só clonar o Git Repo, Compilar o __*main.cpp*__ e como dizem os Americanos "hope for the best". <br>
Usando o VSCode é só ir ao __*main.cpp*__ e correr! __SE__ (GRANDE SE) o VSCode estiver configurado para correr código C/C++! Caso não esteja.. (well thouph luck)(google it e configura! eu não vou fazer um guia...)

## Requerimentos
Se tens o VSCode ou outra IDE configurada para C/C++ tás "Good to Go". Não usei nenhuma Biblioteca extra, o que se vê é o que corre!
- C++ 17 ou mais recente.
- Compilador de C/C++ 

<br><br>
<hr><hr>
<br><br>

# O que vem ai (caso o Kikstart corra bem! ahah)
- Adicionar mais campos aos Employees como telefone, CC, etc. e um modo de ver cada employee individualmente e sentralizadamente.
- Sorting de funcionários e uma forma de lidar com quantidades maiores de férias e Faltas... (como está o ecrã vai cheio num estantinho!)
- GUI... Nah! Qt já era a dor que era em Python! ahah
- Sons também?? why not!? O Natal até vem ai e tudo!

<br><br>
<hr><hr>
<br><br>

# Pontos a melhorar:
- Redundância de código, em especial no que toca a pedir imputes do user. No final comecei a usar funcões mais genericas, mas os danos estavam feitos. Agora é Refactor!
- No início (não sei bem que porquê) decidi meter a logica dos menus no switch case que controla o flow do menu principal... (GRANDE ERRO!!) Isto feio a causar vários problemas de scope e tive de ser criativo (a entalar-me mais) a resolver esses problemas. No final comecei a criar scopes nos Cases para combater esses problemas e ser mais facil de Refactor Later. ^_^ (Infelizmente um dos pontos do trabalho é não fazer GRANDES alterações no que já estava feito... por isso o ERRO fica...)
- Separação de responsabilidade entre as funções. Já mais para o fim, comecei a notar que tinha fuitas funções que podia ser movidas da class HR, ser generalizadas e ser movidas para um ficheiro de utils... (mas o tempo não estica, por isso Refactoring para a próxima)
- Fazer o programa em Inglês talvez não tenha sido das melhores ideias... Apesar de ter sido preferência minha, toda a documentção deste ReadMe está em Português... (só me resta a opção de traduzir esta treta para inglês e ficar com o README_pt e o README_eng)

# O que Aprendi e que Correu bem:
- Aprendi a não ter medo de Poiters e Referências! Apesar de continuarem a ser uma dor de cabeça para Debug! (Ate gostei de trabalhar com elas).
- Amei Matar 2 coelhos com uma cajadada só! Para fazer o Menu que trata das Notas e Cursos, diverti-me bastante a encontrar uma forma de fazer um menu que desse para ambos ao mesmo tempo! E em retrospetiva seria algo do mesmo genero que eu faria com o Adicionar féria/faltas e com o Remover também. Mas para estas a Logica muda um pouco mais no que toca a lidar com repetições... pelo que não olhei muito para elas (o tempo não estica).
