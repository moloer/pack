#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class Pack{

	private:
	
	public:	
		char pack_num[13]; //牌的初始化
		int pack[52]; //玩家选牌
		Pack(){
		//扑克初始化

			pack_num[0] = 'A';
			pack_num[1] = '2';
			pack_num[2] = '3';
			pack_num[3] = '4';
			pack_num[4] = '5';
			pack_num[5] = '6';
			pack_num[6] = '7';
			pack_num[7] = '8';
			pack_num[8] = '9';
			pack_num[9] = '1';
			pack_num[10] = 'J';
			pack_num[11] = 'Q';
			pack_num[12] = 'K';
		
			for(int i = 0; i < 52; i++)
			{
				pack[i] = 0;
			}
			srand((unsigned) time(NULL));
		}
		void colours(void){
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 13; j++)
				{
					int size;
					size = rand()%52;
					if(pack[size] != 0)
					{
						j--;
						continue;
					}
					pack[size] = i;
				}
			}
			
		}

};

class Player:public Pack{
	private:
	char player[4][13];
	public:
	void init(void)
	{
		for(int i = 0; i < 52; i++)
		{
			if(pack[i] == 0) //玩家1
			{
				player[pack[i]][i%13] = pack_num[i%13];			
				showflower(i%4);
				char c = (i%13==0&&i!=0)?'\n':' ';  
				cout<<player[pack[i]][i%13]<<c;
			}

		}
		for(int i = 0; i < 52; i++)
		{
			if(pack[i] == 1) //玩家2
			{
				player[pack[i]][i%13] = pack_num[i%13];
				showflower(i%4);
				char c = (i%13==0&&i!=0)?'\n':' ';  
				cout<<player[pack[i]][i%13]<<c;
			}
		}
		for(int i = 0; i < 52; i++)
		{
			if(pack[i] == 2) //玩家3
			{
				player[pack[i]][i%13] = pack_num[i%13];
				showflower(i%4);
				char c = (i%13==0&&i!=0)?'\n':' ';  
				cout<<player[pack[i]][i%13]<<c;
			}
		}
		for(int i = 0; i < 52; i++)
		{
			if(pack[i] == 3) //玩家4
			{
				player[pack[i]][i%13] = pack_num[i%13];
				showflower(i%4);
				char c = (i%13==0&&i!=0)?'\n':' ';  
				cout<<player[pack[i]][i%13]<<c;
			}
		}
	}
	void showflower(int a)
	{
		switch(a){
			 case 0: cout<<"红桃";break;
			 case 1: cout<<"方块";break;
       	     case 2: cout<<"梅花";break;
    		 case 3: cout<<"黑桃";break;
					}
	}
};




int main(void)
{
	Pack a;
	Player b;
	a.colours();
	b.init();
}
