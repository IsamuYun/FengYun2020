inherit ROOM;
void create()
{
        set("short", "青青石板路");
        set("long", @LONG
青青石板路被山林间的薄雾浸得湿润温泽，油油的闪着光；石板间的青
苔密密地爬满了缝隙，你真想脱了鞋光着脚丫子在上面跑，体会一下这乡间
独有的清凉。石板路的北面离离的散布着几户农家。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "north" : __DIR__"anju",
   "west" : __DIR__"road2",
]));
//set("objects",([
//__DIR__"npc/cxq": 1, ]));
  	set("outdoors","taoyuan");
        set("coor/x",210);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	

}


