#include <iostream>

#include <cmath>

#include <math.h>

using namespace std;

float cosF(float X, int Y, int Z) {
    float aux_1, aux_2, aux_3, aux_4, aux_5, aux_6;

    aux_1 = cos(X);
    //cout << aux_1 << endl;
    aux_2 = aux_1 * float((-Y));
    //cout << aux_2 << endl;
    aux_3 = aux_2 / float(Z);
    //cout << aux_3 << endl;
    aux_4 = aux_3 * 100;
    //cout << aux_4 << endl;
    aux_5 = floor(aux_4);
    //cout << aux_5 << endl;
    aux_6 = aux_5 / 100;
    //cout << aux_6 << endl;
    return aux_6;

};

float
sinF(float X, int Y, int Z) {

    float aux_1, aux_2, aux_3, aux_4, aux_5, aux_6;

    aux_1 = sin(X);
    aux_2 = aux_1 * float(Y);
    aux_3 = aux_2 / float(Z);
    aux_4 = aux_3 * 100;
    aux_5 = floor(aux_4);
    aux_6 = aux_5 / 100;

    return aux_6;

};

float
bucle(int X, int Y, int A, int B) {

    int sY = Y, sA = A, sB = B;
    float aux_1, cosFS, sinFS, pcntaje, AUX;

    for (int i = 0; i <= X; i++) {

        aux_1 = (2 * M_PI) / X;
        AUX = i * aux_1;
        cosFS = cosF(AUX, sY, sA);
        sinFS = sinF(AUX, sY, sB);

        pcntaje = float(i) / float(X);
        pcntaje = pcntaje * 100;

        if (i == 0) {
            cout << "initial point" << "// [" << pcntaje << "% realized]" << endl;
            cout << cosFS << endl;
            cout << sinFS << endl;
        }

        if (pcntaje != 100 && i > 0) {

            cout << "round number " << i << "// [" << pcntaje << "% realized]" << endl;
            cout << cosFS << endl;
            cout << sinFS << endl;

            cout << "" << endl;
        } else if (pcntaje == 100) {
            cout << " final round" << "// [" << pcntaje << "% realized]" << endl;
            cout << cosFS << endl;
            cout << sinFS << endl;

        }

    }

    //cout << "Por lo tanto, el porcentaje total realizado es: " << pcntaje << endl;

    return 0;

};

int
main() {
    float per, Z, aux;
    int p, R, XC, YC, N;

    cout << "enter distance value" << endl;
    cin >> p;

    cout << "enter radio value" << endl;
    cin >> R;

    cout << "enter XC value" << endl;
    cin >> XC;

    cout << "enter YC value" << endl;
    cin >> YC;

    per = 2 * M_PI * R;
    Z = per / p;
    N = floor(Z);

    cout << "" << endl;
    cout << "the flux will be repeated  " << N << " times" << endl;
    cout << "" << endl;

    system("pause");
    cout << "" << endl;

    aux = bucle(N, R, XC, YC);

    return 0;
}
