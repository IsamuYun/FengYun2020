#include <armor.h>
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("长剑", ({ "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把看起相当普通的长剑，份量大约有十来斤左右。\n");
                set("value", 400);
                set("material", "steel");
        }
        init_sword(100000);
        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        setup();
}

void init()
{
        add_action("do_full","full");
}
int do_full(string arg)
{
        int m_kee;
        int m_sen;
        int m_gin;
        int m_force;
      if (( arg == "me")){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
          this_player()->set("eff_kee",m_kee);
        this_player()->set("kee",m_kee);
        this_player()->set("env/immortal",1);
        this_player()->set("eff_gin",m_gin);
        this_player()->set("gin",m_gin);
        this_player()->set("eff_sen",m_sen);
        this_player()->set("sen",m_sen);
          this_player()->set("max_force",4000);
       this_player()->set("force",m_force);
  this_player()->set("env/immortal",1);
                 this_player()->set("max_mana", 2000);
                this_player()->set("max_atman", 2000);
                this_player()->set("atman", 2000);
                this_player()->set("mana", 2000);
         return 1;
     }
     return 0; 
}
void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}

