#include<bits/stdc++.h>

using namespace std;
 
int caso = 0;
int rangoAnillo;
int totalCadena[20];
bool esUsado[20];

bool esPrimo(int numero) {
    for(int i = 2; i <= sqrt(numero); i++) {
        if(numero % i == 0) {
            return false;
        }
    }
    return true;
}
 
void buscarCombinacion(int posicionEstable) {
    if(posicionEstable == rangoAnillo - 1 && esPrimo(totalCadena[rangoAnillo - 1] + totalCadena[rangoAnillo])) {
        for(int i = 0; i < rangoAnillo; i++) {
            //printf(i == rangoAnillo - 1? "%d" : "%d ", totalCadena[i]);
            cout << totalCadena[i];
            if (i != rangoAnillo - 1) {
                cout << ' ';
            }
        }
        cout << endl;
        return;
    }
    for(int i = 2; i <= rangoAnillo; i++) {
        if(!esUsado[i] && esPrimo(totalCadena[posicionEstable] + i)) {
            esUsado[i] = true;
            totalCadena[posicionEstable + 1] = i;
            buscarCombinacion(posicionEstable + 1);
            esUsado[i] = false;
        }
    }
}
 
int main() {
    while(scanf("%d", &rangoAnillo) == 1) {
        caso++;
        if(caso > 1) {
            cout << endl;
        }
        totalCadena[0] = totalCadena[rangoAnillo] = 1;
        cout << "Case " << caso << ":" << endl;
        buscarCombinacion(0);
    }
}