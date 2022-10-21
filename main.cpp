//本程序用于记录物品信息，同时有增删查改功能，方便居民查找、发布和交换物品
//by张益侨
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Object
{
    public:
        string name;
        string information;
};

Object object[256]; //全局变量，所有物品信息都在这个线性表中

int kindsOfObject()
//查看已经有多少种物品，为增删查改函数提供方便
{
    int num=0;
    while (object[num].name.length() != 0) ++num;
    return num;
}

void readTXT()
//将本地txt中的数据转化为Object类。按照saveTXT()的规则，\n与空格之间为名称，空格与\n之间为信息
{
    string objectList;
    ifstream in("object.txt");
    getline(in, objectList, '\0');
    in.close();
    int nameStart=0;
    int informationStart;
    int kind=0;
    for (int i=0; i<objectList.length(); ++i)
    {
        if (objectList[i] == ' ')
        {
            object[kind].name = objectList.substr(nameStart,i-nameStart);
            informationStart = i+1;
        }
        if (objectList[i] == '\n')
        {
            object[kind].information = objectList.substr(informationStart,i-informationStart);
            nameStart = i+1;
            ++kind;
        }
    }

}

void displayObject()
//显示物品列表
{
    int num=0;
    cout << "当前所有物品的信息为：" << endl;
    while (object[num].name.length() != 0)
    {
        cout << object[num].name << "    " << object[num].information <<endl;
        ++ num;
    }
}

void addObject()
//添加物品
{
    int num = kindsOfObject();
    cout << "需要添加的物品名称为：" << endl;
    cin >> object[num].name;
    cout << "需要添加该物品的信息为：" << endl;
    cin >> object[num].information;
}

int* findObjectPosition(const string& name)
//输入名字，查找所有相同名称的物品在线性表中的位置
{
    int* position = new int[256];
    int i=0;
    int j=0;
    for (i=0; i<256; ++i)
    {
        if (object[i].name == name)
        {
            position[j] = i;
            ++j;
        }
    }
    position[j] = -1;
    return position;
}

void findObject()
//查找物品，封装findObjectPosition()
{
    cout << "需要查找的物品名称为：" << endl;
    string name;
    cin >> name;
    int* position = findObjectPosition(name);
    if (position[0] == -1) cout << "暂无该物品信息" <<endl;
    else
    {
        for (int i=0; position[i] != -1; ++i)
            cout << object[position[i]].name << "    " << object[position[i]].information <<endl;
    }
    delete[] position;
}

void deleteObject()
//删除物品
{
    cout << "需要删除的物品名称为：" << endl;
    string name;
    cin >> name;
    int* position = findObjectPosition(name);
    if (position[0] == -1) cout << "暂无该物品信息，无法删除" <<endl;
    else
    {
        for (int i=0; position[i] != -1; ++i)
            cout << object[position[i]].name << "    " << object[position[i]].information <<endl;
        cout << "需要删除的物品信息为第几项？" << endl;
        int del;
        cin>>del;
        int num = kindsOfObject();
        for (int i=position[del-1]; i<num; ++i)
        {
            object[i].name = object[i+1].name;
            object[i].information = object[i+1].information;
        }
    }
    delete[] position;
}

void saveTXT()
//将Object类数据转化为txt存储。\n与空格之间为名称，空格与\n之间为信息
{
    string objectList;
    for (int i=0; object[i].name.length() != 0; ++i)
    {
        objectList += object[i].name;
        objectList += ' ';
        objectList += object[i].information;
        objectList += '\n';
    }
    ofstream out;
    out.open("object.txt");
    out<<objectList;
    out.close();
}

int main()
{
    readTXT();
    while (true)
    {
        cout << "您需要进行的操作为：" << endl << "0：退出程序" << endl << "1：添加物品" << endl << "2：删除物品" << endl
             << "3：显示物品列表" << endl << "4：查找物品信息" << endl;
        int operation;
        cin >> operation;
        switch (operation)
        {
            case 1: addObject(); break;
            case 2: deleteObject(); break;
            case 3: displayObject(); break;
            case 4: findObject(); break;
        }
        saveTXT();
        if (operation == 0) break;
    }
    return 0;
}
