#include <random>
#include <iostream>
#include <windows.h>
#include "Barco.h";
using namespace std;

Barco::Barco(string pNombre, int pX, int pY, bool pAIControlled) {
	nombre = pNombre;
	x = pX;
	y = pY;
	aIControlled = pAIControlled;
}
Barco::Barco() {

}

//getters
string Barco::getNombre() {
	return nombre;
}
double Barco::getEfPesca() {
	return efPesca;
}
int Barco::getPeces() {
	return peces;
}
bool Barco::getNitro() {
	return nitro;
}
int Barco::getReduccion() {
	return reduccion;
}
int Barco::getX() {
	return x;
}
int Barco::getY() {
	return y;
}
int Barco::getObjX() {
	return objX;
}
int Barco::getObjY() {
	return objY;
}
bool Barco::getAIControlled() {
	return aIControlled; 
}
int Barco::getTurno() {
	return turno;
}
int Barco::getLBPX() {
	return LBPX;
}
int Barco::getLBPY() {
	return LBPY;
}
int Barco::getLBE() {
	return LBE;
}
//setters

void Barco::setNombre(string pNombre) {
	nombre = pNombre;
}
void Barco::setEfPesca(double pEfPesca) {
	efPesca = pEfPesca;
}
void Barco::setPeces(int pPeces) {
	peces = pPeces;
}
void Barco::setNitro(bool pNitro) {
	nitro = pNitro;
}
void Barco::setReduccion(int pReduccion) {
	reduccion = pReduccion;
}
void Barco::setX(int pX) {
	x = pX;
}
void Barco::setY(int pY) {
	y = pY;
}
void Barco::setObjX(int pOX) {
	objX = pOX;
}
void Barco::setObjY(int pOY) {
	objY = pOY;
}
void Barco::setAIControlled(bool pAIControlled) {
	aIControlled = pAIControlled;
}
void Barco::setTurno(int pTurno) {
	turno = pTurno;
}
void Barco::setLBPX(int pLBPX) {
	LBPX = pLBPX;
}
void Barco::setLBPY(int pLBPY) {
	LBPY = pLBPY;
}
void Barco::setLBE(int pLBE) {
	LBE = pLBE;
}
//propios

void Barco::pescar(double pCasilla) {
	efPesca = efPesca * pCasilla;

	string eleccion;

	while (eleccion != "s" && eleccion != "n" && getNitro() != 0 && !getAIControlled()) {// se que no deberia estar aqui pero;
		cout << "Quieres probar de lanzar casi todo el cebo? S/N\n";
		int index = 0;
		cin >> eleccion;
		for (char letra : eleccion) {
			eleccion[index] = tolower(letra);
		}
		if (eleccion == "s") {
			int tirada;
			for (int i = 0; i < 20; i++) {
				system("cls");
				tirada = int(rand() % (11));
				cout << tirada << "\n";
				Sleep(100 * (pow(1.1, i)));
			}
			nitroF(tirada);
		}

	}

	double efPescaTemp = efPesca * reduccion;
	double err = int(rand() % (11)); // numero entre el 0 y el 10
	err = 1.05 - (err / 100); //numero entre 1.05 y 0.95
	peces += (20 * efPescaTemp) * err; // cambio los peces
	//cout <<"nombre: " << nombre << " eficiencia: " << efPesca << " temp: " << efPescaTemp << " peces: " << peces << " error: " << err<<"\n";
	if (pCasilla >= LBE) {//para que recuerde la mejor posicion
		LBE = pCasilla;
		LBPX = x;
		LBPY = y;
	}
}

void Barco::nitroF(int pNum)
{
	if (pNum%2 == 0) {
		cout << "Parece que hay mas peces que nunca\n";
		efPesca = efPesca * 2;
	}
	else {
		cout << "Has lanzado todo el cebo y has asustado a los peces\n";
		efPesca = efPesca / 2;
	}
	setNitro(0);
}

//ia
void Barco::escogeLugar() {

}