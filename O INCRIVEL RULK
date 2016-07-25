int main(){
    int c, m, n, x, y;
    //cin >> c;//numero de testes
   // array matrizes[c];
   
  // cin>> c;
    //testes
 //   for (int i = 0; i < c; i++) {
        
        //leitura e criacao do vetor
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
        //matri
        
        //exibicao
       // for (int i = 1; i <= c; i++) {
            cout << "Parede " << 1 << " :" << endl;
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n-1; k++) {
                    cout << matriz[j][k] << " ";
                }
                cout << matriz[j][n-1] << endl;
            }
       // }
//    }
   // }
}
