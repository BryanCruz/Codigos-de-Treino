#include <iostream>
#include <stdlib.h>
using namespace std;


/*
Rulk soca um muro de blocos e causa dano a ele, 
sendo que quanto mais longe do soco, menos dano 
o bloco sofre.
Cada bloco (item da matriz) tem um grau de
quão destruído está, sendo os valores iniciais
definidos pelo usuário.

Exemplo:

Entrada: m = 4, n = 4 (tamanho da matriz)
         x = 2, y = 2

matriz = 10 10 10 10
         10 10 10 10
         10 10 10 10
         10 10 10 10
         
Saída =  19 19 19 18
         19 20 19 18
         19 19 19 18
         18 18 18 18
*/

int main(){
    int c, m, n, x, y;
    cin >> m >> n >> x >> y;
    x--;
    y--;
    int matriz[m][n];
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
            cin >> matriz[j][k];
        }
    }

    int difM,difN, maior;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
            difM = x - j;
            difN = y - k;
            if(abs(difM)>abs(difN)){
                maior = abs(difM);
            }else{
                maior = abs(difN);
            }
            
            if(maior < 10){
                matriz[j][k] += 10 - abs(maior);
            }else{
                matriz[j][k] += 1;
            }
        }
    }

    //exibicao
    cout << "Parede " << 1 << " :" << endl;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < n-1; k++) {
            cout << matriz[j][k] << " ";
        }
        cout << matriz[j][n-1] << endl;
    }
}
