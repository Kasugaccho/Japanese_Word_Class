#pragma once
#include <cstdio>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <cstdint>
//#include <string_view>

namespace gaccho {

	//std�ȗ�
	using std::vector;
	using std::array;
	using std::list;
	using std::string;
	using std::size_t;
	//using std::u32string_view;

	//������
	using str8 = std::string;
	using str16 = std::u16string;
	using str32 = std::u32string;
	using str8_sjis = std::string;

	//����
	using c8 = char;
	using cXX = wchar_t;
	using c16 = char16_t;
	using c32 = char32_t;
	using c8_sjis = char;
	
	//���l
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using f32 = float;
	using f64 = double;

	//�ꉹ��
	constexpr size_t NUMBER_OF_VOWEL = 5;

	//�����������\
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_A = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_KA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_SA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_TA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_NA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_HA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_MA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_YA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_RA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_WA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_GA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_ZA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_DA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_BA = { U'��', U'��', U'��', U'��', U'��' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_PA = { U'��', U'��', U'��', U'��', U'��' };

	//�ꉹID
	enum WORD_CLASS_STR :size_t 
	{
		WORD_CLASS_STR_ID_A,
		WORD_CLASS_STR_ID_I,
		WORD_CLASS_STR_ID_U,
		WORD_CLASS_STR_ID_E,
		WORD_CLASS_STR_ID_O
	};

	constexpr size_t NUMBER_OF_WORD_CLASS_ID = 15;
	constexpr size_t WORD_CLASS_NAME_LEN = 5;
	constexpr array<array<c32, WORD_CLASS_NAME_LEN>, NUMBER_OF_WORD_CLASS_ID>WORD_CLASS_NAME = 
	{ U"����",U"�`�e��",U"�`�e����",U"����",U"����",U"�A�̎�",U"�ڑ���",U"������",U"������",U"����",U"����",U"�n��",U"�l��",U"�c��",U"���O" };

	constexpr size_t NUMBER_OF_WORD_CLASS_MODE = 6;
	constexpr size_t WORD_CLASS_MODE_LEN = 4;
	constexpr array<array<c32, WORD_CLASS_MODE_LEN>, NUMBER_OF_WORD_CLASS_MODE>WORD_CLASS_MODE =
	{ U"���R�`",U"�A�p�`",U"�I�~�`",U"�A�̌`",U"����`",U"���ߌ`" };

	//�i��ID
	enum WORD_CLASS_ID:size_t
	{
		//�i��--------------------------------------------------

		//����
		WORD_CLASS_ID_VERB,
		//�`�e��
		WORD_CLASS_ID_ADJECTIVE,
		//�`�e����
		WORD_CLASS_ID_ADJECTIVE_VERB,
		//����
		WORD_CLASS_ID_NOUN,
		//����
		WORD_CLASS_ID_ADVERB,
		//�A�̎�
		WORD_CLASS_ID_PRENOUN,
		//�ڑ���
		WORD_CLASS_ID_CONJUNCTION,
		//������
		WORD_CLASS_ID_INTERJECTION,
		//������
		WORD_CLASS_ID_PARTICLE_VERB,
		//����
		WORD_CLASS_ID_PARTICLE,

		//�ŗL����--------------------------------------------------

		//����
		WORD_CLASS_ID_COUNTRY,
		//�n��
		WORD_CLASS_ID_PLACE,
		//�l��
		WORD_CLASS_ID_PERSON,
		//�c��
		WORD_CLASS_ID_LAST_NAME,
		//���O
		WORD_CLASS_ID_FARST_NAME,
	};
}