#pragma once
#include "Calculator.h"

#include <string>
#include <vector>

using namespace std;
/*
	Klasa Generator generise sve moguce varijacije datih brojeva i operacija, kombinuje ih u validne matematicke izraze, i predaje ih kalkulatoru
	za evaluaciju.

	Autor: Marko Kuvizic SV38-2021
	Poslednja izmena: 10.01.2023. 12:56
*/
class Generator {
private:
	
	int goal;	//Trenutni broj koji se trazi
	double result;	//Dobijeni rezultat
	string expression;	//Matematicki izraz kojim je dobijen najbolji rezultat
	vector<string> availableNumbers;	//Vektor svih brojeva koji su dozvoljeni u ovoj rundi
	vector<int> allGoals;	//Vektor svih mogucih brojeva koji se traze (Prvo prosledjen broj, pa onda svi brojevi koji se razlikuju za jedan, i tako redom
	vector<int> savedGoals; //Svi brojevi koji se traže za celu igru
	vector<vector<string>> allNumbers;	//Vektor brojeva za sve runde, gde se brojevi za datu rundu brisu kada se ona odigra
	vector<vector<string>> savedNumbers;	//Vektor svih brojeva za sve runde koji ostaje netaknut radi ispisa u fajl
	vector<string> operations;		//Vektor dozvoljenih operacija
	int originalGoal;	//Originalni broj koji se trazi (broj koji je prosledjen)
	bool found;
	vector<vector<string>> opPerm[6];	//Sve varijacije operacija organizovane po duzini (npr. opPerm[5] su sve varijacije sa 5 operacija)
	vector<vector<string>> numPerm[7];	//Sve varijacije brojeva organizovane na slican nacin
	//Ova organizacija po duzini je zgodna zato sto se krajnji izrazi dobijaju ukrstanjem varijacija operacija i brojeva, a 2 varijacije mogu da se ukrste
	//samo ako je varijacija operacija za 1 kraca od varijacije brojeva
public:
	Generator(string file);
	void round();	//Metoda kojom racunar "igra" rundu
	void loadNumbers(string file);	//Metoda kojom se ucitavaju svi dostupni brojevi i rezultati koji se traze za svaku rundu
	void generateCombinations();	//Metoda generise sve kombinacije brojeva
	void permuteCombination(vector<string> comb);	//Funkcija permutuje datu kombinaciju brojeva (permutovanjem svake kombinacije svih duzina dobijaju se 
													//sve varijacije
	void generateVariations(vector<string>& possibleOperations);	//Metoda generise sve varijacije operacija
	string combine2(vector<string> valuePerm, vector<string> operationPerm);	//Metoda kombinuje jednu varijaciju brojeva i jednu varijaciju operacija
																				//u matematicki izraz
	string getExpression();	//Getter za trenutni izraz
	void generate();	//Metoda pokrece proces generacije (poziva sve ostale metode u odgovarajucem redosledu)
	int getGoal();	//Getter za trenutni broj koji se trazi
	vector<int> getAllGoals();	//Geter za sve moguce brojeve koji se traze
	int getOriginalGoal();
	vector<string> getV();
	vector<int> goals;
	void dump(string file); //Metoda za ispisivanje u fajl
	vector<vector<string>> getAllNumbers();
	bool combineAll();  //Metoda ukrsta sve varijacije brojeva i operacija koje su odgovarajucih duzina i poziva metodu kalkulatora za racunanje
						//Ako je jedno od ukrstanja vratilo izraz koji se evaluira na odgovarajuci broj, vraca true, u suprotnom false
};
