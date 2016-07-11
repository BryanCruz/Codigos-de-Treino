#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if((n >= 1) && (n <= 100)){
    int rel[n][n];
    vector<int> h1;
    vector<int> h2;
    
    //inserção dos dados
    for (int linha = 1; linha <= n; linha++){
        for (int coluna = 1; coluna <= n; coluna++){
            cin >> rel[linha][coluna];
        }
    }
    
    
    //rel[aluno][relacoes]
    bool possivel = true;
    
 //   do{
    int i = 0;
    h1.push_back(1);
    for (int linha = 2; linha <= n; linha++){
            
        //verifica o aluno com todos os que já estão no horario 1
        int conth1 = 0;
        int conth2 = 0;
        for (int qt = 0; qt < h1.size(); qt++){
            if (rel[linha][h1.at(qt)] == 1){
                if (h2.size() == 0){
                    h2.push_back(linha);
                }
                else{
                    for (int qt2 = 0; qt2 < h2.size(); qt2++){
                        if (rel[linha][h2.at(qt2)] == 1){
                            possivel = false;
                        }
                        else{
                            conth2++;
                        }
                    }
                    if(conth2 == h2.size()){
                        h2.push_back(linha);
                    }
                }
            }
            else{
                conth1++;
            }
        }
        if (conth1 == h1.size()){
            h1.push_back(linha);
        }
    }
  //  }while(possivel == false);
    if(possivel == true){
        cout << "SIM";
    }
    else{
        cout << "NAO";
    }
}
}