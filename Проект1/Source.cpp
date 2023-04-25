#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

#define N 15

int read_matrix(int matr[N][N]) {
	ifstream in("matrix.txt");
	if (in.is_open())
	{
		//������� ������� �� �����
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				in >> matr[i][j];

		//������� �������
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << matr[i][j] << "  ";
			cout << "\n";
		}

		in.close();//��� ����� ������� �����
		return **matr;
	}
	else
	{
		//���� �������� ����� ������ �� �������
		cout << "���� �� ��������.";
		return 0;
	}
}

int find_way(int matr[N][N], int vv){//, int min[E], int way[N]) {
	int v = vv+1;
	cout << "��������� ������� - " << v << endl;
	int u; // , i = 0;
	stack <int> plan; // ���� ��������� � ���� �����
	plan.push(--v);   // �� �������� � 0, � �� � 1
	matr[v][v] = 1; // ��������, ��� ��� ������� ��� ���������� � ���� 
	//int counter = 1;  // ��������� ��� ���������
	while(!plan.empty()) {
		v = plan.top(); // �������� ��������� �� ����� ������� 
		plan.pop();       // ������� �� �� ����� ���������
		for (u = 0; u < N; u++) { // ���������� �������� � ���
			if (matr[v][u]>0 && !matr[u][u]) { // ���� �����, ��
					plan.push(u);     // ��������� �� � ����
					matr[u][u] = 1; // ��������, ��� ��� �� �����
					//counter++;        // �������, ������� ���� ������
					cout << v + 1 << "\t" << u + 1  << endl;
			}
		}
	} 
	return **matr;
}

int count_components(int matr[N][N]) {
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (matr[i][i] != 1) {
			counter++;
			cout << "__________________________________________\n";
			find_way(matr, i);
		}
	}
	cout << "\n\t�i���i��� ��������� ��'������i: " << counter << endl << endl;
	return 0;
}

void main()
{
	setlocale(LC_ALL, "Ukrainian");
	int matr[N][N];
	
	cout << "�i���i��� ������: " << N << endl;
	cout << "������� ���i�����i: " << endl;
	read_matrix(matr);
	count_components(matr);

	system("pause");
}