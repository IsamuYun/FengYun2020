inherit NPC;
#include <ansi.h>
string doing();
string *item = ({
"������",
"���",
"���",
"����",
"��˿��",
"���ɾ�",
"��ѿ��",
"����Ȧ",
"�ݾ��ɵ�",
"�ں����Ķ���",
"��ʵ�",
"ī�ɵ�",
"������",
"������",
"������",
"ȸ���ɵ�",
"�����ɵ�",
"��Ȫʥ��",
"������",
HIW"���絶"NOR,
MAG"ҹ��ħ��"NOR,
HIG"��Ҷ��"NOR,
RED"��Ѫ��"NOR,
YEL"�����"NOR,
CYN"�������µ�"NOR,
HIY"����ն��"NOR,
HIR"����ŭ��"NOR,
HIC "а��Ե�"NOR,
"����",
HIW"����"NOR,
MAG"���潣"NOR,
HIG"�޻��齣"NOR,
RED"���ƽ�"NOR,
YEL"����"NOR,
CYN"�ط�"NOR,
HIY"���¿���"NOR,
HIR"��ѩ�к�"NOR,
HIC "��ˮ�̲�"NOR,
"�˽�����",
HIW"�������"NOR,
MAG"ة����"NOR,
HIG"��������"NOR,
	RED"�޷���"NOR,
	YEL"����"NOR,
	CYN"����"NOR,
	HIY"�����ѩ"NOR,
	HIR"�޻�����"NOR,
	HIC "Ǭ������"NOR,
	"��צȭ��",
	HIW"��צȭ��"NOR,
	 MAG"����ȭ��"NOR,
	 HIG"������"NOR,
	 RED"����"NOR,
	YEL"����ȭ��"NOR,
	CYN"�����"NOR,
	HIY"��������"NOR,
	HIR"��ʯ��ɽ"NOR,
	HIC "Ե����ɽ"NOR,
	 "������",
	 HIW"���ƺͷ�"NOR,
	MAG"��ɳ����"NOR,
	HIG"Ҷ�ư�"NOR,
	 RED"ҹ����"NOR,
	 YEL"�������"NOR,
	CYN"���ս��"NOR,
	 HIY"����ս��"NOR,
	 HIR"����ħ��"NOR,
	 HIC "��������"NOR,
	 "�鲼ͷ��",
	HIW"����ͷ��"NOR,
	 MAG"�ޱ�ñ"NOR,
	HIG"����ñ"NOR,
	 RED"����ñ"NOR,
	YEL"ǭ��Ƥñ"NOR,
	CYN"�㻨��"NOR,
	HIY"��Ƥñ"NOR,
	 HIR"�����"NOR,
	HIC "�����"NOR,
	 "��������",
	 HIW"˫ɫ����"NOR,
	 MAG"õ����"NOR,
	HIG"��ľ��"NOR,
	RED"Ц������"NOR,
	 YEL"Ư�취��"NOR,
	 CYN"��������"NOR,
	HIY"��ˮ��"NOR,
	 HIR"Ǭ����"NOR,
	HIC "����֮��"NOR,
	"��Ƥѥ",
	 HIW"ţƤѥ"NOR,
	 MAG"��Ь"NOR,
	 HIG"���п���"NOR,
	RED"����ѥ"NOR,
	YEL"׷��ѥ"NOR,
	 CYN"ս������"NOR,
	 HIY"����ս��"NOR,
	 HIR"̤ѩ�޺�"NOR,
	HIC "������"NOR,
	 "����",
	  HIW"÷����"NOR,
	MAG"��ս�ָ"NOR,
	HIG"����"NOR,
	RED"�����ָ"NOR,
	 YEL"�����"NOR,
	CYN"��������"NOR,
	 HIY"����"NOR,
	HIR"�߲ʷ�ʯ"NOR,
	 HIC "�����ָ"NOR,
	"ϸ����",
	HIW"������"NOR,
	MAG"�鲼����"NOR,
	 HIG"��Ƥ����"NOR,
	RED"��¹����"NOR,
	  YEL"��Ƥ����"NOR,
	 CYN"��겼"NOR,
	 HIY"��������"NOR,
	HIR"��ɽ��"NOR,
	HIC "�����ɴ�"NOR,
	 "����",
	 HIW"�ֶ�"NOR,
	MAG"������"NOR,
	 HIG"������"NOR,
	 RED"�����"NOR,
	  YEL"ɺ����"NOR,
	 CYN"����ս��"NOR,
	HIY"�����"NOR,
	 HIR"��ᰶ�"NOR,
	 HIC "Ԫ�ɰԶ�"NOR,
	 "��������",
	 HIW"���߻���"NOR,
	 MAG"�����"NOR,
	HIG"��廤��"NOR,
	RED"��ս���"NOR,
	 YEL"���˻���"NOR,
	 CYN"�����"NOR,
	HIY"�˵�"NOR,
	  HIR"���ǵ��绤��"NOR,
	HIC "������绤��"NOR,
   });

void create()
{
	set_name(HIY "���ϰ�" NOR, ({ "ma", "boss ma" }) );

	set("gender", "����");
	set("age", 35);
	set("long",
		"�����û�����ˣ�ͨ���Ը����м۵ļ۸��չ�ĳ��������\n");
	set("attitude", "peaceful");
	set("str", 100);
	set("per", 130);
	set("int", 100);
	set("cps", 30);
	set("canbuy",10);
	set("buywhat","��");
	set("combat_exp", 1300000);
	set("inquiry", ([ "�չ���Ʒ" : (: doing :)
	  ]));

          set("title", HIC"�߼��չ���"NOR);
	setup();
}
void init()
{
		if (!this_object()->query_temp("markd"))
		{
		set("buywhat",item[random(sizeof(item))]);
		set_temp("markd",1);
		command("chat ���ڿ�ʼ�߼��չ�"+query("buywhat")+"������ֻ��"+environment(this_object())->query("short")+"ͣ������ӡ�");
      	remove_call_out("leave");
        call_out("leave",300);

		}
}
int accept_object(object who, object ob)
{
        object gift,gold,me;
		
        int  val, extra, reb,ti,doubletime,doubletype;
	string test,file,*name;
	mapping quest;
	me = this_object();

        if( me ->query("canbuy") < 1)
	{
        tell_object(who,"���ϰ�˵�������Ѿ��յ�ʮ���ˣ������������ˡ�\n");
	return 0;
	}
        if( (string)ob->query("name") != me->query("buywhat"))
        {
        tell_object(who,"���ϰ�˵��������񡣡�����������Ҫ�Ķ����ɡ�\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"���ϰ�˵�������ѣ�������ʲô��˼��\n");
        return 0;
        }
        else
        {
		val = me->query("canbuy")*50;
        tell_object(who,"���ϰ�˵������ϲ�㣬���ǵ�"+(int)(11-query("canbuy"))+"λ������Ʒ�ģ�������"+val+"�����ӡ�\n");
    me->add("canbuy",-1);
	who->add("buyjob",1);
	//by tiandi 08.1.30������ɾ���Ѿ�������������Ʒ
	if (ob->query("selfmaking"))
	{
	seteuid(ROOT_UID);
	rm(base_name(ob) + ".o");
	rm(base_name(ob) + ".c");
	ob->move(environment(who));
	destruct(ob);
	seteuid(getuid());
	}
	gold = new("/obj/money/gold");
	gold ->set_amount(val);
	doubletime = who->query("doubletime");
	doubletype = (int)who->query("doubletype");
	if (doubletime - time() > 0){
		gold ->set_amount((doubletype+1)*val);
	  	tell_object(who,HIW"�㱻������" +
		chinese_number((doubletype+1)*val) + "���ƽ�\n" NOR);
		}
	else
			{
		tell_object(who,HIW"�㱻�����ˣ�\n" +
		chinese_number(val) + "���ƽ�\n" NOR);
			}
	gold->move(who);
		}
    return 1;
}
void leave()
{
        object ob = this_object();
			command("chat ����͵������ˣ���Ҫ��ȥ�ϻ��ˡ�");
	        message_vision(HIC "���ϰ����ˡ�\n" NOR,this_object());
            destruct(this_object());     
}
string doing()
{
	object me = this_object();
	int val;
	val = me->query("canbuy")*25;
	return "��һ��"+query("buywhat")+"����"+chinese_number(val)+"���ƽ�ļ۸����չ���";
	
}