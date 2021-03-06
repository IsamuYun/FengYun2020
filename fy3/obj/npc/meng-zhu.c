// meng-zhu.c - 武林盟主
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com           1997.7

#include <login.h>
#include <command.h>
#include <ansi.h>
#define SHIZHE "/data/npc/meng-zhu"

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

int in_ask, answer;
int fight_flag;                                 // 争位标志

int do_copy(object me, object ob);
int do_clone(object me, object ob);
string query_save_file()
{
        return SHIZHE;
}

void create()
{
        object me;
        string *armors, *weapons;
        int i;
        if ( !restore() ) {
                set_name("梁大侠", ({ "wuling mengzhu", "wuling", "mengzhu" }) );
                set("long", "这位就是雄踞武林，号召天下，威风赫赫的当今武林盟主。\n" );
                set("title", "武林盟主" );
                set("gender", "男性" );
                set("age", 35);
                set("attitude", "heroism");
                set("generation", 0);
                set("winner", "none");
                set("str", 30);         // 膂力
                set("cps", 30);         // 定力
                set("cor", 30);         // 胆识
                set("per", 30);         // 容貌
                set("int", 30);         // 悟性
                set("con", 30);         // 根骨
                set("spi", 30);         // 灵性
                set("kar", 30);         // 福缘

                set("max_atman", 0);
                set("atman", 0);
                set("max_force", 0);
                set("force", 0);
                set("force_factor", 0);
                set("max_mana", 0);   
          set("mana", 0);
                // set("no_clean_up",1);
                set("combat_exp", 1);

                set_skill("force",    1);
                set_skill("sword",    1);
                set_skill("unarmed",  1);
                set_skill("parry",    1);
                set_skill("move",     1);
                set_skill("dodge",    1);

                set("chat_chance_combat", 80);
                set("chat_msg_combat", ({
                        (: exert_function, "powerup" :),
                }) );
                setup();
                carry_object("/obj/cloth/cloth")->wear();
                carry_object("/obj/weapon/sword")->wield();
        }
        else {
                set_name(query("name"), ({ "wuling mengzhu", "wuling", "mengzhu" }));
                setup();
                me = this_object();
                if( mapp( me->query("weapons") ) ) {
                        weapons = sort_array( keys( me->query("weapons") ), (: strcmp :) );
                        for( i = 0; i < sizeof( weapons ); i++ )
                                carry_object( me->query("weapons/" + weapons[i] ) )->wield();
                }
                if( mapp( me->query("armors") ) )  {
                        armors = sort_array( keys( me->query("armors") ), (: strcmp :) );
                        for( i = 0; i < sizeof( armors ); i++ )
                                carry_object( me->query("armors/" + armors[i] ) )->wear();
                }
        }

        in_ask = 0;
}

void init()
{
        add_action("do_quest", "quest");
}

int accept_fight(object ob)
{
        object me, obj;
        string name;
        fight_flag = 1;
        me  = this_object();
        if(!( obj = find_living("xiake zuoshi")) ) obj = load_object("/obj/npc/zuo-shi");
        name = obj->query("winner");
        if( this_player()->query("id") == name )
                return notify_fail("你已经是武林侠客左使，还要抢当武林盟主？！\n");

        if(!( obj = find_living("yingxiong youshi")) ) obj = load_object("/obj/npc/you-shi");
        name = obj->query("winner");
        if( this_player()->query("id") == name )
                return notify_fail("你已经是武林英雄右使，还要抢当武林盟主？！\n");

        if(!( obj = find_living("shangshan shizhe")) ) obj = load_object("/obj/npc/shang-shan");
        name = obj->query("winner");
        if( this_player()->query("id") == name )
                return notify_fail("你已经是武林赏善使者，还要抢当武林盟主？！\n");

        if(!( obj = find_living("fae shizhe")) ) obj = load_object("/obj/npc/fa-e");
        name = obj->query("winner");
        if( this_player()->query("id") == name )
                return notify_fail("你已经是武林罚恶使者，还要抢当武林盟主？！\n");
        if ( me->query("winner") == ob->query("id") )
                return notify_fail("你跟你自己打什么架？！\n");
//        if (wizardp(this_player()))
//                return notify_fail("巫师不能抢盟主之位！\n");
        if ( me->is_fighting() )
                return notify_fail("已经有人正在挑战武林盟主！\n");
        me->set("eff_gin", me->query("max_gin"));       me->set("gin", me->query("max_gin"));
        me->set("eff_kee", me->query("max_kee"));       me->set("kee", me->query("max_kee"));
        me->set("eff_sen", me->query("max_sen"));       me->set("sen", me->query("max_sen"));
        me->set("max_force", me->query("max_force"));
        me->set("force",     me->query("max_force"));

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        return 1;
}

int accept_kill(object ob) 
{
        object me;

        fight_flag = 0;

        me  = this_object();

        if ( me->is_fighting() ) 
                return notify_fail("已经有人正在挑战罚恶使者！\n");

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
                return 1;
}

int checking(object me, object ob)
{
        object obj,*enemy;
        int my_max_qi, his_max_qi;
		if (!ob || !me)	return 1;
		if (sizeof(me->query_enemy())>1)	return 1;
        my_max_qi  = me->query("max_kee");
        his_max_qi = ob->query("max_kee");

//        if (me->is_fighting()) {
//		改成一定要和挑战者fight
        if (me->is_fighting(ob)) {
                if ( (me->query("kee") * 100 / my_max_qi) <= 80 ) command("exert recover");
                call_out("checking", 1, me, ob);
                return 1;
        }

        if ( !present(ob, environment(me)) ) return 1; 
//
//        if ( fight_flag == 1 && ( (int)me->query("kee")*100 / my_max_qi) <= 30 
//        ||      ( (int)me->query("eff_kee") * 100 / my_max_qi) <= 30 ) {
//        应该和combatd.c里面的处理一样
        if ( fight_flag == 1 && ( 2*(int)me->query("kee")<= my_max_qi)
        ||      ( 2*(int)me->query("eff_kee") <= my_max_qi)) {
                command("say 果然厉害，恭喜你成为当今武林盟主！\n");
                command("chat 哈哈哈，到底是长江後浪推前浪，一代新人换旧人！\n");
                command("chat 恭喜" + ob->query("name") + "被推举为当今武林盟主！\n");
                do_copy( me, ob );
                return 1;
        }
        if (( (int)ob->query("kee") * 100 / his_max_qi) < 50 ) {
                command("say 看来" + RANK_D->query_respect(ob) +
                        "还得多加练习，方能在当今武林中有所作为 !\n");
                return 1;
       }

        return 1;
}

int do_copy(object me, object ob)
{
// 昏迷处理要修改
		if (!ob || !me)	return 1;
		if (me->query_temp("unconcious"))
			me->revive();

        if (!living(me)) me->revive();

        me->set("winner", ob->query("id"));
        me->add("generation", 1);
        if( me->query("generation") > 100 ) me->set("generation", 1);

        me->set("name",  ob->query("name") );

        me->set("title", "第" + CHINESE_D->chinese_number(me->query("generation")) + "代武林盟主");
        me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
        me->delete("title");
        ob->delete_temp("apply/short");
        ob->set_temp("apply/short", ({me->short()}));

        me->set("title", "第" + CHINESE_D->chinese_number(me->query("generation")) + "代武林盟主");
        me->set("short", me->query("title") + " " + me->query("name") + "(Wuling mengzhu)");
        me->delete("title");

        do_clone( me, ob );

        return 1;
}

int do_recopy(object me, object ob)
{
        me = this_object();
        ob = this_player();

        if ( me->query("winner") != ob->query("id") )
                return notify_fail("你不是现任武林盟主！\n");
        me->set("name",  ob->query("name") );
       me->set("title", "第" + CHINESE_D->chinese_number(me->query("generation")) + "代武林盟主");
        me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
        me->delete("title");
        ob->delete_temp("apply/short");
        ob->set_temp("apply/short", ({me->short()}));
        me->set("title", "第" + CHINESE_D->chinese_number(me->query("generation")) + "代武林盟主");
        me->set("short", me->query("title") + " " + me->query("name") + "(Wuling mengzhu)");

        me->delete("title");
        do_clone( me, ob );

        write("状态更新完毕。\n");
        return 1;
}

int do_clone(object me, object ob)
{
        object *inv, new_ob;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i, temp;

        // seteuid( geteuid(me) );

        /* delete and copy skills */

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);

                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
        }

        if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(sname[i], skill_status[sname[i]]);
                }
        }
       /* delete and copy skill maps */
        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);
                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        me->map_skill(mname[i]);
                }
        }

        if ( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mname[i], map_status[mname[i]]);
                }
        }

        /* delete and copy skill prepares */

        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i=0; i<temp; i++) {
                        me->prepare_skill(pname[i]);
                }
        }

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

        /* unwield and remove weapon & armor */
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                destruct(inv[i]);
        }
        delete("weapons");
        delete("armors");

        /* wield and wear weapon & armor */

        inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) {
/*
				if( inv[i]->query("weapon_prop/damage") > 100
                ||  inv[i]->query("armor_prop/armor") > 100 ) continue;
                if( inv[i]->query("weapon_prop") && inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wield();
                        me->set("weapons/" + sprintf("%d", i + 1), base_name(inv[i]) );
                }
                else if( inv[i]->query("armor_prop") && inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wear();
                       me->set("armors/" + sprintf("%d", i + 1), base_name(inv[i]) );
                }*/
// 改动对自造物品的处理
			if (mapp(map_status=inv[i]->query("weapon_prop")) && stringp(inv[i]->query("equipped"))) {
						me->set("weapon_prop",map_status);
                        carry_object(base_name(inv[i]))->wield();
                        me->set("weapons/" + sprintf("%d", i + 1), base_name(inv[i]) );
                }
           if( mapp(map_status=inv[i]->query("armor_prop")) && stringp(inv[i]->query("equipped")) ) {
						me->set("armor_prop",map_status);
                        carry_object(base_name(inv[i]))->wear();
                        me->set("armors/" + sprintf("%d", i + 1), base_name(inv[i]) );
                }

        }

        /* copy entire dbase values */
        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]);
        me->set("cor", hp_status["cor"]);
        me->set("int", hp_status["int"]);
        me->set("spi", hp_status["spi"]);
        me->set("cps", hp_status["cps"]);
        me->set("per", hp_status["per"]);
        me->set("con", hp_status["con"]);
        me->set("kar", hp_status["kar"]);

        me->set("max_gin", hp_status["max_gin"]);
       me->set("eff_gin", hp_status["max_gin"]);
	me->set("gin", hp_status["max_gin"]);
        me->set("max_kee", hp_status["max_kee"]);
       me->set("eff_kee", hp_status["max_kee"]);
   me->set("kee", hp_status["max_kee"]);
        me->set("max_sen", hp_status["max_sen"]);
       me->set("eff_sen", hp_status["max_sen"]);
	me->set("sen", hp_status["max_sen"]);
        me->set("max_force", hp_status["max_force"]);
        me->set("force", hp_status["force"]);
        me->set("max_atman", hp_status["max_atman"]);
        me->set("atman", hp_status["atman"]);
        me->set("max_mana", hp_status["max_mana"]);
        me->set("mana", hp_status["mana"]);
        me->set("age",       hp_status["age"]);
        me->set("modify_age",hp_status["modify_age"]);
        me->set("long",      hp_status["long"]);
        me->set("gender",    hp_status["gender"]);
        me->set("combat_exp",hp_status["combat_exp"]);

        me->set("cloth",     hp_status["cloth"]);
        me->set("weapon",    hp_status["weapon"]);
        me->set("animal",    hp_status["animal"]);

        save();

        tell_object(ob, "状态储存完毕。\n");
/*
        new_ob = new("/obj/npc/meng-zhu");
        new_ob->move("/d/center/guangchang");
        destruct(me);
*/
        return 1;
}


int do_quest()
{
        string *target=({
                "ouyang feng",
                "wei xiaobao",
                "duan yu",
                "xiao feng",
                "xiao longnu",
                "yang guo",
                "dongfang bubai",
                "ren woxing",
                "yue buqun",
                "tianshan tonglao",
                "xu zhu",
                "murong fu",
                "huang yaoshi",
                "zhang sanfeng",
                "li qiushui",
                "xiaoyao zi",
                "ding chunqiu",
                "jinglun fawang",
                "jiu mozhi",
                "qiu chuji",
                "huang shang",
                "dugu qiubai",
        });
        string *dest=({
                "“西毒”欧阳锋",
                "鹿鼎公韦小宝",
                "大理国世子段誉",
                "丐帮帮主萧峰",
                "古墓派小龙女",
                "神雕大侠杨过",
                "东方神教教主东方不败",
                "日月神教教主任我行",
                "华山掌门岳不群",
                "灵鹫宫主人天山童姥",
                "灵鹫宫少主虚竹",
                "慕容世家少主慕容复",
                "“东邪”黄药师",
                "武当派祖师张三丰",
                "逍遥北宗祖师李秋水",
                "逍遥派祖师逍遥子",
                "星宿海祖师丁春秋",
                "西藏圣僧金轮法王",
                "西藏圣僧鸠摩智",
                "“长春子”丘处机",
                "九阴始祖黄裳",
                "剑魔独孤求败",
        });

        int i, total, ran, t, time;
        object ob, who, *list;
        who = this_player();

        t = time()-who->query("biao_start");
        time = who->query("biao_time");

        if( t <= time ) {
                tell_object(who, "武林盟主对你说：" + RANK_D->query_respect(who)
                        + "似乎还有任务在身吧？\n");
                return 1;
        }

        if( t > time && t < (time + 300) ) {
                if( ob = present("mi han", who) ) destruct(ob);
                who->set("biao_failed",1);
        }

       if( t >= (time + 300) )
                who->delete("biao_failed");

        if(who->query("biao_failed") ) {
                command("hehe " + who->query("id"));
                command("say " + this_player()->name() + "，这封密函关系到武林的命运，我看还是让别人送去吧。\n");
                return 1;
        }

        if( random(10) == 0 ) {                 // 送到玩家手中
                list = users();
                total = 0;
                for(i=0; i<sizeof(list); i++) {
                        if( !environment(list[i]) ) continue;
                        if( this_player() && !this_player()->visible(list[i]) ) continue;
                        total ++;
                }
                ran = random(total) + 1;
                total = 0;
                for(i=0; i<sizeof(list); i++) {                        if( !environment(list[i]) ) continue;
                        if( this_player() && !this_player()->visible(list[i]) ) continue;
                        total ++;
                        if( ran == total ) {

if( query_ip_name(list[i]) == query_ip_name(this_player()) ) {
        command("hehe " + who->query("id"));
        command("say " + this_player()->name() + "，这封密函关系到武林的命运，我看还是下次再找你吧。\n");
        return 1;
}
else {
        t = ( 10 + random(10) ) * 10;
        command("say " + this_player()->name() + "，请你在" + CHINESE_D->chinese_time( t )
                + "内把这封密函送到" + list[i]->query("name") + "的手中。");
        ob = new("/obj/misc/mihan");
        ob->set("target", list[i]->query("id"));
        break;
}
                        }
                }
        }
        else {                                  // 送到NPC手中
                ran = random(sizeof(target));
                t = ( 10 + random(10) ) * 10;
                command("say " + this_player()->name() + "，请你在" + CHINESE_D->chinese_time( t )
                        + "内把这封密函送到" + dest[ran] + "的手中。");
                ob = new("/obj/misc/mihan");
                ob->set("target", target[ran]);
        }
        who->set("biao_start", time());
        who->set("biao_time", t);
        ob->move(who);

        tell_object(who, "快快动身吧！\n");

        return 1;
}

