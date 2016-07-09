#include <iostream>
using namespace std;
int main() {
    
    int n, k;
    
    cin >> n >> k;
    
    bool verif = true;
    int colunas[k];
    int peso[n];
    int qtItensCol[k];
    int sequencia[n];
    int somaCol;
    int qtItensAux;
    
    //inserção dos pesos
    for (int i = 0; i<n; i++){
        cin >> peso[i];
    }
    
    for (int i = 0; i<k; i++){
        qtItensCol[i] = 0;
    }
    
    
    for(int nfor = 0; nfor < n; nfor++){ //passar por cada item
        for (int col = 0; col < k; col++){ //passar por cada coluna
            
            //caso não tenha itens na coluna
            if(qtItensCol[col] == 0){
                sequencia[nfor] = col;
                col = k; //para finalizar o for
                qtItensCol[col]++;
            }
                
            else{
                qtItensAux = qtItensCol[col];
                int pesosAux[(qtItensCol[col])];
                
                //atribuição dos valores ao vetor pesosAux[]
                for(int z = (nfor-1); z >= 0; z--){
                    if(sequencia[z] == col){
                        qtItensAux--;
                        pesosAux[qtItensAux] = peso[z];
                    }
                }
                    
                //comparação do peso atual com os alocados
                //qt de verificações
                
                somaCol = peso[nfor];
                    
                int i2 = (qtItensCol[col] - 1);
                    
                do{
                    if(somaCol <= pesosAux[i2]){
                        if (i2 == 0){
                            sequencia[nfor] = col;
                            col = k;
                            qtItensCol[col]++;
                        }
                        
                        else{
                            somaCol = somaCol + pesosAux[i2];
                            
                        }
                        i2--;
                    }
                    else{
                        //caso o número de colunas disponiveis acabe
                            if(col == (k-1)){
                                verif = false;
                                nfor = n;
                            }
                            i2 = -1;
                        }
                        
                    }while(i2 >= 0);
                }       
            }
        }
    
    if(verif == true){
        for(int d = 0; d < n; d++){
            cout << sequencia[d];
        }
    }
    else{
        cout << "IMP";
    }
    return 0;
}