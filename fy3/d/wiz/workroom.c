// Room: /d/wiz/wizroom.c

inherit ROOM;

int block_cmd();

void create ()
{
  set ("short", "��ʦ�����������");
  set ("long", @LONG

��������ʦ�����Լ��������ȵļ��ң�������й�������
�Ķ���ʲô�ļ�����ó��������������Ĺ������ȣ����
��Ķ��ļ���û���������������Ҫ�ϸ���,���̫��û��
������Ĺ������ȱ���,����ʦ�ǻ���Ϊ��û������ָ�ɹ���
���㣬Ҫ������Ȼ����Ҳ�п��ܻᱻ������Ѿ�������ʦ��
���������������֡�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jobroom",
]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_l.c", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
       if (verb=="look") return 0;
       return 1;
}


