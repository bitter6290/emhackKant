#include "constants/spreads.h"

const struct TrainerEVSpread gEvSets[] = {
	[SPREAD_40_EV] =
	{
	.EVs = {40},
	.nature = NATURE_HARDY
	},
	[SPREAD_0_EV] =
	{
	.EVs = {0},
	.nature = NATURE_HARDY
	},
	[SPREAD_20_EV] =
	{
	.EVs = {20},
	.nature = NATURE_HARDY
	},
	[SPREAD_60_EV] =
	{
	.EVs = {60},
	.nature = NATURE_HARDY
	},
	[SPREAD_80_EV] =
	{
	.EVs = {80},
	.nature = NATURE_HARDY
	},
	[SPREAD_FAST_PHYSICAL_SWEEPER_A] =
	{
	.EVs = 
	{
		0,
		252,
		0,
		252,
		0,
		4
	},
	.nature = NATURE_ADAMANT
	},
	[SPREAD_FAST_PHYSICAL_SWEEPER_S] =
	{
	.EVs = 
	{
		0,
		252,
		0,
		252,
		0,
		4
	},
	.nature = NATURE_JOLLY
	},
	[SPREAD_FAST_SPECIAL_SWEEPER_A] =
	{
	.EVs = 
	{
		0,
		0,
		0,
		252,
		252,
		4
	},
	.nature = NATURE_MODEST
	},
	[SPREAD_FAST_SPECIAL_SWEEPER_S] =
	{
	.EVs = 
	{
		0,
		0,
		0,
		252,
		252,
		4
	},
	.nature = NATURE_TIMID
	},
	[SPREAD_BULKY_PHYSICAL_SWEEPER] =
	{
	.EVs = 
	{
		252,
		252,
		0,
		0,
		0,
		4
	},
	.nature = NATURE_ADAMANT
	},
	[SPREAD_BULKY_SPECIAL_SWEEPER] =
	{
	.EVs = 
	{
		252,
		0,
		0,
		0,
		252,
		4
	},
	.nature = NATURE_MODEST
	},
	[SPREAD_PHYSICALLY_DEFENSIVE_PH] =
	{
	.EVs = 
	{
		252,
		0,
		252,
		0,
		0,
		4
	},
	.nature = NATURE_IMPISH
	},
	[SPREAD_PHYSICALLY_DEFENSIVE_SP] =
	{
	.EVs = 
	{
		252,
		0,
		252,
		0,
		0,
		4
	},
	.nature = NATURE_BOLD
	},
	[SPREAD_SPECIALLY_DEFENSIVE_PH] =
	{
	.EVs = 
	{
		252,
		0,
		4,
		0,
		0,
		252
	},
	.nature = NATURE_CAREFUL
	},
	[SPREAD_SPECIALLY_DEFENSIVE_SP] =
	{
	.EVs = 
	{
		252,
		0,
		4,
		0,
		0,
		252
	},
	.nature = NATURE_CALM
	},
	[SPREAD_BULKY_UTILITY_SP] =
	{
	.EVs = 
	{
		252,
		0,
		0,
		252,
		4,
		0
	},
	.nature = NATURE_TIMID
	},
	[SPREAD_BULKY_UTILITY_PH] =
	{
	.EVs = 
	{
		252,
		4,
		0,
		252,
		0,
		0
	},
	.nature = NATURE_JOLLY
	},
	[SPREAD_SLOW_PHYSDEF] =
	{
	.EVs = 
	{
		252,
		0,
		252,
		0,
		0,
		4
	},
	.nature = NATURE_RELAXED
	},
	[SPREAD_SLOW_SPDEF] =
	{
	.EVs = 
	{
		252,
		0,
		4,
		0,
		0,
		252
	},
	.nature = NATURE_SASSY
	},
	[SPREAD_SLOW_ATTACK] =
	{
	.EVs = 
	{
		252,
		252,
		0,
		0,
		0,
		4
	},
	.nature = NATURE_BRAVE
	},
	[SPREAD_SLOW_SPATK] =
	{
	.EVs = 
	{
		252,
		0,
		0,
		0,
		252,
		4
	},
	.nature = NATURE_QUIET
	},
	[SPREAD_FAST_MIXED_SWEEPER] =
	{
	.EVs = 
	{
		0,
		168,
		0,
		168,
		168,
		0
	},
	.nature = NATURE_LONELY
	},
	[SPREAD_MIXED_PH_SLOW_LONELY] =
	{
	.EVs =
	{
		252,
		252,
		0,
		0,
		4,
		0
	},
	.nature = NATURE_LONELY
	},
	[SPREAD_MIXED_PH_FAST_HASTY] =
	{
	.EVs =
	{
		0,
		252,
		0,
		252,
		4,
		0
	},
	.nature = NATURE_HASTY
	},
	[SPREAD_SPDEF_4SPA] =
	{
	.EVs =
	{
		252,
		0,
		0,
		0,
		4,
		252
	},
	.nature = NATURE_CALM
	},
	[SPREAD_PHYSDEF_4SPA] =
	{
	.EVs =
	{
		252,
		0,
		252,
		0,
		4,
		0
	},
	.nature = NATURE_BOLD
	},
	[SPREAD_ATK_SPD_CAREFUL] =
	{
	.EVs =
	{
		0,
		252,
		0,
		4,
		0,
		252
	},
	.nature = NATURE_CAREFUL
	},
	[SPREAD_ATK_SPD_ADAMANT] =
	{
	.EVs =
	{
		0,
		252,
		0,
		4,
		0,
		252
	},
	.nature = NATURE_ADAMANT
	},
	[SPREAD_BOTH_DEF_4SPA] =
	{
	.EVs =
	{
		0,
		0,
		252,
		0,
		4,
		252
	},
	.nature = NATURE_BOLD
	}
};
const u8 gIvSets[][6] = {
	[SPREAD_16_IV] = {16},
	[SPREAD_0_IV] = {0},
	[SPREAD_8_IV] = {8},
	[SPREAD_24_IV] = {24},
	[SPREAD_31_IV] = {31},
	[SPREAD_SLOW] =
	{
		31,
		31,
		31,
		0,
		31,
		31
	},
	[SPREAD_SLOW_LA] =
	{
		31,
		0,
		31,
		0,
		31,
		31
	},
	[SPREAD_LOW_ATTACK] = 
	{
		31,
		0,
		31,
		31,
		31,
		31
	},
	[SPREAD_HP_GRASS] =
	{
		31,
		30,
		31,
		31,
		30,
		31
	},
	[SPREAD_HP_GRASS_LA] =
	{
		31,
		0,
		31,
		31,
		30,
		31
	},
	[SPREAD_HP_FLYING] =
	{
		30,
		30,
		30,
		31,
		30,
		30
	},
	[SPREAD_HP_FLYING_LA] =
	{
		30,
		0,
		30,
		31,
		30,
		30
	},
	[SPREAD_HP_FIRE] =
	{
		31,
		30,
		31,
		30,
		30,
		31
	},
	[SPREAD_HP_FIRE_LA] =
	{
		31,
		0,
		31,
		30,
		30,
		31
	},
	[SPREAD_HP_ICE] =
	{
		31,
		30,
		30,
		31,
		31,
		31
	},
	[SPREAD_HP_ICE_LA] =
	{
		31,
		0,
		30,
		31,
		31,
		31
	},
	[SPREAD_HP_BUG] =
	{
		31,
		30,
		30,
		31,
		31,
		30
	},
	[SPREAD_HP_BUG_LA] =
	{
		31,
		0,
		30,
		31,
		31,
		30
	},
	[SPREAD_HP_STEEL] =
	{
		31,
		31,
		31,
		31,
		31,
		30
	},
	[SPREAD_HP_STEEL_LA] =
	{
		31,
		1,
		31,
		31,
		31,
		30
	},
	[SPREAD_HP_GROUND] =
	{
		31,
		31,
		31,
		31,
		30,
		30
	},
	[SPREAD_HP_GROUND_LA] =
	{
		31,
		0,
		31,
		31,
		30,
		30
	},
	[SPREAD_HP_ROCK] =
	{
		31,
		31,
		30,
		30,
		31,
		30
	},
	[SPREAD_HP_ROCK_LA] =
	{
		31,
		1,
		30,
		30,
		31,
		30
	},
	[SPREAD_HP_WATER] =
	{
		31,
		30,
		30,
		31,
		30,
		31
	},
	[SPREAD_HP_WATER_LA] =
	{
		31,
		0,
		30,
		31,
		30,
		31
	},
};