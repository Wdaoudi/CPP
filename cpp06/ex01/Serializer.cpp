#include "Data.hpp"
#include "Serializer.hpp"

//canonic
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void)copy;
	return (*this);
}

Serializer::~Serializer()
{
}
/* convert */
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

/*
reinterprest cast: le convertisseur le plus brut 
sans verification prealable de compatibilite 
reinterpretation bit a bit */