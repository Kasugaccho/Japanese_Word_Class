//--------------------------------------------------
//
//                 形容動詞クラス
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	//形容動詞 活用形数
	constexpr u8 NUMBER_OF_ADJECTIVE_VERB_MODE = 8;

	//活用形
	enum ADJECTIVE_VERB_MODE :u8 {
		ADJECTIVE_VERB_MODE_MIZEN,
		ADJECTIVE_VERB_MODE_RENYOU,
		ADJECTIVE_VERB_MODE_SYUUSHI,
		ADJECTIVE_VERB_MODE_RENTAI,
		ADJECTIVE_VERB_MODE_KATEI,
		ADJECTIVE_VERB_MODE_RENYOU2,
		ADJECTIVE_VERB_MODE_RENYOU3,
		ADJECTIVE_VERB_MODE_RENTAI2
	};

	class AdjectiveVerb {
	private:
		//原型
		str32 prototype = U"";
		
		bool isException = false;

		array<str32, NUMBER_OF_ADJECTIVE_VERB_MODE> mode_str = {};
		str32 all_mode_str = U"";

	public:
		AdjectiveVerb(const str32& add_prototype);
		str32 mode(const u8 mode_id = ADJECTIVE_VERB_MODE_SYUUSHI);
		void allMode(str32& str);
		str32 addSample(str32& str, const u8 mode_id);

		str32 allModeStr();
		str32 modeStr(const u8 mode_id = ADJECTIVE_VERB_MODE_SYUUSHI);
	};

	void addAdjectiveVerb(vector<AdjectiveVerb>& adjective_verb, const str32& add_prototype)
	{
		AdjectiveVerb add_adjective_verb(add_prototype);
		adjective_verb.emplace_back(add_adjective_verb);
		return;
	}

	inline str32 AdjectiveVerb::modeStr(const u8 mode_id)
	{
		return mode_str[mode_id];
	}

	inline str32 AdjectiveVerb::allModeStr()
	{
		return all_mode_str;
	}

	inline void AdjectiveVerb::allMode(str32& str)
	{
		for (u8 i = 0; i < NUMBER_OF_ADJECTIVE_VERB_MODE; i++) {
			str += mode(i);
			str = addSample(str, i);
			str += U" ";
		}
		return;
	}

	inline str32 AdjectiveVerb::addSample(str32& str, const u8 mode_id)
	{
		switch (mode_id)
		{
		case ADJECTIVE_VERB_MODE_MIZEN:str += U"/う"; break;
		case ADJECTIVE_VERB_MODE_RENYOU:str += U"/た"; break;
		case ADJECTIVE_VERB_MODE_RENTAI:str += U"/とき"; break;
		case ADJECTIVE_VERB_MODE_KATEI:str += U"/ば"; break;
		case ADJECTIVE_VERB_MODE_RENYOU2:str += U"/ない"; break;
		case ADJECTIVE_VERB_MODE_RENYOU3:str += U"/なる"; break;
		case ADJECTIVE_VERB_MODE_RENTAI2:str += U"/のに"; break;
		}
		return str;
	}

	inline AdjectiveVerb::AdjectiveVerb(const str32& add_prototype)
	{
		prototype = add_prototype;

		if (prototype == U"こんな" || prototype == U"そんな" || prototype == U"あんな" || prototype == U"どんな" || prototype == U"同じ" || prototype == U"おなじ") {
			isException = true;
		}

		for (u8 i = 0; i < NUMBER_OF_ADJECTIVE_VERB_MODE; i++) {
			mode_str[i] = mode(i);
		}
		allMode(all_mode_str);
	}

	inline str32 AdjectiveVerb::mode(const u8 mode_id)
	{
		str32 str = prototype;

		switch (mode_id)
		{
		case ADJECTIVE_VERB_MODE_MIZEN:str += U"だろ"; break;
		case ADJECTIVE_VERB_MODE_RENYOU:str += U"だっ"; break;
		case ADJECTIVE_VERB_MODE_RENYOU2:str += U'で'; break;
		case ADJECTIVE_VERB_MODE_RENYOU3:str += U'に'; break;
		case ADJECTIVE_VERB_MODE_SYUUSHI:str += U'だ'; break;
		case ADJECTIVE_VERB_MODE_RENTAI:
			if (isException)break;
			else str += U'な'; break;
		case ADJECTIVE_VERB_MODE_KATEI:str += U"なら"; break;
		case ADJECTIVE_VERB_MODE_RENTAI2:str += U'な'; break;
		}

		return str;
	}

}