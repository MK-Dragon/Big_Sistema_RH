# Big_Sistema_RH
No seguimento do Exercício do mini_sistema_RH, agora adicionando vários melhoramentos e novas funcionabilidades.

## Enunciado do projecto/exercício:
- https://github.com/JoaoPTVilares/Exercicios/blob/main/CalendarioMemoriaDinamica2.md
- https://github.com/JoaoPTVilares/Exercicios/blob/main/ProjectoFinal.md

<br><br>
<hr><hr>
<br><br>

# Como Funciona??
Ao correr o programa, este verifica se existe um com dados de sessões anteriores, caso não encontre nada, ele cria um ficheiro com dados de Demo.

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

<br><br>
<hr><hr>
<br><br>

# Instalação e Correr
É só Compilar o __*main.cpp*__ e como dizem os Americanos "hope for the best". <br>
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
- Falan
