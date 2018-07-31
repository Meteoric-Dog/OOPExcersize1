#pragma once
#include"Virus.h"

#define PROTEIN_SIZE 4
#define CLONE_AMOUNT 2

class DengueVirus :public Virus {
public:
	char m_protein[PROTEIN_SIZE];

public:
	DengueVirus();
	DengueVirus(DengueVirus *dengue_virus);
	~DengueVirus();

public:
	void DoBorn();
	Virus** DoClone();
	void DoDie();
	void InitResistance();
	int GetMark();
	
	DengueVirus& operator=(const DengueVirus &o2);
};
