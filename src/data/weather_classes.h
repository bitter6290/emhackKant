#include "constants/weather_class.h"

const struct WeatherClass gWeatherClasses[] =
{
	[WEATHER_NONE] = {
		.rainSnowChance = 255,
		.sandSunChance = 0,
		.sunChance = 0,
		.snowChance = 0,
	},
	[WEATHER_TEMPERATE] = {
		.rainSnowChance = 204,
		.sandSunChance = 37,
		.sunChance = 255,
		.snowChance = 193,
	},
};