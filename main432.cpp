// Final Project
// Abdullah Alrawi
// 05/18/2022
//cisp 400



#include <cstdlib>

#include <iostream>

#include <string>

#include <functional>

using namespace std;

class Date {

  friend ostream & operator << (ostream & osObject,
    const Date & rec);

  friend istream & operator >> (istream & isObject, Date & rec);

  private:
    int DateDay;

  int DateMonth;

  int DateYear;

  public:

    Date();

  Date(int D, int M, int Y) {

    DateDay = D;

    DateMonth = M;

    DateYear = Y;

  }
};

ostream & operator << (ostream & osObject,
  const Date & rec) {

  osObject << rec.DateDay << " / " << rec.DateMonth << " / " << rec.
  DateYear << endl;

  return osObject;

}

istream & operator >> (istream & isObject, Date & rec) {

  cout << " enter the day: ";

  isObject >> rec.DateDay;

  cout << " enter the month: ";

  isObject >> rec.DateMonth;

  cout << " enter the year: ";

  isObject >> rec.DateYear;

  return isObject;

}

class TheIA {
  private:
    int pole[5][17];
  int PowerCharge = 5;
  int LifeTIme = 0;
  int TheField[12][12];
  int BatteryPercent = 40;
  int M;
  int N;

  public:
    TheIA();
  TheIA(TheIA First, TheIA second);
  int Proceed();
  int LifeTimeIn();
  int PowerChargeIn();
};
TheIA::TheIA() {
  for (int p = 0; p < 12; p++) {
    for (int v = 0; v < 12; v++) {
      if (p == 0 || p == 11 || v == 0 || v == 11) {
        TheField[p][v] = 1;
      } else {
        if (BatteryPercent != 0) {
          int Position = (rand() % 3);
          if (Position == 2) {
            BatteryPercent--;
          }
          TheField[p][v] = Position;
        } else {
          TheField[p][v] = ( rand() % 2 );
        }
      }
    }
  }

  for (int p = 1; p < 11; p++) {
    for (int v = 1; v < 11; v++) {
      if (TheField[p][v] == 0) {
        M = p;
        N = v;
        p = 11;
      }
    }
  }

  pole[0][16] = ( 4 );
  pole[1][16] = ( 4 );
  pole[2][16] = ( 4 );
  pole[3][16] = ( 4 );
  pole[4][16] = ( 4 );

  for (int p = 0; p < 16; p++) {
    pole[0][p] = ( rand() % 3 );
    pole[1][p] = ( rand() % 3 );
    pole[2][p] = ( rand() % 3 );
    pole[3][p] = ( rand() % 3 );
    pole[4][p] = ( rand() % 4 );
  }
}

TheIA::TheIA(TheIA First, TheIA second) {
  for (int p = 0; p < 12; p++) {
    for (int v = 0; v < 12; v++) {
      if (p == 0 || p == 11 || v == 0 || v == 11) {
        TheField[p][v] = 1;
      } else {
        TheField[p][v] = ( rand() % 3 );
      }
    }
  }

  for (int p = 0; p < 8; p++) {
    pole[0][p] = ( First.pole[0][p] );
    pole[1][p] = ( First.pole[1][p] );
    pole[2][p] = ( First.pole[2][p] );
    pole[3][p] = ( First.pole[3][p] );
    pole[4][p] = ( First.pole[4][p] );

    pole[0][p + 8] = ( second.pole[0][p + 8] );
    pole[1][p + 8] = ( second.pole[1][p + 8] );
    pole[2][p + 8] = ( second.pole[2][p + 8] );
    pole[3][p + 8] = ( second.pole[3][p + 8] );
    pole[4][p + 8] = ( second.pole[4][p + 8] );
  }

  if ((rand() % 20) == 1) {
    pole[4][0] = ( rand() % 4 );
    pole[4][4] = ( rand() % 4 );
    pole[4][8] = ( rand() % 4 );
    pole[4][12] = ( rand() % 4 );
  }

  for (int p = 1; p < 11; p++) {
    for (int v = 1; v < 11; v++) {
      if (TheField[p][v] == 0) {
        M = p;
        N = v;
        p = 11;
      }
    }
  }
}

int
TheIA::Proceed() {
  int EndingCharge = 0;
  while (PowerCharge != 0) {
    PowerCharge--;
    LifeTIme++;

    int Up = TheField[M][N - 1];
    int Right = TheField[M + 1][N];
    int Down = TheField[M][N + 1];
    int Left = TheField[M - 1][N];

    int Shift = 16;
    for (int p = 0; p < 16; p++) {
      if (pole[0][p] == Up && pole[1][p] == Right &&
        pole[2][p] == Down && pole[3][p] == Left) {
        Shift = p;
        p = 16;
      }
    }

    if (pole[4][Shift] == 0 && Up != 1) {
      if (Up == 2) {
        PowerCharge = PowerCharge + 5;
        EndingCharge = EndingCharge + PowerCharge;
        TheField[M][N - 1] = 0;
      }
      N--;
    } else if (pole[4][Shift] == 1 && Right != 1) {
      if (Right == 2) {
        PowerCharge = PowerCharge + 5;
        EndingCharge = EndingCharge + PowerCharge;
        TheField[M + 1][N] = 0;
      }
      M++;
    } else if (pole[4][Shift] == 2 && Down != 1) {
      if (Down == 2) {
        PowerCharge = PowerCharge + 5;
        EndingCharge = EndingCharge + PowerCharge;
        TheField[M][N + 1] = 0;
      }
      N++;
    } else if (pole[4][Shift] == 3 && Left != 1) {
      if (Left == 2) {
        PowerCharge = PowerCharge + 5;
        EndingCharge = EndingCharge + PowerCharge;
        TheField[M - 1][N] = 0;
      }
      M--;
    }
  }
  return EndingCharge;
}

int
TheIA::LifeTimeIn() {
  return LifeTIme;
}

int
TheIA::PowerChargeIn() {
  return PowerCharge;
}

void programGreeting();

int
main() {
  Date dt(11, 11, 11);

  cout << dt;

  cin >> dt;

  cout << dt;

  programGreeting();

  srand(time(NULL));
  TheIA IA[200];
  int TotalGenarations = 1000;
  int GenTime = 0;
  int TheCharge = 0;
  int EndingCharge = 0;
  float FitAve = 0.0;

  cout << endl;

  for (int B = 0; B < TotalGenarations; B++) {
    GenTime = 0;

    for (int IAOrder = 0; IAOrder < 200; IAOrder++) {
      TheCharge = IA[IAOrder].Proceed();
      GenTime = GenTime + IA[IAOrder].LifeTimeIn();
      EndingCharge = EndingCharge + TheCharge;
    }

    for (int Z = 0; Z < 200; Z++) {
      TheIA Store = IA[Z];
      int v = Z - 1;
      while (v >= 0 && Store.LifeTimeIn() >= IA[v].LifeTimeIn()) {
        IA[v + 1] = IA[v];
        v = v - 1;
      }
      IA[v + 1] = Store;
    }

    FitAve = EndingCharge / 1000;
    cout << "-------------";
    cout << endl;
    cout << "GEN #:" << (B + 1) << endl;
    cout << endl;
    cout << "Mean Fitness: " << FitAve / 100 << endl;
    cout << endl;
    cout << "-------------";
    cout << endl;

    for (int IAOrder = 0; IAOrder < 100; IAOrder = IAOrder + 2) {
      IA[IAOrder + 100] = TheIA(IA[IAOrder], IA[IAOrder + 1]);
      IA[IAOrder + 101] = TheIA(IA[IAOrder + 1], IA[IAOrder]);
    }
  }
  cout << endl;
  cout << "GEN  Mean Fitness";
  cout << endl;

  for (int B = 0; B < TotalGenarations; B++) {
    GenTime = 0;

    for (int IAOrder = 0; IAOrder < 200; IAOrder++) {
      TheCharge = IA[IAOrder].Proceed();
      GenTime = GenTime + IA[IAOrder].LifeTimeIn();
      EndingCharge = EndingCharge + TheCharge;
    }

    for (int Z = 0; Z < 200; Z++) {
      TheIA Store = IA[Z];
      int v = Z - 1;
      while (v >= 0 && Store.LifeTimeIn() >= IA[v].LifeTimeIn()) {
        IA[v + 1] = IA[v];
        v = v - 1;
      }
      IA[v + 1] = Store;
    }

    FitAve = EndingCharge / 1000;
    cout << (B + 1) << "  " << string(FitAve / 100, '*') << endl;

    for (int IAOrder = 0; IAOrder < 100; IAOrder = IAOrder + 2) {
      IA[IAOrder + 100] = TheIA(IA[IAOrder], IA[IAOrder + 1]);
      IA[IAOrder + 101] = TheIA(IA[IAOrder + 1], IA[IAOrder]);
    }
  }
}

void
programGreeting() {

  cout <<
    "my greetings everyone, this program will run an experiment on generations of robots." <<
    endl;

  cout << endl;

  cout << "Abdullah Alrawi" << endl;

  cout << endl;
}