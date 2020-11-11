#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);
int do_qingtie();
void create()
{
        set_name("春姑", ({ "chun-gu" }) );
        set("gender", "女性" );
        set("title",  "生儿育女" NOR);
            set("nickname",HIR"为人民服务"NOR);
       set("age", 62);
        set("long","是风云接生办的主任，据说和叶孤城有关系。\n");
        set("combat_exp", 500000000);
        set("str", 150000);
         set("inquiry", ([
                "请接生"    : (: do_qingtie :),
                "要生孩子了"    : (: do_qingtie :),
        ]));    
    set("attitude", "friendly");
        setup();

}
void init()
{
        object ob;
        ::init();
        add_action("do_qingtie", "fatie");
}
int do_qingtie()
{
       object me, tie, ob, *all, ke, ma;
       int i;
       object xingren1 ,xingren2;
       me=this_player();
       ob=this_object();
       all = users();
       if (!me->query("marry")) 
       {
        say ("春菇说：“还没有结婚怎么会生孩子呀，我们这里也有计划生育的。”\n");
        return 1;
       }
       if (me->query("gender")=="男性") 
       {
        say ("春菇说：“男的也要生孩子？不可以吧。”\n");
        return 1;
       }
       if (!me->query("baby-ok")) 
       {
        say ("春菇说：“还没有怀六甲，我能帮你吗。”\n");
        return 1;
       }
  message_vision(HIW "$N拍了拍手，几个丫鬟扶着"+me->query("name")+"走了。\n" NOR,this_object()); 
       me->set("jiesheng-ok",1);
       me->move("d/fy/jiesheng_room");
       say(HIR "春姑轻笑一声说：“请其他人在这里等候。”\n" NOR);
       return 1;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "春姑说道：这位" + RANK_D->query_respect(ob)
                                + "，要生小孩么？\n");
                        break;
                case 1:
                        say( "春姑说道：这位" + RANK_D->query_respect(ob)
                                + "，你有伴侣了吗？\n");
                        break;
        }
}


