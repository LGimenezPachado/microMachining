#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

//DEFINITION OF FUNCTIONS

void line (float m, float n, float o, float p, float q);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//BEGIN OF PARALLEPIPED DETERMINATION

void
flatSeq (float a, float b, float c, float d, float e, float f, float g,
	 float h, float i)
//Consists of one or more subdiagrams, or frames, that execute sequentially. Use the Flat Sequence structure to ensure that a subdiagram executes before or after another subdiagram.
{

  //first out
  float aux1 = a + e;
  float aux2 = aux1 + g;
  cout << "first output: " << aux2 << endl;;

  //second out
  float aux3 = b + f;
  float aux4 = aux2 + h;
  cout << "second output: " << aux4 << endl;

  //third out
  float aux5 = c - e;
  float aux6 = aux5 + g;
  cout << "third output: " << aux6 << endl;

  //fourth out
  float aux7 = d - f;
  float aux8 = aux7 + h;
  cout << "fourth output: " << aux8 << endl;

  line (aux2, aux4, aux6, aux8, i);
}




void
loop (float a /*X0 */ , float b /*Y0 */ , float c, float d, float e,
      float f /*Y2 */ , float g /*N*/, float h,
      float i, float j, float k, float l, float m, float n)
{

  //getting ready X2
  float aux1 = c + e;
  float aux2 = aux1 - a;

  //getting ready Y2
  float aux3 = f + d;
  float aux4 = aux3 - b;

  for (int iC = 0; iC <= g; iC++)
    {

      float aux1 = h * iC;
      float aux2 = j * iC;
      float aux3 = i * iC;
      float aux4 = k * iC;

      cout << "round number " << iC << endl;
      flatSeq (a, b, c, d, aux1, aux2, aux3, aux4, n);
      cout << "" << endl;

    }

}


float
cuad (float x)
{
  return x * x;
}



float
cmp (float a, float b)
{
  if (a < b)
    {
      return a;

    }
  else if (a > b)
    {
      return b;

    }
  else
    {
      cout << "the values are the same" << endl;
      return 0;
    }

}

void
pause ()
{
  string cdn;
  cout << "press enter to begin" << endl;
  getline (cin, cdn);
}

//END OF PARALLEPIPED DETERMINATION

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//BEGIN OF LINE WITHOUT INITIAL POINT DETERMINATION

void
xAxis (float a, float b, float c)
{
  for (int i = 0; i < c; i++)
    {

      float aux1 = b * float (i);
      float aux2 = a + aux1;
      float aux3 = 100 * aux2;
      float aux4 = floor (aux3);
      float aux5 = aux4 / 100;
      cout << "round " << i << " of x axis results " << aux5 << endl;

    }
}


void
yAxis (float a, float b, float c)
{
  for (int i = 0; i < c; i++)
    {

      float aux1 = b * float (i);
      float aux2 = a + aux1;
      float aux3 = 100 * aux2;
      float aux4 = floor (aux3);
      float aux5 = aux4 / 100;
      cout << "round " << i << " of y axis results: " << aux5 << endl;

    }

  cout << "" << endl;
  cout << "///////////////////////////////////////////////////////" << endl;

}


void
lineLoop (float a, float b, float c, float d, float e, float f, float g)
{
  cout << "" << endl;
  cout << "x axis begin" << endl;
  xAxis (a, e, g);
  cout << "" << endl;
  cout << "y axis begin" << endl;
  yAxis (b, f, g);
}



void
line (float m, float n, float o, float p, float q)
{

  //Pythagoras
  float a = o - m;
  float c = cuad (a);

  float b = p - n;
  float d = cuad (b);

  float D = sqrt (c + d);	//Hypotenuse

  float Z = D / q;
  float N1 = floor (Z) + 1;
  float N0 = floor (Z);
  float pX = (o - m) / N0;
  float pY = (p - n) / N0;


  if (m == 0 && n == 0 && o == 0 && p == 0)
    {
      cout << "" << endl;
      cout << "The data entered is null" << endl;
    }
  else
    {

      lineLoop (m, n, o, p, pX, pY, N1);
    }
}

//END OF PARALLEPIPED DETERMINATION

int
main ()
{
  float p, X0, Y0, X1, Y1, X2, Y2, D1, D2, Z1, Z2, N1, N2;

  pause ();


  cout << "enter distance value" << endl;
  cin >> p;

  if (p >= 0)
    {
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
      cout << "///////////////////////////////////////////////////////" <<
	endl;
      cout << "" << endl;


      // X1
      float a = X1 - X0;
      float c = cuad (a);

      float b = Y1 - Y0;
      float d = cuad (b);

      D1 = sqrt (c + d);

      Z1 = D1 / p;

      N1 = floor (Z1) + 1;

      float dX1 = (X1 - X0) / (N1 - 1);
      float dY1 = (Y1 - Y0) / (N1 - 1);

      //X2

      float e = X2 - X0;
      float g = cuad (e);

      float f = Y2 - Y0;
      float h = cuad (f);

      D2 = sqrt (g + h);

      Z2 = D2 / p;

      N2 = floor (Z2) + 1;

      float dX2 = (X2 - X0) / (N2 - 1);
      float dY2 = (Y2 - Y0) / (N2 - 1);


      //TOTAL

      float p1 = D1 / (N1 - 1);
      float p2 = D2 / (N2 - 1);


      float N = cmp (N1, N2);

      loop (X0, Y0, X1, Y1, X2, Y2, N, dX1, dY1, dX2, dY2, p1, p2, p);


    }
  else
    {
      cout << "" << endl;
      cout << "the value of the distance can not be negative" << endl;
    }


  return 0;
}
