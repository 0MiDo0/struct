#include <iostream>
#include <string>
using namespace std;
#include <ctime>

struct student
{
	string sName;
	int score;
};

struct teacher
{
	string tName;
	struct student s[5];	
};

void printInfo(struct teacher t[], int len)
{
	for (int i=0; i<len; i++)
	{
		cout << t[i].tName << endl;
		for (int j=0; j<5; j++)
		{
			cout <<"\t"<< t[i].s[j].sName << " Score = " << t[i].s[j].score << endl;
		}
	}
}


int main() {
	//1. setup array
	struct teacher t[3];
	int len = sizeof(t) / sizeof(t[0]);
	
	//2. give array value
	string nameSeed[3] = { "Tom","Jerry","Ben" };
	string nameSeed2 = "ABCDE";
	srand((unsigned int)time(NULL));

	for (int i=0; i<len; i++)
	{
		t[i].tName = "Teacher_";
		t[i].tName += nameSeed[i];
			
		for (int j = 0; j < 5; j++) 
		{
			t[i].s[j].sName = "Student_";
			t[i].s[j].sName += nameSeed2[j];
			
			int random = rand() % 61 + 40; //40~100
			t[i].s[j].score = random;
		}		
	}
	
	//3. print value
	printInfo(t, len);

	system("pause");
	return 0;
}