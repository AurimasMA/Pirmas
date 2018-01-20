#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

const int CMax=100;

ifstream fd("Miestas1.txt");
ifstream fdd("Miestas2.txt");
ofstream fv("Rezultatai.txt");

struct Gatve1
{
	string pav;
	int km;
	int sk;
};
struct Gatve2
{
	string pav;
	int km;
	int sk;
};
struct Rezai
{
	string pav;
	int km;
	int sk;
};

void skaityti(Gatve1 G1[], Gatve2 G2[], int & n, int & m, string m1, string m2);
void atrinkti(Rezai Ga[] ,Gatve1 G1[], Gatve2 G2[], int n, int m, int x, int z, int & ilgis);
void rikiuoti(Rezai Ga[], int ilgis);
void spausdinti(Rezai Ga[], int ilgis);
int main()
{
	int x, z, n, m, ilgis = 0;
	string m1, m2;

	Gatve1 G1[CMax];
	Gatve2 G2[CMax];
	Rezai Ga[CMax];

	cin >> x;
	cin >> z;
	skaityti(G1, G2, n, m, m1, m2);
	atrinkti(Ga, G1, G2, n, m, x, z, ilgis);
	rikiuoti(Ga, ilgis);
	spausdinti(Ga, ilgis);
	return 0;
}
void skaityti(Gatve1 G1[], Gatve2 G2[], int & n, int & m, string m1, string m2)
{
	fd >> m1;
	fd >> n;
	fdd >> m2;
	fdd >> m;
for(int i = 0; i < n; i++)
{
	fd >> G1[i].pav >> G1[i].km >> G1[i].sk;
}

for(int y = 0; y < m; y++)
{
	fdd >> G2[y].pav >> G2[y].km >> G2[y].sk;
}

}

void atrinkti(Rezai Ga[] ,Gatve1 G1[], Gatve2 G2[], int n, int m, int x, int z, int & ilgis)
{
	int a = 0, b = 0;

	for(int i = 0; i < n; i++)
{
	if(G1[i].km < x && G1[i].sk > z)
	{
		Ga[a].pav = G1[i].pav;
		Ga[a].km = G1[i].km;
		Ga[a].sk = G1[i].sk;
		a++;
	}
}
	for(int i = 0; i < m; i++)
{
	if(G2[i].km < x && G2[i].sk > z)
	{
		Ga[a+b].pav = G2[i].pav;
		Ga[a+b].km = G2[i].km;
		Ga[a+b].sk = G2[i].sk;
		b++;
	}
}
ilgis = a + b;
}
void rikiuoti(Rezai Ga[], int ilgis)
{
	int i = 0, c, d;
	string a;
	bool bk = true;
	while (bk)
	{
		bk = false;
		i = i + 1;
		for(int j = ilgis - 1; j > i - 1; j--)
		{
			if(Ga[j].km < Ga[j - 1].km)
			{
				bk = true;
		
				d = Ga[j].sk;
				c = Ga[j].km;
				a = Ga[j].pav;

				Ga[j].km = Ga[j - 1].km;
				Ga[j].pav = Ga[j - 1].pav;
				Ga[j].sk = Ga[j - 1].sk;

				Ga[j - 1].pav = a;
				Ga[j - 1].km = c;
				Ga[j - 1].sk = d;
			}
		}
	}
}
void spausdinti(Rezai Ga[], int ilgis)
{
	for(int i = 0; i < ilgis; i++)
	{
		fv << Ga[i].pav << "   " << Ga[i].km << "  " << Ga[i].sk << endl; 
	}
}

