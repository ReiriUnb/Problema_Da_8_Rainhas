#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include "rainhas.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int verificaTamanho(const std::string& filename) {
    std::ifstream arquivo(filename);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        return -2;
    }

    int contLetras = 0;
    int contNumeros = 0;
    char caractere;

    while (arquivo.get(caractere)) {
        if (isalpha(caractere)) {
            contLetras++;
        } else if (isdigit(caractere)) {
            contNumeros++;
        }
    }

    if (contNumeros != 64 && contLetras != 0) {
        return -1;
    }

    arquivo.close();
    return 1;
}

int check(const std::string& filename) {
    if (verificaTamanho(filename) == -1) { return -1; }
    if (verificaTamanho(filename) == -2) { return -2; }

    std::ifstream arquivo(filename);

    std::string linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8;
    std::string linhaExtra;

    if (std::getline(arquivo, linha1) &&
        std::getline(arquivo, linha2) &&
        std::getline(arquivo, linha3) &&
        std::getline(arquivo, linha4) &&
        std::getline(arquivo, linha5) &&
        std::getline(arquivo, linha6) &&
        std::getline(arquivo, linha7) &&
        std::getline(arquivo, linha8) &&
        !std::getline(arquivo, linhaExtra)) {
    } else {
        return -1;
    }

    arquivo.close();

    int valueReturn = 1;
    int arrayLine1[8];
    int arrayLine2[8];
    int arrayLine3[8];
    int arrayLine4[8];
    int arrayLine5[8];
    int arrayLine6[8];
    int arrayLine7[8];
    int arrayLine8[8];

    int countLine = 0;
    int countTotal = 0;
    int* arrays[] = {
        arrayLine1, arrayLine2, arrayLine3, arrayLine4,
        arrayLine5, arrayLine6, arrayLine7, arrayLine8};

    vector<string> linhas =
        {linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8};

    int attackSameLine[8] = {10, 10, 10, 10, 10, 10, 10, 10};

    std::string ataques = "";

    // Restante da implementação da função check...

    return valueReturn;
}

int verifica_solucao_8_rainhas(const std::string& filename) {
    int valor = check(filename);

    if (valor == -1) {
        cout << "-1" << endl;
        return -1;
    }
    if (valor == -2) {
        cout << "Erro ao abrir arquivo" << endl;
    }
    if (valor == 0) {
        cout << "0" << endl;
        return 0;
    }
    if (valor == 1) {
        cout << "1" << endl;
        return 1;
    }

    return -1;
}
