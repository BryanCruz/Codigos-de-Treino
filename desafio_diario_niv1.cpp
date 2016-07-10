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
    if((contD == contE)&&(contD + contE == tex.length())) {
        
        do{
            string aux = tex;
            string::size_type j = 0;
            if (tex[j]== '['){
                do {
                    j++;
                }while(tex[j] == '[');
                
                if(tex.length() == 2){
                    cout << "consistente" << endl;
                    tex.erase (0,2);
                }else{
                    tex.erase ((j-1),2);
                }
            }
            else{
                cout<<"farsa" << endl;
                check = false;
            }
            
            if(tex.length() == 0){
                check = false;
            }
        }while(check == true);
    }
    
    else{
        cout << "farsa" << endl;
    }
    
    }while(tex != "n");
    
}