#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("达摩剑谱", ({ "damo-jianpu" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "一本羊皮书,上面写着任何弟子禁止阅读(yuedu)。\n");
        }
}

int is_container() { return 1; }

void init()
{
  add_action("do_combine","yuedu");
}

int do_combine(string arg)
{
              int sscore;
       if (this_player()->query("class") != "shaolin"){
              message_vision(HIR"$N不能阅读这本少林秘籍。\n"NOR,this_player());
                return 1;
        }
    if (( arg == "damo-jianpu")){
        sscore = 50 + random(50);
        message_vision("$N偷偷打开这本剑谱,发现里面什么都没有！\n",this_player());
        this_player()->set("m_success/偷读剑谱",1);
        tell_object(this_player(),HIY"由于你对少林的不忠，你的评价降低了!\n"NOR);
        this_player()->add("score",-sscore);
        destruct(this_object());
return 1;
}
     return 0; 
}
