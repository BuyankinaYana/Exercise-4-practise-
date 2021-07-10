#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    string line;
    string Input_file_name;
    string c;
    string Output_file_name;
    vector<string> array_of_strings;

    //запрос пути к считываемому файлу
    if (argc==2)
    {
        Input_file_name=argv[1];
    }
    else
    {
        cout<<"Enter path to file"<<endl;
        cin>>Input_file_name;
    }


    //запрос пути к записываемому файлу
    if (argc==3)
    {
        Output_file_name=argv[2];
    }
    else
    {
        cout<<"Enter the address where you want to save the data"<<endl;
        cin>>Output_file_name;
    }

    //чтение из файла
    ifstream in;
    in.open(Input_file_name);
    while (getline(in,line))
    {
        cout<<line<<endl;
        array_of_strings.push_back(line);
    }
    in.close();

    //обработка методом пузырька
    for (int i=0; i<array_of_strings.size()-1; i++)
    {
        for (int j=i+1; j<array_of_strings.size(); j++)
        {
            if (array_of_strings.at(i)>array_of_strings.at(j))
            {
                c=array_of_strings.at(i);
                array_of_strings.at(i)=array_of_strings.at(j);
                array_of_strings.at(j)=c;
            }
        }
    }

    //вывод результата на экран
    cout<<" "<<endl;
    cout<<"Result"<<endl;
    cout<<" "<<endl;
    for (int i=0; i<array_of_strings.size(); i++)
    {
        cout<<array_of_strings.at(i)<<endl;
    }

    //запись файла
    ofstream out;
    out.open(Output_file_name);
    for (int i=0; i<array_of_strings.size(); i++)
    {
        out<<array_of_strings.at(i)<<endl;
    }
    out.close();
    return 0;
}
