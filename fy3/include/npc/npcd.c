// npcd.c

#pragma optimize
#pragma save_binary
#include <command.h>
/*
#include <npc/name.h>
#include <npc/chinese.c>
#include <npc/japanese.c>
#include <npc/european.c>
#include <npc/masia.c>
#include <npc/indian.c>

#define HUANG_SHANG             "/daemon/class/ultra/huang"
#define DUGU_QIUBAI             "/daemon/class/ultra/dugu"
#define KUIHUA_TAIJIAN          "/daemon/class/ultra/kuihua"
#define NANHAI_SHENNI           "/daemon/classs/ultra/shenni"
*/
mapping levels = ([
//      combat_exp   skill_level
        50000      : 60,                // level 1
        100000     : 80,                // level 2
        200000     : 100,               // level 3
        400000     : 125,               // level 4
        800000     : 150,               // level 5
        1200000    : 175,               // level 6
        1600000    : 200,               // level 7
        2000000    : 225,               // level 8
        2500000    : 250,               // level 9
        2700000    : 275,               // level 10
        3000000    : 300,               // level 11
        5000000    : 350,               // level 12
        7500000    : 400,               // level 13
        9000000    : 450,               // level 14
        15000000   : 500,               // level 15
]);

mapping place = ([
        "大理十里长亭" : ({ "/d/dali/ting" }),
        "风云城"   : ({ "/d/fy/hall", "/d/fy/shufang"，}),
        "圆月山庄"   : ({ "/u/moon/caodi" }),
        "清风细雨楼"   : ({ "/d/lou/biggate", "/d/lou/dating", }),
        "迷茫风雨路" : ({ "/u/palace/palace_path2", "/u/palace/palace_path3", }),
        "布达拉宫" : ({ "/u/guanwai/citygate" }),
        "沉香镇" : ({ "/d/chenxiang/cxcenter" }),
        "黄山一带" : ({ "/d/huangshan/songgu", "/d/huangshan/shanmen",
                        "/d/huangshan/banshan", }),
        "四川一带" : ({ "/d/sichuan/shudao1", }),
        "莽林之中"   : ({ "/d/manglin/center2" }),
        "西方神教"   : ({ "/d/daimiao/tongting", }),
        "东岳大帝庙一带"  : ({ "/d/daimiao/houqing", }),
        "泰山一带"   : ({ "/d/taishan/buyun", "/d/taishan/hongmen", }),
        "老屋一带"   : ({ "/d/laowu/daroad", "/d/laowu/street", }),
        "清平山庄"   : ({ "/d/qingping/ting" }),
        "三清宫"   : ({ "/u/taoguan/taoguan", }),
        "兴国禅寺"   : ({ "/d/qianfo/chansi" }),
        "关外"     : ({ "/u/guanwai/grassland0" }),
        "五毒教"     : ({ "/d/wudujiao/mroom" }),
        "万梅山庄" : ({ "/d/wanmei/center" }),
]);

// return the character(ob) 's level, 0 is lowest
int check_level(object ob)
{
        int *exp;
        int i;

        exp = sort_array(keys(levels), 1);
        for (i = 0; i < sizeof(exp); i++)
                if (ob->query("combat_exp") < exp[i]) break;
        return i;
}

// set the the level of the npc's skill
void init_npc_skill(object ob, int lvl)
{
        int sk_lvl;
        string *ks;
        int i;
        int exp;

        if (lvl < 1) lvl = 1;
        if (lvl >= sizeof(levels)) lvl = sizeof(levels) - 1;

        exp = sort_array(keys(levels), 1)[lvl - 1];
        ob->set("combat_exp", exp);
        sk_lvl = levels[exp];
        if (! ob->query_skills())
                return;
        ks = keys(ob->query_skills());
        for (i = 0; i < sizeof(ks); i++)
                ob->set_skill(ks[i], sk_lvl);
}

string *nations = ({ "中国", "日本", "龟慈", "荷兰", "天竺", "蒙古",
                     "俄罗斯", "英吉利", "法兰西", "西班牙", "葡萄牙",
                     "比利时", "塔吉克斯坦", "哈沙克斯坦", "乌兹别克斯坦" });

// generate a npc with nation & skill level
object create_npc(string nation, int lvl)
{
        object ob;

        switch (nation)
        {
        case "中国":
                ob = new(CLASS_D("generate") + "/chinese");
                NPC_D->generate_cn_name(ob);
                break;
        case "日本":
                ob = new(CLASS_D("generate") + "/japanese");
                NPC_D->generate_jp_name(ob);
                break;
        case "英吉利":
        case "法兰西":
        case "西班牙":
        case "葡萄牙":
        case "比利时":
        case "荷兰":
                ob = new(CLASS_D("generate") + "/european");
                NPC_D->generate_e_name(ob);
                break;
        case "天竺":
                ob = new(CLASS_D("generate") + "/indian");
                NPC_D->generate_in_name(ob);
                break;
        case "花剌子模":
        case "龟慈":
        case "俄罗斯":
        case "塔吉克斯坦":
        case "哈沙克斯坦":
        case "乌兹别克斯坦":
        case "蒙古":
                return 0;
        }

        ob->set("nation", nation);
        init_npc_skill(ob, lvl);

        return ob;
}

// generate challenger
object create_challenger()
{
        string *n;
        object *ob;
        int max_level;
        int i;
        int lvl;

        ob = all_interactive();
        max_level = 0;
        for (i = 0; i < sizeof(ob); i++)
                if (! wizardp(ob[i]) && max_level < check_level(ob[i]))
                        max_level = check_level(ob[i]);

        max_level++;
        lvl = 1 + random(max_level);
        if (lvl < 3) lvl = max_level;

        n = ({ "日本", "日本", "日本",
               "天竺",
               "英吉利", "法兰西", "西班牙", "葡萄牙", "比利时", "荷兰", });
        return create_npc(n[random(sizeof(n))], lvl);
}

// set the basic parameter from me
void set_from_me(object tob, object fob, int scale)
{
        mapping my, hp_status;

        hp_status = fob->query_entire_dbase();
        my = tob->query_entire_dbase();

        if (! scale)
        {
                if (undefinedp(my["scale"]))
                        my["scale"] = 100;
                scale = my["scale"];
        }

        my["str"] = hp_status["str"] * scale / 100;
        my["int"] = hp_status["int"] * scale / 100;
        my["con"] = hp_status["con"] * scale / 100;
        my["dex"] = hp_status["dex"] * scale / 100;

        my["max_kee"]     = hp_status["max_kee"]   * scale / 100;
        my["eff_kee"]     = my["max_kee"];
        my["kee"]         = my["max_kee"];
        my["max_sen"]     = hp_status["max_sen"]   * scale / 100;
        my["eff_sen"]     = my["max_sen"];
        my["sen"]         = my["max_sen"];
        my["max_gin"]   = hp_status["max_gin"] * scale / 100;
        my["eff_gin"]   = my["max_gin"];
        my["gin"]       = my["max_gin"];
        my["max_force"]  = hp_status["max_force"]* scale / 100;
        my["neili"]      = my["max_neili"] * 2;
        my["force_factor"]      = hp_status["max_force"] / 25;
        if (my["max_force"] > 9000)
                // max_force not more then 9k
                my["max_force"] = 9000;

        tob->set_from_me(fob, scale);
}

// place npc
void place_npc(object ob, string *not_place)
{
        string *kp;
        string p;
        string startroom;
        object pos;

        kp = keys(place);
        if (arrayp(not_place))
                kp -= not_place;
        for (;;)
        {
                p = kp[random(sizeof(kp))];
                startroom = place[p][random(sizeof(place[p]))];
                if (! objectp(pos = get_object(startroom)))
                {
                        log_file("log", sprintf("error to place npc to %s:%s\n",
                                                p, startroom));
                        continue;
                }
                break;
        }

        ob->move(pos);
        ob->set("place", p);
        ob->set("startroom", startroom);
        ob->set_temp("moved", ({ }));
        message_vision("$N走了过来。\n", ob);
}

#define MAX_MOVED       5

// random move
void random_move(object ob)
{
        mapping exits;
        string *moved;
        string dir;
        string *dirs;
        int i;

        moved = ob->query_temp("moved");
        if (! moved) moved = ({ });
        if (sizeof(moved) >= MAX_MOVED)
        {
                // out of range, move back
                dir = GO_CMD->query_reverse(moved[sizeof(moved) - 1]);
        } else
        {
                exits = environment(ob)->query("exits");
                dirs = keys(exits);
                for (i = 0; i < 12; i++)
                {
                        if (! sizeof(dirs))
                                return;
                        dir = dirs[random(sizeof(dirs))];
                        if (stringp(GO_CMD->query_reverse(dir)) &&
                            ! exits[dir]->query("no_fight"))
                                break;
                        dirs -= ({ dir });
                }
        }

        if (sizeof(moved) &&
            GO_CMD->query_reverse(dir) == moved[sizeof(moved) - 1])
        {
                // move back
                moved = moved[0..<2];
        } else
                moved += ({ dir });
        ob->set_temp("moved", moved);

        GO_CMD->main(ob, dir);
}
/*
// get all ultra master
object *query_ultra_master()
{
        return ({ get_object(HUANG_SHANG),
                  get_object(DUGU_QIUBAI),
                  get_object(KUIHUA_TAIJIAN),
                  get_object(NANHAI_SHENNI) });
}
*/