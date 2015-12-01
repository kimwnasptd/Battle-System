#include "battle_engine_resource.h"
#include "ROM_tables.h"
#include "multipurpose_resources.c"
#include "./Defines/get_attr.h"
#include "types.h"
#include "./Defines/type_ids.h"
#include "./Defines/battle_types.h"

u8 get_ability_from_bit(struct pokemon *pokemon) {
	u8 ability = get_attr(pokemon, ABILITY_BIT);
	u16 species = get_attr(pokemon, SPECIES);
	if (ability) {
		return base_stats[species].ability2;
	} else {
		return base_stats[species].ability1;
	}
}

u8 get_weight(struct pokemon *pokemon) {
	u16 species = get_attr(pokemon, SPECIES);
	species = species_to_dex_index(species);
	return dex_data[species].weight;
}

void set_types(struct battle_field *battle_field, struct pokemon *pokemon, u8 id) {
	u16 species = get_attr(pokemon, SPECIES);
	battle_field->battlers[id].types[0] = base_stats[species].type1;
	battle_field->battlers[id].types[1] = base_stats[species].type2;
	battle_field->battlers[id].types[2] = TYPE_EGG;
	return;
}

void battler_init(struct battle_field *battle_field, struct pokemon *pokemon, u8 bank, u8 id) {
		battle_field->battlers[id].species = get_attr(pokemon, SPECIES);
		battle_field->battlers[id].ability = get_ability_from_bit(pokemon);
		battle_field->battlers[id].weight = get_weight(pokemon);
		battle_field->battlers[id].level = get_attr(pokemon, LEVEL);
		set_types(battle_field, pokemon, id);
		battle_field->battlers[id].item = get_attr(pokemon, HELD_ITEM);
		battle_field->battlers[id].current_hp = pokemon->current_hp;
		battle_field->battlers[id].total_hp = pokemon->total_hp;
		battle_field->battlers[id].attack = pokemon->attack;
		battle_field->battlers[id].defense = pokemon->defense;
		battle_field->battlers[id].speed = pokemon->speed;
		battle_field->battlers[id].ailment = pokemon->ailment;
		battle_field->battlers[id].pokemon_bank_id = bank;
	return;
}


void battle_init(struct battle_config *b_config) {
	void c2_exit_to_overworld_1_continue_scripts_and_music(void);
	
	// malloc resources and set up
	struct battle_field *battle_field = (struct battle_field*) malloc(sizeof(struct battle_field));
	battle_field->b_config = b_config;
	battle_field->battle_type = b_config->type;
	
	// set up battlers by battle type
	switch (battle_field->battle_type) {
		case SINGLE_WILD:
		case SINGLE_TRAINER:
			battle_field->active_battler_count_max = 2;
			battler_init(battle_field, &pokemon_bank[6], 6, 0); // player's first pkmn
			battler_init(battle_field, &pokemon_bank[0], 0, 3); // opponent's first pkmn
			break;
		case DOUBLE_WILD:
		case DOUBLE_TRAINER:
			battle_field->active_battler_count_max = 4;
			battler_init(battle_field, &pokemon_bank[6], 6, 0); // player's 1st pkmn
			battler_init(battle_field, &pokemon_bank[7], 7, 1); // player's 2nd pkmn
			battler_init(battle_field, &pokemon_bank[0], 0, 3); // opponent's 1st pkmn
			battler_init(battle_field, &pokemon_bank[1], 1, 4); // opponent's 2nd pkmn
			break;
		case DOUBLE_TWO_AI:
			battle_field->active_battler_count_max = 4;
			battler_init(battle_field, &pokemon_bank[6], 6, 0); // player's 1st pkmn
			battler_init(battle_field, &pokemon_bank[9], 9, 1); // ally's 1st pkmn
			battler_init(battle_field, &pokemon_bank[0], 0, 3); // opponent1's 1st pkmn
			battler_init(battle_field, &pokemon_bank[3], 3, 4); // opponent2's 2nd pkmn
			break;
		case TRIPLE_WILD:
		case TRIPLE_TRAINER:
			battle_field->active_battler_count_max = 6;
			battler_init(battle_field, &pokemon_bank[6], 6, 0); // player's 1st pkmn
			battler_init(battle_field, &pokemon_bank[7], 7, 1); // player's 2nd pkmn
			battler_init(battle_field, &pokemon_bank[8], 8, 2); // player's 3rd pkmn
			battler_init(battle_field, &pokemon_bank[0], 0, 3); // opponent's 1st pkmn
			battler_init(battle_field, &pokemon_bank[1], 1, 4); // opponent's 1st pkmn
			battler_init(battle_field, &pokemon_bank[2], 2, 5); // opponent's 2nd pkmn
			break;
		case TRIPLE_FOUR_AI: // low priority
		case TRIPLE_FIVE_AI: // low priority
			break;
		case HORDE_WILD:
		case HORDE_TRAINER:
			battle_field->active_battler_count_max = 6;
			battler_init(battle_field, &pokemon_bank[6], 6, 1); // player's 1st pkmn
			battler_init(battle_field, &pokemon_bank[0], 0, 0); // opponent's 1st pkmn
			battler_init(battle_field, &pokemon_bank[1], 1, 2); // opponent's 2nd pkmn
			battler_init(battle_field, &pokemon_bank[2], 2, 3); // opponent's 3rd pkmn
			battler_init(battle_field, &pokemon_bank[1], 1, 4); // opponent's 4th pkmn
			battler_init(battle_field, &pokemon_bank[2], 2, 5); // opponent's 5th pkmn
			break;
		default:
			free(battle_field);
			// call back, return to overworld -> safe exit
			c2_exit_to_overworld_1_continue_scripts_and_music();
			break;		
	};
	return;
}

























