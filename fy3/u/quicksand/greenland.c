
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����µ���ɳ�Ѿ�������һ��СС�ĺ��������������ǰ�������ˮ��Ȼ
ֻ�ж�ָ��ȴ���峺���ڿ��ȵķ��У���ˮ������ô��������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"desert9",
  "east" : __DIR__"desert8",
//"north" : "/d/bloomdoor/greenland",
]));
	set("resource/water",1);
        set("outdoors", "quicksand");

        set("coor/x",-1085);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-1085);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	object ob;
	string outexit;
        if( interactive( ob = this_player()))
        {
        if(query("exits/east")) delete("exits/east");
        outexit = __DIR__"desert"+(string)( random(3)+6)+ ".c";
        set("exits/east", outexit);

        }
        add_action("do_fillwater", "fillwater");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô�������ˮ��\n");
;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];                         
                        can_fillwater = 1;      
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "��ˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("��Ӿ���װ������ˮ! \n");
			return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�������....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��\n");
        }
	return 1;
}
