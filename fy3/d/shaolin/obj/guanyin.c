// medicine.c
inherit ITEM;
void create()
{
	set_name("������",({"guan yin"}));
        set_weight(6000);
	set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ������񣬾ݴ���ݣ�knee���Ժ������书��ͻ���ͽ���\n");
	    set("unit","��");
	    set("value", 20000);
	}
}

void init()
{
	add_action("apply_effect","knee");
}

int apply_effect()
{
	int value = 20;
	int diff;

	if(this_player()->is_fighting())
	    return notify_fail("ս������ô�ܹ�ݹ�����\n");
		    
	message_vision("$N�����̣�һ�������ڹ�����ǰ�����������ؿ���������ͷ��\n",this_player());
	this_player()->receive_damage("kee",10);
if(!random(300)) this_player()->add("combat_exp",-200);
	return 1;
}


