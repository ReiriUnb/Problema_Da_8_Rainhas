#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rainhas.hpp"

using namespace std;

// Verifica se o tamanho da matriz é válido
int verificaTamanho(const string& filename) {
    ifstream arquivo(filename);

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return -2; // Erro ao abrir o arquivo
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
        return -1; // Formato inválido
    }

    arquivo.close();

    return 1; // Tudo certo com a matriz
}

// Verifica possíveis ataques entre as rainhas
int check(const string& filename) {
    int tamanho = verificaTamanho(filename);
    if (tamanho == -1 || tamanho == -2) {
        return tamanho;
    }

    ifstream arquivo(filename);

    vector<string> linhas;
    string linha;
    while (getline(arquivo, linha)) {
        linhas.push_back(linha);
    }

    arquivo.close();

    // Lógica de verificação de ataques entre as rainhas
    // ...

    return 1; // Tudo certo ou solução encontrada
}

// Função chamada pelo testa_rainhas.cpp para verificar a solução das 8 rainhas
int verifica_solucao_8_rainhas(const string& filename) {
    int valor = check(filename);

    if (valor == -1) {
        cerr << "Matriz inválida." << endl;
    } else if (valor == -2) {
        cerr << "Erro ao abrir arquivo." << endl;
    } else if (valor == 0) {
        cout << "0" << endl; // Não é uma solução válida
    } else if (valor == 1) {
        cout << "1" << endl; // Solução válida
    }

    return valor;
}
