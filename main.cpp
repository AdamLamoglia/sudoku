#include <iostream>

using namespace std;

int tabuleiro[9][9],x,y;

bool verificaLinha(int x,int n){
    for(int i = 0;i < 9;i++){

        if(tabuleiro[x][i] == n)
            return true;
    }
    return false;
}

bool verificaColuna(int y,int n){
    for(int i = 0;i < 9;i++){
        if(tabuleiro[i][y] == n)
            return true;
    }
    return false;
}

bool verificaQuadrante(int a,int b,int n){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(tabuleiro[i+a][j+b] == n)
                return true;
        }
    }
    return false;

}

bool verificaNumero(int x,int y,int n){
        if(verificaLinha(x,n))
            return true;
        if(verificaColuna(y,n))
            return true;
        if(verificaQuadrante(x - x%3,y - y%3,n))
            return true;

    return false;
}

bool verificaZero(){
    for(x = 0;x < 9;x++){
        for(y = 0;y < 9;y++){
            if(tabuleiro[x][y] == 0)
                return false;
        }
    }
    return true;
}

bool sudoku(int n){

    if(verificaZero()){
        return true;
    }

    int a = x,b = y;

    for(int k = 1;k <= 9;k++){
        if(verificaNumero(a,b,k)){
            continue;
        }

        tabuleiro[a][b] = k;

        if(sudoku(9))
            return true;

        tabuleiro[a][b] = 0;
    }
    return false;


}


int main(){
    int casosTeste;

    cin >> casosTeste;

    for(int k = 0;k < casosTeste;k++){

        for(int i = 0;i < 9;i++)
            for(int j = 0;j < 9;j++)
                cin >> tabuleiro[i][j];

        if(sudoku(9)){
            for(int i = 0;i < 9;i++){
                for(int j = 0;j < 9;j++){
                    if(j<8)
                        cout << tabuleiro[i][j] << " ";
                    else
                        cout << tabuleiro[i][j];
                }

                cout << endl;
            }
        }
        else
            cout << "No solution" << endl;
    }
}
