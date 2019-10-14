#include<bits/stdc++.h>

using namespace std;

vector < vector <int> > cadenas;
vector <int> numerosPrimos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int casos = 0;

void imprimirVector(vector <int> &res) {

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (res.size() != i+1) cout << ' ';
    }

}

void imprimirResultados() {

    for (int i = 0; i < cadenas.size(); ++i) {
        imprimirVector(cadenas[i]);
        cout << endl;
    }

}

bool anilloPrimo(vector <int> &posibleCadena) {

    for (int i = 0; i < (posibleCadena.size()) - 1; ++i) {
        int evaluar = posibleCadena[i] + posibleCadena[i+1];
        auto it = std::find(numerosPrimos.begin(), numerosPrimos.end(), evaluar);
        if (it == numerosPrimos.end()) {
            return false;
        }
    }
    int evaluar = posibleCadena[0] + posibleCadena[posibleCadena.size() - 1];
    auto it = std::find(numerosPrimos.begin(), numerosPrimos.end(), evaluar);
    if (it == numerosPrimos.end()) {
        return false;
    }
    return true;

}

void generarCombinaciones(vector <int> &valores) {

    do {
        if (valores[0] != 1) break;
        if (anilloPrimo(valores)) {
            cadenas.push_back(valores);
        }
    } while (std::next_permutation(valores.begin(), valores.end()));

}

void crearAnillo(int &size) {

    vector <int> valores;
    cadenas.clear();
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
        imprimirResultados();
        cout << endl;
    }

    return 0;

}