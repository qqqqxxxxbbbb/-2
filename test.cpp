#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;
struct dish {
	char name[100];
	int price;
};
struct menu {
	//菜单最多100个菜
	dish cai[100];
	int size;
	char filename[100];
};
//向菜单中添加菜品
void addDish(menu* caidan) {
	cout << "菜品名称：";
	cin >> caidan->cai[caidan->size].name;
	cout << "价格:";
	cin >> caidan->cai[caidan->size].price;
	caidan->size++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}
//展示菜单
void showdishmenu(menu* caidan) {
	if (caidan->size == 0) {
		cout << "无菜单" << endl;
		system("pause");
		system("cls");
	}
	else {
		for (int i = 0; i < caidan->size; i++) {
			cout << setw(8) << caidan->cai[i].name << setw(5) << caidan->cai[i].price;
			cout << endl;
		}
		system("pause");
		system("cls");
	}

}
//保存菜单到文件
void savetoFile(menu* caidan, char* filename) {
	ofstream outfile(filename);
	if (outfile.is_open()) {
		for (int i = 0; i < caidan->size; i++) {
			outfile << caidan->cai[i].name << " " << caidan->cai[i].price << endl;
		}
		outfile.close();
		cout << "已保存到文件" << endl;
	}
	else {
		cout << "无法打开文件" << endl;
	}
	system("pause");
	system("cls");
}
//查询菜品是否存在
int isExit(menu* caidan, char* name) {
	for (int i = 0; i < caidan->size; i++) {
		if (!(strcmp(caidan->cai[i].name, name)))
			return i;
	}
	return -1;
}
//删除菜单中的菜品
void deleteDish(menu* caidan) {
	cout << "输入删除菜品名称";
	char name[100];
	cin >> name;
	int ret = isExit(caidan, name);
	if (ret != -1) {
		for (int i = ret; i < caidan->size; i++) {
			caidan->cai[i] = caidan->cai[i + 1];
		}
		caidan->size--;
		cout << "删除成功" << endl;
	}
	else cout << "未找到相关菜品" << endl;
	system("pause");
	system("cls");
}
//修改菜单中的菜品
void changeDish(menu* caidan) {
	cout << "输入要修改的名称";
	char name[100];
	cin >> name;
	int ret = isExit(caidan, name);
	if (ret != -1) {
		cout << "请输入修改后的名称";
		char changeName[100];
		cin >> changeName;
		strcpy(caidan->cai[ret].name, changeName);
		cout << "请输入修改后的价格";
		int newPrice;
		cin >> newPrice;
		caidan->cai[ret].price = newPrice;
	}
	else cout << "未找到该菜品" << endl;
	system("pause");
	system("cls");

}
//系统管理员对菜单设置
void shezhimenu(menu* caidan, char* filename) {
	while (1) {
		cout << "输入对应编码" << endl;
		cout << "1.加入菜品" << endl;
		cout << "2.删除菜品" << endl;
		cout << "3.修改菜品" << endl;
		cout << "4.查看菜品" << endl;
		cout << "5.保存到文件" << endl;
		cout << "0.退出" << endl;
		int n; cin >> n;
		switch (n) {
		case 1:
			addDish(caidan);
			break;
		case 2:
			cout << "输入名称：";
			deleteDish(caidan);
			break;
		case 3:
			changeDish(caidan);
			break;
		case 4:
			showdishmenu(caidan);
			break;
		case 5:
			savetoFile(caidan, filename);
			break;
		case 0:
			return;
		}
	}
}
//展示页面
void showmenu() {
	cout << "请输入相关编号" << endl;
	cout << "1.顾客" << endl;
	cout << "2.厨师" << endl;
	cout << "3.服务员" << endl;
	cout << "4.系统管理员" << endl;
	cout << "5.收银员" << endl;
	cout << "6.老板" << endl;
	cout << "0.退出系统" << endl;
}
//系统管理员密钥123，登录函数
int signIn() {
	cout << "请输入密钥" << endl;
	int k = 123;
	int cishu = 3;
	int key;
	while (cishu != 0) {
		cin >> key;
		if (key == k) break;
		else {
			cout << "密码错误" << endl;
			cout << "你还有" << cishu-1 << "次机会";
			cishu--;
		}
	}
	if (cishu != 0) {
		cout << "成功登陆" << endl;
		system("pause");
		system("cls");
		return 1;
	}
	else {
		cout << "登录失败" << endl;
		return 0;
	}
}
void guke()
{
	cout<<"请输入人数"<<endl;
}
int main() {   
	showmenu();
	int n;
	cin >> n;
	struct menu caidan;
	caidan.size = 0;
	char filename[] = "menu.txt";
	switch (n) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		if (!signIn()) {
			cout << "错误，退出系统" << endl;
			return 0;
		}
		shezhimenu(&caidan, filename);
		break;
	case 5:
		break;
	case 6:
		break;
	case 0:
		cout << "欢迎下次使用" << endl;
		system("pause");
		return 0;
	}

}
