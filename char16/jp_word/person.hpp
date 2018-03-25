//--------------------------------------------------
//
//                   人名クラス
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	class Person
	{
	private:

		//名前
		str32 all_name;

		//国籍
		size_t country;

		//出生地
		size_t born_place;

		//性別
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