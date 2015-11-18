#ifndef BATTLE_LOCAL_RESOURCES
#define BATTLE_LOCAL_RESOURCES

/* Battle setup structs */

struct battle_config {
	u8 type;
	u8 purge_switch;
	u32 *callback_return;
	u8 whiteout_switch;
	u8 money_switch;
	u8 exp_switch;
	u8 tut_mode;
	u8 ai_difficulty;
	u8 env_by_map;
	u8 frontier_mode;
	u8 opponent_count;
	u8 player_control_ally_count;
	u8 ai_control_ally_count;
	u8 ally_backsprites[3];
};

struct battler {
	u8 types[3]; // 3 types, yay gen 6!
	u8 ability[2];
	u16 item;
	u16 moves_used[4];
	u16 move_used_last;
	
	u8 toxic; // turns count
	u8 leech_seed; //pokemon in which slot gets the HP
	u8 disable; // turns remaining
	u8 taunt; // turns remaining
	u8 torment; // turns remaining
	u8 encore; // turns remaining
	
	u8 furry_cutter; // times used
	u8 rollout_iceball; // times used
	
	u8 trap; // duration + dmg
	u16 trap_dmg;
	
	u16 attack_multiplier : 2;
	u16 defence_multiplier : 2;
	u16 special_attack_multiplier : 2;
	u16 special_defence_multiplier : 2;
	u16 speed_multiplier : 2;
	u16 evasion_multiplier : 2;
	u16 accuracy_multiplier : 2;
	u16 pokerus_maybe_someday : 2;
	
	// statuses and things the user can be under
	u16 substitute : 1;
	u16 perish_song : 1;
	u16 electrify : 1;
	u16 bounce : 1;
	u16 dig : 1;
	u16 dive : 1;
	u16 fly : 1;
	u16 phantom_force : 1;
	u16 shadow_force : 1;
	u16 sky_drop : 1;
	u16 lock_on_mind_reader : 1;
	u16 wide_gaurd : 1;
	u16 protect : 1;
	u16 influation : 1;
	u16 floored : 1; // gravity, magnet rise, ect.

};

struct field_modifiers {
	// holds layers count/activated count per side
	u8 spikes[2];
	u8 toxic_spikes[2];
	u8 stealth_rocks[2];
	u8 sticky_web[2];
	u8 fairy_lock[2];
	u8 magnetic_flux;
	
	
	// turns count or team-wide status inducers
	u8 trick_room;
	u8 ion_deluge;
	u8 wide_gaurd[2];
	
	// type and durations
	u8 weather[2];
	
	/* 
	these arrays are of style:
	
	tailwind[0] = 1 if player's side has wind
	tailwind[1] = Duration counter for tailwind player
	tailwind[2] = 1 if opponent's side has wind
	tailwind[3] = Duration counter for tailwind	opponent
	*/	
	u8 tailwind[4]; 
	u8 reflect[4];
	u8 lightscreen[4];
	u8 safeguard[4];
	u8 terrain[4];
	u8 pledge[4];
	u8 wish[12];
	
	/* 
	move[0] = 1 if pokemon at slot was choosen as target to recieve
	move[1] = duration till attack	
	*/
	u8 future_sight[24];
	u8 doomdesire[24];
};

struct battle_field {
	u8 turn_counter;
	struct field_modifiers modifiers;
	struct battler battlers[12]; // potential for 12 on field at once
};


#endif /* BATTLE_LOCAL_RESOURCES */