inherit ROOM;
void create()
{
        set("short", "�����ϳ���");
        set("long", @LONG
�������Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С��������
�Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������������׽��֮��Ĺ�
��ͨ�����Ŷ���������һ���ϳ�ǽ��խ�ݡ�
                         s________________s         
                        /LLLLLLLLLLLLLLLLLL\        
    []__[]             ^^||======||======||^^             []__[] 
    []==[]_[]__[]__[]__[]||[]__[]||[]__[]||[]__[]__[]__[]_[]==[]
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]      
    []==[]__|__|__|__|__|__|_���L녳ǩ�__|__|__|__|__|__|_[]==[]   
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|__/      \|__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__||        |_|__|��|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__��������_|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|��������|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|  ����  |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"swind5",
  "up"   : "/d/fywall/supgate",
  "south" : __DIR__"road0",
]));
        set("objects", ([
        __DIR__"npc/wind_solider" : 2,
        __DIR__"npc/cloud_solider": 2, 
			]) );
        set("outdoors", "fengyun");
        set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}
int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	if( userp(me))
	{
	if( dir == "north" 
	&& !random(10) && ob=present("garrison", this_object()))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
			return notify_fail(ob->name()+"����ȵ��������ֱֳ�������Ƴǣ�\n");	
			
		}
	}
        if( dir == "up" && ob=present("garrison", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(((string)(inv[i]->name()) == "����ս��") && (int)(inv[i]->query("equipped")))
                        return 1;

                }
                return notify_fail(ob->name()+"����ȵ��������˵Ȳ����ϵǻ���ǽ��\n");
        }

        return 1;
	}
	else return 1;
}

