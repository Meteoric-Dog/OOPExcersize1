#include "DengueVirus.h"
#include<iostream>

using namespace std;

const char *PROTEIN[] = {"NS3", "NS5", "E"};

DengueVirus::DengueVirus()
{
	this->DoBorn();
	this->InitResistance();
}

DengueVirus::DengueVirus(DengueVirus * dengue_virus):Virus((Virus*)dengue_virus)
{
	memcpy(this->m_protein, dengue_virus->m_protein, PROTEIN_SIZE);
}

DengueVirus::~DengueVirus()
{
	this->DoDie();
}

void DengueVirus::DoBorn()
{
	this->LoadADNInformation();
	
	int id = rand() % (int)3;
	memcpy(this->m_protein, PROTEIN[id], strlen(PROTEIN[id]));
	this->m_protein[strlen(PROTEIN[id])] = 0;
}

Virus ** DengueVirus::DoClone()
{
	Virus **result = new Virus*[CLONE_AMOUNT];
	for (int i = 0; i < CLONE_AMOUNT; i++)
		result[i] = new DengueVirus(this);
	return result;
}

void DengueVirus::DoDie()
{
	//release all data
	//if (this->m_dna)
	//	delete[] this->m_dna;
	this->m_resistance = DIE_RESISTANCE;
	if (this->m_protein)
		memset(this->m_protein, 0, PROTEIN_SIZE);
}

void DengueVirus::InitResistance()
{
	int amount = 3, range = 10;
	for (int i = 0; i < amount; i++)
		if (strcmp(this->m_protein, PROTEIN[i])) {
			this->m_resistance = rand() % (int)range + range * i + 1;
		}
}

int DengueVirus::GetMark()
{
	return DENGUE_VIRUS;
}

DengueVirus& DengueVirus::operator=(const DengueVirus &o2)
{
	this->m_resistance = o2.m_resistance;
	memcpy(this->m_protein, o2.m_protein, PROTEIN_SIZE);

	if (this->m_dna)
		delete[] this->m_dna;
	int dna_size = strlen(o2.m_dna);
	this->m_dna = new char[dna_size + 1];
	memcpy(this->m_dna, o2.m_dna, dna_size);
	this->m_dna[dna_size] = 0;

	return *this;
}

