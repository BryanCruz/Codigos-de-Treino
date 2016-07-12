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
    vector<int> restantes;
    
    //inserção dos dados
    for (int linha = 0; linha < n; linha++){
        for (int coluna = 0; coluna < n; coluna++){
            cin >> rel[linha][coluna];
        }
    }
    
    //rel[aluno][relacoes]
    bool possivel = true;
    
    do{
    //coloca os alunos em um vetor, para ajudar no controle e, caso um aluno não tenha amigos,
    //não precisaremos considerar ele no calculo de ser possivel ou nao
    for (int linha = 0; linha < n; linha++) {
        int i = 0;
        for (int coluna = 0; coluna < n; coluna++){
            if (rel[linha][coluna] == 0){
                i++;
            }
        }
        if(i < n){
            restantes.push_back(linha);
        }
    }
    
    h1.push_back(restantes.at(0));
    restantes.erase(restantes.begin());
    
    int linha = 0;
    do{
            
        //verifica o aluno com todos os que já estão no horario 1
        int conth1 = 0;
        int conth2 = 0;
        int h1sizeaux = h1.size();
        int h2sizeaux = h2.size();
        for (int qt = 0; qt < h1sizeaux; qt++){
            if (rel[restantes.at(linha)][h1.at(qt)] == 1){
                if (h2.size() == 0){  //insere o primeiro item no 2° horario
                    h2.push_back(restantes.at(linha));
                    restantes.erase(restantes.begin() + linha);
                    linha = 0;
                    qt = h1sizeaux; //para o loop, pois ja usamos o item da linha atual
                }
                else{
                    for (int qt2 = 0; qt2 < h2.size(); qt2++){
                        if (rel[restantes.at(linha)][h2.at(qt2)] == 1){
                            linha = (restantes.size() + 1);
                        }
                        else{
                            conth2++;
                        }
                    }
                    if(conth2 == h2.size()){
                        h2.push_back(restantes.at(linha));
                        restantes.erase(restantes.begin() + linha);
                        linha = 0;
                    }
                    else{
                        possivel = false;
                    }
                }
            }
            else{
                conth1++;
            }
        }
        //verifica condições para ser colocado no horario 1
        if (conth1 == h1sizeaux){ 
            int verVacuidade = 0;
            int conth2n = 0;
            for (int qt = 0; qt < h2sizeaux; qt++){
                if(rel[restantes.at(linha)][qt] == 0){
                    conth2n++;
                }
            }
            //verifica se o aluno é amigo de pelo menos um do outro horario, 
            if((conth2n != h2.size())||(h2.size() == 0)){
                h1.push_back(restantes.at(linha));
                restantes.erase(restantes.begin() + linha);
                linha = 0;
            }else{
                linha++;
                if(linha >= restantes.size()){              //condição criada para evitar erros quando no vetor "restantes" sobraram somente itens 
                    h1.push_back(restantes.at(0));          //que interagem entre si, mas não com com os que ja estão nos vetores)
                    restantes.erase(restantes.begin());
                    linha = 0;
                }
            }
        }
    }while((restantes.size() > 0)&&(possivel == true));/*&&(linha < restantes.size())*/
    
    }while(1<0);
    if(restantes.size() == 0){
        cout << "SIM";
    }
    else{
        cout << "NAO";
    }
}
}
