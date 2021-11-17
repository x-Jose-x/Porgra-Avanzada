using namespace::System;
#pragma once
ref class Figura
{
	String^ id;

public:
	virtual double calcularArea() = 0;
	virtual double calcularPerimetro() = 0;
};

