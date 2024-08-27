#include "PermutationGenerator.h"
#include "Calculator.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <cmath>

//#include "Calc.h"
Generator::Generator(string file):operations({ "+", "*", "-", "S",  "/", "O"}), found(false)
{
    loadNumbers(file);
}

void Generator::loadNumbers(string file)
{
    fstream f;
    stringstream s;
   
    f.open(file);
    string str;
    while (getline(f, str)) {
        s = stringstream(str);
        availableNumbers.clear();
        while (s >> str) {
            availableNumbers.push_back(str);
        }
        
        str = availableNumbers.back();
        availableNumbers.pop_back();
        sort(availableNumbers.begin(), availableNumbers.end(), greater<string>());

        savedNumbers.push_back(availableNumbers);
        allNumbers.push_back(availableNumbers);
        
        goal = stoi(str);
        savedGoals.push_back(goal);
        allGoals.push_back(goal);
    }
    f.close();
    round();
    for (int i = 1; i < 6; i++) {
        goals.push_back(goal + i);
        goals.push_back(goal - i);
    }

}
void Generator::round() {
    goal = allGoals[0];
    allGoals.erase(allGoals.begin());

    availableNumbers = allNumbers[0];
    allNumbers.erase(allNumbers.begin());
}
//Metoda generacije kombinacija se oslanja na "brojanje" u binarnom brojevnom sistemu (recimo za 6 brojeva, binarni broj 100001 je kombinacija u koju
//su ukljuceni samo prvi i poslednji broj
void Generator::generateCombinations() {
    char buffer[7];
    vector<string> combination;
    for (int a = 63; a > 0; a--) {
        combination.clear();
        _itoa_s(a, buffer, 2);
        string old = "";
        for (char c : buffer) {
            if (c == '\0') {
                break;
            }
            old += c;
        }
        string ss = string(6 - old.size(), '0') + old;
        for (int j = 0; j < availableNumbers.size(); j++) {
            
            if ((ss[j] - '0') == 1) {
                combination.push_back(availableNumbers[j]);
            }
        }
        
        permuteCombination(combination);
    }

}
//Metoda sortira i permutuje datu kombinaciju koriscenjem funkcije next_permutation nad iteratorima vektora
void Generator::permuteCombination(vector<string> comb){
    sort(comb.begin(), comb.end());
    do {
        
        numPerm[comb.size()].push_back(comb);
       
        
    } while (next_permutation(comb.begin(), comb.end()));
}
//Metoda generacije varijacija operacija sa ponavljanjem se oslanja na brojanje u brojnom sistemu cija je baza broj dostupnih operacija (za 6 operacija baza
//je 6) gde recimo broj 55555 konvertujemo u varijaciju sa 5 elemenata gde je na svakom mestu poslednja operacija
void Generator::generateVariations(vector<string>& possibleOperations)
{
    char buffer[9];
    vector<string> variation;
    for (int i = 0; i <= 7775; i++) {
        _itoa_s(i, buffer, possibleOperations.size());
        for (int j = 0; buffer[j] != '\0'; j++) {
            variation.push_back(possibleOperations[int(buffer[j] - '0')]);
        }
        opPerm[variation.size()].push_back(variation);
        if (variation.size() > 0 && variation.size() < 5) {
            //U ovom bloku se za svaku varijaciju koja vec nije maksimalne duzine dodaje i verzija varijacije sa nultim elementom na prvom mestu, posto
            //ovaj metod te varijacije inace ne uracunava (npr 0111 nije validan broj ali jeste validna varijacija
            variation.insert(variation.begin(), operations[0]);
            opPerm[variation.size()].push_back(variation);
        }
        variation.clear();
    }
    
  
}

//Pomocna funkcija nalazi odgovarajuce mesto za ugnjezdenu zagradu
void insertNestedOpenBracket(string& str, int a) {
    for (int i = a; i >= 0; i--) {
        if (str[i] == '(') {
            str.insert(i, "(");
            return;
        }
    }
}
//Pomocna funkcija nalazi odgovarajuce mesto za neugnjezdenu zagradu
void insertOpenBracket(string& str, int a) {
    for (int i = a; i >= 0; i--) {
        if (!isdigit(str[i])) {
            str.insert(i+1, "(");
            return;
        }
    }
    str = "(" + str;
}

//Kombinovanje funkcionise naizmenicnim dodavanjem broja i operacije u string, sa pozivanjem specijalnih pomocnih funkcija za zagrade kada se dodje do operacija
//sabiranja i oduzimanja sa prioritetom
string Generator::combine2(vector<string> valuePerm, vector<string> operationPerm)
{
    string res;
    
    

    vector<string>::iterator t = operationPerm.begin();
    res += valuePerm[0];
    for (vector<string>::iterator i = valuePerm.begin()+1; i != valuePerm.end(); i++) {
        if (t == operationPerm.end()) {

            break;
        }
        //Da li je operacija jedna od specijalnih operacija sa prioritetom?
        if (*t == "S") {
            t++;
            //Ako jeste, da li je tako pozicionirana da ce stvoriti ugnjezdenu zagradu
            if (res.length() > 1 && res[res.length() - 1] == ')') {
                insertNestedOpenBracket(res, res.length() - 1);
            }
            else {
                insertOpenBracket(res, res.length()-1);
               
            }
            res.push_back('+');

            res += *(i);
            res.push_back(')');



        }
        else if(*t == "O") {
            t++;
            if (res.length() > 1 && res[res.length() - 1] == ')') {
                insertNestedOpenBracket(res, res.length() - 1);
            }
            else {
                insertOpenBracket(res, res.length() - 1);
                
            }
            
            res.push_back('-');
            if (i == valuePerm.end()) {
                break;
            }
            res += *(i);
            res.push_back(')');

        }
        //Operacija je obicna, nema potrebe za zagradama
        else {
            res += *t;
            t++;
            res += (*(i));
            if (t == operationPerm.end()) {
                break;
            }
            
        }
        
        if (t == operationPerm.end()) {
            if (++i != valuePerm.end()) {
                res += *i;
                break;
            }
            break;
        }

    }
    
    return res+";";
}


//Funkcija prolazi kroz sve varijacije operacija i brojeva i ukrsta one koje su odgovarajucih duzina, proverava njihovu vrednost i staje kad dodje do 
//izraza koji daje resenje, ako ni jedan izraz ne daje resenje proverava se da li postoji izraz koji daje resenje manje ili vece za 1, pa 2, i tako dalje
void Generator::generate()
{
   
    originalGoal = goal;
    generateVariations(operations);
    
    generateCombinations();
    if (combineAll()) {
        return;
    }
    
    //Nije nadjeno ni jedno resenje koje tacno zadovoljava uslov, traze se resenja koja su blizu
    while (goals.size() != 0) {
        //Vec smo napunili vektor goals sa ciljevima koji su blizu trazenog broja, prvo manji i veci za jedan, pa za 2, itd...
        //Sada samo redom uzimamo prvi element iz tog vektora i isti algoritam pokrecemo za taj cilj
        goal = goals[0];
        goals.pop_back();
        if (combineAll()) {
            return;
        }
    }
    cout << "RACUNAR NE MOZE DA NADJE NI JEDNO PRISTOJNO RESENJE (TOLERANCIJA ZA GRESKU JE +-5)" << endl;
    
}
bool Generator::combineAll() {
    string str;
    Calculator<double> c("", availableNumbers, true);
    //Trazi se tacno resenje medju svim mogucim varijacijama, ukrstanjem varijacija brojeva i operacija
    for (int i = 4; i >= 0; i--) {
        for (vector<vector<string>>::iterator t = opPerm[i + 1].begin(); t != opPerm[i + 1].end(); t++) {
            for (vector<vector<string>>::iterator j = numPerm[i + 2].begin(); j != numPerm[i + 2].end(); j++) {
                str = combine2(*j, *t);
                c.init(str);
                double exp = c.expression();
                //Nadjeno je tacno resenje
                if (exp == goal) {
                    cout << "RACUNAR IMA RESENJE ";
                    expression = str;
                    result = goal;

                    return true;
                }
            }
        }
    }
    return false;
}
int Generator::getGoal()
{
    return goal;
}
//Ispisivanje osnovnih podataka u fajl
void Generator::dump(string file)
{
    ofstream out;
    out.open(file, ios_base::app);
    out << "====================" << endl;
    for (int i = 0; i < savedNumbers.size(); i++) {
        out << i + 1 << ". ";
        for (int j = 0; j < savedNumbers[i].size(); j++) {
            out << savedNumbers[i][j] << " ";
        }
        out << savedGoals[i];
        out << endl;
    }
    out.close();
}
vector<vector<string>> Generator::getAllNumbers()
{
    return allNumbers;
}
int Generator::getOriginalGoal()
{
    return originalGoal;
}

vector<string> Generator::getV()
{
    return availableNumbers;
}

vector<int> Generator::getAllGoals()
{
    return allGoals;
}
string Generator::getExpression() {
    return expression;
}