//--------------------------------------------------
//
//                   èïéåÉNÉâÉX
//
//--------------------------------------------------

#pragma once
#include "default.hpp"

namespace gaccho {

	enum PARTICLE_TYPE :size_t
	{
		PARTICLE_TYPE_KAKU,
		PARTICLE_TYPE_SETSUZOKU,
		PARTICLE_TYPE_FUKU,
		PARTICLE_TYPE_SYUU
	};

	class Particle {
	private:
		str32 word_class_name = U"";
		size_t type;

	public:
		Particle(const str32& add_name, const size_t add_type);
		str32 show_name();
	};

	void addParticle(vector<Particle>& particle, const str32& add_prototype, const size_t add_type)
	{
		Particle add_particle(add_prototype, add_type);
		particle.emplace_back(add_particle);
		return;
	}

	inline Particle::Particle(const str32& add_name, const size_t add_type) {
		word_class_name = add_name;
		type = add_type;
	}

	inline str32 Particle::show_name() {
		return word_class_name;
	}

}