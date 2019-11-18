
#include "Reloj.h"
using namespace std;

#ifndef Evento_h
#define Evento_h

class Evento
{
	private:
		// Atributos
		string sNombre;
		string sDescripcion;
		string sLugar;
		Reloj horaDeInicio;
		int iDuracionDelEvento;

	public:
		// Constructores
		Evento(string, string, string, Reloj, int);

		// Métodos
		Reloj horaFinalDelEvento();
		void toString();

		// Acceso
		string getNombre();
		string getDescripcion();
		string getLugar();
		Reloj getHoraDeInicio();
		int getDuracionDelEvento();

		// Modificación
		void setNombre(string);
		void setDescripcion(string);
		void setLugar(string);
		void setHoraDeInicio(Reloj);
		void setDuracionDelEvento(int);
};

Evento::Evento(string sN, string sD, string sL, Reloj hDI, int iDDE)
{
	sNombre = sN;
	sDescripcion = sD;
	sLugar = sL;
	horaDeInicio = hDI;
	iDuracionDelEvento = iDDE;
}

Reloj Evento::horaFinalDelEvento()
{
	int iH = (horaDeInicio.getHoras() + (iDuracionDelEvento / 60)) % 24;
	int iM = horaDeInicio.getMinutos() + (iDuracionDelEvento % 60);
	if (iM > 59)
	{
		++iH;
		iM -= 59;
	}
	Reloj horaFinal(iH, iM);
	return horaFinal;
}

void Evento::toString()
{
	cout << "Nombre: " << sNombre << endl;
	cout << "Descripcion: " << sDescripcion << endl;
	cout << "Lugar: " << sLugar << endl;
	cout << "Hora de Inicio: ";
	horaDeInicio.toString();
	cout << "Duracion del Evento: " << iDuracionDelEvento << endl;
}

string Evento::getNombre()
{
	return sNombre;
}

string Evento::getLugar()
{
	return sLugar;
}

string Evento::getDescripcion()
{
	return sDescripcion;
}

Reloj Evento::getHoraDeInicio()
{
	return horaDeInicio;
}

int Evento::getDuracionDelEvento()
{
	return iDuracionDelEvento;
}

void Evento::setNombre(string sN)
{
	sNombre = sN;
}

void Evento::setLugar(string sL)
{
	sLugar = sL;
}

void Evento::setDescripcion(string sD)
{
	sDescripcion = sD;
}

void Evento::setHoraDeInicio(Reloj hDI)
{
	horaDeInicio = hDI;
}

void Evento::setDuracionDelEvento(int iDDE)
{
	iDuracionDelEvento = iDDE;
}

#endif
