#include "oop2.h"
#include <iostream>

using namespace std;

void ShowMenu();
void CreateAccount();
void Desposit();
void WithDraw();
void Info();

Account * Accounts[100];
int Count = 0;

int main()
{
	int input;

	while (true)
	{
		ShowMenu();
		cin >> input;
		switch (input)
		{
		case 1:
			CreateAccount();
			break;
		case 2:
			Desposit();
			break;

		case 3:
			WithDraw();
			break;

		case 4:
			Info();
			break;

		case 5:
			return 1;

		default:
			break;
		}



	}


}

void ShowMenu()
{
	cout << "----- Menu -----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� :";
}

void CreateAccount()
{
	int Id;
	int Balance;
	char Name[20];

	cout << "[���°���] " << endl;
	cout << "����ID :";
	cin >> Id;
	cout << "�� �� : ";
	cin >> Name;
	cout << "�Աݾ� : ";
	cin >> Balance;

	Accounts[Count++] = new Account(Id, Balance, Name);

}

void Desposit()
{
	int Id;
	int Desposit;
	cout << "[��\t��]" << endl;
	cout << "����ID : ";
	cin >> Id;
	cout << "�Աݾ� : ";
	cin >> Desposit;

	for (int i = 0; i < Count; i++)
	{
		if (Id == Accounts[i]->GetId())
		{
			Accounts[i]->Desposit(Desposit);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "[Error] ID Not Found" << endl;

}

void WithDraw()
{
	int Id;
	int Desposit;
	cout << "[��\t��]" << endl;
	cout << "����ID : ";
	cin >> Id;
	cout << "��ݾ� : ";
	cin >> Desposit;

	for (int i = 0; i < Count; i++)
	{
		if (Id == Accounts[i]->GetId())
		{
			if (Accounts[i]->WithDraw(Desposit))
			{
				cout << "��ݿϷ�" << endl;
			}
			else
			{
				cout << "[Error] Checking Account Balance" << endl;
			}
		
		}
	}
	cout << "[Error] ID Not Found" << endl;
}

void Info()
{

	for (int i = 0; i < Count; i++)
	{
		Accounts[i]->Info();
	}

}