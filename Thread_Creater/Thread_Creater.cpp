// Thread_Creater.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void stepsPerThread(const int* arrayPointer, vector<int>& stepsVector);
void createFile(const int* arrayPointer, const vector<int>& stepsVector);

int main() {
  string mode;
  int range[2] = { 0,0 };
  int* ptr = range;
  vector<int> count_Steps;

  system("CLS");
  cout << "Do you want create [A]ll, a [R]ange or a [S]ingle Thread? ";
  cin >> mode;

  if (mode == "A" || mode == "a" || mode == "1") {
    range[0] = 1;
    cout << "How many Threads do you want to create? ";
    cin >> range[1];
    }
  else if (mode == "R" || mode == "r" || mode == "2") {
    cout << "Which is the first Thread to be created? ";
    cin >> range[0];
    cout << "Which is the last Thread to be created? ";
    cin >> range[1];
    }
  else if (mode == "S" || mode == "s" || mode == "3") {
    cout << "Which Thread should be created? ";
    cin >> range[0];
    range[1] = range[0];
    }

  stepsPerThread(range, count_Steps);
  createFile(range, count_Steps);

  return (0);
}

void stepsPerThread(const int* arrayPointer, vector<int>& stepsVector) {
  int tmp = 0;
  for (int i = *(arrayPointer); i < *(arrayPointer + 1) + 1; i++) {
    cout << "How many step should Thread_" << to_string(i) << " have? ";
    cin >> tmp;
    stepsVector.push_back(tmp);
    }
  }

void createFile(const int* arrayPointer, const vector<int>& stepsVector) {
  ofstream file;
  int tmpSteps = 0;

  for (int i = *(arrayPointer); i <= *(arrayPointer + 1); i++) {
      //Erzeugen des Konstruktors und des Desktruktors
    string nameThreadKonstruktorDestruktor = "Thread_Number_" + to_string(i) + "_Konstruktor_Deskstruktor.txt";
    file.open(nameThreadKonstruktorDestruktor);

    file << "-----------------------------------------------------------------------" << endl;
    file << "                      Thread_Variable_Definition                       " << endl;
    file << "-----------------------------------------------------------------------" << endl;
    file << "    Int32                                           SM_Thread" + to_string(i) + "_Schritt; " << endl;
    file << "    Int32                                           SM_Thread" + to_string(i) + "_Zaehler;" << endl;
    file << "    Boolean                                         SM_Thread" + to_string(i) + "_finished;" << endl;
    file << "-----------------------------------------------------------------------" << endl;
    file << "                      Thread_Function_Definition                       " << endl;
    file << "-----------------------------------------------------------------------" << endl;
    file << "    Boolean    SM_Thread_" + to_string(i) + "                            (void);" << endl;
    file << "-----------------------------------------------------------------------" << endl;
    file << "                      Thread_Variable_Constructor                      " << endl;
    file << "-----------------------------------------------------------------------" << endl;
    file << "  this->SM_Thread" + to_string(i) + "_Schritt                      = 0;" << endl;
    file << "  this->SM_Thread" + to_string(i) + "_Zaehler                      = 0;" << endl;
    file << "  this->SM_Thread" + to_string(i) + "_finished                     = true;" << endl;
    file << endl;
    file << "-----------------------------------------------------------------------" << endl;
    file << "                      Thread_Variable_Destructor                       " << endl;
    file << "-----------------------------------------------------------------------" << endl;
    file << endl;
    file << "  this->SM_Thread" + to_string(i) + "_finished                     = true;" << endl;
    file << "  this->SM_Thread" + to_string(i) + "_Zaehler                      = 0;" << endl;
    file << "  this->SM_Thread" + to_string(i) + "_Schritt                      = 0;" << endl;
    file.close();

    //Erzeugen der ganzen Thread-Funktion
    string nameThreadFunction = "Thread_Number_" + to_string(i) + "_Function.txt";
    file.open(nameThreadFunction);
    file << "Boolean        KLASSENNAME_::SM_Thread_" + to_string(i) + "                                     (void)" << endl;
    file << "  {" << endl;
    file << "  switch(this->SM_Thread" + to_string(i) + "_Schritt)" << endl;
    file << "    {" << endl;

    //Erzeugt für jeden Thread die gewünschte Anzahl an Steps
    for (int j = 0; j < stepsVector[tmpSteps] - 1; j++) {
      file << "    case " + to_string(j) + ":" << endl;
      file << "      {" << endl;
      file << "      /*DO_ANWEISUNG*/" << endl;
      file << "      this->SM_Thread" + to_string(i) + "_Schritt      = " + to_string(j + 1) + ";" << endl;
      file << "      return (false);" << endl;
      file << "      }" << endl;
      file << "    break;" << endl;
      }

      //Erzeugt den letzen Step und den default case
    file << "    case " + to_string(stepsVector[tmpSteps] - 1) + ":" << endl;
    file << "      {" << endl;
    file << "      /*DO_ANWEISUNG*/" << endl;
    file << "      this->SM_Thread" + to_string(i) + "_Zaehler      = " + to_string(0) + ";" << endl;
    file << "      this->SM_Thread" + to_string(i) + "_Schritt      = " + to_string(0) + ";" << endl;
    file << "      return (true);" << endl;
    file << "      }" << endl;
    file << "    break;" << endl;

    file << "    default:" << endl;
    file << "      {" << endl;
    file << "      this->SM_Thread" + to_string(i) + "_Zaehler      = " + to_string(0) + ";" << endl;
    file << "      this->SM_Thread" + to_string(i) + "_Schritt      = " + to_string(0) + ";" << endl;
    file << "      }" << endl;
    file << "    break;" << endl;
    file << "    } // switch" << endl;
    file << "  }" << endl;

    file.close();
    tmpSteps++;
    }
  }

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
