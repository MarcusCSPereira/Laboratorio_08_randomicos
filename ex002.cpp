#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int cartas();
int naipe();
string nomenaipe(int n1);

int main(){
    
    int j1c, j2c, j3c, j4c, j1n, j2n, j3n, j4n, maiorc, maiorn, d1 = 0, d2 = 0;
    char opc;
    bool dupla1 = false, dupla2 = false;
    string winner, ncarta, maiornaipe;
    
    srand(time(0));

    system("cls");

    cout << "Jogo das cartas em dupla, ganha quem fizer 5 pontos\n" << endl;

    do{
        
        j1c = cartas();
        j1n = naipe();
        ncarta = nomenaipe(j1n);
        cout << "O jogador 1 tirou a carta: " << j1c << " de " << ncarta << endl;
        maiorc = j1c;
        maiorn = j1n;
        maiornaipe = ncarta;
        winner = "Jogador 1 ganhou / Pontos para dupla: 1";
        
        j2c = cartas();
        j2n = naipe();
        ncarta = nomenaipe(j2n);
        cout << "O jogador 2 tirou a carta: " << j2c << " de " << ncarta << endl;
        if(j2c > maiorc){
            maiorc = j2c;
            maiorn = j2n;
            maiornaipe = ncarta;
            winner = "Jogador 2 ganhou / Pontos para dupla: 1";
        }
        if(j2c == maiorc && j2n > maiorn){
            maiorc = j2c;
            maiorn = j2n;
            maiornaipe = ncarta;
            winner = "Jogador 2 ganhou / Pontos para dupla: 1";
        }
        
        
        j3c = cartas();
        j3n = naipe();
        ncarta = nomenaipe(j3n);
        cout << "O jogador 3 tirou a carta: " << j3c << " de " << ncarta << endl;
        if(j3c > maiorc){
            maiorc = j3c;
            maiorn = j3n;
            maiornaipe = ncarta;
            winner = "Jogador 3 ganhou / Pontos para dupla: 2";
        }
        if(j3c == maiorc && j3n > maiorn){
            maiorc = j3c;
            maiorn = j3n;
            maiornaipe = ncarta;
            winner = "Jogador 3 ganhou / Pontos para dupla: 2";
        }
        
        
        j4c = cartas();
        j4n = naipe();
        ncarta = nomenaipe(j4n);
        cout << "O jogador 4 tirou a carta: " << j4c << " de " << ncarta << endl;
        if(j4c > maiorc){
            maiorc = j4c;
            maiorn = j4n;
            maiornaipe = ncarta;
            winner = "Jogador 4 ganhou / Pontos para dupla: 2";
        }
        if(j4c == maiorc && j4n > maiorn){
            maiorc = j4c;
            maiorn = j4n;
            maiornaipe = ncarta;
            winner = "Jogador 4 ganhou / Pontos para dupla: 2";
        }
        
        
        if( (maiorc == j1c and maiorn == j1n) or (maiorc == j2c and maiorn == j2n) ){
            dupla1 = true;
        }
        if( (maiorc == j3c and maiorn == j3n) or (maiorc == j4c and maiorn == j4n) ){
            dupla2 = true;
        }

        
        if(dupla1 == true and dupla2 == true){
            winner = "Empate, nenhuma dupla ganhou ponto";
        }else if(dupla1 == true){
            d1++;
        }else if (dupla2 == true){
            d2++;
        }
        

        cout << "\nA maior carta foi: " << maiorc << " de " << maiornaipe << endl;
        cout << "\n"<< winner << endl;
        cout << "\nPontos da dupla 1: " << d1 << endl;
        cout << "\nPontos da dupla 2: " << d2 << endl;

        
        dupla1 = false;
        dupla2 = false;

        
        if(d1 == 5 or d2 == 5){
            break;
        }

        
        cout << "\nDeseja jogar novamente: [S]/[N]: ";
        cin >> opc;
        cout << endl;
        if(opc == 'n' or opc == 'N'){
            break;
        }

    }while(true);


    cout << "\nPlacar final: \n" << endl;
    cout << "Dupla 1 formada por Jogador 1 e Jogador 2: " << d1 << " pontos" << endl;
    cout << "Dupla 2 formada por Jogador 3 e Jogador 4: " << d2 << " pontos\n" << endl;
    
    if(d1 > d2){
        cout << "A Dupla 1 venceu o jogo das cartas\n" << endl;
    }else if(d2 > d1){
        cout << "A Dupla 2 venceu o jogo das cartas\n" << endl;
    }else{
        cout << "O jogo acabou em empate\n" << endl;
    }

}

int cartas(){
    int n1 = rand() % 10 + 1;
    return n1;
}

int naipe(){
    int n2 = rand() % 4 + 1;
    return n2;
}

string nomenaipe(int n1){

    if(n1 == 1){
    return "Ouros";
    }
    if(n1 == 2){
        return "Espadilha";
    }
    if(n1 == 3){
        return "Copas";
    }
    if(n1 == 4){
        return "Paus";
    }
    return "";
}