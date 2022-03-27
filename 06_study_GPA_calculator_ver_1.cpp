#include <iostream>
using namespace std;

double ScoreCal(char& G);
double ScoreOfGrade4_3(char& G);
double ScoreOfGrade4_5(char& G);

int main()
{
	char grade;
	int credit = 1;
	int GPAmethod;
	int subjectNumber = 1;												// number of subjects
	double totalscore = 0;												// sum(credit*score)
	double GPAdata[24][3];												// array[credit per subject][score for each subject]

	int i = 1;
	char grades;
	
	cout << "Enter number of subjects : ";								// how many subjects did you take?
	cin >> subjectNumber;
	
	Re_EnterGrade:
	cout << "Enter 1 if the GPA perfect score is 4.3, and 0 if the perfect score is 4.5.\n -> ";	// GPA 산정 방식
	cin >> GPAmethod;

		if (GPAmethod == 1)												// perfect score == 4.3
		{
			for (i = 0; i < subjectNumber; i++)
			{
				cout << "Enter credit(Hakjeom) of subject" << i + 1 << " : ";
				cin >> GPAdata[i][0];
				cout << "Enter grade(A+ ~ F) of subject" << i + 1 << " : ";
				cin >> grades;
				GPAdata[i][1] = ScoreOfGrade4_3(grades);
				GPAdata[i][2] = ScoreCal(grades);
				totalscore += GPAdata[i][2];
			}
		}
		else if (GPAmethod == 0)										// perfect score == 4.5
		{
			for (i = 0; i < subjectNumber; i++)
			{
				cout << "Enter credit(Hakjeom) of subject" << i + 1 << " : ";
				cin >> GPAdata[i][0];
				cout << "Enter grade(A+ ~ F) of subject" << i + 1 << " : ";
				cin >> grades;
				GPAdata[i][1] = ScoreOfGrade4_5(grades);
				GPAdata[i][2] = ScoreCal(grades);
				totalscore += GPAdata[i][2];
			}
		}
		else															// GPA 산정 방식이 틀렸을 경우 다시 입력
		{
			cout << "RE-ENTER" << endl;
			continue;
		}
	}
}

double ScoreCal(char& G)												// score for each subject
{
	return ScoreOfGrade(S) * S.credit;
}

	double ScoreOfGrade4_3(char& G)										// score of each grade
	{
	switch (G)
	{
	case 'A+':
		return 4.3;	break;
	case 'A':
		return 4.0;	break;
	case 'A-':
		return 3.7; break;
	case 'B+':
		return 3.3;	break;
	case 'B':
		return 3.0;	break;
	case 'B-':
		return 2.7; break;
	case 'C+':
		return 2.3;	break;
	case 'C':
		return 2.0;	break;
	case 'C-':
		return 1.7; break;
	case 'D+':
		return 1.3;	break;
	case 'D':
		return 1.0;	break;
	case 'D-':
		return 0.7; break;
	case 'F':
		return 0.0; break;
	default:
		cout << "RE-ENTER : ";
		cin >> grades;
		goto Re_EnterGrade;
	}
}

double ScoreOfGrade4_5(GPA& S)										// score of each grade
{
	switch (S.grade)
	{
	case 'A+':
		return 4.5;	break;
	case 'A':
		return 4.0;	break;
	case 'B+':
		return 3.3;	break;
	case 'B':
		return 3.0;	break;
	case 'C+':
		return 2.3;	break;
	case 'C':
		return 2.0;	break;
	case 'D+':
		return 1.3;	break;
	case 'D':
		return 1.0;	break;
	case 'F':
		return 0.0; break;
	default:
		cout << "RE-ENTER : ";
		cin >> grades;
		ScoreOfGrade4_5(char G);
	}
}

char GPA::getGrade()													// A+ ~ F
{
	return grade;
}

int GPA::getCredit()														// Credit == Hakjeom
{
	return credit;
}

void GPA::set(char newGrade, int newhg)
{
	char grade = newGrade;
	int hg = newhg;
}