
#include <ansi.h>

inherit F_CLEAN_UP;
 mapping valid_types = ([
//        "array":        "阵法",
        "axe":          "斧法",
        "blade":        "刀法",
        "toxin":        "毒术",
        "sorrow":        "箭术",
        "dagger":       "短兵刃",
        "dodge":        "闪躲术",
        "force":        "内功",
        "fork":         "叉法",
        "hammer":       "锤法",
        "chanting":       "诵经",
        "iron-cloth":   "硬功",
        "literate":     "读写",
        "magic":        "法术",
        "move":         "轻功",
        "parry":        "招架",
        "perception":   "听风术",
        "scratching":   "符之术",
        "cursism" :     "降头术",
        "spells":       "咒文",
        "staff":        "杖法",
        "stealing":     "妙手术",
        "sword":        "剑法",
        "throwing":     "暗器",
        "unarmed":      "拳脚",
        "whip":         "鞭法",
        "herb":         "药道",
        "spear":        "枪法",
]);

int main(object me, string arg)
{
        object player;
        mapping map;
        string *types, *skill, ski, map_to;
        int i, modify;

        if ( arg )
        {
                player = present( arg, environment( me ) );
                if ( !player )
                        player = find_player( arg );
                if ( !player )
                        player = find_living( arg );
                if ( !player )
                        return notify_fail( "你想查看谁的状态? \n" );   
                map = player->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("他现在没有使用任何特殊技能。\n");

                skill = keys(valid_types);
                write("以下是他目前使用中的特殊技能。\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !player->query_skill(skill[i]) ) continue;
                        modify = player->query_temp("apply/" + skill[i]);
                        printf("  %-20s： %-20s  有效等级：%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "无" : 
to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                player->query_skill(skill[i]));
                }
                return 1;
        }
        else
        {
                return notify_fail( "你想看谁的状态啊? \n" );
        }
}

