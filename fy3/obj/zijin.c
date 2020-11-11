#include <ansi.h>
#include <room.h>
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "☆月圆之夜,紫禁之颠！☆");
        set("long", @LONG
     月圆之夜,紫禁之颠！这里就是西门吹雪和叶孤城决战的地方！
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/fy/shufang"
]));
        set("objects", ([
        "/obj/masterye" : 1,
        "/obj/masterximen" : 1,
       ]) );
        set("resettask", 1);
        set("no_fight", 1);
	set("no_magic", 1);
        set("coor/x",-19);
	set("coor/y",-10);
        set("coor/z",100);
        set("coor/x",-19);
	set("coor/y",-10);
        set("coor/z",100);
	setup();
}

void init()
{
        object ob1,ob2,ob;
        ob=this_player();
        ob1=present("master ximen", this_object());
        ob2=present("master ye", this_object());
        add_action("do_foc","fight");
        add_action("do_fod","kill");
	remove_call_out("arrowing");
        if( (wizardp(ob) || ob->query("ye_vs_ximen")) && !this_object()->query("fighting")) call_out("arrowing",1);
}	

int do_fod(string arg)
{
        tell_object(this_player(), "这里是两大剑手对战的地方,你凑什么热闹？\n");
        return notify_fail("  ");
        return 0;
}

int do_foc(string arg)
{
        tell_object(this_player(), "这里是两大剑手对战的地方,你凑什么热闹？\n");
        return notify_fail("  ");
        return 0;
}

int arrowing()
{
        object ob1,ob2,ob;
        message("vision", WHT "\n★一轮皎洁的明月缓缓升上天心......\n", this_object());
        message("vision", "★决战的时刻已到！\n", this_object());
        message("vision", "☆叶孤城缓缓抽出松纹古定剑,打了个躬。\n", this_object());
        message("vision", "☆西门吹雪冷冷一笑,剑已在手中！\n" NOR, this_object());
        ob=new("/obj/guardleader");
        ob1=present("master ximen", this_object());
        ob2=present("master ye", this_object());
        ob1->set("max_sen",999999);
        ob1->set("eff_sen",999999);
        ob1->set("sen",999999);
//        ob1->fight_ob(ob2);
//        ob2->fight_ob(ob1);
        ob1->set("apply/damage",300);
        ob2->set("apply/damage",300);
        ob1->kill_ob(ob2);
        ob2->kill_ob(ob1);
        this_object()->set("fighting",1);
        ob->ccommand("chat 西门吹雪和叶孤城的决战开始！");
}


