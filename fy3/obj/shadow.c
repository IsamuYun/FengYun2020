#pragma save_binary
// ����Ӱ��Ӱ��
// by xgchen@fy

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("Ӱ��",({"shadow"}));
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
        message("vision","Ӱ���ܵ�������������ʧ��\n",environment(this_object()));
        destruct(this_object());
}
void unconcious()
{
die();
}