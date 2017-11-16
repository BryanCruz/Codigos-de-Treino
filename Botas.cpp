int main(){
    int n,m, qt;
    char l;
    bool rodando;
    //cin >> n;
    while(cin>>n){
        
        vector<int> tamanhos;
        vector<char> lados;
        rodando = true;
        
        for (int i = 0; i < n; i++) {
            cin >> m >> l;
            tamanhos.push_back(m);
            lados.push_back(l);
        }
        
        int q = 0;
        qt = 0;
        while(rodando){
            for (int j = q+1; j < n; j++) {
                if(tamanhos.at(q)==tamanhos.at(j)){
                    if(lados.at(q)!=lados.at(j)){
                        qt++;
                        tamanhos.erase(tamanhos.begin()+j);
                        tamanhos.erase(tamanhos.begin()+q);
                        lados.erase(lados.begin()+j);
                        lados.erase(lados.begin()+q);
                        q = 0;
                        j = n;
                    }
                }
                if(j == n-1){
                    q++;
                }
            }
            
            if((q == (tamanhos.size()-1))||(tamanhos.size()<=1)){
                    rodando = false;
                }
        }
        
        cout << qt << endl;
    }
}
