//--------------------------------------------------
//
//                   �l���N���X
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	class Person
	{
	private:

		//���O
		str32 all_name;

		//����
		size_t country;

		//�o���n
		size_t born_place;

		//����
		size_t a;

	public:
		Person();
		~Person();


	};

	inline Person::Person()
	{
	}

	inline Person::~Person()
	{
	}


}