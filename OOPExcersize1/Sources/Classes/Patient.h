#pragma once
#include<iostream>
#include<list>
#include"Virus.h"
#include"FluVirus.h"
#include"DengueVirus.h"

using namespace std;

#define DIE 0
#define ALIVE 1

#define MIN_RESISTANCE 1000
#define RESISTANCE_RANGE 8001
#define DEATH_RESISTANCE -1

#define VIRUS_AMOUNT_RANGE 11
#define VIRUS_AMOUNT_MIN 10

class Patient {
public:
	int m_resistance;
	int m_state;
	list<Virus*> m_virusList;

public:
	Patient();
	~Patient();

public:
	void InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);
	void DoDie();
	int GetState();
};
