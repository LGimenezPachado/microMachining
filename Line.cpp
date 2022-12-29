#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

void
ejeX (float a, float b, float c)
{
  for (int i = 0; i < c; i++)
    {

      float aux1 = b * float (i);
      float aux2 = a + aux1;
      float aux3 = 100 * aux2;
      float aux4 = floor (aux3);
      float aux5 = aux4 / 100;
      cout << "" << endl;
      cout << "Vuelta " << i << " de resultados del eje x: " << aux5 << endl;

    }
}

void
ejeY (float a, float b, float c)
{
  for (int i = 0; i < c; i++)
    {

      float aux1 = b * float (i);
      float aux2 = a + aux1;
      float aux3 = 100 * aux2;
      float aux4 = floor (aux3);
      float aux5 = aux4 / 100;
      cout << "" << endl;
      cout << "Vuelta " << i << " de resultados del eje y: " << aux5 << endl;

    }
}

void
bucle (float a, float b, float c, float d, float e, float f, float g)
{
  cout << "" << endl;
  cout << "COMIENZO DATOS EJE X" << endl;
  ejeX (a, e, g);
  cout << "" << endl;
  cout << "COMIENZO DATOS EJE Y" << endl;
  ejeY (b, f, g);
}

float
cuad (float x)
{
  return x * x;
}

void
PAUSE ()

{
  string cadena;
  cout << "Presione enter para comenzar a ingresar las coordenadas" << endl;
  getline (cin, cadena);
}

int
main ()
{
  float p, X0, Y0, XN, YN, D, Z, N1, N0, pY, pX;

  PAUSE ();


  cout << "Ingrese el paso" << endl;
  cin >> p;

  cout << "Ingrese el punto X incial" << endl;
  cin >> X0;

  cout << "Ingrese el punto Y inicial" << endl;
  cin >> Y0;

  cout << "Ingrese el punto X final" << endl;
  cin >> XN;

  cout << "Ingrese el punto Y final" << endl;
  cin >> YN;

  //Pitagoras
  float a = XN - X0;
  float c = cuad (a);

  float b = YN - Y0;
  float d = cuad (b);

  D = sqrt (c + d); //Hipotenusa

  Z = D / p;
  N1 = floor (Z) + 1;
  N0 = floor (Z);
  pY = (YN - Y0) / N0;
  pX = (XN - X0) / N0;

  if (X0==0 && Y0 == 0 && XN == 0 && YN == 0)
    {
        cout << "" << endl;
        cout << "Los datos ingresados son nulos" << endl;
    } else {

  bucle (X0, Y0, XN, YN, pX, pY, N1);
    }



  return 0;
}
