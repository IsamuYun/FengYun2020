// xuelong1.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("留言板", ({ "board" }) );
        set("location", "/d/xuelongshanzhuang/piaoxueting");
        set("board_id", "xuelong1");
        set("long", @LONG
这是血龙山庄和外界交流的主要手段，由于山高路险，山庄特地在
此为客人准备了留言板。
LONG
	);
	setup();
        set("capacity", 50);                    // 容量为50张留言（通常是30张）
        replace_program(BULLETIN_BOARD);
}
