// GPA Analyzer (GPA)
// Abdullah Alrawi
// 02/20/2022
//cisp 400




#include<iostream>
using namespace std;
class Date
{
private:
  int DateDay;
  int DateMonth;
  int DateYear;
public:
// Specification A1 - Date class
void DateSet(int,int,int);
void Display ();
string DateInput ();
void componentTest();
};

void Date::DateSet(int Mon, int Dy, int Yr){
    DateMonth =Mon;
    DateDay = Dy;
    DateYear = Yr;
    
}

void Date::Display(){
    cout << DateMonth << "/" << DateDay << "/" << DateYear << endl;
}

string Date::DateInput(){
    return to_string(DateMonth) + "/" + to_string(DateDay) + "/" + to_string(DateYear);
}
// Specification A3 - Component Test Method in Date
void Date::componentTest(){
    Date test;
   test.DateSet(11,20,2002);
   if (test.DateInput() == "11/20/2002")
   cout << "passed" << endl;
   else
   cout << "failed" << endl;
}

void UnitTest();

// Specification A4 - Component Test Grade Conversion
void UnitTest() {
    Date TestDate;
    Date Beinging;
   TestDate.componentTest();
    Beinging.componentTest();
}


// Specification C1 - Program Greeting Function
void
programGreeting ()
{
    cout << "my greetings everyone, this program will calculate your GPA."<<endl;
      
     
     
    cout << endl;
      
     
     
    cout << "Abdullah Alrawi" << endl;
      
     
     
    cout << endl;
      
     
        
        cout << "FEB 20, 2022" << endl;
      
     
     
    cout << endl;

     
// Specification A2 - External date initialization
  UnitTest();
  Date TheDate;
  TheDate.DateSet(20, 02, 2022);
  TheDate.Display();
}

void
menu ()
{
    cout <<"1. Add Grade"<< endl;
    cout << endl;
    cout <<"2. Display All Grades"<< endl;
    cout << endl;
    cout <<"3. Process All Grades"<< endl;
    cout << endl;
    cout <<"4. Quit Program"<< endl;
    cout << endl;
    
}

// Specification B4 - Print Letter Grade
char
CalGpa (double score)
{
    if (score >= 90)
    return 'A';
  if (score >= 80)
    return 'B';
  if (score >= 70)
    return 'C';
  if (score >= 60)
    return 'D';
  return 'F';
}

int
main ()
{
  int UserChoice;
  int ArrSize = 0;
  double *GardeArr = NULL, *newGardeArr;
  double score;
  char LetterGrad;
  programGreeting ();
  do
    {
      while (1)
    {
      menu ();
      cout << "please pick (1-4): ";
        cout << endl;
      cin >> UserChoice;
      if (UserChoice >= 1 && UserChoice <= 4)
        break;
      cout << "Invalid input" << endl;
        cout << endl;
    }
      switch (UserChoice)
    {
    case 1:
      {
        cout << "Enter grade : ";
          cout << endl;
        cin >> score;
// Specification B1 - Dynamic Array
        newGardeArr = new double[ArrSize + 1];
//Specification B2 - Add Elements
        for (int i = 0; i < ArrSize; i++)
          newGardeArr[i] = GardeArr[i];
        if (GardeArr)
          delete GardeArr;
        GardeArr = newGardeArr;
        GardeArr[ArrSize++] = score;
        break;
      }
// Specification C2 - Print Scores
    case 2:
      {
        for (int i = 0; i < ArrSize; i++)
          {
        cout << GardeArr[i] << " ";
        // Specification C3 - Letter Grades
         if (GardeArr[i] >= 90)
                 cout << "A" << endl;
           else if (GardeArr[i] >= 80)
                cout << "B" << endl;
           else if (GardeArr[i] >= 70)
                 cout << "C" << endl;
           else if (GardeArr[i] >= 60)
                 cout << "D" << endl;
           else if (GardeArr[i] < 60)
                 cout << "F" << endl;
          }
        break;
      }
// Specification C4 - Compute GPA
    case 3:
      {
        double total = 0;
        for (int i = 0; i < ArrSize; i++)
          total += GardeArr[i];
        LetterGrad = CalGpa (total / ArrSize);
        cout << "GPA : "  << total / ArrSize << "%  " << LetterGrad << endl;
          cout << endl;
        break;
      }
    case 4:
      {
        break;
      }
// Specification B3 - Menu Input Validation
    default:
      {
        cout << "Invalid input" << endl;
          cout << endl;
        break;
      }

    }
    }while(UserChoice!=4);
  return 0;
}
