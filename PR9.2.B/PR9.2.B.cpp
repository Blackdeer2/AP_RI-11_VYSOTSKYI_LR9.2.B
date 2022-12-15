#include <iostream> 
#include <string>
#include <iomanip>

using namespace std;


enum Kurs { I, II, III, IV, V, VI };
string kursStr[] = { "I","II","III","IV","V","VI" };

enum Spec { IT, CS, SA, SE };
string specStr[] = { "Inform sys and tec","Computer Science ","System analysis  ","Softwar enginering" };

struct Student
{
	string   prizv;
	Kurs     kurs;
	Spec     spec;
	struct
	{
		double physic;
		double math;
	};
	union
	{
		double prog;
		double ped;
		double num;
	};

};

void Create(Student* s, int& N) {
	int kurs;
	int spec;
	for (int i = 0; i < N; i++) {
		cout << "Student number " << i + 1 << " : " << endl;
		cin.get();
		cin.sync();

		cout << "    Surname: "; getline(cin, s[i].prizv);
		cout << "    Course (0 - I, 1 - II, 2 - III, 3 - IV, 4 - V, 5 - VI): ";
		cin >> kurs;

		cout << " Specialty (0 - Information systems and technologies, 1 - Computer Science, 2 - System analysis, 3 - Software engineering): ";
		cin >> spec;

		cout << " Assessment in physics : "; cin >> s[i].physic;
		cout << " Assessment in math : "; cin >> s[i].math;
		//cout << " Assessment in programmingі : "; cin >> s[i].prog;
		//cout << " Assessment in pedagogyі : "; cin >> s[i].ped;
		//cout << " Assessment in numerical methodsі : "; cin >> s[i].num;

		s[i].kurs = (Kurs)kurs;
		s[i].spec = (Spec)spec;
		switch (s[i].spec) {
		case IT:
			cout << " Assessment in programmingі : "; cin >> s[i].prog;
			break;
		case CS:
			cout << " Assessment in pedagogyі : "; cin >> s[i].ped;
			break;
		case SA:
		case SE:
			cout << " Assessment in numerical methodsі : "; cin >> s[i].num;
			break;
		}
	}
}

void Print(Student* s, int N) {

	cout << "======================================================================================================================================="
		<< endl;
	cout << "|  №  |   Surname   |   Course   |        Specialty         |   Physics   |   Math   |   Programming   |   Pedagogy   |   Numerical   |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++) {
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(11) << left << kursStr[s[i].kurs]
			<< "|    " << setw(4) << right << specStr[s[i].spec] << "    "
			<< "| " << setw(11) << s[i].physic
			<< "| " << setw(10) << s[i].math;
		/*<< "| " << setw(16) << s[i].prog << "|"
		<< "| " << setw(16) << s[i].ped << "|"
		<< "| " << setw(16) << s[i].num << "|";*/
		switch (s[i].spec) {
		case IT:
			cout << "| " << setw(16) << s[i].prog << "|" << setw(14) << "|" << setw(15) << "|";
			break;
		case CS:
			cout << "| " << setw(17) << "|" << setw(15) << s[i].ped << "|" << setw(15) << "|";
			break;
		case SA:
		case SE:
			cout << "| " << setw(17) << "|" << setw(15) << "|" << setw(15) << s[i].num << "|";
			break;
		}
		cout << endl;
	}
	cout << "======================================================================================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* s, int N) {
	{
		Student tmp;
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if ((s[i1].spec > s[i1 + 1].spec)
					||
					(s[i1].spec == s[i1 + 1].spec && s[i1].kurs > s[i1 + 1].kurs)
					||
					(s[i1].spec == s[i1 + 1].spec && s[i1].kurs == s[i1 + 1].kurs && s[i1].prizv > s[i1 + 1].prizv)
					)
				{
					tmp = s[i1];
					s[i1] = s[i1 + 1];
					s[i1 + 1] = tmp;
				}
	}
}

int* IndexSort(Student* s, const int N)
{
	int* I = new int[N];
	for (int i = 0; i < N; i++)
		I[i] = i;
	int i, j, value;
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1; j >= 0 &&
			((s[I[j]].spec < s[value].spec)
				||
				(s[I[j]].spec == s[value].spec &&
					s[I[j]].kurs < s[value].kurs)
				|| (s[I[j]].spec == s[value].spec &&
					s[I[j]].kurs == s[value].kurs &&
					s[I[j]].prizv > s[value].prizv));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}
void PrintIndexSorted(Student* s, int* I, const int N)
{

	cout << "======================================================================================================================================="
		<< endl;
	cout << "|  №  |   Surname   |   Course   |        Specialty         |   Physics   |   Math   |   Programming   |   Pedagogy   |   Numerical   |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++) {
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << s[I[i]].prizv
			<< "| " << setw(11) << left << kursStr[s[I[i]].kurs]
			<< "|    " << setw(4) << right << specStr[s[I[i]].spec] << "    "
			<< "| " << setw(11) << s[I[i]].physic
			<< "| " << setw(10) << s[I[i]].math
			/*<< "| " << setw(16) << s[i].infor << "|"*/;
		//cout << endl;
		switch (s[i].spec) {
		case IT:
			cout << "| " << setw(16) << s[i].prog << "|" << setw(14) << "|" << setw(15) << "|";
			break;
		case CS:
			cout << "| " << setw(17) << "|" << setw(15) << s[i].ped << "|" << setw(15) << "|";
			break;
		case SA:
		case SE:
			cout << "| " << setw(17) << "|" << setw(15) << "|" << setw(15) << s[i].num << "|";
			break;
		}
		cout << endl;
	}

	cout << "======================================================================================================================================="
		<< endl;
	cout << endl;
}

int BinSearch(Student* s, const int N, const string prizv, const Kurs kurs, const Spec spec)
{
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (s[m].prizv == prizv && s[m].kurs == kurs)
			return m;
		if ((s[m].kurs < kurs)
			||
			(s[m].kurs == kurs && s[m].prizv < prizv) || (s[m].kurs == kurs && s[m].prizv == prizv && s[m].spec < spec))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}


int main() {

	int N;
	cout << "Input count of student N: "; cin >> N;
	Student* s = new Student[N];

	int ispecurs;
	int found;
	int isspec;
	string   prizv;
	Kurs     kurs;
	Spec     spec;
	//double physic;
	//double math;
	//double infor;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Select an action:" << endl << endl;
		cout << " [1] - entering data from the keyboard" << endl;
		cout << " [2] - display of data on the screen" << endl;
		cout << " [3] - physical arrangement of data" << endl;
		cout << " [4] - binary search of a student by last name, course and specialty" << endl;
		cout << " [5] - index ordering and data output" << endl;

		cout << " [0] - exit" << endl << endl;
		cout << "Input value: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(s, N);
			//Student* s = new Student[N];
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			Print(s, N);
			Sort(s, N);
			Print(s, N);
			break;
		case 4:

			cout << "Input keys search:" << endl;
			cout << "  Course (0 - I, 1 - II, 2 - III, 3 - IV):";
			cin >> ispecurs;
			kurs = (Kurs)ispecurs;
			cin.get();
			cin.sync();

			cout << "Specialty (0 - Information systems and technologies, 1 - Computer Science, 2 - System analysis, 3 - Software engineering): ";
			cin >> isspec;
			spec = (Spec)isspec;
			cin.get();
			cin.sync();

			cout << " Surname: ";
			getline(cin, prizv);
			//cout << endl;


			if ((found = BinSearch(s, N, prizv, kurs, spec)) != -1)
				cout << "Found student index " << found + 1 << endl;
			else
				cout << "The desireed student no found" << endl;
			break;
		case 5:
			PrintIndexSorted(s, IndexSort(s, N), N);
			break;
		}
	} while (menuItem != 0);


	return 0;
}
