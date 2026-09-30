// sep29 in class vector core ops.cpp
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class t>
void showVector(const vector<t>& v, string name = "")
{
	cout << endl << name << " size: " << v.size() << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << "element " << i << " " << "[" << v[i] << "]" << endl;
	}

}

void experiment01()
{


	vector<int> v1{ 11, 22, 33, 44, 55 };
	showVector(v1, "v1 vector<int>");

	vector<string> v2{ "homer", "bart", "lisa" };
	showVector(v2, "v2 vector<string>");

	v1.push_back(66);
	v1.push_back(77);
	showVector(v1, "v1 vector<int>");



	cout << "\nfirst: " << v1[0] << endl;
	cout << "last: " << v1[v1.size() - 1] << endl;

	v1.pop_back();
	v1.pop_back();
	v1.pop_back();

	showVector(v1, "v1 vector<int>");

	//vector<int> ::iterator it1 = v1.begin();

	// this is how you create the iterator

	auto it1 = v1.begin();


	// traversing using the iterator!!

	cout << "\ntraversing using iterator: " << endl;

	while (it1 < v1.end())
	{
		cout << *it1 << endl;
		it1++;

	}

	// inserting a new item as first cell of the vector 

	auto it2 = v1.begin();
	v1.insert(it2, 67);
	showVector(v1, "v1 vector<int>");

	// insert 42069 at location 3 without destroying existing data

	it2 = v1.begin();
	v1.insert(it2 + 3, 42069);
	showVector(v1, "v1 vector<int>");

	// erase cell #2

	v1.erase(v1.begin() + 2);
	showVector(v1, "v1 vector<int>");

	vector<int> v3;

	v3.reserve(10);




}

void experiment02()
{
	// my people collection, (name length > 2)

	vector<string> names;

	char again = 'y';

	string name;
	
	while (again == 'y')
	{

		try
		{
			cout << "please enter the name of someone that you love :3 (name length > 2)" << endl;
			getline(cin, name);

			if (name.size() <= 2)
			{
				throw runtime_error("name is too short");
			}

			names.push_back(name);
		}

		catch (const exception& e)
		{
			cout << "error: " << e.what() << endl;
			cout << "try again :3" << endl;

		}
		
		cout << "would you like to continue? :3 (y/n)" << endl;
		cin >> again;
		cin.ignore();


	}

	showVector(names, "the people I love");

}

int main()
{


	//experiment01();

	experiment02();



	cout << "\nall done :3" << endl;


}


