#pragma once
#include <iostream>
using namespace std;
class Barco {
	private:
		double efPesca = 1;
		string nombre = "";
		int peces = 0;
		int reduccion = 1;
		bool nitro = true;
		bool aIControlled = true;
		int x = 0;
		int y = 0;
		int objY = -1;
		int objX = -1;
		int LBPX = 0;
		int LBPY = 0;
		int LBE = 0;
		int turno = 0;

	public:
		//constructor
		Barco();
		Barco(string pNombre, int pX, int pY, bool pAIControlled);

		//getters
		string getNombre();
		double getEfPesca();
		int getPeces();
		bool getNitro();
		int getReduccion();
		int getX();
		int getY();
		int getObjX();
		int getObjY();
		int getTurno();
		bool getAIControlled();
		int getLBPX();
		int getLBPY();
		int getLBE();

		//setters
		void setNombre(string pNombre);
		void setEfPesca(double pEfPesca);
		void setPeces(int pPeces);
		void setNitro(bool pNitro);
		void setReduccion(int pReduccion);
		void setX(int pX);
		void setY(int pY);
		void setObjX(int pOX);
		void setObjY(int pOY);
		void setAIControlled(bool pAIControlled);
		void setTurno(int pTurno);
		void setLBPX(int pLBPX);
		void setLBPY(int pLBPY);
		void setLBE(int pLBE);

		//metodos propios
		void pescar(double pCasilla);
		void nitroF(int pNum);

		//ia
		void escogeLugar();

};