#include<iostream>
#include<windows.h> // system ��� 
#include<conio.h> // kbhit ��� 
#include<stdlib.h> // sleep ��� 
#include<string> //��Ʈ�� ��¿�
using namespace std;

class Player
{
	int Lv;
	int Exp;
	int MaxHp = 100; // �ִ� ü�� ������ �����ڿ��� �ݷ��ʱ�ȭ ���� 
	int G_Hp = MaxHp; // G_Hp(Game_Hp��� ��) ���ӿ� ���� ���� ü�� ������ ���� �� 
	string Name = "������"; // �÷��̾��� �̸��� ������ ���� 
public:
	Player() : Lv(0), Exp(0) {}
	void LvUp(int ex)
	{
		Exp += ex;
		while (Exp >= 100)
		{
			Exp -= 100;
			Lv++;
		}
		std::cout << "LV : " << Lv << " exp : " << Exp << std::endl;
	}
	void Death_Check()// ������ �˻��ϴ� �� 
	{
		if (G_Hp <= 0) // ���� ü���� 0���� �۰ų� ������ 
		{
			GameOver(); // ���� ������ ȣ�� 
		}
	}
	void GameOver()
	{
		char check;
		int i;
		for (i = 10; i >= 0; i--)
		{
			system("cls");// ȭ���� ���� windows ��� �ʿ� 
			cout << "[[ " << Name << " ��(��) ����Ͽ����ϴ� !! ]]" << endl;
			cout << "\n[[ �絵�� �Ͻðڽ��ϱ�? ( Y / N ) ]]" << endl;
			cout << "\t" << i << endl; // 10���� 0���� �������� �ʸ� ��Ÿ���� 
			Sleep(1000); // ���ǽð� 1�� 
			if (kbhit() != 0)  // Ű���尡 �ԷµǸ� ���߰� �ϱ����Ͽ� 
			{
				system("cls"); // ���� �������� ����� 
				break; // for���� Ż�� 
			}
		}
		if (i == -1) // �ð����� �ƹ��� �Է��� ���� �ʾ��� �� 
		{
			system("cls");
			cout << "[[ ������ �����ϰڽ��ϴ� ]]" << endl;
			system("pause"); // ���� ���� ��¹��� �ѹ� Ȯ�� �ϱ� ���Ͽ� 
			exit(1);
		}
		while (1)
		{
			cin >> check;
			if (check == 'Y' || check == 'y')
			{
				G_Hp = MaxHp;
				break;
			}
			else if (check == 'N' || check == 'n')
			{
				//������ ����� �������� ���� ���	
				system("cls");
				cout << "[[ ������ �����ϰڽ��ϴ� ]]" << endl;
				system("pause");
				exit(1);
			}
			else
			{
				cout << "[[ �߸� �Է��ϼ̽��ϴ�( Y / N �� �Է��Ͻʽÿ�) ]]" << endl;
			}
		}

	}

	void Attacked(int a)
	{
		system("cls");
		cout << "[[ " << Name << "��(��) " << a << "��ŭ �������� �Ծ����ϴ� ]]" << endl;
		G_Hp -= a;
		Death_Check();
		cout << "[[ " << Name << "�� ���� ü�� : " << G_Hp << " ]]" << endl;
		system("pause");
	}
};

int main(void)
{
	Player a;
	while (1)
	{
		a.Attacked(rand() % 25 + 10);
	}
}
