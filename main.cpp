include <iostream>
include <cstdlib> // для функции rand()
include <time.h> // для функции time()

using namespace std;

//ТРАНСПОНИРОВАНИЕ
 void Transpose(int m , int **arr_1, int **arr_2)
 {
   for (int i = 0; i < m; i++)
   {
     for (int j = 0; j < m; j++)
     {
       arr_2[i][j] = arr_1[j][i];
     }
   }
 }


// ПОЛУЧЕНИЕ МАТРИЦЫ БЕЗ i-ОЙ СТРОКИ И j-ГО СТОЛБЦА
void Truncation(int **mas, int **p, int i, int j, int m) 
{
  int ki, kj, di, dj;
  di = 0;
  for (ki = 0; (ki < (m - 1)); ki++) 
  { // проверка индекса строки
    if (ki == i) di = 1;
    dj = 0;
    for (kj = 0; kj < m - 1; kj++) 
    { // проверка индекса столбца
      if (kj == j) dj = 1;
      p[ki][kj] = mas[ki + di][kj + dj];
    }
  }
}

//ФУНКЦИЯ ВЫЧИСЛЕНИЕ ОПРЕДЕЛИТЕЛЯ
int Determinant(int **mas, int m) 
{
  int i, j, d, k, n;
  int **p;
  p = new int*[m];
  for (i = 0; i<m; i++)
    p[i] = new int[m];
  j = 0; d = 0;
  k = 1; //(-1) в степени i
  n = m - 1;
  if (m<1) cout << "Определитель вычислить невозможно!";
  if (m == 1) 
  {
    d = mas[0][0];
    return(d);
  }
  if (m == 2) 
  {
    d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
    return(d);
  }
  if (m>2) 
  {
    for (i = 0; i<m; i++) 
    {
      Truncation(mas, p, i, 0, m);
      d = d + k * mas[i][0] * Determinant(p, n);
      k = -k;
    }
  }
  return(d);
}
 
void Mult_matr(int m, int n, int s, int **arr_1, int **arr_2, int **arr_3)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < s; j++)
    {
      int temp = 0;
      for (int l = 0; l < n; l++)
      {
        temp = temp + arr_1[i][l] * arr_2[l][j];
      }
      arr_3[i][j] = temp;
    }
  }
    cout << endl;
}
 
int main()
{
  int m, n, r, s, d_1, d_2;
  cout << "Ввидите m" << endl;
  cin >> m;
  cout << "Ввидите n" << endl;
  cin >> n;
  cout << "Ввидите r" << endl;
  cin >> r;
  cout << "Ввидите s" << endl;
  cin >> s;
  int **mat_1;
  int **mat_2;
  int **mat_3;
 
  //РАНДОМНОЕ ЗАПОЛНЕНИЕ МАТРИЦ
  mat_1 = new int*[m];
  cout << endl << "Первая матрица : " << endl ;
  for (int i = 0; i < m; i++)
  {
    mat_1[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      mat_1[i][j] = rand()%5-1;
      cout << mat_1[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
 
  mat_2 = new int*[r];
  cout << "Вторая матрица : " << endl ;
  for (int i = 0; i < r; i++)
  {
    mat_2[i] = new int[s];
    for (int j = 0; j < s; j++)
    {
      mat_2[i][j] = rand()%5-1;
      cout << mat_2[i][j] << " ";
    }
    cout << endl;
  }
  
  mat_3 = new int*[m];
  for (int i = 0; i < r; i++)
  {
    mat_3[i] = new int[s];
  }
  
  //ПЕРЕМНОЖЕНИЕ МАТРИЦ
  if (m == r)
  {
    Mult_matr(m, n, s, mat_1, mat_2, mat_3);
    cout << "Матрица равная произведению первой и второй матриц : " <<  endl ;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < s; j++)
      {
        cout << mat_3[i][j] << " ";
      }
      cout << endl;
    }
  }
  else cout << "Выполнить перемножение матриц невозможно." << endl;

  //ВЫЗОВ ФУНКЦИИ ПОДСЧЁТА ОПРЕДЕЛИТЕЛЯ
  cout << endl;
  if (m == n)
  {
    d_1 = Determinant(mat_1, m);
    cout << "Определитель первой матрицы равен = " << d_1 <<endl;
    cout << endl;
  }
  else cout << "Проверьте вводимые данные на возможность подсчёта определителя первой матрицы." << endl;
  if (r == s)
  {
    d_2 = Determinant(mat_2, r);
    cout << "Определитель второй матрицы равен = " << d_2 <<endl;
    cout << endl;
  }
  else cout << "Проверьте вводимые данные на возможность выполнения подсчёта определителя второй матрицы" << endl;

  //ТРАНСПОНИРОВАНИЕ
  if (m == n && r == s)
  {
    cout << "Транспонировав матрицу с наибольшим определителем, получаем : " << endl ;
    int **mat_tr;
    if (d_1 >= d_2)
    {
      int **mat_tr;
      mat_tr = new int*[m];
      for (int i = 0; i < m; i++)
      {
      mat_tr[i] = new int[m];
      }
      Transpose(m, mat_1, mat_tr);
      for (int i = 0; i < m; i++)
      {
      for (int j = 0; j < m; j++)
        {
        cout << mat_tr[i][j] << " ";
        }
        cout << endl;
      }
    }
    else if (d_1 < d_2)
    {
      int **mat_tr;
      mat_tr = new int*[r];
      for (int i = 0; i < r; i++)
      {
        mat_tr[i] = new int[r];
      }
      Transpose(r, mat_2, mat_tr);
      for (int i = 0; i < r; i++)
      {
        for (int j = 0; j < r; j++)
        {
          cout << mat_tr[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
  else cout << "Проверьте вводимые данные на возможность выполнения транспонирования матрицы с наибольшим определителем." << endl;
}
