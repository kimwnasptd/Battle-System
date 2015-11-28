#ifndef BATTLE_DMG_CALCULATOR
#define BATTLE_DMG_CALCULATOR


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
	u8 size;
	u8 padding[3];
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


	/* 
	0 = immune
	1 = 1/2
	2 = 1
	3 = 2	
	*/
u8 type_effectiveness = [ 2, 2, 2, 2, 2, 1, 2, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1, 1, 2, 3, 1, 0, 3, 2, 2, 2, 2, 2, 1, 3, 2, 3, 1, 2, 3, 2, 2, 2, 1, 3, 2, 1, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1, 0, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, 2, 2, 0, 3, 2, 3, 1, 2, 3, 2, 2, 2, 1, 3, 2, 2, 2, 2, 2, 2, 1, 3, 2, 1, 2, 3, 2, 1, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 1, 1, 2, 1, 2, 3, 2, 3, 2, 2, 3, 1, 0, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 2, 2, 2, 2, 2, 2, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 2, 3, 2, 1, 1, 3, 2, 2, 3, 1, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 3, 1, 1, 2, 2, 2, 1, 2, 2, 2, 2, 1, 1, 3, 3, 1, 2, 1, 2, 1, 3, 1, 2, 2, 2, 1, 2, 2, 2, 2, 3, 2, 0, 2, 2, 2, 2, 2, 2, 3, 1, 1, 2, 2, 1, 2, 2, 2, 3, 2, 3, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 0, 2, 2, 2, 3, 2, 3, 2, 2, 2, 1, 2, 1, 1, 3, 2, 2, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 0, 2, 1, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 1, 2, 3, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 2];

extern move_id move[move_total];
extern natural_gift_table natural_gift_t[natural_gift_table_size];
extern fling_table fling_t[fling_table_size];
extern sheer_force_table sheer_force_t[sheer_force_table_size];
extern mega_items_table mega_items_t[mega_items_table_size];
extern iron_fist_table iron_fist_t[iron_fist_table_size];
extern reckless_table reckless_t[reckless_table_size];
extern type_effectiveness type_chart;
extern berries_table berries_t[berries_table_size];

#endif /* BATTLE_DMG_CALCULATOR */