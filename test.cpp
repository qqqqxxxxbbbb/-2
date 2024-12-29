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
	//�˵����100����
	dish cai[100];
	int size;
	char filename[100];
};
//��˵�����Ӳ�Ʒ
void addDish(menu* caidan) {
	cout << "��Ʒ���ƣ�";
	cin >> caidan->cai[caidan->size].name;
	cout << "�۸�:";
	cin >> caidan->cai[caidan->size].price;
	caidan->size++;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}
//չʾ�˵�
void showdishmenu(menu* caidan) {
	if (caidan->size == 0) {
		cout << "�޲˵�" << endl;
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
//����˵����ļ�
void savetoFile(menu* caidan, char* filename) {
	ofstream outfile(filename);
	if (outfile.is_open()) {
		for (int i = 0; i < caidan->size; i++) {
			outfile << caidan->cai[i].name << " " << caidan->cai[i].price << endl;
		}
		outfile.close();
		cout << "�ѱ��浽�ļ�" << endl;
	}
	else {
		cout << "�޷����ļ�" << endl;
	}
	system("pause");
	system("cls");
}
//��ѯ��Ʒ�Ƿ����
int isExit(menu* caidan, char* name) {
	for (int i = 0; i < caidan->size; i++) {
		if (!(strcmp(caidan->cai[i].name, name)))
			return i;
	}
	return -1;
}
//ɾ���˵��еĲ�Ʒ
void deleteDish(menu* caidan) {
	cout << "����ɾ����Ʒ����";
	char name[100];
	cin >> name;
	int ret = isExit(caidan, name);
	if (ret != -1) {
		for (int i = ret; i < caidan->size; i++) {
			caidan->cai[i] = caidan->cai[i + 1];
		}
		caidan->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else cout << "δ�ҵ���ز�Ʒ" << endl;
	system("pause");
	system("cls");
}
//�޸Ĳ˵��еĲ�Ʒ
void changeDish(menu* caidan) {
	cout << "����Ҫ�޸ĵ�����";
	char name[100];
	cin >> name;
	int ret = isExit(caidan, name);
	if (ret != -1) {
		cout << "�������޸ĺ������";
		char changeName[100];
		cin >> changeName;
		strcpy(caidan->cai[ret].name, changeName);
		cout << "�������޸ĺ�ļ۸�";
		int newPrice;
		cin >> newPrice;
		caidan->cai[ret].price = newPrice;
	}
	else cout << "δ�ҵ��ò�Ʒ" << endl;
	system("pause");
	system("cls");

}
//ϵͳ����Ա�Բ˵�����
void shezhimenu(menu* caidan, char* filename) {
	while (1) {
		cout << "�����Ӧ����" << endl;
		cout << "1.�����Ʒ" << endl;
		cout << "2.ɾ����Ʒ" << endl;
		cout << "3.�޸Ĳ�Ʒ" << endl;
		cout << "4.�鿴��Ʒ" << endl;
		cout << "5.���浽�ļ�" << endl;
		cout << "0.�˳�" << endl;
		int n; cin >> n;
		switch (n) {
		case 1:
			addDish(caidan);
			break;
		case 2:
			cout << "�������ƣ�";
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
//չʾҳ��
void showmenu() {
	cout << "��������ر��" << endl;
	cout << "1.�˿�" << endl;
	cout << "2.��ʦ" << endl;
	cout << "3.����Ա" << endl;
	cout << "4.ϵͳ����Ա" << endl;
	cout << "5.����Ա" << endl;
	cout << "6.�ϰ�" << endl;
	cout << "0.�˳�ϵͳ" << endl;
}
//ϵͳ����Ա��Կ123����¼����
int signIn() {
	cout << "��������Կ" << endl;
	int k = 123;
	int cishu = 3;
	int key;
	while (cishu != 0) {
		cin >> key;
		if (key == k) break;
		else {
			cout << "�������" << endl;
			cout << "�㻹��" << cishu-1 << "�λ���";
			cishu--;
		}
	}
	if (cishu != 0) {
		cout << "�ɹ���½" << endl;
		system("pause");
		system("cls");
		return 1;
	}
	else {
		cout << "��¼ʧ��" << endl;
		return 0;
	}
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
			cout << "�����˳�ϵͳ" << endl;
			return 0;
		}
		shezhimenu(&caidan, filename);
		break;
	case 5:
		break;
	case 6:
		break;
	case 0:
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		return 0;
	}

}
