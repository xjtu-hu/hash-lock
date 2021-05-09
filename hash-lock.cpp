#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include "newstruct.h"
using namespace std;
class sur;

//本次使用hash算法为KEY除5商a余b，hash（KEY）=10*a+b
int gethash(int KEY) {
	int a = KEY / 5;
	int b = KEY % 5;
	return 10 * a + b;
}
class tar {
private:
	vector<target> cli;
public:
	friend class sur;
	void match(int key1,int metal) {
		for (target temp : cli) {
			if (temp.metalid == metal) {
				if (gethash(key1) == metal) {
					cout <<"ID:"<<temp.id<< " match successfuly" << endl;
				}
			}
		}
	}
};
tar client;
class sur {
private: 
	friend int gethash(int KEY);
	vector<survice> datebase;
public:
	void setclient(tar &a,int b,int c) {
		target temp1;
		temp1.metalid = b;
		temp1.id = c;
		a.cli.push_back(temp1);
	}
	void insertID(int ID) {
		survice temp;
		srand(ID);
		temp.id = ID;
		temp.key = rand();
		temp.metalid = gethash(temp.key);
		datebase.push_back(temp);
		setclient(client ,temp.metalid, temp.id);
		cout <<"ID:"<<ID<< " add successfully with metalid"<<temp.metalid << endl;
		return;
	}
	int findkey(int metal) {
		for (survice temp : datebase) {
			if (temp.metalid == metal) {
				cout << "find key:" << temp.key << " for metalid:" << metal << endl;
				return temp.key;
			}
		}
		cout << "cannot find" << endl;
		return -1;
	}
};
bool flag = true;
sur date;
void readline() {
	char a[20];
	cin.getline(a,20);
	if (a[0] == 'a' && a[1] == 'd' && a[2] == 'd') {
		int id=0;
		//cout << strlen(a)<<endl;
		for (unsigned int i = 3; i < strlen(a); i++) {
			id = id * 10 + (int)(a[i] - '0');
		}
		date.insertID(id);
	}
	else if (a[0] == 'r' && a[1] == 'e' && a[2] == 'a' && a[3] == 'd') {
		int metalid = 0;
		for (unsigned int i = 4; i < strlen(a); i++) {
			metalid = metalid * 10 + (int)(a[i] - '0');
		}
		int hashkey = date.findkey(metalid);
		if (hashkey != -1) {
			client.match(hashkey, metalid);
		}
	}
	else if (a[0] == 'e') {
		flag=false;
	}
}
//使用add添加具有新ID的标签，返回该ID在服务器中分配到metalid
//使用read阅读标签，阅读的值为该标签对应的metalid
//输入e退出程序
int main() {
	cout << "使用add添加具有新ID的标签" << endl;
	cout << "使用read阅读标签，阅读的值为该标签对应的metalid" << endl;
	cout << "输入e退出程序" << endl;
	cout << "例如：添加ID为12的标签，返回ID:12 add successfully with metalid152" << endl;
	cout << "阅读器阅读到metalid=152的标签即可进行匹配，返回：find key:77 for metalid:152" << endl;
	cout << "ID:12 match successfuly" << endl;
	cout << "阅读到的metalid查找不到则返回cannot find" << endl;
	while (flag) {
		readline();
	}
	return 0;
}
