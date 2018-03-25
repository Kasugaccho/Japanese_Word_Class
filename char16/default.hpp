#pragma once
#include <cstdio>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <cstdint>
//#include <string_view>

namespace gaccho {

	//std省略
	using std::vector;
	using std::array;
	using std::list;
	using std::string;
	using std::size_t;
	//using std::u32string_view;

	//文字列
	using str8 = std::string;
	using str16 = std::u16string;
	using str32 = std::u32string;
	using str8_sjis = std::string;

	//文字
	using c8 = char;
	using cXX = wchar_t;
	using c16 = char16_t;
	using c32 = char32_t;
	using c8_sjis = char;
	
	//数値
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using f32 = float;
	using f64 = double;

	//母音数
	constexpr size_t NUMBER_OF_VOWEL = 5;

	//あいうえお表
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_A = { U'あ', U'い', U'う', U'え', U'お' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_KA = { U'か', U'き', U'く', U'け', U'こ' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_SA = { U'さ', U'し', U'す', U'せ', U'そ' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_TA = { U'た', U'ち', U'つ', U'て', U'と' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_NA = { U'な', U'に', U'ぬ', U'ね', U'の' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_HA = { U'は', U'ひ', U'ふ', U'へ', U'ほ' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_MA = { U'ま', U'み', U'む', U'め', U'も' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_YA = { U'や', U'い', U'ゆ', U'え', U'よ' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_RA = { U'ら', U'り', U'る', U'れ', U'ろ' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_WA = { U'わ', U'い', U'う', U'え', U'お' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_GA = { U'が', U'ぎ', U'ぐ', U'げ', U'ご' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_ZA = { U'ざ', U'じ', U'ず', U'ぜ', U'ぞ' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_DA = { U'だ', U'ぢ', U'づ', U'で', U'ど' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_BA = { U'ば', U'び', U'ぶ', U'べ', U'ぼ' };
	constexpr array<c32, NUMBER_OF_VOWEL>WORD_CLASS_STR_PA = { U'ぱ', U'ぴ', U'ぷ', U'ぺ', U'ぽ' };

	//母音ID
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
	{ U"動詞",U"形容詞",U"形容動詞",U"名詞",U"副詞",U"連体詞",U"接続詞",U"感動詞",U"助動詞",U"助詞",U"国名",U"地名",U"人名",U"苗字",U"名前" };

	constexpr size_t NUMBER_OF_WORD_CLASS_MODE = 6;
	constexpr size_t WORD_CLASS_MODE_LEN = 4;
	constexpr array<array<c32, WORD_CLASS_MODE_LEN>, NUMBER_OF_WORD_CLASS_MODE>WORD_CLASS_MODE =
	{ U"未然形",U"連用形",U"終止形",U"連体形",U"仮定形",U"命令形" };

	//品詞ID
	enum WORD_CLASS_ID:size_t
	{
		//品詞--------------------------------------------------

		//動詞
		WORD_CLASS_ID_VERB,
		//形容詞
		WORD_CLASS_ID_ADJECTIVE,
		//形容動詞
		WORD_CLASS_ID_ADJECTIVE_VERB,
		//名詞
		WORD_CLASS_ID_NOUN,
		//副詞
		WORD_CLASS_ID_ADVERB,
		//連体詞
		WORD_CLASS_ID_PRENOUN,
		//接続詞
		WORD_CLASS_ID_CONJUNCTION,
		//感動詞
		WORD_CLASS_ID_INTERJECTION,
		//助動詞
		WORD_CLASS_ID_PARTICLE_VERB,
		//助詞
		WORD_CLASS_ID_PARTICLE,

		//固有名詞--------------------------------------------------

		//国名
		WORD_CLASS_ID_COUNTRY,
		//地名
		WORD_CLASS_ID_PLACE,
		//人名
		WORD_CLASS_ID_PERSON,
		//苗字
		WORD_CLASS_ID_LAST_NAME,
		//名前
		WORD_CLASS_ID_FARST_NAME,
	};
}