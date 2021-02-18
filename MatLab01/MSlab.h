#pragma once
#include <iostream>		//����������� ���������� c++
#include <cstdlib>		//��� ������ system
#include <vector>		//��� ������ � ���������
#include <iomanip>		//setw() ��� ��������������
#include "windows.h"	//��� ����...� Sleep
#include <algorithm>
using namespace std;
void Menu()		//���� ������������ 3 �����
{
	cout << "-------------------------------" << endl;
	cout << "| 1.���� �����                |" << endl;
	cout << "| 2.����� �����               |" << endl;
	cout << "| 3.������ ������             |" << endl;
	cout << "| 4.����� �� ��������� (._.`) |" << endl;
	cout << "-------------------------------" << endl;
	cout << ">>> ";
}
void Choice()	//�� ������ ������ �������, ��� ����� ����������� � ������ ���������
{				//��� ������, ��� ����� ����������, � ��� �������� ������
	cout << "-----------------------------" << endl;
	cout << "| 1. ������� �������������  |" << endl;
	cout << "| 2. ������� ���������      |" << endl;
	cout << "| 3. ������ ���������       |" << endl;
	cout << "| 4. ��������� �����        |" << endl;
	cout << "-----------------------------" << endl;
	cout << ">>> ";			
}
void Adjacency_input(int **&Adj,int m) 
{
	Adj = new int*[m];				//�������� m ����� ������
	if (Adj == NULL) exit(31);		//��� �� ��������
	for (int i = 0; i < m; i++)		//�������� ��� ������ m ������
	{
		Adj[i] = new int[m];		//��� �� m �����
		if (Adj[i] == NULL)
			exit(36);
	}
	cout << "������� ������� ���������: " << endl << "  "; 
	for (int i = 0; i < m; i++)
	{										
		cout << setw(2) << "X" << i + 1;	//�� ���� ���� �� ���� ��������
	}										
	cout << endl;
	for (int i = 0; i < m; i++)				//������ ������� ���������
	{
		cout << "X" << i + 1 << ":";			
		for (int j = 0; j < m; j++)			//�������� ��� ���� ���������� ���������
		{
			cin >> Adj[i][j];				//�� ����� ������ ������� ����� ����������
		}
	}
}
void load(double n)	//��������.
{
	Sleep(1000 * n);
}//�������� �� n ������
void loading(int n, double f) 
{	
	for (int i = 0; i < n; i++)		//�������� �� ����� ��������
	{
		cout << "."; load(f);
	}
}//�������� �������� � n ����� � f ������ �������
void Incidence_input(int **&a,int n,int m)	//������ 2
{
	a = new int *[n];		//������� ���� ������� ������� 
	if (a == NULL) exit (70);
	for (int i = 0; i < n; i++) 
	{
		a[i] = new int[m];	//� �������� ����������� ������ �� ��� ���������
		if (a[i] == NULL)	//���� �� �� ���������� ����� ������� nXm
			exit(75);		//��� ��� n ���
	}
	cout << "������� �������������: " << endl<<"  ";
	for (int i = 0; i < m; i++) 
	{
		cout<< setw(2) <<"X"<< i+1;		//��������
	}
	cout << endl;
	for (int i = 0; i < n; i++) 
	{
		cout<< "E" << i+1<<":";			//������
		for (int j = 0; j < m; j++) 
		{
			cin >> a[i][j];
		}
	}
}
void Incidence_print(int **a, int n, int m)	//��������
{
	cout << "���� ������� ��������������:" << endl<<"     ";
	for (int i = 0; i < m; i++) 
	{
		cout << setw(3) << "X" << i+1;
	}
	cout << endl;
	for (int i = 0; i < n; i++) //��������
	{
		if (i < 9)
			cout << "E" << i + 1 << ": "; //��������
		else cout << "E" << i + 1 << ":";
		for (int j = 0; j < m; j++) 
		{									//�� ����� ����� � ������ 
			cout << right << setw(4) << a[i][j];	//��������� ����
		}
		cout << endl;
	}
}												//������ �..."������ �� ����"
int** Incidence_to_Adjacency(int **arr, int n, int m)	//�������
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
	cout << "M������ C��������:" << endl << "   ";
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
	cout << "������� ������ ���������:" << endl;
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
	cout << "������ ���������:"<<endl;
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