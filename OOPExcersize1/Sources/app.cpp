#pragma once
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include"Classes/Patient.h"

using namespace std;

int main() {
	Patient p;
	int t = 0;
	while (p.GetState() == 1) {
		cout << "Take Medicine (0=NO, 1=YES, 2=QUIT LOOP)" << endl;
		fflush(stdin);
		cin >> t;
		if (t == 1) {
			int min = 1;
			int max = 60;
			int medicine_resistance = min + rand() % (int)(max - min + 1);
			cout << "medicine_resistance:" << medicine_resistance << endl;
			p.TakeMedicine(medicine_resistance);
		}
		else
			if (t == 2)
				break;
	}

	if (p.GetState() == 0)
		cout << endl << "Patient died" << endl;
	system("pause");
	return 0;
}