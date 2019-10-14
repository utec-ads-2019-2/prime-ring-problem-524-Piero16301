#include<bits/stdc++.h>

using namespace std;

vector <int> numerosPrimos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int casos = 0;

void imprimirVector(vector <int> &res) {

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (res.size() != i+1) cout << ' ';
    }

}

bool esPrimo(int &num) {

    for (int i = 0; i < numerosPrimos.size(); ++i) {
        if (num < numerosPrimos[i]) {
            return false;
        }
        if (num == numerosPrimos[i]) {
            return true;
        }
    }
    return false;

}

bool anilloPrimo(vector <int> &posibleCadena) {

    int evaluar = posibleCadena[0] + posibleCadena[posibleCadena.size() - 1];
    if (!esPrimo(evaluar)) {
        return false;
    }
    for (int i = 0; i < (posibleCadena.size()) - 1; ++i) {
        int evaluar = posibleCadena[i] + posibleCadena[i+1];
        if (!esPrimo(evaluar)) {
            return false;
        }
    }
    return true;

}

void generarCombinaciones(vector <int> &valores) {

    do {
        if (valores[0] != 1) break;
        if (anilloPrimo(valores)) {
            imprimirVector(valores);
            cout << endl;
        }
    } while (std::next_permutation(valores.begin(), valores.end()));

}

void crearAnillo(int &size) {

    vector <int> valores;
    for (int i = 1; i <=size; ++i) {
        valores.push_back(i);
    }
    generarCombinaciones(valores);

}

int main() {
    
    int numero;
    while(scanf("%d", &numero) == 1) {
        cout << "Case " << ++casos << ':' << endl;
        crearAnillo(numero);
        cout << endl;
    }

    return 0;

}