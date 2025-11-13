// Utils/DEncript.h


#include <iostream>
#include <string>
 
// Função simples de encriptação (Cifra de César)
std::string encriptar(const std::string &texto, int chave) {
    std::string resultado = texto;
 
    for (size_t i = 0; i < texto.size(); ++i) {
        char c = texto[i];
 
        if (std::isalpha(c)) { // apenas letras
            char base = std::isupper(c) ? 'A' : 'a';
            resultado[i] = char((c - base + chave) % 26 + base);
        } else {
            resultado[i] = c; // mantém espaços e pontuação
        }
    }
    return resultado;
}
 
// Função de desencriptação (reverte o processo)
std::string desencriptar(const std::string &texto, int chave) {
    return encriptar(texto, 26 - (chave % 26)); // desloca no sentido inverso
}
 
/*int main() {
    std::string mensagem;
    int chave;
 
    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, mensagem);
 
    std::cout << "Digite a chave (número): ";
    std::cin >> chave;
 
    std::string cifrada = encriptar(mensagem, chave);
    std::string decifrada = desencriptar(cifrada, chave);
 
    std::cout << "\nMensagem cifrada: " << cifrada << "\n";
    std::cout << "Mensagem decifrada: " << decifrada << "\n";
 
    return 0;
}*/
