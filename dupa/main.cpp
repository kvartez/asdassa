#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char** argv)
{
	
	bool rekord1= false;
	bool rekord2= false;
	bool rekord3= false;
	int liczbaRekordow =0;
	ofstream fileOut; 
 ifstream file; //plik wejsciowy
 ifstream file2; //plik wejsciowy
 ifstream file3; //plik wejsciowy

 char* endptr; // to jest wska�nik na miejsce, gdzie przy konwersji z systemu czworkowego wyst�pi b��d - nieu�ywana zmienna
 long liczba ,liczbaII,liczbaIII, max,max2,max3; //liczba dziesietna, minimum z pliku
 string liczba1, liczba2,liczba3, liczba4,liczba5, liczba6; //dwie liczby w systemie czworkowym wczytujemy jako "string" bo mog� by� d�u�sze od long long
 file.open("dane_systemy1.txt"); //otworz plik liczb
 file2.open("dane_systemy2.txt"); //otworz plik liczb
 file3.open("dane_systemy3.txt");
 fileOut.open("wyjscie.txt");
 bool pierwszy = true;  //do algorytmu MINIMUM - zak�adamy, �e pierwsza liczba jest najmniejsza z dotychczas przeczytanych
 if(file.good()&&file2.good()&&file3.good()){
 	while(!file.eof()&&!file2.eof()&&!file3.eof()){
	 
 	
 	file >>liczba1>>liczba2;
 	file2>>liczba3>>liczba4;
 	file3>>liczba5>>liczba6;
 	liczba = strtol(liczba2.c_str(),&endptr,2);
 	liczbaII = strtol(liczba4.c_str(),&endptr,4);
 	liczbaIII = strtol(liczba6.c_str(),&endptr,8);
 	if(pierwszy)
 	{
 		
 		max =liczba;
 		max2 =liczbaII;
 		max3 =liczbaIII;
 		pierwszy =false;
 		liczbaRekordow ++;
	 }else{
	 	rekord1= false;
	 	rekord2= false;
	 	rekord3= false;
	 	if(liczba>max){
	 		max = liczba;
	 		rekord1 = true;
		 }
		 	if(liczbaII>max2){
	 		max2 = liczbaII;
	 		rekord2 = true;
		 }
		 	if(liczbaIII>max3){
	 		max3 = liczbaIII;
	 		rekord3 = true;
		 }
		 if(rekord1||rekord2||rekord3){
		 	liczbaRekordow ++;
		 	
		 }
	 }
 
 	
 	
 }
 }
 
 filOut<< "," << max <<endl<<max2<<endl<<max3<<endl<<liczbaRekordow; //zapisanie najmniejszej liczby z pliku czworkowego do pliku wynikowego
 file.close();
 file2.close();
 file3.close();
 fileOut.close();
 return 0;
}
