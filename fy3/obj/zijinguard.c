inherit NPC;
#include <ansi.h>
void create()
{
        set_name("ʿ��", ({ "soldier"}) );
        set("age", 30);
	set("long",
"���������Ͻ��ǵ�ʿ����\n");
        set("attitude", "peaceful");
        set("no_arrest", 1);
        set("can_carry", 1);
        set("hit_always_on", 1);
        set("str", 80);
        set("combat_exp", 10000000);
        set("limbs", ({ "�У�" }) );
        set_skill("unarmed", 400);
        set_skill("dodge",400);
        set_skill("parry",400);
        create_family("��͢��Ʒ", 1, "��");
	setup();
}


int accept_object(object who, object ob)
{
object room;
if(ob->query("name") == "�߲�˿�д�" && environment()->query("accept_in"))
{
        command("emote ���˵�ͷ,˵:�����ͨ���ˣ�\n");
        environment()->add("accept_in",-1);
    room = find_object("/obj/wall");
      if(!objectp(room)) room = load_object("/obj/zijinmen");
    who->move(room);
	return 1;
}

if(ob->query("name") == "�߲�˿�д�" && environment()->query("accept_intwo"))
{
        command("emote �ֳ�����ֵı���,���˿�˿��,��������\n");
        command("emote �����ֱ����������þ�,̾�˿�����\n");
    room = find_object("/obj/wall");
      if(!objectp(room)) room = load_object("/obj/zijinmen");
    who->move(room);
        environment()->add("accept_intwo",-1);
	return 1;
}

if(ob->query("name") == "�߲�˿�д�")
{
        command("emote �ֳ�����ֵı���,���˿�˿��,��������\n");
        command("emote ���:����ģ��������Ӽ������ˣ�\n");
        command("emote �ȵ�:����ͨ����\n");
	return 1;
}
}
