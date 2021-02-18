#pragma once
#include <iostream>		//Стандартная библиотека c++
#include <cstdlib>		//Для вызова system
#include <vector>		//Для работы с векторами
#include <iomanip>		//setw() для перфекционизма
#include "windows.h"	//Для души...и Sleep
#include <algorithm>
using namespace std;
void Menu()		//Могу посоветовать 3 блюдо
{
	cout << "-------------------------------" << endl;
	cout << "| 1.Ввод Графа                |" << endl;
	cout << "| 2.Вывод графа               |" << endl;
	cout << "| 3.Начать заново             |" << endl;
	cout << "| 4.Выход из программы (._.`) |" << endl;
	cout << "-------------------------------" << endl;
	cout << ">>> ";
}
void Choice()	//От вашего выбора зависит, что будет происходить с вашими матрицами
{				//Вам решать, кто будет распечатан, а кто навсегда утерян
	cout << "-----------------------------" << endl;
	cout << "| 1. Матрица Инцидентности  |" << endl;
	cout << "| 2. Матрица Смежности      |" << endl;
	cout << "| 3. Список Смежности       |" << endl;
	cout << "| 4. Вернуться назад        |" << endl;
	cout << "-----------------------------" << endl;
	cout << ">>> ";			
}
void Adjacency_input(int **&Adj,int m) 
{
	Adj = new int*[m];				//Выделяем m ячеек памяти
	if (Adj == NULL) exit(31);		//или не выделяем
	for (int i = 0; i < m; i++)		//выделяем для каждой m ячейки
	{
		Adj[i] = new int[m];		//еще по m ячеек
		if (Adj[i] == NULL)
			exit(36);
	}
	cout << "Введите Матрицу Смежности: " << endl << "  "; 
	for (int i = 0; i < m; i++)
	{										
		cout << setw(2) << "X" << i + 1;	//Ну типа эээм ээ мммм печатаем
	}										
	cout << endl;
	for (int i = 0; i < m; i++)				//Вводим матрицу смежности
	{
		cout << "X" << i + 1 << ":";			
		for (int j = 0; j < m; j++)			//соблюдая все меры социальной дистанции
		{
			cin >> Adj[i][j];				//не менее одного пробела между элементами
		}
	}
}
void load(double n)	//задержка.
{
	Sleep(1000 * n);
}//задержка на n секунд
void loading(int n, double f) 
{	
	for (int i = 0; i < n; i++)		//загрузка на время задержки
	{
		cout << "."; load(f);
	}
}//Печатает загрузку в n точек и f единиц времени
void Incidence_input(int **&a,int n,int m)	//Вводим 2
{
	a = new int *[n];		//достаем один столбец таблицы 
	if (a == NULL) exit (70);
	for (int i = 0; i < n; i++) 
	{
		a[i] = new int[m];	//и медленно растягиваем каждый из его элементов
		if (a[i] == NULL)	//Пока он не приобретет форму таблицы nXm
			exit(75);		//или нет n раз
	}
	cout << "Матрица инцидентности: " << endl<<"  ";
	for (int i = 0; i < m; i++) 
	{
		cout<< setw(2) <<"X"<< i+1;		//Печатаем
	}
	cout << endl;
	for (int i = 0; i < n; i++) 
	{
		cout<< "E" << i+1<<":";			//вводим
		for (int j = 0; j < m; j++) 
		{
			cin >> a[i][j];
		}
	}
}
void Incidence_print(int **a, int n, int m)	//Печатаем
{
	cout << "Ваша матрица инциндентности:" << endl<<"     ";
	for (int i = 0; i < m; i++) 
	{
		cout << setw(3) << "X" << i+1;
	}
	cout << endl;
	for (int i = 0; i < n; i++) //Печатаем
	{
		if (i < 9)
			cout << "E" << i + 1 << ": "; //Печатаем
		else cout << "E" << i + 1 << ":";
		for (int j = 0; j < m; j++) 
		{									//На часах скоро в универ 
			cout << right << setw(4) << a[i][j];	//Спокойной ночи
		}
		cout << endl;
	}
}												//Доброе у..."Смотрю на часы"
int** Incidence_to_Adjacency(int **arr, int n, int m)	//Проспал
{
	int** Adj=new int*[m];
	if (Adj == NULL)
		exit(74);
	for (int i = 0; i < m; i++) 
	{
		Adj[i] = new int [m];
		if (Adj[i] == NULL)
			exit(79);
		for (int j = 0; j < m; j++)
			Adj[i][j] = 0;
	}
	for (int i = 0; i < n; i++) 
	{	
		bool ok=false;
		int from = -1,to=-1;
		for (int j = 0; j < m && (from == -1 || to == -1); j++)
		{
			if (arr[i][j] == 2) 
			{
				from = j;
				to = j;
				ok = true;
			}
			else if (arr[i][j] == -1)
				from = j;
			else if (arr[i][j] == 1)
				to = j;
		}
		if (ok)
		{
			Adj[from][to] = 2;
		}
		else
			Adj[from][to] = 1;
	}
	return(Adj);

}
void Adjacency_print(int** A, int m) 
{
	cout << "Mатрица Cмежности:" << endl << "   ";
	for (int i = 0; i < m; i++)
	{
		cout << setw(2) << "X" << i + 1;
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		cout<<left<< "X" << i+1 << ":";
		for (int j = 0; j < m; j++)
		{
				cout << right << setw(3) << A[i][j];
		}
		cout << endl;
	}
}
vector<vector<int>> Adjacency_to_list(int** a, int n)
{
	vector<vector<int>>asmr(n);
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (a[i][j]) {
				int hehe = j+1;
				asmr[i].push_back(hehe);
			}
		}
		asmr[i].push_back(0);
	}
	return(asmr);
}
vector<vector<int>> Adjacency_list_input(int m)
{
	vector<vector<int>> adl(m); 
	cout << "Введите список смежности:" << endl;
	for (int i = 0; i < m; i++) 
	{
		cout << i+1 << ". - ";
		int vt = 1;
		while (vt) {
			cin >> vt;
			adl[i].push_back(vt);
		}
	}
	return(adl);
}
void Adjacency_list_print(vector<vector<int>> adl)
{
	cout << "Список смежности:"<<endl;
	for (int i = 0; i < adl.size(); i++) 
	{
		sort(adl[i].begin(), adl[i].end()-1);
		cout << i+1 << ". - ";
		for (int j = 0; j < adl[i].size(); j++)
		{
			cout << adl[i][j]<<" ";
		}
		cout << "\n";
	}
}
int count(vector<vector<int>> adl)
{
	int coutn = 0;
	for (int i = 0; i < adl.size(); i++)
		for (int j = 0; j < adl[i].size(); j++) 
		{
			if (adl[i][j])
				coutn++;
		}
	return coutn;
}
int** List_to_invidence(vector<vector<int>> adl,int &n,int &m) 
{	
	m = adl.size();
	n = count(adl);
	int** Inv=new int *[n];
	if (Inv == NULL)
		exit(233);
	for (int i = 0; i < n; i++) 
	{
		Inv[i] = new int[m];
		if (Inv[i] == NULL)
			exit(215);
		for (int j = 0; j < m; j++) 
		{
			Inv[i][j] = NULL;
		}
	}
	int cap=0;
	for (int i = 0; i < adl.size(); i++) 
	{
		int from = -1; int to=-1;
		for (int j = 0; j < adl[i].size() && (from==-1 || to==-1); j++) 
		{
			if (adl[i][j]) 
			{
				from = i;
				to = adl[i][j]-1;
			}
			if (adl[i][j] == i+1) 
			{
				Inv[cap++][from] = 2;
				from = -1;
				to = -1;
				continue;
			}
			if (from > -1) {
				Inv[cap][from] = -1;
				Inv[cap++][to] = 1;
				from = -1;
				to = -1;
			}
		}
	}
	return(Inv);
}
void delete_Ajective_matrix(int** &a, int n) //Ctrl+C
{
	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	a = NULL;
}
void delete_incorporated_matrix(int **&a, int n) //Ctrl+V
{
	for (int i = 0; i < n; i++) 
	{
		delete[]a[i];
	}
	delete[]a;
	a = NULL;
}