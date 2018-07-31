#include "Patient.h"

Patient::Patient()
{
	this->InitResistance();
	this->DoStart();
}

Patient::~Patient()
{
	this->DoDie();
}

void Patient::InitResistance()
{
	this->m_resistance = rand() % (int)RESISTANCE_RANGE + MIN_RESISTANCE;
}

void Patient::DoStart()
{
	int type_amount = 2, type=0;
	int virus_amount = rand() % (int)VIRUS_AMOUNT_RANGE + VIRUS_AMOUNT_MIN;

	for (int i = 0; i < virus_amount; i++) {
		type = rand() % (int)type_amount;
		Virus *virus = NULL;
		this->m_virusList.push_back(virus);

		switch (type) {
		case FLU_VIRUS:
			this->m_virusList.back() = new FluVirus();
			break;
		case DENGUE_VIRUS:
			this->m_virusList.back() = new DengueVirus();
			break;
		}
	}

	//cout << "Amount:" << virus_amount << endl;
	//for (list<Virus*>::iterator iter = this->m_virusList.begin(); iter != this->m_virusList.end(); ++iter) {
	//	cout << (*iter)->m_resistance << endl;
	//	cout << (*iter)->GetMark() << endl;
	//	switch ((*iter)->GetMark()) {
	//	case FLU_VIRUS: {
	//		cout << ((FluVirus*)*iter)->m_color << endl;
	//		break;
	//	}
	//	case DENGUE_VIRUS: {
	//		cout << ((DengueVirus*)*iter)->m_protein << endl;
	//		break;
	//	}
	//	}
	//	cout << "-------------" << endl;
	//}

	this->m_state = 1;
}

void Patient::TakeMedicine(int medicine_resistance)
{
	if ((medicine_resistance < 1) || (medicine_resistance > 60)) {
		cout << "Invalid medicine_resistance" << endl;
		return;
	}

	int amount = this->m_virusList.size();
	list<Virus*>::iterator iter;
	int virus_resistance_sum = 0;

	if (amount > 0) {            
		iter = this->m_virusList.begin();
		int i = 0;
		while (i < amount) {
			(*iter)->ReduceResistance(medicine_resistance);

			if ((*iter)->m_resistance <= 0) {
				delete (*iter);
				(*iter) = NULL;
			}
			else {
				//cout << (*iter)->GetMark() << endl;
				Virus **clones = (*iter)->DoClone();
				int clone_amount = 0;

				switch ((*iter)->GetMark()) {
				case FLU_VIRUS: {
					clone_amount = 1;
					break;
				}
				case DENGUE_VIRUS: {
					clone_amount = 2;
					break;
				}
				}

				for (int j = 0; j < clone_amount; j++) {
					Virus* virus = NULL;
					this->m_virusList.push_back(virus);
					this->m_virusList.back() = clones[j];
				}

				virus_resistance_sum += (*iter)->m_resistance*(1 + clone_amount);
			}
			++i;
			++iter;
		}

		iter = this->m_virusList.begin();
		while (iter != this->m_virusList.end()) {
			if ((*iter) == NULL) {
				iter = this->m_virusList.erase(iter);
			}
			else
				++iter;
		}
	}

	cout << endl;
	cout << "Patient resistance:" << this->m_resistance << endl;
	cout << "Virus resistance sum:" << virus_resistance_sum << endl;
	cout << "Virus amount after taking medicine:" << this->m_virusList.size() << endl;
	for (iter = this->m_virusList.begin(); iter != this->m_virusList.end(); ++iter)
		cout << (*iter)->m_resistance << " ";
	cout << endl;

	if (this->m_resistance < virus_resistance_sum) {
		this->DoDie();
	}
}

void Patient::DoDie()
{
	if (this->m_virusList.size() > 0) {
		for (list<Virus*>::iterator iter = this->m_virusList.begin();
			iter != this->m_virusList.end(); ++iter) {
			delete (*iter);
		}		
		this->m_virusList.clear();
	}

	this->m_resistance = DEATH_RESISTANCE;
	this->m_state = DIE;
}

int Patient::GetState()
{
	return this->m_state;
}




