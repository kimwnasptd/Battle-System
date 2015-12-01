#ifndef ROM_TABLES_H
#define ROM_TABLES_H

#include "types.h"

#define type_total 19
#define move_total 621
#define berries_table_size 67

/* most sizes are obviously inaccurate. To adjust once tables are generated */
#define natural_gift_table_size 50
#define fling_table_size 50
#define sheer_force_table_size 50
#define mega_items_table_size 50
#define iron_fist_table_size 50
#define reckless_table_size 50
#define mega_table_size 20
#define species_count 721

struct dex_entry_data {
	u8 name[12];
	u16 height;
	u16 weight;
	u32 description_ptr_1;
	u32 description_ptr_2;
	u16 pkmn_scale;
	u16 pkmn_offset;
	u16 trainer_scale;
	u16 trainer_offset;
};

struct base_stat_entry {
	u8 hp;
	u8 attack;
	u8 defense;
	u8 speed;
	u8 sp_attack;
	u8 sp_def;
	u8 type1;
	u8 type2;
	u8 catch_rate;
	u8 exp_yield;
	u16 effort_yield;
	u16 item_1;
	u16 item_2;
	u8 gender_chance;
	u8 step_to_hatch;
	u8 base_friendship;
	u8 exp_point_table_nr;
	u8 egg_group1;
	u8 egg_group2;
	u8 ability1;
	u8 ability2;
	u8 safari_flee_rate;
	u8 color;
	u16 padding;
};



struct move_table {
	u8 script_id;
	u8 base_power;
	u8 type;
	u8 accuracy;
	u8 PP;
	u8 effect_accuracy;
	u8 affected_targets;
	u8 priority;
	u8 contact : 1;
	u8 protect : 1;
	u8 magic_coat : 1;
	u8 snatch : 1;
	u8 mirror_move : 1;
	u8 kings_2,k : 1;
	u8 crit_chance : 1;
	u8 padding_field : 1;
	u8 is_special;
	u16 move_id;
};

struct natural_gift_table {
	u16 item_id;
};

struct fling_table {
	u16 move_id;
	u8 base_power;
};

struct sheer_force_table {
	u16 move_id;
};

struct mega_items_table {
	u16 item_id;
};

struct berries_table {
	u16 item_id;
};

/* low priority tables: */
struct iron_fist_table {
	u16 move_id;
};

struct reckless_table {
	u16 move_id;
};

struct mold_breaker_table {
	u8 ability_id;
};

struct types {
	u8 something;
};

struct mega_table {
	u16 species;
	u16 item;
};

/* 
0 = immune
1 = 1/2
2 = 1
3 = 2	


u8 type_chart = [2, 2, 2, 2, 2, 1, 2, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1, 1, 2, 3, 1, 0, 3, 2, 2, 2, 2, 2, 1, 3, 2, 3, 1, 2, 3, 2, 2, 2, 1, 3, 2, 1, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1, 0, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 0, 3, 2, 3, 1, 2, 3, 2, 2, 2, 1, 3, 2, 2, 2, 2, 2, 2, 1, 3, 2, 1, 2, 3, 2, 1, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 1, 2, 1, 2, 3, 2, 3, 2, 2, 3, 1, 0, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 2, 2, 2, 2, 2, 2, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 2, 3, 2, 1, 1, 3, 2, 2, 3, 1, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 3, 1, 1, 2, 2, 2, 1, 2, 2, 2, 2, 1, 1, 3, 3, 1, 2, 1, 2, 1, 3, 1, 2, 2, 2, 1, 2, 2, 2, 2, 3, 2, 0, 2, 2, 2, 2, 2, 2, 3, 1, 1, 2, 2, 1, 2, 2, 2, 3, 2, 3, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 0, 2, 2, 2, 3, 2, 3, 2, 2, 2, 1, 2, 1, 1, 3, 2, 2, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 0, 2, 1, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 1, 2, 3, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 2];
*/


u16 species_to_dex_index(u16);
extern struct move_table move[move_total];
extern struct natural_gift_table natural_gift_t[natural_gift_table_size];
extern struct fling_table fling_t[fling_table_size];
extern struct sheer_force_table sheer_force_t[sheer_force_table_size];
extern struct mega_items_table mega_items_t[mega_items_table_size];
extern struct iron_fist_table iron_fist_t[iron_fist_table_size];
extern struct reckless_table reckless_t[reckless_table_size];
extern struct types type_chart[19];
extern struct berries_table berries_t[berries_table_size];
extern struct mega_table megas[mega_items_table_size];
extern struct base_stat_entry base_stats[species_count];
extern struct dex_entry_data dex_data[species_count];
#endif /* ROM_TABLES_H */