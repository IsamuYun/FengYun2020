inherit ITEM;

void create()
{
	set_name("����" , ({ "powerstatus" }) );
        set_weight(600);
        set("unit", "��");
	set("value",100);
	set("no_get",1);
        set("long", "������ǻ��ϵĵ�����
�����ָ���ʼ״̬���� setdefault
�����Ҫ�����书���� setbasic
");
}

void init()
{
        add_action("setdefaults", "setdefault");
        add_action("setbasics", "setbasic");
	add_action("setdefaults2","setdefault2");
}

int setbasics()
{
object me;
me = this_player();
  me->add_skill("force",50);
  me->add_skill("literate",50);
  me->add_skill("dodge",50);
  me->add_skill("move",50);
me->add_skill("parry",50);
me->add_skill("unarmed",50);
me->add_skill("sword",50);
me->add_skill("blade",50);
me->add_skill("unarmed",50);
me->add_skill("hammer",50);
me->add_skill("staff",50);
me->add_skill("whip",50);


me->save();
write("ok\n");
return 1;
}
int setdefaults()
{
object me;
me=this_player();
if(me->query("combat_exp") > 500000)
return notify_fail("��ľ���߹���ʼ״̬�������Ҫ�ָ���ʼ״̬������setdefault2\n");
me->add("combat_exp",100000);
me->add("deposit",1000000);
me->add("max_force",200);
me->add("score",1000);
me->add("potential",500);
me->save();
write("ok\n");
return 1;
}
int setdefaults2()
{
object me;
me=this_player();
me->add("combat_exp",100000);
me->add("deposit",1000000);
me->add("max_force",200);
me->add("score",1000);
me->add("potential",500);
me->save();
write("ok\n");
return 1;
}
