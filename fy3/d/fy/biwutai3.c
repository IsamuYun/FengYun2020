//edit by xgchen@zzfy
#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "±ÈÎäÌ¨");
        set ("long", @LONG

     [41m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[0m
     [41m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[0m
     [41m¡ù¡ù                                                ¡ù¡ù[0m
     [41m¡ù¡ù                                                ¡ù¡ù[0m
     [41m¡ù¡ù                                                ¡ù¡ù[0m
     [41m¡ù¡ù          [1;37m    ÕâÀïÊÇÖ£ÖÝ·çÔÆµÄ±ÈÎäÌ¨    [0m[41m        ¡ù¡ù[0m
     [41m¡ù¡ù                                                ¡ù¡ù[0m
     [41m¡ù¡ù                                                ¡ù¡ù[0m
     [41m¡ù¡ù                                                ¡ù¡ù[0m
     [41m¡ù¡ù                                                ¡ù¡ù[0m
     [41m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[0m
     [41m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[0m
     ±ÈÎäÃüÁî biwuok <id>
LONG);
        set("info_sends",1);
  set("biwuchang", 1);
   set("no_death_penalty", 1);
        set("fight_room",1);
 set("no_magic", 1);
        set("exits", ([
                "down"   : __DIR__"biwutai2",
                "up"   : __DIR__"biwutai3",
        ]));
        setup();
}

void init()
{
        add_action ("do_work","fight");
        add_action ("do_work","kill");
        add_action ("do_fight","biwuok");
        add_action ("do_work","quit");
        add_action ("do_work","exert");
        add_action ("do_work","perform");
        add_action ("do_work","halt");
        add_action ("do_work","jiasi");
        add_action ("do_work","perform xiaoli-feidao");
        add_action ("do_work","cast");
        add_action ("do_work","surrender");
}

int do_fight(string arg)
{
        object me=this_player();
        object *inv=all_inventory(environment(me));
        object ob;
        object who;
        int i;

        if(!arg) { 
                write("ÄãÒªÍ¬Ë­±ÈÎä£¿\n");
                return 1;
        }
        ob=present(arg, environment(me));
        if(!ob) {
                write("ÕâÀïÃ»ÓÐÕâ¸öÈË£¡\n");
                return 1;
        }
        if(ob==me) {
                write("ÄãÒªÍ¬×Ô¼º±ÈÎä£¿£¿£¿\n");
                return 1;
        }
        if(!interactive(ob)) {
                write("ËûÏÖÔÚÎÞ·¨Í¬Äã±ÈÎä£¡\n");
                return 1;
        }
        if(!userp(me) || !userp(ob)) {
                write("ËûÏÖÔÚÎÞ·¨Í¬Äã±ÈÎä£¡\n");
                return 1;
        }

        for(i=0; i<sizeof(inv); i++) {
                who=inv[i];
                if(who->is_fighting()) {
                        write("Ì¨ÉÏ"+who->query("name")+"µÈÕýÔÚ±ÈÎä£¬ÇëÉÔºî£¡\n");
                        return 1;
                }
        }

        message("channel:gab",HIM"¡¾Ö£ÖÝ·çÔÆ±ÈÎä³¡¡¿"+
                me->query("family/family_name")+"µÄ"+me->query("name")+"Óë"+
                ob->query("family/family_name")+"µÄ"+ob->query("name")+
                "ÔÚ±ÈÎäÌ¨ÉÏ½ÏÁ¿¸ßµÍ£¡\n\n"NOR,users());

        me->set("biwu_fighter",1);
        ob->set("biwu_fighter",1);
        ob->fight_ob(me);
        me->fight_ob(ob);
        return 1;
}

varargs void tell_room(string str)
{
        tell_room(__DIR__"biwukantai", str);
}

int do_work()
{
        write("ÕâÀï²»ÄÜÊ¹ÓÃÕâ¸öÖ¸Áî£¡\n");
        return 1;
}
int valid_leave(object me, string dir)
{
        if ( !wizardp(me) && dir=="down" ) {
                if( me->query("biwu_fighter") )
                        return notify_fail("ÄãÂíÉÏÒª±ÈÎäÁË£¬²»Òªµ½´¦ÂÒÅÜ¡£\n");
        }
//        if ( !wizardp(me) && dir=="up" ) {
//                if( me->query("xxx") )
//                        return notify_fail("ÓÐÍæ¼ÒÔÚÄã²»ÄÜÉÏÈ¥¡£\n");
//        }

        me->delete_temp("last_opponent");
        me->delete_temp("last_damage_from");
        me->remove_all_killer();

        return ::valid_leave(me, dir);
}
