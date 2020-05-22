/*
 * 密码锁　360
 * Author: zhiying
 * Date: 2020.5.21
 * Problem URL:https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3383&konwledgeId=42
 */

#include <iostream>
#include <cstring>

using namespace std;
class PasswordLock
{
public:
	PasswordLock();
	void input();
	void output();
private:
	string password;
	bool issymmetry();
	string result;
	void unlock();
};

PasswordLock::PasswordLock()
{
	result = "";
	password = "";
	
}


void PasswordLock::input() {
	
	string str;
    int i=0;
	while (cin>>str){
		password += str;
        
		if (i == 2){
		
			unlock();
			i = -1;
			password = "";
		}
		i++;
	}
}

bool PasswordLock::issymmetry() {
	bool issymmetry = true;

	for (int i =0;i<4;i++){

		if (password.at(i) != password.at(8-i)){
			issymmetry = false;
			break;
		}
		
	}
	return issymmetry;
}

void PasswordLock::unlock() {
	if (issymmetry()) {
		
		result = result + "YES\n";
	}
	else
	{
		
		result = result + "NO\n";
	}
}

void PasswordLock::output(){

	cout <<result;
}

int main()
{
   
	PasswordLock p;
	p.input();
	p.output();
}

