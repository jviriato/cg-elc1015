#include <vector>
#include "dct.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

/* Função que lê o input.dct
   @param filename: arquivo.dct
*/
vector<int> readFile(std::string filename)
{
   unsigned int size;
   const int size_of_header = 4;
   char amostra;
   vector<int> amostras;

   ifstream input(filename, std::ios::binary);
   input.read(reinterpret_cast<char *>(&size), size_of_header);
   amostras.push_back(size);

   for (auto i = 0; i < size; i++)
   {
      input.read(reinterpret_cast<char *>(&amostra), 1);
      cout << "amostra[" << i << "]: " << int(amostra) << endl;
      amostras.push_back(int(amostra));
   }
   return amostras;
}

void writeFile(vector<double> output)
{
   ofstream file("output.dct", std::ios::binary);
   vector<int> output_int(output.begin(), output.end());
   int size = output_int.size();
   file.write((char *)&size, sizeof(int));
   for (auto &amostra : output_int)
      file.write((char *)&amostra, sizeof(char));
   file.close();
}

/* Função auxiliar presente na fórmula da DCT
*/
double __calcC_DCT(double u)
{
   return (u == 0) ? 1 / sqrt(2) : 1.0;
}

vector<double> DCT(const vector<int> &intVec)
{
   vector<double> result;
   vector<double> amostras(intVec.begin(), intVec.end());
   int num_amostras = amostras.front();
   // retira o tamanho total do vetor de amostras
   amostras.erase(amostras.begin());

   for (int u = 0; u < num_amostras; u++)
   {
      double sum = 0;
      int i = 0;
      for (auto const &amostra : amostras)
      {
         sum += __calcC_DCT(u) * amostra * cos((u * M_PI) / (2 * num_amostras) * (2 * i + 1));
         i++;
      }
      double amostra_dct = sqrt(2.0 / double(num_amostras)) * sum;
      result.push_back(amostra_dct);
   }
   return result;
}

vector<double> IDCT(const vector<double> DCT)
{
   vector<double> resultados;
   int num_amostras = DCT.size();

   for (int u = 0; u < num_amostras; u++)
   {
      double sum = 0;
      int i = 0;
      for (auto &amostra : DCT)
      {
         sum += __calcC_DCT(i) * amostra * cos(((M_PI * i) / (2 * num_amostras)) * (2 * u + 1));
         i++;
      }
      double amostra_idct = sqrt(2.0 / double(num_amostras)) * sum;
      resultados.push_back(amostra_idct);
   }
   return resultados;
}

vector<double> Diff(vector<double> original, const vector<double> IDCT)
{
   vector<double> diff;
   // int size = int(original.front());
   // original.erase(original.begin());
   for (auto i = 0; i < original.size(); i++)
   {
      double amostra_diff = original[i] - IDCT[i];
      diff.push_back(amostra_diff);
   }
   return diff;
}

vector<double> Quantizacao1D(int factor, int size)
{
   vector<double> quantizado;
   if (factor >= 2 && factor <= 25)
   {
      for (auto i = 0; i < size; i++)
      {
         double x = 1 + (1 + i) * factor;
         quantizado.push_back(x);
      }
   }
   else
   {
      printf("fator deve ter intervalo [2,25]");
   }
   return quantizado;
}