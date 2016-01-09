#include <iostream>

using namespace std;




typedef struct
{
	int Id;
	int Balance;
	char Name[20];

}Account;

Account Accounts[100];
int Count = 0;

namespace BANK
{

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
		cin >> Accounts[Count].Id;
		cout << "이 름 : ";
		cin >> Accounts	[Count].Name;
		cout << "입금액 : ";
		cin >> Accounts[Count++].Balance;

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
			if (Id == Accounts[i].Id)
			{
				Accounts[i].Balance += Desposit;
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
			if (Id == Accounts[i].Id)
			{
				if (Accounts[i].Balance > Desposit)
				{
					Accounts[i].Balance -= Desposit;
					cout << "출금완료" << endl;
					return;
				}
				else
				{
					cout << "[Error] Checking Account Balance" << endl;
					return;
				}
			}
		}
		cout << "[Error] ID Not Found" << endl;
	}

	void Info()
	{
		for (int i = 0; i < Count; i++)
		{
			cout << "계좌ID: " << Accounts[i].Id << endl;
			cout << "이 름: " << Accounts[i].Name << endl;
			cout << "잔 액: " << Accounts[i].Balance << endl;
			cout << endl;
		}
	}

}

int main()
{
	int input;


	while (1)
	{
		BANK::ShowMenu();
		cin >> input;
		switch (input)
		{
			case 1 :
				BANK::CreateAccount();
				break;
			case 2 :
				BANK::Desposit();
				break;
			case 3 :
				BANK::WithDraw();
				break;
			case 4 :
				BANK::Info();
				break;
			case 5 :
				return 1;
			default :
				break;
		}
		

	}
	return 0;
}

