#include<iostream>
#include<string>
#include<vector>
#include"book.h"
#include"user.h"
using namespace std;

vector<book> books;
vector<user> users;

//1新进图书基本信息的输入。
void stream_1()
{

	book a1;
	string a;
	cout << "请输入书名" << endl;
	cin >> a;
	a1.setshuming(a);
	cout << "书名：" << a << endl;

	string b;
	cout << "请输入书号" << endl;
	cin >> b;
	a1.setshuhao(b);

	cout << "书号：" << b << endl;

	string c;
	cout << "请输入第一作者" << endl;
	cin >> c;
	a1.setdiyi(c);
	cout << "第一作者：" << c << endl;

	string d;
	cout << "请输入版次" << endl;
	cin >> d;
	a1.setbanci(d);
	cout << "版次：" << d << endl;

	string e;
	cout << "请输入出版社" << endl;
	cin >> e;
	a1.setchubanshe(e);
	cout << "出版社：" << e << endl;

	string f;
	cout << "请输入出版年月" << endl;
	cin >> f;
	a1.setnianyue(f);
	cout << "出版年月：" << f << endl;

	a1.m_zhuangtai = false;

	books.push_back(a1);
	cout << "图书添加成功！\n";
}

//4为借书人办理注册。
void stream_4()
{
	user br;
	cout << "输入借书人ID：";
	cin >> br.userid;
	cout << "输入借书人密码：";
	cin >> br.mima;
	users.push_back(br);
	cout << "借书人注册成功！\n";
}

//2图书基本信息的查询。
void stream_2() 
{
	string id;
	cout << "输入要查询的书号：";
	cin >> id;
	for (auto& b : books) {
		if (b.m_shuhao == id) {
			cout << "书名：" << b.m_shuming << " 作者：" << b.m_diyi
				<< " 版次：" << b.m_banci << " 出版社：" << b.m_chubanshe
				<< " 出版时间：" << b.m_nianyue
				<< " 状态：" << (b.m_zhuangtai ? "已借出" : "可借阅") << endl;
			return;
		}
	}
	cout << "未找到该图书！\n";
}

//3对图书信息的删除
void stream_3() 
{
	string id;
	cout << "输入要删除的书号：";
	cin >> id;
	for (int i = 0; i < books.size(); i++) {
		if (books[i].m_shuhao == id) 
		{
			if (books[i].m_zhuangtai) 
			{
				cout << "图书已借出，无法删除！\n";
				return;
			}
			books.erase(books.begin() + i);
			cout << "图书删除成功！\n";
			return;
		}
	}
	cout << "未找到该图书！\n";
}

//5.办理借书
void stream_5() {
	string uid, bid;
	cout << "请输入用户id" << endl;
	cin >> uid;
	cout << "请输入书号" << endl;
	cin >> bid;

	bool t = false;
	for (auto& a : users) {
		if (a.userid == uid)
		{
			t = true;
		}
		if (!t) 
		{
			cout << "未注册" << endl;
			return;
		}
	}

	for (auto& b : books)
	{
		if (b.m_shuhao == bid)
		{
			if (!b.m_zhuangtai)
			{
				cout << "成功借出";
				b.m_zhuangtai = true;
				return;
			}
			cout << "已经借出了" << endl;
		}
	}
	cout << "未找到该图书！" << endl;
}
//6.办理还书
void stream_6() {
	string bid;
	cout << "输入要还的图书书号："; cin >> bid;
	for (auto& b : books) {
		if (b.m_shuhao == bid) {
			if (!b.m_zhuangtai)
			{
				cout << "图书未借出！\n";
				return;
			}
			b.m_zhuangtai = false;
			cout << "还书成功！\n";
			return;
		}
	}
	cout << "未找到该图书！\n";
}

void start()
{
	cout << "\n=====图书管理系统=====\n";
	cout << "1.新书登记\n";
	cout << "2.信息查询\n";
	cout << "3.删除图书\n";
	cout << "4.用户注册\n";
	cout << "5.办理借书\n";
	cout << "6.办理还书\n";
	cout << "0.退出系统\n";
}

int main()
{
	int xuanze;
	while (1)
	{
		start();
		cin >> xuanze;
		switch (xuanze)
		{
		case 1:
			stream_1();
			break;
		case 2:
			stream_2();
			break;
		case 3:
			stream_3();
			break;
		case 4:
			stream_4();
			break;
		case 5:
			stream_5();
			break;
		case 6:
			stream_6();
			break;
		case 0:
			cout << "退出系统" << endl;
			return 0;
		default:
			cout << "输入错误，请重新选择！\n";
		}
	}
	
}
