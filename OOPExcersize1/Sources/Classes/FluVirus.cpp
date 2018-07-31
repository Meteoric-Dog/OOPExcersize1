#include "FluVirus.h"

FluVirus::FluVirus()
{
	this->DoBorn();
	this->InitResistance();
}

FluVirus::FluVirus(FluVirus * flu_virus) :Virus((Virus*)flu_virus), m_color(flu_virus->m_color)
{
}

FluVirus::~FluVirus()
{
	this->DoDie();
}

void FluVirus::DoBorn()
{
	this->LoadADNInformation();
	int type_amount = 2;
	this->m_color = ((rand() % type_amount) == 0) ? BLUE : RED;
}

Virus ** FluVirus::DoClone()
{
	int amount = 1;
	Virus **virus = new Virus*[amount];
	for (int i = 0; i < amount; i++)
		virus[i] = new FluVirus(this);
	return virus;
}

void FluVirus::DoDie()
{
	//release all virus data
	//if (this->m_dna)
	//	delete[] this->m_dna;
	this->m_resistance = DIE_RESISTANCE;
	this->m_color = DIE_COLOR;
}

void FluVirus::InitResistance()
{
	switch (this->m_color) {
	case RED:
		this->m_resistance = rand() % (int)(MIN_RESISTANCE + 1) + MIN_RESISTANCE;
		break;
	case BLUE:
		this->m_resistance = rand() % (int)(MIN_RESISTANCE / 2 + 1) + MIN_RESISTANCE;
		break;
	default:
		this->m_resistance = MIN_RESISTANCE - 1;
	}
}

int FluVirus::GetMark()
{
	return FLU_VIRUS;
}
