inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�㾪��ķ���һ����Ƶ��ŵ�Сľ�ݣ�ľ��ǰ����ľ����ľ�Ρ�
ľ���Ϸ���һ���٣�һ���׷����������������ĵĲ�Ū�š�
ľ���ϵ���������һ���Ҷ�������ɷ����д��:


                  [37;39m����������������������[0m
                  [37;39m��[31m   �� �� �� �� [37;39m   ��[0m
                  [37;39m����������������������[0m


�������ܱ�������ס��Ҫ�ǲ�վ�����ϻ����ѷ����������Ҫ��
��ȥҲֻ�ֿܷ�(cut)����(tiao)�ˡ�
LONG
        );
        set("objects", ([
         __DIR__"npc/rmaster": 1,
          ]) );
        set("coor/x",-10);
        set("coor/y",-610);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_open", "cut");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ�ֿ�ʲô��\n");
                return 1;
        }
        if( arg == "tiao" || arg == "����")
        {
        me = this_player();
        message_vision("$N��ǰ����������������˫�ַֿ�������ֻ��
��ˢ����һ�����������ֿ���һ��ȱ�ڡ�\n", me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"edge");
        if(!me->query("m_success/��������"))
        {
                me->set("m_success/��������",1);
                me->add("score",500);

        }
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�����ַֿ���"+arg+"��\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"����������Ϣ���ֺ����ˣ���ס�˷��ֵĵ�·��\n",
                this_object() );
                delete("exits/east");
}

