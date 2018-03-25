//--------------------------------------------------
//
//                  �`�e���N���X
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	//�`�e�� ���p�`��
	constexpr u8 NUMBER_OF_ADJECTIVE_MODE = 6;

	//���p�`
	enum ADJECTIVE_MODE :u8 {
		ADJECTIVE_MODE_MIZEN,
		ADJECTIVE_MODE_RENYOU,
		ADJECTIVE_MODE_SYUUSHI,
		ADJECTIVE_MODE_RENTAI,
		ADJECTIVE_MODE_KATEI,
		ADJECTIVE_MODE_RENYOU2
	};

	class Adjective {
	private:
		//���^
		str32 prototype = U"";

		array<str32, NUMBER_OF_ADJECTIVE_MODE> mode_str = {};
		str32 all_mode_str = U"";

	public:
		Adjective(const str32& add_prototype);
		str32 mode(const u8 mode_id = ADJECTIVE_MODE_SYUUSHI);
		void allMode(str32& str);
		str32 addSample(str32& str, const u8 mode_id);

		str32 allModeStr();
		str32 modeStr(const u8 mode_id = ADJECTIVE_MODE_SYUUSHI);
	};

	void addAdjective(vector<Adjective>& adjective, const str32& add_prototype)
	{
		Adjective add_adjective(add_prototype);
		adjective.emplace_back(add_adjective);
		return;
	}

	inline str32 Adjective::modeStr(const u8 mode_id)
	{
		return mode_str[mode_id];
	}

	inline str32 Adjective::allModeStr()
	{
		return all_mode_str;
	}

	inline void Adjective::allMode(str32& str)
	{
		for (u8 i = 0; i < NUMBER_OF_ADJECTIVE_MODE; i++) {
			str += mode(i);
			str = addSample(str, i);
			str += U" ";
		}
		return;
	}

	inline str32 Adjective::addSample(str32& str, const u8 mode_id)
	{
		switch (mode_id)
		{
		case ADJECTIVE_MODE_MIZEN:str += U"/��"; break;
		case ADJECTIVE_MODE_RENYOU:str += U"/��"; break;
		case ADJECTIVE_MODE_RENTAI:str += U"/�Ƃ�"; break;
		case ADJECTIVE_MODE_KATEI:str += U"/��"; break;
		case ADJECTIVE_MODE_RENYOU2:str += U"/�Ȃ�"; break;
		}
		return str;
	}

	inline Adjective::Adjective(const str32& add_prototype)
	{
		prototype = add_prototype;

		for (u8 i = 0; i < NUMBER_OF_ADJECTIVE_MODE; i++) {
			mode_str[i] = mode(i);
		}
		allMode(all_mode_str);
	}

	inline str32 Adjective::mode(const u8 mode_id)
	{
		str32 str = prototype;

		switch (mode_id)
		{
		case ADJECTIVE_MODE_MIZEN:str += U"����"; break;
		case ADJECTIVE_MODE_RENYOU:str += U"����"; break;
		case ADJECTIVE_MODE_RENYOU2:str += U'��'; break;
		case ADJECTIVE_MODE_SYUUSHI:str += U'��'; break;
		case ADJECTIVE_MODE_RENTAI:str += U'��'; break;
		case ADJECTIVE_MODE_KATEI:str += U"����"; break;
		}

		return str;
	}

}