// jin-nang by zzfy
#include <ansi.h>
inherit ITEM;
void create()
{
        string *order=({HIB"比武胜利蓝色锦囊"NOR, HIR"比武胜利红色锦囊"NOR, HIY"比武胜利金色锦囊"NOR,HIW"比武胜利白色锦囊"NOR,HIM"比武胜利紫色锦囊"NOR,HIC"比武胜利青色锦囊"NOR});
        set_name((order[random(6)]) , ({ "jin-nang", "jin","nang"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIY "一个用金丝编成的锦囊，似乎可以(open)打开。\n"NOR);
                set("unit","个");
                set("value", 0);
        }
        }
void init()
{
        add_action("open_gongbao","open");
}
int open_gongbao(string arg)
{
        int exp;
        int pot;
        int sscore;
       if (this_player()->query("gender") != "男性"){
              message_vision(HIR"$N你没有权利打开他。\n"NOR,this_player());
                return 1;
        }
       if (this_player()->query("biwuhongbao") == 1){
              message_vision(HIR"$N没有权利打开他。\n"NOR,this_player());
                return 1;
}
        if ( arg == "jin-nang"){
        exp = 2000 + random(2000);
        pot = 300 + random(300);
        sscore = 100;
        message_vision(HIM"$N擦了擦额头的汗水，迫不及待地用颤抖的双手打开了锦囊。\n"NOR,this_player());
        this_player()->add("deposit",sscore);
        this_player()->set("biwuhongbao",1);
        tell_object(this_player(),HIR"哇！！！！你被奖励了：\n\n" +
        chinese_number(sscore) + "两黄金。钱自动放在银行！\n"NOR);
        destruct(this_object());
        return 1;
     }
     return 0; 
}
