#include <iostream>
#include <string>
#include "strutils.h"
//#include <algorithm>
using namespace std;

	//int indexofsign, indexofequation, ikincisayininuzunlugu, indexoffirstnums, lengthoffirstnums, ikincisayininyeri, denktirinyeri, z, x, y, i;
	//string firstnums, isaret, equation, ikincisayi, denktir, sonuc, answer;
	//int score = 0;
	



// for loopta soruyu sor, input formati checkle
// format dogruysa, islemi yap
// islem yanlissa ve joker hakki varsa jokeri sor
// jokeri yoksa diger soruya gec
// islem dogruysa puan ekle
//sorular bitince for loop da bitiyor olacak
//return 0dan once coutla end program

bool herseyibitir() {
	
	return 0;
}
void signcorrector(string& a,string&firstnums, string&isaret, string&equation, string&ikincisayi,string&denktir, string&sonuc, string&answer,int & salak ,int & indexofsign, int & indexofequation, int & ikincisayininuzunlugu, int & indexoffirstnums, int & lengthoffirstnums, int & ikincisayininyeri, int & denktirinyeri, int & z, int&x, int&y, int&i, int&score) {
	
	indexofequation = a.find('=');

	if (((a.find("+-",1)) != std::string::npos)) {
		a[a.find("+-")] = '\0';
	}

	if (a.find("-+",1) != std::string::npos) {
		a[a.find("-+") + 1] = '\0';
	}

	if (a.find("++",1) != std::string::npos) {
		a[a.find("++")] = '\0';
	}

	if (a.find("--",1) != std::string::npos) {
		int temp = a.find("--");
		string new_exp = "";
		new_exp = a.substr(0, temp)+ '+' + a.substr(temp+2);
		a = new_exp;
		
	}
	if(a.find("++") != std::string::npos) {
		if (a.find("++") == 0) {
			cout << "Wrong input format! You got -10 penalty points for this math expression." << endl << endl;
			score -= 10;
			salak += 1;
		}
	}

	if (a.find("--") != std::string::npos) {
		if (a.find("--") == 0) {
			cout << "Wrong input format! You got -10 penalty points for this math expression." << endl << endl;
			score -= 10;
			salak += 1;
		}
	}


	if (a.find('+') == 0) {
		a[0] = '\0';
	}



	if (!isdigit(a[indexofequation + 1]) && a[indexofequation + 1] == '+') {
		a[indexofequation + 1] = '\0';
	}
}
	

void question_again(bool&arti,bool&biricik,bool&dur,bool&devam,bool&right1,bool&basla,bool&birkere,bool&jokerused,int&score,int&joker,string&a, int&salak, int& indexofsign, int& indexofequation, int& ikincisayininuzunlugu, int& indexoffirstnums, int& lengthoffirstnums, int& ikincisayininyeri, int& denktirinyeri, int& z, int& x, int& y, int& i, string & firstnums, string&isaret, string&equation, string&ikincisayi, string&denktir, string&sonuc, string&answer){
	

	while (salak < 5){
		jokerused = false;

		if (birkere) {
			if (joker == 0) {
				salak -= 1;
				birkere = false;
				devam = false;
				jokerused = true;
			}
		}

		bool sacmasapanseyler = true;
		bool wrong_input = true;
		bool dur = true;
		bool check = false;
		
		if (!devam) {
			if (joker == 0 && (jokerused)) {
				
				cout << "Please enter the expression again: ";
				devam = true;
			}
		}
		else{
			cout << "Please enter question #" << salak << " and its answer: ";
		}
		
		cin >> a;
		signcorrector(a,firstnums,isaret,equation,ikincisayi,denktir,sonuc,answer,salak,indexofsign,indexofequation,ikincisayininuzunlugu,indexoffirstnums,lengthoffirstnums,ikincisayininyeri,denktirinyeri,z,x,y,i,score);
		string firstnums, isaret, equation, ikincisayi, denktir, sonuc, answer;
		bool index;
		int indexofsign, indexofequation, ikincisayininuzunlugu, indexoffirstnums, lengthoffirstnums, ikincisayininyeri, denktirinyeri, z, x, y, i;



		
		

		if (a.find('+', 1) != std::string::npos) {
			indexofsign = a.find('+', 1);
			isaret = '+';
			index = true;
			arti = true;
		}

		else if (a.find('-', 1) != std::string::npos) {
			indexofsign = a.find('-', 1);
			isaret = '-';
			arti = false;
			index = true;
			if (isaret == a.substr(indexofsign + 1, 1)) {
				isaret = '+';
			}
		}
		else{
			if (jokerused) {
				cout << "Wrong input format! You got -10 penalty points for this joker option." << endl << endl;
				salak += 1;
				score -= 10;
				index = false;
				jokerused = false;

			}
			else {
				cout << "Wrong input format! You got -10 penalty points for this math expression." << endl << endl;
				
				salak += 1;
				score -= 10;
				index = false;
			}

		}
		indexofequation = a.find('=');
		if (indexofequation <= 2) {
			if (jokerused) {
				cout << "Wrong input format! You got -10 penalty points for this joker option." << endl << endl;
			}
			else {
				cout << "Wrong input format! You got -10 penalty points for this math expression." << endl << endl;
			}
			score -= 10;
			sacmasapanseyler = false;
		}
		if (indexofequation != std::string::npos) {
			equation = a.substr(indexofequation + 1, 1);
		}
		

		/*

		for (int element = 0; element < a.length()-1; element+=1) {
			if (isdigit(element)) {
				int numx = a[element];
				cout << numx;
			}
		}
		*/
		while (index) {
			firstnums = a.substr(0, indexofsign);
			indexoffirstnums = a.find(firstnums);
			lengthoffirstnums = firstnums.length();

			//int end = 1;
			//isaret = a.substr(lengthoffirstnums,1);
			//isaretinyeri = a.substr(lengthoffirstnums, end).find(isaret) + lengthoffirstnums;
			if (a.find('=') != std::string::npos) {
				denktirinyeri = a.find('=');
				denktir = a.substr(denktirinyeri, 1);
			}
			else {
				cout << "Wrong input format! You got -10 penalty points for this math expression." << endl << endl;
				score -= 10;
				salak += 1;

			}

			ikincisayininyeri = indexofsign + 1;
			ikincisayininuzunlugu = denktirinyeri - indexofsign - 1;
			ikincisayi = (a.substr(indexofsign + 1, denktirinyeri - indexofsign - 1));

			sonuc = a.substr(denktirinyeri + 1);
			
			for (i = 0; i < a.length(); i++) {
				if (a[i] != '=') {
					if (a[i] != '-') {
						if (a[i] != '+') {
							if (!isdigit(a[i])){
								if (a[i] != '\0') {
									cout << "Wrong input format! You got -10 penalty points for this math expression." << endl << endl;
									wrong_input = false;
									score -= 10;
									salak += 1;
								}
							}
							
						}
					}
				}
			}
			x = atoi(firstnums);
			y = atoi(ikincisayi);
			z = atoi(sonuc);

			int right;
			if (arti) {
				right = (x + y);

			}
			else if (!arti) {
				right = (x - y);


			}


			if (right == z) {
				if (right == 0) {
					right1 = true;
				}
				right1 = true;
			}
			else {
				right1 = false;

				salak += 1;
				if (joker > 0 && sacmasapanseyler) {
					cout << "Wrong!" << endl << "Would you like to use your joker option to correct the answer? ";
					string answer;
					cin >> answer;

					//transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
					string g = "yes";
					ToLower(answer);
					if (g.find(answer) != std::string::npos) {
						joker -= 1;
						jokerused = true;
						question_again(arti,biricik,dur,devam,right1,basla,birkere,jokerused,score,joker,a,salak,indexofsign,indexofequation,ikincisayininuzunlugu,indexoffirstnums,lengthoffirstnums,ikincisayininyeri,denktirinyeri,z,x,y,i,firstnums,isaret,equation,ikincisayi,denktir,sonuc,answer);
						return;
					

					}
					else {
						cout << "Sorry! The answer should have been: " << right << ". You got 0 points for this math expression." << endl << endl;
						dur = false;
					}
					if (salak == 4) {
						herseyibitir();
					}
				}
				//score -= 10;
			}
			if (right1 && wrong_input) {
				if (jokerused) {
					cout << "Correct answer! You got 25 points for this joker option." << endl << endl;
					jokerused = false;
				}
				else {
					cout << "Correct answer! You got 25 points for this math expression." << endl << endl;
				}
				
				score += 25;
				salak += 1;
				
			}
			else if (dur && wrong_input && sacmasapanseyler) {
				if (jokerused){
					cout << "Sorry! The answer should have been: " << right << ". You got -10 penalty points for this joker option." << endl << endl;
					score -= 10;
					jokerused = false;
				}
				else {
					cout << "Sorry! The answer should have been: " << right << ". You got 0 points for this math expression." << endl << endl;
				}
				
			}

			
			/*
			if ((a.find('+',1) == string::npos)){
				cout << "Thid works.";
			}
			else if ((a.find('-',1) == string::npos)){
				cout << "star";
			}*/
			if (salak == 5) {
				check = true;
			}
				

			break;
		}
		if (check) {
			break;
		}
		
	}
}
		

	


int main() {
	int joker = 1;
	bool index;
	int indexofsign, indexofequation, ikincisayininuzunlugu, indexoffirstnums, lengthoffirstnums, ikincisayininyeri, denktirinyeri, z, x, y, i;
	string firstnums, isaret, equation, ikincisayi, denktir, sonuc, answer;
	string a;
	
	int salak = 1;
	int score = 0;
	//buradan
	bool devam = true;
	bool arti;
	bool right1;

	bool biricik = true;
	bool basla = true;
	
	bool jokerused = false;



	bool dur;



	bool math = true;
	bool birkere = true;

	question_again(arti, biricik, dur, devam, right1, basla, birkere, jokerused, score, joker, a, salak, indexofsign, indexofequation, ikincisayininuzunlugu, indexoffirstnums, lengthoffirstnums, ikincisayininyeri, denktirinyeri, z, x, y, i, firstnums, isaret, equation, ikincisayi, denktir, sonuc, answer);
	if (score < 0) {
		score = 0;
	}
	cout << "End of the program. You got " << score << " points in total." << endl;
	return 0;
}