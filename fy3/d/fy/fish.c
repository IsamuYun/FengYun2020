// ����.c
// change by mudadm 2000.10.12
#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit CREATE_CHAT_ROOM;
int is_chat_room() { return 1; }
void create()
{
        set("short", "����̨");
        set("long", @LONG
���߽�����ۣ��кö�������������ѽ����ʱ�Ĵ�����
�ܵĺ���������϶�������˭�����˴��㣬��������ææµµ��
�˷ܵ����ӣ��㻹��ʲôֵ����ԥ�ģ��Ͽ��ú������ܿ�ʼ
����(diao)�ɣ�
LONG );
        set("exits", ([
                "down" : __DIR__"fysquare",
                ]));
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("coor/x",0);
	set("coor/y",0);
	set("coor/z",10);
        setup();
}
void init()
{
        add_action("do_fish", "fish");
        add_action("do_fish", "diao");
}

int do_fish(string arg)
{

        object me;
        me = this_player();

        if (me->query("combat_exp") > 10000) {
                message_vision(HIG"��͹���Ա����ӰͻȻ������һ������֮�С�\n" +
            HIR "��͹���Ա����$N��ȣ����뵷�ң�������ô���˻������㣬��ò������۸����ְɣ�\n\n\n"NOR,me);
                    me->move("/d/fy/fysquare");
                     return 1;
                                               } else
        if ( !arg || ( arg != "��" ) ) return 
                   notify_fail("��Ҫ��ʲô��?\n");
        else

        if (me->query("kee") < 20 )
                return notify_fail("���֧�ֲ�ס�ˣ���Ъ����ɣ�\n");
        else
                message_vision("$N����һ�ѵ�������ڴ�ʯͷ�ϵ�������������\n", me);
        if (me->is_busy())
                return notify_fail ("�㻹�ǵ���ε�����˵�ɣ�\n");

                switch(random(10)) {  
                        case 0 :             
                             message_vision("$Nһ��ˣ�������һ��"+ HIR "������"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",15+random(2));
                             me->add("combat_exp",20+random(7));
                             me->add("kee",-15);
                           break;
                        case 1 :
                             message_vision("$N��һ��ˣ�������"+ CYN "һ���Ʋ�ñ"NOR +"��������������  \n",me);
                             message_vision(HIW "$N�����Ʋ�ñ���ɵķ����ˡ�  \n\n" NOR,me);
                             me->add("kee",-5);
                           break;
                        case 2 :
                             message_vision("$N��Ư�ζ���$N����һ�����͵�һ��ˣ�$N������"+ RED "һ����ɫ�ĶǶ��� \n"NOR,me);
                             message_vision(HIB "$N�����е��������������� \n\n" NOR,me);
                             me->add("kee",-7);
                           break;
                        case 3 :
                             message_vision("$Nһ��ˣ�������һ��"+ HIC "����"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",3+random(2));
                             me->add("combat_exp",9+random(7));
                             me->add("kee",-6);
                           break;
                        case 4 :
                             message_vision("$Nһ��ˣ�������һ��"+ HIG "����"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",11+random(2));
                             me->add("combat_exp",18+random(7));
                             me->add("kee",-12);
                           break;
                        case 5 :
                             message_vision("$Nһ��ˣ�������һ�����㣬��ϲ����ϲ�� \n\n",me);
                             me->add("potential",6+random(2));
                             me->add("combat_exp",9+random(7));
                             me->add("kee",-10);
                           break;
                        case 6 :
                             message_vision("$Nһ��ˣ�������һ��"+ HIB "����"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",7+random(2));
                             me->add("combat_exp",8+random(7));
                             me->add("kee",-5);
                           break;
                        case 7 :
                             message_vision("$N��һ��ˣ�������"+ WHT "һ���Ͼɵ�˯��"NOR +"�������������� \n",me);
                             message_vision(HIY"$N���ŷϾɵ�˯�����۾����̺��ˡ� \n\n"NOR,me);
                             me->add("kee",-3);
                           break;
                        case 8 :
                             message_vision("$N�͵�һ��ˣ�����̫���ˣ��߶��ˣ������ˣ���ϧ����ϧ�� \n",me);
                             message_vision(HIC "$N���ɵ����������:���ɥѡ� \n\n" NOR,me);
                             me->add("kee",-7);
                           break;
                        default :
                             message_vision("$Nһ��ˣ�������һ��"+ HIM "������"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",10+random(2));
                             me->add("combat_exp",10+random(7));
                             me->add("kee",-8);
                           break;    
                                 }         
                         me->start_busy(2);

        return 1;
}
