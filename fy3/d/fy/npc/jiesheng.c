#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);
int do_qingtie();
void create()
{
        set_name("����", ({ "chun-gu" }) );
        set("gender", "Ů��" );
        set("title",  "������Ů" NOR);
            set("nickname",HIR"Ϊ�������"NOR);
       set("age", 62);
        set("long","�Ƿ��ƽ���������Σ���˵��Ҷ�³��й�ϵ��\n");
        set("combat_exp", 500000000);
        set("str", 150000);
         set("inquiry", ([
                "�����"    : (: do_qingtie :),
                "Ҫ��������"    : (: do_qingtie :),
        ]));    
    set("attitude", "friendly");
        setup();

}
void init()
{
        object ob;
        ::init();
        add_action("do_qingtie", "fatie");
}
int do_qingtie()
{
       object me, tie, ob, *all, ke, ma;
       int i;
       object xingren1 ,xingren2;
       me=this_player();
       ob=this_object();
       all = users();
       if (!me->query("marry")) 
       {
        say ("����˵������û�н����ô��������ѽ����������Ҳ�мƻ������ġ���\n");
        return 1;
       }
       if (me->query("gender")=="����") 
       {
        say ("����˵�����е�ҲҪ�����ӣ������԰ɡ���\n");
        return 1;
       }
       if (!me->query("baby-ok")) 
       {
        say ("����˵������û�л����ף����ܰ����𡣡�\n");
        return 1;
       }
  message_vision(HIW "$N�������֣�����Ѿ�߷���"+me->query("name")+"���ˡ�\n" NOR,this_object()); 
       me->set("jiesheng-ok",1);
       me->move("d/fy/jiesheng_room");
       say(HIR "������Цһ��˵������������������Ⱥ򡣡�\n" NOR);
       return 1;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫ��С��ô��\n");
                        break;
                case 1:
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "�����а�������\n");
                        break;
        }
}


