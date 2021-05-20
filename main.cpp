#include <iostream>

using std::cout;
using std::endl;

double funcX(double x);
double limite(char lado, double tende, double difInicial, double acuracia);
void existeLimite(double tende);

int main() {
    cout << "f(x) = (6x²+11x+3)/(2x²-5x-12)" << endl;
    cout << "Quando f(x) tende a " << -1.5 << ": " << endl;
    existeLimite(-1.5);
    return 0;
}
//Função que séra usada no limite
double funcX(double x) {
    return ((6*x*x+11*x+3)/(2*x*x-5*x-12));
}
//Cálculo do limite
double limite(char lado, double tende, double difInicial, double acuracia) {
    double x, h;
    switch (lado)
    {
    case 'e':
        x = tende - difInicial;
        do {
            h = tende-x;
            x += h/2;
        }while(h > acuracia);
        break;
    case 'd':
        x = tende + difInicial;
        do {
            h = x-tende;
            x -= h/2;
        }while(h > acuracia);
        break;
    default:
        cout << "ERRO: Opção inválida!" << endl;
        break;
    }
    return funcX(x);
}
void existeLimite(double tende){
    double esquerda = limite('e', tende, 0.002, 0.000000001);
    double direita = limite('d', tende, 0.002, 0.000000001);
    if(esquerda == direita) {
        cout << "O limite existe e é " << direita << endl;
    } else {
        cout << "Limite da esquerda é " << esquerda << endl;
        cout << "Limite da direita é " << direita << endl;
        cout << "Portanto, o limite não existe!" << endl;
    }
}
