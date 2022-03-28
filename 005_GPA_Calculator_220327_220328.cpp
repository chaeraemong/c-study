#include <iostream>
using namespace std;

class GPA
{
public:
	void inputSubjectNumber();
	int subjectNumber = 1;
	double totalscore = 0;												// sum(credit*score)
	int totalcredit = 0;
	double gpa = 0;
	void output();
private:
};

double ScoreOfGrade4_3(char grades1, int I);
double ScoreOfGrade4_5(char grades1, int I);

int main()
{
	char grade;
	int credit = 1;
	int GPAmethod;
	double GPAdata[24][3];												// array[credit per subject][score for each subject]

	int i = 1;
	char grades1;

	cout << "Enter '1' if the GPA perfect score is 4.3, and enter '0' if the perfect score is 4.5.\n -> ";	// GPA »êÁ¤ ¹æ½Ä
	cin >> GPAmethod;
	cout << endl;

	if (GPAmethod == 1)													// perfect score == 4.3
	{
		GPA PS4_3{};
		PS4_3.inputSubjectNumber();
		cout << endl;

		for (i = 0; i < PS4_3.subjectNumber; i++)
		{
			printf("Enter credit(Hakjeom) of subject%d : ", i + 1);		// enter credit for each subject
			cin >> GPAdata[i][0];
			printf("Enter grade(A/B/C/D/F) of subject%d : ", i + 1);	// enter grade for each subject
			cin >> grades1;
			GPAdata[i][1] = ScoreOfGrade4_3(grades1,(i+1));				// score for each subject
			GPAdata[i][2] = GPAdata[i][0] * GPAdata[i][1];				// credit*score for each subject
			PS4_3.totalscore += GPAdata[i][2];							// calculate total score
			PS4_3.totalcredit += GPAdata[i][0];							// calculate total credit
			cout << endl;
		}
		PS4_3.output();													// calculate and output GPA
	}
	else if (GPAmethod == 0)											// perfect score == 4.5
	{
		GPA PS4_5{};
		PS4_5.inputSubjectNumber();
		cout << endl;

		for (i = 0; i < PS4_5.subjectNumber; i++)
		{
			printf("Enter credit(Hakjeom) of subject%d : ", i + 1);		// enter credit for each subject
			cin >> GPAdata[i][0];
			printf("Enter grade(A/B/C/D/F) of subject%d : ", i + 1);	// enter grade for each subject
			cin >> grades1;
			GPAdata[i][1] = ScoreOfGrade4_5(grades1, (i + 1));			// score for each subject
			GPAdata[i][2] = GPAdata[i][0] * GPAdata[i][1];				// credit*score for each subject
			PS4_5.totalscore += GPAdata[i][2];							// calculate total score
			PS4_5.totalcredit += GPAdata[i][0];							// calculate total credit
			cout << endl;
		}
		PS4_5.output();													// calculate and output GPA
	}
	else																// entered wrong number of GPA calculation method -> need to restart program
	{
		printf("ENTERED ILLEGAL NUMBER\n");
		printf("RESTART PROGRAM\n");
	}

	return 0;
}

void GPA::inputSubjectNumber()									// number of subjects
{
	cout << "Enter number of subjects : ";								// how many subjects did you take?
	cin >> subjectNumber;
}

double ScoreOfGrade4_3(char grades1, int I)								// enter detailed grade of each subject and output score
{
	char grades2;
	switch (grades1)
	{
	case 'A':
	{
		cout << "Enter detailed grade(+/0/-) of subject" << I << " : ";
		cin >> grades2;
		switch (grades2)
		{
		case '+':
			return 4.3;	break;
		case '0':
			return 4.0; break;
		case '-':
			return 3.7;	break;
		}
	}
	case 'B':
	{
		cout << "Enter detailed grade(+/0/-) of subject" << I << " : ";
		cin >> grades2;
		switch (grades2)
		{
		case '+':
			return 3.3;	break;
		case '0':
			return 3.0; break;
		case '-':
			return 2.7;	break;
		}
	}
	case 'C':
	{
		cout << "Enter detailed grade(+/0/-) of subject" << I << " : ";
		cin >> grades2;
		switch (grades2)
		{
		case '+':
			return 2.3;	break;
		case '0':
			return 2.0; break;
		case '-':
			return 1.7;	break;
		}
	}
	case 'D':
	{
		cout << "Enter detailed grade(+/0/-) of subject" << I << " : ";
		cin >> grades2;
		switch (grades2)
		{
		case '+':
			return 1.3;	break;
		case '0':
			return 1.0; break;
		case '-':
			return 0.7;	break;
		}
	}
	case 'F':
		return 0.0; break;
	default:
		cout << "ENTERED ILLEGAL CHARACTER" << endl;
		cout << "RESTART PROGRAM" << endl;
		break;
	}
}

double ScoreOfGrade4_5(char grades1, int I)								// enter detailed grade of each subject and output score
{
	char grades2;
	switch (grades1)
	{
	case 'A':
	{
		cout << "Enter detailed grade(+/0) of subject" << I << " : ";
		cin >> grades2;
		switch (grades2)
		{
		case '+':
			return 4.5;	break;
		case '0':
			return 4.0; break;
		}
	}
	case 'B':
	{
		cout << "Enter detailed grade(+/0) of subject" << I << " : ";
		cin >> grades2;
		switch (grades2)
		{
		case '+':
			return 3.5;	break;
		case '0':
			return 3.0; break;
		}
	}
	case 'C':
	{
		cout << "Enter detailed grade(+/0) of subject" << I << " : ";
		cin >> grades2;
		switch (grades2)
		{
		case '+':
			return 2.5;	break;
		case '0':
			return 2.0; break;
		}
	}
	case 'D':
	{
		cout << "Enter detailed grade(+/0) of subject" << I << " : ";
		cin >> grades2;
		switch (grades2)
		{
		case '+':
			return 1.5;	break;
		case '0':
			return 1.0; break;
		}
	}
	case 'F':
		return 0.0; break;
	default:
		cout << "ENTERED ILLEGAL CHARACTER" << endl;
		cout << "RESTART PROGRAM" << endl;
		break;
	}
}

void GPA::output()													// calculate and output GPA
{
	gpa = totalscore / totalcredit;
	cout << "Your GPA for the semester is " << gpa << "." << endl;
	printf(" -> %1.2f\n", gpa);
}
