#include <iostream>

int main() {	
    size_t tamanho = 1000 * 1024 * 1024;
    char* memoria = new char[tamanho];

    for (size_t i = 0; i < tamanho; i += 4096) {
        memoria[i] = 1;
    }

    std::cout << "Memoria alocada. Pressione Enter...";
    std::cin.get();

    delete[] memoria;

    std::cout << "Memoria liberada. Pressione Enter...";
    std::cin.get();
}
