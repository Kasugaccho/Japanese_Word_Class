//--------------------------------------------------
//
//                  助動詞クラス
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	//助動詞数
	constexpr size_t NUMBER_OF_PARTICLE_VERB = 21;

	//助動詞 全種類
	enum PARTICLE_VERB :u8 {
		PARTICLE_VERB_GROUP_SERU,
		PARTICLE_VERB_GROUP_SASERU,
		PARTICLE_VERB_GROUP_RERU,
		PARTICLE_VERB_GROUP_RARERU,
		PARTICLE_VERB_GROUP_NAI,
		PARTICLE_VERB_GROUP_NU,
		PARTICLE_VERB_GROUP_NN,
		PARTICLE_VERB_GROUP_U,
		PARTICLE_VERB_GROUP_YOU,
		PARTICLE_VERB_GROUP_MAI,
		PARTICLE_VERB_GROUP_TAI,
		PARTICLE_VERB_GROUP_TAGARU,
		PARTICLE_VERB_GROUP_TA,
		PARTICLE_VERB_GROUP_DA,
		PARTICLE_VERB_GROUP_SOUDA,
		PARTICLE_VERB_GROUP_SOUDA2,
		PARTICLE_VERB_GROUP_YOUDA,
		PARTICLE_VERB_GROUP_RASHII,
		PARTICLE_VERB_GROUP_MASU,
		PARTICLE_VERB_GROUP_DA2,
		PARTICLE_VERB_GROUP_DESU
	};

	//助動詞 活用形数
	constexpr size_t NUMBER_OF_PARTICLE_VERB_MODE = 10;

	//活用形
	enum PARTICLE_VERB_MODE :u8 {
		PARTICLE_VERB_MODE_MIZEN,
		PARTICLE_VERB_MODE_RENYOU,
		PARTICLE_VERB_MODE_SYUUSHI,
		PARTICLE_VERB_MODE_RENTAI,
		PARTICLE_VERB_MODE_KATEI,
		PARTICLE_VERB_MODE_MEIREI,
		PARTICLE_VERB_MODE_MIZEN2,
		PARTICLE_VERB_MODE_RENYOU2,
		PARTICLE_VERB_MODE_RENYOU3,
		PARTICLE_VERB_MODE_MEIREI2
	};

	class ParticleVerb {
	private:
		array<str32, NUMBER_OF_PARTICLE_VERB_MODE> mode_str = {};
		str32 all_mode_str = U"";

	public:
		//str32 mode(const u8 mode_id = ADJECTIVE_VERB_MODE_SYUUSHI);
		void allMode();
		//str32 addSample(str32& str, const u8 mode_id);
		str32 allModeStr();
		void addStr(array<str32, NUMBER_OF_PARTICLE_VERB_MODE> add_mode_str);
	};

	inline void ParticleVerb::addStr(array<str32, NUMBER_OF_PARTICLE_VERB_MODE> add_mode_str)
	{
		for (size_t i = 0; i < NUMBER_OF_PARTICLE_VERB_MODE; i++) mode_str[i] = add_mode_str[i];
		return;
	}

	array<str32, NUMBER_OF_PARTICLE_VERB_MODE> addParticleVerbMode(const str32 mi, const str32 you, const str32 syu, const str32 tai = U"", const str32 ka = U"", const str32 me = U"", const str32 mei2 = U"", const str32 mi2 = U"", const str32 you2 = U"", const str32 you3 = U"") {
		array<str32, NUMBER_OF_PARTICLE_VERB_MODE> add_mode_str = {};

		add_mode_str[PARTICLE_VERB_MODE_MIZEN] = mi;
		add_mode_str[PARTICLE_VERB_MODE_RENYOU] = you;
		add_mode_str[PARTICLE_VERB_MODE_SYUUSHI] = syu;
		add_mode_str[PARTICLE_VERB_MODE_RENTAI] = tai;
		add_mode_str[PARTICLE_VERB_MODE_KATEI] = ka;
		add_mode_str[PARTICLE_VERB_MODE_MEIREI] = me;
		add_mode_str[PARTICLE_VERB_MODE_MIZEN2] = mi2;
		add_mode_str[PARTICLE_VERB_MODE_RENYOU2] = you2;
		add_mode_str[PARTICLE_VERB_MODE_RENYOU3] = you3;
		add_mode_str[PARTICLE_VERB_MODE_MEIREI2] = mei2;
		return add_mode_str;
	}

	void addParticleVerb(array<ParticleVerb, NUMBER_OF_PARTICLE_VERB>& particle_verb)
	{
		particle_verb[PARTICLE_VERB_GROUP_SERU].addStr(addParticleVerbMode(U"せ", U"せ", U"せる", U"せる", U"せれ", U"せろ", U"せよ"));
		particle_verb[PARTICLE_VERB_GROUP_SASERU].addStr(addParticleVerbMode(U"させ", U"させ", U"させる", U"させる", U"させれ", U"させろ", U"させよ"));
		particle_verb[PARTICLE_VERB_GROUP_RERU].addStr(addParticleVerbMode(U"れ", U"れ", U"れる", U"れる", U"れれ", U"れろ", U"れよ"));
		particle_verb[PARTICLE_VERB_GROUP_RARERU].addStr(addParticleVerbMode(U"られ", U"られ", U"られる", U"られる", U"られれ", U"られろ", U"られよ"));
		particle_verb[PARTICLE_VERB_GROUP_NAI].addStr(addParticleVerbMode(U"なかろ", U"なかっ", U"ない", U"ない", U"なけれ", U"", U"", U"", U"なく"));
		particle_verb[PARTICLE_VERB_GROUP_NU].addStr(addParticleVerbMode(U"", U"ず", U"ぬ", U"ぬ", U"ね"));
		particle_verb[PARTICLE_VERB_GROUP_NN].addStr(addParticleVerbMode(U"", U"ず", U"ん", U"ん", U"ね"));
		particle_verb[PARTICLE_VERB_GROUP_U].addStr(addParticleVerbMode(U"", U"", U"う", U"う"));
		particle_verb[PARTICLE_VERB_GROUP_YOU].addStr(addParticleVerbMode(U"", U"", U"よう", U"よう"));
		particle_verb[PARTICLE_VERB_GROUP_MAI].addStr(addParticleVerbMode(U"", U"", U"まい", U"まい"));
		particle_verb[PARTICLE_VERB_GROUP_TAI].addStr(addParticleVerbMode(U"たかろ", U"たかっ", U"たい", U"たい", U"たけれ", U"", U"", U"", U"たく"));
		particle_verb[PARTICLE_VERB_GROUP_TAGARU].addStr(addParticleVerbMode(U"たがら", U"たがり", U"たがる", U"たがる", U"たがれ", U"", U"", U"", U"たがっ"));
		particle_verb[PARTICLE_VERB_GROUP_TA].addStr(addParticleVerbMode(U"たろ", U"", U"た", U"た", U"たら"));
		particle_verb[PARTICLE_VERB_GROUP_DA].addStr(addParticleVerbMode(U"だろ", U"", U"だ", U"だ", U"だら"));
		particle_verb[PARTICLE_VERB_GROUP_SOUDA].addStr(addParticleVerbMode(U"そうだろ", U"そうだっ", U"そうだ", U"そうな", U"そうなら", U"", U"", U"", U"そうで", U"そうに"));
		particle_verb[PARTICLE_VERB_GROUP_SOUDA2].addStr(addParticleVerbMode(U"", U"そうで", U"そうだ"));
		particle_verb[PARTICLE_VERB_GROUP_YOUDA].addStr(addParticleVerbMode(U"ようだろ", U"ようだっ", U"ようだ", U"ような", U"ようなら", U"", U"", U"", U"ようで", U"ように"));
		particle_verb[PARTICLE_VERB_GROUP_RASHII].addStr(addParticleVerbMode(U"", U"らしかっ", U"らしい", U"らしい", U"らしけれ", U"", U"", U"", U"らしく"));
		particle_verb[PARTICLE_VERB_GROUP_MASU].addStr(addParticleVerbMode(U"ませ", U"まし", U"ます", U"ます", U"ますれ", U"ませ", U"まし", U"ましょ"));
		particle_verb[PARTICLE_VERB_GROUP_DA2].addStr(addParticleVerbMode(U"だろ", U"だっ", U"だ", U"な", U"なら", U"", U"", U"", U"で"));
		particle_verb[PARTICLE_VERB_GROUP_DESU].addStr(addParticleVerbMode(U"でしょ", U"でし", U"です", U"です"));

		for (size_t i = 0; i < NUMBER_OF_PARTICLE_VERB; i++) {
			particle_verb[i].allMode();
		}
		return;
	}

	inline str32 ParticleVerb::allModeStr()
	{
		return all_mode_str;
	}

	inline void ParticleVerb::allMode()
	{
		for (size_t i = 0; i < NUMBER_OF_PARTICLE_VERB_MODE; i++) {
			all_mode_str += mode_str[i];
			if (mode_str[i] == U"") all_mode_str += U'○';
			all_mode_str += U" ";
		}
		return;
	}

}