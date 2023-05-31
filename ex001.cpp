#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int jogadados();

int main()
{
    int joga1, joga2;
    int sentinela = 1;
    int cont = 1;

    srand(time(0));

    do{
        cout << "\nRodada numero: " << cont << ":\n";

        joga1= jogadados();
        cout << "\nO jogador 1 tirou: " << joga1 << endl;
        if (joga1 == 7)
        {
            cout <<"\nO jogador 2 ganhou pois a soma dos dados do jogador 1 deu 7\n" << endl;
            break;
        }
        if(joga1 == 21){
            cout <<"\nO jogador 1 ganhou pois a soma dos dados do jogador 1 deu 21\n" << endl;
            break;
        }
        joga2= jogadados();
        cout << "\nO jogador 2 tirou: " << joga2 << endl;
        if (joga2 == 7)
        {
            cout <<"\nO jogador 1 ganhou pois a soma dos dados do jogador 2 deu 7\n" << endl;
            break;
        }
        if(joga2 == 21){
            cout <<"\nO jogador 2 ganhou pois a soma dos dados do jogador 2 deu 21\n" << endl;
            break;
        }
        cont ++;
    }while (sentinela == 1);
    
    cout<< "O jogo teve: " << cont << " rodadas\n" << endl;

    return 0;
}

int jogadados(){
    int d1 = 0, d2 = 0, d3 = 0;
    d1 = rand()%7 + 1;
    d2 = rand()%7 + 1;
    d3 = rand()%7 + 1;
    cout << "\n[" << d1 << "]" << "[" << d2 << "]" << "[" << d3 << "]";
    int soma = d1+d2+d3;

    return soma;
}


