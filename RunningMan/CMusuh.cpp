#include "CMusuh.h"

void CMusuh::initVariables()
{

}

CMusuh::CMusuh()
{

}

CMusuh::~CMusuh()
{
}

CMusuh::CMusuh(const CMusuh& n)
{
}

void CMusuh::render(RenderTarget& target)
{
	target.draw(this->sprite);
}

Clock& CMusuh::get_time()
{
	return this->time;
}


