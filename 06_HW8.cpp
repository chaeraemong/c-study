#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

void parsingNameScores(iostream& fss)
{
	string name = "";
	int total(0), count(0), average(0), score(0);
	fss >> name;

	while (fss >> score)
	{
		count++;
		total += score;
	}

	if (count > 0)
		average = total / count;
	
	fss.clear();
	fss.seekp(0, ios::end);
	fss << endl << "Name : " << name << " Average : " << average;
}

int main()
{
	stringstream ss;
	ss.clear();
	ss.str("");
	string scores = "Luigi 70 100 90";
	ss << scores;
	parsingNameScores(ss);
	cout << ss.str() << endl;

	fstream fs;
	fs.open("testio.txt", ios::in | ios::out);
	if (!fs)
	{
		cout << "Open file failed." << endl;
		exit(1);
	}
	fs.clear();
	fs.seekp(0, ios::cur);
	parsingNameScores(fs);

	return 0;
}


/*
��Ʈ��Ŭ������ ����� ���Ͽ� ��� �Լ����� �����մϴ�.
stringstream�� fstream�� iostream���� �Ļ��Ǿ����ϴ�.

iostream ��ü fss�� �Ű������� ���� parsingNameScores�Լ��� ������ ���� �����մϴ�.
string���� name, int���� total, count, average, score�� �����ϰ� 0���� �ʱ�ȭ�մϴ�.
fss���� name�� �о����, fss ������ score�� �о���鼭 count�� +1, total�� score�� �����ݴϴ�.
count�� 0���� ũ�� average�� total���� count�� �����־� ����� �ݴϴ�.
seekp ����Լ��� �̿��Ͽ� fss������ �����ٿ� name�� average�� �����ݴϴ�.

main������ parsingNameScores�Լ��� �� �� ȣ���ϴµ� �ѹ��� stringstream�� �� �ѹ��� fstream���� �׽�Ʈ�մϴ�.
stringstream ��ü ss�� �����ϰ�, string ��ü scores�� ����, "Luigi 70 100 90"���� �ʱ�ȭ�մϴ�.
ss�� scores�� ���ݴϴ�.
parsingNameScores�Լ��� ���� ss�� �־� ȣ���մϴ�.
cout���� ss�� ���־� cmdâ�� ������ ���� ��Ÿ���� �մϴ�.
Luigi 70 100 90
Name: Luigi Average: 86

fstream ��ü fs�� �����ϰ� testio.txt ������ �����Ű�µ� �а� �� �� �ְ� ��带 ������ �ݴϴ�. ������ �� �о����� üũ�� �� �� �� parsingNameScores�Լ��� ���� fs�� �־� ȣ���մϴ�.

�����Ų �� testio.txt�� ������ �����ϴ�.
Luigi 70 100 90
Name: Luigi Average: 86
*/