// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "dyg xiang"}));
        set("long", "��������ǵڶ���������ܹھ���\n");

        set("gender","����");
        set("str", 2000);
        set("cor", 26);
        set("cps", 25);
set("age", 29);
        set("combat_exp", 100000000);
        set("nickname", HIR" ������Ե�� "HIC"��ȥ������"NOR);
        set("title", HIR"�ڶ���������ܹھ�"NOR" ��������ɽ����");
        setup();
        carry_object("obj/cloth")->wear();
}
/*
void init()
{
        ::init();
        add_action("do_work", "good");

}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
if(!me->is_busy()) return notify_fail("������ʱ���Ѿ����ˡ�\n");
if(userp(me)) return notify_fail("������ʱ���Ѿ����ˡ�\n");
if(me->query("family/master_id")!="dxl") return notify_fail("�㲻�ǹ����ĵ��ӣ����ܽ�����\n");
if(me->query("class")!="ertongtuan_") return notify_fail("�㲻�Ƕ�ͯ�ŵĵ��ӣ����ܽ�����\n");
if(me->query("biwubangjiangli")== 1) return notify_fail("���Ѿ��������ˣ������ٽ����ˡ�\n");
message_vision("$N��ʦ���ڱ���������ս���֣�Ӯ�õ�һ��ھ����������ǽ������!\n",me);
ob = new("/questobj/obj/biwuhongbao");
ob->move(me);
message_vision("����˵��ϣ�������Ϊ���ŷ�����\n", me);
me->start_busy(1);
me->set("biwubangjiangli",1);
return 1;
}
*/
