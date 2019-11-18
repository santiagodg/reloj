
#include <iostream>
#include "Evento.h"
#include "Reloj.h"
using namespace std;

int main()
{
	string sNombre, sDescripcion, sLugar;
	int iDuracionDelEvento, iH, iM;
	Reloj reloj0;
	Evento evento0("","","", reloj0, 0);

	bool bTerminar = false;
	int iOpcion;
	cout << "MENU" << endl;
	do
	{
		cout << "1) Dar de alta evento" << endl;
		cout << "2) Imprimir datos del evento" << endl;
		cout << "3) Hora final del evento" << endl;
		cout << "4) Modificar todo el evento" << endl;
		cout << "5) Terminar" << endl;
		cout << ">>> ";
		cin >> iOpcion;
		cin.ignore();

		switch (iOpcion)
		{
			case 1:
			{
				cout << "Ingrese el nombre: ";
				getline(cin, sNombre);

				cout << "Ingrese la descripcion: ";
				getline(cin, sDescripcion);

				cout << "Ingrese el lugar: ";
				getline(cin, sLugar);

				cout << "Ingrese la hora de inicio (HH MM): ";
				cin >> iH >> iM;
				while ((iH < 0 || 24 <= iH) || (iM < 0 || 60 <= iM))
				{
					cout << "Hora de inicio invalida." << endl;
					cout << "Ingrese la hora de inicio (HH MM): ";
					cin >> iH >> iM;
				}
				Reloj horaDeInicio(iH, iM);

				cout << "Ingrese la duracion del evento (mins): ";
				cin >> iDuracionDelEvento;
				while (iDuracionDelEvento < 0)
				{
					cout << "Duracion del evento invalida." << endl;
					cout << "Ingrese la duracion del evento (mins): ";
					cin >> iDuracionDelEvento;
				}

				Evento evento1(sNombre, sDescripcion, sLugar, horaDeInicio,
						  iDuracionDelEvento);
				evento0 = evento1;
			}
			break;

			case 2:
			{
				evento0.toString();
			}
			break;

			case 3:
			{
				reloj0 = evento0.horaFinalDelEvento();
				cout << "La hora final del evento es ";
				reloj0.horaConFormato();
			}
			break;

			case 4:
			{
				cout << "Ingrese el nuevo nombre: ";
				getline(cin, sNombre);
				evento0.setNombre(sNombre);

				cout << "Ingrese la nueva descripcion: ";
				getline(cin, sDescripcion);
				evento0.setDescripcion(sDescripcion);

				cout << "Ingrese el nuevo lugar: ";
				getline(cin, sLugar);
				evento0.setLugar(sLugar);

				cout << "Ingrese la nueva hora de inicio (HH MM): ";
				cin >> iH >> iM;
				Reloj horaDeInicio(iH, iM);
				evento0.setHoraDeInicio(horaDeInicio);

				cout << "Ingrese la nueva duracion del evento (mins): ";
				cin >> iDuracionDelEvento;
				evento0.setDuracionDelEvento(iDuracionDelEvento);
			}
			break;

			case 5:
			{
				bTerminar = true;
			}
			break;

			default:
			{
				cout << "Opcion invalida." << endl;
				cout << "Ingrese una opcion entre 1 y 5.";
				cout << ">>> ";
				cin >> iOpcion;
			}
			break;
		}
	} while (!bTerminar);

	return 0;
}