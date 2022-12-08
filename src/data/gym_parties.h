#define GYMPARTIES(leader)								\
		.parties = {									\
		[0] = {.ItemCustomMoves = sParty_##leader##1},		\
		[1] = {.ItemCustomMoves = sParty_##leader##2},		\
		[2] = {.ItemCustomMoves = sParty_##leader##3},		\
		[3] = {.ItemCustomMoves = sParty_##leader##4}			\
		},



const struct GymLeaderParties gGymParties[NUM_GYM_LEADERS]=
{
	[GYM_LEADER_BROCK] =
	{
		GYMPARTIES(Brock)
	},
	[GYM_LEADER_YVONNE] =
	{
		GYMPARTIES(Yvonne)
	},
	[GYM_LEADER_WATTSON] =
	{
		GYMPARTIES(WattsonNew)
	},
	[GYM_LEADER_LEO] =
	{
		GYMPARTIES(Leo)
	},
	[GYM_LEADER_MISTY] =
	{
		GYMPARTIES(Misty)
	},
	[GYM_LEADER_ERICA] =
	{
		GYMPARTIES(Erica)
	},
	[GYM_LEADER_VALERIA] =
	{
		GYMPARTIES(Valeria)
	},
};