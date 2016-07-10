#include <string>
#include <iostream>
using namespace std;

int main(){
    bool check;
    string tex;
    
    do{
    tex = "";
    cin >> tex;
    
    //getline (cin, tex);
    int contD = 0;
    int contE = 0;
   
    for(string::size_type i = 0; i < tex.length(); i++){
        if(tex[i] == ('[')){
            contD++;
        }
        if(tex[i] == (']')){
            contE++;
        }
    }
    
    if((contD == contE)&&(contD + contE == tex.length())) { //já admite como farsa se tiverem irregularidades na linha inserida
        do{
            check = true;
            string::size_type j = 0;
            if (tex[j]== '['){
                do {
                    j++;            //vai passando até encontrar um ]
                }while(tex[j] == '['); 
                
                tex.erase ((j-1),2);
                if(tex.length() == 0){  //zerar a string significa que foi consistente até o final
                    cout << "consistente" << endl;
                    tex.erase (0,2);
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
    
    }while(tex != "n");
    cout<<"n";
    
}