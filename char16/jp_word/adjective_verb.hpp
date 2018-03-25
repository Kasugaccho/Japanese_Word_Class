//--------------------------------------------------
//
//                 �`�e�����N���X
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	//�`�e���� ���p�`��
	constexpr u8 NUMBER_OF_ADJECTIVE_VERB_MODE = 8;

	//���p�`
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
		//���^
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
		case ADJECTIVE_VERB_MODE_MIZEN:str += U"/��"; break;
		case ADJECTIVE_VERB_MODE_RENYOU:str += U"/��"; break;
		case ADJECTIVE_VERB_MODE_RENTAI:str += U"/�Ƃ�"; break;
		case ADJECTIVE_VERB_MODE_KATEI:str += U"/��"; break;
		case ADJECTIVE_VERB_MODE_RENYOU2:str += U"/�Ȃ�"; break;
		case ADJECTIVE_VERB_MODE_RENYOU3:str += U"/�Ȃ�"; break;
		case ADJECTIVE_VERB_MODE_RENTAI2:str += U"/�̂�"; break;
		}
		return str;
	}

	inline AdjectiveVerb::AdjectiveVerb(const str32& add_prototype)
	{
		prototype = add_prototype;

		if (prototype == U"�����" || prototype == U"�����" || prototype == U"�����" || prototype == U"�ǂ��" || prototype == U"����" || prototype == U"���Ȃ�") {
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
		case ADJECTIVE_VERB_MODE_MIZEN:str += U"����"; break;
		case ADJECTIVE_VERB_MODE_RENYOU:str += U"����"; break;
		case ADJECTIVE_VERB_MODE_RENYOU2:str += U'��'; break;
		case ADJECTIVE_VERB_MODE_RENYOU3:str += U'��'; break;
		case ADJECTIVE_VERB_MODE_SYUUSHI:str += U'��'; break;
		case ADJECTIVE_VERB_MODE_RENTAI:
			if (isException)break;
			else str += U'��'; break;
		case ADJECTIVE_VERB_MODE_KATEI:str += U"�Ȃ�"; break;
		case ADJECTIVE_VERB_MODE_RENTAI2:str += U'��'; break;
		}

		return str;
	}

}