// by Tiandi for jifa weapon of lifeskill
inherit NPC;
#include <ansi.h>
void create()
{
    set_name(HIG"�������"NOR, ({ "tianjun" }) );
set("gender", "����" );
set("age", 1233);
set("title","Ǳ��������ʦ");
set("long", "�Ƕ����ڶ��ޣ�Ϊ�����ľ���������������֮���������ߴ���ȫ���ʶ༪�� 
����֮���¿��󣬻�����������ͷ������س��йٹ󣬿��ŷ�ˮ�����\n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1);
set("chat_chance_combat", 50 );
set("chat_msg", ({   "������������칬��ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ����Ǽ���������Ǳ�ܣ�\n",}) );
set("chat_msg_combat", ({"�������ŭ���������ҵĵ������£�������ˣ�\n", "�������������Ҳ�þ�û����չ�ֹ��ˣ�\n", }) );
set("inquiry", (["����" : "ÿһ�Ѷ�������ı������׶�������Ǳ�ڵ����������ڱ���֮�ڣ���ͨ������û�а취����\n���ǵģ���ʮ�����У�Ҳֻ�����������������(jifa)�������ԡ�",              "��������" : "�����������������ǣ��ǡ�����ص�������ġ�β������","��ѯ" : "��������˽�(liaojie)�Լ����б������׵�Ǳ�������Ļ������ҾͶ��ˡ�"  ]));
setup();
}
void init(){
object ob;     ::init();
if( interactive(ob = this_player()) && !is_fighting() ) { remove_call_out("greeting"); call_out("greeting", 1, ob);  }add_action("do_jifa", "jifa");add_action("do_jifa2", "liaojie");}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "�������������˵��������Ҳ��һ�����������˾��ǲ�������ϧʹ�ã�ֻ�����ǵ��������Ĺ��ߣ���ϧ��������\n");
}
int do_jifa(string arg){object me, ob;me = this_player();
if( !arg ) return notify_fail("��Ҫ����ʲ�ᶫ����\n");
if( !objectp(ob = present(arg, me)) )
return notify_fail("������û������������\n");
if(me->is_busy())
return notify_fail("����һ��������û����ɡ�\n");
if( !ob->query("selfmaking") )
return notify_fail("��ֻ�ܼ�������������ƵĶ�����\n");
if( ob->query("equipped") )
return notify_fail("���������װ�����ء�\n");
//   if( !ob->query("owner") )
// return notify_fail("�ⶫ����������Ū�����İɡ�\n");
if(ob->query("fuct")>0)
 return notify_fail(ob->query("name")+"�Ѿ�û��ʲôǱ���������Լ����ˡ�\n");
ob->set("fuct",random(100));
if (ob->query("fuct")<1){
ob->set("fuct",1);
}
if (ob->query("fuct")>89&&ob->query("fuct")<94){
 message_vision(HIB"$N�ӹ�$n���е�"+ob->query("name")+"����ϸ�ش�Ħ����������Ȼ$N�۾�����һ�£�Ц�����ض�$n˵������߿��\n"NOR,this_object(),me);
}
else
{
 message_vision(HIB"$N�ӹ�$n���е�"+ob->query("name")+"����ϸ�ش�Ħ����������һ��$Nҡ��ͷ��$n˵��������ƽƽ���������档������ȥ�ɡ�\n"NOR,this_object(),me);
}
me->start_busy(1);
seteuid(ROOT_UID);
ob->save();
ob->restore();
if(ob->move(me))
message_vision("$N��"+ob->name()+"�黹����$n��\n",this_object(),me);
 seteuid(getuid());
return 1;
}

int do_jifa2(string arg)
{
object me, ob;
me = this_player();
        if( !arg ) return notify_fail("��Ҫ�˽�ʲ�ᶫ����\n");
if( !objectp(ob = present(arg, me)) )
return notify_fail("������û������������\n");
if(me->is_busy())
return notify_fail("����һ��������û����ɡ�\n");
if( !ob->query("selfmaking") )
return notify_fail("��ֻ���˽����������ƵĶ�����\n");
if(ob->query("fuct")<1)
return notify_fail(ob->query("name")+"��δ����������Ǳ����������ȥ��������˵��\n");
else if(ob->query("fuct")>89&&ob->query("fuct")<94)
return notify_fail(ob->query("name")+"����ս�����⹦�ܵ�Ǳ��������\n");

write("���ǿ�ϧ��"+ob->query("name")+"���߱��κ�Ǳ��������\n");
 me->start_busy(1);
return 1;
}
