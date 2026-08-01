#pragma once
#include<iostream>
#include<string>
using namespace std;
class book
{
public:
	string m_shuming;//书名
	string m_shuhao;//书号
	string m_diyi;//第一作者
	string m_banci;//版次
	string m_chubanshe;//出版社
	string m_nianyue;//出版年月
	bool m_zhuangtai;//状态


	void setshuming(string a);
	
	string getshuming();
	
	void setshuhao(string b);
	
	string getshuhao();
	

	void setdiyi(string c);
	
	string getdiyi();
	

	void setbanci(string d);
	
	string getbanci();


	void setchubanshe(string e);
	
	string getchubanshe();
	
	void setnianyue(string f);
	
	string getnianyue();
	
	void setzhuangtai(bool g);
	
	bool getzhuangtai();
	
};


