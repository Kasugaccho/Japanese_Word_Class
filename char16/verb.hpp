//--------------------------------------------------
//
//                   動詞クラス
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	//形容詞 活用形数
	constexpr u8 NUMBER_OF_VERB_MODE = 11;

	//動詞グループ
	enum VERB_GROUP :u8 {
		VERB_GROUP_U,
		VERB_GROUP_RU,
		VERB_GROUP_SURU,
		VERB_GROUP_SURU2,
		VERB_GROUP_KURU,
		VERB_GROUP_KURU2
	};

	constexpr size_t NUMBER_OF_VERB_GROUP = 6;
	constexpr size_t VERB_GROUP_LEN = 10;
	constexpr array<array<c32, VERB_GROUP_LEN>, NUMBER_OF_VERB_GROUP>VERB_GROUP_NAME =
	{ U"五段活用",U"一段活用",U"変格活用(する)",U"変格活用(ずる)",U"変格活用(来る)",U"変格活用(くる)" };

	//語尾
	enum VERB_END :u8 {
		VERB_U,
		VERB_KU,
		VERB_SU,
		VERB_TU,
		VERB_NU,
		VERB_HU,
		VERB_MU,
		VERB_YU,
		VERB_RU,
		VERB_WU,
		VERB_GU,
		VERB_ZU,
		VERB_DU,
		VERB_BU,
		VERB_PU
	};

	constexpr size_t NUMBER_OF_VERB_END = 15;
	constexpr array<c32, NUMBER_OF_VERB_END>VERB_END_NAME = { U'ア',U'カ',U'サ',U'タ',U'ナ',U'ハ',U'マ',U'ヤ',U'ラ',U'ワ',U'ガ',U'ザ',U'ダ',U'バ',U'パ' };

	//活用形
	enum VERB_MODE :u8 {
		VERB_MODE_MIZEN,
		VERB_MODE_RENYOU,
		VERB_MODE_SYUUSHI,
		VERB_MODE_RENTAI,
		VERB_MODE_KATEI,
		VERB_MODE_MEIREI,
		VERB_MODE_MIZEN2,

		//"５段"活用形(音便)
		VERB_MODE_RENYOU2,

		//"する"活用形
		VERB_MODE_MIZEN3,
		VERB_MODE_MIZEN4,
		VERB_MODE_MEIREI2
	};

	constexpr u8 NUMBER_OF_VERB_STR_RU = 4;
	constexpr array<c32, NUMBER_OF_VERB_STR_RU> VERB_STR_RU = { U'る', U'れ', U'ろ', U'よ' };

	enum VERB_STR_RU_ID :size_t {
		VERB_STR_ID_RU,
		VERB_STR_ID_RE,
		VERB_STR_ID_RO,
		VERB_STR_ID_YO
	};

	class Verb {
	private:
		//原型
		str32 prototype = U"";

		//動詞グループ
		u8 group;
		//語尾
		u8 end = VERB_RU;

		//語尾のあいうえお表
		array<c32, NUMBER_OF_VOWEL> str_xa;

		//音便
		c32 euphony;

		array<str32, NUMBER_OF_VERB_MODE> mode_str = { {} };
		str32 all_mode_str = U"";

	public:
		Verb(const str32& add_prototype, const u8 add_group, const u8 add_end = VERB_RU);
		str32 mode(const u8 mode_id = VERB_MODE_SYUUSHI);
		void allMode(str32& str);
		str32 addSample(str32& str, const u8 mode_id);

		str32 allModeStr();
		str32 modeStr(const u8 mode_id = VERB_MODE_SYUUSHI);
	};

	void addVerb(vector<Verb>& verb, const str32& add_prototype, const u8 add_group, const u8 add_end = VERB_RU)
	{
		Verb add_verb(add_prototype, add_group, add_end);
		verb.emplace_back(add_verb);
		return;
	}

	inline str32 Verb::modeStr(const u8 mode_id)
	{
		return mode_str[mode_id];
	}

	inline str32 Verb::allModeStr()
	{
		return all_mode_str;
	}

	inline void Verb::allMode(str32& str)
	{
		for (u8 i = 0; i < 8; i++) {
			str += mode(i);
			str = addSample(str, i);
			str += U" ";
		}
		return;
	}

	inline str32 Verb::addSample(str32& str, const u8 mode_id)
	{
		switch (mode_id)
		{
		case VERB_MODE_MIZEN:str += U"/ない"; break;
		case VERB_MODE_RENYOU:str += U"/ます"; break;
		case VERB_MODE_RENTAI:str += U"/とき"; break;
		case VERB_MODE_KATEI:str += U"/ば"; break;
		case VERB_MODE_MIZEN2:str += U"/う"; break;

		case VERB_MODE_RENYOU2:
			switch (end)
			{
			case VERB_GU:
			case VERB_NU:
			case VERB_BU:
			case VERB_MU:
				str += U"/だ";
				break;

			default:
				str += U"/た";
				break;
			}
			break;
		}
		return str;
	}

	inline Verb::Verb(const str32& add_prototype, const u8 add_group, const u8 add_end)
	{
		prototype = add_prototype;
		group = add_group;
		end = add_end;

		switch (add_end)
		{
		case VERB_U:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_A[i]; break;
		case VERB_KU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_KA[i]; break;
		case VERB_SU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_SA[i]; break;
		case VERB_TU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_TA[i]; break;
		case VERB_NU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_NA[i]; break;
		case VERB_HU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_HA[i]; break;
		case VERB_MU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_MA[i]; break;
		case VERB_YU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_YA[i]; break;
		case VERB_RU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_RA[i]; break;
		case VERB_WU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_WA[i]; break;
		case VERB_GU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_GA[i]; break;
		case VERB_ZU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_ZA[i]; break;
		case VERB_DU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_DA[i]; break;
		case VERB_BU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_BA[i]; break;
		case VERB_PU:for (size_t i = 0; i < 5; i++) str_xa[i] = WORD_CLASS_STR_PA[i]; break;
		}

		switch (group)
		{
		case VERB_GROUP_U:
			switch (end)
			{
			case VERB_KU:
			case VERB_GU:
				if (prototype[0] == U'行') euphony = U'っ';
				else euphony = U'い';
				break;
			case VERB_NU:
			case VERB_BU:
			case VERB_MU:
				euphony = U'ん';
				break;
			case VERB_TU:
			case VERB_RU:
			case VERB_WU:
				euphony = U'っ';
				break;
			default:
				euphony = str_xa[WORD_CLASS_STR_ID_I];
				break;
			}
			break;
		default:
			euphony = 0;
			break;
		}



		for (u8 i = 0; i < 8; i++) {
			mode_str[i] = mode(i);
		}
		allMode(all_mode_str);
	}

	inline str32 Verb::mode(const u8 mode_id)
	{
		str32 str = prototype;

		switch (group) {

		case VERB_GROUP_KURU:

			switch (mode_id)
			{
			case VERB_MODE_MIZEN:str += U'来'; break;
			case VERB_MODE_RENYOU:
			case VERB_MODE_RENYOU2:str += U'来'; break;
			case VERB_MODE_SYUUSHI:str += U"来る"; break;
			case VERB_MODE_RENTAI:str += U"来る"; break;
			case VERB_MODE_KATEI:str += U"来れ"; break;
			case VERB_MODE_MEIREI:str += U"来い"; break;
			case VERB_MODE_MIZEN2:str += U"来よ"; break;
			}

			break;

		case VERB_GROUP_KURU2:

			switch (mode_id)
			{
			case VERB_MODE_MIZEN:str += U'こ'; break;
			case VERB_MODE_RENYOU:
			case VERB_MODE_RENYOU2:str += U'き'; break;
			case VERB_MODE_SYUUSHI:str += U"くる"; break;
			case VERB_MODE_RENTAI:str += U"くる"; break;
			case VERB_MODE_KATEI:str += U"くれ"; break;
			case VERB_MODE_MEIREI:str += U"こい"; break;
			case VERB_MODE_MIZEN2:str += U"こよ"; break;
			}

			break;

		case VERB_GROUP_SURU:

			switch (mode_id)
			{
			case VERB_MODE_MIZEN:str += U'し'; break;
			case VERB_MODE_RENYOU:
			case VERB_MODE_RENYOU2:str += U'し'; break;
			case VERB_MODE_SYUUSHI:str += U"する"; break;
			case VERB_MODE_RENTAI:str += U"する"; break;
			case VERB_MODE_KATEI:str += U"すれ"; break;
			case VERB_MODE_MEIREI:str += U"しろ"; break;
			case VERB_MODE_MIZEN2:str += U"しよ"; break;

			case VERB_MODE_MIZEN3:str += U"せ"; break;
			case VERB_MODE_MIZEN4:str += U"さ"; break;
			case VERB_MODE_MEIREI2:str += U"せよ"; break;
			}

			break;

		case VERB_GROUP_SURU2:

			switch (mode_id)
			{
			case VERB_MODE_MIZEN:str += U'じ'; break;
			case VERB_MODE_RENYOU:
			case VERB_MODE_RENYOU2:str += U'じ'; break;
			case VERB_MODE_SYUUSHI:str += U"ずる"; break;
			case VERB_MODE_RENTAI:str += U"ずる"; break;
			case VERB_MODE_KATEI:str += U"ずれ"; break;
			case VERB_MODE_MEIREI:str += U"じろ"; break;
			case VERB_MODE_MIZEN2:str += U"じよ"; break;

			case VERB_MODE_MIZEN3:str += U"ぜ"; break;
			case VERB_MODE_MIZEN4:str += U"ざ"; break;
			case VERB_MODE_MEIREI2:str += U"ぜよ"; break;
			}

			break;

		case VERB_GROUP_RU:

			switch (mode_id)
			{
			case VERB_MODE_SYUUSHI:
			case VERB_MODE_RENTAI:str += VERB_STR_RU[VERB_STR_ID_RU]; break;
			case VERB_MODE_KATEI:str += VERB_STR_RU[VERB_STR_ID_RE]; break;
			case VERB_MODE_MEIREI:str += VERB_STR_RU[VERB_STR_ID_RO]; break;
			case VERB_MODE_MIZEN2:str += VERB_STR_RU[VERB_STR_ID_YO]; break;
			}

			break;

		case VERB_GROUP_U:

			switch (mode_id)
			{
			case VERB_MODE_MIZEN:str += str_xa[WORD_CLASS_STR_ID_A]; break;
			case VERB_MODE_RENYOU:str += str_xa[WORD_CLASS_STR_ID_I]; break;
			case VERB_MODE_SYUUSHI:
			case VERB_MODE_RENTAI:str += str_xa[WORD_CLASS_STR_ID_U]; break;
			case VERB_MODE_KATEI:
			case VERB_MODE_MEIREI:str += str_xa[WORD_CLASS_STR_ID_E]; break;
			case VERB_MODE_MIZEN2:str += str_xa[WORD_CLASS_STR_ID_O]; break;
			case VERB_MODE_RENYOU2:str += euphony; break;
			}

			break;
		}

		return str;
	}

}