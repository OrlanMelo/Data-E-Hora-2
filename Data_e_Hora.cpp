#include <ctime>
#include <sysinfoapi.h>
#include <chrono>
#include <iostream>
#include <tchar.h>

using namespace std;
using namespace chrono;

class cFuncoes
{
private:
public:

	void ObterTempo()
	{
		auto agora = system_clock::now();
		time_t tempo = system_clock::to_time_t(agora);

		_tprintf(L"Hora e data: %s\n", _wctime(&tempo));
	}

	void ObterTempo2()
	{
		time_t tempo = time(0);
		tm atual;
		localtime_s(&atual, &tempo);

		cout << "Dia: " << atual.tm_mday << "\n";
		cout << "Mes: " << atual.tm_mon + 1 << "\n";
		cout << "Ano: " << atual.tm_year + 1900 << "\n";

		cout << "Hora: " << atual.tm_hour << ":" << atual.tm_min + 0 << "\n";
	}

	void AlterarData(int Dia, int Mes, int Ano, bool Hora, int iHora, int Minuto)
	{
		SYSTEMTIME Tempo;
		Tempo.wDay = Dia;
		Tempo.wMonth = Mes;
		Tempo.wYear = Ano;

		if (Hora == true)
		{
			Tempo.wHour = iHora;
			Tempo.wMinute = Minuto;
		}

		SetLocalTime(&Tempo);
		SetLocalTime(&Tempo);
	}

}Funcoes;

int main()
{

	Funcoes.ObterTempo();
	Funcoes.ObterTempo2();

	Funcoes.AlterarData(1, 2, 2022, true, 1, 12);

}