#pragma once

template <typename T>
class Cola
{
	struct Nodo
	{
		T* item;
		Nodo* Next = nullptr;
		int id;

		Nodo(T* item) {
			this->item = item;
			this->Next = nullptr;
		}
	};

	Nodo* headC = nullptr; 
	Nodo* tailC = nullptr;
	int sizeC = 0;

public:

	int getSizeC() {
		return this->sizeC;
	}

	bool isEmptyC() {
		if (headC == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void addCola(T* item) {

		Nodo* node = new Nodo(item);
		
		if (this->isEmptyC())
		{
			headC = node;
			tailC = node;
		}
		else
		{
			tailC->Next = node;
			tailC = node;
		}
		
		this->sizeC++;

	}

	T* topC() {
		return this->headC->item;
	}

	T* popC() {
		if (headC != nullptr || tailC != nullptr) {
			if (this->headC->Next != nullptr) {
				Nodo* Auxiliar = new Nodo(headC);
				while (Auxiliar->Next != this->tailC) {
					Auxiliar = Auxiliar->Next;
				}
				this->tailC = Auxiliar;
				this->tailC->Next = nullptr;
				this->sizeC--;
				return Auxiliar;
				delete Auxiliar;
			}
			else {
				this->headC = nullptr;
				this->tailC = nullptr;
			}
		}
	}

	T* getC(int index) {
		if (index >= this->sizeC|| index < 0)
		{
			return nullptr; 
		}

		Nodo* iterator = this->headC;

		int i = 0;

		while (i < index)
		{
			iterator = iterator->Next;
			i++;
		}

		return iterator->item;
	}

	T* remove(int index) {
		if (index >= this->sizeC || index <= 0)
		{
			return nullptr;
		}

		Nodo** iterator = &this->headC;
		Nodo* previous = nullptr;

		int i = 0;

		while (i < index) {
			previous = *iterator;
			iterator = &((*iterator)->Next);
			i++;
		}

		if (this->sizeC - 1 == index) {
			this->tailC = previous;
		}

		*iterator = (*iterator)->Next;
		this->sizeC--;
	}


};

