#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

#define N 15

int read_matrix(int matr[N][N]) {
	ifstream in("matrix.txt");
	if (in.is_open())
	{
		//Считаем матрицу из файла
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				in >> matr[i][j];

		//Выведем матрицу
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << matr[i][j] << "  ";
			cout << "\n";
		}

		in.close();//под конец закроем файла
		return **matr;
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Файл не знайдено.";
		return 0;
	}
}

int find_way(int matr[N][N], int vv){//, int min[E], int way[N]) {
	int v = vv+1;
	cout << "Початкова вершина - " << v << endl;
	int u; // , i = 0;
	stack <int> plan; // план посещения в виде стека
	plan.push(--v);   // мы нумеруем с 0, а не с 1
	matr[v][v] = 1; // отмечаем, что эта вершина уже заносилась в план 
	//int counter = 1;  // начальную уже сосчитали
	while(!plan.empty()) {
		v = plan.top(); // посещаем следующую по плану вершину 
		plan.pop();       // удаляем ее из плана посещения
		for (u = 0; u < N; u++) { // перебираем соседние с ней
			if (matr[v][u]>0 && !matr[u][u]) { // если новая, то
					plan.push(u);     // добавляем ее в план
					matr[u][u] = 1; // отмечаем, что уже не новая
					//counter++;        // считаем, сколько было вершин
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
	cout << "\n\tКiлькiсть компонент зв'язностi: " << counter << endl << endl;
	return 0;
}

void main()
{
	setlocale(LC_ALL, "Ukrainian");
	int matr[N][N];
	
	cout << "Кiлькiсть вершин: " << N << endl;
	cout << "Матриця сумiжностi: " << endl;
	read_matrix(matr);
	count_components(matr);

	system("pause");
}