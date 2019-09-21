#include <algorithm>
#include <iostream>
#include <vector>




struct edge {

  int x, y;


  edge () {}


  edge (int a, int b) {

    x = a;


    y = b;

  }

};




int main() {

  int n, m;


  std:: cout << "Введи количество вершин и рёбер \n";


  std:: cin >> n >> m;


  std:: vector <edge> graph (m); 


  std:: vector <edge> tree;


  std:: vector <int> variety (n);


  for (int i = 0; i < n; i++) {

    variety [i] = i;

  }


  for (int i = 0; i < m; i++) {

    int a, b;


    std:: cout << "Веди значения рёбер x и y \n";


    std:: cin >> a >> b;


    graph [i]. x = a;


    graph [i]. y = b;

  }


  for (int i = 0; i < m; i++) {

    int a = graph [i]. x;


    int b = graph [i]. y;


    if (variety [a] != variety [b]) {

      tree. push_back (graph [i]);


      int oldVariety = variety [b];


      int newVariety = variety [a];


      for (int j = 0; j < n; j++) {

        if (variety [j] == oldVariety) {

          variety [j] = newVariety;

        }

      }

    }

  }


  std:: cout << "\n Вывод дерева \n";


  for (int i = 0; i < n-1; i++) {

    std:: cout << tree [i]. x << " " << tree [i]. y;


    if (i != n-2) {

      std:: cout << std:: endl;

    }

  }


  return 0;

}
