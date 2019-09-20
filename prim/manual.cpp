#include<iostream>


int a, b, u, v, n, i, j, ne =1;
int visited [10] = {0}, min, mincost = 0, cost [10][10];




int main ()
{

  int path [100] = {0}; //В этот массив будут записываться вершины, по которым составиться путь
  int pathIndex = 0;


  std:: cout << "Введи количество вершин  ";
  std:: cin >> n;


  std:: cout << "Введи матрицу смежности \n";


  for (i = 1; i <= n; i++) {

    for (j = 1; j <= n; j++) {

      std:: cin >> cost [i][j];


      if (cost [i][j] == 0) {

        cost [i][j] = 999999999; //999 - это что-типа бесконечности. Должно быть больше чем значения веса каждого из ребер в графе

      }

    }

  }


  visited [1] = 1;


  std:: cout << "\n";


  while (ne < n) {

    for (i = 1, min = 999999999; i <= n; i++) {

      for (j = 1; j <= n; j++) {

        if (cost [i][j] < min) {

          if (visited [i] != 0) {

            min = cost [i][j];


            a = u = i;


            b = v = j;

          }

        }

      }

    }


    if (visited [u] == 0 || visited [v] == 0) {

      path [pathIndex] = b;


      pathIndex++;

      //cout<<"\n "<<ne++<<"  "<<a<<"  "<<b<<min; //Можно вывести так
      ne++; //если строчку выше раскомментировать - эту закомментировать


      mincost += min;


      visited [b] = 1;

    }


    cost [a][b] = cost [b][a] = 999999999;

  }


  std:: cout << "\n";


  std:: cout << 1 << " --> ";


  for (int i = 0; i < n-1; i++) {

    std:: cout << path [i];


    if (i < n-2) {

      std:: cout << " --> ";

    }

  }


  std:: cout << "\n Минимальная стоимость  " << mincost;


  std:: cin.get();
  std:: cin.get();


  return 0;

}
