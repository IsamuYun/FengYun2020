inherit ROOM;
void create ()
{
  set ("short", "̽��ʫ̨");
  set ("long", @LONG
�����е��������ٴ�����ʫ�Դʵ��źá�ֻҪ������У��ͻ���ű�ī��������
���𣬵ȵ����է�������ǣ��ܱʼ��飬����ǧ�����䡣ʫ̨���������ľ��ݣ�
[33m
                       �����оƽ���
                       �Ĺ����ս���ͷ��
                                       ���������ھƺ�ʧ��ʱ��

[37m
LONG);

        set("jianyu_room",1);
  set("no_death_penalty", 1);
  set("objects", ([ /* sizeof() == 3 */
    __DIR__"npc/referee" : 1,
  __DIR__"npc/prince" : 1,
  __DIR__"npc/yaren" : 1,
"/d/wiz/fyup/npc/xiaoqiang" :1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 1,
  "z" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wcloud1",
  "up" : __DIR__"wenroom",
]));
        call_other( "/obj/board/fyyh_b", "???" );
  setup();
//  replace_program(ROOM);
}
void init()
{
        add_action("do_work", "2002");

}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
if(me->is_busy()) return notify_fail("����Ҫ��Ϣһ�ᡣ\n");
if(me->query("2002")== 1) return notify_fail("���Ѿ��������ˣ������ٽ����ˡ�\n");
message_vision("ϣ��$N���µ�һ�����֧������!\n",me);
ob = new("/questobj/obj/2002hongbao");
ob->move(me);
me->start_busy(1);
me->set("2002",1);
return 1;
}

