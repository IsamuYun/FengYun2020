// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("秦五", ({ "dyg xiang"}));
        set("long", "这就是我们第二届比武大会总冠军。\n");

        set("gender","男性");
        set("str", 2000);
        set("cor", 26);
        set("cps", 25);
set("age", 29);
        set("combat_exp", 100000000);
        set("nickname", HIR" 万事随缘往 "HIC"来去若梦行"NOR);
        set("title", HIR"第二届比武大会总冠军"NOR" 少林寺下山弟子");
        setup();
        carry_object("obj/cloth")->wear();
}
/*
void init()
{
        ::init();
        add_action("do_work", "good");

}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
if(!me->is_busy()) return notify_fail("奖励的时间已经过了。\n");
if(userp(me)) return notify_fail("奖励的时间已经过了。\n");
if(me->query("family/master_id")!="dxl") return notify_fail("你不是哈哈的弟子，不能奖励。\n");
if(me->query("class")!="ertongtuan_") return notify_fail("你不是儿童团的弟子，不能奖励。\n");
if(me->query("biwubangjiangli")== 1) return notify_fail("你已经来奖励了，不能再奖励了。\n");
message_vision("$N你师父在比武大会中力战对手，赢得第一届冠军，这个红包是奖励你的!\n",me);
ob = new("/questobj/obj/biwuhongbao");
ob->move(me);
message_vision("哈哈说：希望你继续为本门发扬光大。\n", me);
me->start_busy(1);
me->set("biwubangjiangli",1);
return 1;
}
*/
