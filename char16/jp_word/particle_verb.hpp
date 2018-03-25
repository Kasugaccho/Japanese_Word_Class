//--------------------------------------------------
//
//                  �������N���X
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	//��������
	constexpr size_t NUMBER_OF_PARTICLE_VERB = 21;

	//������ �S���
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

	//������ ���p�`��
	constexpr size_t NUMBER_OF_PARTICLE_VERB_MODE = 10;

	//���p�`
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
		particle_verb[PARTICLE_VERB_GROUP_SERU].addStr(addParticleVerbMode(U"��", U"��", U"����", U"����", U"����", U"����", U"����"));
		particle_verb[PARTICLE_VERB_GROUP_SASERU].addStr(addParticleVerbMode(U"����", U"����", U"������", U"������", U"������", U"������", U"������"));
		particle_verb[PARTICLE_VERB_GROUP_RERU].addStr(addParticleVerbMode(U"��", U"��", U"���", U"���", U"���", U"���", U"���"));
		particle_verb[PARTICLE_VERB_GROUP_RARERU].addStr(addParticleVerbMode(U"���", U"���", U"����", U"����", U"����", U"����", U"����"));
		particle_verb[PARTICLE_VERB_GROUP_NAI].addStr(addParticleVerbMode(U"�Ȃ���", U"�Ȃ���", U"�Ȃ�", U"�Ȃ�", U"�Ȃ���", U"", U"", U"", U"�Ȃ�"));
		particle_verb[PARTICLE_VERB_GROUP_NU].addStr(addParticleVerbMode(U"", U"��", U"��", U"��", U"��"));
		particle_verb[PARTICLE_VERB_GROUP_NN].addStr(addParticleVerbMode(U"", U"��", U"��", U"��", U"��"));
		particle_verb[PARTICLE_VERB_GROUP_U].addStr(addParticleVerbMode(U"", U"", U"��", U"��"));
		particle_verb[PARTICLE_VERB_GROUP_YOU].addStr(addParticleVerbMode(U"", U"", U"�悤", U"�悤"));
		particle_verb[PARTICLE_VERB_GROUP_MAI].addStr(addParticleVerbMode(U"", U"", U"�܂�", U"�܂�"));
		particle_verb[PARTICLE_VERB_GROUP_TAI].addStr(addParticleVerbMode(U"������", U"������", U"����", U"����", U"������", U"", U"", U"", U"����"));
		particle_verb[PARTICLE_VERB_GROUP_TAGARU].addStr(addParticleVerbMode(U"������", U"������", U"������", U"������", U"������", U"", U"", U"", U"������"));
		particle_verb[PARTICLE_VERB_GROUP_TA].addStr(addParticleVerbMode(U"����", U"", U"��", U"��", U"����"));
		particle_verb[PARTICLE_VERB_GROUP_DA].addStr(addParticleVerbMode(U"����", U"", U"��", U"��", U"����"));
		particle_verb[PARTICLE_VERB_GROUP_SOUDA].addStr(addParticleVerbMode(U"��������", U"��������", U"������", U"������", U"�����Ȃ�", U"", U"", U"", U"������", U"������"));
		particle_verb[PARTICLE_VERB_GROUP_SOUDA2].addStr(addParticleVerbMode(U"", U"������", U"������"));
		particle_verb[PARTICLE_VERB_GROUP_YOUDA].addStr(addParticleVerbMode(U"�悤����", U"�悤����", U"�悤��", U"�悤��", U"�悤�Ȃ�", U"", U"", U"", U"�悤��", U"�悤��"));
		particle_verb[PARTICLE_VERB_GROUP_RASHII].addStr(addParticleVerbMode(U"", U"�炵����", U"�炵��", U"�炵��", U"�炵����", U"", U"", U"", U"�炵��"));
		particle_verb[PARTICLE_VERB_GROUP_MASU].addStr(addParticleVerbMode(U"�܂�", U"�܂�", U"�܂�", U"�܂�", U"�܂���", U"�܂�", U"�܂�", U"�܂���"));
		particle_verb[PARTICLE_VERB_GROUP_DA2].addStr(addParticleVerbMode(U"����", U"����", U"��", U"��", U"�Ȃ�", U"", U"", U"", U"��"));
		particle_verb[PARTICLE_VERB_GROUP_DESU].addStr(addParticleVerbMode(U"�ł���", U"�ł�", U"�ł�", U"�ł�"));

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
			if (mode_str[i] == U"") all_mode_str += U'��';
			all_mode_str += U" ";
		}
		return;
	}

}