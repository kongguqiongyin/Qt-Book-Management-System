#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class user
{
public:
	string userid;
	string mima;
	vector<string>jieshu;

	user(string id = "", string mi = "") :userid(id), mima(mi) {}
};
