
#include <iostream>
using namespace std;

#ifndef Reloj_h
#define Reloj_h

class Reloj
{
	private:
		// Atributos
		int iHoras;
		int iMinutos;
	public:
		// Constructores
		Reloj();			// Default 12:00
		Reloj(int, int);

		//Métodos
		void toString(); 			// Formato HH:MM
		void horaConFormato();		// 23:40 -> 11:40 PM

		// Acceso
		int getHoras();
		int getMinutos();

		// Modificación
		void setHoras(int);
		void setMinutos(int);
};

Reloj::Reloj()
{
	iHoras = 12;
	iMinutos = 0;
}

Reloj::Reloj(int iH, int iM)
{
	iHoras = iH;
	iMinutos = iM;
}

void Reloj::toString()
{
	if (iHoras < 10)
	{
		cout << '0';

	}
	cout << iHoras;
	cout << ':';
	if (iMinutos < 10)
	{
		cout << '0';
	}
	cout << iMinutos << endl;
}

void Reloj::horaConFormato()
{
	char cM;
	if (iHoras < 12)
	{
		cM = 'A';
		if (iHoras == 0)
		{
			cout << "12";
		}
		else if (iHoras < 10)
		{
			cout << '0';
			cout << iHoras;
		}
		else
		{
			cout << iHoras;
		}
	}
	else
	{
		cM = 'P';
		if (iHoras == 12)
		{
			cout << iHoras;
		}
		else
		{
			cout << iHoras - 12;
		}
	}
	cout << ':';
	if (iMinutos < 10)
	{
		cout << '0';
	}
	cout << iMinutos;
	cout << cM;
	cout << 'M' << endl;
}

int Reloj::getHoras()
{
	return iHoras;
}

int Reloj::getMinutos()
{
	return iMinutos;
}

void Reloj::setHoras(int iH)
{
	iHoras = iH;
}

void Reloj::setMinutos(int iM)
{
	iMinutos = iM;
}

#endif
