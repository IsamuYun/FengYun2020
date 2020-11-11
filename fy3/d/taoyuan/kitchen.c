inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������Ĺ��ߺܰ���էһ����������̨�������ŵİ���Ļ��磬����ʲôҲ����
�������������������С����������ϲ���ԵĴ��ͱ�����������Ʈ����Ũ���Ĵ����
�����Ĵ��̡���ʰ�������������̨�ϻ����ż�Ƭ�л�����Ӱ�з·���һЩ���ߡ�
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"cyard",
	]) );

	set("objects", ([
		__DIR__"obj/oven" : 1,
		__DIR__"obj/pot" : 1,
	]) );

        set("coor/x",220);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}
void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("pot", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
        }
        con = present("oven", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/scallion");
                item->move(con);
                item = new(__DIR__"obj/caidao");
                item->move(con);
                item = new(__DIR__"obj/lighter");
                item->move(con);
        }
}

