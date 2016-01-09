class Account
{
	private:
		int Id;
		int Balance;
		char *Name;
	public:
		Account(int Id, int Balance, char* Name);
		void Desposit(int Desposit);
		void Info();
		int GetId();
		bool WithDraw(int WithDraw);
		
		~Account()
		{
			delete []Name;
		}
};