#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;



int main(int argc, char* argv[])
{
    double t, x;
    string linia;
    typedef pair <double,double> Probka;
    ifstream plik("sygnal.csv");
    vector <Probka> dane;
    while (getline(plik, linia))
    {
        stringstream ss(linia);
        ss >> t;
        ss.ignore();
        ss >> x;
        dane.push_back(Probka(t, x));
    }
    plik.close();
    for (int i=1; i<dane.size(); i++)
    {
        cout << dane[i].first << "," << dane[i].second << endl;
    }
    ofstream plik2 ("out.csv", ios::app);
    for (int i=1; i<dane.size(); i++)
        plik2 << dane[i].first << dane[i].second << endl;
    plik.close();


}
