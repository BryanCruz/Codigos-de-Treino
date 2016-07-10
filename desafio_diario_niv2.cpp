#include <string>
#include <iostream>
using namespace std;

int main(){/*
    int resultado(int r){ 
        if(r == 0){ 
            cout<<"farsa" << endl;
            check = false; //exibe farsa e para o loop
        }
        else{
            cout << "consistente" << endl;
            check = false;
        }
    }*/
    bool check;
    string tex;
    int n = 0;
    do{
    n++;
    tex = "";
    cin >> tex;
    
    if(tex.length() <= 500){
    //getline (cin, tex);
    int contCoD = 0;
    int contCoE = 0;
    int contChD = 0;
    int contChE = 0;
    int extra = 0;      //contar quantos deslocamentos pra direita precisa ter para o loop não ser infinito
   
    for(string::size_type i = 0; i < tex.length(); i++){
        if(tex[i] == ('[')){
            contCoD++;
        }
        if(tex[i] == (']')){
            contCoE++;
        }
        if(tex[i] == ('{')){
            contChD++;
        }
        if(tex[i] == ('}')){
            contChE++;
        }
    }
    
  
    if((contCoD == contCoE)&&(contChD == contChE)
    &&(contCoD + contCoE + contChD + contChE == tex.length())) { //já admite como farsa se tiverem irregularidades na linha inserida
        do{
            check = true;
            string::size_type j = 0;
            j += extra;
            if ((tex[j]== '[')||(tex[j] == '{')){
                if(tex[j] == '['){
                    do {
                        j++;            //vai passando até encontrar um ]
                    }while(tex[j] != ']'); 
                    if(tex[j-1] == '['){
                        tex.erase ((j-1),2);
                        extra = 0;
                    }else{
                        if(tex[j-1] == '{'){
                            //resultado(0);
                            cout<<"farsa" << endl;
                            check = false; //exibe farsa e para o loop
                        }else{
                            extra++;
                        }
                    }
                }
                else{
                    do {
                        j++;            //vai passando até encontrar um }
                    }while(tex[j] != '}'); 
                    if(tex[j-1] == '{'){
                        tex.erase ((j-1),2);
                        extra = 0;
                    }
                    else{
                        if(tex[j-1] == '{'){
                            //resultado(0);
                            cout<<"farsa" << endl;
                            check = false; //exibe farsa e para o loop
                        }else{
                            extra++;
                        }
                    }
                }
                
                if(tex.length() == 0){  //zerar a string significa que foi consistente até o final
                    cout << "consistente" << endl;
                    check = false;
                }
            }
            else{
                cout<<"farsa" << endl;
                check = false; //exibe farsa e para o loop
            }
        }while(check == true);
    }
    
    else{
        cout << "farsa" << endl;
    }
    }
    }while((tex != "n") && (n < 100));
    cout<<"n";
    
}