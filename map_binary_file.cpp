#include <iostream>
#include <map>
#include <fstream>

using namespace std;

void printUi();

struct wordsBin {
  int num;
  string word;
  int flag;
};

int main()
{
    map<int, map<string, int> > wordMap;
    //inserting
    wordMap.insert(make_pair(1, map<string, int>()));
    wordMap[1].insert(make_pair("word", 0));
    wordMap.insert(make_pair(2, map<string, int>()));
    wordMap[2].insert(make_pair("word2", 0));
    printUi();
 map<int, map<string, int> >::iterator itr;
    map<string, int>::iterator ptr;
    wordsBin s;
    s.num = 1;
    s.word = "word";
    s.flag = 0;

    cout << s.num << " " << s.word << " " << s.flag << "\n";

    //regular file
    fstream b("intout.bin",ios::out|ios::binary);
    int id;
    string letters;
    int flag;
        for (itr = wordMap.begin(); itr != wordMap.end(); itr++) {
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
        id = itr->first;
		letters =   ptr->first;
		flag =   ptr->second;
            b<<id << " ";
            b<<letters << " ";
            b<< flag << endl;

        }
    }
    b.close();


/*
    map<int, map<string, int> > wordMap;
    //inserting
    wordMap.insert(make_pair(1, map<string, int>()));
    wordMap[1].insert(make_pair("word", 0));
    wordMap.insert(make_pair(2, map<string, int>()));
    wordMap[2].insert(make_pair("word2", 0));

    //printing
    map<int, map<string, int> >::iterator itr;
    map<string, int>::iterator ptr;

    for (itr = wordMap.begin(); itr != wordMap.end(); itr++) {
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            cout << "First key is " << itr->first
                 << " And second key is " << ptr->first
                 << " And value is " << ptr->second << endl;
        }
    }

    fstream b("intout.bin",ios::out|ios::binary);
    int id;
    string letters;
    int flag;
        for (itr = wordMap.begin(); itr != wordMap.end(); itr++) {
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
                        id = itr->first;
		letters =   ptr->first;
		flag =   ptr->second;
            f<<id << " ";
            f<<letters << " ";
            f<< flag << endl;
            b<<itr->first << " ";
            b<<ptr->first << " ";
            b<< ptr->second << endl;
        }
    }
    f.close();
    */

/*
    //regular file
    fstream f("intout.txt",ios::out);
        for (itr = wordMap.begin(); itr != wordMap.end(); itr++) {
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            f<<itr->first << " ";
            f<<ptr->first << " ";
            f<< ptr->second << endl;
        }
    }
    f.close();
*/





//const int MAX_NAME_SIZE = 15;


	//char name[MAX_NAME_SIZE];
	//std::cin.getline(name, MAX_NAME_SIZE);

	//std::cout << name << std::endl;
	//return 0;
}

void printUi(){
cout << "1.Logically delete one record\n";
cout << "2.Print all non-deleted records\n";
cout << "3.Print all records\n";
cout << "4.Purge deleted records\n";
}
