#include <iostream>
using namespace std;
int main() {
    
    int n, k, pesoCol, qtItensAux, col;
    bool verif = true;
    
    cin >> n >> k;

    if ((n >= 1)&&(n<=5000)&&(k>=1)&&(k<=2000)){
    int peso[n];
    int qtItensCol[k];
    int sequencia[n];
    
    
    //inserção dos pesos
    
    bool checarPeso = true;
    for (int i = 0; i<n; i++){
        cin >> peso[i];
        if ((peso[i] < 1) || (peso[i] > 500)){
            checarPeso = false;
        }
    }
    
    if (checarPeso = true){
    for (int i = 0; i<k; i++){
        qtItensCol[i] = 0;
    }
    
    
    for(int nfor = 0; nfor < n; nfor++){ //passar por cada item
        col = 0;
        
        do{ //passar por cada coluna
           
            //caso não tenha itens na coluna
            if(qtItensCol[col] > 0){
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
                
                pesoCol = peso[nfor];
                    
                int i2 = (qtItensCol[col] - 1);
                    
                do{
                    if(pesoCol <= pesosAux[i2]){
                        if (i2 != 0){                         //se o loop chegou em zero e passou pela condiçao, significa que a nova caixa pode ser colocada naquela coluna
                            pesoCol = pesoCol + pesosAux[i2]; //adiciona o peso da proxima caixa no topo para verificar da proxima vez que o loop rodar
                        }
                        else{
                            sequencia[nfor] = col;
                            qtItensCol[col]++;
                            col = k; //finaliza o loop
                        }
                        i2--;
                    }
                    else{
                        
                        //caso o número de colunas disponiveis acabe
                            if(col == (k-1)){
                                verif = false;
                                nfor = n;
                            }
                            col++;
                        i2 = -1;
                    }
                        
                }while(i2 >= 0);
            }
                
            else{
                qtItensCol[col] = 1;
                sequencia[nfor] = col;
                col = k; //para finalizar o loop
            }       
        }while(col < k);
    }
    
    if(verif == true){
        for(int d = 0; d < n; d++){
            cout << sequencia[d] + 1 << " ";
        }
    }
    else{
        cout << "IMP";
    }
}
}
}