#include <iostream>
#include "oop2.h"

#pragma warning(disable:4996)

using namespace std;

Account::Account(int Id, int Balance, char* Name)
	: Id(Id), Balance(Balance)
{
	Account::Name = new char[strlen(Name) - 1];
	strcpy(Account::Name, Name);
}

int Account::GetId()
{
	return Account::Id;
}


void Account::Desposit(int Desposit)
{
	Account::Balance += Desposit;
}

void Account::Info()
{

		cout << "°èÁÂID: " << Account::Id << endl;
		cout << "ÀÌ ¸§: " << Account::Name << endl;
		cout << "ÀÜ ¾×: " << Account::Balance << endl;
		cout << endl;

}

bool Account::WithDraw(int WithDraw)
{
	if (Account::Balance < WithDraw)
	{
		return false;
	}
	Account::Balance -= WithDraw;
	return true;

}

