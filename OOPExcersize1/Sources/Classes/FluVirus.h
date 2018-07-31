#pragma once
#include"Virus.h"

#define BLUE 0x0000ff
#define RED 0xff0000
#define DIE_COLOR -1

class FluVirus :public Virus {
public:
	int m_color;

public:
	FluVirus();
	FluVirus(FluVirus *flu_virus);
	~FluVirus();

public:
	void DoBorn();
	Virus** DoClone();
	void DoDie();
	void InitResistance();
	int GetMark();
};
