inherit ROOM;
void create()
{
        set("short", "��Դ��");
        set("long", @LONG
��ǰ��Ӱɽ��֮�£������ɢ���ż������ᣬ�������������޺ۣ�ż��Ȯ�ͣ�
Ҳ�ܿ����ƽ�����������о������κγ��������ӣ�һ�ж��������İ�������
�������棬Ҳֻ����������ݷ��㣬��Զɽ���䡣��Ľ��Ե�һ��ɽʯ�ϣ���ϡ
����һЩ�֡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"northwest" : __DIR__"fenghuo",
	"east" : __DIR__"road1",
	]) );

	set("item_desc", ([
	"ɽʯ": "����ʯ̦��ɽʯ�ϣ���ϡ���ţ���Դ�壢���֡�\n",
	"stone": "����ʯ̦��ɽʯ�ϣ���ϡ���ţ���Դ�壢���֡�\n",
	]) );

   	set("outdoors","taoyuan");
        set("coor/x",180);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
}

void pipe_notify()
{
	object  room;
	
message_vision("�����������Եĸ��������������\n", this_player());
	call_out("animal_come", 3);
}

void animal_come()
{
	object deer;

	deer = present("little deer", this_object());
	if(!objectp(deer)) {
		deer = new(__DIR__"npc/deer");
		deer->move(this_object());
message("vision","����δ�䣬һֻС÷��¹�ʹ����Ժ����˳�����\n", this_object());
	}
	return;	
}
