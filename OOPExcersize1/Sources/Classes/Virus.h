#pragma once
#include<fstream>
#include<string>

using namespace std;

#define DNA_FILE "ATGX.bin"
#define MIN_RESISTANCE 10
#define MAX_RESISTANCE 30
#define DIE_RESISTANCE 0

#define FLU_VIRUS 0             //marks
#define DENGUE_VIRUS 1

class Virus {
public:
	char *m_dna;
	int m_resistance;

public:
	Virus();
	Virus(Virus *virus);
	virtual ~Virus();

public:
	void LoadADNInformation();
	void ReduceResistance(int medicine_resistance);
	
	virtual void DoBorn() = 0;
	virtual Virus** DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
	virtual int GetMark() = 0;
};
