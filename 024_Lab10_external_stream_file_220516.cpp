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
스트림클래스는 상속을 통하여 멤버 함수들을 공유합니다.
stringstream과 fstream은 iostream에서 파생되었습니다.

iostream 객체 fss를 매개변수로 갖는 parsingNameScores함수를 다음과 같이 정의합니다.
string형의 name, int형의 total, count, average, score를 선언하고 0으로 초기화합니다.
fss에서 name을 읽어오고, fss 끝까지 score를 읽어오면서 count를 +1, total에 score를 더해줍니다.
count가 0보다 크면 average는 total에서 count를 나눠주어 계산해 줍니다.
seekp 멤버함수를 이용하여 fss끝에서 다음줄에 name과 average를 적어줍니다.

main에서는 parsingNameScores함수를 두 번 호출하는데 한번은 stringstream로 또 한번은 fstream으로 테스트합니다.
stringstream 객체 ss를 선언하고, string 객체 scores를 선언, "Luigi 70 100 90"으로 초기화합니다.
ss에 scores를 써줍니다.
parsingNameScores함수에 인자 ss를 넣어 호출합니다.
cout으로 ss를 써주어 cmd창에 다음과 같이 나타나게 합니다.
Luigi 70 100 90
Name: Luigi Average: 86

fstream 객체 fs를 선언하고 testio.txt 파일을 연결시키는데 읽고 쓸 수 있게 모드를 세팅해 줍니다. 파일을 잘 읽었는지 체크를 해 준 후 parsingNameScores함수에 인자 fs를 넣어 호출합니다.

실행시킨 후 testio.txt는 다음과 같습니다.
Luigi 70 100 90
Name: Luigi Average: 86
*/
