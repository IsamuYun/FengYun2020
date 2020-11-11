inherit ITEM;

void create()
{
	set_name("�׽�ʯ" , ({ "powerstone" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "����һ�����о����񹦣���Ħ�׽��������׽�ʯ��\n");
        set("value", 0);
}

void init()
{
        add_action("setskillss", "setski");
        add_action("setattss", "setatt");
	add_action("setdefaultss", "setdef");
}
int setskillss ( string arg)
{
	object me;
	string skilltype, skilllevel;
	int ski;
	me = this_player();		
        if(!arg) return notify_fail("Usage: setski skilltype skilllevel\n");
        if( sscanf(arg, "%s to %s", skilltype, skilllevel)==2
        || sscanf(arg, "%s %s", skilltype, skilllevel)==2 );
        else return notify_fail("Usage: setski skilltype skilllevel\n");
	ski = atoi(skilllevel);
        me->set_skill(skilltype , -10000000);
	tell_object(me, "Set your " + skilltype + " to " + skilllevel + "\n");
	return 1;
}
 
int setattss ( string arg)
{
        object me;
        string atttype, attlevel;
        int ski;
        me = this_player();
        if(!arg) return notify_fail("Usage: setatt atttype attlevel\n");
        if( sscanf(arg, "%s to %s", atttype, attlevel)==2
        || sscanf(arg, "%s %s", atttype, attlevel)==2 );
        else return notify_fail("Usage: setatt atttype attllevel\n");
        ski = atoi(attlevel);
         me->set(atttype , -10000000);
        tell_object(me, "Set your " + atttype + " to " + attlevel + "\n");
        return 1;
}
