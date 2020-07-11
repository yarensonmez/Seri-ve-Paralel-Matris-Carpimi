#include <iostream>
#include <random>
#include <omp.h>
#include <stdlib.h>

#define NUM_THREADS 8

using namespace std;

//Programdaki degiskenler
float** X;
float** Y;
float** Z;

double** dX;
double** dY;
double** dZ;

int n;

float basla;
float bitis;

void SeriMatrisAlF();
void SeriCarpimF();
void SeriMatrisAlD();
void SeriCarpimD();

void ParalelMatrisAlF();
void ParalelCarpimF();
void ParalelMatrisAlD();
void ParalelCarpimD();

int secim;

int main()
{
	cout << "\n\n";
	cout << "1 - Seri Float\n";
	cout << "2 - Seri Double\n";
	cout << "3 - Paralel Float\n";
	cout << "4 - Paralel Double\n\n";

	cout << "Seciminizi girin: ";
	cin >> secim;

	if (secim == 1) {
		cout << "\nSeri Matris Carpimi (float)\n\n";

		//Carpılacak iki matris icin satir ve sutun sayisi aliyorum.
		cout << "Matrislerin boyutunu giriniz: ";
		cin >> n;

		cout << "Matrisler olusturuluyor..\n\n ";
		SeriMatrisAlF();

		cout << "Carpim basladi.. Lutfen bekleyiniz..\n\n ";
		basla = omp_get_wtime();
		SeriCarpimF();
		bitis = omp_get_wtime() - basla;
		cout << "Seri kosma zamani: " << bitis << " sn " << endl;
	}

	if (secim == 2) {
		cout << "\nSeri Matris Carpimi (double)\n\n";
		cout << "Matrislerin boyutunu girin: ";
		cin >> n;

		cout << "Matrisler olusturuluyor..\n";
		SeriMatrisAlD();

		cout << "Carpim basladi.. Lutfen bekleyiniz..\n\n ";
		basla = omp_get_wtime();  //Matris carpım isleminden once zamani baslatiyorum.
		SeriCarpimD();
		bitis = omp_get_wtime() - basla;	//Gecen zamandan baslangic zamanini cıkarip zamani buluyorum
		cout << "Seri carpim toplam zaman: " << bitis << " sn" << endl;
	}

	if (secim == 3) {
		printf("\nOPENMP ile Paralel Matris Carpimi (float)\n\n");


		cout << "Matrislerin boyutunu girin: ";
		cin >> n;

		cout << "Matrisler olusturuluyor..\n\n ";
		ParalelMatrisAlF();

		cout << "Carpim basladi.. Lutfen bekleyiniz..\n\n ";
		basla = omp_get_wtime();
		ParalelCarpimF();
		bitis = omp_get_wtime() - basla;
		cout << "Paralel kosma zamani: " << bitis << " sn " << endl;
	}

	if (secim == 4) {
		printf("\nOPENMP ile Paralel Matris Carpimi (double)\n\n");


		cout << "Matrislerin boyutunu girin: ";
		cin >> n;

		cout << "Matrisler olusturuluyor..\n\n ";
		ParalelMatrisAlD();

		cout << "Carpim basladi.. Lutfen bekleyiniz..\n\n ";
		basla = omp_get_wtime();
		ParalelCarpimD();
		bitis = omp_get_wtime() - basla;
		cout << "Paralel kosma zamani: " << bitis << " sn " << endl;
	}


	return main();
}

void SeriMatrisAlF() {
	//Buradan itibaren matrisleri olusturmaya basliyorum.
	X = new float* [n]; //İlk matris
	Y = new float* [n];  //İkinci matris
	Z = new float* [n];  //Sonuc matrisi

	for (int i = 0; i < n; i++) { X[i] = new float[n]; }
	for (int i = 0; i < n; i++) { Y[i] = new float[n]; }
	for (int i = 0; i < n; i++) { Z[i] = new float[n]; }

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			X[i][j] = 1.0;		//İlk matrisi 1.0 ile dolduruyorum.
			Y[i][j] = 1.0;		//İkinci matrisi 1.0 ile dolduruyorum.
		}
	}
}

void SeriCarpimF() {

	//Matris carpım isleminden once zamani baslatiyorum.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Z[i][j] = 0;	//Gecici degiskenimi sifira esitliyorum.
			for (int k = 0; k < n; k++)
			{
				Z[i][j] += X[i][k] * Y[k][j];	//Her satir sutun carpimindan gelen toplamlari buluyorum.
			}
		}
	}
}

void SeriMatrisAlD() {
	//Buradan itibaren matrisleri olusturmaya basliyorum.
	dX = new double* [n]; //İlk matris
	dY = new double* [n]; //İkinci matris
	dZ = new double* [n]; //Sonuc matrisi

	for (int i = 0; i < n; i++) { dX[i] = new double[n]; }
	for (int i = 0; i < n; i++) { dY[i] = new double[n]; }
	for (int i = 0; i < n; i++) { dZ[i] = new double[n]; }

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dX[i][j] = 1.0;		//İlk matrisi 1.0 ile dolduruyorum.
			dY[i][j] = 1.0;		//İkinci matrisi 1.0 ile dolduruyorum.
		}
	}
}

void SeriCarpimD() {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dZ[i][j] = 0;	//Gecici degiskenimi sifira esitliyorum.
			for (int k = 0; k < n; k++)
			{
				dZ[i][j] += dX[i][k] * dY[k][j];	//Her satir sutun carpimindan gelen toplamlari buluyorum.
			}
		}
	}

}

void ParalelMatrisAlF() {
	//Buradan itibaren matrisleri olusturmaya basliyorum.
	X = new float* [n]; //İlk matris
	Y = new float* [n];  //İkinci matris
	Z = new float* [n];  //Sonuc matrisi

#pragma omp parallel for
	for (int i = 0; i < n; i++) { X[i] = new float[n]; }
#pragma omp parallel for
	for (int i = 0; i < n; i++) { Y[i] = new float[n]; }
#pragma omp parallel for
	for (int i = 0; i < n; i++) { Z[i] = new float[n]; }

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			X[i][j] = 1.0;		//İlk matrisi 1.0 ile dolduruyorum.
			Y[i][j] = 1.0;		//İkinci matrisi 1.0 ile dolduruyorum.
		}
	}
}

void ParalelCarpimF() {

	int i, j, k;

	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel for private(i,j,k) collapse(3) schedule(dynamic)

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				Z[i][j] += X[i][k] * Y[k][j];
			}
		}
	}
}

void ParalelMatrisAlD() {

	//Buradan itibaren matrisleri olusturmaya basliyorum.
	dX = new double* [n]; //İlk matris
	dY = new double* [n]; //İkinci matris
	dZ = new double* [n]; //Sonuc matrisi

#pragma omp parallel for
	for (int i = 0; i < n; i++) { dX[i] = new double[n]; }
#pragma omp parallel for
	for (int i = 0; i < n; i++) { dY[i] = new double[n]; }
#pragma omp parallel for
	for (int i = 0; i < n; i++) { dZ[i] = new double[n]; }

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dX[i][j] = 1.0;		//İlk matrisi 1.0 ile dolduruyorum.
			dY[i][j] = 1.0;		//İkinci matrisi 1.0 ile dolduruyorum.
		}
	}
}

void ParalelCarpimD() {
	int i, j, k;

	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel for private(i,j,k) collapse(3) schedule(dynamic)

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				dZ[i][j] += dX[i][k] * dY[k][j];
			}
		}
	}
}
