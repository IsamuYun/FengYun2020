inherit ROOM;
void create()
{
        set("short", "ͨ����վ");
        set("long", @LONG
�����Ƿ��Ƴǵ���վ����ҪΪ����ͨ�̵ı������������ȥ���⣬������
;�����ۣ��������һ��������ʧΪһ���ð취����Ժ�����Կ���һ��
����װ���˻��������װ������һ���������ֵ���վ�ϰ�����æµ�š�
LONG
        );
        set("exits", ([   "north" : "/d/fy/wgate", ]));
       set("objects",([    __DIR__"npc/boss1" : 1,   ]));
        set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
void mabian_notify()
{
        object ob;

  message("vision","�󺰵�������Ҫȥ���ѣ������ڣ�����\n" , this_object() );
                call_out("boat_come",5);
}
void boat_come()
{
        object boat;
        object woman;
        object *inv;
        object who, oob;
        int i;
        
        if (query("exits/up")) return;
        if (!objectp(boat=find_object(__DIR__"boat")))
                boat=load_object(__DIR__"boat");
        inv=all_inventory(boat);
        
        message("vision","��յ��Ĺ���һ���׷��ԲԵĸϳ����ˣ�����һ���׺õ�������������\n",this_object());
        message("vision","�ϳ�����˵�������͹٣�����Ҫȥ���������Ǿ����ϳ��ɡ�\n",this_object());
        boat->set("exits/down",__DIR__"yizhan");
        boat->set("no_fight",1);
        boat->set("no_magic",1);
        set("exits/up",__DIR__"boat");
        call_out("boat_leave",10,boat);
}
void boat_leave(object boat)
{
        if (query("exits/up")) delete("exits/up");
        if (boat->query("exits/down")) boat->delete("exits/down");
        message("vision","�ϳ��������һ˦�����������ʻ����վ��\n",this_object()); 
        boat->set_temp("mark/dest","island");
        message("vision","�ϳ��������һ˦�����������ʻ����վ��\n",boat);
        boat->boat_run(0);
}

