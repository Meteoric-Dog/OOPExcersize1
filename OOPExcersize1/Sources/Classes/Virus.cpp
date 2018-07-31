#include "Virus.h"

Virus::Virus()
{
	this->m_dna = NULL;
	this->m_resistance = MIN_RESISTANCE - 1;
}

Virus::Virus(Virus * virus)
{
	int leng = strlen(virus->m_dna);
	this->m_dna = new char[leng + 1];
	memcpy(this->m_dna, virus->m_dna, leng);
	this->m_dna[leng] = 0;

	this->m_resistance = virus->m_resistance;
}

Virus::~Virus()
{
	if (this->m_dna)
		delete[] this->m_dna;
}

void Virus::LoadADNInformation()
{
	fstream file;
	file.open(DNA_FILE, ios::in | ios::binary);
	string temp;

	if (file.is_open()) 
	{
		if (file.peek() != EOF) {
			getline(file, temp);
			
			int leng = temp.length();
			this->m_dna = new char[leng + 1];

			memcpy(this->m_dna, temp.c_str(), leng);
			this->m_dna[leng] = 0;
		}
	}

	file.close();
}

void Virus::ReduceResistance(int medicine_resistance)
{
	this->m_resistance -= medicine_resistance;
}
