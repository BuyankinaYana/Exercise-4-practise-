#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    string a;
    string x;
    string c;
    string h;
    vector<string> v;

    //запрос имен файлов
    cout<<"Enter path to file"<<endl;
    cin>>x;
    cout<<"Enter the address where you want to save the data"<<endl;
    cin>>h;

    //чтение из файла
    ifstream in;
    in.open(x);
    while (!in.eof())
    {
        getline(in,a);
        cout<<a<<endl;
        v.push_back(a);
    }
    in.close();

    //обработка методом пузырька
    for (int i=0; i<v.size()-1; i++)
    {
        for (int j=i+1; j<v.size(); j++)
        {
            if (v.at(i)>v.at(j))
            {
                c=v.at(i);
                v.at(i)=v.at(j);
                v.at(j)=c;
            }
        }
    }

    //вывод результата на экран
    cout<<"Result"<<endl;
    cout<<" "<<endl;
    for (int i=0; i<v.size(); i++)
    {
        cout<<v.at(i)<<endl;
    }

    //запись файла
    ofstream out;
    out.open(h);
    for (int i=0; i<v.size(); i++)
    {
        out<<v.at(i)<<endl;
    }
    out.close();
    return 0;
}
