//--------------------------------------------------
//
//                   –¼ŽŒƒNƒ‰ƒX
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	enum NOUN_TYPE :u32
	{
		NOUN_TYPE_UNKNOWN,
		NOUN_TYPE_FOOD,
		NOUN_TYPE_DRINK,
		NOUN_TYPE_PERSON1,
		NOUN_TYPE_PERSON2,
		NOUN_TYPE_PERSON3,
	};

	class Noun {
	private:
		str32 word_class_name = U"";
		u32 type = NOUN_TYPE_UNKNOWN;

	public:
		Noun(const str32& add_name);
		str32 show_name();
	};

	inline Noun::Noun(const str32& add_name) {
		word_class_name = add_name;
	}

	inline str32 Noun::show_name() {
		return word_class_name;
	}

}