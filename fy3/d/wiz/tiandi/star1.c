inherit NPC;
//written by Tiandi for lifeskills init
#include <ansi.h>
int do_ask();
void create(){       
set_name(HIG"�������"NOR, ({ "tianjun" }) );
set("gender", "����" );
set("age", 1233);
set("long", "Ϊ��������֮�ף�������������������ǡ����ǣ��˶�ɱ֮�׳壬�ʶ��ס�
����ֵ�ղ����ᣬ��������²��ɣ�������������գ�����֮�����־��� \n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1 );
set("chat_chance_combat", 50 );
set("chat_msg", ({                "��������������Ƕ�ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ����������������\n",    }) );
set("chat_msg_combat", ({           "�������ŭ���������������£�������ˣ�\n",           "�������������Ҳ�þ�û����չ�ֹ��ˣ�\n", }) );
set("inquiry", ([  "�����" : (: do_ask:),              "lifeskills" : (: do_ask :),              "��������" : "�����������������ǣ��ǡ�����ص�������ġ�β������"       ]));
setup();}
void init(){
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {           remove_call_out("greeting");     call_out("greeting", 1, ob);     }}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "����������ȵ�˵�����������ȥ�ˣ������������������ˡ�\n");
}
int do_ask(){
object me;
me=this_player();
if (me->query("max_lifetili") ) {       message_vision("$N˵����$n�Ѿ�ѧ��������ܣ����½�Ϊ�����츣�ɡ���\n",this_object(), me);                 return 1;     }
me->set("max_lifetili",250);
me->Set("lifetili",0);
me->set("lifecook",1);
me->set("lifedoctor",1);
me->set("lifeweapon",1);
me->set("lifearmor",1);
message_vision("$N˵��:����$n�������㹻���˼��������ף��ȵȡ��������ԣ���������������$n����\nЩǷȱ���ã��Ұ��㿪ͨ��Щ���������������㹻�ľ�����������Ұɣ�\n",this_object(), me);
message_vision("$N�ᰴ$n���Դ������ķ���һ���߲�֮â�����һ����$n�о�������ܣ�lifeskills���ƺ���Щ����\n",this_object(), me);
write("��ѧ������⿣�docook����\n��ѧ����������dolian����\n��ѧ���˶��죨duanzao����\n��ѧ�������ƣ�lianzhi����\n");
return 1;}
