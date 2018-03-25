//--------------------------------------------------
//
//                   ïiéåÉNÉâÉX
//
//--------------------------------------------------
#pragma once
#include "default.hpp"
#include "verb.hpp"
#include "adjective.hpp"
#include "adjective_verb.hpp"
#include "particle_verb.hpp"
#include "particle.hpp"
#include "utf8.hpp"

namespace gaccho {

	struct StackStr {
		u8 word_class_id;
		size_t word_id;

		size_t select_word_len = 0;

		u32 hit = 1000;
	};

	class WorldClassClass
	{
	private:
		str32 str = U"";
		str32 search_str = U"";

		u32 str_len_max = 0;

		list<StackStr> stackStr;

		vector<Verb> verb;
		vector<Adjective> adjective;
		vector<AdjectiveVerb> adjective_verb;
		array<ParticleVerb, NUMBER_OF_PARTICLE_VERB> particleVerb;
		vector<Particle> particle;

	public:
		WorldClassClass(str32& add_str);
		void addVerb(const str32& add_prototype, const u8 add_group, const u8 add_end = VERB_RU);
		void addParticle(const str32& add_prototype, const size_t add_type);

		void searchStr();
	};

	inline void WorldClassClass::searchStr()
	{
		//ç≈ëÂï∂éöêîÇéÊìæ
		for (Verb j : verb) 
			for (u8 k = 0; k < NUMBER_OF_VERB_MODE; k++) 
				if (j.modeStr(k).length() > str_len_max) str_len_max = j.modeStr(k).length();

		for (Adjective j : adjective) 
			for (u8 k = 0; k < NUMBER_OF_ADJECTIVE_MODE; k++) 
				if (j.modeStr(k).length() > str_len_max) str_len_max = j.modeStr(k).length();

		for (AdjectiveVerb j : adjective_verb) 
			for (u8 k = 0; k < NUMBER_OF_ADJECTIVE_VERB_MODE; k++) 
				if (j.modeStr(k).length() > str_len_max) str_len_max = j.modeStr(k).length();




		size_t str_len = str.size();
		c32 str_c = 0;



		for (size_t i = 0; i < str_len; i++) {
			if (str[i] == 0) break;
			str_c = str[i];

			for (StackStr j : stackStr) {

			}



			for (Verb j : verb) {
				for (u8 k = 0; k < NUMBER_OF_VERB_MODE;k++) {
					if (j.mode(k)[0] == str_c) k;
				}
			}
		}

		return;
	}

	inline void WorldClassClass::addVerb(const str32& add_prototype, const u8 add_group, const u8 add_end)
	{
		Verb add_verb(add_prototype, add_group, add_end);
		verb.emplace_back(add_verb);
		return;
	}

	inline void WorldClassClass::addParticle(const str32& add_prototype, const size_t add_type)
	{
		Particle add_particle(add_prototype, add_type);
		particle.emplace_back(add_particle);
		return;
	}

	inline WorldClassClass::WorldClassClass(str32& add_str)
	{
		str = add_str;
		addParticleVerb(particleVerb);
	}

}