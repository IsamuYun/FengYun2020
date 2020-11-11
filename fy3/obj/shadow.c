#pragma save_binary
// 分身化影的影子
// by xgchen@fy

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("影子",({"shadow"}));
        set("int",30);
        setup();               
}

void heal_up()
{
if(!is_fighting())
        destruct(this_object());             

}

int receive_damage(int damage)
{
	object killer,*inv;
	int i;
	if(damage)
        {
	remove_all_enemy();
	inv=all_inventory(environment(this_object()));
                for(i=0; i<sizeof(inv); i++)
                {
                inv[i]->remove_enemy(this_object());
		}
        call_out("die",1,this_object());
        }
}
void die()
{
        message("vision","影子受到攻击，立刻消失了\n",environment(this_object()));
        destruct(this_object());
}
void unconcious()
{
die();
}