#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

struct Profil

{

int IDbroj;

string Nickname;

float  Nivo;

Profil(int ID, const string& Nickname)

: IDbroj(IDbroj), Nickname(Nickname), Nivo(Nivo)
{

}

bool operator<(const Profil& p) const

{

return Nickname < p.Nickname; // order by Name

}

};


struct SortProfilePointers

{
bool operator()(const Profil* lhs, const Profil* rhs) const

{

return *lhs < *rhs;

}

};

int main()

{

vector<Profil*> Profiles;

Profiles.push_back(new Profil(2, "Kika"));

Profiles.push_back(new Profil(4, "Violeta"));

Profiles.push_back(new Profil(1, "Mila"));

Profiles.push_back(new Profil(5, "Petar"));

Profiles.push_back(new Profil(3, "Pluton"));

cout<<"***Pechatenje na podatocite*** "<<endl;
cout<<setw(10)<<"IDbroj"<<setw(10)<<"Nickname"<<endl;

for(const auto* p: Profiles)
    {
        cout <<setw(10)<<p->IDbroj<<setw(10)<< p->Nickname <<endl;
    }

cout<<endl<<"***Podatocite sortirani po rastecki A-Z***"<<endl;
cout<<setw(10)<<"IDbroj"<<setw(10)<<"Nickname"<<endl;

sort(Profiles.begin(), Profiles.end(), SortProfilePointers());

for(const auto* p: Profiles)

cout << p->IDbroj << ": " << p->Nickname << '\n';

//vector vo nadvoreshen fajl
ofstream outFile ("INKI889KristinaTanevska.txt");
for (const auto& q: Profiles) outFile<<q<<endl;

for(auto* p: Profiles)

delete p;

}
