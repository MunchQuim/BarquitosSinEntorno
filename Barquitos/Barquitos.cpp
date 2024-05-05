// Barquitos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <random>
#include <iostream>
#include <string>
#include "Barco.h";
#include <windows.h>
#include <cmath>
using namespace ::std;

const int anchoMar = 12;
const int altoMar = 27;
const int numeroBarcos = 4;
const double multi[4] = { 1, 1.1, 1.25, 1.5 };//informacion sobre la pesca de la zona

void premios(Barco(&pBarcos)[numeroBarcos]) {
	int time = 333;
	const int length = sizeof(pBarcos) / sizeof(Barco);
	string strPez[length] = {"","","",""};
	int num = 0;
	int contador = 0;

	while (contador !=length) {
		system("cls");
		contador = 0;
		for (int i = 0; i < length; i++)
		{
			if (pBarcos[i].getPeces() >= num) {
				strPez[i] += "|";
			}
			else if (num - pBarcos[i].getPeces()<10) {
				for (int j = 0; j < num - pBarcos[i].getPeces(); j++) {
					strPez[i] += ".";
				}
			}
			else {
				contador++;
			}
			cout<<pBarcos[i].getNombre()<<":\t"<<strPez[i]<<"\n";
		};

		num+=10;//cada linea indica grupos de 10 peces

		if (time > 50) {
			time = time * pow(0.9, contador);
		}
		if (time < 50) {
			time = 50;
		}
		
		Sleep(time);	
	}


}

void escogeLugar(Barco& pBarco) {
	//implementar luego, puede ser propia del barco
	if (pBarco.getTurno() == 0) {
		
	}
	else {

	}
	pBarco.setObjX(rand() % anchoMar);
	pBarco.setObjY(rand() % altoMar);

	pBarco.setTurno(pBarco.getTurno() + 1);
}

void pescaBarcos(Barco(&pBarcos)[numeroBarcos], int pMapa[anchoMar][altoMar]) {

	for (int i = 0; i < (sizeof(pBarcos) / sizeof(Barco)); i++) {//solo imprime los resultados del pj
		if (pBarcos[i].getAIControlled()) {
			//cout << "\n\n casilla" << multi[pMapa[pBarcos[i].getX()][pBarcos[i].getY()]];
			pBarcos[i].pescar(multi[pMapa[pBarcos[i].getX()][pBarcos[i].getY()]]);
		}
		else {
			int peces = pBarcos[i].getPeces();

			pBarcos[i].pescar(multi[pMapa[pBarcos[i].getX()][pBarcos[i].getY()]]);
			
			peces = pBarcos[i].getPeces() - peces;
			cout << "Has pescado: "<< peces<<" peces\n";

			switch (pMapa[pBarcos[i].getX()][pBarcos[i].getY()])// indica la presencia de peces
			{

			case 0:
				cout << "No parece un buen lugar donde pescar 🐟\n";
				break;
			case 1:
				cout << "Parece que hay algunos peces por aquí 🐟🐟\n";
				break;
			case 2:
				cout << "Parece una buena zona, sigue así 🐟🐟🐟\n";
				break;
			case 3:
				cout << "Este lugar está abarrotado de peces 🐟🐟🐟🐟\n";
				break;

			default:
				break;
			}

			cout << "Peces: " << pBarcos[i].getPeces();
		}
		
	}

}

void mueveBarcos(Barco(&pBarcos)[numeroBarcos]) {

	for (int i = 0; i < (sizeof(pBarcos) / sizeof(Barco)); i++) {

		pBarcos[i].setX(pBarcos[i].getObjX());
		pBarcos[i].setObjX(-1);
		pBarcos[i].setY(pBarcos[i].getObjY());
		pBarcos[i].setObjY(-1);

	}
	//verificacion del choque
}


void ronda(Barco(&pArray)[numeroBarcos]) {
	
	for (int i = 0; i < (sizeof(pArray) / sizeof(Barco)); i++) {
		if (pArray[i].getAIControlled()) {//barco rival
			// mando el barco a escoger su lugar
			escogeLugar(pArray[i]);
		}
		else {
			int valor = 0;
			while (!(pArray[i].getObjX() >= 0 && pArray[i].getObjX() < anchoMar)) {
				cout << "A que posicion X quieres ir? 0-"<<(anchoMar-1)<<"\n";
				try
				{
					cin >> valor;
					pArray[i].setObjX(valor);
				}
				catch (const std::exception&)
				{
					cout << "intenta introducir un valor numerico\n";
				}
				
			}
			while (!(pArray[i].getObjY() >= 0 && pArray[i].getObjY() < altoMar)) {
				cout << "A que posicion Y quieres ir? 0-" << (altoMar-1)<<"\n";
				try
				{
					cin >> valor;
					pArray[i].setObjY(valor);
				}
				catch (const std::exception&)
				{
					cout << "intenta introducir un valor numerico\n";
				}

			}
			
			
		}
	}
	



}
void imprimeMapa(int pMapa[anchoMar][altoMar], Barco (&pBarcos)[numeroBarcos]) {

		cout << "----- \n\n";
		for (int i = 0; i < altoMar; i++) {//altura
		for (int j = 0; j < anchoMar; j++) {//anchura
			bool usado = false;

			for (Barco elemento : pBarcos) {
				if (elemento.getX() == j && elemento.getY() == i) {
					if (!elemento.getAIControlled()) {
						cout << "Q";
					}
					else {
						cout << "V";
					}
					usado = true;
				}
			}
			if (!usado) {
				cout << "~";
			}
		}
		cout << "\n";
	}


}
void creaBarcos(Barco(&pArray)[numeroBarcos]){
	int dPosicion = anchoMar/numeroBarcos;
	for (int i = 0; i < numeroBarcos-1; i++)
	{	
		
		string nombreBarco = "Barco" + to_string(i + 1);
		Barco rival(nombreBarco, dPosicion*(i+1), 0, true);
		pArray[i] = rival;
	}
}
void creaPersonaje(Barco(&pArray)[numeroBarcos]) {

	string nombre;
	cout << "Cual es tu nombre?";
	cin >> nombre;
	Barco personaje(nombre, 0, 0, false);
	pArray[numeroBarcos-1] = personaje;

}
//genero un mapa con una zona de 9x9 donde dentro hay una zona de 3x3 y dentro una de 1x1
void obtenerMapa(int (&pArray)[anchoMar][altoMar]) {

	int infraSubOptimo = 9;
	int subOptimo = 3;
	int optimo = 1;
	for (int i = 0; i < altoMar; i++) {
		for (int j = 0; j < anchoMar; j++) {
			pArray[j][i] = 0;
		}
	}
	//determinar que posicion para el infraSubObtimo
	int posISOX = rand()%(anchoMar - infraSubOptimo+1);
	int posISOY = rand()%(altoMar - infraSubOptimo+1);

	for (int i = posISOY; i < posISOY+infraSubOptimo; i++) {
		for (int j = posISOX; j < posISOX+infraSubOptimo; j++) {
			pArray[j][i] = 1;
		}
	}
	
	int posSOX = rand()%(infraSubOptimo - subOptimo +1)+posISOX;
	int posSOY = rand() % (infraSubOptimo - subOptimo + 1) + posISOY;

	for (int i = posSOY; i < posSOY + subOptimo; i++) {
		for (int j = posSOX; j < posSOX + subOptimo; j++) {
			pArray[j][i] = 2;
		}
	}

	int posOX = rand() % (subOptimo - optimo + 1) + posSOX;
	int posOY = rand() % (subOptimo - optimo + 1) + posSOY;

	for (int i = posOY; i < posOY + optimo; i++) {
		for (int j = posOX; j < posOX + optimo; j++) {
			pArray[j][i] = 3;
			cout << "x: " << j << ", y: " << i <<"\n";
		}
	}
}

//imprime el mapa
void imprimeMapaDebug(int pArray [anchoMar][altoMar]) {

	for (int i = 0; i < altoMar; i++) {
		for (int j = 0; j < anchoMar; j++) {
			cout << pArray[j][i];
		}
		cout << '\n';
	}

}



int main() {
	int turno = 5;

	
	srand(time(NULL));

	int marArray[anchoMar][altoMar];//mapa
	obtenerMapa(marArray);
	imprimeMapaDebug(marArray);
	Barco barcoArray[numeroBarcos];//creo array de barcos;
	creaBarcos(barcoArray);//mete los barcos al array
	creaPersonaje(barcoArray);// mete al personaje en el array
	
	
	while (turno > 0) {
		ronda(barcoArray);
		//todo el mundo ha escogido, sus valores pasan a ser su ubicacion actual (y verificar choques)
		for (Barco barco : barcoArray) {
			//cout << "\n" << barco.getNombre() << " X=" << barco.getX() << " Y=" << barco.getY() << " ObjX=" << barco.getObjX() << " ObjY=" << barco.getObjY() << "\n";
		}system("cls");
		mueveBarcos(barcoArray);
		for (Barco barco : barcoArray) {
			//cout << "\n" << barco.getNombre() << " X=" << barco.getX() << " Y=" << barco.getY() << " ObjX=" << barco.getObjX() << " ObjY=" << barco.getObjY() << "\n";
		}
		// todo el mundo se ha movido, se procede a calcular la eficiencia y pescar
		pescaBarcos(barcoArray, marArray);

		//todo el mundo ha pescado

		// imprime el mapa
		imprimeMapa(marArray, barcoArray);

		turno--;
	}
	Sleep(5000);
	premios(barcoArray);
	




}


