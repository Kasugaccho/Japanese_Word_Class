#include "word_class.hpp"
using namespace gaccho;

int main()
{
	vector<Verb> verb;

	addVerb(verb, U"働", VERB_GROUP_U, VERB_KU);
	addVerb(verb, U"休", VERB_GROUP_U, VERB_MU);
	addVerb(verb, U"食べ", VERB_GROUP_RU);
	addVerb(verb, U"寝", VERB_GROUP_RU);
	addVerb(verb, U"起き", VERB_GROUP_RU);
	addVerb(verb, U"見", VERB_GROUP_RU);
	addVerb(verb, U"あげ", VERB_GROUP_RU);
	addVerb(verb, U"わか", VERB_GROUP_U, VERB_RU);
	addVerb(verb, U"ググ", VERB_GROUP_U, VERB_RU);
	addVerb(verb, U"マミ", VERB_GROUP_U, VERB_RU);
	addVerb(verb, U"ディス", VERB_GROUP_U, VERB_RU);
	addVerb(verb, U"", VERB_GROUP_SURU);
	addVerb(verb, U"", VERB_GROUP_KURU);
	addVerb(verb, U"", VERB_GROUP_KURU2);
	addVerb(verb, U"勉強", VERB_GROUP_SURU);
	addVerb(verb, U"切", VERB_GROUP_U, VERB_RU);
	addVerb(verb, U"愛", VERB_GROUP_SURU);
	addVerb(verb, U"愛", VERB_GROUP_U, VERB_SU);

	for (Verb i : verb) printf("%s\n", utf32ToShiftjis(i.allModeStr()).c_str());

	vector<Adjective> ad;
	addAdjective(ad, U"暑");
	addAdjective(ad, U"寒");
	for (Adjective i : ad) printf("%s\n", utf32ToShiftjis(i.allModeStr()).c_str());

	vector<AdjectiveVerb> adv;
	addAdjectiveVerb(adv, U"きれい");
	addAdjectiveVerb(adv, U"好き");
	addAdjectiveVerb(adv, U"そんな");
	addAdjectiveVerb(adv, U"同じ");
	for (AdjectiveVerb i : adv) printf("%s\n", utf32ToShiftjis(i.allModeStr()).c_str());

	array<ParticleVerb, NUMBER_OF_PARTICLE_VERB> particleVerb;
	addParticleVerb(particleVerb);
	for (ParticleVerb i : particleVerb) printf("%s\n", utf32ToShiftjis(i.allModeStr()).c_str());

	vector<Particle> pa;
	addParticle(pa, U"が", PARTICLE_TYPE_KAKU);
	addParticle(pa, U"を", PARTICLE_TYPE_KAKU);
	for (Particle i : pa) printf("%s\n", utf32ToShiftjis(i.show_name()).c_str());



	printf("\n");
	return 0;
}


