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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 :";
}

void CreateAccount()
{
	int Id;
	int Balance;
	char Name[20];

	cout << "[계좌개설] " << endl;
	cout << "계좌ID :";
	cin >> Id;
	cout << "이 름 : ";
	cin >> Name;
	cout << "입금액 : ";
	cin >> Balance;

	Accounts[Count++] = new Account(Id, Balance, Name);

}

void Desposit()
{
	int Id;
	int Desposit;
	cout << "[입\t금]" << endl;
	cout << "계좌ID : ";
	cin >> Id;
	cout << "입금액 : ";
	cin >> Desposit;

	for (int i = 0; i < Count; i++)
	{
		if (Id == Accounts[i]->GetId())
		{
			Accounts[i]->Desposit(Desposit);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "[Error] ID Not Found" << endl;

}

void WithDraw()
{
	int Id;
	int Desposit;
	cout << "[출\t금]" << endl;
	cout << "계좌ID : ";
	cin >> Id;
	cout << "출금액 : ";
	cin >> Desposit;

	for (int i = 0; i < Count; i++)
	{
		if (Id == Accounts[i]->GetId())
		{
			if (Accounts[i]->WithDraw(Desposit))
			{
				cout << "출금완료" << endl;
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