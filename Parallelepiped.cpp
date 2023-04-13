#include <iostream>

#include <math.h>

#include <cmath>

using namespace std;

void
flatSeq(float a, float b, float c, float d, float e, float f, float g,
    float h)
//Consists of one or more subdiagrams, or frames, that execute sequentially. Use the Flat Sequence structure to ensure that a subdiagram executes before or after another subdiagram.
{

    //first out
    float aux1 = a + e;
    float aux2 = aux1 + g;
    cout << "first out: " << aux2 << endl;;

    //second out
    float aux3 = b + f;
    float aux4 = aux2 + h;
    cout << "second out: " << aux4 << endl;

    //third out
    float aux5 = c - e;
    float aux6 = aux5 + g;
    cout << "third out: " << aux6 << endl;

    //fourth out
    float aux7 = d - f;
    float aux8 = aux7 + h;
    cout << "fourth out: " << aux8 << endl;

}

void
bucle(float a /*X0 */ , float b /*Y0 */ , float c, float d, float e,
    float f /*Y2 */ , float g /*N*/ , float h,
    float i, float j, float k, float l, float m) {

    //getting ready X2
    float aux1 = c + e;
    float aux2 = aux1 - a;

    //getting ready Y2
    float aux3 = f + d;
    float aux4 = aux3 - b;

    for (int iC = 0; iC <= g; iC++) {

        float aux1 = h * iC;
        float aux2 = j * iC;
        float aux3 = i * iC;
        float aux4 = k * iC;

        //  cout << "round number " << iC << endl;
        //flatSeq (a, b, c, d, aux1, aux2, aux3, aux4);
        //cout << "" << endl;

        float pcntaje = float(iC) / float(g);
        pcntaje = pcntaje * 100;

        if (iC == 0) {
            cout << "" << endl;

            cout << "initial point" << " // [" << pcntaje << "% realized]" << endl;
            cout << "" << endl;

            //cout << cosFS << endl;
            //cout << sinFS << endl;
            flatSeq(a, b, c, d, aux1, aux2, aux3, aux4);
            cout << "" << endl;

        }

        if (pcntaje != 100 && iC > 0) {

            cout << "round number " << iC << " // [" << pcntaje << "% realized]" << endl;
            cout << "" << endl;

            //cout << cosFS << endl;
            //cout << sinFS << endl;
            flatSeq(a, b, c, d, aux1, aux2, aux3, aux4);
            cout << "" << endl;

            cout << "" << endl;
        } else if (pcntaje == 100) {
            cout << "final round" << " // [" << pcntaje << "% realized]" << endl;
            cout << "" << endl;

            //cout << cosFS << endl;
            //cout << sinFS << endl;
            flatSeq(a, b, c, d, aux1, aux2, aux3, aux4);
            cout << "" << endl;

        }

    }

}

float
cuad(float x) {
    return x * x;
}

float
cmp(float a, float b) {
    if (a < b) {
        return a;

    } else if (a > b) {
        return b;

    } else {
        cout << "the values are the same" << endl;
        return 0;
    }

}

int
main() {
    float p, X0, Y0, X1, Y1, X2, Y2, D1, D2, Z1, Z2, N1, N2;

    cout << "enter distance value" << endl;
    cin >> p;

    cout << "enter X0 value" << endl;
    cin >> X0;

    cout << "enter Y0 value" << endl;
    cin >> Y0;

    cout << "enter X1 value" << endl;
    cin >> X1;

    cout << "enter Y1 value" << endl;
    cin >> Y1;

    cout << "enter X2 value" << endl;
    cin >> X2;

    cout << "enter Y2 value" << endl;
    cin >> Y2;
    cout << "" << endl;

    system("pause");
    // X1
    float a = X1 - X0;
    float c = cuad(a);

    float b = Y1 - Y0;
    float d = cuad(b);

    D1 = sqrt(c + d);

    Z1 = D1 / p;

    N1 = floor(Z1) + 1;

    float dX1 = (X1 - X0) / (N1 - 1);
    float dY1 = (Y1 - Y0) / (N1 - 1);

    //X2

    float e = X2 - X0;
    float g = cuad(e);

    float f = Y2 - Y0;
    float h = cuad(f);

    D2 = sqrt(g + h);

    Z2 = D2 / p;

    N2 = floor(Z2) + 1;

    float dX2 = (X2 - X0) / (N2 - 1);
    float dY2 = (Y2 - Y0) / (N2 - 1);

    //TOTAL

    float p1 = D1 / (N1 - 1);
    float p2 = D2 / (N2 - 1);

    float N = cmp(N1, N2);

    bucle(X0, Y0, X1, Y1, X2, Y2, N, dX1, dY1, dX2, dY2, p1, p2);

    return 0;
}
