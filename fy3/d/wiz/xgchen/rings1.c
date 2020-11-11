#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name( HIY "荣誉戒指" NOR, ({ "rongyu ring", "ring" }) );
        set_weight(0);

        set("no_get",1);
       set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long",
                        HIW"这是郑州风云送给荣誉玩家的戒指。\n"NOR);
                set("armor_type", "finger");
                set("wear_msg", "$N将$n拿出来小心地戴在手指上。\n");
                set("remove_msg", "$N将$n小心地从手指上摘下来放好。\n");
        }
        setup();
}
void init()
{
        add_action("do_full","full");
        add_action("do_goto","gotoo");
}
int do_full(string arg)
{
        int m_kee;
        int m_sen;
        int m_gin;
        int m_force;
       if (this_player()->query("rongyu") < 1){
              message_vision(HIR"$N不是荣誉玩家，请不要乱用。\n"NOR,this_player());
                return 1;
        }
    if (( arg == "me")){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
              message_vision(HIR"$N打开荣誉戒指，一道金光从天而降。\n"NOR,this_player());
        this_player()->set("eff_kee",m_kee);
        this_player()->set("kee",m_kee);
        this_player()->set("env/immortal",1);
        this_player()->set("eff_gin",m_gin);
        this_player()->set("gin",m_gin);
        this_player()->set("eff_sen",m_sen);
        this_player()->set("sen",m_sen);
        this_player()->set("force",m_force);
        this_player()->set("title",HIR"郑州风云荣誉玩家"NOR);
                this_player()->set("max_mana", 2000);
                this_player()->set("max_atman", 2000);
                this_player()->set("atman", 2000);
                this_player()->set("mana", 2000);
                this_player()->set_skill("iron-cloth", 100);
        return 1;
     }
     return 0; 
}
int do_goto(object me, object target)
{
        if(this_player()->query("rongyu") < 1 )
                return notify_fail("你不是荣誉玩家不能使用荣誉戒指！\n");
        write(HIC"你要去哪个人身边？"NOR);
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        object ob;

        if( !name || name=="" ) {
                write(HIC"停止移动。\n");
                return;
        }
              me = this_player();
        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if( !ob || !me->visible(ob) || !environment(ob)) {
                write(HIB"你无法移动到这个人的身边 ....\n"NOR);
                write(HIC"你要去哪个人身边？"NOR);
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
      
        message_vision( HIR "\n$N高举荣誉戒指，运用巫师给你的移动权力....\n" NOR, me);
        me->move(environment(ob));
        message( "vision", HIG "\n你的身边出现了一个人！看上去好象就是"+me->name()+"。\n\n" NOR,
                environment(ob), ({ me }) );
}
void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}

