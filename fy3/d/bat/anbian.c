//3300,0,10
inherit ROOM;
void create()
{
        set("short", "人间地狱 ");
        set("long", @LONG
石头是死灰色的，冷、硬、狰狞；怒涛拍打着海岸，宛如千军呼啸，万马奔腾。
岛的四周礁石罗列，几乎每一个方向都有触礁的船只，看来就像是一只只被恶兽巨
牙咬住的小兔。无论多轻巧，多坚固的船，都休想能泊上海岸。天地萧杀。    
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"kongdi",
		  "east" : __DIR__"dong",
		]));         
		set("objects",([
        	__DIR__"npc/xunluo" : 1,
			__DIR__"npc/dizi" : 2,
       	]) );
    set("outdoors", "bat");
    set("coor/x",3300);
	set("coor/y",0);
	set("coor/z",10);
	set("no_magic",1);
      set("no_dazuo",1);

	setup();
    replace_program(ROOM);

}
